#include "header.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Endgame");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    e_game_state current_state = MENU;

    // Load textures
    Texture2D background = LoadTexture("resource/textures/background.png");
    Texture2D run = LoadTexture("resource/textures/run.png");
    Texture2D idle = LoadTexture("resource/textures/nindzia.png");
    Texture2D coin = LoadTexture("resource/textures/coin.png");
    Texture2D portal = LoadTexture("resource/textures/portal.png");
    Texture2D ghost = LoadTexture("resource/textures/boo.png");

    // Menu textures
    Texture2D button_texture_1 = LoadTexture("resource/textures/menu1.png");
    Texture2D button_texture_2 = LoadTexture("resource/textures/menu2.png");
    Texture2D off_sound_button = LoadTexture("resource/textures/off_sound_button.png");
    Texture2D on_sound_button = LoadTexture("resource/textures/on_sound_button.png");
    Texture2D game_name = LoadTexture("resource/textures/game_name.png");

    // Audio
    InitAudioDevice();
    Music music = LoadMusicStream("resource/audio/menu.mp3");
    SetMusicVolume(music, 0.5f);
    Sound grass_running = LoadSound("resource/audio/grass_running.mp3");
    SetSoundVolume(grass_running, 0.5f);
    Sound lose = LoadSound("resource/audio/lose.mp3");
    SetSoundVolume(lose, 0.5f);
    bool is_muted = false;
    float music_volume = 0.5f;

    // Player initialization
    t_player player = {
        .x = 10,
        .y = 736,
        .width = idle.width,
        .height = idle.height,
        .velocity = 3,
        .speed = 3.3,
        .direction = RIGHT,
        .last_dash_time = 0,
        .animation = {
            .run_source = {0.f, 0.f, (float)run.width / 6.0f, (float)run.height},
            .idle_source = {0.f, 0.f, (float)idle.width, (float)idle.height},
            .frame = 0,
            .running_time = 0.0f,

            .breathing_time = 0.0f,
            .breathing_offset = 0.0f,

            .coin_source = {0, 0, coin.width / 14, coin.height},
            .coin_frame = 0,
            .coin_time = 0.0f,
            .portal_source = {0.f, 0.f, (float)portal.width / 4.0f, (float)portal.height},
            .portal_frame = 0,
            .portal_time = 0.0f
        }
    };


    t_platform platforms[30];
    t_moving_platform m_platforms[10];
    t_coin coins[MAX_COINS];

    int platform_count = 0;
    int moving_platform_count = 0;

    Vector2 portal_position = (Vector2) {1500, 700};
    e_move move = IDLE;
    e_animation animation = IDLE_A;

    int score = 0;

    bool is_paused = false;
    bool initialized = false;
    bool unloaded = false;

    float countdown = 10.0f;
    float last_time = GetTime();

    while (!WindowShouldClose()) {

        if (current_state == MENU) {
            create_menu(&current_state, &music, background, button_texture_1, button_texture_2, 
                        off_sound_button, on_sound_button, game_name, &is_muted, &music_volume);
            initialized = false;
        }


        // Update and draw Level 1
        else if (current_state == LEVEL1) {

            if (IsKeyPressed(KEY_P)) {
                is_paused = !is_paused;
            }

            if (!initialized) {
                platform_count = 21;
                moving_platform_count = 3;
                init_level(current_state, platforms, m_platforms, coins);
                initialized = true;
            }

            if (player.y + player.height >= SCREEN_HEIGHT) {
                current_state = GAME_OVER;
            }

            if (score == MAX_COINS && check_portal_collision(player, portal_position)) {
                current_state = LEVEL2;
                initialized = false;
            }

            if (!is_paused) {
                update_moving_platforms(m_platforms, moving_platform_count);
                handle_movement(&player, &move, &animation, grass_running);
                update_animation(&player, animation, run, coin, portal);
                handle_platforms_collision(&player, platforms, platform_count, m_platforms, moving_platform_count);
                handle_coin_collision(&player, &score, coins);
            }

            if (is_paused) {
                if (IsKeyPressed(KEY_ESCAPE)) {
                    current_state = MENU;
                    is_paused = !is_paused;
                    countdown = 10.0f;
                }
            }
            
            if (countdown == 0) {
                current_state = GAME_OVER;
            }

            BeginDrawing();
                ClearBackground(WHITE);

                draw_background(background);

                draw_level(platforms, platform_count, m_platforms, moving_platform_count);
                draw_player(move, player, idle, run);
                draw_hint(player);

                draw_coins(coins, player, coin);
                draw_portal(player, &countdown, &last_time, &score, portal);

                // Display score
                DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

            EndDrawing();
        }
        else if (current_state == LEVEL2) {
            if(IsKeyPressed(KEY_P)) {
                is_paused = !is_paused;
            }

            if (!unloaded) {
                for (int i = 0; i < 21; i++) {
                    UnloadTexture(platforms[i].texture);
                }
                for (int i = 0; i < 3; i++) {
                    UnloadTexture(m_platforms[i].texture);
                }
                unloaded = true;
            }

            if (!initialized) {
                platform_count = 6; // Static array size
                moving_platform_count = 5; // Static array size
                init_level(current_state, platforms, m_platforms, coins);
                score = 0;
                initialized = true;
            }

            if (player.y + player.height >= SCREEN_HEIGHT) {
                current_state = GAME_OVER;
            }

            if (!is_paused) {
                update_moving_platforms(m_platforms, moving_platform_count);
                handle_movement(&player, &move, &animation, grass_running);
                update_animation(&player, animation, run, coin, portal);
                handle_platforms_collision(&player, platforms, platform_count, m_platforms, moving_platform_count);
                handle_coin_collision(&player, &score, coins);
            }

            if (is_paused) {
                if(IsKeyPressed(KEY_ESCAPE)) {
                    current_state = MENU;
                    is_paused = !is_paused;
                    countdown = 10.0f;
                }
            }
            BeginDrawing();
                ClearBackground(WHITE);

                draw_background(background);

                draw_level(platforms, platform_count, m_platforms, moving_platform_count);
                draw_player(move, player, idle, run);

                draw_coins(coins, player, coin);
                draw_portal(player, &countdown, &last_time, &score, portal);

                // Display score
                DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

            EndDrawing();
        }
        else if (current_state == GAME_OVER) {
            static double death_time = 0; 
            static bool ghost_displayed = false; 
            static bool lose_sound_played = false;  

            if (!lose_sound_played) {  
                StopMusicStream(music);
                StopSound(grass_running);
                PlaySound(lose); 
                lose_sound_played = true; 
            }

            if (!ghost_displayed) {
                player.animation.idle_source = (Rectangle){0.f, 0.f, (float)ghost.width, (float)ghost.height};
                death_time = GetTime(); 
                ghost_displayed = true;
            }

            BeginDrawing();
            ClearBackground(WHITE);
            draw_background(background); 
            draw_level(platforms, platform_count, m_platforms, moving_platform_count);
            draw_player(IDLE, player, ghost, run);
            draw_coins(coins, player, coin);
            
            if (GetTime() - death_time > 1.5) {
                game_over(); 
            }
            
            EndDrawing();
            
            if (IsKeyPressed(KEY_ENTER)) {
                current_state = MENU;
                player.x = 10;
                player.y = 736;
                score = 0;
                countdown = 10.0f;
                initialized = false;
                unloaded = false;
                lose_sound_played = false; 
            }
        }
    }

    UnloadTexture(background);
    UnloadTexture(run);
    UnloadTexture(idle);
    UnloadTexture(coin);
    UnloadTexture(portal);
    UnloadTexture(button_texture_1);
    UnloadTexture(button_texture_2);
    UnloadTexture(off_sound_button);
    UnloadTexture(on_sound_button);
    UnloadTexture(game_name);
    for (int i = 0; i < 6; i++) {
        UnloadTexture(platforms[i].texture);
    }
    for (int i = 0; i < 5; i++) {
        UnloadTexture(m_platforms[i].texture);
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

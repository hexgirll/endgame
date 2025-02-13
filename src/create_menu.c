#include "header.h"

static void draw_logo(Texture2D game_name) {
    int game_name_width = game_name.width * 1.2f;
    int game_name_height = game_name.height * 1.2f;
    int game_name_x = (SCREEN_WIDTH - game_name_width) / 2;
    int game_name_y = 120;

    DrawTexturePro(game_name, (Rectangle){0, 0, game_name.width, game_name.height},
                   (Rectangle){game_name_x, game_name_y, game_name_width, game_name_height},
                   (Vector2){0, 0}, 0.0f, WHITE);
}

static void draw_play_exit_buttons(Texture2D button_texture_1, Texture2D button_texture_2, Rectangle play_button, Rectangle exit_button) {
    Color brown_text = { 77, 43, 13, 255 };
    float scale = 1.7f;

    DrawTextureEx(button_texture_1, (Vector2){play_button.x, play_button.y}, 0.0f, scale, WHITE);
    DrawText("Play Now", 
            play_button.x + (play_button.width - MeasureText("Play Now", 40)) / 2,
            play_button.y + (play_button.height - 40) / 2, 40, brown_text);
    DrawTextureEx(button_texture_2, (Vector2){exit_button.x, exit_button.y}, 0.0f, scale, WHITE);
    DrawText("Exit", 
        exit_button.x + (exit_button.width - MeasureText("Exit", 40)) / 2, 
        exit_button.y + (exit_button.height - 40) / 2, 40, brown_text);
}

static void draw_sound_button(Texture2D off_sound_button, Texture2D on_sound_button, Rectangle sound_button_rect, bool is_muted) {
    Texture2D sound_button_texture;

    if (is_muted) {
        sound_button_texture = on_sound_button;
    } 
    else {
        sound_button_texture = off_sound_button;
    }

    DrawTexturePro(sound_button_texture, 
                  (Rectangle){0, 0, sound_button_texture.width, sound_button_texture.height},
                  (Rectangle){sound_button_rect.x, sound_button_rect.y, sound_button_rect.width, sound_button_rect.height},
                  (Vector2){0, 0}, 0.0f, WHITE);
}

static void handle_mouse_clicks(Vector2 mouse_point, Rectangle play_button, Rectangle exit_button,
                        Rectangle sound_button_rect, Music *music, bool *is_muted, float *music_volume) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(mouse_point, play_button)) {
            TraceLog(LOG_INFO, "Play Now clicked!");
        }

        if (CheckCollisionPointRec(mouse_point, exit_button)) {
            TraceLog(LOG_INFO, "Exit clicked!");
            StopMusicStream(*music);
            CloseWindow();
            exit(0);
        }

        if (CheckCollisionPointRec(mouse_point, sound_button_rect)) {
            *is_muted = !(*is_muted);
            *music_volume = *is_muted ? 0.0f : 0.5f;

            SetMusicVolume(*music, *music_volume);
        }
    }
}

void create_menu(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Menu");
    SetTargetFPS(60);
    InitAudioDevice();
    
    Music music = LoadMusicStream("resource/audio/menu.mp3");
    SetMusicVolume(music, 0.5f);
    
    Texture2D background = LoadTexture("resource/textures/background.png");
    Texture2D button_texture_1 = LoadTexture("resource/textures/menu1.png");
    Texture2D button_texture_2 = LoadTexture("resource/textures/menu2.png");
    Texture2D off_sound_button = LoadTexture("resource/textures/off_sound_button.png");
    Texture2D on_sound_button = LoadTexture("resource/textures/on_sound_button.png");
    Texture2D game_name = LoadTexture("resource/textures/game_name.png");
    
    float scale = 1.7f;
    Rectangle play_button = {SCREEN_WIDTH / 2 - (button_texture_1.width * scale) / 2,
                             SCREEN_HEIGHT / 2 - (button_texture_1.height * scale) / 2,
                             button_texture_1.width * scale, button_texture_1.height * scale};
    Rectangle exit_button = {play_button.x, play_button.y + play_button.height, play_button.width, play_button.height};
    Rectangle sound_button_rect = {20, SCREEN_HEIGHT - 70, 50, 50};
    
    bool is_muted = false;
    float music_volume = 0.5f;
    
    while (!WindowShouldClose()) {
        Vector2 mouse_point = GetMousePosition();

        UpdateMusicStream(music);

        if (!IsMusicStreamPlaying(music)) {
            PlayMusicStream(music);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexturePro(background, (Rectangle){0, 0, background.width, background.height},
                       (Rectangle){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT},
                       (Vector2){0, 0}, 0.0f, WHITE);
        draw_logo(game_name);
        draw_play_exit_buttons(button_texture_1, button_texture_2, play_button, exit_button);
        draw_sound_button(off_sound_button, on_sound_button, sound_button_rect, is_muted);
        handle_mouse_clicks(mouse_point, play_button, exit_button, 
                            sound_button_rect, &music, &is_muted, &music_volume);
        EndDrawing();
    }
    
    UnloadTexture(background);
    UnloadTexture(button_texture_1);
    UnloadTexture(button_texture_2);
    UnloadTexture(off_sound_button);
    UnloadTexture(on_sound_button);
    UnloadTexture(game_name);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
}

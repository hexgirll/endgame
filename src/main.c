#include "header.h"

Texture2D idle;
Texture2D background;
Texture2D run;
Texture2D idle;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    float velocity;
    float speed;
    e_direction direction;
    float last_dash_time;
} t_player;

bool on_ground(t_player player, int window_height) {
    if (player.y + player.height >= window_height) {
        return true;
    }
    return false;
}

t_player *in_window(t_player *player, int window_width) {
    if(player->x < 0) {
        player->x = 0;
    }
    if (player->x + player->width > window_width) {
        player->x = window_width - player->width;
    }
    return player;
}

int main() {
    int window_width = 1600;
    int window_height = 900;

    float gravity = 1.2;

    InitWindow(window_width, window_height, "Endgame");
    SetTargetFPS(60);
 
    background = LoadTexture("resource/textures/background.png");
    run = LoadTexture("resource/textures/run.png");
    idle = LoadTexture("resource/textures/nindzia.png");

    Rectangle run_source = {0.f , 0.f, (float)run.width / 6.f, (float)run.height};
    Rectangle idle_source = {0.f , 0.f, (float)idle.width, (float)idle.height};

    t_player player = {
        .x = window_width / 2,
        .y = window_height - idle.height,
        .width = idle.width,
        .height = idle.height,
        .velocity = 3,
        .speed = 3,
        .direction = RIGHT,
        .last_dash_time = 0
    };

    e_move move = IDLE;

    int frame = 0;
    float running_time = 0.0f;
    //float idle_time = 0.0f;
    const float update_time = 1.0f/12.0f;
    float breathing_time = 0.0f;
    const float breathing_speed = 7.0f;
    float breathing_offset = 0.0f;

    while (!WindowShouldClose()) {

        float delta_time = GetFrameTime();
        in_window(&player, window_width);

        // Jump
        if (on_ground(player, window_height)) {
            player.velocity = 0;
            player.y = window_height - player.height;

            if(IsKeyPressed(KEY_SPACE)) {
                move = JUMP;
                player.velocity = -20;
            }
        }
        player.velocity += gravity;

        float current_time = GetTime();

        // Dash
        if (IsKeyPressed(KEY_LEFT_SHIFT) && (current_time - player.last_dash_time > DASH_COOLDOWN)) {
            move = DASH;
            player.last_dash_time = current_time; // Reset dash cooldown
        }

        // Apply dash
        if (move == DASH) {
            if (current_time - player.last_dash_time > DASH_DURATION) {
                move = IDLE; // Stop dashing after duration
            } 
            else {
                if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                    player.x += player.speed * DASH_SPEED_MULTIPLIER;
                    player.direction = RIGHT;
                }
                if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                    player.x -= player.speed * DASH_SPEED_MULTIPLIER;
                    player.direction = LEFT;
                }
            }
        }
        
        // Normal movement
        if (move != DASH) {
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                move = RUN;
                player.direction = RIGHT;
                player.x += player.speed;
                running_time += delta_time;
                if (running_time >= update_time) {
                    running_time = 0.0f;
                    frame = (frame + 1) % 6;
                    run_source.x = frame * run.width / 6;
                }
            }
            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                move = RUN;
                player.direction = LEFT;
                player.x -= player.speed;
                running_time += delta_time;
                if (running_time >= update_time) {
                    running_time = 0.0f;
                    frame = (frame + 1) % 6;
                    run_source.x = frame * run.width / 6;
                }
            }
            else {
                move = IDLE;
            }
        }

        if (move == IDLE) {
            breathing_time += delta_time * breathing_speed;
            breathing_offset = sinf(breathing_time);  // breathing effect
        } 
        else {
            breathing_offset = 0;
        }

        player.y += player.velocity;

        BeginDrawing();

            ClearBackground(WHITE);

            Rectangle back_src = { 0, 0, background.width, background.height }; // Full texture
            Rectangle back_dest = { 0, 0, window_width, window_height }; // Fit to window
            Vector2 back_origin = { 0, 0 };
            float rotation = 0.0f;

            DrawTexturePro(background, back_src, back_dest, back_origin, rotation, WHITE);

            if (move == DASH) {
                for (int i = 0; i < 5; i++) {
                    float offset = (i - 2) * 2.0f;
                    DrawTexture(idle, player.x + offset, player.y + offset, (Color){255, 255, 255, 50});
                }
            }

            if (move == RUN || move == DASH) {
                if (player.direction == RIGHT) {
                    Rectangle src = run_source;
                    Rectangle dst = (Rectangle){
                        player.x,
                        player.y,
                        player.width,
                        player.height
                    };
                    DrawTexturePro(run, src, dst, (Vector2){0, 0}, 0, WHITE);
                } else {
                    // smotrit vlevo
                    Rectangle src = (Rectangle) {
                        run_source.x + run_source.width,
                        run_source.y,
                        -run_source.width,
                        run_source.height
                    };
                    Rectangle dst = (Rectangle) {
                        player.x,
                        player.y,
                        player.width,
                        player.height
                    };
                    DrawTexturePro(run, src, dst, (Vector2){0, 0}, 0, WHITE);
                }
            } 
            if (move == IDLE) {
                if (player.direction == RIGHT) {
                    Rectangle src = idle_source;
                    Rectangle dst = (Rectangle) {
                        player.x,
                        player.y - 2 + breathing_offset,
                        player.width,
                        player.height
                    };
                    DrawTexturePro(idle, src, dst, (Vector2){0, 0}, 0, WHITE);
                } 
                else {
                    // smotrit vlevo
                    Rectangle src = (Rectangle) {
                        idle_source.x + idle_source.width,
                        idle_source.y,
                        -idle_source.width,
                        idle_source.height
                    };
                    Rectangle dst = (Rectangle) {
                        player.x,
                        player.y - 2 + breathing_offset,
                        player.width,
                        player.height
                    };
                    DrawTexturePro(idle, src, dst, (Vector2){0, 0}, 0, WHITE);
                }
            }
        EndDrawing();
    }
    
    UnloadTexture(idle);
    CloseWindow();
    return 0;
}
#include "header.h"

void handle_movement(t_player *player, e_move *move, e_animation *animation, Sound grass_running) {
    float current_time = GetTime();

    // Jump
    if (player->velocity == 0 && IsKeyPressed(KEY_SPACE)) {
        *move = JUMP;
        player->velocity = -23;
    }
    player->velocity += GRAVITY;
    player->y += player->velocity;

    // Dash
    if (IsKeyPressed(KEY_LEFT_SHIFT) && (current_time - player->last_dash_time > DASH_COOLDOWN)) {
        *move = DASH;
        player->last_dash_time = current_time; // Reset dash cooldown
    }

    // Apply dash
    if (*move == DASH) {
        if (current_time - player->last_dash_time > DASH_DURATION) {
            *move = IDLE; // Stop dashing after duration
        } else {
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                player->x += player->speed * DASH_SPEED_MULTIPLIER;
                player->direction = RIGHT;
            }
            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                player->x -= player->speed * DASH_SPEED_MULTIPLIER;
                player->direction = LEFT;
            }
        }
    }

    // Normal movement
    if (*move != DASH) {
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            *move = RUN;
            *animation = RUN_A;
            player->direction = RIGHT;
            player->x += player->speed;

            if (!IsSoundPlaying(grass_running)) {
                PlaySound(grass_running);  // Play sound only if not already playing
            }
        } 
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            *move = RUN;
            *animation = RUN_A;
            player->direction = LEFT;
            player->x -= player->speed;

            if (!IsSoundPlaying(grass_running)) {
                PlaySound(grass_running);  // Play sound only if not already playing
            }
        } 
        else {
            *move = IDLE;
            *animation = IDLE_A;
            if (IsSoundPlaying(grass_running)) {
                StopSound(grass_running);  // Stop the sound if idle
            }
        }
    }
}

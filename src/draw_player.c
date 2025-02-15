#include "header.h"

void draw_player(e_move move, t_player player, Texture2D idle, Texture2D run) {
    if (move == DASH) {
        for (int i = 0; i < 5; i++) {
            float offset = (i - 2) * 2.0f;
            DrawTexture(idle, player.x + offset, player.y + offset, (Color){255, 255, 255, 50});
        }
    }

    if (move == RUN || move == DASH) {
        if (player.direction == RIGHT) {
            DrawTexturePro(run, player.animation.run_source, 
                          (Rectangle){player.x, player.y, player.width, player.height}, 
                          (Vector2){0, 0}, 0, WHITE);
        }
        else {
            // Flip the texture for left direction
            Rectangle flipped_run_source = {
                player.animation.run_source.x + player.animation.run_source.width,
                player.animation.run_source.y,
                -player.animation.run_source.width,
                player.animation.run_source.height
            };
            DrawTexturePro(run, flipped_run_source, 
                          (Rectangle){player.x, player.y, player.width, player.height}, 
                          (Vector2){0, 0}, 0, WHITE);
        }
    } 
    if (move == IDLE) {
        if (player.direction == RIGHT) {
            DrawTexturePro(idle, player.animation.idle_source, 
                        (Rectangle){player.x, player.y - 2 + player.animation.breathing_offset, player.width, player.height},
                        (Vector2){0, 0}, 0, WHITE);
        } 
        else {
            // Flip the texture for left direction
            Rectangle flipped_idle_source = {
                player.animation.idle_source.x + player.animation.idle_source.width,
                player.animation.idle_source.y,
                -player.animation.idle_source.width,
                player.animation.idle_source.height
            };
            DrawTexturePro(idle, flipped_idle_source, 
                          (Rectangle){player.x, player.y - 2 + player.animation.breathing_offset, player.width, player.height}, 
                          (Vector2){0, 0}, 0, WHITE);
                    }
                }            
}

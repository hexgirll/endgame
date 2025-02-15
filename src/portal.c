#include "header.h"

#include "header.h"

void draw_portal(e_game_state current_state, t_player player, float *countdown, float *last_time, int *score, Texture2D portal) {
    if (*score == MAX_COINS) {
        // TIMER
        float current_time = GetTime();
        float delta = current_time - *last_time;

        if (*countdown > 0) {
            *countdown -= delta;
        } 
        else {
            *countdown = 0;
        }

        *last_time = current_time; // Update last_time correctly

        // Draw the timer
        DrawText("Timer:", 1500, 10, 25, RED);
        DrawText(TextFormat("%d", (int)(*countdown + 0.99f)), 1550, 40, 25, RED);
        
        // Draw the portal
        if (current_state == LEVEL1) {
            DrawTextureRec(portal, player.animation.portal_source, (Vector2){1500, 700}, WHITE);
        }
        if (current_state == LEVEL2) {
            Rectangle flipped_source = player.animation.portal_source;
            flipped_source.width = -flipped_source.width;
            Vector2 position = {50, 120};
            
            DrawTextureRec(portal, flipped_source, position, WHITE);
        }
        
    } 
    else {
        *last_time = GetTime(); // Reset last_time properly
    }
}


bool check_portal_collision(t_player player, Vector2 portal_position) {
    return (player.x < portal_position.x + player.animation.portal_source.width &&
            player.x + player.width > portal_position.x &&
            player.y < portal_position.y + player.animation.portal_source.height &&
            player.y + player.height > portal_position.y);
}
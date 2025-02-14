#include "header.h"

void draw_hint(t_player player) {
    float hint1_x = 10;
    float hint1_y = 630;
    float hint2_x = 370; 
    float hint2_y = 640;
    
    float distance1 = fabs(player.x - hint1_x);
    float distance2 = fabs(player.x - hint2_x);

    if (distance1 < 140 && (player.y > hint1_y)) { 
        DrawRectangle(hint1_x, hint1_y, 250, 80, Fade(DARKGRAY, 0.0f));
        DrawText("- Jump: SPACE", hint1_x + 10, hint1_y + 10, 18, GOLD);
        DrawText("- Move: A / D", hint1_x + 10, hint1_y + 30, 18, GOLD);
        DrawText("- Dash: SHIFT", hint1_x + 10, hint1_y + 50, 18, GOLD);
    }

    if (distance2 < 140 && (player.y > hint1_y)) {  
        DrawRectangle(hint2_x, hint2_y, 300, 60, Fade(DARKGRAY, 0.0f));
        DrawText("Collect all coins and get out", hint2_x + 10, hint2_y + 10, 18, GOLD);
        DrawText("of the forest in time!", hint2_x + 10, hint2_y + 30, 18, GOLD);
    }
}
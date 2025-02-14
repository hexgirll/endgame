#include "header.h"

void game_over(void) {
    int fontSize = 50;
    const char *message = "Game Over";
    int textWidth = MeasureText(message, fontSize);
    int posX = (SCREEN_WIDTH - textWidth) / 2;
    int posY = (SCREEN_HEIGHT - fontSize) / 2;
    DrawText(message, posX, posY, fontSize, RED);
    DrawText("Press ENTER to return to menu", posX - 40, posY + 60, 20, WHITE);
}
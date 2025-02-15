#include "header.h"

void game_over(Texture2D gameOverTexture) {
    
    int scaledWidth = gameOverTexture.width / 4;
    int scaledHeight = gameOverTexture.height / 4;
    int posX = (SCREEN_WIDTH - scaledWidth) / 2;
    int posY = (SCREEN_HEIGHT - scaledHeight) / 2;
    
    DrawTexturePro(gameOverTexture, (Rectangle){0, 0, gameOverTexture.width, gameOverTexture.height}, 
                   (Rectangle){posX, posY, scaledWidth, scaledHeight}, 
                   (Vector2){0, 0}, 0, WHITE);
    
    int textWidth = MeasureText("Press ENTER to return to menu", 20);
    int textX = (SCREEN_WIDTH - textWidth) / 2;

    DrawText("Press ENTER to return to menu", textX, posY + scaledHeight + 20, 20, YELLOW);
    EndDrawing();
}

void you_win(Texture2D youWin) {

    BeginDrawing();
    
    int scaledWidth = youWin.width / 4;
    int scaledHeight = youWin.height / 4;
    int posX = (SCREEN_WIDTH - scaledWidth) / 2;
    int posY = (SCREEN_HEIGHT - scaledHeight) / 2;
    
    DrawTexturePro(youWin, (Rectangle){0, 0, youWin.width, youWin.height}, 
                   (Rectangle){posX, posY, scaledWidth, scaledHeight}, 
                   (Vector2){0, 0}, 0, WHITE);
    
    int textWidth = MeasureText("Press ENTER to return to menu", 20);
    int textX = (SCREEN_WIDTH - textWidth) / 2;

    DrawText("Press ENTER to return to menu", textX, posY + scaledHeight + 20, 20, YELLOW);
    EndDrawing();
}

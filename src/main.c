#include "header.h"
#include "platform.h"
int main() {
    InitWindow(1600, 900, "Hello Raylib");
    InitLevel();

    while (!WindowShouldClose()) {
        UpdatePlayer();
        HandleCollisions();

        BeginDrawing();
        ClearBackground(RAYWHITE);
    
        DrawLevel();
        DrawRectangle(player.position.x, player.position.y, player.width, player.height, RED);
    
        EndDrawing();
    }
    return 0;
}
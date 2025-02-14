#include "header.h"

void draw_background(Texture2D background) {
    Rectangle back_src = { 0, 0, background.width, background.height }; // Full texture
    Rectangle back_dest = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; // Fit to window
    Vector2 back_origin = { 0, 0 };
    float rotation = 0.0f;
    DrawTexturePro(background, back_src, back_dest, back_origin, rotation, WHITE);
}
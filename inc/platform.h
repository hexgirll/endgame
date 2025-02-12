#ifndef PLATFORM_H
#define PLATFORM_H
#include "header.h"

typedef struct {
    Vector2 position;
    Vector2 size;
    Texture2D texture;
    float scaleX, scaleY;
    float grassHeight;
} Platform;

#define PLATFORM_COUNT 24
Platform platforms[PLATFORM_COUNT];

void InitLevel() {
    platforms[0] = (Platform){{0, 800}, {235, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[1] = (Platform){{1200, 450}, {235, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[2] = (Platform){{295, 300}, {235, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[3] = (Platform){{0, 550}, {130, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[4] = (Platform){{650, 780}, {130, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[5] = (Platform){{1450, 170}, {130, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[6] = (Platform){{300, 750}, {126, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 1.0f, 1.0f, 5 * 0.4f};
    platforms[7] = (Platform){{323, 520}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[8] = (Platform){{800, 720}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[9] = (Platform){{1280, 120}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[10] = (Platform){{1030, 550}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[11] = (Platform){{920, 520}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[12] = (Platform){{810, 490}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[13] = (Platform){{150, 460}, {160, 1}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[14] = (Platform){{690, 150}, {160, 1}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[15] = (Platform){{0, 190}, {160, 10}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[16] = (Platform){{450, 550}, {255, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[17] = (Platform){{1250, 250}, {255, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[18] = (Platform){{950, 185}, {255, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[19] = (Platform){{1200, 830}, {360, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 1.0f, 1.0f, 25 * 1.0f};
    platforms[20] = (Platform){{390, 135}, {160, 1}, LoadTexture("resource/textures/platforms/platform5.png"), 0.8f, 0.8f, 25 * 0.95f};
    platforms[21] = (Platform){{1000, 700}, {160, 1}, LoadTexture("resource/textures/platforms/platform5.png"), 0.8f, 0.8f, 25 * 0.9f};
    platforms[22] = (Platform){{810, 350}, {290, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 1.0f, 1.0f, 25 * 0.7f};
    platforms[23] = (Platform){{1180, 660}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
}


void DrawLevel() {
    for (int i = 0; i < PLATFORM_COUNT; i++) {
        Rectangle source = {0, 0, platforms[i].texture.width, platforms[i].texture.height};
        Rectangle dest = {
            platforms[i].position.x,
            platforms[i].position.y - platforms[i].grassHeight, // Отрисовываем ниже
            platforms[i].texture.width * platforms[i].scaleX,
            platforms[i].texture.height * platforms[i].scaleY
        };
        Vector2 origin = {0, 0};

        DrawTexturePro(platforms[i].texture, source, dest, origin, 0, WHITE);
    }
}


typedef struct {
    Vector2 position;
    Vector2 velocity;
    float width, height;
} Player;

Player player = {{200, 100}, {0, 0}, 20, 20};

void UpdatePlayer() {
    player.velocity.y += 0.1f;  // Гравитация
    player.position.y += player.velocity.y;

    if (IsKeyDown(KEY_LEFT)) player.position.x -= 3;
    if (IsKeyDown(KEY_RIGHT)) player.position.x += 3;
}

bool CheckCollision(Player p, Platform plat) {
    return (p.position.x < plat.position.x + plat.size.x &&
            p.position.x + p.width > plat.position.x &&
            p.position.y + p.height > plat.position.y &&
            p.position.y < plat.position.y + plat.size.y);
}

void HandleCollisions() {
    for (int i = 0; i < PLATFORM_COUNT; i++) {
        if (player.velocity.y > 0 && CheckCollision(player, platforms[i])) {
            player.velocity.y = 0;
            player.position.y = platforms[i].position.y - player.height;
            
            if (IsKeyPressed(KEY_SPACE)) {
                player.velocity.y = -5; // Прыжок
            }
        }
    }
}


#endif

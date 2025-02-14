#include "header.h"

void init_level(e_game_state current_state, t_platform *platforms, t_moving_platform *m_platforms, t_coin *coins) {
        if (current_state == LEVEL1) {
            platforms[0] = (t_platform){{0, 800}, {236, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
            platforms[1] = (t_platform){{1200, 450}, {236, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
            platforms[2] = (t_platform){{295, 300}, {236, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
            platforms[3] = (t_platform){{0, 550}, {142, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[4] = (t_platform){{650, 780}, {144, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[5] = (t_platform){{1450, 170}, {142, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[6] = (t_platform){{323, 520}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
            platforms[7] = (t_platform){{800, 720}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
            platforms[8] = (t_platform){{1280, 120}, {101, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
            platforms[9] = (t_platform){{1030, 550}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[10] = (t_platform){{920, 520}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[11] = (t_platform){{810, 490}, {90, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
            platforms[12] = (t_platform){{150, 460}, {170, 1}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
            platforms[13] = (t_platform){{0, 190}, {170, 1}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
            platforms[14] = (t_platform){{450, 550}, {255, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
            platforms[15] = (t_platform){{1250, 300}, {255, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
            platforms[16] = (t_platform){{950, 130}, {260, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
            platforms[17] = (t_platform){{1200, 830}, {373, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 1.0f, 1.0f, 25 * 1.0f};
            platforms[18] = (t_platform){{390, 135}, {151, 1}, LoadTexture("resource/textures/platforms/platform5.png"), 0.8f, 0.8f, 25 * 0.95f};
            platforms[19] = (t_platform){{1000, 700}, {150, 1}, LoadTexture("resource/textures/platforms/platform5.png"), 0.8f, 0.8f, 25 * 0.9f};
            platforms[20] = (t_platform){{1180, 660}, {88, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};

            m_platforms[0] = (t_moving_platform){{270, 750}, {126, 1}, {270, 750}, {500, 750}, LoadTexture("resource/textures/platforms/platform2.png"), 1.0f, 1.0f, 5 * 0.4f, 1.0f, 1};
            m_platforms[1] = (t_moving_platform){{620, 350}, {296, 1}, {620, 350}, {860, 350}, LoadTexture("resource/textures/platforms/platform6.png"), 1.0f, 1.0f, 25 * 0.7f, 1.0f, 1};
            m_platforms[2] = (t_moving_platform){{600, 165}, {170, 1}, {600, 165}, {720, 165}, LoadTexture("resource/textures/platforms/platform3.png"), 0.7f, 0.7f, 25 * 0.8f, 1.0f, 1};

            coins[0].position = (Vector2){ 1300, 400 };
            coins[1].position = (Vector2){ 370, 470 };
            coins[2].position = (Vector2){ 400, 250 };
            coins[3].position = (Vector2){ 680, 730 };
            coins[4].position = (Vector2){ 830, 450 };
            coins[5].position = (Vector2){ 750, 100 };
            coins[6].position = (Vector2){ 1290, 70 };

            for (int i = 0; i < MAX_COINS; i++) {
                coins[i].collected = false;
            }
    
        }
        if (current_state == LEVEL2) {
            platforms[0] = (t_platform){{0, 750}, {300, 1}, LoadTexture("resource/textures/platforms/platform1.png"), 1.0f, 1.0f, 15 * 1.0f}; 
            platforms[1] = (t_platform){{400, 680}, {200, 1}, LoadTexture("resource/textures/platforms/platform2.png"), 1.0f, 1.0f, 15 * 1.0f};
            platforms[2] = (t_platform){{750, 600}, {250, 1}, LoadTexture("resource/textures/platforms/platform3.png"), 1.0f, 1.0f, 20 * 1.0f};
            platforms[3] = (t_platform){{1100, 550}, {180, 1}, LoadTexture("resource/textures/platforms/platform4.png"), 1.0f, 1.0f, 20 * 1.0f};
            platforms[4] = (t_platform){{1350, 700}, {220, 1}, LoadTexture("resource/textures/platforms/platform5.png"), 1.0f, 1.0f, 20 * 1.0f};
            platforms[5] = (t_platform){{900, 400}, {200, 1}, LoadTexture("resource/textures/platforms/platform6.png"), 1.0f, 1.0f, 15 * 1.0f};


            m_platforms[0] = (t_moving_platform){{600, 500}, {200, 1}, {600, 500}, {900, 500}, LoadTexture("resource/textures/platforms/platform2.png"), 1.0f, 1.0f, 15 * 1.0f, 2.0f, 1};
            m_platforms[1] = (t_moving_platform){{300, 350}, {180, 1}, {300, 350}, {500, 350}, LoadTexture("resource/textures/platforms/platform3.png"), 1.0f, 1.0f, 15 * 1.0f, 1.5f, 1};
            m_platforms[2] = (t_moving_platform){{850, 250}, {250, 1}, {850, 250}, {1100, 250}, LoadTexture("resource/textures/platforms/platform5.png"), 1.0f, 1.0f, 20 * 1.0f, 1.8f, 1}; // Сместил левее
            m_platforms[3] = (t_moving_platform){{500, 150}, {200, 1}, {500, 150}, {700, 150}, LoadTexture("resource/textures/platforms/platform6.png"), 1.0f, 1.0f, 15 * 1.0f, 1.2f, 1}; // Новая платформа
            m_platforms[4] = (t_moving_platform){{1100, 100}, {220, 1}, {1100, 100}, {1300, 100}, LoadTexture("resource/textures/platforms/platform4.png"), 1.0f, 1.0f, 18 * 1.0f, 1.6f, 1}; // Новая платформа сверху

            coins[0].position = (Vector2){ 1300, 400 };
            coins[1].position = (Vector2){ 370, 470 };
            coins[2].position = (Vector2){ 400, 250 };
            coins[3].position = (Vector2){ 680, 730 };
            coins[4].position = (Vector2){ 830, 450 };
            coins[5].position = (Vector2){ 750, 100 };
            coins[6].position = (Vector2){ 1290, 70 };

            for (int i = 0; i < MAX_COINS; i++) {
                coins[i].collected = false;
            }
        }
}
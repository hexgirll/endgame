#include "header.h"

// Function to initialize coins
void InitCoins() {
    for (int i = 0; i < MAX_COINS; i++) {
        coins[i].position = (Vector2){ GetRandomValue(100, 1500), GetRandomValue(100, 800) };
        coins[i].collected = false;
    }
}

bool CheckCoinCollision(t_player player, t_coin coin) {
    return (player.x < coin.position.x + player.animation.coin_source.width &&
            player.x + player.width > coin.position.x &&
            player.y < coin.position.y + player.animation.coin_source.height &&
            player.y + player.height > coin.position.y);
}

void HandleCoinCollection(t_player *player, int *score) {
    for (int i = 0; i < MAX_COINS; i++) {
        if (!coins[i].collected && CheckCoinCollision(*player, coins[i])) {
            coins[i].collected = true;
            (*score)++;
        }
    }
}

void InitLevel() {
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
}

void UpdateMovingPlatforms() {
    for (int i = 0; i < M_PLATFORM_COUNT; i++) {
        if (m_platforms[i].movingRight) {
            m_platforms[i].position.x += m_platforms[i].speed;
            if (m_platforms[i].position.x >= m_platforms[i].endPos.x) {
                m_platforms[i].position.x = m_platforms[i].endPos.x;
                m_platforms[i].movingRight = 0;
            }
        } 
        else {
            m_platforms[i].position.x -= m_platforms[i].speed;
            if (m_platforms[i].position.x <= m_platforms[i].startPos.x) {
                m_platforms[i].position.x = m_platforms[i].startPos.x;
                m_platforms[i].movingRight = 1; 
            }
        }
    }
}

void DrawLevel() {
    // Draw static platforms
    for (int i = 0; i < PLATFORM_COUNT; i++) {
        Rectangle source = {0, 0, platforms[i].texture.width, platforms[i].texture.height};
        Rectangle dest = {
            platforms[i].position.x,
            platforms[i].position.y - platforms[i].grassHeight,
            platforms[i].texture.width * platforms[i].scaleX,
            platforms[i].texture.height * platforms[i].scaleY
        };
        Vector2 origin = {0, 0};

        DrawTexturePro(platforms[i].texture, source, dest, origin, 0, WHITE);
    }

    // Draw moving platforms
    for (int i = 0; i < M_PLATFORM_COUNT; i++) {
        Rectangle source = {0, 0, m_platforms[i].texture.width, m_platforms[i].texture.height};
        Rectangle dest = {
            m_platforms[i].position.x,
            m_platforms[i].position.y - m_platforms[i].grassHeight,
            m_platforms[i].texture.width * m_platforms[i].scaleX,
            m_platforms[i].texture.height * m_platforms[i].scaleY
        };
        Vector2 origin = {0, 0};

        DrawTexturePro(m_platforms[i].texture, source, dest, origin, 0, WHITE);
    }
}


bool CheckCollision(t_player player, Vector2 platPos, Vector2 platSize) {
    float left_foot = player.x + 27;
    float right_foot = player.x + player.width - 27;

    return ((left_foot >= platPos.x && left_foot <= platPos.x + platSize.x) ||
            (right_foot >= platPos.x && right_foot <= platPos.x + platSize.x)) &&
            (player.y + player.height > platPos.y &&
            player.y + player.height - player.velocity <= platPos.y);
}

bool CheckBottomCollision(t_player player, Vector2 platPos, Vector2 platSize) {
    float head_x;
    if (player.direction == RIGHT)
    {
        head_x = player.x + player.width / 2 + 10;
    }
    else {
        head_x = player.x + player.width / 2 - 10;
    }

    return (head_x >= platPos.x + 5 && head_x <= platPos.x + platSize.x - 5) &&
           (player.y < platPos.y + platSize.y &&
            player.y + player.height > platPos.y + (platSize.y / 2));
}



void HandleCollisions(t_player *player, int window_height) {
    bool onPlatform = false;

    // Check collision with static platforms
    for (int i = 0; i < PLATFORM_COUNT; i++) {
        if (player->velocity > 0 && CheckCollision(*player, platforms[i].position, platforms[i].size)) {
            player->velocity = 0;
            player->y = platforms[i].position.y - player->height;
            onPlatform = true;
        } 
        else if (player->velocity < 0 && CheckBottomCollision(*player, platforms[i].position, platforms[i].size)) {
            player->velocity = 1;
            player->y = platforms[i].position.y + platforms[i].size.y + 1;
        }
    }

    // Check collision with moving platforms
    for (int i = 0; i < M_PLATFORM_COUNT; i++) {
        if (player->velocity > 0 && CheckCollision(*player, m_platforms[i].position, m_platforms[i].size)) {
            player->velocity = 0;
            player->y = m_platforms[i].position.y - player->height;
            onPlatform = true;

            // Move player
            player->x += m_platforms[i].movingRight ? m_platforms[i].speed : -m_platforms[i].speed;
        } 
        else if (player->velocity < 0 && CheckBottomCollision(*player, m_platforms[i].position, m_platforms[i].size)) {
            player->velocity = 1;
            player->y = m_platforms[i].position.y + m_platforms[i].size.y + 1;
        }
    }

    if (!onPlatform) {
        player->velocity += 1;
    }

    if (player->y + player->height > window_height) {
        player->y = window_height - player->height;
        player->velocity = 0;
    }
}



void update_animation(t_player *player, e_animation animation, float delta_time) {
    const float update_time = 1.0f / 12.0f; // Player animation frame rate
    const float breathing_speed = 7.0f;     // Breathing effect speed
    const float coin_update_time = 0.1f;    // Coin animation frame rate
    const float portal_update_time = 0.2f;

    // Update player animation
    if (animation == RUN_A) {
        player->animation.running_time += delta_time;
        if (player->animation.running_time >= update_time) {
            player->animation.running_time = 0.0f;
            player->animation.frame = (player->animation.frame + 1) % 6;
            player->animation.run_source.x = player->animation.frame * (run.width / 6);
        }
    } 
    else if (animation == IDLE_A) {
        player->animation.breathing_time += delta_time * breathing_speed;
        player->animation.breathing_offset = sinf(player->animation.breathing_time);  // Breathing effect
    } 
    else {
        player->animation.breathing_offset = 0;
    }

    // Update coin animation
    player->animation.coin_time += delta_time;
    if (player->animation.coin_time >= coin_update_time) {
        player->animation.coin_time = 0.0f;
        player->animation.coin_frame = (player->animation.coin_frame + 1) % 14;
        player->animation.coin_source.x = player->animation.coin_frame * (coin.width / 14);
    }

    // Portal anim
    player->animation.portal_time += delta_time;
    if (player->animation.portal_time >= portal_update_time) {
        player->animation.portal_time = 0.0f;
        player->animation.portal_frame = (player->animation.portal_frame + 1) % 4;
        player->animation.portal_source.x = player->animation.portal_frame * (portal.width / 4);
    }
}

int main() {
    int window_width = 1600;
    int window_height = 900;

    float gravity = 1.0f;

    InitWindow(window_width, window_height, "Endgame");
    SetTargetFPS(60);
 
    background = LoadTexture("resource/textures/background.png");
    run = LoadTexture("resource/textures/run.png");
    idle = LoadTexture("resource/textures/nindzia.png");
    coin = LoadTexture("resource/textures/coin.png");
    portal = LoadTexture("resource/textures/portal.png");

    t_player player = {
        .x = 10,
        .y = 736,
        .width = idle.width,
        .height = idle.height,
        .velocity = 3,
        .speed = 3.3,
        .direction = RIGHT,
        .last_dash_time = 0,
        .animation = {
            .run_source = {0.f, 0.f, (float)run.width / 6.0f, (float)run.height},
            .idle_source = {0.f, 0.f, (float)idle.width, (float)idle.height},
            .frame = 0,
            .running_time = 0.0f,

            .breathing_time = 0.0f,
            .breathing_offset = 0.0f,

            .coin_source = {0, 0, coin.width / 14, coin.height},
            .coin_frame = 0,
            .coin_time = 0.0f,
            .portal_source = {0.f, 0.f, (float)portal.width / 4.0f, (float)portal.height},
            .portal_frame = 0,
            .portal_time = 0.0f
        }
    };

    e_move move = IDLE;
    e_animation animation = IDLE_A;

    int score = 0;

    InitCoins();
    InitLevel();

    float countdown = 10.0f;
    float last_time = GetTime();

    while (!WindowShouldClose()) {
        UpdateMovingPlatforms();

        float delta_time = GetFrameTime();

        // Jump
        if (player.velocity == 0 && IsKeyPressed(KEY_SPACE)) {
            move = JUMP;
            player.velocity = -23;
        }
        player.velocity += gravity;

        float current_time = GetTime();

        // Dash
        if (IsKeyPressed(KEY_LEFT_SHIFT) && (current_time - player.last_dash_time > DASH_COOLDOWN)) {
            move = DASH;
            player.last_dash_time = current_time; // Reset dash cooldown
        }

        // Apply dash
        if (move == DASH) {
            if (current_time - player.last_dash_time > DASH_DURATION) {
                move = IDLE; // Stop dashing after duration
            } 
            else {
                if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                    player.x += player.speed * DASH_SPEED_MULTIPLIER;
                    player.direction = RIGHT;
                }
                if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                    player.x -= player.speed * DASH_SPEED_MULTIPLIER;
                    player.direction = LEFT;
                }
            }
        }
        
        // Normal movement
        if (move != DASH) {
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                move = RUN;
                animation = RUN_A;
                player.direction = RIGHT;
                player.x += player.speed;
            }
            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                move = RUN;
                animation = RUN_A;
                player.direction = LEFT;
                player.x -= player.speed;
            }
            else {
                move = IDLE;
                animation = IDLE_A;
            }
        }

        update_animation(&player, animation, delta_time);

        player.y += player.velocity;

        HandleCollisions(&player, window_height);
        HandleCoinCollection(&player, &score);

        BeginDrawing();

            ClearBackground(WHITE);

            Rectangle back_src = { 0, 0, background.width, background.height }; // Full texture
            Rectangle back_dest = { 0, 0, window_width, window_height }; // Fit to window
            Vector2 back_origin = { 0, 0 };
            float rotation = 0.0f;

            DrawTexturePro(background, back_src, back_dest, back_origin, rotation, WHITE);

            DrawLevel();
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

            for (int i = 0; i < MAX_COINS; i++) {
                if (!coins[i].collected) {
                    DrawTextureRec(coin, player.animation.coin_source, coins[i].position, WHITE);
                }
            }

            if (score == MAX_COINS) {
                float current_time = GetTime();
                float delta = current_time - last_time;

                // Update the countdown if it's greater than 0
                if (countdown > 0) {
                    countdown -= delta;
                } 
                else {
                    countdown = 0; // Stop the timer at 0
                }

                last_time = current_time; // Update last_time for the next frame

                // Draw the timer
                DrawText("Timer:", 1500, 10, 25, RED); // Font size changed to 20
                DrawText(TextFormat("%d", (int)(countdown + 0.99f)), 1550, 40, 25, RED); // Font size changed to 20

                // Draw the portal
                DrawTextureRec(portal, player.animation.portal_source, (Vector2){1500, 700}, WHITE);
            } 
            else {
                // Reset last_time to avoid jumps when the timer is not active
                last_time = GetTime(); 
            }




            // Display score
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(run);
    UnloadTexture(idle);
    UnloadTexture(coin);
    for (int i = 0; i < PLATFORM_COUNT; i++) {
        UnloadTexture(platforms[i].texture);
    }
    for (int i = 0; i < M_PLATFORM_COUNT; i++) {
        UnloadTexture(m_platforms[i].texture);
    }

    CloseWindow();
    return 0;
}
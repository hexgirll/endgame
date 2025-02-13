#include "header.h"

// Function to initialize platforms
void InitLevel() {
    platforms[0] = (Platform){{0, 800}, {235, 1}, LoadTexture("resource/textures/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[1] = (Platform){{1200, 450}, {235, 1}, LoadTexture("resource/textures/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[2] = (Platform){{295, 300}, {235, 1}, LoadTexture("resource/textures/platform6.png"), 0.8f, 0.8f, 15 * 0.8f};
    platforms[3] = (Platform){{0, 550}, {130, 1}, LoadTexture("resource/textures/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[4] = (Platform){{650, 780}, {130, 1}, LoadTexture("resource/textures/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[5] = (Platform){{1450, 170}, {130, 1}, LoadTexture("resource/textures/platform1.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[6] = (Platform){{300, 750}, {126, 1}, LoadTexture("resource/textures/platform2.png"), 1.0f, 1.0f, 5 * 0.4f};
    platforms[7] = (Platform){{323, 520}, {101, 1}, LoadTexture("resource/textures/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[8] = (Platform){{800, 720}, {101, 1}, LoadTexture("resource/textures/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[9] = (Platform){{1280, 120}, {101, 1}, LoadTexture("resource/textures/platform2.png"), 0.8f, 0.8f, 5 * 0.4f};
    platforms[10] = (Platform){{1030, 550}, {90, 1}, LoadTexture("resource/textures/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[11] = (Platform){{920, 520}, {90, 1}, LoadTexture("resource/textures/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[12] = (Platform){{810, 490}, {90, 1}, LoadTexture("resource/textures/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
    platforms[13] = (Platform){{150, 460}, {160, 1}, LoadTexture("resource/textures/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[14] = (Platform){{690, 150}, {160, 1}, LoadTexture("resource/textures/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[15] = (Platform){{0, 190}, {160, 10}, LoadTexture("resource/textures/platform3.png"), 0.7f, 0.7f, 25 * 0.8f};
    platforms[16] = (Platform){{450, 550}, {255, 1}, LoadTexture("resource/textures/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[17] = (Platform){{1250, 250}, {255, 1}, LoadTexture("resource/textures/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[18] = (Platform){{950, 185}, {255, 1}, LoadTexture("resource/textures/platform4.png"), 0.7f, 0.7f, 25 * 0.7f};
    platforms[19] = (Platform){{1200, 830}, {360, 1}, LoadTexture("resource/textures/platform4.png"), 1.0f, 1.0f, 25 * 1.0f};
    platforms[20] = (Platform){{390, 135}, {160, 1}, LoadTexture("resource/textures/platform5.png"), 0.8f, 0.8f, 25 * 0.95f};
    platforms[21] = (Platform){{1000, 700}, {160, 1}, LoadTexture("resource/textures/platform5.png"), 0.8f, 0.8f, 25 * 0.9f};
    platforms[22] = (Platform){{810, 350}, {290, 1}, LoadTexture("resource/textures/platform6.png"), 1.0f, 1.0f, 25 * 0.7f};
    platforms[23] = (Platform){{1180, 660}, {90, 1}, LoadTexture("resource/textures/platform2.png"), 0.7f, 0.7f, 5 * 0.4f};
}

// Function to initialize coins
void InitCoins() {
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

bool CheckCoinCollision(t_player player, t_coin coin) {
    return (player.x < coin.position.x + player.animation.coin_source.width &&
            player.x + player.width > coin.position.x &&
            player.y < coin.position.y + player.animation.coin_source.height &&
            player.y + player.height > coin.position.y);
}

void HandleCoinCollection(t_player *player) {
    for (int i = 0; i < MAX_COINS; i++) {
        if (!coins[i].collected && CheckCoinCollision(*player, coins[i])) {
            coins[i].collected = true;
            score++;
        }
    }
}

void DrawLevel() {
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
        DrawRectangleLines(platforms[i].position.x, platforms[i].position.y,
                   platforms[i].size.x, platforms[i].size.y, RED);
    }
}

bool CheckCollision(t_player player, Platform plat) {
    return (player.x < plat.position.x + plat.size.x &&
            player.x + player.width > plat.position.x &&
            player.y + player.height > plat.position.y &&
            player.y + player.height - player.velocity <= plat.position.y);
}

bool CheckBottomCollision(t_player player, Platform plat) {
    return (player.x < plat.position.x + plat.size.x &&
            player.x + player.width > plat.position.x &&
            player.y < plat.position.y + plat.size.y &&
            player.y + player.height > plat.position.y + (plat.size.y / 2));
}

void HandleCollisions(t_player *player, int window_height) {
    bool onPlatform = false;

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        if (player->velocity > 0 && CheckCollision(*player, platforms[i])) {
            player->velocity = 0;
            player->y = platforms[i].position.y - player->height;
            onPlatform = true;
        } else if (player->velocity < 0 && CheckBottomCollision(*player, platforms[i])) {
            player->velocity = 1;
            player->y = platforms[i].position.y + platforms[i].size.y + 1;
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
    
    // Update player animation
    if (animation == RUN_A) {
        player->animation.running_time += delta_time;
        if (player->animation.running_time >= update_time) {
            player->animation.running_time = 0.0f;
            player->animation.frame = (player->animation.frame + 1) % 6;
            player->animation.run_source.x = player->animation.frame * (run.width / 6);
        }
    } else if (animation == IDLE_A) {
        player->animation.breathing_time += delta_time * breathing_speed;
        player->animation.breathing_offset = sinf(player->animation.breathing_time);  // Breathing effect
    } else {
        player->animation.breathing_offset = 0;
    }
    
    // Update coin animation
    player->animation.coin_running_time += delta_time;
    if (player->animation.coin_running_time >= coin_update_time) {
        player->animation.coin_running_time = 0.0f;
        player->animation.coin_frame = (player->animation.coin_frame + 1) % 14;
        player->animation.coin_source.x = player->animation.coin_frame * (coin.width / 14);
    }
    }
    
    int main() {
    int window_width = 1600;
    int window_height = 900;
    
    float gravity = 1.2;
    
    InitWindow(window_width, window_height, "Endgame");
    SetTargetFPS(60);
    
    background = LoadTexture("resource/textures/background.png");
    run = LoadTexture("resource/textures/run.png");
    idle = LoadTexture("resource/textures/nindzia.png");
    coin = LoadTexture("resource/textures/coin.png");
    
    t_player player = {
        .x = window_width / 2,
        .y = window_height - idle.height,
        .width = idle.width,
        .height = idle.height,
        .velocity = 3,
        .speed = 3,
        .direction = RIGHT,
        .last_dash_time = 0,
        .animation = {
            .run_source = {0.f, 0.f, (float)run.width / 6.f, (float)run.height},
            .idle_source = {0.f, 0.f, (float)idle.width, (float)idle.height},
            .frame = 0,
            .running_time = 0.0f,
            .breathing_time = 0.0f,
            .breathing_offset = 0.0f,
    
            // Initialize coin animation data
            .coin_source = {0, 0, coin.width / 14, coin.height},
            .coin_frame = 0,
            .coin_running_time = 0.0f
        }
    };
    
    e_move move = IDLE;
    e_animation animation = IDLE_A;
    
    InitLevel();
    InitCoins();  // Initialize coins
    
    while (!WindowShouldClose()) {
        float delta_time = GetFrameTime();
    
        // Jump
        if (player.velocity == 0 && IsKeyPressed(KEY_SPACE)) {
            move = JUMP;
            player.velocity = -25;
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
            } else {
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
        HandleCoinCollection(&player);  // Handle coin collection here
    
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
    
            // Draw coins
            for (int i = 0; i < MAX_COINS; i++) {
                if (!coins[i].collected) {
                    DrawTextureRec(coin, player.animation.coin_source, coins[i].position, WHITE);
                }
            }
    
            // Display score
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);
    
        EndDrawing();
    }
    
    UnloadTexture(idle);
    UnloadTexture(run);
    UnloadTexture(background);
    UnloadTexture(coin);
    CloseWindow();
    return 0;
    }
    
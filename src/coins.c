#include "header.h"

bool check_coin_collision(t_player player, t_coin coin) {
    return (player.x < coin.position.x + player.animation.coin_source.width &&
            player.x + player.width > coin.position.x &&
            player.y < coin.position.y + player.animation.coin_source.height &&
            player.y + player.height > coin.position.y);
}

void handle_coin_collision(t_player *player, int *score, t_coin *coins) {
    for (int i = 0; i < MAX_COINS; i++) {
        if (!coins[i].collected && check_coin_collision(*player, coins[i])) {
            coins[i].collected = true;
            (*score)++;
        }
    }
}

void draw_coins(t_coin *coins, t_player player, Texture2D coin) {
    for (int i = 0; i < MAX_COINS; i++) {
        if (!coins[i].collected) {
            DrawTextureRec(coin, player.animation.coin_source, coins[i].position, WHITE);
        }
    }
}

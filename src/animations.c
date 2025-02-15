#include "header.h"

void update_animation(t_player *player, e_animation animation, Texture2D run, Texture2D coin, Texture2D portal) {
    const float update_time = 1.0f / 12.0f; // Player animation frame rate
    const float breathing_speed = 7.0f;     // Breathing effect speed
    const float coin_update_time = 0.1f;    // Coin animation frame rate
    const float portal_update_time = 0.2f;
    float delta_time = GetFrameTime();

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

#include "header.h"

bool check_collision(t_player player, Vector2 plat_pos, Vector2 plat_size) {
    float left_foot = player.x + 27;
    float right_foot = player.x + player.width - 27;

    return ((left_foot >= plat_pos.x && left_foot <= plat_pos.x + plat_size.x) ||
            (right_foot >= plat_pos.x && right_foot <= plat_pos.x + plat_size.x)) &&
            (player.y + player.height > plat_pos.y &&
            player.y + player.height - player.velocity <= plat_pos.y);
}

bool check_bottom_collision(t_player player, Vector2 plat_pos, Vector2 plat_size) {
    float head_x;
    if (player.direction == RIGHT)
    {
        head_x = player.x + player.width / 2 + 10;
    }
    else {
        head_x = player.x + player.width / 2 - 10;
    }

    return (head_x >= plat_pos.x + 5 && head_x <= plat_pos.x + plat_size.x - 5) &&
           (player.y < plat_pos.y + plat_size.y &&
            player.y + player.height > plat_pos.y + (plat_size.y / 2));
}



void handle_platforms_collision(t_player *player, t_platform *platforms, int platform_count, t_moving_platform *m_platforms, int moving_platform_count) {
    bool on_platform = false;

    // Check collision with static platforms
    for (int i = 0; i < platform_count; i++) {
        if (player->velocity > 0 && check_collision(*player, platforms[i].position, platforms[i].size)) {
            player->velocity = 0;
            player->y = platforms[i].position.y - player->height;
            on_platform = true;
        } 
        else if (player->velocity < 0 && check_bottom_collision(*player, platforms[i].position, platforms[i].size)) {
            player->velocity = 1;
            player->y = platforms[i].position.y + platforms[i].size.y + 1;
        }
    }

    // Check collision with moving platforms
    for (int i = 0; i < moving_platform_count; i++) {
        if (player->velocity > 0 && check_collision(*player, m_platforms[i].position, m_platforms[i].size)) {
            player->velocity = 0;
            player->y = m_platforms[i].position.y - player->height;
            on_platform = true;

            // Move player
            player->x += m_platforms[i].movingRight ? m_platforms[i].speed : -m_platforms[i].speed;
        } 
        else if (player->velocity < 0 && check_bottom_collision(*player, m_platforms[i].position, m_platforms[i].size)) {
            player->velocity = 1;
            player->y = m_platforms[i].position.y + m_platforms[i].size.y + 1;
        }
    }

    if (!on_platform) {
        player->velocity += 1;
    }
}
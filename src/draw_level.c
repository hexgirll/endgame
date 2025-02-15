#include "header.h"

void draw_level(t_platform *platforms, int platform_count, t_moving_platform *m_platforms, int moving_platform_count) {
    //static platforms
    for (int i = 0; i < platform_count; i++) {
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

    //moving platforms
    for (int i = 0; i < moving_platform_count; i++) {
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

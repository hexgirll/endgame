#include "header.h"

void update_moving_platforms(t_moving_platform *m_platforms, int moving_platform_count) {
    for (int i = 0; i < moving_platform_count; i++) {
        printf("Platform[%d] position: (%f, %f)\n", i, m_platforms[i].position.x, m_platforms[i].position.y);
        
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

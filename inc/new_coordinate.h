void InitLevel() {
    platforms[0] = (t_platform){{0, 750}, {300, 1}, LoadTexture("resource/textures/platform1.png"), 1.0f, 1.0f, 15 * 1.0f}; 
    platforms[1] = (t_platform){{400, 680}, {200, 1}, LoadTexture("resource/textures/platform2.png"), 1.0f, 1.0f, 15 * 1.0f};
    platforms[2] = (t_platform){{750, 600}, {250, 1}, LoadTexture("resource/textures/platform3.png"), 1.0f, 1.0f, 20 * 1.0f};
    platforms[3] = (t_platform){{1100, 550}, {180, 1}, LoadTexture("resource/textures/platform4.png"), 1.0f, 1.0f, 20 * 1.0f};
    platforms[4] = (t_platform){{1350, 700}, {220, 1}, LoadTexture("resource/textures/platform5.png"), 1.0f, 1.0f, 20 * 1.0f};
    platforms[5] = (t_platform){{900, 400}, {200, 1}, LoadTexture("resource/textures/platform6.png"), 1.0f, 1.0f, 15 * 1.0f};


    m_platforms[0] = (t_moving_platform){{600, 500}, {200, 1}, {600, 500}, {900, 500}, LoadTexture("resource/textures/platform2.png"), 1.0f, 1.0f, 15 * 1.0f, 2.0f, 1};
    m_platforms[1] = (t_moving_platform){{300, 350}, {180, 1}, {300, 350}, {500, 350}, LoadTexture("resource/textures/platform3.png"), 1.0f, 1.0f, 15 * 1.0f, 1.5f, 1};
    m_platforms[2] = (t_moving_platform){{850, 250}, {250, 1}, {850, 250}, {1100, 250}, LoadTexture("resource/textures/platform5.png"), 1.0f, 1.0f, 20 * 1.0f, 1.8f, 1}; // Сместил левее
    m_platforms[3] = (t_moving_platform){{500, 150}, {200, 1}, {500, 150}, {700, 150}, LoadTexture("resource/textures/platform6.png"), 1.0f, 1.0f, 15 * 1.0f, 1.2f, 1}; // Новая платформа
    m_platforms[4] = (t_moving_platform){{1100, 100}, {220, 1}, {1100, 100}, {1300, 100}, LoadTexture("resource/textures/platform4.png"), 1.0f, 1.0f, 18 * 1.0f, 1.6f, 1}; // Новая платформа сверху

}
#ifndef HEADER_H
#define HEADER_H

#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DASH_SPEED_MULTIPLIER 4
#define DASH_DURATION 0.2f
#define DASH_COOLDOWN 0.5f
#define MAX_COINS 8
#define GRAVITY 1.0f


typedef enum {
    MENU,
    LEVEL1,
    LEVEL2,
    GAME_OVER
} e_game_state;

typedef enum {
    RIGHT,
    LEFT
} e_direction;

typedef enum {
    IDLE,
    RUN,
    JUMP,
    DASH
} e_move;

typedef enum  {
    IDLE_A,
    RUN_A,
    COIN_A,
    PICK_UP_A
} e_animation;


typedef struct {
    Rectangle run_source;
    Rectangle idle_source;
    int frame;
    float running_time;
    float breathing_time;
    float breathing_offset;
    Rectangle coin_source;
    int coin_frame;
    float coin_time;
    Rectangle portal_source;
    int portal_frame;
    float portal_time;
} t_animation_data;

typedef struct {
    int x;
    int y;
    int width;
    int height;
    float velocity;
    float speed;
    e_direction direction;
    float last_dash_time;
    t_animation_data animation;
} t_player;

typedef struct {
    Vector2 position;
    Vector2 size;
    Texture2D texture;
    float scaleX, scaleY;
    float grassHeight;
} t_platform;

typedef struct {
    Vector2 position;
    bool collected;
} t_coin;

typedef struct {
    Vector2 position;
    Vector2 size;
    Vector2 startPos;
    Vector2 endPos;
    Texture2D texture;
    float scaleX, scaleY;
    float grassHeight;
    float speed;   
    int movingRight; 
} t_moving_platform;

void init_level(e_game_state current_state, t_platform *platforms, t_moving_platform *m_platforms, t_coin *coins);
void update_moving_platforms(t_moving_platform *m_platforms, int moving_platform_count);
void draw_level(t_platform *platforms, int platform_count, t_moving_platform *m_platforms, int moving_platform_count);
bool check_collision(t_player player, Vector2 plat_pos, Vector2 plat_size);
bool check_bottom_collision(t_player player, Vector2 plat_pos, Vector2 plat_size);
void handle_platforms_collision(t_player *player, t_platform *platforms, int platform_count, t_moving_platform *m_platforms, int moving_platform_count);
void create_menu(e_game_state *current_state, Music *music, Texture2D background, Texture2D button_texture_1, Texture2D button_texture_2, 
                 Texture2D off_sound_button, Texture2D on_sound_button, Texture2D game_name, bool *is_muted, float *music_volume);
void handle_movement(t_player *player, e_move *move, e_animation *animation, Sound grass_running);
void update_animation(t_player *player, e_animation animation, Texture2D run, Texture2D coin, Texture2D portal);
void init_coins(t_coin *coins);
bool check_coin_collision(t_player player, t_coin coin);
void handle_coin_collision(t_player *player, int *score, t_coin *coins);
void draw_coins(t_coin *coins, t_player player, Texture2D coin);
void draw_background(Texture2D background);
void draw_player(e_move move, t_player player, Texture2D idle, Texture2D run);
void draw_portal(t_player player, float *countdown, float *last_time, int *score, Texture2D portal);
bool check_portal_collision(t_player player, Vector2 portal_position);
void draw_hint(t_player player);
void game_over(void);



#endif


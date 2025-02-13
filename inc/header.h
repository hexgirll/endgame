#ifndef HEADER_H
#define HEADER_H

#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

#define DASH_SPEED_MULTIPLIER 4
#define DASH_DURATION 0.2f
#define DASH_COOLDOWN 0.5f
#define PLATFORM_COUNT 21
#define M_PLATFORM_COUNT 3
#define MAX_COINS 10

Texture2D idle;
Texture2D background;
Texture2D run;
Texture2D coin;
Texture2D portal;

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

t_platform platforms[PLATFORM_COUNT];
t_moving_platform m_platforms [M_PLATFORM_COUNT];
t_coin coins[MAX_COINS];

#endif

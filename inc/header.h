#ifndef HEADER_H
#define HEADER_H

#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

#define DASH_SPEED_MULTIPLIER 5
#define DASH_DURATION 0.2f
#define DASH_COOLDOWN 0.5f
#define MAX_COINS 7

Texture2D idle;
Texture2D background;
Texture2D run;
Texture2D coin;

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
    float coin_running_time;
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
    bool collected;
} t_coin;

typedef struct {
    Vector2 position;
    Vector2 size;
    Texture2D texture;
    float scaleX, scaleY;
    float grassHeight;
} Platform;

#define PLATFORM_COUNT 24
Platform platforms[PLATFORM_COUNT];

t_coin coins[MAX_COINS];
int score;

#endif

#ifndef HEADER_H
#define HEADER_H

#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define DASH_SPEED_MULTIPLIER 4
#define DASH_DURATION 0.2f
#define DASH_COOLDOWN 0.5f
#define PLATFORM_COUNT 21
#define M_PLATFORM_COUNT 3
#define MAX_COINS 7
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900


typedef enum {
    MENU,
    LEVEL1
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

void create_menu();

#endif

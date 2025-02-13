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

typedef enum {
    IDLE,
    RUN,
    JUMP,
    DASH
} e_move;

typedef enum {
    RIGHT,
    LEFT
} e_direction;

#endif

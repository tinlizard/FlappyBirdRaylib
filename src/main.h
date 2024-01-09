#ifndef PIPES_H
#define PIPES_H
#define NUM_PIPES 100
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "raylib.h"
//define TopPipe struct
typedef struct TopPipe {
    Texture2D pipeTexture;
    int x;
    int y;
    int width;
    int height;
    int dist;
} TopPipe;

typedef struct BottomPipe {
    Texture2D pipeTexture; 
    int x;
    int y;
    int width;
    int height;
} BottomPipe;

//function definitions
static void UpdateDrawFrame(void); 
static void spawnPipesTop(); 
static void spawnPipesBottom();
static void initPipes();

#endif

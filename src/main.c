#include "main.h"
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

TopPipe topPipes[NUM_PIPES];
BottomPipe bottomPipes[NUM_PIPES]; 
Texture2D backgroundTexture;
//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
static void UpdateDrawFrame(void); 
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 288;
    const int screenHeight = 512;

    srand(time(NULL));
    InitWindow(screenWidth, screenHeight, "raylib");
    SetWindowTitle("Flappy Bird");
    backgroundTexture = LoadTexture("resources/background-day.png");
    initPipes();

    //--------------------------------------------------------------------------------------

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


//print x position of first pipe, update x position of all pipes
static void spawnPipesTop(){
        for(int i=0; i<NUM_PIPES; i++){
            //char int_str [5];
            DrawTexture(topPipes[i].pipeTexture,topPipes[i].x,topPipes[i].y,WHITE);
            //sprintf(int_str,"%d",topPipes[NUM_PIPES-1].x);
            //DrawText(int_str,70,50,30,RED);
            topPipes[i].x -= 1; 

            if(topPipes[NUM_PIPES-1].x<=topPipes[NUM_PIPES-1].width){
                for(int j=1; j<NUM_PIPES; j++){
                    topPipes[j].x = j * 200;
                } 
            }
        }
}
//print x position of first pipe, update x position of all pipes
static void spawnPipesBottom(){
        for(int i=0; i<NUM_PIPES; i++){
            //char int_str [5];
            DrawTexture(bottomPipes[i].pipeTexture,bottomPipes[i].x,bottomPipes[i].y,WHITE);
            //sprintf(int_str,"%d",bottomPipes[NUM_PIPES-1].x);
            //DrawText(int_str,140,50,30,RED);
            bottomPipes[i].x -= 1; 

            if(bottomPipes[NUM_PIPES-1].x<=bottomPipes[NUM_PIPES-1].width){
                for(int j=1; j<NUM_PIPES; j++){
                    bottomPipes[j].x = j*200; 
                } 
            }
        }
}

static void initPipes(){
    //initialize top pipes
    for(int i=0; i<NUM_PIPES; i++){
        int randInt;
        //generate numbers between 5 and 8
        for(int j=5; j<7; j++){
            randInt = (rand() % 6)*j;
        }
        topPipes[i].pipeTexture = LoadTexture("resources/top_pipe_green.png");
        topPipes[i].x = i*200;
        topPipes[i].y = -30+randInt;
        topPipes[i].width = 70; 
        topPipes[i].height = 320;
    }
    //intialize bottom pipes
    for(int i=0; i<NUM_PIPES; i++){
        int randInt;
        //generate random numbers between 5 and 8
        for(int j=5; j<6; j++){
            randInt = (rand() % 6)*j;
        }
        bottomPipes[i].pipeTexture = LoadTexture("resources/bottom_pipe_green.png");
        bottomPipes[i].x = i*200;
        bottomPipes[i].y = 360+randInt;
        bottomPipes[i].width = 70; 
        bottomPipes[i].height = 320;
    }
}
// Update and draw game frame
static void UpdateDrawFrame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawTexture(backgroundTexture,0,0,WHITE);
        DrawFPS(10, 10);
        
        spawnPipesTop();
        spawnPipesBottom();
        
    EndDrawing();
}

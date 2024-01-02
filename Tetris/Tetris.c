#include "Tetris.h"

#define tetrominoStartX  (STAGE_WIDTH / 2)
#define tetrominoStartY  0

//Game info
int score = 0;
int gameover = 2;
int Threshold_value = THRESHOLD_VALUE;
int Threshold = 1;

// Tetromino info
int Current_tetromino_X = tetrominoStartX;
int Current_tetromino_Y = tetrominoStartY;
int Current_tetromino_type;
int Current_rotation = 0;
float Tetromino_timer = 1;
float Tetromino_down_timer;
int Current_color;
    
time_t Unix_time;

#pragma region Init_Stage_And_Tetro
int stage[] = 
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const int lTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int lTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int jTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int oTetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int sTetromino90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
};

const int sTetromino180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
};

const int sTetromino270[] =
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
};


const int tTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int tTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int iTetromino180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
};

const int iTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino90[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0,
};

const int zTetromino180[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
};

const int zTetromino270[] =
{
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
};

Color colorTypes[8] =
{
    {53, 92, 184, 255},
    {245, 245, 125, 255},
    {115, 230, 164,255},
    {172, 129, 230,255},
    {230, 171, 129,255},
    {120, 218, 227,255},
    {97,5,85,255},
    {85,45,63,255},
};

const int *tetrominoTypes[7][4] =
{
    {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
    {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
    {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
    {oTetromino, oTetromino, oTetromino, oTetromino},
    {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
    {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
    {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

#pragma endregion Init_Stage_And_Tetro

void Init_functions()
{
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "TETRIS");
    InitAudioDevice();
    Init_Sounds();
}

void Close_functions()
{
    CloseAudioDevice();
    CloseWindow();
}

void ResetVariables()
{
    Current_tetromino_X = tetrominoStartX;
    Current_tetromino_Y = tetrominoStartY;
    Current_tetromino_type = GetRandomValue(0, 6);
    Current_rotation = 0;
    Current_color = GetRandomValue(0, 7);
}

void ResetGame()
{
    score = 0;
    gameover = 0;
    Tetromino_down_timer = Tetromino_timer;

    for(int y = 1; y < STAGE_HEIGHT - 1; y++)
    {
        for(int x = 1; x < STAGE_WIDTH -1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int color = stage[offset];

            if(stage[offset] != 0)
            {
                stage[offset] = 0;
            }
        }
    }
}

int main(int argc, char** argv)
{
    #pragma region Init_Functions_And_Variables
    Init_functions();

    // setting world start screen offset 
    const int startOffsetX = (WINDOWWIDTH / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    const int startOffsetY = (WINDOWHEIGHT / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);
    
    // Initialize font and position
    Font font = LoadFont("Font/Tetris_font.ttf");                                   
    Vector2 Score_position = {startOffsetX + WINDOWWIDTH / 2, tetrominoStartY + 200};   

    // Initialize Random value
    time(&Unix_time);
    SetRandomSeed(Unix_time);

    // Initialize timer & random value for tetromino
    Tetromino_down_timer = Tetromino_timer;
    Current_color = GetRandomValue(0, 7);
    Current_tetromino_type = GetRandomValue(0, 6);

    SetTargetFPS(60);

    #pragma endregion Init_Functions_And_Variables

    while(!WindowShouldClose())
    {
        UpdateMusicStream(background_music);
        
        if (gameover == 0)
        {
            Tetromino_down_timer -= GetFrameTime();
            #pragma region Check_Input
            if (IsKeyPressed(KEY_SPACE))
            {
                Current_rotation = Change_Rotation(Current_rotation, Current_tetromino_X, Current_tetromino_Y, Current_tetromino_type);
            }

            if (IsKeyPressed(KEY_RIGHT))
            {
                Current_tetromino_X = Move_right(Current_tetromino_X,Current_tetromino_Y, Current_rotation,Current_tetromino_type);
            }

            if (IsKeyPressed(KEY_LEFT))
            {
                Current_tetromino_X = Move_Left(Current_tetromino_X,Current_tetromino_Y, Current_rotation,Current_tetromino_type);
            }

            if(Tetromino_down_timer <= 0 || IsKeyPressed(KEY_DOWN))
            {            
                if(!CheckCollision(Current_tetromino_X,Current_tetromino_Y+1,tetrominoTypes[Current_tetromino_type][Current_rotation]))
                {
                    Current_tetromino_Y++;
                    Tetromino_down_timer = Tetromino_timer;
                }
                else
                {
                    PlaySound(collision_sound);
                    score = AddPoints(score, 10);
                    Add_tetromino_to_stage(Current_tetromino_type,Current_rotation,Current_tetromino_X,Current_tetromino_Y,Current_color);
                    DeleteLines(line_effect_sound, &score);
        
                    ResetVariables();
                    
                    // Do another check for collision, if return true we have a game over situation
                    if (CheckCollision(Current_tetromino_X,Current_tetromino_Y+1,tetrominoTypes[Current_tetromino_type][Current_rotation]))
                    {
                        //Game over
                        StopMusicStream(background_music);
                        PlaySound(game_over_sound);
                        gameover = 1;
                    }
                }

                if (score > Threshold_value)
                {
                    // As the score increases the speed increases
                    Change_speed(&Tetromino_timer,&Threshold,&Threshold_value);
                }
            }
        #pragma endregion Check_Input
        }
        else if (gameover == 1)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                //resetGame
                ResetGame();
            }   
        }
        else
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                gameover = 0;
            } 
        }
        
        #pragma region Draw
        BeginDrawing();
        ClearBackground(GRAY);

        if (gameover == 0)
        {
            // Game Loop scene
            DrawTextEx(font, TextFormat("Score : \n %06i", score), Score_position,font.baseSize, 4, BLACK);
            drawTetromino(colorTypes[Current_color],startOffsetX, startOffsetY, Current_tetromino_X, Current_tetromino_Y, tetrominoTypes[Current_tetromino_type][Current_rotation]);
            Draw_wall_and_grill(startOffsetX,startOffsetY);
        }
        else if (gameover == 1)
        {
            // Game Over scene
            DrawText("GAME OVER", WINDOWWIDTH /2 - 275, WINDOWHEIGHT/2 - 100,90,BLACK);
            DrawText("Press ENTER to restart..", WINDOWWIDTH /2 - 250, WINDOWHEIGHT/2 + 200,40,BLACK);
        }
        else
        {
            // Start Game scene
            DrawText("TETRIS", WINDOWWIDTH /2 - 275, WINDOWHEIGHT/2 - 100,130,BLACK);
            DrawText("Press ENTER to start the game", WINDOWWIDTH /2 - 275, WINDOWHEIGHT/2 + 200,35,BLACK);
        }
        
        EndDrawing();
        #pragma endregion Draw
    }

    Close_functions();

    return 0;
}
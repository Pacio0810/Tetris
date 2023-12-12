#include "Tetris.h"

#define tetrominoStartX  (STAGE_WIDTH / 2)
#define tetrominoStartY  0

// Inizialize Sound and music
Music background_music;
Sound collision_sound;
Sound rotate_sound;
Sound line_effect_sound;

int score = 0;

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

void ResetVariables(int* currentTetrominoX, int* currentTetrominoY, int* currentTetrominoType, int* currentRotation, int* currentColor)
{
    *currentTetrominoX = tetrominoStartX;
    *currentTetrominoY = tetrominoStartY;
    *currentTetrominoType = GetRandomValue(0, 6);
    *currentRotation = 0;
    *currentColor = GetRandomValue(0, 7);
}

int main(int argc, char** argv)
{
    #pragma region Init_Functions_And_Variables
    Init_functions();
    const int startOffsetX = (WINDOWWIDTH / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2);
    const int startOffsetY = (WINDOWHEIGHT / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);

    
    Font font = LoadFont("Font/Tetris_font.ttf");                                   
    Vector2 Score_position = {startOffsetX + WINDOWWIDTH / 2, tetrominoStartY + 200};   

    int Threshold_value = THRESHOLD_VALUE;
    int Threshold = 1;

    int Current_tetromino_X = tetrominoStartX;
    int Current_tetromino_Y = tetrominoStartY;

    time_t Unix_time;
    time(&Unix_time);

    SetRandomSeed(Unix_time);

    int Current_tetromino_type = GetRandomValue(0, 6);
    int Current_rotation = 0;

    float Tetromino_timer = 1;
    float Tetromino_down_timer = Tetromino_timer;
    int Current_color = GetRandomValue(0, 7);
    
    SetTargetFPS(60);

    #pragma endregion Init_Functions_And_Variables

    while(!WindowShouldClose())
    {
        Tetromino_down_timer -= GetFrameTime();
        UpdateMusicStream(background_music);
        
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
      
                ResetVariables(&Current_tetromino_X, &Current_tetromino_Y, &Current_tetromino_type, &Current_rotation, &Current_color);
            }

            if (score > Threshold_value)
            {
                Change_speed(&Tetromino_timer,&Threshold,&Threshold_value);
            }
            
        }
        #pragma endregion Check_Input
        
        #pragma region Draw
        BeginDrawing();
        ClearBackground(GRAY);

        DrawTextEx(font, TextFormat("Score : \n %06i", score), Score_position,font.baseSize, 4, BLACK);

        drawTetromino(colorTypes[Current_color],startOffsetX, startOffsetY, Current_tetromino_X, Current_tetromino_Y, tetrominoTypes[Current_tetromino_type][Current_rotation]);
        Draw_wall_and_grill(startOffsetX,startOffsetY);
        
        EndDrawing();
        #pragma endregion Draw
    }

    Close_functions();

    return 0;
}
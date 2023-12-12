#include "Tetris.h"

void ResetLines(int startLineY)
{
    for (int y = startLineY; y >= 0; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y+1) * STAGE_WIDTH + x;

            if (stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    } 
}

void DeleteLines(const Sound line_sound, int *score)
{
    int lines_deleted = 0;
    int points = 0;

    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        if(checkLine)
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage+offset,0,(STAGE_WIDTH-2)* sizeof(int));
            PlaySound(line_sound);
            ResetLines(y);
            lines_deleted++;
        }
    }

    points = POINTS_FOR_LINE * lines_deleted;

    if (lines_deleted == 4)
    {
        points = POINTS_FOR_LINE * lines_deleted * 2;               //Tetris = 400 bonus points
    }

    *score = AddPoints(*score, points);
}

void Change_speed(float* TetrominoTimer, int* Threshold, int* Threshold_value)
{
    *TetrominoTimer = *TetrominoTimer / 1.2f;
    (*Threshold) ++;
    *Threshold_value = THRESHOLD_VALUE * (*Threshold);      
}

int AddPoints(int score, const int points_to_add)
{
    score = score + points_to_add;
    return score;
}
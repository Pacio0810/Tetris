#include "Tetris.h"

int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if(tetromino[offset] == 1)
            {
                const int offset_stage = (y + tetrominoStartY) * STAGE_WIDTH + (x +tetrominoStartX);

                if (stage[offset_stage] != 0)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int Change_Rotation(int currentRotation, const int currentTetrominoX, const int currentTetrominoY, const int currentTetrominoType)
{
    const int lastRotation = currentRotation;

    currentRotation++;

    if (currentRotation > 3)
    {
        currentRotation = 0;
    }

    if (CheckCollision(currentTetrominoX,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
    {
        currentRotation = lastRotation;
    }

    PlaySound(rotate_sound);

    return currentRotation;
}

int Move_right(int currentTetrominoX, const int currentTetrominoY, const int currentRotation, const int currentTetrominoType)
{
    // No need to check overflow, wall is your protector
    if (!CheckCollision(currentTetrominoX+1,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
    {
        currentTetrominoX++;
        return currentTetrominoX;
    }
    return currentTetrominoX;
}

int Move_Left(int currentTetrominoX, const int currentTetrominoY, const int currentRotation, const int currentTetrominoType)
{
    // No need to check overflow, wall is your protector
    if (!CheckCollision(currentTetrominoX-1,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
    {
        currentTetrominoX--;
        return currentTetrominoX;
    }
    return currentTetrominoX;
}
#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

#define WINDOWHEIGHT 700
#define WINDOWWIDTH 600

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24

#define TETROMINO_SIZE 4

#define THRESHOLD_VALUE 400

// define for Path and Volume value
#define BACKGROUND_MUSIC_PATH "Sound/Tetris_SoundTrack.mp3"
#define BACKGROUND_MUSIC_VOLUME 0.2f
#define COLLISION_SOUND_PATH "Sound/Collision_sound.wav"
#define COLLISION_SOUND_VOLUME 1
#define ROTATE_SOUND_PATH "Sound/Rotate_sound.wav"
#define ROTATE_SOUND_VOLUME 1
#define LINE_SOUND_PATH "Sound/Lines_effect_sound.mp3"
#define LINE_SOUND_VOLUME 1
#define GAME_OVER_SOUND_PATH "Sound/Game_over_sound.mp3"
#define GAME_OVER_SOUND_VOLUME 1

#define POINTS_FOR_LINE 100

extern const int *tetrominoTypes[7][4];
extern int stage[];
extern Color colorTypes[8];

// extern music & sound variables
extern Music background_music;
extern Sound collision_sound;
extern Sound rotate_sound;
extern Sound line_effect_sound;
extern Sound game_over_sound;

#pragma region Movement
int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

int Change_Rotation(int currentRotation, const int currentTetrominoX, const int currentTetrominoY, const int currentTetrominoType);

int Move_right(int currentTetrominoX, const int currentTetrominoY, const int currentRotation, const int currentTetrominoType);

int Move_Left(int currentTetrominoX, const int currentTetrominoY, const int currentRotation, const int currentTetrominoType);
#pragma endregion Movement

#pragma region Draw
void Draw_wall_and_grill(const int startOffsetX, const int startOffsetY);

void drawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

void Add_tetromino_to_stage(const int currentTetrominoType, const int currentRotation, const int currentTetrominoX, const int currentTetrominoY, const int currentColor);
#pragma endregion Draw

void Init_Sounds();

#pragma region Game_Functions
int AddPoints(int score, const int points_to_add);

void ResetLines(int startLineY);

void DeleteLines(const Sound line_sound, int *score);

void Change_speed(float* TetrominoTimer, int* Threshold, int* Threshold_value);
#pragma endregion Game_Functions
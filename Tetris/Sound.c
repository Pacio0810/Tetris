#include "Tetris.h"

Music background_music;
Sound collision_sound;
Sound rotate_sound;
Sound line_effect_sound;
Sound game_over_sound;

Music Add_music(const char* file_path, const int loop, const float volume_value)
{
    Music music = LoadMusicStream(file_path);
    music.looping = loop;
    PlayMusicStream(music);
    SetMusicVolume(music, volume_value);

    return music;
}

Sound Add_sound(const char* file_path, const float volume_value)
{
    Sound sound = LoadSound(file_path);
    SetSoundVolume(sound, volume_value);

    return sound;
}

void Init_Sounds()
{
    background_music = Add_music(BACKGROUND_MUSIC_PATH, 1, BACKGROUND_MUSIC_VOLUME);
    collision_sound = Add_sound(COLLISION_SOUND_PATH, COLLISION_SOUND_VOLUME);
    rotate_sound = Add_sound(ROTATE_SOUND_PATH, ROTATE_SOUND_VOLUME);
    line_effect_sound = Add_sound(LINE_SOUND_PATH, LINE_SOUND_VOLUME);
    game_over_sound = Add_sound(GAME_OVER_SOUND_PATH, GAME_OVER_SOUND_VOLUME);
}
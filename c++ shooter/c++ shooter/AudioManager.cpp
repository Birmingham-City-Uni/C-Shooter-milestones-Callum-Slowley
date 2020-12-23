#include "AudioManager.h"

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{
}

void AudioManager::PlayMusic(std::string fileName, int loops)
{
	Mix_PlayMusic(Mix_LoadMUS(fileName.c_str()), loops);
}

void AudioManager::PlaySFX(std::string fileName, int loops, int channel)
{
	Mix_PlayChannel(channel, Mix_LoadWAV(fileName.c_str()), loops);
}

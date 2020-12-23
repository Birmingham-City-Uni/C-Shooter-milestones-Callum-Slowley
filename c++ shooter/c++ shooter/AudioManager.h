#pragma once

#include <Windows.h>
#include <dsound.h>
#include <SDL_mixer.h>
#include<iostream>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();
	void PlayMusic(std::string fileName, int loops = -1);
	void PlaySFX(std::string fileName, int loops = 0,int channel=0);
private:

};


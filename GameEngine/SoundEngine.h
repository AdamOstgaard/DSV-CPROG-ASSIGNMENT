#pragma once
#include <string>
#include <vector>
#ifdef APPLE
#include "SDL2/SDL_mixer.h"
#elif _WIN32
#include <SDL_mixer.h>
#endif
#include "ResourcePath.h"


class SoundEngine {
public: 
	int SoundEngine::playSound(std::string FilePath = "DefaultBgMusic", int channel = -1, int volume = 64, int loops = -1);
	static SoundEngine * getInstance();
	void stopSound(int channel);
	void initalize();
	virtual ~SoundEngine();
private:
	SoundEngine();
	std::vector<Mix_Chunk*> sounds;
};


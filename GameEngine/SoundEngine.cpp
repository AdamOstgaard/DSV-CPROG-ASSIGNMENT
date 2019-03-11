#include "SoundEngine.h"
#ifdef APPLE
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

SoundEngine::SoundEngine() {

}

void SoundEngine::initalize() {
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
	int volume = 64;
}
SoundEngine::~SoundEngine()
{
	for (auto sound : sounds) {
		Mix_FreeChunk(sound);
	}
	Mix_CloseAudio();
	Mix_Quit();
}

int SoundEngine::playSound(std::string FilePath, int channel, int volume, int loops){
	auto sound = Mix_LoadWAV((RESOURCE_PATH + FilePath).c_str());
	sounds.push_back(sound);
	Mix_Volume(channel, volume);
	return Mix_PlayChannel(channel, sound,loops);
}

void SoundEngine::stopSound(int channel) {
	Mix_FadeOutChannel(channel, 0);
}

SoundEngine * SoundEngine::getInstance() {
	return new SoundEngine();
}

#pragma once
#include "Sprite.h"

#if APPLE
#include "SDL2/SDL.h"
#else 
#include "SDL.h"
#endif

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "PlayerSprite.h"
#include "SoundEngine.h"

class GameEngine
{
private:
	std::vector<Sprite*> tickEventHandlers;
	std::unordered_set<Sprite*> tempTickRemoveList;
	std::unordered_set<Sprite*> tempTickAddList;
	std::vector<PlayerSprite*> userEventHandlers; //uppdatera typen längre fram

public:
	static GameEngine * getinstance();
	~GameEngine();
	struct GameSettings;
	void removeAllMario();
	void run(GameSettings settings);
	void queueRemoveSprite(Sprite * sprite);
	void queueAddSprite(Sprite * sprite);
	void PollForSDLEvent();
	void initialize(GameSettings settings);
	void installSprite(Sprite* sprite);
	SDL_Rect getWindowsSize();
	void installPlayerSprite(PlayerSprite * sprite);
	std::vector<Sprite*>* getSprites();
	void shutDown();

	typedef struct GameSettings
	{
		const int MAX_FRAME_RATE = 60;
		const std::string GAME_NAME = "Adam o Andreas gör ett spel";
		const int HEIGHT = 700;
		const int WIDTH = 1400;
		const SDL_Color BG_COLOR = { 255,255,255,255 };
	};
	SoundEngine * getSoundEngine();
private:
	SoundEngine* soundEngine;
	void removeSprites();
	void removeSprite(Sprite * s);
	GameEngine();
	SDL_Renderer* renderer;
	void addSprites();
	void tick();
	bool quit;
};
#pragma once
#include "SDL.h"
#include <string>
class GameEngine
{
public:

	GameEngine();
	~GameEngine();
	struct GameSettings;
	void run(GameSettings settings);
	void createWindow(GameSettings settings);

	typedef struct GameSettings
	{
		const int MAX_FRAME_RATE = 60;
		const std::string GAME_NAME = "Adam o Andreas gör ett spel";
		const int HEIGHT = 1600;
		const int WIDTH = 700;
		const SDL_Color BG_COLOR = { 255,255,255,255 };
	};
private:
	void tick();
};
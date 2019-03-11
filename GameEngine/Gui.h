#pragma once
#ifdef APPLE
#include "SDL2/SDL_ttf.h"
#elif _WIN32
#include <SDL_ttf.h>
#endif
#include "GameEngine.h"
#include "TextElement.h";

class GameEngine;
class MarioShooterGame;
class Gui
{
public:
	Gui();
	~Gui();
	void initialize(SDL_Renderer * r, SDL_Rect * ws, GameEngine * ge, MarioShooterGame * mg);
	void install(TextElement * textElement);
	void tick();
	void render();
	static Gui* getInstance();
private:
	std::vector<TextElement*> textElements;
	GameEngine * gameEngine;
	MarioShooterGame* marioShooterGame;
	SDL_Renderer* renderer;
	SDL_Rect* windowSize;
	Gui(const Gui&);
    Gui* operator=(const Gui&);
};


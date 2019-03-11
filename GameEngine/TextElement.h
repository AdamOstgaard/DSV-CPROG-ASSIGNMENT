#pragma once
#include <string>
#include "ResourcePath.h"
#if APPLE
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#else 
#include "SDL.h"
#include <SDL_ttf.h>
#endif

class GameEngine;
class MarioShooterGame;

class TextElement
{
public:
	TextElement::TextElement(std::string n, SDL_Point p);
	virtual ~TextElement();
	virtual void tick() = 0;
	virtual void initialize(SDL_Renderer * r, GameEngine * ge, MarioShooterGame * msg);
	void updateTexture();
	void render();
private:
	std::string name;
	SDL_Texture* texture = NULL;
	int width, height;
	TextElement(const TextElement& other) = delete;
protected:
	SDL_Point point;
	std::string text;
	SDL_Color color;
	TTF_Font* font;
	SDL_Rect rect;
	SDL_Renderer* renderer;
	GameEngine* gameEngine;
	MarioShooterGame*  marioGame;
};


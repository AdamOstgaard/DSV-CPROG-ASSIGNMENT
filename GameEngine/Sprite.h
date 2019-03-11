#pragma once
#if APPLE
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#else 
#include "SDL.h"
#include "SDL_image.h"
#endif

#include <string>
#include <vector>

class GameEngine;
class Sprite
{
public:	
	virtual ~Sprite();
	void initialize(SDL_Renderer * r, SDL_Rect ws, GameEngine * e);
	void update(std::vector<Sprite*>*);
	const SDL_Rect * getRect();
	void setTexture(std::string tp);
	virtual void tick(const std::vector<Sprite*> *) = 0;
	GameEngine * getGameEngine();
	struct Position {
		int x;
		int y;
	} position;
	virtual void hit() = 0;
	const std::string getName();
	const SDL_Texture* getTexture();
private:
	std::string name;
	SDL_Texture* texture;
	GameEngine * gameEngine ;
	Sprite(const Sprite&);
	//Sprite* operator=(const Sprite&);
	void render();
	SDL_Renderer* renderer;
	SDL_Rect rect;
	std::string texturePath;
protected:
	int width;
	int height;
	SDL_Rect windowSize;
	Sprite(std::string imagePath, Position pos, std::string n);
	SDL_Point getCenter();
};


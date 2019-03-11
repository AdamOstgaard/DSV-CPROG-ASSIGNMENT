#pragma once
#include "MovingSprite.h"
#include <vector>
class PlayerSprite :
	public MovingSprite
{
public:
	PlayerSprite(std::string imagePath, Position startingPosition);
	~PlayerSprite();
	static PlayerSprite * getInstance(std::string imagePath, Position startingPosition);
	void handleInput(SDL_Event event, const std::vector<Sprite*> *);
	void shoot();
};


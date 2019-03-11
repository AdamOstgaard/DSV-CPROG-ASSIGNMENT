#include "MovingSprite.h"
#include "Sprite.h"
#include <vector>
#include <iostream>

MovingSprite::MovingSprite(std::string imgPath ,Position p, std::string n) : Sprite(imgPath, p, n)
{

}


MovingSprite::~MovingSprite()
{
}

void MovingSprite::hit()
{
	
}

void MovingSprite::tick(const std::vector<Sprite*> * allSprites )
{
}

Sprite * MovingSprite::getCollision(SDL_Rect rect, const std::vector<Sprite*> * sprites) {
	for (auto i : *sprites) {
		if (i == this) {
			continue;
			// std::cout << "selfcollide";
		}
		if (checkCollision(*(i->getRect()), rect)) {
			// std::cout << "collision";
			return i;
		}
	}
	return nullptr;
}

bool MovingSprite::checkWallCollision(const SDL_Rect rect) {

	SDL_Rect windoWrect = {0,0,windowSize.h,windowSize.w};
	return !(checkCollision(rect, windowSize));

}

bool MovingSprite::checkCollision(const SDL_Rect a, const SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
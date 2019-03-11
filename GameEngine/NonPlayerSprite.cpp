#include "NonPlayerSprite.h"
#include "GameEngine.h"
#include "ExplosionSprite.h"

Direction NonPlayerSprite::direction = RIGHT;
int NonPlayerSprite::row = 0;

void NonPlayerSprite::tick(const std::vector<Sprite*>* allSprites) {
	move(allSprites);
}

void NonPlayerSprite::move(const std::vector<Sprite*>* allSprites) {
	double speedMultiplier = 1.7;
	int baseSpeed = 5;
	int speed = baseSpeed + speedMultiplier * row;

	int ySpeed = 20;
	int yPos = row * ySpeed;

	if (direction == RIGHT) {
		SDL_Rect nextPosition = { position.x + speed, yPos, width, height };
		bool changeDirection = checkWallCollision(nextPosition);
		if (changeDirection) {
			direction = LEFT;
			position.x += speed;
			row++;
		}
		else {
			position.x += speed;
			position.y = yPos;
		}
	}
	else if (direction == LEFT) {
		SDL_Rect nextPosition = { position.x - speed, yPos, width, height};
		bool changeDirection = checkWallCollision(nextPosition);
		if (changeDirection) {
			direction = RIGHT;
			position.x += speed;
			row++;
		}
		else {
			position.x -= speed;
			position.y = yPos;
		}
	}
}

NonPlayerSprite* NonPlayerSprite::getInstance(std::string filePath, Position position){
	return new NonPlayerSprite(filePath, position);
}

NonPlayerSprite::NonPlayerSprite(std::string filePath, Position position, std::string n): MovingSprite(filePath, position, n)
{
}

void NonPlayerSprite::hit() {
	auto explosionSprite = ExplosionSprite::getInstance({ -999,-999 }, 100);
	int explosionWidth = explosionSprite->getRect()->w;
	int explosionHeight = explosionSprite -> getRect()->h;
	auto center = getCenter();
	
 	explosionSprite->setCenter(center);

	auto engi = getGameEngine();
	engi->queueAddSprite(explosionSprite);
	engi->queueRemoveSprite(this);
}

NonPlayerSprite::~NonPlayerSprite()
{
}


#include "ExplosionSprite.h"
#include "GameEngine.h"

ExplosionSprite * ExplosionSprite::getInstance(Position pos, int ticks)
{
	return new ExplosionSprite(pos, ticks);
}

ExplosionSprite::~ExplosionSprite()
{
}


ExplosionSprite::ExplosionSprite(Position pos, int ticks, std::string n) : Sprite("explosion.gif", pos, n), ticksLeft(ticks)
{
}

// sets the center for next render
void ExplosionSprite::setCenter(SDL_Point position) {
	center = position;
}

void ExplosionSprite::tick(const std::vector<Sprite*>* allSprites) {
	position = {
		center.x - width / 2,
		center.y - height / 2
	};
	if (--ticksLeft) {
		return;
	}
	getGameEngine()->queueRemoveSprite(this);
}

void ExplosionSprite::hit() {
	
}
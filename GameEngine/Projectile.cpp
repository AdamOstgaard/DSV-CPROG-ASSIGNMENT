#include "Projectile.h"
#include "GameEngine.h"

Projectile* Projectile::getInstance(Position pos, Direction dir) {
	return new Projectile(pos,dir);
}

Projectile::Projectile(Position pos, Direction dir, std::string n): MovingSprite("sword.png",pos, n), direction(dir)
{
   
}


Projectile::~Projectile()
{
}

void Projectile::hit() {

}

void Projectile::tick(const std::vector<Sprite*>* allSprites) {
	SDL_Rect nextPosition = { position.x + 0,position.y - 5,getRect()->w,getRect()->h };
	auto hitSprite = getCollision(nextPosition, allSprites);

	if (checkWallCollision(nextPosition)) {
		auto engine = getGameEngine();
		engine->queueRemoveSprite(this);
	}
	else if (hitSprite != nullptr && hitSprite->getName() == "NonPlayerSprite") {
		hitSprite->hit();
		auto engine = getGameEngine();
		engine->queueRemoveSprite(this);
	}
	position = {position.x, position.y - 5 };
}
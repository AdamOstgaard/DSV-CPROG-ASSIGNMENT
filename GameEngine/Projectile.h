#pragma once
#include "Direction.h"
#include "MovingSprite.h"
#include <string>

class Projectile : public MovingSprite
{
public:
	static Projectile * getInstance(Position pos, Direction dir);
	~Projectile();
	void hit() override;
	void tick(const std::vector<Sprite*>* allSprites);
private:
	Projectile(Position pos, Direction dir, std::string n = "Projectile");
	Direction direction;
};


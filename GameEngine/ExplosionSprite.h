#pragma once
#include "Sprite.h"


class ExplosionSprite : public Sprite
{
public:
	static ExplosionSprite * getInstance(Position pos, int ticks);

	~ExplosionSprite();
	void setCenter(SDL_Point position);
	void tick(const std::vector<Sprite*>* allSprites) override;
	void hit() override;
private: 
	ExplosionSprite(Position pos, int ticks, std::string n = "Explsion");
	int ticksLeft;
	SDL_Point center;
};


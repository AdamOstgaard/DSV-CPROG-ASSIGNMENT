#pragma once
#include "Sprite.h"
#include <string>
#include <vector>

class MovingSprite :
	public Sprite
{
public:
	static MovingSprite* getInstance(std::string s, Position p) {
		return new MovingSprite(s,p);
	}
	virtual ~MovingSprite();
	void hit() override;
	bool checkCollision(const SDL_Rect a, const SDL_Rect b);
	Sprite * getCollision(SDL_Rect rect, const std::vector<Sprite*>* sprites);
protected:
	MovingSprite(std::string imgPath, Position p, std::string n = "MovingSprite");
	bool checkWallCollision(const SDL_Rect rect);
	void tick(const std::vector<Sprite*>* allSprites) override;
private:
};



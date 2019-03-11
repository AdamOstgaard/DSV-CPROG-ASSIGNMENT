#pragma once
#include <string>
#include "MovingSprite.h"
#include "Direction.h"


class NonPlayerSprite :
	public MovingSprite
{
public:
	static NonPlayerSprite* getInstance(std::string filePath, Position position);
	~NonPlayerSprite();
	void tick(const std::vector<Sprite*>* allSprites) override;
private:
	void move(const std::vector<Sprite*>* allSprites);
	static Direction direction;
	NonPlayerSprite(std::string filePath, Position position, std::string n = "NonPlayerSprite");
	void hit() override;
	static int row;
};



#include "Score.h"
#include "MarioShooterGame.h"

Score::Score(SDL_Point p, std::string n) : TextElement(n,p)
{
	text = "SCORE: 0";
}

void Score::tick() {
	std::string temp = "SCORE: " + std::to_string(marioGame->getScore());
	if (temp.compare(text)) {
		text = temp;
		updateTexture();
	}
}

Score * Score::getInstance(SDL_Point p, std::string n)
{
	return new Score(p,n);
}

Score::~Score()
{
}

#pragma once
#include "TextElement.h"

class Score: public TextElement
{
public:
	static Score* getInstance(SDL_Point p,std::string n = "Score");
private:
	Score(SDL_Point p, std::string n);
	void tick();
	~Score();
};


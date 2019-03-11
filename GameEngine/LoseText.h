#pragma once
#include "TextElement.h"
class LoseText :
	public TextElement
{
public:
	static LoseText* getInstance();
	~LoseText();
	void tick();
private:
	LoseText();
	void initialize(SDL_Renderer * r, GameEngine * ge, MarioShooterGame * msg);
};


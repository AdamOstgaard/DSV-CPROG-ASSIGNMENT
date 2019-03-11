#include "LoseText.h"
#include <cstdlib>
#include "GameEngine.h"

LoseText::LoseText() : TextElement("YOU LOST",{0,0})
{
	text = "YOU LOST";
	updateTexture();
}

void LoseText::initialize(SDL_Renderer * r, GameEngine * ge, MarioShooterGame * msg) {
	TextElement::initialize(r, ge, msg);
	point = { std::rand() % (ge->getWindowsSize().w) , std::rand() % ge->getWindowsSize().h };
	updateTexture();
}


LoseText * LoseText::getInstance()
{
	return new LoseText();
}

LoseText::~LoseText()
{
}

void LoseText::tick()
{
	
}

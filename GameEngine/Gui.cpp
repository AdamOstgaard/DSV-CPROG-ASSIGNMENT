#include "Gui.h"

Gui::Gui()
{
}


Gui::~Gui()
{
	for (auto text : textElements)
		delete text;
	TTF_Quit();
}

void Gui::initialize(SDL_Renderer * r, SDL_Rect* ws, GameEngine * ge, MarioShooterGame* mg)
{
	TTF_Init();
	renderer = r;
	windowSize = ws;
	gameEngine = ge;
	marioShooterGame = mg;
}

void Gui::install(TextElement* textElement)
{
	
	textElements.push_back(textElement);
	textElement->initialize(renderer, gameEngine, marioShooterGame);
	textElement->updateTexture();
}

void Gui::tick()
{
	for (auto o : textElements) {
		o->tick();
	}
}

Gui * Gui::getInstance()
{
	return new Gui();
}

void Gui::render()
{
	for (auto o : textElements) {
		o->render();
	}
}

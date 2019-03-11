#include "TextElement.h"
#include <string>

TextElement::TextElement(std::string n, SDL_Point p): name(n), point(p)
{
	font = TTF_OpenFont((RESOURCE_PATH+"comic.ttf").c_str(), 36);
}

TextElement::~TextElement()
{
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void TextElement::tick()
{

}

void TextElement::initialize(SDL_Renderer * r, GameEngine * ge, MarioShooterGame * msg) {
	renderer = r;
	gameEngine = ge;
	marioGame = msg;
}

void TextElement::updateTexture() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
	}
	auto surface = TTF_RenderText_Solid(font,text.c_str(), {255,0,0});
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
}

void TextElement::render()
{
	rect = {
		point.x,
		point.y,
		width,
		height
	};
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

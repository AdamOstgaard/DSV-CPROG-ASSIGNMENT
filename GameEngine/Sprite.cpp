#include "Sprite.h"
#include "GameEngine.h"
#include <string>
#include "ResourcePath.h"

Sprite::Sprite(std::string imagePath, Position pos, std::string n) : texturePath(imagePath), position(pos), name(n)
{

}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

SDL_Point Sprite::getCenter() {
	return {
		position.x + width / 2,
		position.y + height / 2
	};
}

void Sprite::initialize(SDL_Renderer* r, SDL_Rect ws, GameEngine * e) {
	gameEngine = e;
	windowSize = ws;
	renderer = r;
	setTexture(texturePath);
}

void Sprite::update(std::vector<Sprite*>* allSprites) {
	tick(allSprites);
	render();
}

const SDL_Rect * Sprite::getRect() {
	return &rect;
}

void Sprite::setTexture(std::string tp)
{
	texturePath = tp;
	auto surface = IMG_Load((RESOURCE_PATH + tp).c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
}

GameEngine * Sprite::getGameEngine()
{
	return gameEngine;
}

const std::string Sprite::getName()
{
	return name;
}

const SDL_Texture * Sprite::getTexture()
{
	return texture;
}

void Sprite::render() {
	rect = {
		position.x,
		position.y,
		width,
		height
	};
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

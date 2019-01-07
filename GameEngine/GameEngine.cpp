#include "GameEngine.h"
#include "SDL.h"
#include <iostream>
#include <string>

SDL_Window* window;
SDL_Surface* screenSurface;

GameEngine::GameEngine()
{
	window = NULL;
	screenSurface = NULL;
}

GameEngine::~GameEngine()
{
}

void GameEngine::run(GameEngine::GameSettings settings) {
	// add tick	
	tick();
}

void GameEngine::tick() {
	while (true) {
		SDL_Delay(200);
	}
}

void GameEngine::createWindow(GameEngine::GameSettings settings) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf(" SDL could not be initialized!");
	}
	else {
		window = SDL_CreateWindow(settings.GAME_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,settings.HEIGHT, settings.WIDTH,
			SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Could not create Game Window!");
		}
		else {
		   screenSurface = SDL_GetWindowSurface(window);
		   SDL_FillRect(screenSurface, NULL, SDL_MapRGBA(
			   screenSurface->format, 
			   settings.BG_COLOR.r, 
			   settings.BG_COLOR.b, 
			   settings.BG_COLOR.g, 
			   settings.BG_COLOR.a)
		   );
		}
	}
}
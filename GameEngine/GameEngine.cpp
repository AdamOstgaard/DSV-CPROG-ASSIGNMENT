#ifdef APPLE
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif
#include "GameEngine.h"
#include <vector>
#include "MovingSprite.h"
#include "NonPlayerSprite.h"
#include "MarioShooterGame.h"


SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* renderer;

GameEngine* GameEngine::getinstance(){
	return new GameEngine();
}

GameEngine::GameEngine()
{
}

SoundEngine* GameEngine::getSoundEngine() {
	return soundEngine;
}

void GameEngine::installSprite(Sprite* sprite) {

	sprite->initialize(renderer, getWindowsSize(), this);
	tickEventHandlers.push_back(sprite);
}

SDL_Rect GameEngine::getWindowsSize() {
	int windowHeight, windowWidth;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	return { 0,0,windowWidth, windowHeight};
}

void GameEngine::installPlayerSprite(PlayerSprite* sprite) {
	installSprite(sprite);
	userEventHandlers.push_back(sprite);
}

std::vector<Sprite*>* GameEngine::getSprites()
{
	return &tickEventHandlers;
}

void GameEngine::shutDown()
{
	for (auto s : tickEventHandlers)
		delete s;
	delete soundEngine;
	SDL_RenderClear(renderer);
	SDL_FreeSurface(screenSurface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

void GameEngine::removeSprite(Sprite * s) {
	for (int i = 0; i < tickEventHandlers.size(); i++) {
		if (tickEventHandlers[i] == s) {
			tickEventHandlers.erase(tickEventHandlers.begin() + i);
		}
	}
	delete s;
}

GameEngine::~GameEngine()
{	
}

int counter = 0;

void GameEngine::removeAllMario() {
	for (auto i : tickEventHandlers) {
		if (i->getName() == "NonPlayerSprite") {
			queueRemoveSprite(i);
		}
	}
}

void GameEngine::run(GameEngine::GameSettings settings) {
	auto game = MarioShooterGame::getInstance(this,renderer);
	
	game->startGame();

	quit = false;
	const int tickInterval = 1000 / settings.MAX_FRAME_RATE;
	int delay = 0;

	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		removeSprites();
		addSprites();

		PollForSDLEvent();
		
		SDL_RenderClear(renderer);
		tick();
		game->tick();
		SDL_RenderPresent(renderer);

		delay = nextTick - SDL_GetTicks();
		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

	delete game;
	shutDown();
}

void GameEngine::queueRemoveSprite(Sprite* sprite) {
	tempTickRemoveList.insert(sprite);
}

void GameEngine::queueAddSprite(Sprite* sprite) {
	tempTickAddList.insert(sprite);
}

void GameEngine::removeSprites() {
	for (auto sprite : tempTickRemoveList) {
		removeSprite(sprite);
	}
	tempTickRemoveList.clear();
}
void GameEngine::addSprites() {
	for (auto sprite : tempTickAddList)
		installSprite(sprite);
	tempTickAddList.clear();
}

void GameEngine::PollForSDLEvent() {
	SDL_Event sdlEvent;
	
	while (SDL_PollEvent(&sdlEvent)) {
		for (auto i : userEventHandlers) {
			/// userEventHandlers.userInput(sdlEvent);
			i->handleInput(sdlEvent, &tickEventHandlers);
		}
		if (sdlEvent.type == SDL_KEYDOWN && sdlEvent.key.keysym.sym == 'k') {
			removeAllMario();
		}
		if (sdlEvent.type == SDL_QUIT) {
			quit = true;
		}
	}	
}

void GameEngine::tick() 
{
	for (Sprite* item : tickEventHandlers) {
		item->update(&tickEventHandlers);
	}
}

void GameEngine::initialize(GameEngine::GameSettings settings) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf(" SDL could not be initialized!");
	}
	else {
		window = SDL_CreateWindow(settings.GAME_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,settings.WIDTH, settings.HEIGHT,
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
		  
		   renderer = SDL_CreateRenderer(window,-1,0);
		   soundEngine = SoundEngine::getInstance();
		   soundEngine->initalize();
		}
	}
}

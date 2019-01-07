#include "GameEngine.h"
#include "Main.h"
#include "SDL.h"

int main(int argc, char* args[]) {
	GameEngine* gm = new GameEngine();
	GameEngine::GameSettings settings = {};
	gm->createWindow(settings);
	gm->run(settings);
	return 0;
}
#include "GameEngine.h"
#include "Main.h"
#include <windows.h>
#include <iostream>
#include <fstream>


int main(int argc, char* args[]) {
	GameEngine* gm = GameEngine::getinstance();
	gm->initialize({});
	gm->run({});
	delete gm;
	Sleep(100000);
	return 0;
}
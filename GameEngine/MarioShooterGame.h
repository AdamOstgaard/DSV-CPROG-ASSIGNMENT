#pragma once
#include "GameEngine.h"
#include "Gui.h";

class MarioShooterGame
{
public:
	static MarioShooterGame * getInstance(GameEngine * ge, SDL_Renderer * r);
	void startGame();
	void spawnMarios(int numberOfMarios);
	~MarioShooterGame();
	void tick();
	int getScore();
private:
	MarioShooterGame(GameEngine * ge, SDL_Renderer * r);
	void spawnScore();
	bool testWinCondition();
	int countMarios();
	GameEngine * gameEngine;
	int bgMusicChannel;
	bool gameIsRunning = true;
	Gui * gui;
	SDL_Renderer * renderer;
	int score = 0;
	const int MARIO_COUNT = 20;
    bool testLoseCondition();
};


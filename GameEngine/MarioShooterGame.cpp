#include "MarioShooterGame.h"
#include "NonPlayerSprite.h"
#include "Score.h"
#include "LoseText.h"


MarioShooterGame::MarioShooterGame(GameEngine * ge, SDL_Renderer * r) : gameEngine(ge), renderer(r)
{
	gui = Gui::getInstance();
	gui->initialize(r, &ge->getWindowsSize(), ge, this);
}

MarioShooterGame * MarioShooterGame::getInstance(GameEngine * ge, SDL_Renderer * r)
{
	return new MarioShooterGame(ge, r);
}

void MarioShooterGame::startGame() {
	bgMusicChannel = gameEngine->getSoundEngine()->playSound("bgMusic.wav");
	gameEngine->installPlayerSprite(PlayerSprite::getInstance("link.png", { 500,500 }));
	spawnMarios(MARIO_COUNT);
}

void MarioShooterGame::spawnMarios(int numberOfMarios) {
	for (int i = 0; i < numberOfMarios; i++) {
		gameEngine->queueAddSprite(NonPlayerSprite::getInstance("super-mario.gif", { 50 + i*50,50 }));
	}
	spawnScore();
}


MarioShooterGame::~MarioShooterGame()
{
	delete gui;
}

void MarioShooterGame::tick()
{
    

	score = MARIO_COUNT - countMarios();
	if (testWinCondition() && gameIsRunning) {
		gameIsRunning = false;
		gameEngine->getSoundEngine()->stopSound(bgMusicChannel);
		gameEngine->getSoundEngine()->playSound("winMusic.wav");
	}
	if (testLoseCondition()) {
		gui->install(LoseText::getInstance());
	}
	gui->tick();
	gui->render();
}

bool MarioShooterGame::testLoseCondition() {
	//Trigger lose
	auto sprites = gameEngine->getSprites();
	int c = 0;
	for (auto sprite : *sprites) {
		if(sprite->getName() != "PlayerSprite"){
			continue;
		}
		auto temp = dynamic_cast<PlayerSprite*>(sprite);
		if (temp) {
			auto col = temp->getCollision(*(temp->getRect()), sprites);
			if (col != NULL && col->getName() == "NonPlayerSprite")
				return true;
		}
	}
	return false;
}

int MarioShooterGame::getScore()
{
	return score;
}

void MarioShooterGame::spawnScore()
{
	auto score = Score::getInstance({500,500});
	gui->install(score);
}

bool MarioShooterGame::testWinCondition() {
	return !countMarios();
}

int MarioShooterGame::countMarios() {
	auto sprites = gameEngine->getSprites();
	int c = 0;
	for (auto sprite : *sprites) {
		if (sprite->getName() == "NonPlayerSprite") c++;
	}
	return c;
}
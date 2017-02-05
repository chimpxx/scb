#include "Game.h"

Game::Game(IcatGame *icatGame)
	:icatGame(icatGame)
{
	levelLoader = new LevelLoader(icatGame);
	worldPtr = nullptr;
}


Game::~Game()
{
}

void Game::clearScene() {
	if (!worldPtr)
		worldPtr = new b2World(gravity);
}

void Game::initLevel(int levelNum) {
	clearScene();
	currentGameScene = levelLoader->load(levelNum, worldPtr);
	player = levelLoader->player;
	icatGame->setScenePtr(currentGameScene);
}

void Game::update() {
	worldPtr->Step(0.2f, 8, 3);
	updateKeyEvents();
	player->update(icatGame->getDeltaTime());
}

void Game::updateKeyEvents() {
	if (UserInteraction::rightDown) {
        player->runRight();
        /*if (!UserInteraction::spacePress)
            player->runRight();
        else
            player->turnRight();*/
    }
	if (UserInteraction::leftDown) {
        player->runLeft();
        /*if (!UserInteraction::spacePress)
            player->runLeft();
        else
            player->turnLeft();*/
    }
    if (UserInteraction::spacePress) {
        player->jump();
        UserInteraction::spacePress = false;
    }
}
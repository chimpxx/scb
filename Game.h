#ifndef _GAME_H_
#define _GAME_H_

#include <Box2D/Box2D.h>

#include "IcatGame.h"
#include "LevelLoader.h"

class Game
{
public:
	Game(IcatGame *icatGame);
	~Game();
	void initLevel(int levelNum);
	void update();

private:
	void updateKeyEvents();
	void clearScene();

private:
	IcatGame *icatGame;
	LevelLoader* levelLoader;
	Scene* currentGameScene;
	Player* player;

	b2Vec2 gravity{ 0.0f, -2.0f };
	b2World *worldPtr;

};

#endif _GAME_H_
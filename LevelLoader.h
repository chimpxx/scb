#ifndef _LEVEL_LOADER_H_
#define _LEVEL_LOADER_H_

#include <fstream>
#include <sstream>
#include <iomanip>

#include "IcatGame.h"
#include "Scene.h"
#include "Brick.h"
#include "Player.h"

#include <Box2D/Box2D.h>

class LevelLoader
{
public:
	LevelLoader(IcatGame* icatGame);
	~LevelLoader();

	Scene* load(int levelNum, b2World* worldPtr);

private:
	std::string readLevelData(int levelNum);
	Scene* createScene(std::string levelData);
	Brick* createBrick(const glm::vec3& position);
	Brick* createPlatform(const glm::vec3& position);
	Player* createPlayer(const glm::vec3& position);

	b2Body* createStaticBody(float x, float y);
	b2Body* createDynamicBody(float x, float y);
public:
	Player* player;
private:
	b2World* currentWorldPtr;
	IcatGame* icatGame;
};


#endif // !_LEVEL_LOADER_H_


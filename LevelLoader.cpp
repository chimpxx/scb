#include "LevelLoader.h"


LevelLoader::LevelLoader(IcatGame* icatGame)
{
	this->icatGame = icatGame;
}


LevelLoader::~LevelLoader()
{
}

Scene* LevelLoader::load(int levelNum, b2World* worldPtr){
	currentWorldPtr = worldPtr;
	std::string levelData = readLevelData(levelNum);
	if (levelData != "")
		return createScene(levelData);
	else
		return nullptr;
}

b2Body* LevelLoader::createStaticBody(float x, float y) {

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	b2Body* staticBody = currentWorldPtr->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(2.0f, 2.0f);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;

	staticBody->CreateFixture(&boxFixtureDef);

	return staticBody;
}

b2Body* LevelLoader::createDynamicBody(float x, float y) {

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.angle = 0.0f;
	bodyDef.allowSleep = false;

	b2Body* dynamicBody = currentWorldPtr->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(1.0f, 1.0f);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;

	dynamicBody->CreateFixture(&boxFixtureDef);

	return dynamicBody;
}

Brick* LevelLoader::createBrick(const glm::vec3& position) {
	Entity* e = icatGame->createEntity("./assets/environment/brick.png");
	e->setPosition(position);
	b2Body *staticBody = createStaticBody(position.x, position.y);

	return new Brick(new PhysicsEntity(e,staticBody));
}

Brick* LevelLoader::createPlatform(const glm::vec3& position) {
	Entity* e = icatGame->createEntity("./assets/environment/platform.png");
	e->setPosition(position);
	b2Body *staticBody = createStaticBody(position.x, position.y);


	return new Brick(new PhysicsEntity(e, staticBody));
}

Player* LevelLoader::createPlayer(const glm::vec3& position) {
	Entity* e = icatGame->createEntity("./assets/gamePlay/player/idle/01.png");
	e->setPosition(position);
	b2Body *dynamicBody = createDynamicBody(position.x, position.y);
	player = new Player(new PhysicsEntity(e, dynamicBody));
	return player;
}

Scene* LevelLoader::createScene(std::string levelData){
	Scene* scene = new Scene();
    glm::vec3 position(2.f, 74.f, 0);
	float offset = 4.f;
	for (char ch : levelData){
		switch (ch){
		case '0':
			position.x += offset;
			break;
		case '1':
			scene->addEntity(createPlatform(position));
			position.x += offset;
			break;
		case '2':
			scene->addEntity(createBrick(position));
			position.x += offset;
			break;
		case '3':
			scene->addEntity(createPlayer(position));
			position.x += offset;
			break;
		case '\n':
			position.x = 2.f;
			position.y -= offset;
			break;
		}
	}
	return scene;
}

std::string LevelLoader::readLevelData(int levelNum){

	std::stringstream padedLevelNumStr;
	padedLevelNumStr << std::setw(3) << std::setfill('0') << levelNum;

	std::string fileLocation = "./assets/levelDetails/" + padedLevelNumStr.str() + ".txt";

	std::string levelDataStr;
	std::ifstream levelDataStrStream(fileLocation, std::ios::in);
	if (levelDataStrStream.is_open()){
		std::string Line = "";
		while (getline(levelDataStrStream, Line))
			levelDataStr += "\n" + Line;
		levelDataStrStream.close();
		return levelDataStr;
	}
	else{
		printf("Impossible to open %s. Are you in the rightDown directory ?\n", &fileLocation[0]);
		getchar();
		return "";
	}
}
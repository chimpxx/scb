



#include "IcatGame.h"
#include <Box2D/Box2D.h>


#include "Game.h"

IcatGame icatGame;
Game* game;

void initGame()
{
	game = new Game(&icatGame);
	game->initLevel(3);

    /*Entity *e = icatGame.createEntity("./assets/IcatIM.png");
    e->setPosition(glm::vec3(6.4f, 3.6f, 0.0f));
    Scene *s = new Scene();
    s->addEntity(e);
    icatGame.setScenePtr(s);*/
}


int main(){

	if (icatGame.initializeWindow()) {
		initGame();

		do {
			game->update();

			//rendering everything
			icatGame.updateWindow();

		} while (!icatGame.ifWindowShouldClose());
		icatGame.terminate();
	}

	return 0;
}

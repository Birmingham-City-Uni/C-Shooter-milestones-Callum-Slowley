#include "GameLoop.h"
#include "Player.h"
#include "Score.h"

//this can be accessed in any cpp file by adding "extern GameLoop * gameLoop"
GameLoop* gameLoop;
extern Player* player;

int main(int argc, char* args[])
{
	//construct a new gameloop object
	gameLoop = new GameLoop();
	if (!gameLoop->init()) {
		return 1;
	}


	//update and draw the game until quit by the user
	while (gameLoop->processInput()) {
		gameLoop->update();
		gameLoop->draw();
		if (player->dead) {
			break;
		}
	}

	//perform any necessary cleaning up
	gameLoop->clean();

	//delete the gameloop object which has been allocated to memory.
	delete gameLoop;
	return 0;
}
#include <iostream>

#include "kisupeli.h"

// using namespace sf;

int main()
{
	//init seed for randomizing
	std::srand(static_cast<unsigned>(time(NULL)));

	// init the little engine <3
	//Game game;
	Map map;

	map.initMap();
	map.printMap();

	Game game(map);
//	Game initWalls(map);
//
	//Gameloop AKA Event polling
	while (game.whilstRunning())
	{
		game.updateGame();
		game.renderGame();
	}
	return (0);
}
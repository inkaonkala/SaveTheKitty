#ifndef KISUPELI_H
#define KISUPELI_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector> //for enemies
#include <ctime> // for randomizing

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

# endif

class Map
{
private:

	std::vector<std::vector<char>> mapBase;

	//map markers
	int	map_len;
	int	map_hi;
public:
	// map marker share
	int getMapH() const { return map_hi; }
	int getMapL() const { return map_len; }

	char getTile(int y, int x) const { return mapBase[y][x]; }

	//functions
	void	initMap();
	void	printMap(); //for testing

};

class Game
{
private:

	sf::RenderWindow	*win;
	sf::Event			ev;
	sf::VideoMode		videoMode;
	Map& map;

	//Game logic 

//	sf:;idontknow		keys;

	float				timer;

	// game objects

	sf::Texture					wallTex;
	std::vector<sf::Sprite>		walls; //this should not be sprite
	sf::Sprite					wall;

	std::vector<sf::Texture> 	catTexture;
	std::vector<sf::Sprite> 	cats;
	sf::Sprite cat;

	//sf::Texture				 	playerATex;
	std::vector<sf::Sprite> 	playerA;
	sf::Sprite 					pa;

//	sf::Texture					playerBTex;
	std::vector<sf::Sprite>		playerB;
	sf::Sprite 					pb;

	sf::Texture 				playerATex1, playerATex2;
	sf::Texture 				playerBTex1, playerBTex2;
	sf::Texture* 				currentPlayerATex;
	sf::Texture* 				currentPlayerBTex;

	sf::Clock animationClock;
	sf::Time animationInterval = sf::seconds(0.5f); // Change every 0.5 seconds
	

	void	initVar();
	void	initWin();
	void	initWalls(Map& map);
	void	initPlayers(Map& map);

public:

	//costructors and distructors
	Game(Map& map);
	virtual ~Game();

	const bool whilstRunning() const;

	// functions to run the game

	
	void	pollEvents();
	void	renderWalls();


	void	animatePlayers();

	void	spawnPlayerA();
	void	updatePA();
	void	renderPA();

	void	spawnPlayerB();
	void	updatePB();
	void	renderPB();

	void	updateGame();
	void	renderGame();
};
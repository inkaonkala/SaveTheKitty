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

	// window 

	sf::RenderWindow	*win;
	sf::Event			ev;
	sf::VideoMode		videoMode;
	Map& map;

	// muuttujat 

	float	playerSpeed = 4.0f;
	float	timer;

	sf::Clock animationClock;
	sf::Time animationInterval = sf::seconds(0.5f); // Change every 0.5 seconds
	
	// movement

	float	gravityForce = 6.0f;
	float	jumpForce = 40.0f;
	bool	canJumpA = true;
	bool	canJumpB = true;

	// game objects

	sf::Texture					wallTex;
	std::vector<sf::Sprite>		walls;
	sf::Sprite					wall;

	sf::Texture					waterTex;
	std::vector<sf::Sprite>		waters;
	sf::Sprite					water;

	sf::Texture					binATex;
	std::vector<sf::Sprite>		binA;
	sf::Sprite					biA;

	sf::Texture					binBTex;
	std::vector<sf::Sprite>		binB;
	sf::Sprite					biB;

	sf::Texture					makerATex;
	std::vector<sf::Sprite>		makerA;
	sf::Sprite					makA;

	sf::Texture					makerBTex;
	std::vector<sf::Sprite>		makerB;
	sf::Sprite					makB;

	sf::Texture					catTex1, catTex2;
	std::vector<sf::Sprite> 	kitty;
	sf::Sprite 					cat;

	sf::Texture 				playerATex1, playerATex2;
	std::vector<sf::Sprite> 	playerA;
	sf::Sprite 					pa;

	sf::Texture 				playerBTex1, playerBTex2;
	std::vector<sf::Sprite>		playerB;
	sf::Sprite 					pb;

	sf::Texture* 				currentPlayerATex;
	sf::Texture* 				currentPlayerBTex;
	sf::Texture*				currentCatTex;

// all init functions

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
	void	movement(Map& map);

//	void	spawnPlayerA();
//	void	updatePA();
	void	renderPA();

//	void	spawnPlayerB();
//	void	updatePB();
	void	renderPB();

	void	renderCat();

	void	updateGame();
	void	renderGame();
};
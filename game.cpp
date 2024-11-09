
#include "kisupeli.h"

void Game::initVar()
{
	this->win = nullptr;
//	this->waterTimer;
//	this->points;
}

void Game::initWin()
{
	this->videoMode.height = map.getMapH() * 32; 
	this->videoMode.width =  map.getMapL() * 32;

	this->win = new sf::RenderWindow(this->videoMode, "Save the cat!", sf::Style::Titlebar | sf::Style::Close);
	this->win->setFramerateLimit(60);
}

//Constructor and destructors

Game::Game(Map& map) : map(map)
{
	this->initVar();
	this->initWin();
	this->initWalls(map);
	this->initPlayers(map);
	//this->initCat();
}

Game::~Game()
{
	delete this->win;
}

const bool Game::whilstRunning() const
{
	return this->win->isOpen();
}

void Game::pollEvents()
{
	while (this->win->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
			case sf::Event::Closed:
				this->win->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->win->close();
				break;
			default:
				break;
		}
	}
}

void Game::updateGame()
{
	this->pollEvents();
	//update all objects
	this->animatePlayers();
	this->movement(map);
}

void Game::renderGame()
{
	this->win->clear(sf::Color(173, 216, 230));
	this->renderWalls();
	// clear old, draw new stuff

	this->renderPA();
	this->renderPB();
	this->renderCat();

	this->win->display();
}
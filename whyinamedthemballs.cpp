#include "kisupeli.h"

//sf::Texture					ballATex;
//std::vector<sf::Sprite>		ballA;
//sf::Sprite					baA;

void Game::renderBallB()
{
	for (auto &e : this->ballB)
	{
		this->win->draw(e);
	}
}

void Game::renderBallA()
{
	for (auto &e : this->ballA)
	{
		this->win->draw(e);
	}
}

void	Game::initBalls(Map& map)
{
	if (!this->ballATex.loadFromFile("images/ballA.png")) {
		std::cout << "These A nuts are gone!" << std::endl;
	}
	if (!this->ballBTex.loadFromFile("images/ballB.png")) {
		std::cout << "DMN these B nuts!" << std::endl;
	}
	for (int y = 0; y < map.getMapH(); ++y) {
		for (int x = 0; x < map.getMapL(); ++x) 
		{
			// Ball A is on the top of the makerA
			if (map.getTile(y, x) == '2') {
				sf::Sprite baA(this->ballATex);
				baA.setPosition(x * 32, y * 32);
				this->ballA.push_back(baA);
			}
			// Ball B is on the maker B
			if (map.getTile(y, x) == '3') {
				sf::Sprite baB(this->ballBTex);
				baB.setPosition(x * 32, y * 32);
				this->ballB.push_back(baB);
			}
		}
	}
	carriedBallA.setTexture(this->ballATex);
	carriedBallA.setPosition(-100, -100); // pff screen
	carriedBallB.setTexture(this->ballBTex);
	carriedBallB.setPosition(-100, -100);
}
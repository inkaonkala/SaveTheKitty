#include "kisupeli.h"

void	Map::initMap()
{
	this->map_hi = 0;
	this->map_len = 0;
	std::ifstream file("maps/map.txt");
	if(!file)
	{
		std::cerr << "No map opened!" << std::endl;
		return ; 
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::vector<char> row;
		for (char c : line)
		{
			if (c != ' ')
			row.push_back(c);
		}
		if (this->map_len == 0 && !row.empty())
			this->map_len = row.size();
		if (!row.empty())
		{
			mapBase.push_back(row);
			this->map_hi++;
		}
	}
	file.close();
}

void Map::printMap()
{
	for (const auto& row : mapBase)
	{
		for (char c : row)
			std::cout << c << ' ';
		std::cout << '\n';
	}
	std::cout << map_hi << std::endl;
	std::cout << map_len << std::endl;
}

void Game::renderWalls()
{
	// renders wall AND all the other solid stuff too
	// walls
	for (auto &e : this->walls)
	{
		this->win->draw(e);
	}
	// Draw water
	for (auto& water : this->waters)
	{
		this->win->draw(water);
	}

	// Draw bins (binA and binB)
	for (auto& binA : this->binA)
	{
		this->win->draw(binA);
	}
	for (auto& binB : this->binB)
	{
		this->win->draw(binB);
	}

	// Draw ball makers (makerA and makerB)
	for (auto& makerA : this->makerA)
	{
		this->win->draw(makerA);
	}
	for (auto& makerB : this->makerB)
	{
		this->win->draw(makerB);
	}

}

void Game::initWalls(Map& map)
{
	/* load textures for 
		-walls
		-water
		-bins (for balls)
		-Ball maker
	*/

	if (!this->wallTex.loadFromFile("images/tiili.png"))
	{
		std::cout << "Error: no tiles to be found!" << std::endl;
	}
	if (!this->waterTex.loadFromFile("images/water.png"))
	{
		std::cout << "Error: no water to be found! It's going to be really dry game, heh heh!" << std::endl;
	}
	if (!this->binATex.loadFromFile("images/binA.png"))
	{
		std::cout << "Error: no binA to be found!" << std::endl;
	}
	if (!this->binBTex.loadFromFile("images/binB.png"))
	{
		std::cout << "Error: no binB to be found!" << std::endl;
	}
	if (!this->makerATex.loadFromFile("images/makerA.png"))
	{
		std::cout << "Error: no makerA to be found!" << std::endl;
	}
	if (!this->makerBTex.loadFromFile("images/makerB.png"))
	{
		std::cout << "Error: no makerB to be found!" << std::endl;
	}
	// Set textures according to map

	this->wall.setTexture(this->wallTex);
	
	for (int y = 0; y < map.getMapH(); ++y) 
	{
		for (int x = 0; x < map.getMapL(); ++x)
		{
			// set wall
			if (map.getTile(y, x) == '1') 
			{
				sf::Sprite wall(this->wallTex);
				wall.setPosition(x * 32, y * 32);
				this->walls.push_back(wall);
			}
			// set water
			if (map.getTile(y, x) == 'W') 
			{
				sf::Sprite water(this->waterTex);
				water.setPosition(x * 32, y * 32);
				this->waters.push_back(water);
			}

			// set ballMakerA
			if (map.getTile(y, x) == '2') 
			{
				sf::Sprite makA(this->makerATex);
				makA.setPosition(x * 32, y * 32);
				this->makerA.push_back(makA);
			}
			//set binA
			if (map.getTile(y, x) == '4') 
			{
				sf::Sprite biA(this->binATex);
				biA.setPosition(x * 32, y * 32);
				this->binA.push_back(biA);
			}
			//set binB
			if (map.getTile(y, x) == '6') 
			{
				sf::Sprite biB(this->binBTex);
				biB.setPosition(x * 32, y * 32);
				this->binB.push_back(biB);
			}
			//set BallMAkerB
			if (map.getTile(y, x) == '3') 
			{
				sf::Sprite makB(this->makerBTex);
				makB.setPosition(x * 32, y * 32);
				this->makerB.push_back(makB);
			}
		}
	}
}
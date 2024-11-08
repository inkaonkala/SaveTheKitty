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
	for (auto &e : this->walls)
	{
		this->win->draw(e);
	}
}

void Game::initWalls(Map& map)
{
	if (!this->wallTex.loadFromFile("images/tiili.png"))
	{
		std::cout << "Error: no tiles to be found!" << std::endl;
	}
	this->wall.setTexture(this->wallTex);
	
	for (int y = 0; y < map.getMapH(); ++y) {
		for (int x = 0; x < map.getMapL(); ++x){
			if (map.getTile(y, x) == '1') {
				sf::Sprite wall(this->wallTex);
				wall.setPosition(x * 32, y * 32);
				this->walls.push_back(wall);
			}
		}
	}
}
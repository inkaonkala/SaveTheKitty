#include "kisupeli.h"

void	Game::movement(Map& map)
{
	// wall collision logic

auto canMoveTo = [&](sf::Sprite& sprite, float offsetX, float offsetY) {
    // Get the player's current position and future position
    float newX = sprite.getPosition().x + offsetX;
    float newY = sprite.getPosition().y + offsetY;

    // Convert the new position to map grid coordinates
    int tileX1 = static_cast<int>(newX / 32);
    int tileY1 = static_cast<int>(newY / 32);
    int tileX2 = static_cast<int>((newX + 30) / 32); // Right/bottom edge
    int tileY2 = static_cast<int>((newY + 30) / 32);

    // Check if any corner of the player sprite would intersect a wall
    return tileX1 >= 0 && tileY1 >= 0 && tileX2 < map.getMapL() && tileY2 < map.getMapH() &&
           map.getTile(tileY1, tileX1) != '1' && map.getTile(tileY2, tileX1) != '1' &&
           map.getTile(tileY1, tileX2) != '1' && map.getTile(tileY2, tileX2) != '1';
};

	// move player A WASD

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJumpA)
	{
		this->playerA[0].move(0, -jumpForce);
		canJumpA = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMoveTo(this->playerA[0], -playerSpeed, 0))
	{
		this->playerA[0].move(-playerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMoveTo(this->playerA[0], playerSpeed, 0))
	{
		this->playerA[0].move(playerSpeed, 0);
	}

	// gravity to player A

	if(canMoveTo(this->playerA[0], 0, playerSpeed))
		this->playerA[0].move(0, gravityForce);
	else
		canJumpA = true;


	// move player B arrows

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJumpB)
	{
		this->playerB[0].move(0, -jumpForce);
		canJumpB = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMoveTo(this->playerB[0], -playerSpeed, 0))
	{
		this->playerB[0].move(-playerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canMoveTo(this->playerB[0], playerSpeed, 0))
	{
		this->playerB[0].move(playerSpeed, 0);
	}

	if(canMoveTo(this->playerB[0], 0, playerSpeed))
		this->playerB[0].move(0, gravityForce);
	else
		canJumpB = true;
}
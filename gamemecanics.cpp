#include "kisupeli.h"

/*
void Game::gameMechanics(Map& map)
{
	// check if player is on the BallMaker
	if (map.getTile(playerAPos.y, playerAPos.x) == '2')
	{
		carrying = true;
		carriedballA.getPosition(playerA.getPosition().x, playerA.getPosition().y - 32);
	}

	//attach the ball on the player
	if (carrying)
	{
		ballA.getPosition(playerA().x, playerA.getPosition().y - 32);
	}

	// check if bin is reached and update Gcounter
	if (map.getTile(playerAPos.y, playerAPos.x) == '4')
	{
		//the ball on the head will disapear
		carrying = false;
		renderBallA();
		this->map.Gcounter--;
	}
	//if (blockcounter <= 0)
	//	youwinthegame();
}
*/

void Game::gameMechanics(Map& map) 
{
    // Check if player is at a ball maker (2)
    if (map.getTile(playerAPos.y, playerAPos.x) == '2') {
        carrying = true;
        // Set carriedBallA position to follow Player A
        carriedBallA.setPosition(playerA[0].getPosition().x, playerA[0].getPosition().y - 32);
    }

    // Drop the ball in the bin (4) and update the counter
    if (carrying && map.getTile(playerAPos.y, playerAPos.x) == '4') {
        carrying = false;
        carriedBallA.setPosition(-100, -100); // Hide the carried ball
        // Decrease counter and place new ball on 'G' tile
        if (--this->map.Gcounter > 0) {
            for (int y = 0; y < map.getMapH(); ++y) {
                for (int x = 0; x < map.getMapL(); ++x) {
                    if (map.getTile(y, x) == 'G') {
                        sf::Sprite newBall(this->ballATex);
                        newBall.setPosition(x * 32, y * 32);
                        this->ballA.push_back(newBall);
                        break;
                    }
                }
            }
        }
    }

    // Check game win condition
    //if (blockCounter <= 0) {
    //    youWinTheGame();
}


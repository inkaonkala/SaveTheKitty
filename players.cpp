
#include "kisupeli.h"

void Game::animatePlayers()
{
 	if (this->animationClock.getElapsedTime() >= this->animationInterval) {
        // Toggle Player A's texture
        if (this->currentPlayerATex == &this->playerATex1) {
            this->currentPlayerATex = &this->playerATex2;
        } else {
            this->currentPlayerATex = &this->playerATex1;
        }

        // Toggle Player B's texture
        if (this->currentPlayerBTex == &this->playerBTex1) {
            this->currentPlayerBTex = &this->playerBTex2;
        } else {
            this->currentPlayerBTex = &this->playerBTex1;
        }

        // Apply the new textures to each sprite in the player vectors
        for (auto& sprite : this->playerA) {
            sprite.setTexture(*this->currentPlayerATex);
        }
        for (auto& sprite : this->playerB) {
            sprite.setTexture(*this->currentPlayerBTex);
        }

        // Reset the animation clock
        this->animationClock.restart();
    }
}

void Game::renderPA()
{
	for (auto &e : this->playerA)
	{
		this->win->draw(e);
	}
}

void Game::renderPB()
{
		for (auto &e : this->playerB)
	{
		this->win->draw(e);
	}
}

void Game::initPlayers(Map& map) {
    // Load Player A textures
    if (!this->playerATex1.loadFromFile("images/PA1.png")) {
        std::cout << "Error: Could not find PlayerA texture PA1!" << std::endl;
    }
    if (!this->playerATex2.loadFromFile("images/PA2.png")) {
        std::cout << "Error: Could not find PlayerA texture PA2!" << std::endl;
    }
    
    // Load Player B textures
    if (!this->playerBTex1.loadFromFile("images/PB1.png")) {
        std::cout << "Error: Could not find PlayerB texture PB1!" << std::endl;
    }
    if (!this->playerBTex2.loadFromFile("images/PB2.png")) {
        std::cout << "Error: Could not find PlayerB texture PB2!" << std::endl;
    }

    // Initialize Player A sprites
    for (int y = 0; y < map.getMapH(); ++y) {
        for (int x = 0; x < map.getMapL(); ++x) {
            if (map.getTile(y, x) == 'A') {
                sf::Sprite pa(this->playerATex1);
                pa.setPosition(x * 32, y * 32);
                this->playerA.push_back(pa);
            }
            if (map.getTile(y, x) == 'B') {
                sf::Sprite pb(this->playerBTex1);
                pb.setPosition(x * 32, y * 32);
                this->playerB.push_back(pb);
            }
//			if (map.getTile(y, x) == 'C') {
//                sf::Sprite cat(this->playerBTex1);
//                pb.setPosition(x * 32, y * 32);
//                this->playerB.push_back(pb);
//            }
        }
    }

    // Set initial texture states
    this->currentPlayerATex = &this->playerATex1;
    this->currentPlayerBTex = &this->playerBTex1;
}

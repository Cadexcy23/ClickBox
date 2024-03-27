#include "Player.h"
#include "Object.h"
#include "Artist.h"
#include "Controller.h"

Player::player Player::currentPlayer;

void Player::loadPlayer()
{
	Player::currentPlayer.objectType = &Object::objectMasterList[0];
	Player::currentPlayer.x = 10;
	Player::currentPlayer.y = 10;
	Player::currentPlayer.xVel = 0;
	Player::currentPlayer.yVel = 0;
	Player::currentPlayer.alive = true;
	Player::currentPlayer.lastUpdate = 0;
}

void drawPlayers()
{
	Artist artist;

	//debug info
	//artist.drawLetters(std::to_string(Object::objectList.size()), 0, 0, Artist::smallFont);



	
	Player::currentPlayer.draw();

	if (Player::currentPlayer.lastUpdate < clock())
	{
		Player::currentPlayer.update();
		/*if (!Player::currentPlayer.alive)
		{
			//printf("size: %i \n", Game::clickAttackList.size());
			if (Player::currentPlayer.size() == 1)
			{
				//printf("cleared all \n");
				Player::currentPlayer.clear();
			}
			else
			{
				//printf("cleared one \n");
				Player::currentPlayer.erase(Player::currentPlayer.begin() + i);
			}
		}*/
	}
	
}

void Player::controller(int input)
{
	switch (input)
	{
	case Controller::RIGHT_MOUSE_CLICK:


		break;
	case Controller::KEY_PRESS:
		const Uint8 *state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_W])
		{
			Player::currentPlayer.jump();
		}
		if (state[SDL_SCANCODE_A])
		{
			Player::currentPlayer.moveLeft();
		}
		if (state[SDL_SCANCODE_D])
		{
			Player::currentPlayer.moveRight();
		}
		break;
	}
}

void Player::draw()
{
	drawPlayers();
	
}
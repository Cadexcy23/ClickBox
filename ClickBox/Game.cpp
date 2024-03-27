#include <time.h>
#include "Game.h"
#include "Controller.h"
#include "Artist.h"
#include "Object.h"


std::vector<Game::clickAttackSpot> Game::clickAttackList;

float Game::gravity = .0005;



void hitCheck()
{
	for (int i = 0; i < Object::objectList.size(); i++)
	{
		//printf("%i\n", i);
		if (Controller::mouseX + 12 > Object::objectList[i].x && Controller::mouseX - 12 < Object::objectList[i].x + Object::objectList[i].objectType->width &&
			Controller::mouseY + 12 > Object::objectList[i].y && Controller::mouseY - 12 < Object::objectList[i].y + Object::objectList[i].objectType->height)
		{
			printf("Hit %i\n", i);
			Object::objectList[i].alive = false;
		}
	}
}

void drawClickAttacks()
{
	Artist artist;

	//Debug info
	//artist.drawLetters(std::to_string(Game::clickAttackList.size()), 0, 0, Artist::smallFont);

	//go thru all of them and draw/update
	for (int i = 0; i < Game::clickAttackList.size(); i++)
	{
		if (Game::clickAttackList[i].lastUpdate < clock())
		{
			Game::clickAttackList[i].update();
			if (Game::clickAttackList[i].age >= 500)
			{
				//printf("size: %i \n", Game::clickAttackList.size());
				if (Game::clickAttackList.size() == 1)
				{
					//printf("cleared all \n");
					Game::clickAttackList.clear();
				}
				else
				{
					//printf("cleared one \n");
					Game::clickAttackList.erase(Game::clickAttackList.begin());
				}
				
			}
		}
		if (Game::clickAttackList.size() > 0)
		{
			Game::clickAttackList[i].draw();
		}
	}
}

void addClickAttack()
{
	srand(clock());
	Game::clickAttackSpot tempSpot;
	tempSpot.x = Controller::mouseX - 12;
	if (tempSpot.x < 0)
	{
		tempSpot.x = 0;
	}
	if (tempSpot.x > Artist::SCREEN_WIDTH - 24)
	{
		tempSpot.x = Artist::SCREEN_WIDTH - 24;
	}
	tempSpot.y = Controller::mouseY - 12;
	if (tempSpot.y < 0)
	{
		tempSpot.y = 0;
	}
	if (tempSpot.y > Artist::SCREEN_HEIGHT - 24)
	{
		tempSpot.y = Artist::SCREEN_HEIGHT - 24;
	}
	tempSpot.xVel = (rand() % 50) * .001 + .001;
	tempSpot.yVel = (rand() % 50) * -.001 -.05;
	tempSpot.age = 0;
	tempSpot.lastUpdate = 0;
	if (rand() % 100 < 10)
	{
		tempSpot.rgb.r = 255;
		tempSpot.rgb.g = 0;
		tempSpot.rgb.b = 0;
	}
	else
	{
		tempSpot.rgb.r = 255;
		tempSpot.rgb.g = 255;
		tempSpot.rgb.b = 255;
	}

	Game::clickAttackList.push_back(tempSpot);
}

void Game::controller(int input)
{
	switch (input)
	{
	case Controller::LEFT_MOUSE_CLICK:
		hitCheck();
		addClickAttack();
		
		break;
	}
}

void Game::draw()
{
	drawClickAttacks();
}
#include "Object.h"
#include <vector>
#include "Artist.h"
#include "Controller.h"


std::vector<Object::masterObject> Object::objectMasterList;
std::vector<Object::object> Object::objectList;


void Object::addObject(Object::masterObject* objectType, float x, float y, float xVel, float yVel)
{
	Object::object tempObject;
	x -= objectType->width / 2;
	y -= objectType->height / 2;

	if (x < 0)
	{
		x = 1;
	}
	if (x > Artist::SCREEN_WIDTH - objectType->width)
	{
		x = Artist::SCREEN_WIDTH - objectType->width - 1;
	}
	if (y < 0)
	{
		y = 1;
	}
	if (y > Artist::SCREEN_HEIGHT - objectType->height)
	{
		y = Artist::SCREEN_HEIGHT - objectType->height - 1;
	}

	tempObject.alive = true;
	tempObject.lastUpdate = 0;
	tempObject.objectType = objectType;
	tempObject.x = x;
	tempObject.y = y;
	tempObject.xVel = xVel;
	tempObject.yVel = yVel;

	

	Object::objectList.push_back(tempObject);
}

void drawObjects()
{
	Artist artist;

	//debug info
	artist.drawLetters(std::to_string(Object::objectList.size()), 0, 0, Artist::smallFont);



	for (int i = 0; i < Object::objectList.size(); i++)
	{
		if (Object::objectList.size() > 0)
		{
			Object::objectList[i].draw();
		}
		

		if (Object::objectList[i].lastUpdate < clock())
		{
			Object::objectList[i].update();
			if (!Object::objectList[i].alive)
			{
				//printf("size: %i \n", Game::clickAttackList.size());
				if (Object::objectList.size() == 1)
				{
					//printf("cleared all \n");
					Object::objectList.clear();
				}
				else
				{
					//printf("cleared one \n");
					Object::objectList.erase(Object::objectList.begin() + i);
				}
			}
		}
	}
}

void loadObject(std::string name, std::string textureName, float bounciness, int width = 0, int height = 0)
{
	Artist artist;

	Object::masterObject tempObject;

	tempObject.name = name;
	tempObject.bounciness = bounciness;
	tempObject.width = width;
	tempObject.height = height;

	tempObject.texture = artist.loadTexture("Resource/objects/" + textureName + ".png");

	if (tempObject.width == 0)
	{
		int w = 0;
		SDL_QueryTexture(tempObject.texture, NULL, NULL, &w, NULL);
		tempObject.width = w;
	}
	if (tempObject.height == 0)
	{
		int h = 0;
		SDL_QueryTexture(tempObject.texture, NULL, NULL, NULL, &h);
		tempObject.height = h;
	}

	Object::objectMasterList.push_back(tempObject);
}

void Object::loadObjectMasterList()
{
	loadObject("Player", "playerIdle", .1);
	loadObject("Strawberry Mochi", "mochiStrawberry", .1);
	loadObject("Vanilla Mochi", "mochiVanilla", .1);
	loadObject("Green Tea Mochi", "mochiGreenTea", .5);
	
}

void Object::draw()
{
	drawObjects();
}
void Object::controller(int input)
{
	switch (input)
	{
	case Controller::RIGHT_MOUSE_CLICK:
		
	
		break;
	case Controller::KEY_PRESS:
		const Uint8 *state = SDL_GetKeyboardState(NULL);

		//printf("Got here\n");
		if (state[SDL_SCANCODE_1])
		{
			addObject(&Object::objectMasterList[1], Controller::mouseX, Controller::mouseY, 0, 0);
		}
		if (state[SDL_SCANCODE_2])
		{
			addObject(&Object::objectMasterList[2], Controller::mouseX, Controller::mouseY, 0, 0);
		}
		if (state[SDL_SCANCODE_3])
		{
			addObject(&Object::objectMasterList[3], Controller::mouseX, Controller::mouseY, 0, 0);
		}
		break;
	}
}
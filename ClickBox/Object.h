#pragma once
#ifndef vector
#include <vector>
#endif
#ifndef SDL
#include <SDL.h>
#endif 
#ifndef time
#include <time.h>
#endif 
#ifndef Artist
#include "Artist.h"
#endif 
#ifndef Game
#include "Game.h"
#endif 
class Object{
public:
	struct masterObject {
		std::string name;
		int width, height;
		float bounciness;
		SDL_Texture* texture;
	};
	struct object {
		masterObject* objectType;
		float x, y, xVel, yVel;
		int lastUpdate;
		bool alive;
		

		/*void jump()
		{
			//printf("y: %f\n", y);
			if (y >= Artist::SCREEN_HEIGHT - objectType->height - 1)
			{
				//printf("Could jump\n");
				if (rand() % 1000 == 0)
				{
					yVel = -.2;
					if (rand() % 2 == 0)
					{
						xVel += .05;
					}
					else
					{
						xVel -= .05;
					}
					
				}
			}
		}*/
		bool collisionDetectionRight()
		{
			if (x + xVel + objectType->width >= Artist::SCREEN_WIDTH)
			{
				return true;
			}
			return false;
		}
		bool collisionDetectionLeft()
		{
			if (x + xVel <= 0)
			{
				return true;
			}
			return false;
		}
		bool collisionDetectionDown()
		{
			if (y + yVel + objectType->height >= Artist::SCREEN_HEIGHT)
			{
				return true;
			}
			return false;
		}
		bool collisionDetectionUp()
		{
			if (y + yVel <= 0)
			{
				return true;
			}
			return false;
		}
		void draw()
		{
			Artist artist;

			artist.drawImage(x, y, objectType->width, objectType->height, objectType->texture);
		}
		void update()
		{
			//TEMP
			if (y >= Artist::SCREEN_HEIGHT - objectType->height - 1)
			{
				//printf("Could jump\n");
				if (rand() % 1000 == 0)
				{
					yVel = -.2;
					if (rand() % 2 == 0)
					{
						xVel += .05;
					}
					else
					{
						xVel -= .05;
					}

				}
			}


			x += xVel;
			y += yVel;
			yVel += Game::gravity;
			lastUpdate = clock();
			if (collisionDetectionRight() || collisionDetectionLeft())
			{
				//printf("Flipped X\n");
				xVel *= -objectType->bounciness;
				yVel *= objectType->bounciness;
			}
			if (collisionDetectionUp() || collisionDetectionDown())
			{
				//printf("Flipped Y\n");
				yVel *= -objectType->bounciness;
				xVel *= objectType->bounciness;
			}

			/*if (!alive)
			{
				printf("size: %i \n", Object::objectList.size());
				if (Object::objectList.size() == 1)
				{
					printf("cleared all \n");
					Object::objectList.clear();
				}
				else
				{
					printf("cleared one \n");
					Object::objectList.erase(Object::objectList.begin());
				}
			}*/
		}
	};
	static std::vector<masterObject> objectMasterList;
	static std::vector<object> objectList;
	void addObject(Object::masterObject* objectType, float x, float y, float width, float height);
	void loadObjectMasterList();
	void draw();
	void controller(int input);
};
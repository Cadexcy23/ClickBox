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

class Game {
public:

	static float gravity;
	

	struct clickAttackSpot {
		float x, y, xVel, yVel;
		int age, lastUpdate;
		Artist::RGB rgb;
		bool collisionDetectionX()
		{
			if (x + xVel + 24 >= Artist::SCREEN_WIDTH)
			{
				return true;
			}
			if (x + xVel <= 0)
			{
				return true;
			}
			return false;
		}
		bool collisionDetectionY()
		{
			if (y + yVel + 24 >= Artist::SCREEN_HEIGHT)
			{
				return true;
			}
			if (y + yVel <= 0)
			{
				return true;
			}
			return false;
		}
		void update()
		{
			age++;
			x += xVel;
			y += yVel;
			yVel += .0003;
			lastUpdate = clock();
			if (collisionDetectionX())
			{
				//printf("Flipped X\n");
				xVel *= -.9;
				yVel *= .9;
			}
			if (collisionDetectionY())
			{
				//printf("Flipped Y\n");
				yVel *= -.9;
				xVel *= .9;
			}
		}
		void draw()
		{
			Artist artist;

			SDL_SetTextureAlphaMod(Artist::gClickAttackX, 255 - age / 2);
			SDL_SetTextureColorMod(Artist::gClickAttackX, rgb.r, rgb.g, rgb.b);
			artist.drawImage(x, y, 24, 24, Artist::gClickAttackX);
			SDL_SetTextureAlphaMod(Artist::gClickAttackX, 255);
			SDL_SetTextureColorMod(Artist::gClickAttackX, 255, 255, 255);
		}
	};

	static std::vector<clickAttackSpot> clickAttackList;

	void controller(int input);

	void draw();
};
#pragma once
#ifndef Object
#include "Object.h"
#endif 
class Player {
public :
	struct player : Object::object {
		void moveLeft()
		{
			xVel -= .1;
		}
		void moveRight()
		{
			xVel += .1;
		}
		void jump()
		{
			yVel -= 1;
		}
	};

	static struct player currentPlayer;
	void loadPlayer();
	void controller(int input);
	void draw();
};
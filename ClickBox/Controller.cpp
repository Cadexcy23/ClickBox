#include <SDL.h>
#include <stdio.h>
#include "Controller.h"
#include "Game.h"
#include "Object.h"
#include "Player.h"

int Controller::mouseX = 0;
int Controller::mouseY = 0;

int Controller::gameState = Controller::GAMESTATE_IN_GAME;
//Keeps track if game is running
bool Controller::quit = false;
//Event handler
SDL_Event e;



void runInputs(int input)
{
	Game game;
	Object object;
	Player player;

	
	object.controller(input);
	game.controller(input);
	player.controller(input);
	//printf("Ran inputs\n");
}

void Controller::controller()
{
	//Set mouse pos
	SDL_GetMouseState(&Controller::mouseX, &Controller::mouseY);
	//printf("Mouse X: %i Mouse Y: %i\n", Controller::mouseX, Controller::mouseY);
	//Declare classes
	
	//Handle events on queue
	if (SDL_PollEvent(&e) != 0)
	{
		//printf("input detected: %i\n", e.type);
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			Controller::quit = true;
		}



		//MOUSE
		Uint32 mouseState = SDL_GetMouseState(NULL, NULL);
		//User clicks
		//printf("mouse input: %i \n", mouseState);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			//printf("mouse input: %i \n", mouseState);
			//LEFT CLICK
			if (mouseState == 1)
			{
				//printf("Mouse X: %i Mouse Y: %i\n", Controller::mouseX, Controller::mouseY);
				//set what input it is or run a funtion with em all
				runInputs(LEFT_MOUSE_CLICK);
			}

			//RIGHT CLICK
			if (mouseState == 4)
			{
				runInputs(RIGHT_MOUSE_CLICK);
			}

			//MIDDLE CLICK
			if (mouseState == 2)
			{
				runInputs(MIDDLE_MOUSE_CLICK);
			}
		}

		if (e.type == SDL_MOUSEMOTION)
		{
			//LEFT CLICK
			if (mouseState == 1)
			{
				//printf("Dragged left click\n");
				runInputs(LEFT_MOUSE_DRAG);
			}

			//RIGHT CLICK
			if (mouseState == 4)
			{
				//printf("Dragged right click\n");
				runInputs(RIGHT_MOUSE_DRAG);
			}

			//MIDDLE CLICK
			if (mouseState == 2)
			{
				//printf("Dragged middle click\n");
				runInputs(MIDDLE_MOUSE_DRAG);
			}
		}


		//Keyboard
		if (e.type == 768)
		{
			//printf("Keyboard pressed\n");
			runInputs(KEY_PRESS);
		}
		

	}
}
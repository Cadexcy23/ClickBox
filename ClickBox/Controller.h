#pragma once

class Controller {
public:
	enum inputs {
		LEFT_MOUSE_CLICK,
		RIGHT_MOUSE_CLICK,
		MIDDLE_MOUSE_CLICK,
		LEFT_MOUSE_DRAG,
		RIGHT_MOUSE_DRAG,
		MIDDLE_MOUSE_DRAG,
		KEY_PRESS
	};
	enum gamestates {
		GAMESTATE_IN_GAME
	};
	static int gameState, gameIndex;
	static bool quit;
	//Keeps track of mouse Pos
	static int mouseX, mouseY;
	
	//Checks for inputs from the user
	void controller();
};
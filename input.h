#pragma once

#include "SDL.h"
#include <iostream>

struct MouseState {
	int x, y;
};

struct InputInfo {
	bool w, f;

	void setAllTrue() {
		w = true;
		f = true;
	}
};

class Input {
public:
	Input();
	void update();
	bool quit = false;

	bool mouseDown = false;
	bool mousePressed = false;

	InputInfo inputDown;
	InputInfo inputPressed;

	MouseState mouseState;

private:
	InputInfo inputReleased;
};

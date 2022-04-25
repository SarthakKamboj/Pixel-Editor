#pragma once

#include "SDL.h"
#include <iostream>
#include <map>
#include <vector>

struct MouseState {
	int x, y;
};

class Input {
public:
	Input();
	void update();
	bool quit = false;

	bool mouseDown = false;
	bool mousePressed = false;

	bool keyPressed = false;

	MouseState mouseState;
	MouseState mouseDelta;

	SDL_KeyCode keyPressedCode;

	std::map<SDL_KeyCode, bool> down;
	std::map<SDL_KeyCode, bool> pressed;

	bool isMousePressedOn(int x, int y, int width, int height);
	bool isMouseInRegion(int x, int y, int width, int height);
	bool isMouseDownOn(int x, int y, int width, int height);

private:
	std::map<SDL_KeyCode, bool> released;

	void resetInput();
};

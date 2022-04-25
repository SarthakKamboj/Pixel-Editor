#pragma once

#include "SDL.h"
#include <iostream>
#include <map>
#include <vector>
// #include "uiComponentHandler.h"

struct MouseState {
	int x, y;
};

// extern UIComponentRegistrar uiComponentRegistrar;

struct InputInfo {
	bool w, f, u, r;
	// bool a, b, c, d, e, f, g, h, i, j, k, l, m

	void setAllTrue() {
		w = true;
		f = true;
		u = true;
		r = true;
	}
};

// class UIComponentRegistrar;
// class UIComponent;

class Input {
public:
	// Input(UIComponentRegistrar* uiComponentRegistrar);
	Input();
	void update();
	bool quit = false;

	bool mouseDown = false;
	bool mousePressed = false;

	bool keyPressed = false;

	// InputInfo inputDown;
	// InputInfo inputPressed;

	MouseState mouseState;
	MouseState mouseDelta;

	// bool isMousePressedOn(UIComponent* component);
	// bool isMouseInRegion(UIComponent* component);
	// bool isMouseDownOn(UIComponent* component);

	SDL_KeyCode keyPressedCode;

	std::map<SDL_KeyCode, bool> down;
	std::map<SDL_KeyCode, bool> pressed;

	bool isMousePressedOn(int x, int y, int width, int height);
	bool isMouseInRegion(int x, int y, int width, int height);
	bool isMouseDownOn(int x, int y, int width, int height);

private:
	// InputInfo inputReleased;
	std::map<SDL_KeyCode, bool> released;

	// UIComponent* uiComponentMouseOver;
	// UIComponentRegistrar* uiComponentRegistrar;

	void resetInput();
};

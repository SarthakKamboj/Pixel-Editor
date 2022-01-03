#include "input.h"

Input::Input() {
	// inputReleased.setAllTrue();
	/*
	for (std::pair<SDL_KeyCode, bool> keyValue : released) {
		pressed[keyValue.first] = true;
	}
	*/
}

void Input::resetInput() {
	for (std::pair<SDL_KeyCode, bool> keyValue : down) {
		down[keyValue.first] = false;
	}

	for (std::pair<SDL_KeyCode, bool> keyValue : pressed) {
		pressed[keyValue.first] = false;
	}
}

void Input::update() {

	SDL_Event evnt;

	SDL_PollEvent(&evnt);

	// inputDown = {};
	// inputPressed = {};

	resetInput();

	mousePressed = false;
	keyPressed = false;

	switch (evnt.type) {
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_MOUSEBUTTONDOWN:
		mousePressed = true;
		mouseDown = true;
		break;
	case SDL_MOUSEBUTTONUP:
		mouseDown = false;
		break;
	case SDL_KEYDOWN: {
		SDL_KeyCode keyCode = (SDL_KeyCode)evnt.key.keysym.sym;
		keyPressed = true;
		keyPressedCode = keyCode;

		down[keyCode] = true;

		if (released.find(keyCode) == released.end() || released[keyCode]) {
			pressed[keyCode] = true;
			released[keyCode] = false;
		}

		/*
		switch (keyCode) {
		case SDLK_w:
			inputDown.w = true;
			if (inputReleased.w) {
				inputPressed.w = true;
				inputReleased.w = false;
			}
			break;
		case SDLK_f:
			inputDown.f = true;
			if (inputReleased.f) {
				inputPressed.f = true;
				inputReleased.f = false;
			}
			break;
		case SDLK_r:
			inputDown.r = true;
			if (inputReleased.r) {
				inputPressed.r = true;
				inputReleased.r = false;
			}
			break;
		case SDLK_u:
			inputDown.u = true;
			if (inputReleased.u) {
				inputPressed.u = true;
				inputReleased.u = false;
			}
			break;
		}
		*/
		break;
	}
	case SDL_KEYUP: {
		SDL_KeyCode keyCode = (SDL_KeyCode)evnt.key.keysym.sym;
		released[keyCode] = true;
		break;
		/*
		switch (keyCode) {
		case SDLK_w:
			inputReleased.w = true;
			break;
		case SDLK_f:
			inputReleased.f = true;
			break;
		case SDLK_u:
			inputReleased.u = true;
			break;
		case SDLK_r:
			inputReleased.r = true;
			break;
		}
		break;
		*/
	}
	}

	MouseState prevMouseState = mouseState;
	SDL_GetMouseState(&mouseState.x, &mouseState.y);

	mouseDelta.x = mouseState.x - prevMouseState.x;
	mouseDelta.y = mouseState.y - prevMouseState.y;
	// std::cout << mouseState.x << ", " << mouseState.y << std::endl;
	/*
	if (mouseDown) {
		SDL_GetMouseState(&mouseState.x, &mouseState.y);
	}
	*/

}

bool Input::isMouseInRegion(int x, int y, int width, int height) {
	return mouseState.x >= x && mouseState.x < x + width && mouseState.y >= y && mouseState.y < y + height;
}

bool Input::isMousePressedOn(int x, int y, int width, int height) {
	return mousePressed && isMouseInRegion(x, y, width, height);
}

bool Input::isMouseDownOn(int x, int y, int width, int height) {
	return mouseDown && isMouseInRegion(x, y, width, height);
}
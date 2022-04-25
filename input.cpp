#include "input.h"

// Input::Input(UIComponentRegistrar* _uiComponentRegistrar) : uiComponentRegistrar(_uiComponentRegistrar) {
Input::Input() {
	// inputReleased.setAllTrue();

	/*
	for (std::pair<SDL_KeyCode, bool> keyValue : released) {
		pressed[keyValue.first] = true;
	}
	*/

	// uiComponentMouseOver = NULL;
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
	}
					break;
	case SDL_KEYUP: {
		SDL_KeyCode keyCode = (SDL_KeyCode)evnt.key.keysym.sym;

		down[keyCode] = false;
		pressed[keyCode] = false;
		released[keyCode] = true;
	}
				  break;
	}

	if (mousePressed) {
		std::cout << "mouse pressed" << std::endl;
	}

	if (mouseDown) {
		SDL_GetMouseState(&mouseState.x, &mouseState.y);
	}

	/*
	MouseState prevMouseState = mouseState;
	SDL_GetMouseState(&mouseState.x, &mouseState.y);

	mouseDelta.x = mouseState.x - prevMouseState.x;
	mouseDelta.y = mouseState.y - prevMouseState.y;

	uiComponentMouseOver = NULL;
	std::vector<int>& zLayers = uiComponentRegistrar->zLayers;
	std::map<int, std::vector<UIComponent*>>& uiComponentLayers = uiComponentRegistrar->uiComponentLayers;

	for (int i = ((int)zLayers.size()) - 1; i >= 0; i--) {
		bool foundMouseOver = false;
		for (UIComponent* component : uiComponentLayers[zLayers[i]]) {
			if (isMouseInRegion(component->x, component->y, component->width, component->height)) {
				uiComponentMouseOver = component;
				foundMouseOver = true;
				break;
			}
		}
		if (foundMouseOver) {
			break;
		}
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

/*
bool Input::isMousePressedOn(UIComponent* component) {
	return mousePressed && uiComponentMouseOver == component;
}

bool Input::isMouseInRegion(UIComponent* component) {
	return uiComponentMouseOver == component;
}

bool Input::isMouseDownOn(UIComponent* component) {
	return mouseDown && uiComponentMouseOver == component;
}
*/

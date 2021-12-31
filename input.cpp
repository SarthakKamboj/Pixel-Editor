#include "input.h"

Input::Input() {
	inputReleased.setAllTrue();
}

void Input::update() {

	SDL_Event evnt;

	SDL_PollEvent(&evnt);

	inputDown = {};
	inputPressed = {};

	mousePressed = false;

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
		case SDLK_u:
			inputDown.u = true;
			if (inputReleased.u) {
				inputPressed.u = true;
				inputReleased.u = false;
			}
			break;
		}
		break;
	}
	case SDL_KEYUP: {
		SDL_KeyCode keyCode = (SDL_KeyCode)evnt.key.keysym.sym;
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
		}
		break;
	}
	}

	if (mouseDown) {
		SDL_GetMouseState(&mouseState.x, &mouseState.y);
	}

}
#include "input.h"

void Input::update() {

	SDL_Event evnt;

	SDL_PollEvent(&evnt);

	switch (evnt.type) {
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_MOUSEBUTTONDOWN:
		mouseDown = true;
		break;
	case SDL_MOUSEBUTTONUP:
		mouseDown = false;
		break;
	case SDL_KEYDOWN:
		SDL_KeyCode keyCode = (SDL_KeyCode)evnt.key.keysym.sym;
		break;
	}
}
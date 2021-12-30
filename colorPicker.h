#pragma once

#include "SDL.h"
#include "input.h"

extern SDL_Renderer* renderer;
extern Input input;

class ColorPicker {
public:
	ColorPicker();
	void render(int x, int y);
	void update(int x, int y);
	SDL_Color selectedColor;

private:
	SDL_Color colors[5];
	int selectedIdx;
};

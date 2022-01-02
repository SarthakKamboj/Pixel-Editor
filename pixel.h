#pragma once

#include "SDL.h"
#include "input.h"
#include "colorPicker.h"
#include "pixelChange.h"

extern SDL_Renderer* renderer;
extern Input input;
extern ColorPicker colorPicker;

struct Pixel {
	int row, col, width, height;
	SDL_Color color;

	Pixel();
	Pixel(int _row, int _col, int _width, int _height, SDL_Color _color);
	Pixel(const Pixel& other);

	void update(int x, int y);
	void render(int x, int y);

	bool clickedOn(int x, int y);
};



#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "pixel.h"

extern SDL_Renderer* renderer;

class Canvas {
public:
	Canvas(int _rows, int _cols, int _widthPerCell, int _heightPerCell);
	void update(int x, int y);
	void render(int x, int y);

private:
	int rows, cols, widthPerCell, heightPerCell;

	int width, height;

	SDL_Texture* canvasTexture;
	Pixel** pixels;
};
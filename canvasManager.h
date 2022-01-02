#pragma once

#include "SDL.h"
#include "canvas.h"

extern SDL_Renderer* renderer;

class CanvasManager {
public:
	CanvasManager();
	void createCanvas(int rows, int cols, int widthPerCell, int heightPerCell);

	void update(int x, int y);
	void render(int x, int y);
private:
	Canvas canvas;

	bool created = false;
};

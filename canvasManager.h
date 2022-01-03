#pragma once

#include "SDL.h"
#include "canvas.h"

extern SDL_Renderer* renderer;

class CanvasManager {
public:
	CanvasManager(ColorPicker& colorPicker);
	void createCanvas(int rows, int cols, int widthPerCell, int heightPerCell);

	void update(int x, int y);
	void render(int x, int y);

	Canvas* getCanvas();
private:
	ColorPicker& colorPicker;
	Canvas canvas;

	bool created = false;
};

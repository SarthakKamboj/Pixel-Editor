#pragma once

#include "SDL.h"
#include "input.h"
#include "slider.h"
#include "label.h"
#include <string>

extern SDL_Renderer* renderer;
extern Input input;

class ColorPicker {
public:
	ColorPicker();
	ColorPicker(const ColorPicker& other);

	void render(int x, int y);
	void update(int x, int y);
	SDL_Color selectedColor;

private:
	SDL_Color colors[6];
	int selectedIdx;

	Slider redSlider;
	Label redLabel;

};

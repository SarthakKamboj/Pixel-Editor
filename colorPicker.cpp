#include "colorPicker.h"

ColorPicker::ColorPicker() :
	red(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Red", 16))),
	green(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Green", 16))),
	blue(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Blue", 16)))
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	selectedColor = getSelectedColor();
	selectedIdx = 0;

}


SDL_Color ColorPicker::getSelectedColor() {
	SDL_Color color;
	color.r = red.slider.cur;
	color.g = green.slider.cur;
	color.b = blue.slider.cur;
	color.a = 255;
	return color;
}


ColorPicker::ColorPicker(const ColorPicker& other) :
	red(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Red", 16))),
	green(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Green", 16))),
	blue(ColorPicker::ColorInput(Slider(0, 255, 100), Label("0", 16), Label("Blue", 16)))
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	selectedColor = getSelectedColor();
	selectedIdx = 0;

}

void ColorPicker::update(int x, int y) {

	red.update(x, y + 400);
	green.update(x, y + 500);
	blue.update(x, y + 600);

	selectedColor = getSelectedColor();

}

void ColorPicker::render(int x, int y) {

	red.render(x, y + 400);
	green.render(x, y + 500);
	blue.render(x, y + 600);

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	SDL_Color prev = Util::getRenderDrawColor();
	SDL_Color colorSelected = { red.slider.cur, green.slider.cur, blue.slider.cur, 255 };
	Util::setRenderDrawColor(colorSelected);
	SDL_Rect colorMapping = { x, y + 675, 50, 50 };
	SDL_RenderFillRect(renderer, &colorMapping);

	Util::setRenderDrawColor(prev);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
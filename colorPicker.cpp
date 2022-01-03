#include "colorPicker.h"

ColorPicker::ColorPicker() : redSlider(0, 255, 100),
redLabel(std::to_string(redSlider.cur), 16)
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	selectedColor = colors[0];
	selectedIdx = 0;
}


ColorPicker::ColorPicker(const ColorPicker& other) : redSlider(0, 255, 100),
redLabel(std::to_string(redSlider.cur), 16)
{
	colors[0] = { 217, 40, 1, 255 };
	colors[1] = { 136,113,1, 255 };
	colors[2] = { 252,153,57, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };
	colors[5] = { 255, 255, 255, 255 };

	selectedColor = colors[0];
	selectedIdx = 0;
}

void ColorPicker::update(int x, int y) {

	int prevRed = redSlider.cur;
	redSlider.update(x, y + 400);
	int newRed = redSlider.cur;

	if (prevRed != newRed) {
		redLabel.setLabel(std::to_string(newRed));
	}

	if (!input.mousePressed) return;

	int bottomYPadding = 10;
	int size = 30;

	for (int i = 0; i < 6; i++) {
		SDL_Color& color = colors[i];

		int colorY = y + ((size + bottomYPadding) * i);

		if (input.mouseState.x >= x && input.mouseState.x <= x + size && input.mouseState.y >= colorY && input.mouseState.y <= colorY + size) {
			selectedColor = color;
			selectedIdx = i;
		}
	}
}

void ColorPicker::render(int x, int y) {

	redSlider.render(x, y + 400);
	redLabel.render(x, y + 450);

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	int yPadding = 5;
	int size = 30;

	for (int i = 0; i < 6; i++) {

		int colorCellStartY = y + ((size + (2 * yPadding)) * i) + yPadding;

		if (i == selectedIdx) {

			SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);

			int borderWidth = 5;

			SDL_Rect position;
			position.x = x - borderWidth;
			position.y = colorCellStartY - borderWidth;
			position.w = size + (2 * borderWidth);
			position.h = size + (2 * borderWidth);

			SDL_RenderFillRect(renderer, &position);
		}

		SDL_Color& color = colors[i];
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		SDL_Rect position;
		position.x = x;
		position.y = colorCellStartY;
		position.w = size;
		position.h = size;

		SDL_RenderFillRect(renderer, &position);
	}



	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
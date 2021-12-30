#include "colorPicker.h"

ColorPicker::ColorPicker() {
	colors[0] = { 255, 0, 0, 255 };
	colors[1] = { 0, 255, 0, 255 };
	colors[2] = { 0, 0, 255, 255 };
	colors[3] = { 255, 0, 255, 255 };
	colors[4] = { 255, 255, 0, 255 };

	selectedColor = colors[0];
	selectedIdx = 0;
}

void ColorPicker::update(int x, int y) {

	static bool changed = false;

	if (!input.mouseDown) {
		changed = false;
		return;
	}

	if (changed) return;

	changed = true;

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	int bottomYPadding = 10;
	int size = 30;

	for (int i = 0; i < 5; i++) {
		SDL_Color& color = colors[i];

		int colorY = y + ((size + bottomYPadding) * i);

		if (mouseX >= x && mouseX <= x + size && mouseY >= colorY && mouseY <= colorY + size) {
			selectedColor = color;
			selectedIdx = i;
		}
	}
}

void ColorPicker::render(int x, int y) {

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	int yPadding = 5;
	int size = 30;

	for (int i = 0; i < 5; i++) {

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
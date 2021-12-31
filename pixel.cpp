#include "pixel.h"


Pixel::Pixel() : row(0), col(0), width(0), height(0) {
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
}

Pixel::Pixel(int _row, int _col, int _width, int _height, SDL_Color _color) : row(_row), col(_col), width(_width), height(_height), color(_color) {}

Pixel::Pixel(const Pixel& other) : row(other.row), col(other.col), color(other.color) {}

void Pixel::update(int x, int y) {
	if (input.mouseDown) {
		// int mouseX, mouseY;
		// SDL_GetMouseState(&mouseX, &mouseY);

		if (input.mouseState.x >= x && input.mouseState.x < x + width && input.mouseState.y >= y && input.mouseState.y < y + height) {
			color = colorPicker.selectedColor;
		}
	}
}


bool Pixel::clickedOn(int x, int y) {
	if (input.mousePressed) {
		// int mouseX, mouseY;
		// SDL_GetMouseState(&mouseX, &mouseY);

		return input.mouseState.x >= x && input.mouseState.x < x + width && input.mouseState.y >= y && input.mouseState.y < y + height;
	}
	return false;
}

void Pixel::render(int x, int y) {

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_Rect canvasMapping;
	canvasMapping.x = x;
	canvasMapping.y = y;
	canvasMapping.w = width;
	canvasMapping.h = height;

	SDL_RenderFillRect(renderer, &canvasMapping);
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderDrawRect(renderer, &canvasMapping);
}
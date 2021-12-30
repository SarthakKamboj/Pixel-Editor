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
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);

		if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height) {
			/*
			color.r = 0;
			color.g = 0;
			color.b = 255;
			color.a = 255;
			*/
			color = colorPicker.selectedColor;
		}
	}
}

void Pixel::render(int x, int y) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_Rect canvasMapping;
	canvasMapping.x = x;
	canvasMapping.y = y;
	canvasMapping.w = width;
	canvasMapping.h = height;

	SDL_RenderFillRect(renderer, &canvasMapping);
}
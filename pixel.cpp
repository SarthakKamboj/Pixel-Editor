#include "pixel.h"


Pixel::Pixel() : row(0), col(0), width(0), height(0) {
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
}

Pixel::Pixel(int _row, int _col, int _width, int _height, SDL_Color _color) : row(_row), col(_col), width(_width), height(_height), color(_color) {}

Pixel::Pixel(const Pixel& other) : row(other.row), col(other.col), color(other.color), width(other.width), height(other.height) {}

void Pixel::update(int x, int y) {
	if (input.mouseDown && !Util::isSameColor(color, colorPicker.selectedColor)) {
		if (input.mouseState.x >= x && input.mouseState.x < x + width && input.mouseState.y >= y && input.mouseState.y < y + height) {
			std::vector<PixelChange> change;
			// history.stateChanges.clear();

			PixelChange pixelChange;
			pixelChange.row = row;
			pixelChange.col = col;
			pixelChange.prevColor = color;
			pixelChange.newColor = colorPicker.selectedColor;

			color = colorPicker.selectedColor;

			change.push_back(pixelChange);
			history.addStateChange(change);
			std::cout << "prevColor: (" << (int)pixelChange.prevColor.r << ", " << (int)pixelChange.prevColor.g << ", " << (int)pixelChange.prevColor.b << ")" << std::endl;
		}
	}
}


bool Pixel::clickedOn(int x, int y) {
	if (input.mousePressed) {
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
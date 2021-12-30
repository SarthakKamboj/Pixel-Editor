#include "canvas.h"

Canvas::Canvas(int _rows, int _cols, int _widthPerCell, int _heightPerCell) : rows(_rows), cols(_cols),
pixels(new Pixel* [rows]),
heightPerCell(_heightPerCell), widthPerCell(_widthPerCell)
{

	SDL_Color colors[3];
	colors[0] = { 255, 0, 0, 255 };
	colors[1] = { 0, 255, 0, 255 };
	colors[2] = { 0, 0, 255, 255 };

	for (int row = 0; row < rows; row++) {
		pixels[row] = new Pixel[cols];
		for (int col = 0; col < cols; col++) {

			Pixel& pixel = pixels[row][col];
			SDL_Color color = colors[(int)(rand() % 3)];
			color.r = 255;
			color.g = 255;
			color.b = 255;
			color.a = 255;

			pixel.row = row;
			pixel.col = col;
			pixel.color = color;
			pixel.width = widthPerCell;
			pixel.height = heightPerCell;

		}
	}

	width = cols * widthPerCell;
	height = rows * heightPerCell;

}


void Canvas::update(int x, int y) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			Pixel& pixel = pixels[row][col];
			pixel.update(x + (col * widthPerCell), y + (row * heightPerCell));
		}
	}
}

void Canvas::render(int x, int y) {

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_RenderFillRect(renderer, &rect);

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			Pixel& pixel = pixels[row][col];
			pixel.render(x + (col * widthPerCell), y + (row * heightPerCell));
		}
	}

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
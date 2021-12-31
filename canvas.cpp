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


	TTF_Font* font = TTF_OpenFont("fonts/SpaceMono.ttf", 16);
	SDL_Surface* fillSelectSurface = TTF_RenderText_Blended(font, "Fill Rect", { 255, 255, 255, 255 });
	fillSelectTex = SDL_CreateTextureFromSurface(renderer, fillSelectSurface);

}


void Canvas::update(int x, int y) {

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			Pixel& pixel = pixels[row][col];
			int pixelX = x + (col * widthPerCell);
			int pixelY = y + (row * heightPerCell);
			if (fillSelectOn) {
				if (pixel.clickedOn(pixelX, pixelY) && !sameColor(colorPicker.selectedColor, pixel.color)) {
					fillSelect(row, col);
					return;
				}
			}
			else {
				pixel.update(pixelX, pixelY);
			}
		}
	}

	static bool changed = false;

	if (input.inputPressed.f) {
		fillSelectOn = !fillSelectOn;
	}
	else if (input.mousePressed) {
		int w, h;

		int borderWidth = 5;
		SDL_QueryTexture(fillSelectTex, NULL, NULL, &w, &h);

		if (input.mouseState.x >= x + borderWidth && input.mouseState.x < x + borderWidth + w && input.mouseState.y >= height + borderWidth && input.mouseState.y <= height + borderWidth + h) {
			fillSelectOn = !fillSelectOn;
		}
	}
}


void Canvas::fillSelect(int startRow, int startCol) {

	SDL_Color startColor = pixels[startRow][startCol].color;
	std::queue<Pos> posPixelsToChange;
	std::vector<Pos> visited;

	Pos start(startRow, startCol);

	posPixelsToChange.push(start);

	while (posPixelsToChange.size() > 0) {

		Pos pos = posPixelsToChange.front();
		posPixelsToChange.pop();

		if (posInVec(pos, visited)) continue;

		visited.push_back(pos);

		Pos leftPos, rightPos, topPos, bottomPos;
		leftPos.row = pos.row;
		leftPos.col = pos.col - 1;

		rightPos.row = pos.row;
		rightPos.col = pos.col + 1;

		topPos.row = pos.row - 1;
		topPos.col = pos.col;

		bottomPos.row = pos.row + 1;
		bottomPos.col = pos.col;

		if (leftPos.col >= 0 && !posInVec(leftPos, visited) && sameColor(pixels[leftPos.row][leftPos.col].color, startColor)) {
			posPixelsToChange.push(leftPos);
		}

		if (rightPos.col < cols && !posInVec(rightPos, visited) && sameColor(pixels[rightPos.row][rightPos.col].color, startColor)) {
			posPixelsToChange.push(rightPos);
		}

		if (topPos.row >= 0 && !posInVec(topPos, visited) && sameColor(pixels[topPos.row][topPos.col].color, startColor)) {
			posPixelsToChange.push(topPos);
		}

		if (bottomPos.row < rows && !posInVec(bottomPos, visited) && sameColor(pixels[bottomPos.row][bottomPos.col].color, startColor)) {
			posPixelsToChange.push(bottomPos);
		}

		pixels[pos.row][pos.col].color = colorPicker.selectedColor;
	}

}

bool Canvas::sameColor(SDL_Color& c1, SDL_Color& c2) {
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

bool Canvas::posInVec(Pos& pos, std::vector<Pos>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		Pos& posInVec = vec[i];
		if (posInVec.row == pos.row && posInVec.col == pos.col) {
			return true;
		}
	}
	return false;
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

	int w, h;
	int borderWidth = 5;
	SDL_QueryTexture(fillSelectTex, NULL, NULL, &w, &h);

	if (fillSelectOn) {
		SDL_Rect selectedBckRect = { x, height, w + (borderWidth * 2), h + (borderWidth * 2) };
		SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
		SDL_RenderFillRect(renderer, &selectedBckRect);
	}

	SDL_Rect fillSelectOptionRect = { x + borderWidth, height + borderWidth, w, h };
	SDL_RenderCopy(renderer, fillSelectTex, NULL, &fillSelectOptionRect);



	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
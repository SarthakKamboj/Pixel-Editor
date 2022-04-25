#include "canvas.h"

Canvas::Canvas(int _rows, int _cols, int _widthPerCell, int _heightPerCell, SDL_Renderer* _renderer, ColorPicker& _colorPicker) : rows(_rows), cols(_cols),
heightPerCell(_heightPerCell), widthPerCell(_widthPerCell), renderer(_renderer), colorPicker(_colorPicker)
{

	SDL_Color colors[3];
	colors[0] = { 255, 0, 0, 255 };
	colors[1] = { 0, 255, 0, 255 };
	colors[2] = { 0, 0, 255, 255 };

	pixels.reserve(rows);
	for (int row = 0; row < rows; row++) {
		pixels.push_back(std::vector<Pixel>());
		pixels[row].reserve(cols);
		for (int col = 0; col < cols; col++) {
			Pixel pixel(colorPicker);
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

			pixels[row].push_back(pixel);

		}
	}

	width = cols * widthPerCell;
	height = rows * heightPerCell;

	fillSelectTex = Util::getText("Fill", 16, { 255, 255, 255, 255 });
}


Canvas& Canvas::operator=(const Canvas& other) {
	rows = other.rows;
	cols = other.cols;
	widthPerCell = other.widthPerCell;
	heightPerCell = other.heightPerCell;
	width = other.width;
	height = other.height;
	fillSelectOn = other.fillSelectOn;
	fillSelectTex = Util::getText("Fill", 16, { 255, 255, 255, 255 });
	renderer = other.renderer;
	pixels = other.pixels;
	return *this;
}

void Canvas::update(int x, int y) {

	if (!active && input.isMousePressedOn(x, y, width, height)) {
		active = true;
	}

	if (active && !input.mouseDown) {
		active = false;
	}

	if (active) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				Pixel& pixel = pixels[row][col];
				int pixelX = x + (col * widthPerCell);
				int pixelY = y + (row * heightPerCell);
				if (fillSelectOn) {
					if (pixel.clickedOn(pixelX, pixelY) && !Util::isSameColor(colorPicker.selectedColor, pixel.color)) {
						fillSelect(row, col);
						return;
					}
				}
				else {
					pixel.update(pixelX, pixelY);
				}
			}
		}
	}

	if (input.pressed[SDLK_u]) {
		if (history.numRecordedStateChanges == 0) return;
		std::vector<PixelChange>& stateChanges = history.stateChanges[history.numRecordedStateChanges - 1];
		for (unsigned i = 0; i < stateChanges.size(); i++) {
			PixelChange& pixelChange = stateChanges[i];
			int row = pixelChange.row;
			int col = pixelChange.col;
			SDL_Color prevColor = pixelChange.prevColor;

			pixels[row][col].color = prevColor;
		}

		history.numRecordedStateChanges -= 1;
		history.numRecordedUndoActions += 1;

	}

	if (input.pressed[SDLK_r]) {
		if (history.numRecordedUndoActions == 0) return;

		std::vector<PixelChange>& stateChanges = history.stateChanges[history.numRecordedStateChanges];
		history.numRecordedStateChanges += 1;

		for (unsigned i = 0; i < stateChanges.size(); i++) {

			PixelChange& pixelChange = stateChanges[i];
			int row = pixelChange.row;
			int col = pixelChange.col;
			SDL_Color origColor = pixelChange.newColor;

			pixels[row][col].color = origColor;
		}

		history.numRecordedUndoActions -= 1;
	}

	if (input.pressed[SDLK_f]) {
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

	std::vector<PixelChange> stateChange;

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

		if (leftPos.col >= 0 && !posInVec(leftPos, visited) && Util::isSameColor(pixels[leftPos.row][leftPos.col].color, startColor)) {
			posPixelsToChange.push(leftPos);
		}

		if (rightPos.col < cols && !posInVec(rightPos, visited) && Util::isSameColor(pixels[rightPos.row][rightPos.col].color, startColor)) {
			posPixelsToChange.push(rightPos);
		}

		if (topPos.row >= 0 && !posInVec(topPos, visited) && Util::isSameColor(pixels[topPos.row][topPos.col].color, startColor)) {
			posPixelsToChange.push(topPos);
		}

		if (bottomPos.row < rows && !posInVec(bottomPos, visited) && Util::isSameColor(pixels[bottomPos.row][bottomPos.col].color, startColor)) {
			posPixelsToChange.push(bottomPos);
		}

		PixelChange pixelChange;
		pixelChange.row = pos.row;
		pixelChange.col = pos.col;
		pixelChange.prevColor = pixels[pos.row][pos.col].color;
		pixelChange.newColor = colorPicker.selectedColor;

		stateChange.push_back(pixelChange);

		pixels[pos.row][pos.col].color = colorPicker.selectedColor;

	}

	history.addStateChange(stateChange);
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

	int borderWidth = 5;
	int fillSelectWidth, fillSelectHeight;
	SDL_QueryTexture(fillSelectTex, NULL, NULL, &fillSelectWidth, &fillSelectHeight);

	if (fillSelectOn) {
		SDL_Rect selectedBckRect = { x, y + height, fillSelectWidth + (borderWidth * 2), fillSelectHeight + (borderWidth * 2) };
		SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
		SDL_RenderFillRect(renderer, &selectedBckRect);
	}

	SDL_Rect fillSelectOptionRect = { x + borderWidth, y + height + borderWidth, fillSelectWidth, fillSelectHeight };
	SDL_RenderCopy(renderer, fillSelectTex, NULL, &fillSelectOptionRect);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

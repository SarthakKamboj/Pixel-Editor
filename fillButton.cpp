/*
#include "fillButton.h"

FillButton::FillButton() : fillButton(Button("Fill", { 40, 54, 133, 255 }, { 33, 43, 97, 255 }, { 26, 33, 71, 255 }, 0, 680, 16)) {

}

void FillButton::update() {
	Canvas* canvas = canvasManager.getCanvas();
	if (canvas == NULL) return;
	fillButton.update();
	// fillArea();
}

void FillButton::render() {
	Canvas* canvas = canvasManager.getCanvas();
	if (canvas == NULL) return;
	fillButton.render();
}

void FillButton::fillArea(int startRow, int startCol) {

	Canvas* canvas = canvasManager.getCanvas();
	if (canvas == NULL) return;
	std::vector<std::vector<Pixel>>& pixels = canvas->pixels;

	int rows = pixels.size();
	if (rows == 0) return;
	int cols = pixels[0].size();

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

bool FillButton::posInVec(Pos& pos, std::vector<Pos>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		Pos& posInVec = vec[i];
		if (posInVec.row == pos.row && posInVec.col == pos.col) {
			return true;
		}
	}
	return false;
}
*/

#include "clearButton.h"

ClearButton::ClearButton(CanvasManager& _canvasManager) :
	clearButton(Button("Clear", { 173, 57, 47, 255 }, { 156, 54, 45, 255 }, { 133, 47, 40, 255 }, 100, 720, 16)),
	canvasManager(_canvasManager)
{
}

void ClearButton::update() {
	clearButton.update();
	if (clearButton.pressedOn) {
		clearCanvas();
	}
}

void ClearButton::render() {
	clearButton.render();
}

void ClearButton::clearCanvas() {
	Canvas* canvas = canvasManager.getCanvas();
	if (canvas == NULL) return;
	std::vector<PixelChange> changes;
	SDL_Color white = { 255, 255, 255, 255 };
	for (unsigned row = 0; row < canvas->pixels.size(); row++) {
		for (unsigned col = 0; col < canvas->pixels[row].size(); col++) {
			Pixel& pixel = canvas->pixels[row][col];
			if (!Util::isSameColor(white, pixel.color)) {
				PixelChange pixelChange;
				pixelChange.row = row;
				pixelChange.col = col;
				pixelChange.prevColor = pixel.color;
				pixelChange.newColor = white;

				canvas->pixels[row][col].color = white;

				changes.push_back(pixelChange);
			}
		}
	}

	history.addStateChange(changes);
}
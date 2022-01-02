#include "canvasCreationModal.h"

CanvasCreationModal::CanvasCreationModal(int _x, int _y) :
	x(_x), y(_y),
	colsLabel(Label("Columns", 16)),
	colsInput(NumberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 })),
	rowsLabel(Label("Row", 16)),
	rowsInput(NumberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 })),
	cellSizeLabel(Label("Cell Size", 16)),
	cellSizeInput(NumberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 })),
	createButton(Button("Create", { 40, 54, 133, 255 }, { 33, 43, 97, 255 }, { 26, 33, 71, 255 }, x, y + 80, 16)),
	closeButton(Button("Close", { 173, 57, 47, 255 }, { 156, 54, 45, 255 }, { 133, 47, 40, 255 }, x, y + 105, 16))
{

}

void CanvasCreationModal::update() {
	if (active) {
		rowsInput.update(x + 100, y + 5);
		colsInput.update(x + 100, y + 30);
		cellSizeInput.update(x + 100, y + 55);
		createButton.update();
		closeButton.update();

		if (closeButton.pressedOn) {
			active = false;
		}

		if (createButton.pressedOn) {
			int size = cellSizeInput.getInputNumber();
			canvasManager.createCanvas(rowsInput.getInputNumber(), colsInput.getInputNumber(), size, size);
			active = false;
		}
	}
}

void CanvasCreationModal::render() {
	if (active) {
		SDL_Color prevColor = Util::getRenderDrawColor();

		Util::setRenderDrawColor({ 0,0,0,255 });

		SDL_Rect rect = { x, y, 200, 130 };
		SDL_RenderFillRect(renderer, &rect);

		rowsLabel.render(x, y + 5);
		rowsInput.render(x + 100, y + 5);

		colsLabel.render(x, y + 30);
		colsInput.render(x + 100, y + 30);

		cellSizeLabel.render(x, y + 55);
		cellSizeInput.render(x + 100, y + 55);

		createButton.render();
		closeButton.render();

		Util::setRenderDrawColor(prevColor);
	}
}
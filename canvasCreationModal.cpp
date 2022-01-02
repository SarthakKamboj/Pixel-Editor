#include "canvasCreationModal.h"

CanvasCreationModal::CanvasCreationModal(int _x, int _y) :
	x(_x), y(_y),
	widthInput(NumberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 })),
	heightInput(NumberInput(16, 100, { 255, 255, 255, 255 }, { 0,0,0,255 })),
	createButton(Button("Create", { 40, 54, 133, 255 }, { 33, 43, 97, 255 }, { 26, 33, 71, 255 }, x, y + 55, 16)),
	closeButton(Button("Close", { 173, 57, 47, 255 }, { 156, 54, 45, 255 }, { 133, 47, 40, 255 }, x, y + 80, 16))
{

}

void CanvasCreationModal::update() {
	if (active) {
		widthInput.update(x, y + 5);
		heightInput.update(x, y + 30);
		createButton.update();
		closeButton.update();

		if (closeButton.pressedOn) {
			active = false;
		}
	}
}

void CanvasCreationModal::render() {
	if (active) {

		SDL_Color prevColor = Util::getRenderDrawColor();

		Util::setRenderDrawColor({ 0,0,0,255 });

		SDL_Rect rect = { x, y, 100, 100 };
		SDL_RenderFillRect(renderer, &rect);

		widthInput.render(x, y + 5);
		heightInput.render(x, y + 30);
		createButton.render();
		closeButton.render();

		Util::setRenderDrawColor(prevColor);
	}
}
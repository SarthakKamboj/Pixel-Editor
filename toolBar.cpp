#include "toolBar.h"

ToolBar::ToolBar(int _x, int _y, int _width, int _height, CanvasManager& _canvasManager) :
	x(_x), y(_y), width(_width), height(_height),
	canvasManager(_canvasManager),
	newButton(Button("New", { 51, 86, 204, 255 }, { 34, 75, 221, 255 }, { 11, 41, 244, 255 }, 0, 0, 16)),
	ccm(CanvasCreationModal(x + 10, y + 10, canvasManager))
{}

void ToolBar::update() {

	newButton.update();

	if (newButton.pressedOn) {
		ccm.active = true;
	}

	ccm.update();
}

void ToolBar::render() {

	SDL_Color prevColor = Util::getRenderDrawColor();

	SDL_Rect rendererMapping = { x, y, width, height };
	Util::setRenderDrawColor({ 125, 125, 125, 255 });
	SDL_RenderFillRect(renderer, &rendererMapping);

	newButton.render();
	ccm.render();

	Util::setRenderDrawColor(prevColor);

}
#include "toolBar.h"

ToolBar::ToolBar(int _x, int _y, int _width, int _height, CanvasManager& _canvasManager) :
	x(_x), y(_y), width(_width), height(_height),
	canvasManager(_canvasManager),
	newButton(Button("New", { 51, 86, 204, 255 }, { 34, 75, 221, 255 }, { 11, 41, 244, 255 }, 0, 0, 16)),
	ccm(CanvasCreationModal(x + 10, y + 10, canvasManager))
{}

void ToolBar::update() {
	// closeButton.update();

	/*
	if (closeButton.pressedOn) {
		input.quit = true;
	}
	*/
	newButton.update();

	if (newButton.pressedOn) {
		ccm.active = true;
	}

	ccm.update();
}

void ToolBar::render() {

	// closeButton.render();
	SDL_Color prevColor = Util::getRenderDrawColor();

	SDL_Rect rendererMapping = { x, y, width, height };
	Util::setRenderDrawColor({ 125, 125, 125, 255 });
	SDL_RenderFillRect(renderer, &rendererMapping);

	newButton.render();
	ccm.render();

	Util::setRenderDrawColor(prevColor);
	// SDL_Rect rect = { 0,0,50,20 };
	// SDL_RenderFillRect(renderer, rect);

	/*
	SDL_Rect rendererMapping = { x, y, width, height };
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rendererMapping);

	int closeWidth, closeHeight;
	SDL_QueryTexture(closeTexture, NULL, NULL, &closeWidth, &closeHeight);

	SDL_Rect mapping = { x, y, closeWidth, closeHeight };
	SDL_RenderCopy(renderer, closeTexture, NULL, &mapping);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	*/
}
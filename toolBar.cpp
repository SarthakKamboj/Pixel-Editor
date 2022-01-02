#include "toolBar.h"

ToolBar::ToolBar(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height),
newButton(Button("New", { 51, 86, 204, 255 }, { 34, 75, 221, 255 }, { 11, 41, 244, 255 }, 0, 0, 16)),
ccm(x + 10, y + 10)
// closeButton(Button("Close", { 51, 86, 204, 255 }, { 34, 75, 221, 255 }, { 11, 41, 244, 255 }, 0, 0, 16))
{
	// closeTexture = Util::getText("Close");
}

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
	newButton.render();
	ccm.render();
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
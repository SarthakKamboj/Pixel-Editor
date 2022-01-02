#include "button.h"

Button::Button(std::string text, SDL_Color _background, SDL_Color _hoverBackground, SDL_Color _backgroundPressedOn, int x, int y, int _fontSize) : background(_background),
hoverBackground(_hoverBackground),
backgroundPressedOn(_backgroundPressedOn)
{
	textTexture = Util::getText(text, _fontSize, { 255, 255, 255, 255 });

	renderMapping.x = x;
	renderMapping.y = y;
	SDL_QueryTexture(textTexture, NULL, NULL, &renderMapping.w, &renderMapping.h);
}

void Button::update() {
	if (input.isMousePressedOn(renderMapping.x, renderMapping.y, renderMapping.w, renderMapping.h)) {
		pressedOn = true;
		pressedOnBackground = true;
	}
	else if (input.isMouseDownOn(renderMapping.x, renderMapping.y, renderMapping.w, renderMapping.h) && pressedOnBackground) {
		pressedOn = false;
	}
	else if (input.isMouseInRegion(renderMapping.x, renderMapping.y, renderMapping.w, renderMapping.h)) {
		hoverOver = true;
		pressedOn = false;
		pressedOnBackground = false;
	}
	else {
		pressedOn = false;
		pressedOnBackground = false;
		hoverOver = false;
	}
}

void Button::render() {
	SDL_Color renderBackground = background;
	if (pressedOnBackground) {
		renderBackground = backgroundPressedOn;
	}
	else if (hoverOver) {
		renderBackground = hoverBackground;
	}

	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	SDL_SetRenderDrawColor(renderer, renderBackground.r, renderBackground.g, renderBackground.b, renderBackground.a);

	SDL_RenderFillRect(renderer, &renderMapping);
	SDL_RenderCopy(renderer, textTexture, NULL, &renderMapping);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

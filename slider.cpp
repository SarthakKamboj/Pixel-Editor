#include "slider.h"

Slider::Slider(int _min, int _max, int _width) : min(_min), max(_max), width(_width)
{
	cur = min + (internalCur * (max - min));
}


Slider& Slider::operator=(const Slider& other) {
	cur = other.cur;
	min = other.min;
	max = other.max;
	internalCur = other.internalCur;
	internalMin = other.internalMin;
	internalMax = other.internalMax;
	width = other.width;
	return *this;
}

void Slider::update(int x, int y) {
	int valIconHeight = 20;
	SDL_Rect valRect = { x + (width * internalCur), y - (valIconHeight / 2), 10, valIconHeight };

	if (!active && input.isMouseDownOn(valRect.x, valRect.y, valRect.w, valRect.h)) {
		active = true;
	}

	if (active && !input.mouseDown) {
		active = false;
	}

	if (active) {
		internalCur = ((float)(input.mouseState.x - x)) / width;

		internalCur = fmax(fmin(internalCur, internalMax), internalMin);

		cur = min + (internalCur * (max - min));
	}
}

void Slider::render(int x, int y) {
	SDL_Rect canvasMapping = { x, y, width, 3 };

	SDL_Color prevColor = Util::getRenderDrawColor();

	Util::setRenderDrawColor({ 255, 255, 255, 255 });
	SDL_RenderFillRect(renderer, &canvasMapping);

	int valIconHeight = 20;
	SDL_Rect valRect = { x + (width * internalCur), y - (valIconHeight / 2), 10, valIconHeight };
	SDL_RenderFillRect(renderer, &valRect);

	Util::setRenderDrawColor(prevColor);
}
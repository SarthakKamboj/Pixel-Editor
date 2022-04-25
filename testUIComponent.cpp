#include "testUIComponent.h"

TestUIComponent::TestUIComponent(int _x, int _y, int _z, SDL_Color _hoverColor, SDL_Color _baseColor) :
	UIComponent(_x, _y, _z, 100, 100, &uiComponentRegistrar), hoverColor(_hoverColor), baseColor(_baseColor)
{}

void TestUIComponent::update() {
	UIComponent::update();
	hover = input.isMouseInRegion(x, y, width, height);
}

void TestUIComponent::render() {

	SDL_Color prev = Util::getRenderDrawColor();

	SDL_Rect rendererMapping = { x, y, width, height };
	SDL_Color color = baseColor;
	if (hover) {
		color = hoverColor;
	}

	if (focused) {
		int borderWidth = 5;
		SDL_Rect borderMapping;

		borderMapping.x = rendererMapping.x - borderWidth;
		borderMapping.y = rendererMapping.y - borderWidth;
		borderMapping.w = rendererMapping.w + (borderWidth * 2);
		borderMapping.h = rendererMapping.h + (borderWidth * 2);

		Util::setRenderDrawColor({ 125, 125, 125, 255 });
		SDL_RenderFillRect(renderer, &borderMapping);

	}

	Util::setRenderDrawColor(color);
	SDL_RenderFillRect(renderer, &rendererMapping);

	Util::setRenderDrawColor(prev);
}
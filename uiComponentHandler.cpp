#include "uiComponentHandler.h"

UIComponent::UIComponent(int _x, int _y, int _z, int _width, int _height, UIComponentRegistrar* _uiRegistrar) :
	x(_x), y(_y), z(_z),
	width(_width), height(_height),
	uiRegistrar(_uiRegistrar)
{
	uiRegistrar->addUIComponent(this);
}


void UIComponent::update() {
	if (!focused && input.isMousePressedOn(x, y, width, height)) {
		// if (!focused && input.isMousePressedOn(this)) {
		focused = true;
	}

	if (focused && input.mousePressed && !input.isMousePressedOn(x, y, width, height)) {
		// if (focused && input.mousePressed && !input.isMousePressedOn(this)) {
		focused = false;
	}

	/*
	if (focused && !input.mouseDown) {
		focused = false;
	}
	*/
}

void UIComponent::render() {}

UIComponentRegistrar::UIComponentRegistrar() {}

void UIComponentRegistrar::addUIComponent(UIComponent* uiComponent) {
	uiComponentLayers[uiComponent->z].push_back(uiComponent);

	bool found = false;
	for (unsigned idx = 0; idx < zLayers.size(); idx++) {
		if (zLayers[idx] == uiComponent->z) {
			found = true;
			break;
		}
	}

	if (!found) {
		zLayers.push_back(uiComponent->z);
		std::sort(zLayers.begin(), zLayers.begin() + zLayers.size());
	}
}

void UIComponentRegistrar::update() {
	for (int idx = ((int)(zLayers.size())) - 1; idx >= 0; idx--) {
		for (UIComponent* uiComponent : uiComponentLayers[zLayers[idx]]) {
			uiComponent->update();
		}
	}
}

void UIComponentRegistrar::render() {
	// for (int idx = ((int)(zLayers.size())) - 1; idx >= 0; idx--) {
	for (int idx = 0; idx < (int)zLayers.size(); idx++) {
		for (UIComponent* uiComponent : uiComponentLayers[zLayers[idx]]) {
			uiComponent->render();
		}
	}
}

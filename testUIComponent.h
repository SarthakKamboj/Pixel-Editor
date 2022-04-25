#pragma once

#include "uiComponentHandler.h"
#include "input.h"
#include "SDL.h"
#include "util.h"

extern UIComponentRegistrar uiComponentRegistrar;
extern Input input;
extern SDL_Renderer* renderer;

class TestUIComponent : public UIComponent {
public:
	TestUIComponent(int x, int y, int z, SDL_Color hoverColor, SDL_Color baseColor);
	void update();
	void render();

private:
	bool hover = false;
	SDL_Color hoverColor, baseColor;
};

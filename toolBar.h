#pragma once

#include "SDL.h"
#include "util.h"
#include "button.h"
#include "canvasCreationModal.h"

extern SDL_Renderer* renderer;

class ToolBar {
public:
	ToolBar(int x, int y, int width, int height);
	void update();
	void render();

private:
	int width, height;
	int x, y;

	CanvasCreationModal ccm;

	// SDL_Texture* closeTexture;
	Button newButton;
	// Button closeButton;
};

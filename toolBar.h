#pragma once

#include "SDL.h"
#include "util.h"
#include "button.h"
#include "canvasCreationModal.h"
#include "canvasManager.h"

extern SDL_Renderer* renderer;

class ToolBar {
public:
	ToolBar(int x, int y, int width, int height, CanvasManager& canvasManager);
	void update();
	void render();

private:
	int x, y;
	int width, height;

	CanvasManager& canvasManager;
	CanvasCreationModal ccm;

	Button newButton;
};

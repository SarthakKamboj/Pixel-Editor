#pragma once

#include "numberInput.h"
#include "SDL.h"
#include "util.h"
#include "button.h"
#include "canvasManager.h"
#include "label.h"

extern SDL_Renderer* renderer;

class CanvasCreationModal {
public:
	CanvasCreationModal(int x, int y, CanvasManager& canvasManager);
	bool active = false;
	void update();
	void render();
private:
	int x, y;

	Label colsLabel;
	NumberInput colsInput;
	Label rowsLabel;
	NumberInput rowsInput;
	Label cellSizeLabel;
	NumberInput cellSizeInput;
	Button createButton;
	Button closeButton;

	CanvasManager& canvasManager;
};

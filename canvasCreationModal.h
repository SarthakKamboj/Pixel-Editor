#pragma once

#include "numberInput.h"
#include "SDL.h"
#include "util.h"
#include "button.h"

extern SDL_Renderer* renderer;

class CanvasCreationModal {
public:
	CanvasCreationModal(int x, int y);
	bool active = false;
	void update();
	void render();
private:
	int x, y;

	NumberInput widthInput;
	NumberInput heightInput;
	Button createButton;
	Button closeButton;

};

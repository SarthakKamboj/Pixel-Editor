#pragma once

#include "button.h"
#include "canvasManager.h"
#include "history.h"
#include "pixelChange.h"
#include "util.h"

// extern CanvasManager canvasManager;
extern History history;

class ClearButton {
public:
	ClearButton(CanvasManager& canvasManager);
	void update();
	void render();

private:
	Button clearButton;
	CanvasManager& canvasManager;

	void clearCanvas();
};

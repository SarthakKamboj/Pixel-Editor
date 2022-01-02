#pragma once
#include "SDL.h"
#include <vector>
#include "input.h"
#include "canvas.h"
#include "pixelChange.h"

class Canvas;
extern Input input;

class History {
public:

	Canvas* canvas;
	std::vector<PixelChange> stateChanges;

	void update();
};

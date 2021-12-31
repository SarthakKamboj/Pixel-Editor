#pragma once

#include "SDL.h"
#include <vector>
#include "canvas.h"

struct PixelChange {
	int row, col;
	SDL_Color prevColor;
	SDL_Color newColor;

	PixelChange() : row(0), col(0), prevColor({ 255, 255, 255, 255 }), newColor({ 0,0,0, 255 }) {}

	PixelChange(const PixelChange& other) : row(other.row), col(other.col),
		prevColor(other.prevColor), newColor(other.newColor) {

	}
};

class History {
public:

	// Canvas* canvas;
	std::vector<PixelChange> stateChanges;

	void update();
};

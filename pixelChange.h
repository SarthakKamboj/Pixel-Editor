#pragma once

#include "SDL.h"

struct PixelChange {
	int row, col;
	SDL_Color prevColor;
	SDL_Color newColor;

	PixelChange() : row(0), col(0), prevColor({ 255, 255, 255, 255 }), newColor({ 0,0,0, 255 }) {}

	PixelChange(const PixelChange& other) : row(other.row), col(other.col),
		prevColor(other.prevColor), newColor(other.newColor) {}

	PixelChange& operator=(const PixelChange& other) {
		row = other.row;
		col = other.col;
		prevColor = other.prevColor;
		newColor = other.newColor;
		return *this;
	}
};

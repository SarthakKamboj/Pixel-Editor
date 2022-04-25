#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include "pixel.h"
#include "history.h"
#include "util.h"
#include "colorPicker.h"

extern History history;

struct Pos {
	int row, col;

	Pos() : row(0), col(0) {}
	Pos(int _row, int _col) : row(_row), col(_col) {}
	Pos(const Pos& other) : row(other.row), col(other.col) {}

	Pos& operator=(const Pos& other) {
		row = other.row;
		col = other.col;
	}
};

class Canvas {
public:
	Canvas(int _rows, int _cols, int _widthPerCell, int _heightPerCell, SDL_Renderer* renderer, ColorPicker& colorPicker);
	~Canvas();
	Canvas& operator=(const Canvas& other);
	void update(int x, int y);
	void render(int x, int y);

	std::vector<std::vector<Pixel>> pixels;

private:
	int rows, cols, widthPerCell, heightPerCell;
	int width, height;

	bool fillSelectOn = false;

	ColorPicker& colorPicker;

	SDL_Texture* fillSelectTex;
	SDL_Renderer* renderer;

	void fillSelect(int startRow, int startCol);
	bool posInVec(Pos& pos, std::vector<Pos>& vec);

	bool active = false;

	void populatePixels();
	void clearPixels();
};
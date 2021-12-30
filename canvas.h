#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include "pixel.h"

extern SDL_Renderer* renderer;
extern ColorPicker colorPicker;

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
	Canvas(int _rows, int _cols, int _widthPerCell, int _heightPerCell);
	void update(int x, int y);
	void render(int x, int y);

private:
	int rows, cols, widthPerCell, heightPerCell;
	int width, height;

	bool fillSelectOn = false;

	SDL_Texture* canvasTexture;
	SDL_Texture* fillSelectTex;

	Pixel** pixels;

	void fillSelect(int startRow, int startCol);
	bool posInVec(Pos& pos, std::vector<Pos>& vec);
	bool sameColor(SDL_Color& c1, SDL_Color& c2);
};
#pragma once

#include "SDL.h"
#include "util.h"
#include "input.h"
#include "math.h"

extern SDL_Renderer* renderer;
extern Input input;

class Slider {
public:
	Slider(int min, int max, int width);
	void update(int x, int y);
	void render(int x, int y);

	int cur;
private:

	int min, max;

	int width;
	float internalMin = 0.0f, internalMax = 1.0f;
	float internalCur = 0.5f;
};

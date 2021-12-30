#pragma once

#include "SDL.h"
#include <iostream>

class Input {
public:
	void update();
	bool quit = false;
	bool mouseDown = false;
};

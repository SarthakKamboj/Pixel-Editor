#pragma once

#include <vector>
#include <algorithm>
// #include "input.h"
// #include "canvas.h"
#include "pixelChange.h"

// extern Input input;

class History {
public:
	History();
	void addStateChange(std::vector<PixelChange>& stateChange);

	std::vector<std::vector<PixelChange>> stateChanges;

	int numStateChanges = 0;
	int maxHistorySize = 5;
};

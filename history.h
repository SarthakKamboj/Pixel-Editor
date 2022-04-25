#pragma once

#include <vector>
#include <algorithm>
#include "pixelChange.h"

class History {
public:
	History();
	void addStateChange(std::vector<PixelChange>& stateChange);

	std::vector<std::vector<PixelChange>> stateChanges;

	int numRecordedStateChanges = 0;
	int maxHistorySize = 5;

	int numRecordedUndoActions = 0;
};

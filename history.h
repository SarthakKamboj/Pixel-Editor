#pragma once

#include <vector>
#include <algorithm>
#include "pixelChange.h"

class History {
public:
	History();
	void addStateChange(std::vector<PixelChange>& stateChange);
	// void addUndoAction(std::vector<PixelChange>& undoChange);

	std::vector<std::vector<PixelChange>> stateChanges;
	// std::vector<std::vector<PixelChange>> pastUndos;

	int numRecordedStateChanges = 0;
	int maxHistorySize = 5;

	int numRecordedUndoActions = 0;
	// int maxUndoRecordSize = 5;
};

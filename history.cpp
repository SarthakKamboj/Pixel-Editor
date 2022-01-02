#include "history.h"


History::History() {
	stateChanges.resize(maxHistorySize);
}

void History::addStateChange(std::vector<PixelChange>& stateChange) {
	if (numStateChanges < maxHistorySize) {
		numStateChanges += 1;
		stateChanges[numStateChanges - 1] = stateChange;
	}
	else {
		std::rotate(stateChanges.begin(), stateChanges.begin() + 1, stateChanges.end());
		stateChanges[maxHistorySize - 1] = stateChange;
	}
}

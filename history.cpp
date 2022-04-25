#include "history.h"


History::History() {
	stateChanges.resize(maxHistorySize);
}

void History::addStateChange(std::vector<PixelChange>& stateChange) {
	if (numRecordedStateChanges < maxHistorySize) {
		numRecordedStateChanges += 1;
		stateChanges[numRecordedStateChanges - 1] = stateChange;
	}
	else {
		std::rotate(stateChanges.begin(), stateChanges.begin() + 1, stateChanges.end());
		stateChanges[maxHistorySize - 1] = stateChange;
	}
	numRecordedUndoActions = 0;
}


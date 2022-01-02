#include "history.h"


History::History() {
	stateChanges.resize(maxHistorySize);
	// pastUndos.resize(maxUndoRecordSize);
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

/*
void History::addUndoAction(std::vector<PixelChange>& undoAction) {
	if (numRecordedUndoActions < maxUndoRecordSize) {
		numRecordedUndoActions += 1;
		pastUndos[numRecordedUndoActions - 1] = undoAction;
	}
	else {
		std::rotate(pastUndos.begin(), pastUndos.begin() + 1, pastUndos.end());
		pastUndos[numRecordedUndoActions - 1] = undoAction;
	}
}
*/

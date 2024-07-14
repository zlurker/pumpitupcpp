#include "NoteLineData.h"

NoteLineData::NoteLineData(float nPY) {
	notesPositionY = nPY;
}

void NoteLineData::AddNoteToLine(int nPX) {
	notesPositionX.push_back(nPX);
}

float NoteLineData::GetNotesYPosition() {
	return notesPositionY;
}

const std::vector<int>& NoteLineData::GetNotesXPosition() {
	return notesPositionX;
}
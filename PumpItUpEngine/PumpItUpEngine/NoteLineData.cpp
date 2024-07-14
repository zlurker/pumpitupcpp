#include "NoteLineData.h"

NoteLineData::NoteLineData(float nPY) {
	notesPositionY = nPY;
}

void NoteLineData::AddNoteToLine(int nPX,char nT) {\
	notesPositionX.push_back(NoteData(nPX, nT));
}

float NoteLineData::GetNotesYPosition() {
	return notesPositionY;
}

const std::vector<NoteData>& NoteLineData::GetNotesXPosition() {
	return notesPositionX;
}
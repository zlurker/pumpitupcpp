#include "NoteLineData.h"

NoteLineData::NoteLineData(float nPY, int nPX) {
	notesPositionY = nPY;
	notesPositionX.push_back(nPX);
}

void NoteLineData::AddNoteToLine(int nPX) {
	notesPositionX.push_back(nPX);
}
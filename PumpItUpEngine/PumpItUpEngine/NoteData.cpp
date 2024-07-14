#include "NoteData.h"

NoteData::NoteData(int xP, char nT) {
	xPosition = xP;
	noteType = nT;
}

int NoteData::GetXPosition() {
	return xPosition;
}

int NoteData::GetNoteType() {
	return noteType;
}
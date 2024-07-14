#pragma once
#include <vector>
#include "NoteData.h"

class NoteLineData {
public:
	NoteLineData(float);
	void AddNoteToLine(int,char);

	float GetNotesYPosition();
	const std::vector<NoteData>& GetNotesXPosition();

private:
	float notesPositionY;
	std::vector<NoteData> notesPositionX;
};
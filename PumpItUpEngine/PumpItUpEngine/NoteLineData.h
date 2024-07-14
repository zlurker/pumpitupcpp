#pragma once
#include <vector>

class NoteLineData {
public:
	NoteLineData(float);
	void AddNoteToLine(int);

	float GetNotesYPosition();
	const std::vector<int>& GetNotesXPosition();

private:
	float notesPositionY;
	std::vector<int> notesPositionX;
};
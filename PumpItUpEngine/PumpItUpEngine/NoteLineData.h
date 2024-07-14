#pragma once
#include <vector>

class NoteLineData {
public:
	NoteLineData(float, int);
	void AddNoteToLine(int);

private:
	float notesPositionY;
	std::vector<int> notesPositionX;
};
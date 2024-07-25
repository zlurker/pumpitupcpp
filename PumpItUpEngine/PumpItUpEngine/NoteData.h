#pragma once
class NoteData
{
public:
	NoteData(int, char);
	int GetXPosition();
	int GetNoteType();

private:
	int xPosition;
	char noteType;

};


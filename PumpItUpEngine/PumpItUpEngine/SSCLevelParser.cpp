#include "SSCLevelParser.h"
#include <unordered_map>
#include <iostream>

void SSCLevelParser::OnEndFileParsing() {
	std::unordered_map<std::string, std::string>* sscKeyValues = GetSSCKeyValues();
	std::cout << "NoteData: " << (*sscKeyValues)["NOTES"] << std::endl;

	GenerateNoteLineData((*sscKeyValues)["NOTES"]);
}

void SSCLevelParser::GenerateNoteLineData(const std::string& nD) {
	std::vector<std::string> noteSections =  Split(nD, ",");

	for (int i = 0; i < noteSections.size(); i++) {
		std::vector<std::string> noteSectionLines = Split(noteSections[i], "\n");

		for (int j = 0; j < noteSectionLines.size(); j++) {
			float position = i + ((1.0f / noteSectionLines.size()) * j);
			NoteLineData noteLineData(position);

			for (int k = 0; k < noteSectionLines[j].size(); k++) 
				if (noteSectionLines[j][k] != '0')
					noteLineData.AddNoteToLine(k);
			
			if (noteLineData.GetNotesXPosition().size() > 0)
				noteLineDatas.push_back(noteLineData);
		}
	}

	std::cout << "Completed loading of stepchart notes data" << std::endl;
}
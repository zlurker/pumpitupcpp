#include "SSCLevelParser.h"
#include <unordered_map>
#include <iostream>

void SSCLevelParser::OnEndFileParsing() {
	std::unordered_map<std::string, std::string>* sscKeyValues = GetSSCKeyValues();
	std::cout << "NoteData: " << (*sscKeyValues)["NOTES"] << std::endl;
}
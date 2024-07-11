#include "SSCLevelParser.h"
#include <unordered_map>

SSCLevelParser::SSCLevelParser(GameLevel* gL) {
	gameLevel = gL;
}

void SSCLevelParser::OnEndFileParsing() {
	std::unordered_map<std::string, std::string>* sscKeyValues = GetSSCKeyValues();
}
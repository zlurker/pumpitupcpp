#include "MainSSCParser.h"
#include <iostream>
MainSSCParser::MainSSCParser(SSCFile* sF) {
	sscFile = sF;
	isHeaders = true;
	previousCheckPoint = 0;
}

void MainSSCParser::OnStartParse() {
	isHeaders = true;
	previousCheckPoint = 0;
}

void MainSSCParser::OnEndKeyValuePair(const std::string& key) {
	
	if (key == "NOTEDATA") {
		std::unordered_map<std::string, std::string>* sscKeyValues = GetSSCKeyValues();
		int currentChar = GetCurrentChar();

		if (isHeaders) {
			sscFile->HandleHeader(*sscKeyValues);
			isHeaders = false;
		}
		else
			sscFile->HandleLevel(*sscKeyValues, previousCheckPoint, currentChar);

		sscKeyValues->clear();
		previousCheckPoint = currentChar;
	}
}

void MainSSCParser::OnEndFileParsing() {
	std::unordered_map<std::string, std::string>* sscKeyValues = GetSSCKeyValues();
	int currentChar = GetCurrentChar();

	sscFile->HandleLevel(*sscKeyValues, previousCheckPoint, currentChar);
}
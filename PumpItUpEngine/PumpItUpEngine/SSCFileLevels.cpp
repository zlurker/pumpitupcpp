#include "SSCFileLevels.h"
#include <iostream>
#include "SSCLevelParser.h"

SSCFileLevels::SSCFileLevels(const std::string& sT, const std::string& m, int cS, int cE) {
	stepType = sT;
	meter = m;
	charStart = cS;
	charEnd = cE;
}

void SSCFileLevels::GenerateSSCFileLevelStringDetails() {
	std::cout << "------Level Details------" << std::endl;

	std::cout << "StepType: " << stepType << std::endl;
	std::cout << "Meter: " << meter << std::endl;
}

int SSCFileLevels::GetCharStart() {
	return charStart;
}

int SSCFileLevels::GetCharEnd() {
	return charEnd;
}
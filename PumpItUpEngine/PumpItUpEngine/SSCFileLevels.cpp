#include "SSCFileLevels.h"
#include <iostream>

SSCFileLevels::SSCFileLevels(const std::string& sT, const std::string& m, int cS, int cE) {
	stepType = sT;
	meter = m;
	charStart = cS;
	charEnd = cE;
}

void SSCFileLevels::GenerateSSCFileLevelDetails() {
	std::cout << "------Level Details------" << std::endl;

	std::cout << "StepType: " << stepType << std::endl;
	std::cout << "Meter: " << meter << std::endl;
}
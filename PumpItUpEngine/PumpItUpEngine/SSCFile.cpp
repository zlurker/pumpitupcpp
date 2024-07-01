#include "SSCFile.h"
#include <iostream>

SSCFile::SSCFile(std::string dP, std::string sP) {
	directoryPath = dP;
	sscFile = sP;
	std::cout << "Created new SSC file entry at directory " << directoryPath << "." << std::endl << "SSC Path : " << sscFile << std::endl;
}

std::string SSCFile::GetDirectoryPath() {
	return directoryPath;
}

std::string SSCFile::GetSSCPath() {
	return sscFile;
}
#include "SSCFile.h"

SSCFile::SSCFile(std::string dP, std::string sP) {
	directoryPath = dP;
	sscPath = sP;
}

std::string SSCFile::GetDirectoryPath() {
	return directoryPath;
}

std::string SSCFile::GetSSCPath() {
	return sscPath;
}
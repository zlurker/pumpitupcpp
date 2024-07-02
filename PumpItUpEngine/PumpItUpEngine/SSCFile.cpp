#include "SSCFile.h"
#include <fstream>
#include <iostream>

SSCFile::SSCFile(std::string dP, std::string sP) {
	directoryPath = dP;
	sscFile = sP;

	std::cout << "Created new SSC file entry at directory " << directoryPath << "." << std::endl << "SSC Path : " << sscFile << std::endl;
	LoadSSCFileDetails(CombinePaths(directoryPath, sscFile));	
}

void SSCFile::LoadSSCFileDetails(std::string sscFilePath) {
	std::ifstream file(sscFilePath);  // Open the file
	if (!file) {
		std::cerr << "Unable to open file";
		return;  // Exit if the file couldn't be opened
	}

	std::cout << "Reading SSC file..." << std::endl;

	std::string content;
	char ch;

	while (file.get(ch)) {
		content += ch;
	}

	file.close(); 

	std::cout << "File content:\n" << content << std::endl;
}

std::string SSCFile::GetDirectoryPath() {
	return directoryPath;
}

std::string SSCFile::GetSSCPath() {
	return sscFile;
}

std::string SSCFile::CombinePaths(const std::string& path1, const std::string& path2) {
	if (path1.back() == '/' || path1.back() == '\\') {
		return path1 + path2;
	}
	else {
		return path1 + '/' + path2;
	}
}
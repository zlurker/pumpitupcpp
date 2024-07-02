#include "SSCFile.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

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

	bool isHeaders = true;
	std::string content;
	int colonIndex = 0;
	int i = 0;
	char ch;

	std::unordered_map<std::string, std::string> sscKeyValues;

	while (file.get(ch)) {
		if (ch == ':') colonIndex = i;

		if (ch == ';') {
			content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());

			std::string key = content.substr(0, colonIndex);
			std::string value = content.substr(colonIndex);

			if (key == "#NOTEDATA")
				if (isHeaders) {
					for (const auto& pair : sscKeyValues) {
						std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
					}

					isHeaders = false;
				}
			sscKeyValues[key] = value;
			content = "";
			i = 0;

			//std::cout << "Key: " << key << " Value: " << sscKeyValues[key] << std::endl;
		}
		else {
			content += ch;
		}
		i++;
	}

	file.close();

	//std::cout << "File content:\n" << content << std::endl;
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
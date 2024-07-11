#include "SSCFile.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>
#include "MainSSCParser.h"

SSCFile::SSCFile(const std::string& dP, const std::string& sP) {
	songLevels = new std::vector<SSCFileLevels*>();
	directoryPath = dP;
	sscFile = sP;

	//std::cout << "Created new SSC file entry at directory " << directoryPath << "." << std::endl << "SSC Path : " << sscFile << std::endl;
	LoadSSCFileDetails(GetSSCFullPath());
}

void SSCFile::LoadSSCFileDetails(const std::string& sscFilePath) {
	MainSSCParser parser = MainSSCParser(this);
	parser.ParseFile(sscFilePath);

	/*std::ifstream file(sscFilePath);  // Open the file
	if (!file) {
		std::cerr << "Unable to open file";
		return;  // Exit if the file couldn't be opened
	}

	//std::cout << "Reading SSC file..." << std::endl;

	bool isHeaders = true;
	int previousCheckPoint = 0;
	int i = 0;
	std::string content;
	char ch;

	std::unordered_map<std::string, std::string> sscKeyValues;

	while (file.get(ch)) {

		if (ch == ';') {
			content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());

			std::vector<std::string> keyValuePair = Split(content, ":");
			std::vector<std::string> keyArray = Split(keyValuePair[0], "#");

			std::string key = keyArray[keyArray.size() - 1];
			std::string value = keyValuePair.size() > 1 ? keyValuePair[1] : "";

			sscKeyValues[key] = value;

			if (key == "NOTEDATA") {
				if (isHeaders) {
					HandleHeader(sscKeyValues);
					isHeaders = false;
				}
				else
					HandleLevel(sscKeyValues, previousCheckPoint, i);

				sscKeyValues.clear();
				previousCheckPoint = i;
			}

			content = "";
			//std::cout << "Key: " << key << " Value: " << sscKeyValues[key] << std::endl;
		}
		else {
			content += ch;
		}

		i++;
	}

	HandleLevel(sscKeyValues, previousCheckPoint, i);

	file.close();
	*/
}

std::string SSCFile::GetDirectoryPath() {
	return directoryPath;
}

std::string SSCFile::GetSSCPath() {
	return sscFile;
}

std::string SSCFile::GetSSCFullPath() {
	return CombinePaths(directoryPath, sscFile);
}

void SSCFile::GenerateSSCChartDetails() {
	std::cout << "------------SONG DETAILS------------" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Artist: " << artist << std::endl;
	std::cout << "Banner: " << bannerPath << std::endl;
	std::cout << "Music: " << musicPath << std::endl;
	std::cout << "Song Category: " << songCategory << std::endl;
	std::cout << "Display BPM: " << displayBpm << std::endl;

	for (int i = 0; i < songLevels->size(); i++)
		(*songLevels)[i]->GenerateSSCFileLevelStringDetails();
}

std::string SSCFile::CombinePaths(const std::string& path1, const std::string& path2) {
	if (path1.back() == '/' || path1.back() == '\\') {
		return path1 + path2;
	}
	else {
		return path1 + '/' + path2;
	}
}

std::vector<std::string> SSCFile::Split(const std::string& str, const std::string& delimiter) {
	std::vector<std::string> tokens;
	std::regex regex(delimiter);
	std::sregex_token_iterator iter(str.begin(), str.end(), regex, -1);
	std::sregex_token_iterator end;

	while (iter != end) {
		tokens.push_back(*iter++);
	}

	return tokens;
}

void SSCFile::HandleHeader(const std::unordered_map<std::string, std::string>& map) {
	name = map.at("TITLE");
	artist = map.at("ARTIST");
	bannerPath = map.at("BANNER");
	musicPath = map.at("MUSIC");
	songCategory = map.at("SONGCATEGORY");
	displayBpm = map.at("DISPLAYBPM");
}

void SSCFile::HandleLevel(const std::unordered_map<std::string, std::string>& map, int charStart, int charEnd) {
	SSCFileLevels* level = new SSCFileLevels(map.at("STEPSTYPE"), map.at("METER"), charStart, charEnd);
	songLevels->push_back(level);
}

SSCFileLevels* SSCFile::GetLevel(int id) {
	return (*songLevels)[id];
}
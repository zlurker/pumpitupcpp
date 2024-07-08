#include "FileParserBase.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>

FileParserBase::FileParserBase(const std::string& fP) {
	filePath = fP;
	currentChar = 0;
}

void FileParserBase::ParseFile() {
	std::ifstream file(filePath);  // Open the file
	if (!file) {
		std::cerr << "Unable to open file";
		return;  // Exit if the file couldn't be opened
	}

	std::string content;
	char ch;

	while (file.get(ch)) {

		if (ch == ';') {
			content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());

			std::vector<std::string> keyValuePair = Split(content, ":");
			std::vector<std::string> keyArray = Split(keyValuePair[0], "#");

			std::string key = keyArray[keyArray.size() - 1];
			std::string value = keyValuePair.size() > 1 ? keyValuePair[1] : "";

			sscKeyValues[key] = value;

			OnEndKeyValuePair();
		}
		else {
			content += ch;
		}

		currentChar++;
	}

	file.close();
}

int FileParserBase::GetCurrentChar() {
	return currentChar;
}

std::unordered_map<std::string, std::string>* FileParserBase::GetSSCKeyValues() {
	return &sscKeyValues;
}

void FileParserBase::OnEndKeyValuePair() {

}

std::vector<std::string> FileParserBase::Split(const std::string& str, const std::string& delimiter) {
	std::vector<std::string> tokens;
	std::regex regex(delimiter);
	std::sregex_token_iterator iter(str.begin(), str.end(), regex, -1);
	std::sregex_token_iterator end;

	while (iter != end) {
		tokens.push_back(*iter++);
	}

	return tokens;
}
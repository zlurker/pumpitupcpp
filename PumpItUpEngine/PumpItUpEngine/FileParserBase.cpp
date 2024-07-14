#include "FileParserBase.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>

void FileParserBase::ParseFile(const std::string& filePath) {
	ParseFile(filePath, 0, std::nullopt);
}

void FileParserBase::ParseFile(const std::string& filePath, std::optional<int> startIndex, std::optional<int> length) {
	currentChar = -1;
	OnStartParse();

	std::ifstream file(filePath);  // Open the file
	if (!file) {
		std::cerr << "Unable to open file";
		return;  // Exit if the file couldn't be opened
	}
	
	std::string content;
	char ch;

	while (file.get(ch)) {

		currentChar++;

		if (startIndex.has_value())
			if (startIndex.value() > currentChar)
				continue;

		if (ch == ';') {
			

			std::vector<std::string> keyValuePair = Split(content, ":");
			std::vector<std::string> keyArray = Split(keyValuePair[0], "#");

			std::string key = keyArray[keyArray.size() - 1];
			key.erase(std::remove(key.begin(), key.end(), '\n'), key.end());

			std::string value = keyValuePair.size() > 1 ? keyValuePair[1] : "";

			sscKeyValues[key] = value;

			OnEndKeyValuePair(key);
			content = "";
		}
		else {
			content += ch;
		}

		if (length.has_value())
			if (length.value() <= currentChar)
				break;
	}

	OnEndFileParsing();
	file.close();
	sscKeyValues.clear();
}

int FileParserBase::GetCurrentChar() {
	return currentChar;
}

std::unordered_map<std::string, std::string>* FileParserBase::GetSSCKeyValues() {
	return &sscKeyValues;
}

void FileParserBase::OnStartParse() {

}

void FileParserBase::OnEndKeyValuePair(const std::string& key) {

}

void FileParserBase::OnEndFileParsing() {

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
#pragma once
#include <unordered_map>
#include <string>

class FileParserBase
{
public:
	void ParseFile(std::string);

private:
	virtual int GetCurrentChar();
	virtual std::unordered_map<std::string, std::string>* GetSSCKeyValues();
	virtual void OnEndKeyValuePair();
	virtual void OnEndFileParsing();
	virtual std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

	int currentChar;
	std::unordered_map<std::string, std::string> sscKeyValues;
};


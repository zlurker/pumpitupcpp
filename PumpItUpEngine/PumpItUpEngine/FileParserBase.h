#pragma once
#include <unordered_map>
#include <string>

class FileParserBase
{
public:
	FileParserBase(const std::string&);
private:
	virtual int GetCurrentChar();
	virtual std::unordered_map<std::string, std::string>* GetSSCKeyValues();
	virtual void OnEndKeyValuePair();
	virtual std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

	int currentChar;
	std::unordered_map<std::string, std::string> sscKeyValues;

	std::string filePath;
	void ParseFile();
};


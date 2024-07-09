#pragma once
#include <unordered_map>
#include <string>
#include <optional>

class FileParserBase
{
public:
	void ParseFile(const std::string&);
	void ParseFile(const std::string&, std::optional<int>, std::optional<int>);

	int GetCurrentChar();
	std::unordered_map<std::string, std::string>* GetSSCKeyValues();
	std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

	virtual void OnStartParse();
	virtual void OnEndKeyValuePair(const std::string& key);
	virtual void OnEndFileParsing();

private:

	int currentChar;
	std::unordered_map<std::string, std::string> sscKeyValues;
};


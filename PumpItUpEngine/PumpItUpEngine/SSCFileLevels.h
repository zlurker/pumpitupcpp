#include <string>

#pragma once
class SSCFileLevels
{
public:
	SSCFileLevels(const std::string&, const std::string&,int,int);
	void GenerateSSCFileLevelStringDetails();
	int GetCharStart();
	int GetCharEnd();

private:
	std::string stepType;
	std::string meter;

	int charStart;
	int charEnd;
};
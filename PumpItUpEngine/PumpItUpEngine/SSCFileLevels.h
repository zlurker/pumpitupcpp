#include <string>

#pragma once
class SSCFileLevels
{
public:
	SSCFileLevels(const std::string&, const std::string&,int,int);
	void GenerateSSCFileLevelDetails();

private:
	std::string stepType;
	std::string meter;

	int charStart;
	int charEnd;
};
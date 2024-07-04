#include <string>

#pragma once
class SSCFileLevels
{
public:
	SSCFileLevels(const std::string&, const std::string&);
	void GenerateSSCFileLevelDetails();

private:
	std::string stepType;
	std::string meter;
};
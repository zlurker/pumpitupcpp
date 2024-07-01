#pragma once
#include <string>
class SSCFile
{
public:
	SSCFile(std::string, std::string);
	std::string GetDirectoryPath();
	std::string GetSSCPath();

private:
	std::string directoryPath;
	std::string sscFile;
};


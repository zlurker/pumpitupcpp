#pragma once
#include <string>
#include <vector>
class SSCFile
{
public:
	SSCFile(std::string, std::string);
	void LoadSSCFileDetails(std::string);
	std::string GetDirectoryPath();
	std::string GetSSCPath();

private:
	std::string CombinePaths(const std::string& path1, const std::string& path2);
	std::vector<std::string> Split(const std::string& str, const std::string& delimiter);
	std::string directoryPath;
	std::string sscFile;
};


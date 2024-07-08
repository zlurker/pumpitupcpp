#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "SSCFileLevels.h"

class SSCFile
{
public:
	SSCFile(const std::string&, const std::string&);
	void LoadSSCFileDetails(const std::string&);
	std::string GetDirectoryPath();
	std::string GetSSCPath();
	void GenerateSSCChartDetails();

	void HandleHeader(const std::unordered_map<std::string, std::string>&);
	void HandleLevel(const std::unordered_map<std::string, std::string>&, int, int);

private:
	std::string CombinePaths(const std::string& path1, const std::string& path2);
	std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

	std::string directoryPath;
	std::string sscFile;

	std::string name;
	std::string artist;
	std::string bannerPath;
	std::string musicPath;
	std::string songCategory;
	std::string displayBpm;

	std::vector<SSCFileLevels*>* songLevels;
};


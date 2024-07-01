#pragma once
#include "SSCFile.h"
#include <vector>

class FileLoader
{
public:
	FileLoader();
	void LoadSSCFiles();

private:
	void ScanDirectory(std::string path);
	std::vector<SSCFile*>* sscFiles;
};


#pragma once
#include "SSCFile.h"
#include <vector>

class FileLoader
{
public:
	FileLoader();
	void LoadSSCFiles();

private:
	std::vector<SSCFile*>* sscFiles;
};


#pragma once
#include "FileParserBase.h"
#include "SSCFile.h"
#include <string>

class MainSSCParser :
    public FileParserBase
{
public:
    MainSSCParser(SSCFile*);

private:
    SSCFile* sscFile;
};


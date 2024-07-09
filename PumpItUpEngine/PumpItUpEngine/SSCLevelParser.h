#pragma once
#include "FileParserBase.h"
#include "SSCFileLevels.h"

class SSCLevelParser :
    public FileParserBase
{
public:
    SSCLevelParser(SSCFileLevels*);
private:
    virtual void OnEndFileParsing();

    SSCFileLevels* sscLevel;
};


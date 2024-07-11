#pragma once
#include "FileParserBase.h"
#include "SSCFileLevels.h"
#include "GameLevel.h"

class SSCLevelParser :
    public FileParserBase
{

private:
    virtual void OnEndFileParsing();
};


#pragma once
#include "FileParserBase.h"
#include "SSCFileLevels.h"
#include "GameLevel.h"

class SSCLevelParser :
    public FileParserBase
{
public:
    SSCLevelParser(GameLevel*);
private:
    virtual void OnEndFileParsing();

    GameLevel* gameLevel;
};


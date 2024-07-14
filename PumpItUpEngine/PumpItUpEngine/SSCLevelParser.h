#pragma once
#include "FileParserBase.h"
#include "SSCFileLevels.h"
#include "GameLevel.h"
#include <vector>
#include "NoteLineData.h"

class SSCLevelParser :
    public FileParserBase
{

private:
    std::vector<NoteLineData> noteLineDatas;
    virtual void OnEndFileParsing();
};


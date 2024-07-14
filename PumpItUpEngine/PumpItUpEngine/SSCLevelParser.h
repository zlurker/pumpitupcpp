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
    void GenerateNoteLineData(const std::string&);

    std::vector<NoteLineData> noteLineDatas;
    virtual void OnEndFileParsing();
};


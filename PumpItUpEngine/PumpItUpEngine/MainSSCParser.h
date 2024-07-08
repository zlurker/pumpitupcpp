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
    virtual void OnStartParse();
    virtual void OnEndKeyValuePair(const std::string& key);
    virtual void OnEndFileParsing();

    SSCFile* sscFile;
    bool isHeaders;
    int previousCheckPoint;
};


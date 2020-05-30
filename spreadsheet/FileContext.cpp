#include "FileContext.h"

FileContext::FileContext() :
    isSet(false)
{
}

FileContext::FileContext(const std::string& filename)
{
    setActiveFile(filename);
}

const std::string* FileContext::getActiveFile() const
{
    if (isSet) return &value;
    return nullptr;
}

void FileContext::setActiveFile(const std::string& filename)
{
    value = filename;
    isSet = true;
}

void FileContext::clearActiveFile()
{
    isSet = false;
}

#pragma once
#include <string>

/**
 * @brief Represents a wrapper class for a file name
 * Provides methods to set, modify and clear the name
 *
 */
class FileContext
{
private:
    std::string value;
    bool isSet;
public:
    /**
     * @brief Construct a new File Context object with no unspecified file
     * 
     */
    FileContext();
    /**
     * @brief Construct a new File Context object with the given filename
     * 
     * @param filename the filename
     */
    FileContext(const std::string& filename);
    /**
     * @brief get a pointer to the active file name nullptr otherwise
     * 
     * @return const std::string* 
     */
    const std::string* getActiveFile() const;
    /**
     * @brief Set the active file to filename
     * 
     * @param filename 
     */
    void setActiveFile(const std::string& filename);
    /**
     * @brief clear the filename
     * 
     */
    void clearActiveFile();
};

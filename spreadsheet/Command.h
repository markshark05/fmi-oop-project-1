#pragma once
#include <vector>
#include <string>

class Command {
public:
    virtual std::string getName() = 0;
    virtual std::string run(const std::vector<const std::string>& arguments) = 0;
};

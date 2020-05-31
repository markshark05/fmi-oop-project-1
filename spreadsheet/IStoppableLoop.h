#pragma once

/**
 * @brief Represents an abstract object that can be stopped
 * 
 */
class IStoppableLoop
{
public:
    virtual void stop() = 0;
};

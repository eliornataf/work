/*****************************************************************************
* File Name: CDR Harvester
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CDR_HARVESTER_HPP__
#define __CDR_HARVESTER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string

/*-------------------------------- Structure -------------------------------*/

class CDRHarvester {
public:
    // Constructor

    CDRHarvester(const std::string &a_processorIpAdress, const unsigned int a_processorPortNumber);

    // Destructor

    ~CDRHarvester() = default;

    // Copy Constructor

    CDRHarvester(const CDRHarvester &a_other) = delete;

    // Assignment Operator

    CDRHarvester &operator=(const CDRHarvester &a_other) = delete;

    // Methods

    void RunHarvester();
    void StopHarvester();

private:
    // Methods

    void ReadCDRFromCDRDirectoryAndSendToProcessor();
    std::streampos GetFileSize(const std::string &a_filePath);

    // Class Members

    std::string m_processorIpAdress;
    unsigned int m_processorPortNumber;
    bool m_isHarvesterRunning;
};

#endif /* __CDR_HARVESTER_HPP__ */
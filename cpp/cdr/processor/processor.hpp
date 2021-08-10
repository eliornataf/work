/*****************************************************************************
* File Name: Processor
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __PROCESSOR_HPP__
#define __PROCESSOR_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "../cdrParser/cdrParser.hpp" // CDR Parser Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager Header

/*-------------------------------- Structure -------------------------------*/

class Processor {
public:
    // Constructor

    Processor();

    // Destructor

    ~Processor();

    // Copy Constructor

    Processor(const Processor &a_other) = delete;

    // Assignment Operator

    Processor &operator=(const Processor &a_other) = delete;

    // Methods

    void SendCDRToProcessor(const std::string &a_cdr);
    void RunProcessor();
    void StopProcessor();

    // Constants

    static constexpr unsigned int HARVESTER_PORT_NUMBER = 4040;
    static constexpr unsigned int BUFFER_SIZE = 16384;

private:
    // Constants

    static constexpr unsigned int TEN_MINUTES = 600;

    // Methods

    void RunHarvesterListeningThread();
    std::streampos GetFileSize(const std::string &a_filePath);

    // Class Members

    CDRParser m_cdrParser;
    DataBaseManager *m_dataBaseManager;
    unsigned int *m_cdrFileNumber;
    bool m_isProcessorRunning;
};

#endif /* __PROCESSOR_HPP__ */

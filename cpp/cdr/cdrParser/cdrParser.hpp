/*****************************************************************************
* File Name: CDR Interpreter
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CDR_INTERPRETER_HPP__
#define __CDR_INTERPRETER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string
#include "../cdr/cdr.hpp" // CDR Header
#include "../cdr/usageType.hpp" // Usage Type Header
#include "../taskMaker/taskMaker.hpp" // Task Maker Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager Header

/*-------------------------------- Structure -------------------------------*/

class CDRParser {
public:
    // Enum
    
    enum CDRPart {
        SEQUENCE_NUMBER = 0,
        IMSI,
        IMEI,
        USAGE_TYPE,
        MSISDN,
        CALL_DATE,
        CALL_TIME,
        DURATION,
        BYTES_RECEIVED,
        BYTES_TRANSMITTED,
        SECOND_PARTY_IMSI,
        SECOND_PARTY_MSISDN
    };

    // Constructor

    CDRParser();

    // Destructor

    ~CDRParser() = default;

    // Copy Constructor

    CDRParser(const CDRParser &a_other) = delete;

    // Assignment Operator

    CDRParser &operator=(const CDRParser &a_other) = delete;

    // Methods

    void ParseFileToCDRsAndSendToTaskMaker(const std::string &a_cdr, DataBaseManager *a_dataBaseManager);

private:
    // Constants

    static constexpr char DELIMITER = '|';

    // Methods

    CDR ParserSingleLineToCDR(const std::string &a_currentLine);
    UsageType StringToUsageTypeEnum(const std::string &a_str);

    // Class Members 

    TaskMaker m_taskMaker;
};

#endif /* __CDR_INTERPRETER_HPP__ */

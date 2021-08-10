/*****************************************************************************
* File Name: CDR
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CDR_HPP__
#define __CDR_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string 
#include "usageType.hpp" // Usage Type Header 

/*-------------------------------- Structure -------------------------------*/

struct CDR {
    // Class Members

    unsigned long m_sequenceNumber;
    unsigned long m_IMSI;
    std::string m_IMEI;
    UsageType m_type; 
    std::string m_MSISDN; 
    std::string m_callDate;
    std::string m_callTime;
    unsigned long m_duration;
    unsigned long m_bytesReceived;
    unsigned long m_bytesTransmitted;
    unsigned long m_IMSISecondParty;
    std::string m_MSISDNSecondParty;
};

#endif /* __CDR_HPP__ */

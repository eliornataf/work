/*****************************************************************************
* File Name: Inter Operator Settlement Object
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __INTER_OPERATOR_SETTLEMENT_OBJECT_HPP__
#define __INTER_OPERATOR_SETTLEMENT_OBJECT_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string

/*-------------------------------- Structure -------------------------------*/

class InterOperatorSettlementObject {
public:
    // Constructor

    InterOperatorSettlementObject(const unsigned long &a_IMSI, const unsigned long a_totalOutgoingVoiceCallsDuration, const unsigned long a_totalIncomingVoiceCallsDuration, const unsigned long a_totalOutgoingSMSMessages, const unsigned long a_totalIncomingSMSMessages);

    // Destructor

    ~InterOperatorSettlementObject() = default;

    // Copy Constructor

    InterOperatorSettlementObject(const InterOperatorSettlementObject &a_other) = default;

    // Assignment Operator

    InterOperatorSettlementObject &operator=(const InterOperatorSettlementObject &a_other) = default;

    // Methods

    InterOperatorSettlementObject& operator+=(const InterOperatorSettlementObject &a_other);

    // Get Methods

    unsigned long GetIMSI() const;
    unsigned long GetTotalOutgoingVoiceCallsDuration() const;
    unsigned long GetTotalIncomingVoiceCallsDuration() const;
    unsigned long GetTotalOutgoingSMSMessages() const;
    unsigned long GetTotalIncomingSMSMessages() const;

private:
    // Class Members

    unsigned long m_IMSI; 
    unsigned long m_totalOutgoingVoiceCallsDuration;
    unsigned long m_totalIncomingVoiceCallsDuration;
    unsigned long m_totalOutgoingSMSMessages;
    unsigned long m_totalIncomingSMSMessages;
};

#endif /* __INTER_OPERATOR_SETTLEMENT_OBJECT_HPP__ */

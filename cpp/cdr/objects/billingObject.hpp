/*****************************************************************************
* File Name: Billing Object
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BILLING_OBJECT_HPP__
#define __BILLING_OBJECT_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string

/*-------------------------------- Structure -------------------------------*/

class BillingObject {
public:
    // Constructor

    BillingObject(const unsigned long a_IMSI, const unsigned long a_totalOutgoingVoiceCalls, const unsigned long a_totalIncomingVoiceCalls, const unsigned long a_totalTransferredData, const unsigned long a_totalReceivedData, const unsigned long a_totalSMSSent, const unsigned long a_totalSMSReceived);

    // Destructor

    ~BillingObject() = default;

    // Copy Constructor

    BillingObject(const BillingObject &a_other) = default;

    // Assignment Operator

    BillingObject &operator=(const BillingObject &a_other) = default;

    // Methods

    BillingObject& operator+=(const BillingObject &a_other);

    // Get Methods

    unsigned long GetIMSI() const;
    unsigned long GetTotalOutgoingVoiceCalls() const;
    unsigned long GetTotalIncomingVoiceCalls() const;
    unsigned long GetTotalTransferredData() const;
    unsigned long GetTotalReceivedData() const;
    unsigned long GetTotalSMSSent() const;
    unsigned long GetTotalSMSReceived() const;

private:
    // Class Members

    unsigned long m_IMSI; 
    unsigned long m_totalOutgoingVoiceCalls;
    unsigned long m_totalIncomingVoiceCalls;
    unsigned long m_totalTransferredData;
    unsigned long m_totalReceivedData;
    unsigned long m_totalSMSSent;
    unsigned long m_totalSMSReceived;
};

#endif /* __BILLING_OBJECT_HPP__ */

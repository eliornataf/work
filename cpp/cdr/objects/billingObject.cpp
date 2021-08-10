#include "billingObject.hpp" // Billing Object Header

BillingObject::BillingObject(const unsigned long a_IMSI, const unsigned long a_totalOutgoingVoiceCalls, const unsigned long a_totalIncomingVoiceCalls, const unsigned long a_totalTransferredData, const unsigned long a_totalReceivedData, const unsigned long a_totalSMSSent, const unsigned long a_totalSMSReceived)
: m_IMSI(a_IMSI)
, m_totalOutgoingVoiceCalls(a_totalOutgoingVoiceCalls)
, m_totalIncomingVoiceCalls(a_totalIncomingVoiceCalls)
, m_totalTransferredData(a_totalTransferredData)
, m_totalReceivedData(a_totalReceivedData)
, m_totalSMSSent(a_totalSMSSent)
, m_totalSMSReceived(a_totalSMSReceived) {
}

BillingObject& BillingObject::operator+=(const BillingObject &a_other) {
    this->m_totalIncomingVoiceCalls += a_other.m_totalIncomingVoiceCalls;
    this->m_totalOutgoingVoiceCalls += a_other.m_totalOutgoingVoiceCalls;
    this->m_totalTransferredData += a_other.m_totalTransferredData;
    this->m_totalReceivedData += a_other.m_totalReceivedData;
    this->m_totalSMSSent += a_other.m_totalSMSSent;
    this->m_totalSMSReceived += a_other.m_totalSMSReceived;

    return *this;
}

unsigned long BillingObject::GetIMSI() const {
    return this->m_IMSI;
}

unsigned long BillingObject::GetTotalOutgoingVoiceCalls() const {
    return this->m_totalIncomingVoiceCalls;
}

unsigned long BillingObject::GetTotalIncomingVoiceCalls() const {
    return this->m_totalOutgoingVoiceCalls;
}

unsigned long BillingObject::GetTotalTransferredData() const {
    return this->m_totalTransferredData;
}

unsigned long BillingObject::GetTotalReceivedData() const {
    return this->m_totalReceivedData;
}

unsigned long BillingObject::GetTotalSMSSent() const {
    return this->m_totalSMSSent;
}

unsigned long BillingObject::GetTotalSMSReceived() const {
    return this->m_totalSMSReceived;
}
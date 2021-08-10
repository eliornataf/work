#include "interOperatorSettlementObject.hpp" // Inter Operator Settlement Object

InterOperatorSettlementObject::InterOperatorSettlementObject(const unsigned long &a_IMSI, const unsigned long a_totalOutgoingVoiceCallsDuration, const unsigned long a_totalIncomingVoiceCallsDuration, const unsigned long a_totalOutgoingSMSMessages, const unsigned long a_totalIncomingSMSMessages) 
: m_IMSI(a_IMSI)
, m_totalOutgoingVoiceCallsDuration(a_totalOutgoingVoiceCallsDuration)
, m_totalIncomingVoiceCallsDuration(a_totalIncomingVoiceCallsDuration)
, m_totalOutgoingSMSMessages(a_totalOutgoingSMSMessages)
, m_totalIncomingSMSMessages(a_totalIncomingSMSMessages) {
}

InterOperatorSettlementObject& InterOperatorSettlementObject::operator+=(const InterOperatorSettlementObject &a_other) {
    this->m_totalOutgoingVoiceCallsDuration += a_other.m_totalOutgoingVoiceCallsDuration;
    this->m_totalIncomingVoiceCallsDuration += a_other.m_totalIncomingVoiceCallsDuration;
    this->m_totalOutgoingSMSMessages += a_other.m_totalOutgoingSMSMessages;
    this->m_totalIncomingSMSMessages += a_other.m_totalIncomingSMSMessages;

    return *this;
}

unsigned long InterOperatorSettlementObject::GetIMSI() const {
    return this->m_IMSI;
}

unsigned long InterOperatorSettlementObject::GetTotalOutgoingVoiceCallsDuration() const {
   return this->m_totalOutgoingVoiceCallsDuration;
}

unsigned long InterOperatorSettlementObject::GetTotalIncomingVoiceCallsDuration() const {
    return this->m_totalIncomingVoiceCallsDuration;
}

unsigned long InterOperatorSettlementObject::GetTotalOutgoingSMSMessages() const {
    return this->m_totalOutgoingSMSMessages;
}

unsigned long InterOperatorSettlementObject::GetTotalIncomingSMSMessages() const {
    return this->m_totalIncomingSMSMessages;
}
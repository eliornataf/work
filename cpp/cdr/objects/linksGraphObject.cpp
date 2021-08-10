#include "linksGraphObject.hpp" // Links Graph Object Header

LinksGraphObject::LinksGraphObject(const unsigned long &a_IMSI, const unsigned long a_IMSISecondParty, const unsigned long a_totalVoiceCallsDuration, const unsigned long a_totalSMSExchanged)
: m_IMSI(a_IMSI)
, m_IMSISecondParty(a_IMSISecondParty)
, m_totalVoiceCallsDuration(a_totalVoiceCallsDuration)
, m_totalSMSExchanged(a_totalSMSExchanged) {
}

LinksGraphObject& LinksGraphObject::operator+=(const LinksGraphObject &a_other) {
    this->m_totalVoiceCallsDuration += a_other.m_totalVoiceCallsDuration;
    this->m_totalSMSExchanged += a_other.m_totalSMSExchanged;

    return *this;
}

unsigned long LinksGraphObject::GetIMSI() const {
    return this->m_IMSI;
}

unsigned long LinksGraphObject::GetIMSISecondParty() const {
    return this->m_IMSISecondParty;
}

unsigned long LinksGraphObject::GetTotalVoiceCallsDuration() const {
    return this->m_totalVoiceCallsDuration;
}

unsigned long LinksGraphObject::GetTotalSMSExchanged() const {
    return this->m_totalSMSExchanged;
}
#include "cdrConvertor.hpp" // CDR Convertor Header

CDRConvertor::CDRConvertor(const CDR &a_cdr)
: m_cdr(a_cdr) {
}

BillingObject CDRConvertor::CreateBillingObject() const {
    switch (m_cdr.m_type) {
        case OUTGOING_VOICE_CALL:
            return BillingObject(this->m_cdr.m_IMSI, this->m_cdr.m_duration, 0, 0, 0, 0, 0);

        case INCOMING_VOICE_CALL:
            return BillingObject(this->m_cdr.m_IMSI, 0, this->m_cdr.m_duration, 0, 0, 0, 0);

        case OUTGOING_MESSAGE:
            return BillingObject(this->m_cdr.m_IMSI, 0, 0, 0, 0, 1, 0);

        case INCOMING_MESSAGE:
            return BillingObject(this->m_cdr.m_IMSI, 0, 0, 0, 0, 0, 1);

        case DATA:
            return BillingObject(this->m_cdr.m_IMSI, 0, 0, this->m_cdr.m_bytesTransmitted, m_cdr.m_bytesReceived, 0, 0);

        default:
            return BillingObject(this->m_cdr.m_IMSI, 0, 0, 0, 0, 0, 0);
    }
}

LinksGraphObject CDRConvertor::CreateLinksGraphObject() const {
    switch (m_cdr.m_type) {
        case OUTGOING_VOICE_CALL:
            return LinksGraphObject(this->m_cdr.m_IMSI, this->m_cdr.m_IMSISecondParty, this->m_cdr.m_duration, 0);

        case INCOMING_VOICE_CALL:
            return LinksGraphObject(this->m_cdr.m_IMSI, this->m_cdr.m_IMSISecondParty, this->m_cdr.m_duration, 0);

        case OUTGOING_MESSAGE:
            return LinksGraphObject(this->m_cdr.m_IMSI, this->m_cdr.m_IMSISecondParty, 0, 1);

        case INCOMING_MESSAGE:
            return LinksGraphObject(this->m_cdr.m_IMSI, this->m_cdr.m_IMSISecondParty, 0, 1);

        default:
            return LinksGraphObject(this->m_cdr.m_IMSI, this->m_cdr.m_IMSISecondParty, 0, 0);
    }
}

InterOperatorSettlementObject CDRConvertor::CreateInterOperatorSettlementObject() const {
     switch (m_cdr.m_type) {
        case OUTGOING_VOICE_CALL:
            return InterOperatorSettlementObject(this->m_cdr.m_IMSI, this->m_cdr.m_duration, 0, 0, 0);

        case INCOMING_VOICE_CALL:
            return InterOperatorSettlementObject(this->m_cdr.m_IMSI, 0, this->m_cdr.m_duration, 0, 0);

        case OUTGOING_MESSAGE:
            return InterOperatorSettlementObject(this->m_cdr.m_IMSI, 0, 0, 1, 0);

        case INCOMING_MESSAGE:
            return InterOperatorSettlementObject(this->m_cdr.m_IMSI, 0, 0, 0, 1);

        default:
            return InterOperatorSettlementObject(this->m_cdr.m_IMSI, 0, 0, 0, 0);
    }
}
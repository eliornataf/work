#include <cstring> // strtok
#include <stdexcept> // std::runtime_error
#include <string> // std::getline, std::stoul, std::find
#include <sstream> //std::stringstream
#include "cdrParser.hpp" // CDR Parser Header

/*******************************************************
******************* Public Functions *******************
*******************************************************/

CDRParser::CDRParser() 
: m_taskMaker() {
}

void CDRParser::ParseFileToCDRsAndSendToTaskMaker(const std::string &a_cdr, DataBaseManager *a_dataBaseManager) {
    std::stringstream currentFile(a_cdr);
    std::string currentLine;

    std::getline(currentFile, currentLine, '\n');  // skip header 

    while (std::getline(currentFile, currentLine)) {
        this->m_taskMaker.AddTaskToSafeQueue(ParserSingleLineToCDR(currentLine), a_dataBaseManager);
    }
}

/*******************************************************
******************* Private Functions ******************
*******************************************************/

CDR CDRParser::ParserSingleLineToCDR(const std::string &a_currentLine) {
    std::stringstream currentLineStream(a_currentLine);
    std::string currentPart;
    CDR extractedCDR;

    for (size_t partNumber = 0;partNumber <= SECOND_PARTY_MSISDN;++partNumber) {
        std::getline(currentLineStream, currentPart, DELIMITER);
            
        switch (partNumber) {
            case SEQUENCE_NUMBER: 
                extractedCDR.m_sequenceNumber = std::stoul(currentPart); 
                break;

            case IMSI:
                extractedCDR.m_IMSI = std::stoul(currentPart);
                break;

            case IMEI:
                extractedCDR.m_IMEI = currentPart;
                break;

            case USAGE_TYPE:
                extractedCDR.m_type = this->StringToUsageTypeEnum(currentPart);
                break;

            case MSISDN:
                extractedCDR.m_MSISDN = currentPart;
                break;

            case CALL_DATE:
                extractedCDR.m_callDate = currentPart;
                break;

            case CALL_TIME:
                extractedCDR.m_callTime = currentPart;
                break;

            case DURATION:
                extractedCDR.m_duration = std::stoul(currentPart);
                break;

            case BYTES_RECEIVED:
                extractedCDR.m_bytesReceived = std::stoul(currentPart);
                break;

            case BYTES_TRANSMITTED:
                extractedCDR.m_bytesTransmitted = std::stoul(currentPart);
                break;

            case SECOND_PARTY_IMSI:
                extractedCDR.m_IMSISecondParty = ("" == currentPart) ? 0 : std::stoul(currentPart);
                break;

            case SECOND_PARTY_MSISDN:
                char *token = std::strtok(const_cast<char*>(currentPart.c_str()), "\n");
                extractedCDR.m_MSISDNSecondParty = (nullptr != token) ? std::string(token) : std::string("");
                break;
        }
    }

    return extractedCDR;
}

UsageType CDRParser::StringToUsageTypeEnum(const std::string &a_str) {
    if ("MOC" == a_str) {
        return OUTGOING_VOICE_CALL;
    }
    else if ("MTC" == a_str) {
        return INCOMING_VOICE_CALL;
    }
    else if ("SMS-MO" == a_str) {
        return OUTGOING_MESSAGE;
    }
    else if ("SMS-MT" == a_str) {
        return INCOMING_MESSAGE;
    }
    else if ("D" == a_str) {
        return DATA;
    }
    else if ("U" == a_str) {
        return CALL_NOT_ANSWERED;
    }
    else if ("B" == a_str) {
        return BUSY_CALL;
    }
    else if ("X" == a_str) {
        return FAILED_CALL;
    }
    else {
        throw std::runtime_error("Usage type error");
    }
}

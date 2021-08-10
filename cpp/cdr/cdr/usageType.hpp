/*****************************************************************************
* File Name: Usage Type
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __UsageType_HPP__
#define __UsageType_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string 

/*-------------------------------- Structure -------------------------------*/

enum UsageType {
    OUTGOING_VOICE_CALL = 0,
    INCOMING_VOICE_CALL,
    OUTGOING_MESSAGE,
    INCOMING_MESSAGE,
    DATA,
    CALL_NOT_ANSWERED, 
    BUSY_CALL, 
    FAILED_CALL 
};

#endif /* __UsageType_HPP__ */

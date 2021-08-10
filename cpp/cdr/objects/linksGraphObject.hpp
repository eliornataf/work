/*****************************************************************************
* File Name: Links Graph Object
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LINKS_GRAPH_OBJECT_HPP__
#define __LINKS_GRAPH_OBJECT_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string

/*-------------------------------- Structure -------------------------------*/

class LinksGraphObject {
public:
    // Constructor

    LinksGraphObject(const unsigned long &a_IMSI, const unsigned long a_IMSISecondParty, const unsigned long a_totalVoiceCallsDuration, const unsigned long a_totalSMSExchanged);

    // Destructor

    ~LinksGraphObject() = default;

    // Copy Constructor

    LinksGraphObject(const LinksGraphObject &a_other) = default;

    // Assignment Operator

    LinksGraphObject &operator=(const LinksGraphObject &a_other) = default;

    // Methods

    LinksGraphObject& operator+=(const LinksGraphObject &a_other);

    // Get Methods

    unsigned long GetIMSI() const;
    unsigned long GetIMSISecondParty() const;
    unsigned long GetTotalVoiceCallsDuration() const;
    unsigned long GetTotalSMSExchanged() const;

private:
    // Class Members

    unsigned long m_IMSI; 
    unsigned long m_IMSISecondParty;
    unsigned long m_totalVoiceCallsDuration;
    unsigned long m_totalSMSExchanged;
};

#endif /* __LINKS_GRAPH_OBJECT_HPP__ */

/*****************************************************************************
* File Name: CDR Convertor
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CDR_CONVERTOR_HPP__
#define __CDR_CONVERTOR_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "../cdr/cdr.hpp" // CDR Header
#include "../objects/billingObject.hpp" // Billing Object Header
#include "../objects/linksGraphObject.hpp" // Links Graph Object Header
#include "../objects/interOperatorSettlementObject.hpp" // Inter Operator Settlement Object

/*-------------------------------- Structure -------------------------------*/

class CDRConvertor {
public:
    // Constructor

    CDRConvertor(const CDR &a_cdr);

    // Destructor

    ~CDRConvertor() = default;

    // Copy Constructor

    CDRConvertor(const CDRConvertor &a_other) = default;

    // Assignment Operator

    CDRConvertor &operator=(const CDRConvertor &a_other) = default;

    // Methods

    BillingObject CreateBillingObject() const;
    LinksGraphObject CreateLinksGraphObject() const;
    InterOperatorSettlementObject CreateInterOperatorSettlementObject() const;

private:
    // Class Members

    CDR m_cdr;
};

#endif /* __CDR_CONVERTOR_HPP__ */

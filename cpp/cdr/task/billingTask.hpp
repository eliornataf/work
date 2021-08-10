/*****************************************************************************
* File Name: Billing Task
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BILLING_TASK_HPP__
#define __BILLING_TASK_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "task.hpp" // Task Header
#include "../cdr/cdr.hpp" // CDR Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager

/*-------------------------------- Structure -------------------------------*/

class BillingTask : public Task {
public:
    // Constructor

    BillingTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager);

    // Destructor

    virtual ~BillingTask() = default;

    // Copy Constructor

    BillingTask(const BillingTask &a_other) = delete;

    // Assignment Operator

    BillingTask &operator=(const BillingTask &a_other) = delete;

    // Methods

    virtual void Execute() const override;

private:
    // Class members

    CDR m_cdr;
    DataBaseManager *m_dataBaseManager;
};

#endif /* __BILLING_TASK_HPP__ */

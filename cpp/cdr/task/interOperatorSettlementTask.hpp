/*****************************************************************************
* File Name: Inter Operator Settlement Task
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __INTER_OPERATOR_SETTELEMENT_TASK_HPP__
#define __INTER_OPERATOR_SETTELEMENT_TASK_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "../cdr/cdr.hpp" // CDR Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager
#include "task.hpp" // Task Header

/*-------------------------------- Structure -------------------------------*/

class InterOperatorSettlementTask : public Task {
public:
    // Constructor

    InterOperatorSettlementTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager);

    // Destructor

    virtual ~InterOperatorSettlementTask() = default;

    // Copy Constructor

    InterOperatorSettlementTask(const InterOperatorSettlementTask &a_other) = delete;

    // Assignment Operator

    InterOperatorSettlementTask &operator=(const InterOperatorSettlementTask &a_other) = delete;

    // Methods

    virtual void Execute() const override;

private:
    // Class members

    CDR m_cdr;
    DataBaseManager *m_dataBaseManager;
};

#endif /* __INTER_OPERATOR_SETTELEMENT_TASK_HPP__ */

/*****************************************************************************
* File Name: Links Graph Task
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LINKS_GRAPH_TASK_HPP__
#define __LINKS_GRAPH_TASK_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "task.hpp" // Task Header
#include "../cdr/cdr.hpp" // CDR Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager

/*-------------------------------- Structure -------------------------------*/

class LinksGraphTask : public Task {
public:
    // Constructor

    LinksGraphTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager);

    // Destructor

    virtual ~LinksGraphTask() = default;

    // Copy Constructor

    LinksGraphTask(const LinksGraphTask &a_other) = delete;

    // Assignment Operator

    LinksGraphTask &operator=(const LinksGraphTask &a_other) = delete;

    // Methods

    virtual void Execute() const override;

private:
    // Class members

    CDR m_cdr;
    DataBaseManager *m_dataBaseManager;
};

#endif /* __LINKS_GRAPH_TASK_HPP__ */

/*****************************************************************************
* File Name: Task Maker
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TASK_MAKER_HPP__
#define __TASK_MAKER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string
#include "../cdr/cdr.hpp" // CDR Header
#include "../dataBaseManager/dataBaseManager.hpp" // Data Base Manager Header
#include "../multithreading/threadPool.hpp" // Thread Pool Header

/*-------------------------------- Structure -------------------------------*/

class TaskMaker {
public:
    // Constructor

    TaskMaker();

    // Destructor

    ~TaskMaker() = default;

    // Copy Constructor

    TaskMaker(const TaskMaker &a_other) = default;

    // Assignment Operator

    TaskMaker &operator=(const TaskMaker &a_other) = default;

    // Methods

    void AddTaskToSafeQueue(const CDR &a_cdr, DataBaseManager *a_dataBase);

private:
    // Constants

    static constexpr unsigned NUMBER_OF_THREADS = 10;
    static constexpr unsigned SAFE_QUEUE_CAPACITY = 1000;

    // Class Members

    ThreadPool m_threadPool;
};

#endif /* __TASK_MAKER_HPP__ */

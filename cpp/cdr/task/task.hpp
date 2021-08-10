/*****************************************************************************
* File Name: Task
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TASK_HPP__
#define __TASK_HPP__

/*------------------------------- Header Files ------------------------------*/

/*-------------------------------- Structure -------------------------------*/

class Task {
public:
    // Constructor

    // Task() = default;

    // Destructor

    virtual ~Task() = default;

    // Copy Constructor

    // Task(const Task &a_other) = default;

    // Assignment Operator

    // Task &operator=(const Task &a_other) = default;

    // Methods

    virtual void Execute() const = 0;
};

#endif /* __TASK_HPP__ */

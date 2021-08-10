#include <vector> // std::vector
#include "taskMaker.hpp" // Task Maker Header
#include "../task/task.hpp" // Task Header
#include "../task/billingTask.hpp" // Billing Task Header
#include "../task/interOperatorSettlementTask.hpp" // Inter Operator Settlement Header
#include "../task/linksGraphTask.hpp" // Links Graph Task Header

TaskMaker::TaskMaker() 
: m_threadPool(NUMBER_OF_THREADS, SAFE_QUEUE_CAPACITY) {
}

void TaskMaker::AddTaskToSafeQueue(const CDR &a_cdr, DataBaseManager *a_dataBase) {
    Task *billingTask = new BillingTask(a_cdr, a_dataBase);
    this->m_threadPool.AddTaskToSafeQueue(billingTask);

    Task *interOperatorSettlementTask = new InterOperatorSettlementTask(a_cdr, a_dataBase);
    this->m_threadPool.AddTaskToSafeQueue(interOperatorSettlementTask);

    Task *linksGraphTask = new LinksGraphTask(a_cdr, a_dataBase);
    this->m_threadPool.AddTaskToSafeQueue(linksGraphTask);
}

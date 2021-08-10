#include "threadPool.hpp" // Thread Pool Header

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void* ThreadPoolFunction(void *a_arg) {
    SafeQueue<Task*> *safeQueue = static_cast<SafeQueue<Task*>*>(a_arg);

    while (safeQueue->CheckIfSafeQueueRunning()) { 
        while (!safeQueue->IsEmpty()) {
            Task *currTask = safeQueue->Pop();
            currTask->Execute();
            delete currTask;
        }
    } 

    return nullptr;
}

/*******************************************************
******************* Public Functions *******************
*******************************************************/

ThreadPool::ThreadPool(const unsigned int a_numOfThreads, const unsigned int a_safeQueueCapacity)
: m_threadVector()
, m_safeQueue(new SafeQueue<Task*>(a_safeQueueCapacity)) {
    for (size_t i = 0;i < a_numOfThreads;++i) {
        this->m_threadVector.push_back(Thread(ThreadPoolFunction, this->m_safeQueue));
    }
}

ThreadPool::~ThreadPool() {
    delete this->m_safeQueue;
}

void ThreadPool::AddTaskToSafeQueue(Task *a_task) {
    this->m_safeQueue->Push(a_task);
}

void ThreadPool::StopSafeQueueExecution() {
    while (!this->m_safeQueue->IsEmpty()) {
        for (size_t i = 0;i < this->m_threadVector.size();++i) {
            this->m_threadVector.at(i).Cancel();
        }
    }

    this->m_safeQueue->StopSafeQueue();
}
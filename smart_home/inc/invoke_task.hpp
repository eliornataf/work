#ifndef INVOKE_TASK_HPP
#define INVOKE_TASK_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "event.hpp" // Event Header
#include "router.hpp" // Router Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class InvokeTask : public Runnable {
public:    
    InvokeTask(std::shared_ptr<Router> a_router, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue);
    ~InvokeTask() = default;

    InvokeTask(const InvokeTask &a_other) = delete;
    InvokeTask &operator=(const InvokeTask &a_other) = delete;

    virtual void run() override;

private:
    std::shared_ptr<Router> m_router;
    std::shared_ptr<Event> m_event;
    std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> m_encoderBlockingBoundedQueue;
};

} // advcpp

#endif // INVOKE_TASK_HPP
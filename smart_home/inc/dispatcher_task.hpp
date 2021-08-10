#ifndef DISPATCHER_TASK_HPP
#define DISPATCHER_TASK_HPP

#include <memory> // std::shared_ptr
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "event.hpp" // Event Header
#include "i_subscriber.hpp" // I Subscriber Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class DispatcherTask : public Runnable {
public:
    DispatcherTask(std::shared_ptr<ISubscriber> a_subscriber, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue);
    virtual ~DispatcherTask() = default;

    DispatcherTask(const DispatcherTask &a_other) = delete;
    DispatcherTask &operator=(const DispatcherTask &a_other) = delete;

    virtual void run() override;

private:
    std::shared_ptr<ISubscriber> m_subscriber;
    std::shared_ptr<Event> m_event;
    std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> m_encoderBlockingBoundedQueue;
};

} // advcpp


#endif // DISPATCHER_TASK_HPP
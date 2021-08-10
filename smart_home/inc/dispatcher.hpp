#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include <memory> // std::shared_ptr
#include <set> // std::set
#include "atomic_flag.hpp" // Atomic Flag Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "event.hpp" // Event Header
#include "i_subscriber.hpp" // I Subscriber Header
#include "thread_pool.hpp" // Thread Pool Header

namespace advcpp {

class Dispatcher {
public:
    Dispatcher();
    ~Dispatcher() = default;

    Dispatcher(const Dispatcher &a_other) = delete;
    Dispatcher &operator=(const Dispatcher &a_other) = delete;

    void Dispatch(std::set<std::shared_ptr<ISubscriber>> a_set, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue);

private:
    static constexpr size_t BLOCKING_BOUNDED_QUEUE_SIZE = 100;

private:
    ThreadPool m_threadPool;
};

} // advcpp

#endif // DISPATCHER_HPP
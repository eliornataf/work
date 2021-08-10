#ifndef CONTROLLER_AGENT_HPP
#define CONTROLLER_AGENT_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "agent.hpp" // Agent Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "i_encoder.hpp" // I Encoder Header
#include "i_subscriber.hpp" // I Subscriber Header
#include "socket.hpp" // Socket Header

namespace advcpp {

class ControllerAgent : public Agent, public ISubscriber {
public:
    ControllerAgent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config, std::shared_ptr<IEncoder> a_encoder);
    ~ControllerAgent() = default;

    ControllerAgent(const ControllerAgent &a_other) = default;
    ControllerAgent &operator=(const ControllerAgent &a_other) = default;

    virtual void Notify(std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue) override;

private:
    std::shared_ptr<IEncoder> m_encoder;
};

} // advcpp

#endif // CONTROLLER_AGENT_HPP
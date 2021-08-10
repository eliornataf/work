#ifndef SENSOR_AGENT_HPP
#define SENSOR_AGENT_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "agent.hpp" // Agent Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "i_decoder.hpp" // I Decoder Header
#include "i_publisher.hpp" // I Publisher Header

namespace advcpp {

class SensorAgent : public Agent, public IPublisher {
public:    
    SensorAgent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config, std::shared_ptr<IDecoder> a_decoder);
    ~SensorAgent() = default;

    SensorAgent(const SensorAgent &a_other) = default;
    SensorAgent &operator=(const SensorAgent &a_other) = default;

    virtual void Publish(const std::string &a_event, std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue) override;

private:
    std::shared_ptr<IDecoder> m_decoder;
};

} // advcpp


#endif // SENSOR_AGENT_HPP
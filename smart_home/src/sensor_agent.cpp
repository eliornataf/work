#include <memory> // std::shared_ptr
#include "../inc/sensor_agent.hpp" // Sensor Agent Header

using namespace advcpp;

SensorAgent::SensorAgent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config, std::shared_ptr<IDecoder> a_decoder)
: Agent(a_id, a_type, a_location, a_log, a_config)
, m_decoder(a_decoder)
{
}

void SensorAgent::Publish(const std::string &a_event, std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue)
{
    a_decoderBlockingBoundedQueue->Enqueue(m_decoder->Decode(a_event));
}

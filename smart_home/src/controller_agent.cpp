#include "../inc/controller_agent.hpp" // Controller Agent Header

using namespace advcpp;

ControllerAgent::ControllerAgent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config, std::shared_ptr<IEncoder> a_encoder)
: Agent(a_id, a_type, a_location, a_log, a_config)
, m_encoder(a_encoder)
{
}

void ControllerAgent::Notify(std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue)
{
    a_encoderBlockingBoundedQueue->Enqueue(std::make_pair(m_id, m_encoder->Encode(a_event)));
}
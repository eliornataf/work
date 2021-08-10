#include "../inc/encoder.hpp" // Encoder Header

using namespace advcpp;

std::string Encoder::Encode(const std::shared_ptr<Event> &a_event)
{
    std::string type(a_event->GetType());
    std::string timestamp(a_event->GetTimestamp().GetCompleteDateTime());
    std::string payload(a_event->GetPayload());
    std::string location(a_event->GetLocation().GetCompleteLocation());

    return std::string(type + EVENT_PARTS_DELIMITER + timestamp + EVENT_PARTS_DELIMITER
                        + payload + EVENT_PARTS_DELIMITER + location + EVENT_PARTS_DELIMITER + NEW_LINE);
}

#include <memory> // std::shared_ptr
#include <sstream> //std::stringstream
#include "../inc/decoder.hpp" // Decoder Header

using namespace advcpp;

std::shared_ptr<Event> Decoder::Decode(const std::string &a_event)
{
    std::stringstream currentLineStream(a_event);
    std::string currentPart;

    std::string type;
    Timestamp timestamp(DUMMY);
    std::string payload;
    Location location;

    for (size_t i = 0;i <= LOCATION;++i)
    {
        std::getline(currentLineStream, currentPart, EVENT_PARTS_DELIMITER);

        switch(i)
        {
            case TYPE:
                type = currentPart;
            
            case TIMESTAMP:
                timestamp = ConvetStringToTimeStamp(currentPart);

            case PAYLOAD:
                payload = currentPart;

            case LOCATION:
                location = ConvetStringToLocation(currentPart);
        }
    }
    
    return std::make_shared<Event>(type, timestamp, payload, location);
}

//////////////// Private Methods ////////////////

Timestamp Decoder::ConvetStringToTimeStamp(const std::string &a_string)
{
    std::stringstream currentLineStream(a_string);
    std::string currentPart;

    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;

    for (size_t i = 0;i <= YEAR;++i)
    {   
        std::getline(currentLineStream, currentPart, PARTS_PARAMETERS_DELIMITER);
        
        switch(i)
        {
            case SECOND:
                second = std::atoi(currentPart.c_str());

            case MINUTE:
                minute = std::atoi(currentPart.c_str());

            case HOUR:
                hour = std::atoi(currentPart.c_str());

            case DAY:
                day = std::atoi(currentPart.c_str());
            
            case MONTH:
                month = std::atoi(currentPart.c_str());
            
            case YEAR:
                year = std::atoi(currentPart.c_str());
        }
    }

    return Timestamp(second, minute, hour, day, month, year);
}

Location Decoder::ConvetStringToLocation(const std::string &a_string)
{
    std::stringstream currentLineStream(a_string);
    std::string currentPart;

    unsigned int floor;
    unsigned int room;

    for (size_t i = 0;i <= ROOM;++i)
    {   
        std::getline(currentLineStream, currentPart, PARTS_PARAMETERS_DELIMITER);
        
        switch(i)
        {
            case FLOOR:
                floor = std::atoi(currentPart.c_str());

            case ROOM:
                room = std::atoi(currentPart.c_str());
        }
    }

    return Location(floor, room);
}
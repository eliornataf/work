#include <sstream> //std::stringstream
#include "../inc/protocol.hpp" // Protocol Header

using namespace advcpp;

std::shared_ptr<RequestType> Protocol::GetDataByType(const std::string &a_string)
{
    std::stringstream currentLineStream(a_string);
    std::string currentPart;

    std::getline(currentLineStream, currentPart, PARTS_DELIMITER);

    switch (std::atoi(currentPart.c_str()))
    {
        case CONNECT:
        {
            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            return std::make_shared<RequestType>(ConnectRequest(currentPart));
        }
            
        case DISCONNECT:
        {
            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            return std::make_shared<RequestType>(DisconnectRequest(currentPart));
        }
           
        case EVENT:
        {
            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string id = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string event = currentPart;
            return std::make_shared<RequestType>(EventRequest(id, event));
        }
            
        case SUBSCRIBE:
        {
            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string id = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string type = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string floor = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string room = currentPart;

            return std::make_shared<RequestType>(SubscribeRequest(id, type, floor, room));
        }
            
        case UNSUBSCRIBE:
        {
            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string id = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string type = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string floor = currentPart;

            std::getline(currentLineStream, currentPart, PARTS_DELIMITER);
            std::string room = currentPart;

            return std::make_shared<RequestType>(UnSubscribeRequest(id, type, floor, room));
        }
    }

    return std::make_shared<RequestType>(UnValidRequestType());
}
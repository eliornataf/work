#ifndef PROTOCOL_REQUEST_TYPES_HPP
#define PROTOCOL_REQUEST_TYPES_HPP

#include <string> // std::string

namespace advcpp {

enum Type {
    CONNECT = 0,
    DISCONNECT,
    EVENT,
    SUBSCRIBE,
    UNSUBSCRIBE,
    UN_VALID
};

class RequestType {
public:
    virtual ~RequestType() = default;

    virtual unsigned int GetRequestType() = 0;
    virtual std::string GetID() = 0;
};

class ConnectRequest : public RequestType {
public:    
    ConnectRequest(const std::string &a_id) : m_id(a_id) {}
    ~ConnectRequest() = default;

    ConnectRequest(const ConnectRequest &a_other) = default;
    ConnectRequest &operator=(const ConnectRequest &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

private:
    unsigned int m_RequestType = CONNECT;
    std::string m_id;
};

class DisconnectRequest : public RequestType {
public:    
    DisconnectRequest(const std::string &a_id) : m_id(a_id) {}
    ~DisconnectRequest() = default;

    DisconnectRequest(const DisconnectRequest &a_other) = default;
    DisconnectRequest &operator=(const DisconnectRequest &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

private:
    unsigned int m_RequestType = DISCONNECT;
    std::string m_id;
};

class EventRequest : public RequestType {
public:    
    EventRequest(const std::string &a_id, const std::string &a_event) : m_id(a_id), m_event(a_event) {}
    ~EventRequest() = default;

    EventRequest(const EventRequest &a_other) = default;
    EventRequest &operator=(const EventRequest &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

    std::string GetEvent() const {return m_event;}

private:
    unsigned int m_RequestType = EVENT;
    std::string m_id;
    std::string m_event;
};

class SubscribeRequest : public RequestType {
public:    
    SubscribeRequest(const std::string &a_id, const std::string &a_type, const std::string &a_floor, const std::string &a_room) : m_id(a_id), m_type(a_type), m_floor(a_floor), m_room(a_room) {}
    ~SubscribeRequest() = default;

    SubscribeRequest(const SubscribeRequest &a_other) = default;
    SubscribeRequest &operator=(const SubscribeRequest &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

    std::string GetType() const {return m_type;}
    std::string GetFloor() const {return m_floor;}
    std::string GetRoom() const {return m_room;}

private:
    unsigned int m_RequestType = SUBSCRIBE;
    std::string m_id;
    std::string m_type;
    std::string m_floor;
    std::string m_room;
};

class UnSubscribeRequest : public RequestType {
public:    
    UnSubscribeRequest(const std::string &a_id, const std::string &a_type, const std::string &a_floor, const std::string &a_room) : m_id(a_id), m_type(a_type), m_floor(a_floor), m_room(a_room) {}
    ~UnSubscribeRequest() = default;

    UnSubscribeRequest(const UnSubscribeRequest &a_other) = default;
    UnSubscribeRequest &operator=(const UnSubscribeRequest &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

    std::string GetType() const {return m_type;}
    std::string GetFloor() const {return m_floor;}
    std::string GetRoom() const {return m_room;}

private:
    unsigned int m_RequestType = UNSUBSCRIBE;
    std::string m_id;
    std::string m_type;
    std::string m_floor;
    std::string m_room;
};

class UnValidRequestType : public RequestType {
public:    
    UnValidRequestType() {}
    ~UnValidRequestType() = default;

    UnValidRequestType(const UnValidRequestType &a_other) = default;
    UnValidRequestType &operator=(const UnValidRequestType &a_other) = default;

    virtual unsigned int GetRequestType() override {return m_RequestType;}
    virtual std::string GetID() override {return m_id;}

private:
    unsigned int m_RequestType = UN_VALID;
    std::string m_id = "unValid";
};

} // advcpp

#endif // PROTOCOL_REQUEST_TYPES_HPP
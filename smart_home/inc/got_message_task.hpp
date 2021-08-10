#ifndef GOT_MESSAGE_TASK_HPP
#define GOT_MESSAGE_TASK_HPP

#include <memory> // std:shared_ptr
#include <string> // std::string
#include "runnable.hpp" // Runnable Header
#include "socket.hpp" // Socket Header
#include "protocol_request_handler.hpp" // Protocol Request Hander Header

namespace advcpp {

class GotMessageTask : public Runnable {
public: 
    GotMessageTask(std::shared_ptr<ProtocolRequestHandler> a_protocolRequestHandler, const std::string &a_message, std::shared_ptr<Socket> a_clientSocket);
    ~GotMessageTask() = default;

    GotMessageTask(const GotMessageTask &a_other) = default;
    GotMessageTask &operator=(const GotMessageTask &a_other) = default;

    virtual void run() override;

private:
    std::shared_ptr<ProtocolRequestHandler> m_protocolRequestHandler;
    std::string m_message;
    std::shared_ptr<Socket> m_clientSocket;
};

} // advcpp




#endif // GOT_MESSAGE_TASK_HPP
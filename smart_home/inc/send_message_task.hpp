#ifndef SEND_MESSAGE_TASK_HPP
#define SEND_MESSAGE_TASK_HPP

#include <string> // std::string
#include "runnable.hpp" // Runnable Header
#include "socket_manager.hpp" // Socket Manager Header

namespace advcpp {

class SendMessageTask : public Runnable {
public:
    SendMessageTask(std::shared_ptr<SocketManager> a_socketManager, const std::string &a_agentID, const std::string &a_event);
    ~SendMessageTask();

    SendMessageTask(const SendMessageTask &a_other) = delete;
    SendMessageTask &operator=(const SendMessageTask &a_other) = delete;

    virtual void run() override;

private:
    std::shared_ptr<SocketManager> m_socketManager;
    std::string m_agentID;
    std::string m_event;
};

} // advcpp


#endif // SEND_MESSAGE_TASK_HPP
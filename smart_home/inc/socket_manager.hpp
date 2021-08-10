#ifndef SOCKET_MANAGER_HPP
#define SOCKET_MANAGER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include <optional> // std::optional
#include <unordered_map> // std::unordered_map
#include "socket.hpp" // Socket Header

namespace advcpp {

class SocketManager {
public:    
    SocketManager() = default;
    ~SocketManager() = default;

    SocketManager(const SocketManager &a_other) = default;
    SocketManager &operator=(const SocketManager &a_other) = default;

    void Add(const std::string &a_id, std::shared_ptr<Socket> a_socket);
    void Remove(const std::string &a_id);
    std::shared_ptr<Socket> Find(const std::string &a_id);

private:
    std::unordered_map<std::string, std::shared_ptr<Socket>> m_socketMap;
};

} // advcpp


#endif // SOCKET_MANAGER_HPP
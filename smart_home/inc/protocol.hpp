#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "protocol_request_types.hpp" // Protocol Request Types Header

namespace advcpp {

class Protocol {
public:
    Protocol() = default;
    ~Protocol() = default;

    Protocol(const Protocol &a_other) = default;
    Protocol &operator=(const Protocol &a_other) = default;

    std::shared_ptr<RequestType> GetDataByType(const std::string &a_string);

private:
    static constexpr char PARTS_DELIMITER = '&';
};

} // advcpp

#endif // PROTOCAL_HPP
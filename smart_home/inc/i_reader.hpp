#ifndef I_READER_HPP
#define I_READER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include <vector> // std::vector
#include "agent.hpp" // Agent Header

namespace advcpp {

class IReader {
public:
    virtual ~IReader() = default;

    virtual std::vector<std::shared_ptr<Agent>> Read(const std::string &a_file) = 0;
};

}

#endif // I_INITIALIZER_HPP
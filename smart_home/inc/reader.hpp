#ifndef READER_HPP
#define READER_HPP

#include <memory> // std::shared_ptr
#include "agent_manager.hpp" // Agent Manager Header
#include "i_reader.hpp" // I Reader Header
#include "so_loader.hpp" // SO Loader Header
#include "so_path.hpp" // SO Path Header

namespace advcpp {

class Reader : public IReader {
public:
    Reader() = default;
    ~Reader() = default;

    Reader(const Reader &a_other) = default;
    Reader &operator=(const Reader &a_other) = default;

    virtual std::vector<std::shared_ptr<Agent>> Read(const std::string &a_file) override;

private:
    typedef std::shared_ptr<Agent> (*CreateAgent)(const std::string &a_id, const std::string &a_type,
                     const Location &a_location, const std::string &a_log, const std::string &a_config);

    enum InitializeFileLine
    {
        ID = 0,
        TYPE,
        ROOM,
        FLOOR,
        LOG,
        CONFIG,
        NEW_LINE,
        NUMBER_OF_LINES
    };

    static constexpr size_t DO_ANOTHER_AGENT = 0;
};

} // advcpp

#endif // READER_HPP
#ifndef SO_PATH
#define SO_PATH

#include <string> // std::string

namespace advcpp {

class SOPath {
public:
    explicit SOPath(const std::string &a_agentID); 
    ~SOPath() = default;

    SOPath(const SOPath &a_other) = default;
    SOPath &operator=(const SOPath &a_other) = default;

    std::string GetName() const;

private:
    std::string m_agentID;
};

} // advcpp


#endif // SO_PATH
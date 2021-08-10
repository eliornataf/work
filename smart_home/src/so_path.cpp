#include <sstream> // std::stringstream

#include "../inc/so_path.hpp" // SO Path Header

using namespace advcpp;

SOPath::SOPath(const std::string &a_agentID)
: m_agentID(a_agentID)
{ 
}

std::string SOPath::GetName() const
{
    std::stringstream path;
    path << "../so/lib" << m_agentID << ".so";
    return path.str();
}
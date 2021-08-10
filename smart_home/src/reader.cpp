#include <fstream> // std::ifstream
#include "../inc/reader.hpp" // Reader Header
#include "../inc/location.hpp" // Location Header

using namespace advcpp;

std::vector<std::shared_ptr<Agent>> Reader::Read(const std::string &a_file)
{
    std::ifstream configFile(a_file);

    std::vector<std::shared_ptr<Agent>> agentsVector;

    size_t i = 0;
    std::string currentLine, m_id, m_type, m_room, m_floor, m_log, m_config;

    while (std::getline(configFile, currentLine))
    {
        for (;i < NUMBER_OF_LINES;++i)
        {
            switch(i)
            {
                case ID:
                    m_id = currentLine.substr(2, currentLine.size() - 2);
                
                case TYPE:
                    m_type = currentLine.substr(7, currentLine.size());

                case ROOM:
                    m_room = currentLine.substr(7, 7);

                case FLOOR:
                    m_floor = currentLine.substr(8, 8);

                case LOG:
                    m_log = currentLine.substr(6, currentLine.size());;

                case CONFIG:
                    if (0 != currentLine.size())
                    {
                        m_config = currentLine.substr(9, currentLine.size());
                    }
                    else 
                    {
                        std::getline(configFile, currentLine);
                        break;
                    }
                
                case NEW_LINE:
                    ; // do nothing
            }

            std::getline(configFile, currentLine);
        }

        std::string soPath = SOPath(m_id).GetName();
        CreateAgent makeAgent = reinterpret_cast<CreateAgent>(SOLoader(soPath).GetFunction("MakeAgent"));
        std::shared_ptr<Agent> newAgent = (*makeAgent)(m_id, m_type, 
            Location(std::stoul(m_floor), std::stoul(m_room)), m_log, m_config);

        agentsVector.push_back(newAgent);

        i = DO_ANOTHER_AGENT;
    }

    return agentsVector;
}
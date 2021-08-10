#include <dirent.h> // opendir
#include <fstream> // std::ifstream
#include <sstream> //std::stringstream
#include <string.h> // strcmp
#include <stdexcept> // std::runtime_error
#include <string> // std::getline, std::stoul, std::find
#include "cdrHarvester.hpp" // CDR Harvester
#include "../network/socket.hpp" // Socket Header

CDRHarvester::CDRHarvester(const std::string &a_processorIpAdress, const unsigned int a_processorPortNumber)
: m_processorIpAdress(a_processorIpAdress)
, m_processorPortNumber(a_processorPortNumber)
, m_isHarvesterRunning(true) {
}

/*******************************************************
******************* Public Functions *******************
*******************************************************/

void CDRHarvester::RunHarvester() {
    while (m_isHarvesterRunning) {
        this->ReadCDRFromCDRDirectoryAndSendToProcessor();
    }
}

void CDRHarvester::StopHarvester() {
    this->m_isHarvesterRunning = false;
}

/*******************************************************
******************* Private Functions *******************
*******************************************************/

void CDRHarvester::ReadCDRFromCDRDirectoryAndSendToProcessor() {
    DIR *cdrDirectory = opendir("cdrDirectory");
    if (!cdrDirectory) {
        throw std::runtime_error("opendir failed"); 
    }

    struct dirent *entry = nullptr;
    
    while ((entry = readdir(cdrDirectory))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") ) {
            continue;
        }

        Socket socket(this->m_processorIpAdress, this->m_processorPortNumber);

        std::string filePath = std::string("cdrDirectory") + "/" + entry->d_name;
        std::ifstream currFile(filePath, std::ios::binary);
        std::streampos currFileSize = GetFileSize(filePath);

        char *cdrFileBuffer = new char[currFileSize];
        currFile.read(cdrFileBuffer, currFileSize);

        socket.Connect();
        socket.Send(cdrFileBuffer, currFileSize);

        delete[] cdrFileBuffer;
        
        std::remove(filePath.c_str());
    }

    closedir(cdrDirectory);
}

std::streampos CDRHarvester::GetFileSize(const std::string &a_filePath) {
    std::ifstream currentFile(a_filePath, std::ios::binary);

    std::streampos fileBegin = currentFile.tellg();
    currentFile.seekg(0, std::ios::end);
    std::streampos fileEnd = currentFile.tellg();

    currentFile.close();

    return fileEnd - fileBegin;
}

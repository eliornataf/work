#include <dirent.h> // opendir
#include <fstream> // std::ifstream, std::ofstream
#include <stdexcept> // std::runtime_error
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include "processor.hpp" // Processor Header
#include "../network/socket.hpp" // Socket Header
#include "../network/listeningSocket.hpp" // Listening Socket Header
#include "../multithreading/thread.hpp" // Thread Header

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void *HarvesterListeningThreadFunction(void* a_arg) {
    ListeningSocket harvesterListeningSocket(Processor::HARVESTER_PORT_NUMBER);

    while (true) {
        if (harvesterListeningSocket.Accept()) {
            char *buffer = harvesterListeningSocket.Receive(Processor::BUFFER_SIZE);
            std::ofstream newCdrFile(std::string("cdrFiles/new/cdrFileNumber") + std::to_string(*static_cast<unsigned int*>(a_arg)) + ".txt");
            ++(*static_cast<unsigned int*>(a_arg));
            newCdrFile << buffer;
            delete[] buffer;
        }
    }

    return nullptr;
}

/*******************************************************
******************* Public Functions *******************
*******************************************************/

Processor::Processor()
: m_cdrParser()
, m_dataBaseManager(new DataBaseManager())
, m_cdrFileNumber(new unsigned int{0})
, m_isProcessorRunning(true) {
    this->RunHarvesterListeningThread();
}

Processor::~Processor() {
    delete this->m_cdrFileNumber;
    delete this->m_dataBaseManager;
}

void Processor::RunProcessor() {
    while (this->m_isProcessorRunning) {
        // sleep(TEN_MINUTES);

        DIR *processorCDRDirectory = opendir("cdrFiles/new");
        if (!processorCDRDirectory) {
            throw std::runtime_error("opendir failed"); 
        }

        struct dirent *entry = nullptr;
        
        while ((entry = readdir(processorCDRDirectory))) {
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") ) {
                continue;
            }

            std::string filePath = std::string("cdrFiles/new") + "/" + entry->d_name;
            std::ifstream currFile(filePath, std::ios::binary);
            std::streampos currFileSize = GetFileSize(filePath);

            char *cdrFileBuffer = new char[currFileSize];
            currFile.read(cdrFileBuffer, currFileSize);
            std::string cdrFileBufferConverted(cdrFileBuffer);
            
            this->m_cdrParser.ParseFileToCDRsAndSendToTaskMaker(cdrFileBufferConverted, this->m_dataBaseManager);

            delete[] cdrFileBuffer;

            std::ofstream doneFile(std::string("cdrFiles/done/") + entry->d_name);
            doneFile << currFile.rdbuf();
            std::remove(filePath.c_str());
        }

        closedir(processorCDRDirectory);
    }
}

void Processor::StopProcessor() {
    this->m_isProcessorRunning = false;
}

/*******************************************************
******************* Private Functions *******************
*******************************************************/

void Processor::RunHarvesterListeningThread() {
    Thread harvesterListeningThread(&HarvesterListeningThreadFunction,this->m_cdrFileNumber);
    harvesterListeningThread.Detach();
}

std::streampos Processor::GetFileSize(const std::string &a_filePath) {
    std::ifstream currentFile(a_filePath, std::ios::binary);

    std::streampos fileBegin = currentFile.tellg();
    currentFile.seekg(0, std::ios::end);
    std::streampos fileEnd = currentFile.tellg();

    currentFile.close();

    return fileEnd - fileBegin;
}
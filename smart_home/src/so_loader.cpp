#include <dlfcn.h> // dlopen, dlsym, dlclose
#include <stdexcept> // std::runtime_error

#include "../inc/so_loader.hpp"

using namespace advcpp;

SOLoader::SOLoader(const std::string &a_file)
: m_handle(dlopen(a_file.c_str(), RTLD_LAZY))
{
    if (!m_handle)
    {
        throw std::runtime_error("dlopen failed");
    }
}

SOLoader::~SOLoader()
{
    dlclose(m_handle);
}

void *SOLoader::GetFunction(const std::string &a_function) const
{
    return dlsym(m_handle, a_function.c_str());
}

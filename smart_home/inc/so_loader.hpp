#ifndef SO_LOADER_HPP
#define SO_LOADER_HPP

#include <dlfcn.h> // dlopen, dlsym, dlclose
#include <string> // std::string

namespace advcpp {

class SOLoader {
public:
    explicit SOLoader(const std::string &a_file);    
    ~SOLoader();  

    SOLoader(const SOLoader &a_other) = default;
    SOLoader &operator=(const SOLoader &a_other) = default;

    void *GetFunction(const std::string &a_function) const;

private:    
    void *m_handle;
};

} // advcpp

#endif // SO_LOADER_HPP
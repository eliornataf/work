#ifndef RUNNABLE_HPP
#define RUNNABLE_HPP

namespace advcpp {

class Runnable {
public:
    virtual ~Runnable() = default;
    
    virtual void run() = 0;
};

} // advcpp

#endif // RUNNABLE_HPP

#ifndef RUNNABLE_ADAPTERS_HPP
#define RUNNABLE_ADAPTERS_HPP

#include <cstddef> // size_t
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class GlobalFunctionAdapaterWithoutReturnValue : public Runnable {
public:
    GlobalFunctionAdapaterWithoutReturnValue(void(*a_function)()) : m_function(a_function) {};
    virtual ~GlobalFunctionAdapaterWithoutReturnValue() = default;

    GlobalFunctionAdapaterWithoutReturnValue(const GlobalFunctionAdapaterWithoutReturnValue &a_other) = default;
    GlobalFunctionAdapaterWithoutReturnValue &operator=(const GlobalFunctionAdapaterWithoutReturnValue &a_other) = default;

    virtual void run() override {m_function();}

private:
    void(*m_function)();
};

template <typename ReturnValue>
class GlobalFunctionAdapaterWithReturnValue : public Runnable {
public:
    GlobalFunctionAdapaterWithReturnValue(ReturnValue(*a_function)()) : m_function(a_function), m_returnValue() {};
    virtual ~GlobalFunctionAdapaterWithReturnValue() = default;

    GlobalFunctionAdapaterWithReturnValue(const GlobalFunctionAdapaterWithReturnValue &a_other) = default;
    GlobalFunctionAdapaterWithReturnValue &operator=(const GlobalFunctionAdapaterWithReturnValue &a_other) = default;

    virtual void run() override {m_returnValue = m_function();}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    ReturnValue(*m_function)();
    ReturnValue m_returnValue;
};

template <typename ReturnValue, typename Arg>
class GlobalFunctionAdapaterWithReturnValueAndOneArg : public Runnable {
public:
    GlobalFunctionAdapaterWithReturnValueAndOneArg(ReturnValue(*a_function)(Arg), const Arg &a_argument) : m_function(a_function), m_returnValue(), m_argument(a_argument) {};
    virtual ~GlobalFunctionAdapaterWithReturnValueAndOneArg() = default;

    GlobalFunctionAdapaterWithReturnValueAndOneArg(const GlobalFunctionAdapaterWithReturnValueAndOneArg &a_other) = default;
    GlobalFunctionAdapaterWithReturnValueAndOneArg &operator=(const GlobalFunctionAdapaterWithReturnValueAndOneArg &a_other) = default;

    virtual void run() override {m_returnValue = m_function(m_argument);}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    ReturnValue(*m_function)(Arg);
    ReturnValue m_returnValue;
    Arg m_argument;
};

template <typename ReturnValue, typename Arg1, typename Arg2>
class GlobalFunctionAdapaterWithReturnValueAndTwoArg : public Runnable {
public:
    GlobalFunctionAdapaterWithReturnValueAndTwoArg(ReturnValue(*a_function)(Arg1, Arg2), const Arg1 &a_argument1, const Arg2 &a_argment2) : m_function(a_function), m_returnValue(), m_argument1(a_argument1), m_argument2(a_argment2) {};
    virtual ~GlobalFunctionAdapaterWithReturnValueAndTwoArg() = default;

    GlobalFunctionAdapaterWithReturnValueAndTwoArg(const GlobalFunctionAdapaterWithReturnValueAndTwoArg &a_other) = default;
    GlobalFunctionAdapaterWithReturnValueAndTwoArg &operator=(const GlobalFunctionAdapaterWithReturnValueAndTwoArg &a_other) = default;

    virtual void run() override {m_returnValue = m_function(m_argument1, m_argument2);}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    ReturnValue(*m_function)(Arg1, Arg2);
    ReturnValue m_returnValue;
    Arg1 m_argument1;
    Arg2 m_argument2;
};

template <typename Class>
class MemberFunctionAdapaterWithoutReturnValue : public Runnable {
public:
    MemberFunctionAdapaterWithoutReturnValue(Class &a_class, void(Class::* a_function)()) : m_class(&a_class), m_function(a_function) {};
    virtual ~MemberFunctionAdapaterWithoutReturnValue() = default;

    MemberFunctionAdapaterWithoutReturnValue(const MemberFunctionAdapaterWithoutReturnValue &a_other) = default;
    MemberFunctionAdapaterWithoutReturnValue &operator=(const MemberFunctionAdapaterWithoutReturnValue &a_other) = default;

    virtual void run() override {(m_class->*m_function)();}

private:
    Class *m_class;
    void(Class::* m_function)();
};

template <typename Class, typename ReturnValue>
class MemberFunctionAdapaterWithReturnValue : public Runnable {
public:
    MemberFunctionAdapaterWithReturnValue(Class &a_class, ReturnValue(Class::* a_function)()) : m_class(&a_class), m_function(a_function), m_returnValue() {};
    virtual ~MemberFunctionAdapaterWithReturnValue() = default;

    MemberFunctionAdapaterWithReturnValue(const MemberFunctionAdapaterWithReturnValue &a_other) = default;
    MemberFunctionAdapaterWithReturnValue &operator=(const MemberFunctionAdapaterWithReturnValue &a_other) = default;

    virtual void run() override {m_returnValue = (m_class->*m_function)();}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    Class *m_class;
    ReturnValue(Class::* m_function)();
    ReturnValue m_returnValue;
};

template <typename Class, typename ReturnValue, typename Arg>
class MemberFunctionAdapaterWithReturnValueAndOneArg : public Runnable {
public:
    MemberFunctionAdapaterWithReturnValueAndOneArg(Class &a_class, ReturnValue(Class::* a_function)(Arg), const Arg &a_argument) : m_class(&a_class), m_function(a_function), m_returnValue(), m_argument(a_argument) {};
    virtual ~MemberFunctionAdapaterWithReturnValueAndOneArg() = default;

    MemberFunctionAdapaterWithReturnValueAndOneArg(const MemberFunctionAdapaterWithReturnValueAndOneArg &a_other) = default;
    MemberFunctionAdapaterWithReturnValueAndOneArg &operator=(const MemberFunctionAdapaterWithReturnValueAndOneArg &a_other) = default;

    virtual void run() override {m_returnValue = (m_class->*m_function)(m_argument);}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    Class *m_class;
    ReturnValue(Class::* m_function)(Arg);
    ReturnValue m_returnValue;
    Arg m_argument;
};

template <typename Class, typename ReturnValue, typename Arg1, typename Arg2>
class MemberFunctionAdapaterWithReturnValueAndTwoArg : public Runnable {
public:
    MemberFunctionAdapaterWithReturnValueAndTwoArg(Class &a_class, ReturnValue(Class::* a_function)(Arg1, Arg2), const Arg1 &a_argument1, const Arg2 &a_argument2) : m_class(&a_class), m_function(a_function), m_returnValue(), m_argument1(a_argument1), m_argument2(a_argument2) {};
    virtual ~MemberFunctionAdapaterWithReturnValueAndTwoArg() = default;

    MemberFunctionAdapaterWithReturnValueAndTwoArg(const MemberFunctionAdapaterWithReturnValueAndTwoArg &a_other) = default;
    MemberFunctionAdapaterWithReturnValueAndTwoArg &operator=(const MemberFunctionAdapaterWithReturnValueAndTwoArg &a_other) = default;

    virtual void run() override {m_returnValue = (m_class->*m_function)(m_argument1, m_argument2);}

    ReturnValue GetReturnValue() const {return m_returnValue;}

private:
    Class *m_class;
    ReturnValue(Class::* m_function)(Arg1, Arg2);
    ReturnValue m_returnValue;
    Arg1 m_argument1;
    Arg2 m_argument2;
};

template <typename Class>
class MemberFunctionAdapaterWithNumberOfIterations : public Runnable {
public:
    MemberFunctionAdapaterWithNumberOfIterations(Class &a_class, void(Class::* a_function)(), const size_t a_numberOfIterations) : m_class(&a_class), m_function(a_function), m_numberOfIterations(a_numberOfIterations) {};
    virtual ~MemberFunctionAdapaterWithNumberOfIterations() = default;

    MemberFunctionAdapaterWithNumberOfIterations(const MemberFunctionAdapaterWithNumberOfIterations &a_other) = default;
    MemberFunctionAdapaterWithNumberOfIterations &operator=(const MemberFunctionAdapaterWithNumberOfIterations &a_other) = default;

    virtual void run() override {for (size_t i = 0;i < m_numberOfIterations;++i) { (m_class->*m_function)();}}

private:
    Class *m_class;
    void(Class::* m_function)();
    size_t m_numberOfIterations;
};

} // advcpp

#endif // RUNNABLE_ADAPTERS_HPP

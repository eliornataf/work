#ifndef THREAD_GROUP_HXX
#define THREAD_GROUP_HXX

template <typename Policy> 
ThreadGroup<Policy>::ThreadGroup(std::shared_ptr<Runnable> a_runnable, const size_t a_numberOfThreads, const Policy &a_userPolicy)
: m_threadList()
, m_runnable(a_runnable)
, m_userPolicy(a_userPolicy)
{
    AddThreads(a_numberOfThreads);
}

template <typename Policy> 
void ThreadGroup<Policy>::Join() 
{   
    std::for_each(m_threadList.begin(), m_threadList.end(), [](std::shared_ptr<Thread<Policy>> a_thread)
    {
        try 
        {
            a_thread->Join();
        } 
        catch (const std::exception &ex) 
        {
            // do nothing
        }
    });
}

template <typename Policy> 
void ThreadGroup<Policy>::Detach() 
{   
    std::for_each(m_threadList.begin(), m_threadList.end(), [](std::shared_ptr<Thread<Policy>> a_thread)
    {
        try 
        {
            a_thread->Detach();
        } 
        catch (const std::exception &ex) 
        {
            // do nothing
        }
    });
}

template <typename Policy> 
void ThreadGroup<Policy>::Cancel(const bool a_isWaitingAfterCancelNecessary) 
{   
    std::for_each(m_threadList.begin(), m_threadList.end(), [a_isWaitingAfterCancelNecessary](std::shared_ptr<Thread<Policy>> a_thread)
    {
        try 
        {
            a_thread->Cancel(a_isWaitingAfterCancelNecessary);
        } 
        catch (const std::exception &ex) 
        {
            // do nothing
        }
    });
}

template <typename Policy> 
void ThreadGroup<Policy>::Add(const size_t a_numberOfThreads)
{
    RemoveDoneThreads();
    AddThreads(a_numberOfThreads);
}
template <typename Policy> 
size_t ThreadGroup<Policy>::Remove(const size_t a_numberOfThreads)
{
    size_t numberOfRemovedThreads = RemoveDoneThreads();
    size_t listSize = m_threadList.size();

    for (size_t i = 0;i < listSize && numberOfRemovedThreads < a_numberOfThreads;++i, ++numberOfRemovedThreads) 
    {
        try 
        {
            m_threadList.back()->Cancel();
        } 
        catch (const std::exception &ex) 
        {
            // do nothing
        }

        m_threadList.pop_back();
    }

    return numberOfRemovedThreads;
}

/// Private Methods /////

template <typename Policy> 
void ThreadGroup<Policy>::AddThreads(const size_t a_numberOfThreads) 
{
    for (size_t i = 0;i < a_numberOfThreads;++i) 
    {
        m_threadList.emplace_back(std::shared_ptr<Thread<Policy>>(new Thread<Policy>(m_runnable, m_userPolicy)));
    }
}

template <typename Policy> 
size_t ThreadGroup<Policy>::RemoveDoneThreads()
{
    size_t numberOfRemovedThreads = 0;

    for (auto beginIter = m_threadList.begin(), endIter = m_threadList.end();beginIter != endIter;) 
    {
        if (!(*beginIter)->IsThreadAlive()) 
        {
            beginIter = m_threadList.erase(beginIter);
            ++numberOfRemovedThreads;
        }
        else
        {
            ++beginIter;
        }
    }

    return numberOfRemovedThreads;
}

template <typename Policy> 
size_t ThreadGroup<Policy>::NumberOfThreads() const 
{
    return m_threadList.size();
}

#endif // THREAD_GROUP_HXX

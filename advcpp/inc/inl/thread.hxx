#ifndef THREAD_HXX
#define THREAD_HXX

template <typename Policy> 
void *Thread<Policy>::ThreadFunction(void *a_arg)
{
    Thread *thread = static_cast<Thread*>(a_arg);

    std::shared_ptr<Runnable> runnableCopy = thread->m_runnable;
    std::shared_ptr<SyncPoint> syncPointCopy = thread->m_syncPoint;

    thread->m_barrier.Wait();

    try
    {
        runnableCopy->run();
    }
    catch (const abi::__forced_unwind &ex)
    {
        throw;
    }
    catch (...)
    {
        // do noting
    }
    
    syncPointCopy->Off();

    return nullptr;
}

template <typename Policy> 
Thread<Policy>::Thread(std::shared_ptr<Runnable> a_runnable, const Policy &a_userPolicy)
: m_thread()
, m_userPolicy(a_userPolicy)
, m_isJoinableOrDetachableOrCancelable()
, m_barrier()
, m_runnable(a_runnable)
, m_syncPoint(new SyncPoint())
{
    assert(a_runnable);

    m_barrier.Init(NUMBER_OF_THREADS_WHICH_WILL_PARTICIPATE_THE_BARRIER);

    if (PTHREAD_SUCCESS != pthread_create(&this->m_thread, NULL, ThreadFunction, this))
    {
        throw std::runtime_error("thread create failed");
    }

    m_barrier.Wait();

    m_isJoinableOrDetachableOrCancelable.Set();
}

template <typename Policy> 
Thread<Policy>::~Thread() 
{
    if (m_isJoinableOrDetachableOrCancelable.Get())
    {
        m_userPolicy.OnDestruction(*this);
    }
}

template <typename Policy> 
void Thread<Policy>::Join() 
{
    if (m_isJoinableOrDetachableOrCancelable.Get()) 
    {
        if (PTHREAD_SUCCESS != pthread_join(this->m_thread, nullptr)) 
        {
            throw std::runtime_error("Thread join failed");
        }

        m_isJoinableOrDetachableOrCancelable.Clear();
    }
}

template <typename Policy> 
void Thread<Policy>::Detach() 
{
    if (m_isJoinableOrDetachableOrCancelable.Get()) 
    {
        if (PTHREAD_SUCCESS != pthread_detach(this->m_thread)) 
        {
            throw std::runtime_error("thread detach failed");
        }

        m_isJoinableOrDetachableOrCancelable.Clear();
    }
}

template <typename Policy> 
void Thread<Policy>::Cancel(const bool a_isWaitingAfterCancelNecessary)
{
    if (PTHREAD_SUCCESS != pthread_cancel(this->m_thread)) 
    {
        throw std::runtime_error("thread cancel failed");
    }

    if (a_isWaitingAfterCancelNecessary) 
    {
        Join();
    }

    m_isJoinableOrDetachableOrCancelable.Clear();
}

template <typename Policy> 
bool Thread<Policy>::IsThreadAlive()
{
    return m_syncPoint->Get();
}

#endif // THREAD_HXX

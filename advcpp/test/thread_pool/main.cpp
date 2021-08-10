#include "mu_test.h" // MU Test Header
#include <memory> // std::shared_ptr
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "task_counter_decrement.hpp" // Task Counter Decrement Header
#include "task_counter_increment.hpp" // Task Counter Increment Header
#include "thread_group.hpp" // Thread Group Header
#include "thread_pool.hpp" // Thread Pool Header

#define BLOCKING_BOUNDED_QUEUE (1) // 2
#define NUMBER_OF_THREADS (1) // 8
#define NUMBER_OF_SUBMIT (80) // 1000
#define NUMBER_OF_ITERATIONS (100000) // 100000

using namespace advcpp;

BEGIN_TEST(QueueCapacityIsZero)
    try
    {
        ThreadPool threadPool(0, NUMBER_OF_THREADS);
    }
    catch(...)
    {
        // do nothing
    }

    ASSERT_PASS(); 
END_TEST

BEGIN_TEST(SubmitAndShutDownTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    threadPool.ShutDown();
        
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndShutDownDefaultNumberOfThreads)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    threadPool.ShutDown();
        
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndAddAndShutDownTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    threadPool.AddThreads(NUMBER_OF_THREADS);

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.ShutDown();
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAfterShutDownTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.ShutDown();

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndAddAfterShutDownTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.ShutDown();

    threadPool.AddThreads(NUMBER_OF_THREADS);
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == counter.GetCount()); 
END_TEST

Counter g_counter;
BEGIN_TEST(SubmitWithoutShutDownTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(g_counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    ASSERT_PASS();
END_TEST

BEGIN_TEST(SubmitWithoutShutDownContinueTest)
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT == g_counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndAndShutDownQueueIsEmptyTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    threadPool.AddThreads(NUMBER_OF_THREADS);

    threadPool.ShutDown();
    
    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndAddAndShutDownImmediatelyTest)
    ThreadPool threadPool(5000, 0);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < 5000;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.AddThreads(NUMBER_OF_THREADS);

    threadPool.ShutDownImmediately();
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT != counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndShutDownImmediatelyQueueIsEmptyTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, 1);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    threadPool.ShutDownImmediately();
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT != counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndAddAfterShutDownImmediatelyTest)
    ThreadPool threadPool(5000, 0);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < 5000;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.AddThreads(NUMBER_OF_THREADS);

    threadPool.ShutDownImmediately();

    threadPool.AddThreads(NUMBER_OF_THREADS);
    
    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT != counter.GetCount()); 
END_TEST

BEGIN_TEST(AddAndSubmitAfterShutDownImmediatelyTest)
    ThreadPool threadPool(5000, 0);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < 5000;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.AddThreads(NUMBER_OF_THREADS);

    threadPool.ShutDownImmediately();

    for (size_t i = 0;i < 5000;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    ASSERT_THAT(NUMBER_OF_ITERATIONS * NUMBER_OF_SUBMIT != counter.GetCount()); 
END_TEST

BEGIN_TEST(SubmitAndRemoveTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    threadPool.RemoveThreads(NUMBER_OF_THREADS);
        
    ASSERT_PASS(); 
END_TEST

BEGIN_TEST(SubmitAndRemoveMoreThreadThanNumberOfThreadsTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    threadPool.RemoveThreads(NUMBER_OF_THREADS * 10);
        
    ASSERT_PASS(); 
END_TEST

BEGIN_TEST(SubmitAndRemoveLessThreadThanNumberOfThreadsTest)
    ThreadPool threadPool(BLOCKING_BOUNDED_QUEUE, NUMBER_OF_THREADS);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < NUMBER_OF_SUBMIT;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }
    
    threadPool.RemoveThreads(0);
        
    ASSERT_PASS(); 
END_TEST

BEGIN_TEST(SubmitAndRemoveLessThreadThanNumberOfThreadsTest2)
    ThreadPool threadPool(2, 0);

    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, NUMBER_OF_ITERATIONS));

    for (size_t i = 0;i < 2;++i)
    {
        threadPool.Submit(taskCounterIncrement);
    }

    threadPool.AddThreads(2);
    
    threadPool.RemoveThreads(1);
        
    ASSERT_PASS(); 
END_TEST

BEGIN_SUITE(ThreadPoolTests)
    TEST(QueueCapacityIsZero)
    TEST(SubmitAndShutDownTest)
    TEST(SubmitAndShutDownDefaultNumberOfThreads)
    TEST(SubmitAfterShutDownTest)
    TEST(SubmitAndAddAndShutDownTest)
    TEST(SubmitAndAddAfterShutDownTest)
    TEST(SubmitWithoutShutDownTest)
    TEST(SubmitWithoutShutDownContinueTest)
    TEST(SubmitAndAndShutDownQueueIsEmptyTest)
    TEST(SubmitAndAddAndShutDownImmediatelyTest)
    TEST(SubmitAndShutDownImmediatelyQueueIsEmptyTest)
    TEST(SubmitAndAddAfterShutDownImmediatelyTest)
    TEST(AddAndSubmitAfterShutDownImmediatelyTest)
    TEST(SubmitAndRemoveTest)
    TEST(SubmitAndRemoveMoreThreadThanNumberOfThreadsTest)
    TEST(SubmitAndRemoveLessThreadThanNumberOfThreadsTest)
    TEST(SubmitAndRemoveLessThreadThanNumberOfThreadsTest2)
END_SUITE
#include "mu_test.h" // MU Test Header
#include "runnable.hpp"
#include "runnable_adapters.hpp" // Runnable Adapters Header
#include "task_counter_decrement.hpp" // Task Counter Decrement Header
#include "task_counter_increment.hpp" // Task Counter Increment Header
#include "thread.hpp" // Thread Header
#include "thread_group.hpp" // Thread Group Header

#define TEN_ITERATIONS (10)
#define TEN_THOUSAND_OF_ITERATIONS_2 (10000)
#define ONE_MILLION_ITERATIONS (1000000)

#define TEN_THREADS (10)
#define HOUNDARD_THREADS (100)

using namespace advcpp;

/////////////////////////////////////// Thread Test //////////////////////////////////

BEGIN_TEST(OneThreadIncrementTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_ITERATIONS));
    
    Thread thread1(taskCounterIncrement, JoinPolicy());
    thread1.Join();

    ASSERT_THAT(10 == counter.GetCount()); 
END_TEST

BEGIN_TEST(TwoThreadsIncrementSimpleTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement1(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement2(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    
    Thread thread1(taskCounterIncrement1, JoinPolicy());
    Thread thread2(taskCounterIncrement2, JoinPolicy());
    
    thread1.Join();
    thread2.Join();

    ASSERT_THAT(TEN_THOUSAND_OF_ITERATIONS_2 * 2 == counter.GetCount()); 
END_TEST

BEGIN_TEST(TwoThreadsIncrementLargeTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement1(new TaskCounterIncrement(counter, ONE_MILLION_ITERATIONS));
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement2(new TaskCounterIncrement(counter, ONE_MILLION_ITERATIONS));
    
    Thread thread1(taskCounterIncrement1, JoinPolicy());
    Thread thread2(taskCounterIncrement2, JoinPolicy());

    thread1.Join();
    thread2.Join();

    ASSERT_THAT(ONE_MILLION_ITERATIONS * 2 == counter.GetCount()); 
END_TEST

BEGIN_TEST(TwoThreadsOneIncrementOneDecrementSimpleTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    std::shared_ptr<TaskCounterDecrement> taskCounterDecrement(new TaskCounterDecrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    
    Thread thread1(taskCounterIncrement, JoinPolicy());
    Thread thread2(taskCounterDecrement, JoinPolicy());

    thread1.Join();
    thread2.Join();

    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

BEGIN_TEST(TwoThreadsOneIncrementOneDecrementLargeTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, ONE_MILLION_ITERATIONS));
    std::shared_ptr<TaskCounterDecrement> taskCounterDecrement(new TaskCounterDecrement(counter, ONE_MILLION_ITERATIONS));
    
    Thread thread1(taskCounterIncrement, JoinPolicy());
    Thread thread2(taskCounterDecrement, JoinPolicy());

    thread1.Join();
    thread2.Join();

    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

// //////////////////////////////////// Thread Group Test ///////////////////////////////

BEGIN_TEST(ThreadGroupTestIncrementTask)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_ITERATIONS));
    
    ThreadGroup threadGroup(taskCounterIncrement, TEN_THREADS, JoinPolicy());
    threadGroup.Join();
    
    ASSERT_THAT(TEN_ITERATIONS * TEN_THREADS == counter.GetCount()); 
END_TEST

BEGIN_TEST(ThreadGroupTestIncrementTaskLargeTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    
    ThreadGroup threadGroup(taskCounterIncrement, HOUNDARD_THREADS, JoinPolicy());
    threadGroup.Join();
    
    ASSERT_THAT(TEN_THOUSAND_OF_ITERATIONS_2 * HOUNDARD_THREADS == counter.GetCount()); 
END_TEST

BEGIN_TEST(ThreadGroupTestIncrementAndDecrementTaskTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    std::shared_ptr<TaskCounterDecrement> taskCounterDecrement(new TaskCounterDecrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));

    ThreadGroup threadGroupIncrement(taskCounterIncrement, TEN_THREADS, JoinPolicy());
    ThreadGroup threadGroupDecrement(taskCounterDecrement, TEN_THREADS, JoinPolicy());
    threadGroupIncrement.Join();
    threadGroupDecrement.Join();
    
    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

BEGIN_TEST(ThreadGroupTestIncrementAndDecrementTaskLargeTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    std::shared_ptr<TaskCounterDecrement> taskCounterDecrement(new TaskCounterDecrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));

    ThreadGroup threadGroupIncrement(taskCounterIncrement, HOUNDARD_THREADS, JoinPolicy());
    ThreadGroup threadGroupDecrement(taskCounterDecrement, HOUNDARD_THREADS, JoinPolicy());
    threadGroupIncrement.Join();
    threadGroupDecrement.Join();
    
    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

//////////////////////////// Global Function Adapter Test /////////////////////////////

int Return10Pow() 
{
    return 10 * 10;
}

BEGIN_TEST(GlobalFunctionAdapterWithReturnValue)
    GlobalFunctionAdapaterWithReturnValue<int> adapterWithReturnValue(Return10Pow);
    adapterWithReturnValue.run();
    
    ASSERT_THAT(100 == adapterWithReturnValue.GetReturnValue()); 
END_TEST

long Pow(long a_number) 
{
    return a_number * a_number;
}

BEGIN_TEST(GlobalFunctionAdapterWithReturnValueAndOneArg)
    long number = 50;

    GlobalFunctionAdapaterWithReturnValueAndOneArg<long ,long> adapterWithReturnValueAndOneArg(Pow, number);
    adapterWithReturnValueAndOneArg.run();
    
    ASSERT_THAT(number * number == adapterWithReturnValueAndOneArg.GetReturnValue()); 
END_TEST

double SumTwoNumbers(double a_number1, long a_number2) 
{
    return a_number1 + a_number2;
}

BEGIN_TEST(GlobalFunctionAdapterWithReturnValueAndTwoArg)
    double number1 = 20.7;
    long number2 = 100;

    GlobalFunctionAdapaterWithReturnValueAndTwoArg<double ,double, long> adapterWithReturnValueAndTwoArg(SumTwoNumbers, number1, number2);
    adapterWithReturnValueAndTwoArg.run();
    
    ASSERT_THAT(number1 + number2 == adapterWithReturnValueAndTwoArg.GetReturnValue()); 
END_TEST

////////////////////////// Member Function Adapter + Thread / ThreadGroup Test ////////////////////////

BEGIN_TEST(MemberFunctionAdapterWithOneThreadIncrementOneTest)
    Counter counter;
    std::shared_ptr<Runnable> memberFunctionAdapterCounterIncrement(new MemberFunctionAdapaterWithoutReturnValue<Counter>(counter, &Counter::Increment));
    
    Thread thread1(memberFunctionAdapterCounterIncrement, JoinPolicy());
    thread1.Join();

    ASSERT_THAT(1 == counter.GetCount()); 
END_TEST

BEGIN_TEST(MemberFunctionAdapterWithOneThreadIncrementMillionTest)
    Counter counter;
    std::shared_ptr<Runnable> memberFunctionAdapterCounterIncrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Increment, ONE_MILLION_ITERATIONS));
    
    Thread thread1(memberFunctionAdapterCounterIncrement, JoinPolicy());
    thread1.Join();

    ASSERT_THAT(ONE_MILLION_ITERATIONS == counter.GetCount()); 
END_TEST

BEGIN_TEST(MemberFunctionAdapterWithTwoThreadsIncrementMillionTest)
    Counter counter;
    std::shared_ptr<Runnable> memberFunctionAdapterCounterIncrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Increment, ONE_MILLION_ITERATIONS));
    
    Thread thread1(memberFunctionAdapterCounterIncrement, JoinPolicy());
    Thread thread2(memberFunctionAdapterCounterIncrement, JoinPolicy());

    thread1.Join();
    thread2.Join();

    ASSERT_THAT(ONE_MILLION_ITERATIONS * 2 == counter.GetCount()); 
END_TEST

BEGIN_TEST(MemberFunctionAdapterWithTwoThreadsOneIncrementOneDecrementTest)
    Counter counter;
    std::shared_ptr<Runnable> memberFunctionAdapterCounterDecrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Decrement, ONE_MILLION_ITERATIONS));
    std::shared_ptr<Runnable> memberFunctionAdapterCounterIncrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Increment, ONE_MILLION_ITERATIONS));
    
    Thread threadDecrement(memberFunctionAdapterCounterDecrement, JoinPolicy());
    Thread threadIncrement(memberFunctionAdapterCounterIncrement, JoinPolicy());

    threadDecrement.Join();
    threadIncrement.Join();

    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

BEGIN_TEST(MemberFunctionAdapterWithTwoThreadGroupOneIncrementOneDecrementTest)
    Counter counter;
    std::shared_ptr<Runnable> memberFunctionAdapterCounterDecrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Decrement, ONE_MILLION_ITERATIONS));
    std::shared_ptr<Runnable> memberFunctionAdapterCounterIncrement(new MemberFunctionAdapaterWithNumberOfIterations<Counter>(counter, &Counter::Increment, ONE_MILLION_ITERATIONS));
    
    ThreadGroup threadGroupDecrement(memberFunctionAdapterCounterDecrement, HOUNDARD_THREADS, JoinPolicy());
    ThreadGroup threadGroupIncrement(memberFunctionAdapterCounterIncrement, HOUNDARD_THREADS, JoinPolicy());

    threadGroupDecrement.Join();
    threadGroupIncrement.Join();

    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

/////////////////////////// Join/Detach Policy Test ////////////////////////

BEGIN_TEST(OneThreadIncrementWithJoinPolicyTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_ITERATIONS));
    
    {
        Thread thread1(taskCounterIncrement, JoinPolicy());
    }

    ASSERT_THAT(10 == counter.GetCount()); 
END_TEST

BEGIN_TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    std::shared_ptr<TaskCounterDecrement> taskCounterDecrement(new TaskCounterDecrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));

    {
        ThreadGroup threadGroupIncrement(taskCounterIncrement, HOUNDARD_THREADS, JoinPolicy());
        ThreadGroup threadGroupDecrement(taskCounterDecrement, HOUNDARD_THREADS, JoinPolicy());
    }

    ASSERT_THAT(0 == counter.GetCount()); 
END_TEST

/////////////////////////// Add/Remove New Threads Test ////////////////////////

BEGIN_TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyAndAddTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));

    {
        ThreadGroup threadGroupIncrement(taskCounterIncrement, HOUNDARD_THREADS, JoinPolicy());
        threadGroupIncrement.Add(HOUNDARD_THREADS);
        threadGroupIncrement.Add(HOUNDARD_THREADS);
    }

    ASSERT_THAT(HOUNDARD_THREADS * TEN_THOUSAND_OF_ITERATIONS_2 * 3 == counter.GetCount()); 
END_TEST

BEGIN_TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyAndRemoveTest)
    Counter counter;
    std::shared_ptr<TaskCounterIncrement> taskCounterIncrement(new TaskCounterIncrement(counter, TEN_THOUSAND_OF_ITERATIONS_2));
    
    ThreadGroup threadGroupIncrement(taskCounterIncrement, HOUNDARD_THREADS, JoinPolicy());

    ASSERT_THAT(HOUNDARD_THREADS == threadGroupIncrement.Remove(HOUNDARD_THREADS)); 
END_TEST


BEGIN_SUITE(ThreadTests)
    TEST(OneThreadIncrementTest)
    TEST(TwoThreadsIncrementSimpleTest)
    TEST(TwoThreadsIncrementLargeTest)
    TEST(TwoThreadsOneIncrementOneDecrementSimpleTest)
    TEST(TwoThreadsOneIncrementOneDecrementLargeTest)

    TEST(ThreadGroupTestIncrementTask)
    TEST(ThreadGroupTestIncrementTaskLargeTest)
    TEST(ThreadGroupTestIncrementAndDecrementTaskTest)
    TEST(ThreadGroupTestIncrementAndDecrementTaskLargeTest)
    
    TEST(GlobalFunctionAdapterWithReturnValue)
    TEST(GlobalFunctionAdapterWithReturnValueAndOneArg)
    TEST(GlobalFunctionAdapterWithReturnValueAndTwoArg)

    TEST(MemberFunctionAdapterWithOneThreadIncrementOneTest)
    TEST(MemberFunctionAdapterWithOneThreadIncrementMillionTest)
    TEST(MemberFunctionAdapterWithTwoThreadsOneIncrementOneDecrementTest)
    TEST(MemberFunctionAdapterWithTwoThreadGroupOneIncrementOneDecrementTest)

    TEST(OneThreadIncrementWithJoinPolicyTest)
    TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyTest)
    
    TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyAndAddTest)
    TEST(ThreadGroupTestIncrementAndDecrementTaskLargeJoinPolicyAndRemoveTest)
END_SUITE

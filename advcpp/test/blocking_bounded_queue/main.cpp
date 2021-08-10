#include "mu_test.h" // MU Test Header
#include <memory> // std::shared_ptr
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "task_dequeue.hpp" // Task Dequeue Header
#include "task_enqueue.hpp" // Task Enqueue Header
#include "thread.hpp" // Thread Header
#include "thread_group.hpp" // Thread Group Header

#define QUEUE_CAPACITY (5)
#define HOUNDARD_ITERATIONS (100)
#define TEN_THREADS (10)

using namespace advcpp;

BEGIN_TEST(SimpleEnqueueDequeueSizeTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));
    
    for (size_t i = 0;i < QUEUE_CAPACITY;++i)
    {
        blockingBoundedQueue->Enqueue(i);
    }

    ASSERT_THAT(QUEUE_CAPACITY == (*blockingBoundedQueue).Size());

    for (size_t i = 0;i < 2;++i)
    {
        int returnValue;
        blockingBoundedQueue->Dequeue(returnValue);
    }

    ASSERT_THAT(QUEUE_CAPACITY - 2 == (*blockingBoundedQueue).Size());

    for (size_t i = 0;i < 3;++i)
    {
        int returnValue;
        blockingBoundedQueue->Dequeue(returnValue);
    }

    ASSERT_THAT(0 == blockingBoundedQueue->Size());
END_TEST

BEGIN_TEST(SimpleEnqueueDequeueCapacityIsFullIsEmptyTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));
    
    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Capacity());
    ASSERT_THAT(false == blockingBoundedQueue->IsFull());
    ASSERT_THAT(true == blockingBoundedQueue->IsEmpty());

    for (size_t i = 0;i < QUEUE_CAPACITY;++i)
    {
        blockingBoundedQueue->Enqueue(i);
    }

    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Capacity());
    ASSERT_THAT(true == blockingBoundedQueue->IsFull());
    ASSERT_THAT(false == blockingBoundedQueue->IsEmpty());

    for (size_t i = 0;i < QUEUE_CAPACITY - 2;++i)
    {
        int returnValue;
        blockingBoundedQueue->Dequeue(returnValue);
    }

    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Capacity());
    ASSERT_THAT(false == blockingBoundedQueue->IsFull());
    ASSERT_THAT(false == blockingBoundedQueue->IsEmpty());
END_TEST

BEGIN_TEST(OneProducerAndOneConsumerTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));

    std::shared_ptr<std::vector<int>> enqueueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS);
    std::shared_ptr<TaskEnqueue<int>> sharedPointerTaskEnqueue(new TaskEnqueue(blockingBoundedQueue, HOUNDARD_ITERATIONS, enqueueVector));

    std::shared_ptr<std::vector<int>> dequeueVector(new std::vector<int>);
    dequeueVector->reserve(HOUNDARD_ITERATIONS);
    std::shared_ptr<TaskDequeue<int>> sharedPointerTaskDequeue(new TaskDequeue(blockingBoundedQueue, HOUNDARD_ITERATIONS, dequeueVector));
    
    Thread threadEnqueue(sharedPointerTaskEnqueue, JoinPolicy());
    Thread threadDequeue(sharedPointerTaskDequeue, JoinPolicy());

    threadEnqueue.Join();
    threadDequeue.Join();

    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Capacity());
    ASSERT_THAT(true == blockingBoundedQueue->IsEmpty());
    ASSERT_THAT(false == blockingBoundedQueue->IsFull());
    ASSERT_THAT(0 == blockingBoundedQueue->Size());

    for (size_t i = 0;i < HOUNDARD_ITERATIONS;++i) 
    {
        ASSERT_THAT(static_cast<int>(i) == sharedPointerTaskEnqueue->Get(i));
    }

    for (size_t i = 0;i < HOUNDARD_ITERATIONS;++i) 
    {
        ASSERT_THAT(static_cast<int>(i) == sharedPointerTaskDequeue->Get(i));
    }
END_TEST

BEGIN_TEST(OneProducerAndOneConsumerTest2)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));

    std::shared_ptr<std::vector<int>> enqueueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS + QUEUE_CAPACITY);
    std::shared_ptr<TaskEnqueue<int>> sharedPointerTaskEnqueue(new TaskEnqueue(blockingBoundedQueue, HOUNDARD_ITERATIONS + QUEUE_CAPACITY, enqueueVector));

    std::shared_ptr<std::vector<int>> dequeueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS);
    std::shared_ptr<TaskDequeue<int>> sharedPointerTaskDequeue(new TaskDequeue(blockingBoundedQueue, HOUNDARD_ITERATIONS, dequeueVector));
    
    Thread threadEnqueue(sharedPointerTaskEnqueue, JoinPolicy());
    Thread threadDequeue(sharedPointerTaskDequeue, JoinPolicy());

    threadEnqueue.Join();
    threadDequeue.Join();

    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Capacity());
    ASSERT_THAT(false == blockingBoundedQueue->IsEmpty());
    ASSERT_THAT(true == blockingBoundedQueue->IsFull());
    ASSERT_THAT(QUEUE_CAPACITY == blockingBoundedQueue->Size());

    for (size_t i = 0;i < HOUNDARD_ITERATIONS + QUEUE_CAPACITY;++i) 
    {
        ASSERT_THAT(static_cast<int>(i) == sharedPointerTaskEnqueue->Get(i));
    }

    for (size_t i = 0;i < HOUNDARD_ITERATIONS;++i) 
    {
        ASSERT_THAT(static_cast<int>(i) == sharedPointerTaskDequeue->Get(i));
    }
END_TEST

BEGIN_TEST(TwoProducerAndOneConsumerTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));

    std::shared_ptr<std::vector<int>> enqueueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS * 2 + QUEUE_CAPACITY);
    std::shared_ptr<TaskEnqueue<int>> sharedPointerTaskEnqueue(new TaskEnqueue(blockingBoundedQueue, HOUNDARD_ITERATIONS * 2 + QUEUE_CAPACITY, enqueueVector));

    std::shared_ptr<std::vector<int>> dequeueVector(new std::vector<int>);
    dequeueVector->reserve(HOUNDARD_ITERATIONS * 2);
    std::shared_ptr<TaskDequeue<int>> sharedPointerTaskDequeue(new TaskDequeue(blockingBoundedQueue, HOUNDARD_ITERATIONS, dequeueVector));
    
    Thread threadEnqueue(sharedPointerTaskEnqueue, JoinPolicy());
    Thread threadDequeue1(sharedPointerTaskDequeue, JoinPolicy());
    Thread threadDequeue2(sharedPointerTaskDequeue, JoinPolicy());

    threadEnqueue.Join();
    threadDequeue1.Join();
    threadDequeue2.Join();

    ASSERT_THAT(HOUNDARD_ITERATIONS * 2 + QUEUE_CAPACITY == enqueueVector->size());
    ASSERT_THAT(HOUNDARD_ITERATIONS * 2 == dequeueVector->size());
END_TEST

BEGIN_TEST(OneProducerAndTwoConsumerTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));

    std::shared_ptr<std::vector<int>> enqueueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS * 2);
    std::shared_ptr<TaskEnqueue<int>> sharedPointerTaskEnqueue(new TaskEnqueue(blockingBoundedQueue, HOUNDARD_ITERATIONS, enqueueVector));

    std::shared_ptr<std::vector<int>> dequeueVector(new std::vector<int>);
    dequeueVector->reserve((HOUNDARD_ITERATIONS * 2));
    std::shared_ptr<TaskDequeue<int>> sharedPointerTaskDequeue(new TaskDequeue(blockingBoundedQueue, HOUNDARD_ITERATIONS * 2, dequeueVector));

    Thread threadEnqueue1(sharedPointerTaskEnqueue, JoinPolicy());
    Thread threadEnqueue2(sharedPointerTaskEnqueue, JoinPolicy());
    Thread threadDequeue(sharedPointerTaskDequeue, JoinPolicy());

    threadEnqueue1.Join();
    threadEnqueue2.Join();
    threadDequeue.Join();

    ASSERT_THAT(HOUNDARD_ITERATIONS * 2 == enqueueVector->size());
    ASSERT_THAT(HOUNDARD_ITERATIONS * 2 == dequeueVector->size());
END_TEST

BEGIN_TEST(OneProducerWithAliveFlagAndDetachPolicyTest)
    std::shared_ptr<BlockingBoundedQueue<int>> blockingBoundedQueue(new BlockingBoundedQueue<int>(QUEUE_CAPACITY));

    std::shared_ptr<std::vector<int>> enqueueVector(new std::vector<int>);
    enqueueVector->reserve(HOUNDARD_ITERATIONS * HOUNDARD_ITERATIONS);
    std::shared_ptr<TaskEnqueue<int>> sharedPointerTaskEnqueue(new TaskEnqueue(blockingBoundedQueue, HOUNDARD_ITERATIONS * HOUNDARD_ITERATIONS * HOUNDARD_ITERATIONS * HOUNDARD_ITERATIONS, enqueueVector));

    Thread threadEnqueue(sharedPointerTaskEnqueue, DetachPolicy());

    ASSERT_PASS();
END_TEST

BEGIN_SUITE(blockingBoundedQueueTest)
    TEST(SimpleEnqueueDequeueSizeTest)
    TEST(SimpleEnqueueDequeueCapacityIsFullIsEmptyTest)
    TEST(OneProducerAndOneConsumerTest)
    TEST(OneProducerAndOneConsumerTest2)
    TEST(TwoProducerAndOneConsumerTest)
    TEST(OneProducerAndTwoConsumerTest)
    TEST(OneProducerWithAliveFlagAndDetachPolicyTest)
END_SUITE

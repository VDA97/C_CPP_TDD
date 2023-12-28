#include <gtest/gtest.h>
#include <iostream>
#include <gmock/gmock.h>

using namespace std;
using ::testing::_;
using ::testing::Return;

// QueueInterface class with two methods
class QueueInterface
{
public:
    virtual ~QueueInterface() { ; };
    virtual void enqueue(int data) = 0;
    virtual int dequeue() = 0;
};

// MockClass for QueueInterface
class MockQueue : public QueueInterface
{
public:
    MOCK_METHOD0(dequeue, int());
    MOCK_METHOD1(enqueue, void(int data));
};

class DataHolder
{
public:
    DataHolder(QueueInterface *queue) : queue(queue) { ; }
    void addData(int data)
    {
        queue->enqueue(data);
    }
    int getData()
    {
        return queue->dequeue();
    }

protected:
    QueueInterface *queue;
};

TEST(GMockTests, CanAddData)
{
    MockQueue myMockObj;
    DataHolder dh(&myMockObj);

    EXPECT_CALL(myMockObj, enqueue(_)); // The enqueue _ means "accept any value wildcard"
    dh.addData(1);
}

TEST(GMockTests, CanGetData)
{
    MockQueue myMockObj;
    DataHolder dh(&myMockObj);
    EXPECT_CALL(myMockObj, enqueue(1));
    EXPECT_CALL(myMockObj, dequeue()).WillOnce(Return(1)); // The enqueue _ means "accept any value wildcard"
    dh.addData(1);
    int data = dh.getData();
    ASSERT_EQ(1, data);
}
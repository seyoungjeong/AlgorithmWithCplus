#include <gtest/gtest.h>
#include "SimpleRingBuffer.h"

TEST(TestSimpleRingBuffer, TestSimpleEnqueueAndDequeue){
    rbuf_clear();

    rbuf_enqueue(1);
    rbuf_enqueue(2);
    rbuf_enqueue(3);

    uint8_t data;
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(1, data);
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(2, data);
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(3, data);
}

TEST(TestSimpleRingBuffer, TestFull){
    rbuf_clear();

    for (uint8_t i = 0; i < 31; i++ ) {
        EXPECT_FALSE(rbuf_is_full());
        EXPECT_TRUE(rbuf_enqueue(i));
    }
    EXPECT_FALSE(rbuf_enqueue(32));
    EXPECT_TRUE(rbuf_is_full());
}

TEST(TestSimpleRingBuffer, TestRotation){
    rbuf_clear();

    for (uint8_t i = 0; i < 31; i++ ) {
        EXPECT_FALSE(rbuf_is_full());
        EXPECT_TRUE(rbuf_enqueue(i));
    }

    uint8_t data;
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(0, data);
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(1, data);
    EXPECT_TRUE(rbuf_dequeue(data));
    EXPECT_EQ(2, data);

    EXPECT_TRUE(rbuf_enqueue(31));
    EXPECT_TRUE(rbuf_enqueue(32));
    EXPECT_TRUE(rbuf_enqueue(33));

    for (uint8_t i = 3; i < 34; i++ ) {
        uint8_t data;
        EXPECT_TRUE(rbuf_dequeue(data));
        EXPECT_EQ(i, data);
    }
}


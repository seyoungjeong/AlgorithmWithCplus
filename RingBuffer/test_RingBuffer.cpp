#include <gtest/gtest.h>
#include "RingBuffer.h"

TEST(TestRingBuffer, TestEnqueueAndDequeue){
    RingBuffer rb = RingBuffer(32);
    const uint32_t data[] = {0, 1, 2, 3, 4};

    EXPECT_TRUE(rb.enqueue(data, sizeof(data)));

    uint32_t rdata[5] = {};
    size_t rlength = 5;
    EXPECT_TRUE(rb.dequeue(rdata, rlength));
    EXPECT_TRUE(0 == memcmp(data, rdata, 5));
}


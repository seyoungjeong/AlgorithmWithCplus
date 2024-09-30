#pragma once

#include <stdint.h>

#define RBUF_SIZE   32

static uint8_t rbuf[RBUF_SIZE];
static uint8_t rbuf_read = 0;
static uint8_t rbuf_write = 0;

static inline bool rbuf_is_full() {
    uint8_t next = (rbuf_write + 1) % RBUF_SIZE;
    return (next == rbuf_read);
}

static inline bool rbuf_is_empty() {
    return (rbuf_write == rbuf_read);
}

static inline void rbuf_clear() {
    // Actuire lock here
    rbuf_read = rbuf_write = 0;
    // Release lock here
}

static inline bool rbuf_enqueue(uint8_t data) {
    bool ret = false;
    // Actuire lock here
    if (!rbuf_is_full()) {
        rbuf[rbuf_write] = data;
        rbuf_write = (rbuf_write + 1) % RBUF_SIZE;
        ret = true;
    }
    // Release lock here
    return ret;
}

static inline bool rbuf_dequeue(uint8_t &data) {
    bool ret = false;
    // Actuire lock here
    if (!rbuf_is_empty()) {
        data = rbuf[rbuf_read];
        rbuf_read = (rbuf_read + 1) % RBUF_SIZE;
        ret = true;
    }
    // Release lock here
    return ret;
}


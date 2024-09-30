#include <cstddef>
#include <stdexcept>
#include <stdint.h>
#include <algorithm>

using namespace std;

class RingBuffer {
    size_t _cap;
    uint8_t* _buffer;

    size_t _rid, _wid;
    size_t _len;

public:
    RingBuffer(size_t cap) {
        if (cap <= 0) {
            throw length_error("Invalid buffer capacity");
        }
        _cap = cap;
        _buffer = new uint8_t[_cap];
        _rid = _wid = _len = 0;
    }
    ~RingBuffer() {
        delete _buffer;
    }

    size_t get_free() {
        return _cap - _len;
    }

    size_t get_length() {
        return _len;
    }

    bool enqueue(const uint32_t* data, size_t len) {
        if (len > get_free()) {
            return false;
        }
        size_t len_to_end = _wid >= _rid 
            ? min(len, _cap - _wid) : min(len, _rid - _wid);
        memcpy(_buffer + _wid, data, len_to_end);
        size_t remaining = len - len_to_end;
        if (remaining) {
            memcpy(_buffer, data + len_to_end, remaining);
        }
        _wid = (_wid + len) % _cap;
        _len += len;
        return true;
    }

    bool dequeue(uint32_t* data, size_t len) {
        if (len > get_length()) {
            return false;
        }
        size_t len_to_end = _wid >= _rid 
            ? min(len, _wid - _rid) : min(len, _cap - _rid);
        memcpy(data, _buffer + _rid, len_to_end);
        size_t remaining = len - len_to_end;
        if (remaining) {
            memcpy(data + len_to_end, _buffer, remaining);
        }
        _rid = (_rid + len) % _cap;
        _len -= len;
        return true;
     }
};


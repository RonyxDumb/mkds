#include "03/code_021cd2cc.h"

s32 ParseHexDigit(u32 value) {
    if (value <= '9') {
        return value - '0';
    }
    if (value <= 'F') {
        return value - '7';
    }
    return value - 'W';
}

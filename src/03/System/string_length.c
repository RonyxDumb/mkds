#include "03/System/string_length.h"

s32 GetStringLengthWithLimit(const u8 *bytes, s32 limit) {
    s32 index;
    for (index = 0; index < limit; index++) {
        if (bytes[index] == 0) {
            break;
        }
    }
    return index;
}

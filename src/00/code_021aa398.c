#include "00/code_021aa398.h"

void func_ov000_021aa398(u8 *bytes, s32 count) {
    s32 i;
    bytes += count;
    for (i = 0; i < count; i++) {
        bytes--;
        (*bytes)++;
        if (*bytes != 0) {
            break;
        }
    }
}

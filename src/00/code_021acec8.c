#include "00/code_021acec8.h"

s32 func_ov000_021acec8(const u16 *text, s32 count) {
    while (count != 0 && text[count - 1] == 0) {
        count--;
    }
    return count;
}

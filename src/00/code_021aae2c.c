#include "00/code_021aae2c.h"

s32 func_ov000_021aae2c(const s8 *text) {
    const s8 *start = text;
    while (*text != '.' && *text != 0) {
        text++;
    }
    return text - start;
}

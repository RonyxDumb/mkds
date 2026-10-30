#include "00/code_0219b8fc.h"
#include "00/code_0219887c.h"
#include "00/code_0219b000.h"
#include "00/code_0219b8a8.h"
#include "00/code_0219b958.h"
#include "00/code_0219b9b4.h"

void **func_ov000_0219b8fc(u32 a, s32 b) {
    u8 c;

    for (c = 0; c < b; c++) {
        if (a == data_ov000_021b54c8->mUnk_430[c]) {
            break;
        }
    }
    if (c >= b) {
        return 0;
    }
    return func_ov000_0219b958(
        func_ov000_0219b9b4((Unk0219887c *) func_ov000_0219b9d4(data_ov000_021b54c8->mUnk_5f4[c])));
}

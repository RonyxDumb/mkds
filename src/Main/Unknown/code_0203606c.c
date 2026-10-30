#include "Main/Unknown/code_0203606c.h"
#include "Main/Unknown/code_020360d0.h"
#include "Main/Unknown/unk_0217a000.h"

// non-matching: 80%, the original has one shared epilogue (movne r0, 1 then branch); here the epilogue is duplicated, 8 bytes over
u32 func_0203606c(void) {
    return data_0217aa08->mUnk_28 != 0 ? 1 : func_020360a0();
}

u32 func_020360a0(void) {
    if (func_020360d0() != 0) {
        return data_021759d4->mUnk_10;
    }
    return 0;
}

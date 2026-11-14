#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/unk_02153000.h"

const u8 data_021532a8[52] = {4, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 7, 0, 0, 0, 3, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 0xb, 0, 0, 0, 0xc};

#pragma thumb on
u32 func_02025eb0(u32 characterIndex) {
    u32 value0 = (u32) characterIndex;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &data_021532a8;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return value0;
}
#pragma thumb off

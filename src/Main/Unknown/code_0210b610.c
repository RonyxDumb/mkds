#include "Main/Unknown/code_0210b610.h"

#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_0210b610(void) {
    s32 a;
    s32 b;
    s32 c;
    s64 d;

    a = *(u32 *) data_0217ccb8 + 0x1999;
    *(u32 *) data_0217ccb8 = a;
    b = a & 0xffff;
    c = data_0215d4b4[(b >> 4) * 2];
    d = (s64) c * 0x90000 + 0x800;
    *(u32 *) data_0217ccb8 = b;
    *(u32 *) data_0217ccb4 = (s32) (d >> 12) >> 12;
}

#include "Main/Unknown/code_02089e10.h"
#include "Main/Unknown/unk_02155000.h"

void func_02089e68(Unk02089e68 *a) {
    a->mUnk_02 = (s32) (((s64) ((s32) a->mUnk_00 << 12) * 0x1333 + 0x800) >> 12) >> 12;
    a->mUnk_00 = a->mUnk_00 - 1;
    if (a->mUnk_00 <= 0) {
        a->mUnk_08 = 0;
    }
}

void func_02089e10(int a) {
    *(u32 *) 0x400048c = data_02155ed0[a * 3] | data_02155ed0[a * 3 + 1] << 16;
    *(u32 *) 0x400048c = data_02155ed0[a * 3 + 2];
}

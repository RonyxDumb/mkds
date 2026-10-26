#include "code_02146bb8.h"

void func_02146c24(Unk02146bb8 *a) {
    a->mUnk_00 = *(vu64 *) 0x04000290;
    a->mUnk_08 = *(vu64 *) 0x04000298;
    a->mUnk_18 = *(vu16 *) 0x04000280 & 3;
    a->mUnk_10 = *(vu64 *) 0x040002B8;
    a->mUnk_1a = *(vu16 *) 0x040002B0 & 1;
}

void func_02146bb8(const Unk02146bb8 *a) {
    *(vu64 *) 0x04000290 = a->mUnk_00;
    *(vu64 *) 0x04000298 = a->mUnk_08;
    *(vu16 *) 0x04000280 = a->mUnk_18;
    *(vu64 *) 0x040002B8 = a->mUnk_10;
    *(vu16 *) 0x040002B0 = a->mUnk_1a;
}

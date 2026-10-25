#include "01/code_0219baf4.h"

void func_ov001_0219baf4(void) {
    if (data_ov001_021a9bf4->mUnk_6c == 1) {
        *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & ~0x1f00) | 0x1800;
    }
    func_0212b91c();
    func_0211de34();
    func_0211df38();
    func_02117218();
    func_02036ab0((void *)data_ov001_021a9bf4->mUnk_44);
    data_ov001_021a9bf4 = 0;
}

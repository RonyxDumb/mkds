#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_02038000.h"

void func_020ad9c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    func_02038d28(a->mUnk_28, b, c, d, e, f, g, h);
}

void func_020ad98c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038d00(a->mUnk_28, b, c, d, e, f, g);
}

void func_020ad958(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038cd8(a->mUnk_28, b, c, d, e, f, g);
}

void func_020ad924(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038cd8(a->mUnk_70, b, c, d, e, f, g);
}

void func_020ad904(u32 a) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffcfffef) | a;
}

void func_020ad8e0(u32 a) {
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffcfffef) | a;
}

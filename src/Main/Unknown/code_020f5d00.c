#include "Main/Unknown/code_020f5d00.h"

#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f5d6c.h"

void func_020f5d00(Unk0206bcb0 *a) {
    func_020f2228(a, 0x8800);
    if (*(u32 *) &a->mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

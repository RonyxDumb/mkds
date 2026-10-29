#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"

void func_0208ffe4(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

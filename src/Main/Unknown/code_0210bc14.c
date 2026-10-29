#include "Main/Unknown/code_0210bc14.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212da38.h"
#include "code_020172d0.h"

u32 func_0210bc8c(int a, int b) {
    s32 i;
    Unk0210bc54 *p;

    p = (Unk0210bc54 *) (b + ((Unk02017328 *) a)->mUnk_0a);
    if (p->mUnk_08 != 0) {
        i = 0;
    } else {
        i = 1;
        p->mUnk_08 = (u32) a;
    }
    if (i != 0) {
        func_020174a4((Unk02017328 *) a, (void *) b);
    } else {
        return 0;
    }
    return 1;
}

void func_0210bc54(Unk02017328 *a, void *b) {
    Unk0210bc54 *p;

    func_02017354(a, b);
    p = (Unk0210bc54 *) ((u8 *) b + a->mUnk_0a);
    if (p->mUnk_08 != 0) {
        p->mUnk_08 = 0;
    }
}

// non-matching: the original fills the 0x17 rows with eight zero words each (two stm per row, no loads);
// mine keeps the zero struct on the stack and loads it (ldm) into each row.
void func_0210bc14(void) {
    s32 i;
    Unk0217cd30 *p;
    Unk0217cd30 v = {0};

    p = (Unk0217cd30 *) data_0217cd30;
    for (i = 0; i < 0x17; i++) {
        *p++ = v;
    }
}

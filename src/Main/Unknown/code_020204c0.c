#include "Main/Unknown/code_020204c0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"

// non-matching: 97.7%, the early returns are merged differently
s32 func_020204c0(Unk0217aa00_24 *a) {
    u16 v1[4];

    if (a == 0) {
        return 0;
    }
    if (a->mUnk_3c == 0) {
        return 0;
    }
    func_0214d1fc(&a->mUnk_50, v1, 8);
    func_0200ee58(v1, 8);
    if (a->mUnk_44 == 0) {
        if (v1[0] == 0x2348 || v1[0] == 0xbd8a) {
            if (v1[3] == 4) {
                return 1;
            }
        }
    }
    return 0;
}

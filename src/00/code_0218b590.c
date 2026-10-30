#include "00/code_0218b590.h"
#include "00/code_0218a918.h"
#include "00/code_0218b000.h"
#include "00/code_0218e8bc.h"
#include "00/code_021a4b84.h"
#include "00/unk_021b2000.h"
#include "code_02135014.h"
#include "code_02139f70.h"

s32 func_ov000_0218b590(Unk0218b668 *a, s32 b, u32 c, u8 *d, s32 e, const u8 *f, u32 g, u32 h) {
    u8 v1[256] = {0};
    s32 n;
    s32 i;
    s32 r;
    const u8 *s;
    n = 0;
    a->mUnk_620 = c;
    a->mUnk_040 = 0;
    for (i = 0; i < e; i++) {
        s = data_ov000_021b45bc[d[i]];
        if (n + (s32) func_0213a434(s) + 1 >= 256) {
            break;
        }
        n += func_02135014(v1 + n, data_ov000_021b21e8, s);
        func_ov000_0218a93c((u32) a, d[i]);
    }
    r = func_ov000_0218ca58((Unk0218b928 *) a->mUnk_04c, v1, f, g, h);
    if (r == 0 && b == 0) {
        n = 10;
        while (((Unk0218b928 *) a->mUnk_04c)->mUnk_00 == 3 || (a->mUnk_010 > 0 && r == 0)) {
            func_ov000_0218e8bc(n);
            r = func_ov000_0218b4bc(a);
        }
    }
    return r;
}

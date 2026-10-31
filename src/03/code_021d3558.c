#include "03/code_021d3558.h"
#include "03/code_021d1000.h"
#include "03/code_021d3488.h"
#include "03/code_021d34c8.h"
#include "03/unk_021da000.h"

void func_ov003_021d3558(int a) {
    Unk021d34e4 *b;
    s32 c;
    u32 d;

    b = data_ov003_021da32c[a].mUnk_0c.mUnk_04;
    if (b != &data_ov003_021da32c[a].mUnk_20) {
        do {
            b->mUnk_08(b, b->mUnk_0c);
            b = b->mUnk_04;
        } while (b != &data_ov003_021da32c[a].mUnk_20);
    }
    c = 0;
    if (data_ov003_021da32c[a].mUnk_34 > 0) {
        do {
            d = (u32) func_ov003_021d1cd4(data_ov003_021da32c[a].mResource);
            if (d == 0) {
                break;
            }
            func_ov003_021d3488(a, d);
            c++;
        } while (c < data_ov003_021da32c[a].mUnk_34);
    }
}

#include "00/code_0218a064.h"
#include "00/code_021884d8.h"
#include "00/code_021898dc.h"
#include "00/code_0218a018.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void func_ov000_0218a064(const u32 *a, Unk02188ec0 *v1, Unk0218a064 *v2) {
    Unk02188db0 *e;

    MI_CpuCopy8(data_ov000_021b0738, v2, 0x58);
    v2->field4 = a[0];
    v2->field8 = a[1];
    if (v1->fieldD0D < 6) {
        e = &v1->field0[func_ov000_021884d8(v1->fieldD0D)];
        if (e->fieldC0[0] != 0) {
            v2->fieldC = 0;
            v2->field10 = func_ov000_0218a018(e->fieldC0);
            v2->field14 = func_ov000_02189fd0(e->fieldD0);
            v2->field18 = func_ov000_0218a018(e->fieldC4);
            v2->field1C = func_ov000_0218a018(e->fieldC8);
            v2->field20 = func_ov000_0218a018(e->fieldCC);
        } else {
            v2->fieldC = 1;
            v2->field10 = 0;
            v2->field14 = 0;
            v2->field18 = 0;
            v2->field1C = 0;
            v2->field20 = 0;
        }
    }
}

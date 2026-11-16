#include "00/code_02188de4.h"
#include "00/code_02188ec0.h"
#include "00/code_0218a64c.h"
#include "code_0214d018.h"
#include "00/code_0218a67c.h"

u32 func_ov000_02188de4(struct Unk02188ec0 *v1, u32 a, Unk02188de4 *v2) {
    Unk02188db0 *p;

    p = v1->field0;
    switch (a) {
        case 2:
            p++;
        case 1:
            p++;
        case 0:
            v2->field0 = p->fieldE6;
            MI_CpuCopy8(p->field80, v2->field2, 0x50);
            break;
        case 5:
            p++;
        case 4:
            p++;
        case 3:
            v2->field0 = 1;
            MI_CpuCopy8(p->fieldD1, v2->field2, 0x14);
            v2->field2[0x14] = 0;
            break;
        case 6:
            v2->field0 = 2;
            func_ov000_0218a64c(v1->field470[v1->fieldD13].fieldC, v2->field2);
            break;
        case 7:
            v2->field0 = 2;
            func_ov000_0218a6ac(v1->field470[v1->fieldD13].fieldC, v2->field2);
            break;
        case 8:
        case 9:
            break;
    }
    if (v2->field0 != 0) {
        return 1;
    }
    return 0;
}

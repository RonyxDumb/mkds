#include "00/code_021894e4.h"

#include "00/code_02188ec0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_0214d018.h"
#include "code_02139f70.h"

u32 func_ov000_02189714(Unk02188ee0 *a) {
    int v1;
    v1 = strncmp((const char *) a->fieldC, data_ov000_021b06f0, 8);
    if (v1 == 0) {
        return 8;
    }
    return 0;
}

u8 func_ov000_021896c4(Unk02188ec0 *v1) {
    u8 n;
    Unk02188ec0_300 *c;

    c = v1->field300;
    n = func_ov000_0218954c(v1);
    c += n;
    if (v1->fieldD0C == 0 || v1->fieldD0C == 6) {
        MI_CpuCopy8(data_ov000_021b06f0, c->field4, 8);
        c->field3 = 8;
        c->field1 = 8;
        n++;
    }
    return n;
}

u8 func_ov000_02189614(Unk02188ec0 *v1) {
    u8 n;
    Unk02188ec0_300 *c;

    c = v1->field300;
    n = func_ov000_0218954c(v1);
    c += n;
    if (v1->fieldD0C == 0 || v1->fieldD0C == 4) {
        MI_CpuCopy8(data_ov000_021b20d0, c->field4, 8);
        c->field3 = 8;
        c->field1 = 6;
        n++;
        c++;
    }
    if (v1->fieldD0C == 0 || v1->fieldD0C == 7) {
        MI_CpuCopy8(data_ov000_021b06e8, c->field4, 8);
        c->field3 = 8;
        c->field1 = 9;
        n++;
        c++;
    }
    if (v1->fieldD0C == 0 || v1->fieldD0C == 8) {
        MI_CpuCopy8(data_ov000_021b06f8, c->field4, 0xb);
        c->field3 = 0xb;
        c->field1 = 10;
        n++;
    }
    return n;
}

u8 func_ov000_0218954c(Unk02188ec0 *v1) {
    s32 i;
    u8 n;
    u8 j;
    BOOL v2;
    Unk02188db0 *e;
    Unk02188ec0_300 *c;

    n = 0;
    e = v1->field0;
    c = v1->field300;
    for (i = 0; i < 3; e++, i++) {
        if (v1->fieldD0C == 0 || v1->fieldD0C == i + 1) {
            if (e->fieldE7 != 0xff) {
                for (j = 0; j < 0x20; j++) {
                    if (e->field40[j] == 0) {
                        break;
                    }
                    c->field4[j] = e->field40[j];
                }
                if (j != 0) {
                    c->field3 = j;
                    c->field1 = i;
                    v2 = TRUE;
                } else {
                    v2 = FALSE;
                }
                if (v2 != FALSE) {
                    n++;
                    c++;
                }
                if (e->fieldE7 == 1) {
                    for (j = 0; j < 0x20; j++) {
                        if (e->field60[j] == 0) {
                            break;
                        }
                        c->field4[j] = e->field60[j];
                    }
                    if (j != 0) {
                        c->field3 = j;
                        c->field1 = i + 3;
                        v2 = TRUE;
                    } else {
                        v2 = FALSE;
                    }
                    if (v2 != FALSE) {
                        n++;
                        c++;
                    }
                }
            }
        }
    }
    return n;
}

u8 func_ov000_021894e4(s32 a, Unk02188ec0_444 *b, Unk02188ec0_300 *c, Unk02188ee0 *d) {
    u8 n;
    u8 i;
    u8 j;

    n = 0;
    for (i = 0; i < a; b++, d++, i++) {
        if (i >= 9) {
            break;
        }
        if (b->field0 == 0 && d->field36 != b->field3) {
            for (j = 0; j < 0x20; j++) {
                if (d->fieldC[j] == 0) {
                    break;
                }
                c->field4[j] = d->fieldC[j];
            }
            c->field3 = j;
            c->field2 = d->field36 - 1;
            c++;
            n++;
        }
    }
    return n;
}

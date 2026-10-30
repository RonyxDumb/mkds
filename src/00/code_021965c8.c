#include "00/code_021965c8.h"
#include "00/code_021965a0.h"
#include "code_0213442c.h"
#include "00/unk_021b3000.h"

s32 func_ov000_021965c8(Unk0218f960 *a, s8 *b, s32 *c, s8 *d, s8 *e) {
    s8 *p;
    s8 f;
    s32 i;

    if (b == 0) {
        func_0213442c(data_ov000_021b3a0c, data_ov000_021b3a1c, 0, 0x199);
    }
    if (d == 0) {
        func_0213442c(data_ov000_021b3a2c, data_ov000_021b3a1c, 0, 0x19a);
    }
    if (e == 0) {
        func_0213442c(data_ov000_021b3a38, data_ov000_021b3a1c, 0, 0x19b);
    }
    p = b + *c;
    if (*p != 0x5c) {
        func_ov000_021965a0(a, 1, data_ov000_021b3a48);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    i = 0;
    b = p + 2;
    f = p[1];
    if (f != 0x5c) {
        do {
            if (f == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b3a48);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (i == 0x1ff) {
                func_ov000_021965a0(a, 1, data_ov000_021b3a48);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            *d = f;
            d++;
            i++;
            f = *b;
            b++;
        } while (f != 0x5c);
    }
    *d = 0;
    i = 0;
    while ((f = *b++) != 0x5c && f != 0) {
        if (i == 0x1ff) {
            func_ov000_021965a0(a, 1, data_ov000_021b3a48);
            func_ov000_02190f4c(a, 3, 1);
            return 3;
        }
        *e = f;
        e++;
        i++;
    }
    *e = 0;
    *c = *c + ((b - p) - 1);
    return 0;
}

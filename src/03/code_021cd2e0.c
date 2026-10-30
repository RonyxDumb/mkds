#include "03/code_021cd2e0.h"
#include "03/code_021d27d8.h"
#include "code_020205b0.h"
#include "code_021510a4.h"
#include "code_0213a460.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_02151fc4.h"
#include "Main/Unknown/code_02151718.h"

void func_ov003_021cd2e0(const char *v1, u8 *v2) {
    u8 a[4];
    s32 i;
    s32 j;
    u8 *p;
    func_0214d168(a, 0, 4);
    for (i = 0; i < 4; i++) {
        func_0214d1fc(v1 + i * 3, a, 3);
        j = 0;
        p = a;
        for (; j < 3; j++) {
            if (*p != 0) {
                break;
            }
            *p = ' ';
            p++;
        }
        v2[i] = func_0213bf90(a);
    }
}

void func_ov003_021cd338(s32 param_1) {
    u32 a = *(*(u8 **) &data_ov003_021da270 + param_1 * 0x100 + 0xe7);
    u32 b = 1 << param_1;
    s32 c = 0;
    s32 d[4];
    void *e;
    u8 *p;
    s32 i;
    func_0214d168(d, 0, 0x10);
    d[param_1] = 1;
    if (param_1 <= 2) {
        p = *(u8 **) &data_ov003_021da270;
        if ((((const u8 *) p)[0xef] & b) != 0) {
            c = 1;
        }
        if (a == 0xff && c != 0) {
            p[0xef] = p[0xef] & ~b;
            *(*(u8 **) &data_ov003_021da270 + 0x1ef) = *(*(u8 **) &data_ov003_021da270 + 0x1ef) & ~b;
            d[1] = 1;
            d[0] = 1;
        } else if (a != 0xff && c == 0) {
            p[0xef] = p[0xef] | b;
            *(*(u8 **) &data_ov003_021da270 + 0x1ef) = *(*(u8 **) &data_ov003_021da270 + 0x1ef) | b;
            d[1] = 1;
            d[0] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            *(u16 *) (*(u8 **) &data_ov003_021da270 + i * 0x100 + 0xfe) = func_020205e8(
                (const u16 *) (*(u8 **) &data_ov003_021da270 + 0x4f8), *(u8 **) &data_ov003_021da270 + i * 0x100, 0xfe);
        }
    }
    e = func_ov003_021d285c(0x100, 0x20);
    func_02151794((int) *(u8 **) &data_ov003_021da270, d, (u32) e);
    func_ov003_021d2808(&e);
}

void func_ov003_021cd42c(void) {
    volatile u16 a = 0;
    Unk021510a4 b;
    u8 *c;
    s32 i;
    func_0214cfe4(a, *(u8 **) &data_ov003_021da270, 0x400);
    for (i = 0; i < 3; i++) {
        *(*(u8 **) &data_ov003_021da270 + i * 0x100 + 0xe7) = 0xff;
    }
    func_02151fc4(&b);
    c = func_021510a4(&b);
    for (i = 0; i < 2; i++) {
        func_0214d1fc(c, *(u8 **) &data_ov003_021da270 + i * 0x100 + 0xf0, 0xe);
    }
    for (i = 0; i < 4; i++) {
        func_ov003_021cd338(i);
    }
}

#include "00/code_021abca0.h"
#include "00/code_021abc04.h"
#include "00/code_021abd68.h"
#include "code_0214d018.h"

void func_ov000_021abca0(void *f, const u8 *b, u32 c) {
    Hash20Context *a = f;
    u32 d;
    u32 e;
    d = (a->field18 >> 3) & 0x3f;
    a->field18 += c << 3;
    if (a->field18 < (c << 3)) {
        a->field14++;
    }
    a->field14 += c >> 29;
    e = 64 - d;
    if (c >= e) {
        MI_CpuCopy8(b, &a->field1C[d], e);
        d = 0;
        func_ov000_021abd68(a, a->field1C);
        for (; e + 63 < c; e += 64) {
            func_ov000_021abd68(a, b + e);
        }
    } else {
        e = 0;
    }
    MI_CpuCopy8(b + e, &a->field1C[d], c - e);
}

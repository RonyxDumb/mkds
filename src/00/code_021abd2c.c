#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void func_ov000_021abd2c(Hash20Context *a) {
    MI_CpuFill8(a, 0, 0x5c);
    a->field0 = (0x67452301u);
    a->field4 = (0xefcdab89u);
    a->field8 = (0x98badcfeu);
    a->fieldC = (0x10325476u);
    a->field10 = (0xc3d2e1f0u);
}

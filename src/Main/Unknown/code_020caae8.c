#include "Main/Unknown/code_020caae8.h"
#include "code_0214a390.h"

void func_020cab2c(u32 a, u32 b) {
    *(vu32 *) 0x4001010 = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}

void func_020caae8(u32 a, u32 b, u32 c, u32 d, s32 e) {
    func_0214a390((u16 *) 0x4001050, a, b, c, d, e);
}

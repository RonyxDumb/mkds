#include "Main/Unknown/code_02035d48.h"

void func_02035d48(u32 param_1, int param_2) {
    *(u32 *) 0x0400101c = (param_1 & 0x1ff) | ((param_2 << 16) & 0x01ff0000);
}

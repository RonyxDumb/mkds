#include "Main/Unknown/code_020f92e8.h"

void func_020f9320(unsigned int p0, unsigned int p1) {
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 252) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 252))) & ((~(p1)))));
}

void func_020f92e8(u32 param_1, u32 param_2) {
    func_020eaa14((u32 *) ((u32 *) (u32) (param_1)), (u32 *) ((u32 *) (u32) (param_2)), (int) (0x00000b33u),
                  (int) (0x00000733u), (u32) (0x00000acdu), (u32 *) ((u32 *) (u32) (param_1)));
    return;
}

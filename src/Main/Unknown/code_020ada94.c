#include "Main/Unknown/code_020ada94.h"

#pragma thumb on

void func_020ada94(void) {
    (**(UnkFunc **) ((int) data_0217b340 + *(int *) ((int) data_0217b340 + 0xc) * 8 + 0x14))();
    *(u32 *) ((int) data_0217b340 + 4) = 0;
    func_021258f0();
    func_020ae5f0((void *) ((int) data_0217b340 + 0xb0),
                  (void *) ((int) data_0217b340 + 0x4b4));
}

#pragma thumb off

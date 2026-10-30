#include "Main/Unknown/code_02047b30.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0200d118.h"
#include "code_020182c0.h"

#pragma thumb on

u32 func_02047b30(u32 a, const char *b) {
    char v1[0x80];

    if (b[0] == '/') {
        func_0200d9e0(v1, 0x80, data_02165048, a, b);
    } else {
        func_0200d9e0(v1, 0x80, data_02165050, a, b);
    }
    return func_020182c0((const u8 *) v1);
}

#pragma thumb off

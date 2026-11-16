#include "Main/Unknown/code_0204f220.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_0204f220(u32 *payload, int length) {
    if ((length == 4) && (*payload == 0)) {
        gStruct217AA00->field1E38 = 1;
    }
}

#pragma thumb off

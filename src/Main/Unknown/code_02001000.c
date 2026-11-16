#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0200104c(void) {
    gStruct217AA00->field4 = 2;
    gStruct217AA00->field44.field3E = 0;
    gStruct217AA00->field8B &= ~8;
}

void func_02001000(void) {
    u8 v1;
    v1 = gStruct217AA00->field8A;
    if (v1 == 0) {
        return;
    }
    if (QueueMPDataHalfwordAndWord(7, gStruct217AA00->field44.mChildMask, v1) == FALSE) {
        return;
    }
    DisconnectChildren(v1);
}

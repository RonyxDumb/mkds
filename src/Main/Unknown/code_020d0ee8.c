#include "Main/Unknown/code_020d0ee8.h"
#include "Main/Unknown/code_02057d10.h"

#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0f60.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020d0f60(void) {
    gThreadFunctionQueue->mRunRequested = 1;
}

#pragma thumb on
u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex) {
    u32 result;

    result = 1;
    if (data_0216aeac[cupPictureIndex * 2] == 0) {
        result = 0;
    } else if (func_020d0ec4() != FALSE) {
        if (gCupPicture->mCupPictureIndex != cupPictureIndex) {
            gCupPicture->mCupPictureIndex = cupPictureIndex;
            QueueThreadFunction(LoadCupPictureNclr);
            QueueThreadFunction(LoadCupPictureNcgr);
            QueueThreadFunction(LoadCupPictureNscr);
            func_020d0f60();
        }
    } else {
        result = 0;
    }
    return result;
}
#pragma thumb off

u32 func_020d0ee8(void) {
    return (gThreadFunctionQueue->mRunRequested);
}

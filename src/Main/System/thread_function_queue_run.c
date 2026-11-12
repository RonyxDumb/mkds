#include "Main/System/thread_function_queue_run.h"
#include "Main/System/thread_function_queue.h"

#include "Main/Unknown/code_020d0efc.h"
#include "Main/Menu/cup_picture.h"
#include "Main/Unknown/code_020d0f60.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/unk_0217b000.h"

void RequestThreadFunctionQueueRun(void) {
    gThreadFunctionQueue->mRunRequested = 1;
}

#pragma thumb on
u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex) {
    u32 result;

    result = 1;
    if (data_0216aeac[cupPictureIndex * 2] == 0) {
        result = 0;
    } else if (IsCupPictureReady() != FALSE) {
        if (gCupPicture->mCupPictureIndex != cupPictureIndex) {
            gCupPicture->mCupPictureIndex = cupPictureIndex;
            QueueThreadFunction(LoadCupPictureNclr);
            QueueThreadFunction(LoadCupPictureNcgr);
            QueueThreadFunction(LoadCupPictureNscr);
            RequestThreadFunctionQueueRun();
        }
    } else {
        result = 0;
    }
    return result;
}
#pragma thumb off

u32 GetThreadFunctionQueueRunRequested(void) {
    return (gThreadFunctionQueue->mRunRequested);
}

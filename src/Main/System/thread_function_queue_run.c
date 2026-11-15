#include "Main/System/thread_function_queue_run.h"
#include "Main/System/thread_function_queue.h"

#include "Main/Menu/cup_picture.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/Menu/menu_screen_callbacks.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Save/ghost_record_file.h"

s32 gCupPictureNitroOrRetroTable[1] = {2};
s32 gCupPictureNumberTable[81] = {0, 1, 0x10, 2, 0, 2, 0,   2, 0,   2, 0,   2, 0,   2, 0,    2, 0,   1, 8, 1, 1,   1,
                                  2, 1, 7,    1, 3, 1, 4,   1, 9,   1, 6,   0, 0xa, 0, 4,    0, 0xc, 0, 1, 2, 0,   0,
                                  2, 1, 0xe,  0, 8, 0, 0xb, 0, 0xe, 0, 5,   0, 6,   0, 0x10, 0, 9,   0, 3, 0, 0xf, 0,
                                  7, 0, 0xd,  1, 5, 1, 0xa, 1, 0xb, 1, 0xc, 1, 0xd, 1, 0xf};

void RequestThreadFunctionQueueRun(void) {
    gThreadFunctionQueue->mRunRequested = 1;
}

#pragma thumb on
u32 TrySetCupPictureIndexAndQueueLoads(int cupPictureIndex) {
    u32 result;

    result = 1;
    if (gCupPictureNumberTable[cupPictureIndex * 2] == 0) {
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

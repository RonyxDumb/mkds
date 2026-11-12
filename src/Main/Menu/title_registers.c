#include "Main/Menu/title_registers.h"

#include "Main/Unknown/code_020ada94.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void WriteTitleSceneRegisters(void) {
    gTitleScene->mStateHandlers[gTitleScene->mState].mWriteRegisters();
    gTitleScene->mStateChanged = FALSE;
    WriteSceneTextRegisters();
    UploadOamLists(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off

void IncrementCounterSaturating(int *counter) {
    u32 value;
    value = *(u32 *) counter;
    if ((s32) value < 0x7fffffff) {
        *counter = value + 1;
    }
}

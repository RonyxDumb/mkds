#include "Main/Menu/title_registers.h"

#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

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

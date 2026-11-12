#include "Main/Menu/title_state4.h"

#include "Main/Unknown/code_020acacc.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Menu/title_state0.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/oam.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb00.h"
#include "00/code_02181f98.h"

#pragma thumb on
u32 TitleState4ReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off

#pragma thumb on

void UpdateTitleState4(void) {
    s32 titleStateFrames;

    titleStateFrames = GetTitleStateFrames();
    gTitleScene->mSelectedOffset = GetSelectedPressOffset(titleStateFrames);
    if (titleStateFrames >= 10) {
        SetTitleState(3, 5);
    }
    SetupAndDrawTitleTable();
}

void TitleState5Nop(void) {}

#pragma thumb off

void SetConnectionKind(u32 value) {
    gStartupWork->mConnectionKind = value;
}

void TitleSetWLMenuKind(u32 value) {
    gMenuShared->mWLMenuKind = value;
}

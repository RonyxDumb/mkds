#include "Main/Menu/title_select_press.h"

#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_blend_in.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"

#pragma thumb on
u32 TitleSelectPressReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}

void UpdateTitleSelectPress(void) {
    s32 titleStateFrames;

    titleStateFrames = GetTitleStateFrames();
    gTitleScene->mSelectedOffset = GetSelectedPressOffset(titleStateFrames);
    if (titleStateFrames >= 10) {
        SetTitleState(TITLE_STATE_SLIDE_OUT, TITLE_STATE_LEAVE);
    }
    SetupAndDrawTitleTable();
}

void TitleLeaveNop(void) {}

#pragma thumb off

void SetConnectionKind(u32 value) {
    gStartupWork->mConnectionKind = value;
}

void TitleSetWLMenuKind(u32 value) {
    gMenuShared->mWLMenuKind = value;
}

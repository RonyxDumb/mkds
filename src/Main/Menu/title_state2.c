#include "Main/Menu/title_state2.h"
#include "Main/Race/demo_race.h"
#include "Main/Menu/title_state5.h"

#include "Main/Menu/title_pair_new.h"
#include "Main/Menu/title_input.h"
#include "Main/Menu/title_state1.h"
#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_state0.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/Scene/title_no_input_frame_limit.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/init_after_startup.h"
#include "Main/System/result_archive_path.h"

u32 TitleGetPairX(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 TitleGetSlotPairX(u32 slotIndex) {
    return TitleGetPairX(&gInputSlots[slotIndex].mPair);
}

u32 TitleGetPairY(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 TitleGetSlotPairY(u32 slotIndex) {
    return TitleGetPairY(&gInputSlots[slotIndex].mPair);
}

#pragma thumb on

void UpdateTitleMenuInput(SceneNumbers *sceneNumbers) {
    u32 slotIndex;
    s32 previousIndex;
    s32 rectIndex;

    if (sceneNumbers != NULL) {
        slotIndex = GetTitleInputSlot();
        if (TitleGetNewBits(slotIndex, PAD_KEY_A) != 0) {
            SetTitleState(TITLE_STATE_SELECT_PRESS, 8);
            StartTitleSelectedSound();
            gTitleScene->mStartedOnSelected = TRUE;
        } else if (GetNewOrRepeatBits(slotIndex, (PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case TITLE_ENTRY_OPTION:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_RECORD;
                    gTitleScene->mPreferRecordEntry = TRUE;
                    StartSoundOncePerFrame(0);
                    break;
                case TITLE_ENTRY_RECORD:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_OPTION;
                    gTitleScene->mPreferRecordEntry = FALSE;
                    StartSoundOncePerFrame(0);
                    break;
            }
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case TITLE_ENTRY_FIRST:
                    if (gTitleScene->mPreferRecordEntry != FALSE) {
                        gTitleScene->mSelectedIndex = TITLE_ENTRY_RECORD;
                    } else {
                        gTitleScene->mSelectedIndex = TITLE_ENTRY_OPTION;
                    }
                    break;
                case TITLE_ENTRY_WL_MENU:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_FIRST;
                    break;
                case TITLE_ENTRY_WIFI_MENU:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_WL_MENU;
                    break;
                case TITLE_ENTRY_OPTION:
                case TITLE_ENTRY_RECORD:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_WIFI_MENU;
                    break;
            }
            StartSoundOncePerFrame(0);
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case TITLE_ENTRY_FIRST:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_WL_MENU;
                    break;
                case TITLE_ENTRY_WL_MENU:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_WIFI_MENU;
                    break;
                case TITLE_ENTRY_WIFI_MENU:
                    if (gTitleScene->mPreferRecordEntry != FALSE) {
                        gTitleScene->mSelectedIndex = TITLE_ENTRY_RECORD;
                    } else {
                        gTitleScene->mSelectedIndex = TITLE_ENTRY_OPTION;
                    }
                    break;
                case TITLE_ENTRY_OPTION:
                case TITLE_ENTRY_RECORD:
                    gTitleScene->mSelectedIndex = TITLE_ENTRY_FIRST;
                    break;
            }
            StartSoundOncePerFrame(0);
            gTitleScene->mNoInputFrames = 0;
        } else if (TitleIsSlotPairNew(slotIndex) != 0) {
            u32 pointX = TitleGetSlotPairX(slotIndex);
            u32 pointY = TitleGetSlotPairY(slotIndex);
            previousIndex = gTitleScene->mSelectedIndex;
            rectIndex = FindRectContainingPoint(pointX, pointY, gTitleScene->mTitleSBnbl);
            if (rectIndex != -1) {
                if (previousIndex == rectIndex) {
                    gTitleScene->mStartedOnSelected = TRUE;
                }
                gTitleScene->mSelectedIndex = rectIndex;
                SetTitleState(TITLE_STATE_SELECT_PRESS, 8);
                StartTitleSelectedSound();
            }
        } else {
            s32 noInputFrameLimit = GetTitleNoInputFrameLimit();
            gTitleScene->mNoInputFrames++;
            if (gTitleScene->mNoInputFrames > noInputFrameLimit) {
                if (IsSeqVariableChanged(0) != 0) {
                    sceneNumbers->mNextScene = SCENE_RACE;
                    SetNextDemoRace(gTitleScene->mCharacterKartPicks);
                }
            }
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off

#pragma thumb on
u32 TitleSlideOutReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off

u32 TitleGetCellLayoutCount(LayoutEntryTable *cellLayout) {
    return cellLayout->mCount;
}

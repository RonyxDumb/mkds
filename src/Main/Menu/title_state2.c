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
#include "Main/MapObjects/data_0217b000.h"
#include "Main/System/init_after_startup.h"

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

void UpdateTitleState2(SceneNumbers *sceneNumbers) {
    u32 slotIndex;
    s32 previousIndex;
    s32 rectIndex;

    if (sceneNumbers != NULL) {
        slotIndex = GetTitleInputSlot();
        if (TitleGetNewBits(slotIndex, PAD_KEY_A) != 0) {
            SetTitleState(4, 8);
            StartTitleSelectedSound();
            gTitleScene->mStartedOnSelected = TRUE;
        } else if (GetNewOrRepeatBits(slotIndex, (PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 3:
                    gTitleScene->mSelectedIndex = 4;
                    gTitleScene->mPreferEntry4 = TRUE;
                    StartSoundOncePerFrame(0);
                    break;
                case 4:
                    gTitleScene->mSelectedIndex = 3;
                    gTitleScene->mPreferEntry4 = FALSE;
                    StartSoundOncePerFrame(0);
                    break;
            }
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 0:
                    if (gTitleScene->mPreferEntry4 != FALSE) {
                        gTitleScene->mSelectedIndex = 4;
                    } else {
                        gTitleScene->mSelectedIndex = 3;
                    }
                    break;
                case 1:
                    gTitleScene->mSelectedIndex = 0;
                    break;
                case 2:
                    gTitleScene->mSelectedIndex = 1;
                    break;
                case 3:
                case 4:
                    gTitleScene->mSelectedIndex = 2;
                    break;
            }
            StartSoundOncePerFrame(0);
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 0:
                    gTitleScene->mSelectedIndex = 1;
                    break;
                case 1:
                    gTitleScene->mSelectedIndex = 2;
                    break;
                case 2:
                    if (gTitleScene->mPreferEntry4 != FALSE) {
                        gTitleScene->mSelectedIndex = 4;
                    } else {
                        gTitleScene->mSelectedIndex = 3;
                    }
                    break;
                case 3:
                case 4:
                    gTitleScene->mSelectedIndex = 0;
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
                SetTitleState(4, 8);
                StartTitleSelectedSound();
            }
        } else {
            s32 noInputFrameLimit = GetTitleNoInputFrameLimit();
            gTitleScene->mNoInputFrames++;
            if (gTitleScene->mNoInputFrames > noInputFrameLimit) {
                if (IsSeqVariableChanged(0) != 0) {
                    sceneNumbers->mNextScene = 2;
                    SetNextDemoRace(gTitleScene->mCharacterKartPicks);
                }
            }
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off

#pragma thumb on
u32 TitleState3ReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off

u32 TitleGetCellLayoutCount(LayoutEntryTable *cellLayout) {
    return (*OFFSET_PTR(const u16, cellLayout, 6));
}

#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_020aca24.h"

#include "Main/Unknown/code_020acbf0.h"
#include "Main/Unknown/code_020acbf8.h"
#include "Main/Unknown/code_020acdc4.h"
#include "Main/Unknown/code_020acdec.h"
#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acde4.h"
#include "Main/Unknown/code_020ace0c.h"

u32 title_spi_getTpX(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 0));
}

u32 title_input_getTpXById(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 functionAddress;
    slotsAddress = (u32) &gInputUnits;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    functionAddress = (u32) &title_spi_getTpX;
    value0 = (value1) + (0x48u);
    value0 = title_spi_getTpX(value0);
    return value0;
}

u32 title_spi_getTpY(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 2));
}

u32 title_input_getTpYById(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 functionAddress;
    slotsAddress = (u32) &gInputUnits;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    functionAddress = (u32) &title_spi_getTpY;
    value0 = (value1) + (0x48u);
    value0 = title_spi_getTpY(value0);
    return value0;
}

#pragma thumb on

void title_mainStateRender(Unk020aca24 *a) {
    u32 slotIndex;
    s32 previousIndex;
    s32 rectIndex;

    if (a != NULL) {
        slotIndex = title_input_getMasterInputUnitId();
        if (title_input_isSetPadTrigById(slotIndex, PAD_KEY_A) != 0) {
            title_gotoState(4, 8);
            title_playActivationSound();
            sTitleSceneState->mSelectedPressed = TRUE;
        } else if (mutil_checkKeys(slotIndex, (PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
            switch (sTitleSceneState->mSelectedIndex) {
                case 3:
                    sTitleSceneState->mSelectedIndex = 4;
                    sTitleSceneState->mPreferEntry4 = TRUE;
                    sfx_2105AC0(0);
                    break;
                case 4:
                    sTitleSceneState->mSelectedIndex = 3;
                    sTitleSceneState->mPreferEntry4 = FALSE;
                    sfx_2105AC0(0);
                    break;
            }
            sTitleSceneState->mNoInputFrames = 0;
        } else if (mutil_checkKeys(slotIndex, PAD_KEY_UP) != 0) {
            switch (sTitleSceneState->mSelectedIndex) {
                case 0:
                    if (sTitleSceneState->mPreferEntry4 != FALSE) {
                        sTitleSceneState->mSelectedIndex = 4;
                    } else {
                        sTitleSceneState->mSelectedIndex = 3;
                    }
                    break;
                case 1:
                    sTitleSceneState->mSelectedIndex = 0;
                    break;
                case 2:
                    sTitleSceneState->mSelectedIndex = 1;
                    break;
                case 3:
                case 4:
                    sTitleSceneState->mSelectedIndex = 2;
                    break;
            }
            sfx_2105AC0(0);
            sTitleSceneState->mNoInputFrames = 0;
        } else if (mutil_checkKeys(slotIndex, PAD_KEY_DOWN) != 0) {
            switch (sTitleSceneState->mSelectedIndex) {
                case 0:
                    sTitleSceneState->mSelectedIndex = 1;
                    break;
                case 1:
                    sTitleSceneState->mSelectedIndex = 2;
                    break;
                case 2:
                    if (sTitleSceneState->mPreferEntry4 != FALSE) {
                        sTitleSceneState->mSelectedIndex = 4;
                    } else {
                        sTitleSceneState->mSelectedIndex = 3;
                    }
                    break;
                case 3:
                case 4:
                    sTitleSceneState->mSelectedIndex = 0;
                    break;
            }
            sfx_2105AC0(0);
            sTitleSceneState->mNoInputFrames = 0;
        } else if (title_input_isValidPenDownEventById(slotIndex) != 0) {
            u32 pointX = title_input_getTpXById(slotIndex);
            u32 pointY = title_input_getTpYById(slotIndex);
            previousIndex = sTitleSceneState->mSelectedIndex;
            rectIndex = FindRectContainingPoint(pointX, pointY, sTitleSceneState->mTitleSBnbl);
            if (rectIndex != -1) {
                if (previousIndex == rectIndex) {
                    sTitleSceneState->mSelectedPressed = TRUE;
                }
                sTitleSceneState->mSelectedIndex = rectIndex;
                title_gotoState(4, 8);
                title_playActivationSound();
            }
        } else {
            s32 noInputFrameLimit = sndvar_getDemoRaceDelay();
            sTitleSceneState->mNoInputFrames++;
            if (sTitleSceneState->mNoInputFrames > noInputFrameLimit) {
                if (sndvar_getVarField4IsZero(0) != 0) {
                    a->mNextScene = 2;
                    SetNextDemoRace(sTitleSceneState->mCharacterKartPicks);
                }
            }
        }
    }
    title_renderUI();
}

#pragma thumb off

#pragma thumb on
u32 title_buttonsOutVblank(u32 value) {
    u32 value0 = value;
    u32 functionAddress;
    functionAddress = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 title_jn_ui_getBnclElementCount(Unk0201ea30 *p0) {
    return (*OFFSET_PTR(const u16, p0, 6));
}

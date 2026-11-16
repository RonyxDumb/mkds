#include "Main/Unknown/code_020019b0.h"
#include "registers.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02001080.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200eddc.h"
#include "code_0214a390.h"
#include "code_0214b824.h"

void logo_loadBg(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName) {
    g2du_unpackPaletteData(&files->mPalette, arc_getSceneArcFile(paletteFileName));
    DC_StoreRange(files->mPalette->mData, files->mPalette->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    } else {
        GXS_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    }
    g2du_unpackCharacterData(&files->mChars, arc_getSceneArcFile(charsFileName));
    DC_StoreRange(files->mChars->mData, files->mChars->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    } else {
        GXS_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    }
    g2du_unpackScreenData(&files->mScreenMap, arc_getSceneArcFile(screenMapFileName));
    DC_StoreRange(files->mScreenMap->mData, files->mScreenMap->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    } else {
        GXS_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    }
}

void logo_create(void *heap) {
    Unk02125de0Arg arg;
    u8 *displaySettings;
    logo_sLogoState = heap_alloc(heap, 60);
    displaySettings = dc_createDisplayConfig(heap, logo_sDisplayConfigBase);
    dc_setBg1Config(displaySettings + 0x28, 1, 0, 0, 0, 0, 1, 0);
    dc_setBg1Config(displaySettings + 0x70, 1, 0, 0, 0, 0, 2, 0);
    dc_setDisplayConfig(displaySettings);
    logo_loadBg(&logo_sLogoState->mMainBg, 1, aLogo_r_ninte_1, aLogo_r_ninte_2, aLogo_r_nintend);
    logo_loadBg(&logo_sLogoState->mSubBg, 0, aAllrightsres_1, aAllrightsres_2, aAllrightsreser);
    sm_init(&logo_sLogoState->mStateMachine, logo_sStates, 12, NULL);
    logo_sLogoState->mUnk_2c_0 = 0;
    logo_sLogoState->mState0Frames = 0;
    logo_sLogoState->mCommonMessages = arc_get2dArcFile(aCommon_bmg);
    arg.mUnk_00 = TRUE;
    arg.mUnk_04 = m2d_getFont(1);
    arg.mUnk_08 = 0;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = FALSE;
    arg.mUnk_18 = NULL;
    arg.mUnk_1c = FALSE;
    arg.mUnk_20 = FALSE;
    arg.mUnk_24 = 0;
    arg.mUnk_0c = 1;
    gmenu_unpackData();
    gmenu_init(heap, &arg);
}

void logo_finish(void) {
    s32 outputEffect;
    s32 soundMode;
    outputEffect = 0;
    logo_sLogoState = NULL;
    soundMode = gSaveData->mFirstBlock->mSoundMode;
    switch (soundMode) {
        case SOUND_MODE_STEREO:
            break;
        case SOUND_MODE_HEADPHONES:
            outputEffect = 2;
            break;
        case SOUND_MODE_SURROUND:
        default:
            outputEffect = 1;
            break;
    }
    sound_2108E94(outputEffect);
    gmenu_finish();
}

void logo_vblank(void) {
    s32 brightness;
    s32 frames;
    brightness = 0;
    gmenu_vblank();
    frames = logo_sLogoState->mState0Frames;
    if (frames > 90) {
        brightness = (-(frames - 90) * 16) / 30;
    }
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 2, brightness);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 2, brightness);
}

void logo_render(SceneNumbersView *sceneNumbers) {
    sm_execute(&logo_sLogoState->mStateMachine);
    if (sceneNumbers != NULL && logo_sLogoState->mStateMachine.mState == 11) {
        sceneNumbers->mNextScene = 0;
    }
    gmenu_render();
}

void logo_fadeInStateInit(void) {
    savd_loadAsync();
    logo_sLogoState->mUnk_2c_1 = 0;
}

void logo_fadeInStateUpdate(void) {
    s32 slotIndex;
    StateMachine *stateMachine;
    logo_sLogoState->mState0Frames = logo_sLogoState->mState0Frames + 1;
    if (logo_sLogoState->mState0Frames > 120) {
        stateMachine = &logo_sLogoState->mStateMachine;
        stateMachine->mNextState = 1;
        stateMachine->mNextStateRequested = 1;
    }
    slotIndex = input_getDirectInputUnitId();
    if ((gInputUnits[slotIndex].mBits & 0xf03) != 0xf03) {
        return;
    }
    logo_sLogoState->mUnk_2c_0 = 1;
}

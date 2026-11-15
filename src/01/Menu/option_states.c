#include "01/Menu/option_states.h"

#include "01/code_02193000.h"
#include "01/Menu/option_hensyu_menu.h"
#include "01/Menu/option_embrem_select.h"
#include "01/unk_021a9000.h"
#include "Main/System/heap.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Menu/message_screen.h"
#include "gx_bgcnt.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Menu/menu_shared_clear.h"

OptionStates *gOptionStates;

void ClearOptionStateCallbacks(void) {
    gOptionStates->mCallbacks.mInit = NULL;
    gOptionStates->mCallbacks.mRelease = NULL;
    gOptionStates->mCallbacks.mAdvance = NULL;
    gOptionStates->mCallbacks.mPostUpdate = NULL;
}

void LoadOptionData(void) {
    LoadedPartPointer loadedPartPointer;
    LoadNcgrData(&loadedPartPointer.mNcgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LoadNscrData(&loadedPartPointer.mNscr, FindSceneFile("Option_top_menu_m.nscr"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    LoadNcgrData(&loadedPartPointer.mNcgr, FindSceneFile("Option_select_menu_m_b.ncgr"));
    LoadNscrData(&loadedPartPointer.mNscr, FindSceneFile("Option_select_menu_m.nscr"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_select_menu_m_b.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("Option_top_menu_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("Option_top_menu_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_top_menu_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("Option_hensyu_menu_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("Option_hensyu_menu_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_hensyu_menu_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("Option_select_menu_m.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("Option_select_menu_m.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_select_menu_m_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("Option_select_menu_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("Option_select_menu_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_select_menu_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("Option_embrem_select_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("Option_embrem_select_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("Option_embrem_select_s_o.nclr"));
}

void SetupOptionBackgrounds(void) {
    u32 visiblePlaneBits;
    vu32 firstFillValue;
    vu32 secondFillValue;
    void *bg0Screen;
    void *bg1Screen;
    visiblePlaneBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    visiblePlaneBits |= 1;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (visiblePlaneBits << 8);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x9000;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x9204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 1;
    bg0Screen = (void *) G2S_GetBG0ScrPtr();
    firstFillValue = 0;
    MIi_CpuClearFast(firstFillValue, bg0Screen, 0x1000);
    bg1Screen = (void *) G2S_GetBG1ScrPtr();
    secondFillValue = 0;
    MIi_CpuClearFast(secondFillValue, bg1Screen, 0x1000);
}

void InitOptionStates(void *heap, s16 previousScene) {
    SceneTextInitParams sceneTextParams;
    gOptionStates = HeapAlloc(heap, sizeof(OptionStates));
    gOptionStates->mHeap = heap;
    gOptionStates->mSceneDisplaySettings = CreateSceneDisplaySettings(heap);
    SetupOptionBackgrounds();
    InitLinkLevelIcons(heap, GetOptionFirstBuffer());
    sceneTextParams.mUseTxtSystem = TRUE;
    sceneTextParams.mTxtSystemFont = GetFontByIndex(1);
    sceneTextParams.mUseCanvas1 = 0;
    sceneTextParams.mUseCanvas2 = 1;
    sceneTextParams.mUseCanvas3 = 0;
    sceneTextParams.mUseSelectChoises = FALSE;
    sceneTextParams.mSelectChoisesFont = NULL;
    sceneTextParams.mUseSelectReturn = TRUE;
    sceneTextParams.mUseBackScreen = TRUE;
    sceneTextParams.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &sceneTextParams);
    gOptionStates->mStateHeap = CreateExpHeapFromMaxFree(gOptionStates->mHeap);
    LoadOptionData();
    ClearOptionStateCallbacks();
    gOptionStates->mNextScene = -1;
    switch (previousScene) {
        case SCENE_TITLE:
            gOptionStates->mPrevState = OPTION_STATE_SCENE_TITLE;
            gOptionStates->mState = OPTION_STATE_TOP_MENU;
            RegisterOptionTopMenuCallbacks();
            break;
        case SCENE_KEYBOARD:
            gOptionStates->mPrevState = OPTION_STATE_SCENE_KEYBOARD;
            gOptionStates->mState = OPTION_STATE_HENSYU_MENU;
            RegisterOptionHensyuMenuCallbacks();
            break;
        case SCENE_EMBLEM:
            gOptionStates->mPrevState = OPTION_STATE_SCENE_EMBLEM;
            if (gMenuShared->mOptionReturnsToEmbremSelect == FALSE) {
                gOptionStates->mState = OPTION_STATE_HENSYU_MENU;
                RegisterOptionHensyuMenuCallbacks();
            } else {
                gOptionStates->mState = OPTION_STATE_EMBREM_SELECT;
                RegisterOptionEmbremSelectCallbacks();
            }
            break;
    }
    gOptionStates->mNextState = OPTION_STATE_NONE;
    gOptionStates->mCallbacks.mInit(gOptionStates->mStateHeap);
}

void ReleaseOptionStates(void) {
    if (gOptionStates->mCallbacks.mRelease != NULL) {
        gOptionStates->mCallbacks.mRelease();
    }
    ClearOptionStateCallbacks();
    ClearLinkLevelIconsPointer();
    ReleaseSceneText();
    gOptionStates = NULL;
}

void AdvanceOptionStates(void) {
    if (gOptionStates->mCallbacks.mAdvance != NULL) {
        gOptionStates->mCallbacks.mAdvance();
    }
    if (gOptionStates->mNextState != OPTION_STATE_NONE) {
        gOptionStates->mCallbacks.mRelease();
        ClearOptionStateCallbacks();
        HeapDestroy(gOptionStates->mStateHeap);
        gOptionStates->mStateHeap = CreateExpHeapFromMaxFree(gOptionStates->mHeap);
        switch (gOptionStates->mNextState) {
            case OPTION_STATE_TOP_MENU:
                RegisterOptionTopMenuCallbacks();
                break;
            case OPTION_STATE_SELECT_MENU:
                RegisterOptionSelectMenuCallbacks();
                break;
            case OPTION_STATE_HENSYU_MENU:
                RegisterOptionHensyuMenuCallbacks();
                break;
            case OPTION_STATE_EMBREM_SELECT:
                RegisterOptionEmbremSelectCallbacks();
                break;
        }
        gOptionStates->mPrevState = gOptionStates->mState;
        gOptionStates->mState = gOptionStates->mNextState;
        gOptionStates->mNextState = OPTION_STATE_NONE;
        if (gOptionStates->mCallbacks.mInit != NULL) {
            gOptionStates->mCallbacks.mInit(gOptionStates->mStateHeap);
        }
    }
    AdvanceSceneText();
    AdvanceLinkLevelIcons();
}

void WriteOptionStatesRegisters(void) {
    if (gOptionStates->mCallbacks.mPostUpdate != NULL) {
        (*gOptionStates->mCallbacks.mPostUpdate)();
    }
    WriteSceneTextRegisters();
}

void SetOptionStateCallbacks(OptionStateCallbacks *callbacks) {
    gOptionStates->mCallbacks = *callbacks;
}

void RequestOptionState(u32 nextState) {
    gOptionStates->mNextState = nextState;
}

u32 GetOptionPrevState(void) {
    return gOptionStates->mPrevState;
}

int GetOptionNextScene(void) {
    return gOptionStates->mNextScene;
}

void RequestOptionNextScene(u16 nextScene) {
    gOptionStates->mNextScene = nextScene;
}

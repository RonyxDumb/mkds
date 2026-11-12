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
    visiblePlaneBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    visiblePlaneBits |= 1;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (visiblePlaneBits << 8);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9000;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    bg0Screen = (void *) G2S_GetBG0ScrPtr();
    firstFillValue = 0;
    MIi_CpuClearFast(firstFillValue, bg0Screen, 0x1000);
    bg1Screen = (void *) G2S_GetBG1ScrPtr();
    secondFillValue = 0;
    MIi_CpuClearFast(secondFillValue, bg1Screen, 0x1000);
}

void InitOptionStates(void *heap, s16 a) {
    SceneTextInitParams sceneTextParams;
    gOptionStates = HeapAlloc(heap, 0x2c);
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
    switch (a) {
        case 0:
            gOptionStates->mPrevState = 4;
            gOptionStates->mState = 0;
            RegisterOptionTopMenuCallbacks();
            break;
        case 14:
            gOptionStates->mPrevState = 5;
            gOptionStates->mState = 2;
            RegisterOptionHensyuMenuCallbacks();
            break;
        case 3:
            gOptionStates->mPrevState = 6;
            if (gMenuShared->mOptionReturnsToEmbremSelect == FALSE) {
                gOptionStates->mState = 2;
                RegisterOptionHensyuMenuCallbacks();
            } else {
                gOptionStates->mState = 3;
                RegisterOptionEmbremSelectCallbacks();
            }
            break;
    }
    gOptionStates->mNextState = -1;
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
    if (gOptionStates->mNextState != -1) {
        gOptionStates->mCallbacks.mRelease();
        ClearOptionStateCallbacks();
        HeapDestroy(gOptionStates->mStateHeap);
        gOptionStates->mStateHeap = CreateExpHeapFromMaxFree(gOptionStates->mHeap);
        switch (gOptionStates->mNextState) {
            case 0:
                RegisterOptionTopMenuCallbacks();
                break;
            case 1:
                RegisterOptionSelectMenuCallbacks();
                break;
            case 2:
                RegisterOptionHensyuMenuCallbacks();
                break;
            case 3:
                RegisterOptionEmbremSelectCallbacks();
                break;
        }
        gOptionStates->mPrevState = gOptionStates->mState;
        gOptionStates->mState = gOptionStates->mNextState;
        gOptionStates->mNextState = -1;
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

void SetOptionStateCallbacks(UnkFunc **callbacks) {
    gOptionStates->mCallbacks = *(OptionStateCallbacks *) callbacks;
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

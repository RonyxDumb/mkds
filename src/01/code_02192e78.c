#include "01/code_02192e78.h"

#include "01/code_02193000.h"
#include "01/code_02199964.h"
#include "01/code_0219d5dc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214a2a0.h"
#include "code_0214a2f4.h"
#include "code_0214d018.h"
#include "registers.h"

OptionStates *gOptionStates;

void ClearOptionStateCallbacks(void) {
    gOptionStates->mCallbacks.mInit = NULL;
    gOptionStates->mCallbacks.mRelease = NULL;
    gOptionStates->mCallbacks.mAdvance = NULL;
    gOptionStates->mCallbacks.mUnk_0c = NULL;
}

void LoadOptionData(void) {
    LoadedPartPointer v;
    LoadNcgrData(&v.mNcgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LoadNscrData(&v.mNscr, FindSceneFile("Option_top_menu_m.nscr"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    LoadNcgrData(&v.mNcgr, FindSceneFile("Option_select_menu_m_b.ncgr"));
    LoadNscrData(&v.mNscr, FindSceneFile("Option_select_menu_m.nscr"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_m_b.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_top_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_top_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_top_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_hensyu_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_hensyu_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_hensyu_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_select_menu_m.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_select_menu_m.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_m_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_select_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_select_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_embrem_select_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_embrem_select_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_embrem_select_s_o.nclr"));
}

void func_ov001_021930ac(void) {
    u32 t;
    vu32 a;
    vu32 b;
    void *d1;
    void *d2;
    t = (reg_GX_DISPCNT & 0x1f00) >> 8;
    t |= 1;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (t << 8);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9000;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    d1 = (void *) G2S_GetBG0ScrPtr();
    a = 0;
    MIi_CpuClearFast(a, d1, 0x1000);
    d2 = (void *) G2S_GetBG1ScrPtr();
    b = 0;
    MIi_CpuClearFast(b, d2, 0x1000);
}

void InitOptionStates(void *heap, s16 a) {
    SceneTextInitParams arg;
    gOptionStates = HeapAlloc(heap, 0x2c);
    gOptionStates->mHeap = heap;
    gOptionStates->mUnk_28 = CreateSceneDisplaySettings(heap);
    func_ov001_021930ac();
    InitLinkLevelIcons(heap, GetOptionFirstBuffer());
    arg.mUseTxtSystem = TRUE;
    arg.mTxtSystemFont = GetFontByIndex(1);
    arg.mUseCanvas1 = 0;
    arg.mUseCanvas2 = 1;
    arg.mUseCanvas3 = 0;
    arg.mUseSelectChoises = FALSE;
    arg.mSelectChoisesFont = NULL;
    arg.mUseSelectReturn = TRUE;
    arg.mUseBackScreen = TRUE;
    arg.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &arg);
    gOptionStates->mStateHeap = CreateExpHeapFromMaxFree(gOptionStates->mHeap);
    LoadOptionData();
    ClearOptionStateCallbacks();
    gOptionStates->mUnk_14 = -1;
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
            if (gMenuShared->mUnk_18 == FALSE) {
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

void func_ov001_02192f8c(void) {
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

void func_ov001_02192ec4(void) {
    if (gOptionStates->mCallbacks.mUnk_0c != NULL) {
        (*gOptionStates->mCallbacks.mUnk_0c)();
    }
    WriteSceneTextRegisters();
}

void SetOptionStateCallbacks(UnkFunc **a) {
    gOptionStates->mCallbacks = *(OptionStateCallbacks *) a;
}

void RequestOptionState(u32 a) {
    gOptionStates->mNextState = a;
}

u32 GetOptionPrevState(void) {
    return gOptionStates->mPrevState;
}

int func_ov001_02192e84(void) {
    return gOptionStates->mUnk_14;
}

void func_ov001_02192e78(u16 a) {
    gOptionStates->mUnk_14 = a;
}

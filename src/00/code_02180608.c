#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_02180814.h"

#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_02180c04.h"
#include "00/code_02181714.h"
#include "00/code_021848c8.h"
#include "00/code_021849e0.h"
#include "00/code_02184aa4.h"
#include "00/code_021857b8.h"
#include "00/code_02184ba8.h"
#include "00/code_02185344.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02025f80.h"

void ClearWiFiStateCallbacks(void) {
    gWiFiStates->mCallbacks.mInit = NULL;
    gWiFiStates->mCallbacks.mRelease = NULL;
    gWiFiStates->mCallbacks.mAdvance = NULL;
    gWiFiStates->mCallbacks.mWriteRegisters = NULL;
}

void LoadWiFiMenuSceneData(void) {
    LoadedPartPointer loadedPartPointer;
    LoadNcgrData(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_VS_setting_s_b.ncgr"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_VS_setting_s_b.nclr"));
    LoadNscrData(&loadedPartPointer.mNscr, FindSceneFile("WiFi_VS_s_setting.nscr"));
    LoadNcgrData(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_VS_matching_s_b.ncgr"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_VS_matching_s_b.nclr"));
    LoadNscrData(&loadedPartPointer.mNscr, FindSceneFile("WiFi_VS_matching_s.nscr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_top_menu_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("WiFi_top_menu_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_top_menu_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_VS_matching_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("WiFi_VS_matching_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_VS_matching_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_aikotoba_s.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("WiFi_aikotoba_s.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_aikotoba_s_o.nclr"));
    LoadNcgrData2(&loadedPartPointer.mNcgr, FindSceneFile("WiFi_aikotoba_check_m.nce.ncgr"));
    LoadNcerData(&loadedPartPointer.mNcer, FindSceneFile("WiFi_aikotoba_check_m.nce.ncer"));
    LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("WiFi_aikotoba_check_m_o.nclr"));
    LoadSelectCharacterData();
    LoadSelectKartData();
    LoadWiFiVSCourseSelectFiles();
    LoadPlayerEntryListFiles();
}

void InitWiFiStates(void *heap, s32 sceneNumber) {
    SceneTextInitParams sceneTextInitParams;
    StateMachine *sessionStateMachine;
    gWiFiStates = HeapAlloc(heap, 0x3c);
    gWiFiStates->mHeap = heap;
    gWiFiStates->mUnk_14 = 0;
    CreateRaceSetupCopy(heap);
    gWiFiStates->mUnk_2c = CreateWiFiStatesDisplaySettings(heap);
    InitLinkLevelIcons(heap, GetWiFiMenuMainOamList());
    sceneTextInitParams.mUseTxtSystem = TRUE;
    sceneTextInitParams.mTxtSystemFont = GetFontByIndex(1);
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 0;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = FALSE;
    sceneTextInitParams.mSelectChoisesFont = NULL;
    sceneTextInitParams.mUseSelectReturn = TRUE;
    sceneTextInitParams.mUseBackScreen = TRUE;
    sceneTextInitParams.mBackScreenKind = 1;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &sceneTextInitParams);
    LoadWiFiMenuSceneData();
    InitPlayerEntryList(heap, GetWiFiMenuMainOamList());
    InitKartModelMenuWithParamFiles(GetHeap(GetCurrentHeapCall()));
    RequestKartModelMenuCharacter(-1);
    RequestKartModelMenuKart(-1);
    ReleaseKartModelLoadSlotsForScene();
    gWiFiStates->mStateHeap = CreateExpHeapFromMaxFree(heap);
    ClearWiFiStateCallbacks();
    gWiFiStates->mNextScene = -1;
    if (gMenuShared->mWiFiTopMenuRequested != FALSE) {
        sceneNumber = 0;
        gMenuShared->mWiFiTopMenuRequested = FALSE;
    }
    switch (sceneNumber) {
        case 0:
            gWiFiStates->mPrevState = 10;
            gWiFiStates->mState = 1;
            RegisterWiFiTopMenuCallbacks();
            ResetWiFiSessionToOff();
            gMenuShared->mWiFiMenuStartKind = 0;
            break;
        case 12:
            gWiFiStates->mPrevState = 13;
            gWiFiStates->mState = 1;
            RegisterWiFiTopMenuCallbacks();
            break;
        case 2:
        case 10:
            switch (gMenuShared->mWiFiMenuStartKind) {
                case 0:
                    gWiFiStates->mState = 1;
                    RegisterWiFiTopMenuCallbacks();
                    break;
                case 1:
                    sessionStateMachine = &gWiFiSession->mStateMachine;
                    sessionStateMachine->mNextState = 2;
                    sessionStateMachine->mNextStateRequested = 1;
                    gWiFiStates->mState = 2;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case 2:
                    SetupWiFiSession(1);
                    gWiFiStates->mState = 4;
                    RegisterSelectCharacterCallbacks();
                    break;
                case 3:
                    SetupWiFiSession(2);
                    CopyEntriesToRaceSetupCopy();
                    gWiFiStates->mState = 6;
                    RegisterWiFiVSCourseSelectCallbacks();
                    break;
            }
            break;
        case 14:
            gWiFiStates->mPrevState = 11;
            gWiFiStates->mState = 8;
            RegisterWiFiAikotobaCallbacks();
            break;
        case 8:
            switch (gMenuShared->mWiFiScene8StartKind) {
                case 0:
                    gWiFiStates->mPrevState = 14;
                    gWiFiStates->mState = 2;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case 1:
                    gWiFiStates->mPrevState = 14;
                    gWiFiStates->mState = 8;
                    RegisterWiFiAikotobaCallbacks();
                    break;
            }
            break;
    }
    gWiFiStates->mNextState = -1;
    gWiFiStates->mCallbacks.mInit(gWiFiStates->mStateHeap);
    gMenuShared->mResultArchiveDl = 1;
}

void ReleaseWiFiStates(void) {
    if (gWiFiStates->mCallbacks.mRelease != NULL) {
        gWiFiStates->mCallbacks.mRelease();
    }
    ClearWiFiStateCallbacks();
    ReleasePlayerEntryList();
    ClearLinkLevelIconsPointer();
    ReleaseSceneText();
    gWiFiStates = NULL;
}

void AdvanceWiFiStates(void) {
    if (gWiFiStates->mCallbacks.mAdvance != NULL) {
        gWiFiStates->mCallbacks.mAdvance();
    }
    if (gWiFiStates->mNextState != -1) {
        gWiFiStates->mCallbacks.mRelease();
        ClearWiFiStateCallbacks();
        HeapDestroy(gWiFiStates->mStateHeap);
        gWiFiStates->mStateHeap = CreateExpHeapFromMaxFree(gWiFiStates->mHeap);
        switch (gWiFiStates->mNextState) {
            case 0:
                RegisterWiFiLoginMenuCallbacks();
                break;
            case 1:
                RegisterWiFiTopMenuCallbacks();
                break;
            case 2:
                RegisterWiFiVSSettingCallbacks();
                break;
            case 3:
                RegisterWiFiVSMatchingCallbacks();
                break;
            case 4:
                RegisterSelectCharacterCallbacks();
                break;
            case 5:
                RegisterSelectKartCallbacks();
                break;
            case 6:
                RegisterWiFiVSCourseSelectCallbacks();
                break;
            case 7:
                RegisterWiFiConnectionLostCallbacks();
                break;
            case 8:
                RegisterWiFiAikotobaCallbacks();
                break;
            case 9:
                RegisterWiFiAikotobaCheckCallbacks();
                break;
        }
        gWiFiStates->mPrevState = gWiFiStates->mState;
        gWiFiStates->mState = gWiFiStates->mNextState;
        gWiFiStates->mNextState = -1;
        if (gWiFiStates->mCallbacks.mInit != NULL) {
            gWiFiStates->mCallbacks.mInit(gWiFiStates->mStateHeap);
        }
    }
    AdvanceSceneText();
    AdvanceLinkLevelIcons();
    gWiFiStates->mUnk_14++;
    if (gWiFiStates->mUnk_14 > 0) {
        gWiFiStates->mUnk_14 = 0;
    }
}

void WriteWiFiStatesRegisters(void) {
    if (gWiFiStates->mCallbacks.mWriteRegisters != NULL) {
        gWiFiStates->mCallbacks.mWriteRegisters();
    }
    WriteSceneTextRegisters();
}

void SetWiFiStateCallbacks(const WiFiStateCallbacks *callbacks) {
    gWiFiStates->mCallbacks = *callbacks;
}

void RequestWiFiState(s32 nextState) {
    u32 requestedState = nextState;
    u32 wiFiStatesAddress;
    wiFiStatesAddress = (u32) &gWiFiStates;
    gWiFiStates->mNextState = requestedState;
}

s32 GetWiFiPrevState(void) {
    return gWiFiStates->mPrevState;
}

u32 GetWiFiNextScene(void) {
    return (gWiFiStates->mNextScene);
}

void SetWiFiNextScene(u32 nextScene) {
    gWiFiStates->mNextScene = (u16) nextScene;
}

u32 IsWiFiStatesCounterNotNegative(void) {
    if (0 <= gWiFiStates->mUnk_14) {
        return TRUE;
    }
    return FALSE;
}

u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex) {
    u32 messageIndices[4] = {2, 3, 4, 5};
    return messageIndices[settingIndex];
}

u32 GetWiFiVSSettingIndex(void) {
    return gWiFiStates->mWiFiVSSettingIndex;
}

void SetWiFiVSSettingIndex(u32 settingIndex) {
    gWiFiStates->mWiFiVSSettingIndex = settingIndex;
}

s32 GetWiFiVSSettingFlag(void) {
    u32 vsSettingFlag;
    vsSettingFlag = gWiFiStates->mUnk_34;
    return vsSettingFlag;
}

void SetWiFiVSSettingFlag(s32 flag) {
    u32 flagValue = flag;
    u32 statesPointerAddress;
    statesPointerAddress = (u32) &gWiFiStates;
    gWiFiStates->mUnk_34 = flagValue;
}

BOOL IsWiFiSessionOffOutsideLogin(void) {
    BOOL valid = TRUE;
    if (gWiFiStates != NULL && gWiFiStates->mState == 0) {
        valid = FALSE;
    }
    if (gWiFiSession->mStateMachine.mState == 0 && valid != FALSE) {
        return TRUE;
    }
    return FALSE;
}

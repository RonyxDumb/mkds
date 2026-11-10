#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_0219e0a8.h"
#include "code_020176c0.h"
#include "Main/Unknown/code_02044618.h"

void UpdateRaceScene(SceneNumbers *sceneNumbers, u32 sceneFrames) {
    RaceSetup *raceSetup;
    u32 c;
    if (IsDataSharingIncomplete() == 0) {
        if (IsInputOpenDuringRace() == 0) {
            if (sceneNumbers != NULL) {
                if (RaceSceneGetCurrentMode() == 5) {
                    c = GetWiFiRaceSyncPickedValue();
                } else {
                    c = GetChoisesSPickedValue();
                }
                if (c != 0) {
                    SetPickedValue(c);
                    SetNextSceneFromPickedValue(sceneNumbers, c);
                }
                switch (GetCurrentRaceKind()) {
                    case RACE_KIND_DEMO:
                        c = 0;
                        if (sceneFrames > GetDemoRaceFrameLimit()) {
                            if (IsSeqVariableChanged(1) != 0) {
                                c = 1;
                                SetDemoEndedByInput(0);
                            }
                        }
                        if (c == 0) {
                            if (GetDownBits(GetRaceSceneInputSlot(), 0x2fff) != 0) {
                                c = 1;
                                StartRaceSceneSound(5);
                                SetDemoEndedByInput(1);
                            } else if (RaceSceneSlotHasPairOrLost(GetRaceSceneInputSlot()) != 0) {
                                c = 1;
                                StartRaceSceneSound(5);
                                SetDemoEndedByInput(1);
                            }
                        }
                        if (c != 0) {
                            sceneNumbers->mNextScene = 0;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case 4:
                        if (IsCameraChainEnded() != 0 ||
                            (sceneFrames > 0x5a && (GetDownBits(GetRaceSceneInputSlot(), 0xc0f) != 0 ||
                                                    RaceSceneIsSlotPairNew(GetRaceSceneInputSlot()) != 0))) {
                            sceneNumbers->mNextScene = 2;
                            SetNextRaceKind(0);
                        }
                        break;
                    case RACE_KIND_REPLAY:
                        switch (RaceSceneGetCurrentMode()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (ShouldEndReplayRace() != 0) {
                                    sceneNumbers->mNextScene = 2;
                                }
                                break;
                        }
                        break;
                    case RACE_KIND_AWARD:
                        if (ShouldEndAwardRace(sceneFrames) != 0) {
                            sceneNumbers->mNextScene = 0xa;
                        }
                        break;
                    case RACE_KIND_STAFF_ROLL:
                        c = 0x2a5a;
                        if (RaceSceneGetCurrentCourseId() == COURSE_ID_STAFFROLLTRUE) {
                            c = 0x2b02;
                        }
                        if (sceneFrames > c) {
                            sceneNumbers->mNextScene = 0xf;
                            break;
                        }
                        if (ShouldEndStaffRoll(sceneFrames) != 0) {
                            func_ov001_0219e0c4();
                            sceneNumbers->mNextScene = 0xf;
                        }
                        break;
                }
            }
            if (ShouldUpdateRace(sceneFrames) != 0) {
                UpdateRace();
            }
            UpdateRaceHud();
        }
        UpdateRaceHudSubScreen();
        switch (GetCurrentRaceKind()) {
            case RACE_KIND_NORMAL:
            case RACE_KIND_REPLAY:
            case RACE_KIND_START_GP:
            case 4:
                UpdateChoisesS();
                break;
        }
        if (GetChoisesSOpenDuringRace() != 0) {
            SetInputOpenDuringRace(1);
        } else {
            SetInputOpenDuringRace(0);
        }
    }
    raceSetup = gRaceSetup;
    if (raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        c = 1;
    } else {
        if (sceneFrames < 0x708) {
            c = 0;
        } else {
            c = 1;
        }
    }
    if (c != 0) {
        if (raceSetup->mMode != 5 || IsFrameSpanningVBlank() == 0) {
            DrawRace();
        }
    }
    DrawRaceHud();
    UpdateChoisesSScreenMap();
}

void PreSleepRaceScene(void) {
    gStartupWork->mUnk_54 = FALSE;
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        SetChoisesSOpenDuringRace(1);
    }
    PreSleepMicInput();
    while ((u32) data_0217c7ac != 0) {
        PrepareDisplayFrame();
        UpdateChoisesS();
        UpdateSounds();
        FinishDisplayFrame();
        UpdateChoisesSScreenMap();
        RecordFrameTimes();
    }
}

void PostSleepRaceScene(void) {
    PostSleepMicInput();
}

u32 RunRaceScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gRaceSceneCallbacks;
    SetCurrentRaceFromNext();
    if (gRaceSetup->mMode == 5) {
        callbacks.mUnk_1c = 1;
    }
    if (gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
            callbacks.mFadeToClearFrameCount = 1;
            callbacks.mFadeToFadedFrameCount = 0x78;
        }
    } else {
        callbacks.mFadeToClearFrameCount = 0x3c;
        callbacks.mFadeToFadedFrameCount = 0x78;
    }
    if (gBootInfo->mUnk_00 != 2) {
        LoadSndBanksForCharacters(1);
    }
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void InitMenuScene(void) {
    InitMenu();
}

void ReleaseMenuScene(void) {
    ReleaseMenu();
    gStartupWork->mDemoEndedByInput &= ~1;
    ResetTimeAttackNextEntries();
}

void WriteMenuSceneRegistersCallback(void) {
    WriteMenuSceneRegisters();
}

void UpdateMenuScene(void) {
    UpdateMenuScreen();
    HideUnusedMenuOams();
}

u32 RunMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gMenuSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

u32 CreateFrmHeapsAndAllocSoundBuffer(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer,
                                      void **outFirstFrontHeap, void **outSecondFrontHeap, void **outThirdFrontHeap) {
    u32 soundBufferSize;
    if (gBootInfo->mUnk_00 == 2) {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x19000);
    } else {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x1b800);
    }
    if (gBootInfo->mUnk_00 != 2) {
        *outFirstFrontHeap = NULL;
        *outSecondFrontHeap = NULL;
        *outThirdFrontHeap = NULL;
    } else {
        *outFirstFrontHeap = CreateFrmHeapFromFront(heap, 0x19000);
        *outSecondFrontHeap = CreateFrmHeapFromFront(heap, 0x4b000);
        *outThirdFrontHeap = CreateFrmHeapFromFront(heap, 0x1b800);
    }
    soundBufferSize = GetSndInitBufferSize(gBootInfo->mUnk_00 == 2 ? 2 : 0);
    *outSoundBuffer = HeapAlloc(heap, soundBufferSize);
    NNS_FndGetTotalFreeSizeForExpHeap(heap);
    return soundBufferSize;
}

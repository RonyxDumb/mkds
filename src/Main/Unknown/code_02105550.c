#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_0202511c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0204984c.h"

#include "code_0212bcac.h"
#include "Main/Unknown/code_021055b0.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/code_0210d9a0.h"
#include "Main/Unknown/code_0210dc50.h"
#include "Main/Unknown/code_0210ef68.h"
#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/code_02110534.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_02110720.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02105980.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_02111000.h"
#include "code_0212ba68.h"
#include "code_0212c7a0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0206bcb0.h"
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
#include "Main/Unknown/code_0210912c.h"
#include "Main/Unknown/code_02109178.h"
#include "Main/Unknown/code_0210b6a0.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_0210bbec.h"
#include "Main/Unknown/code_0210d570.h"
#include "Main/Unknown/code_0210dc48.h"
#include "Main/Unknown/code_0210ef50.h"
#include "Main/Unknown/code_0210f858.h"
#include "Main/Unknown/code_0210fa28.h"
#include "Main/Unknown/code_0210faac.h"
#include "Main/Unknown/code_0210fb54.h"
#include "Main/Unknown/code_02110484.h"
#include "Main/Unknown/code_02111118.h"
#include "code_0212ba34.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_021089f4.h"
#include "Main/Unknown/code_02108a40.h"
#include "Main/Unknown/code_02108b78.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02024974.h"

const Vec3 data_0215a6c0 = {0x1000, 0x1000, 0x1000};
const Vec3 data_0215a6cc = {0, 0, 0};

// Keeps seq 0 looping on the in-memory archive until StopSeqZeroLoop; UpdateSounds restarts it.
void StartSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    gSeqZeroLoopOn = 1;
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StopSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&data_0217c788, 0xd);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void func_02108d00(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StartMessageScreenSeq(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void func_02108c1c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 8);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void func_02108c04(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
}

void func_02108bb4(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0x202);
}

void func_02108b78(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x203);
}

void func_02108b2c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0x204);
}

void func_02108adc(void) {
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    if (data_0217c778 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c778, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c778, 0, 0x205);
}

void func_02108a8c(void) {
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    if (data_0217c778 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c778, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c778, 0, 0x206);
}

void func_02108a40(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x207);
}

void func_021089f4(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (0x0000020au));
}

void func_02108990(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x20a);
}

void func_0210895c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
}

LoadedSoundSet *GetLoadedSoundSet(void) {
    return &data_0217c7b4;
}

BOOL LoadSndBanksAndWaveArcs(s32 bankMask) {
    s32 i;
    NNSSndHeap *savedHeap;

    savedHeap = data_0217d130;
    data_0217d130 = data_0217c77c;
    if (data_0216c7d4 != 2) {
        NNS_SndArcLoadBank(1, data_0217c77c);
    }
    for (i = 0; i < 0xd; i++) {
        if (((bankMask >> i) & 1) != 0) {
            if (NNS_SndArcLoadBankEx(data_0216c7f8[i], 2, data_0217c77c) == 0) {
                data_0217d130 = savedHeap;
                return FALSE;
            }
            if (NNS_SndArcLoadWaveArc(data_0216c82c[i], data_0217c77c) == 0) {
                data_0217d130 = savedHeap;
                return FALSE;
            }
        }
    }
    data_0217d130 = savedHeap;
    return TRUE;
}

BOOL LoadSndBanksAndWaveArcsIfChanged(s32 bankMask) {
    if (bankMask == 0) {
        return TRUE;
    }
    if (gLoadedSoundBanks.mLoadMarker != 0xff00 && gLoadedSoundBanks.mBankMask == bankMask) {
        return TRUE;
    }
    NNS_SndHeapClear(data_0217c77c);
    gLoadedSoundBanks.mLoadMarker = 0xff00;
    gLoadedSoundBanks.mBankMask = 0;
    gLoadedSoundBanks.mBankMask = bankMask;
    gLoadedSoundBanks.mLoadMarker = 0xfe00;
    if (LoadSndBanksAndWaveArcs(bankMask) == FALSE) {
        return FALSE;
    }
    return TRUE;
}

// Total size of the buffer CreateSndHeaps carves into its three parts.
int GetSndHeapsBufferSize(int heapSizeKind) {
    return (heapSizeKind == 0 ? 0xc8000 : 0xaf000) - (heapSizeKind == 2 ? 0xaf000 : 0xc400);
}

int GetSndInitBufferSize(int heapSizeKind) {
    return heapSizeKind == 2 ? 0xaf000 : 0xc400;
}

void ReleaseSndHeaps(void) {
    NNS_SndHeapDestroy(data_0217d130);
    data_0217d130 = NULL;
    NNS_SndHeapDestroy(data_0217c77c);
    data_0217c77c = NULL;
    NNS_SndHeapDestroy(data_0217c790);
    data_0217c790 = NULL;
    ClearSndFileAddresses(GetSndDataFileIdList());
    ClearSndFileIdList(GetSndDataFileIdList());
    ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6f4[0];
    ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6f4[1];
    ResetLoadedSoundSet(&data_0217c7b4);
}

void CreateSndHeaps(u32 heapSizeKind, u32 buffer) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    u32 soundHeapSizeCopy;
    u32 seqRowHeapSizeCopy;
    u32 w;
    u32 x;

    data_0216c7d4 = heapSizeKind;
    switch (heapSizeKind) {
        case 0:
            soundHeapSize = 0x36f3c;
            break;
        case 1:
            soundHeapSize = 0x26a08;
            break;
        case 2:
            soundHeapSize = 0x25a5c;
            break;
    }
    ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6ec[0];
    ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6ec[1];
    ResetLoadedSoundSet(&data_0217c7b4);
    data_0217c77c = NNS_SndHeapCreate((void *) buffer, soundHeapSize);
    seqRowHeapSize = 0;
    data_0217d130 = NULL;
    buffer = buffer + soundHeapSize;
    switch (heapSizeKind) {
        case 0:
            seqRowHeapSize = 0x6580;
            break;
        case 1:
            seqRowHeapSize = 0x35a0;
            break;
        case 2:
            seqRowHeapSize = 0x35a0;
            break;
    }
    CreateSeqRowHeap((void *) buffer, seqRowHeapSize);
    data_0217c790 = (NNSSndHeap *) buffer;
    x = buffer + seqRowHeapSize;
    w = (heapSizeKind == 0 ? 0xc8000 : 0xaf000) - (heapSizeKind == 2 ? 0xaf000 : 0xc400);
    switch (heapSizeKind) {
        case 0:
            soundHeapSizeCopy = 0x36f3c;
            break;
        case 1:
            soundHeapSizeCopy = 0x26a08;
            break;
        case 2:
            soundHeapSizeCopy = 0x25a5c;
            break;
    }
    seqRowHeapSizeCopy = 0;
    switch (heapSizeKind) {
        case 0:
            seqRowHeapSizeCopy = 0x6580;
            break;
        case 1:
            seqRowHeapSizeCopy = 0x35a0;
            break;
        case 2:
            seqRowHeapSizeCopy = 0x35a0;
            break;
    }
    w = w - soundHeapSizeCopy - seqRowHeapSizeCopy;
    data_0217d130 = NNS_SndHeapCreate((void *) x, w);
    x = 0;
    if (heapSizeKind == 1) {
        x = 1;
    }
    LoadInitialSndGroup(x);
}

void InitSound(void *buffer, u32 b, u32 useFileArchive) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    Unk02108344 heapSizeKind;
    s32 i;

    gSeqZeroLoopOn = 0;
    if (useFileArchive == 0) {
        heapSizeKind = E2;
        switch (heapSizeKind) {
            case E0:
                soundHeapSize = 0x36f3c;
                break;
            case E1:
                soundHeapSize = 0x26a08;
                break;
            case E2:
                soundHeapSize = 0x25a5c;
                break;
        }
        seqRowHeapSize = 0;
        switch (heapSizeKind) {
            case E0:
                seqRowHeapSize = 0x6580;
                break;
            case E1:
                seqRowHeapSize = 0x35a0;
                break;
            case E2:
                seqRowHeapSize = 0x35a0;
                break;
        }
        b = b - soundHeapSize;
        data_0216c7d4 = 2;
        b = b - seqRowHeapSize;
    }
    InitSoundSystem(buffer, b, useFileArchive != 0 ? gSoundDataSdatPath : 0);
    InitSoundRequestQueues();
    NNS_SndArcInitOnMemory(&gOnMemorySndArc, gOnMemorySdat);
    NNS_SndArcSetCurrent(&gFileSndArc);
    if (useFileArchive != 0) {
        LoadInitialSndArcs();
    } else {
        ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6e4[0];
        ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6e4[1];
        data_0217c77c = NNS_SndHeapCreate((buffer + b), 0x25a5c);
        CreateSeqRowHeap((buffer + b + 0x25a5c), 0x35a0);
    }
    data_0216cb28 = 0x69;
    StartSoundOutputEffect(1);
    InitKartSoundPitchFactors();
    ClearSndFileIdList(GetSndDataFileIdList());
    ClearSndFileIdList(GetSoundSetFileIdList());
    for (i = 0; i < 12; i++) {
        NNS_SndHandleInit(&data_0217c838[i]);
    }
    InitSoundHandlePool(&data_0217c7c4, data_0217c7d8, 3, 8);
    NNS_SndHandleInit(&data_0217c7ac);
    NNS_SndHandleInit(&data_0217c788);
    NNS_SndHandleInit(&data_0217c778);
    NNS_SndSetMasterVolume(0x7f);
    NNS_SndSetMonoFlag(0);
    SetSoundFadeSteps(0x1e);
    gPlayerVolumeFade.mVolumePerFrameBeforeRaceStart = FX_Div(0x7f000, 0x46000);
    gPlayerVolumeFade.mVolumePerFrameAfterRaceStart = FX_Div(0x7f000, 0x3c000);
    gPlayerVolumeFade.mPlayerMaskBeforeRaceStart = 0xff;
    gPlayerVolumeFade.mPlayerMaskAfterRaceStart = 0x7f;
    gPlayerVolumeFade.mVolumePerFrame = gPlayerVolumeFade.mVolumePerFrameBeforeRaceStart;
    gPlayerVolumeFade.mVolume = 0;
    InitSoundFalloffsAndPlayingSounds();
    data_0217c780 = 0;
    InitSoundPitchSwing();
}

// Per-frame sound step; runs once per iteration of every scene frame loop.
void UpdateSounds(void) {
    s32 i;
    BOOL seqZeroPlaying;
    NNSSndSeqPlayer *seqPlayer;

    if (data_0217d070.mProgress != 0) {
        UpdateSceneSoundState();
    }
    ResetThunderShrinkSoundCounter();
    ResetMapObjectSoundCounter();
    for (i = 0; i < 7; i++) {
        RunSoundRequests(OFFSET_PTR(SoundRequestQueue, data_0217d26c, i * sizeof(SoundRequestQueue)));
    }
    IncrementSoundHandleAges(&data_0217c7c4);
    UpdateSoundSources();
    if (gSeqZeroLoopOn == 1) {
        seqPlayer = data_0217c788;
        seqZeroPlaying = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0 && seqPlayer->mSeqNo == 0;
        if (seqZeroPlaying == FALSE) {
            NNS_SndArcSetCurrent(&gOnMemorySndArc);
            if (data_0217c788 != NULL) {
                NNS_SndPlayerStopSeq(&data_0217c788, 0);
            }
            NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0);
            NNS_SndArcSetCurrent(&gFileSndArc);
        }
    }
    UpdateSndMain();
    gSoundStartedThisFrame = 0;
}

// Loads the sound data of the scene that is starting; the parameter is not used.
void InitSceneSounds(s32 e) {
    s32 sceneSoundRowIndex;
    s32 currentSceneNumber;
    s32 v;
    BOOL b;
    u32 d;
    NNSSndHeap *savedHeap;
    SoundRow buf;
    ScenePlayersSeqInfo s;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    ClearSurfaceSoundIds();
    currentSceneNumber = GetCurrentSceneNumber();
    v = 0x69;
    b = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        d = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == 2;
        if (d != 0) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_BEACH:
                v = v + 0x17;
                break;
            case COURSE_ID_OLD_MOMO_64:
                v = v + 5;
                break;
            case COURSE_ID_OLD_MARIO_SFC:
                v = v + 1;
                break;
            case COURSE_ID_OLD_PEACH_AGB:
            case COURSE_ID_OLD_LUIGI_AGB:
                v = v + 0xd;
                break;
            case COURSE_ID_OLD_DONUT_SFC:
                v = v + 5;
                break;
        }
    }
    if (v > 0x7f) {
        v = 0x7f;
    }
    data_0216cb28 = v;
    sceneSoundRowIndex = GetSceneSoundRowIndex(currentSceneNumber, &buf);
    if (data_0217d060 == NULL) {
        ResetSeqVariableReadings();
        SetSeqVariableEnabled(0, 0);
        SetSeqVariableEnabled(1, 0);
    }
    ResetEmblemSoundCounters();
    ResetSeqQueue();
    InitKingTeresaSoundState(0);
    SetSoundFadeSteps(GetSceneFadeToFadedFrameCount());
    InitKartNearSoundFactors();
    InitVolumeFade();
    switch (currentSceneNumber) {
        case 2:
            v = gRaceSetup->mCourseId;
            switch (v) {
                case COURSE_ID_TOWN:
                    SetSeqVariableEnabled(0, 1);
                    SetSeqVariableEnabled(1, 1);
                    break;
                case COURSE_ID_MANSION:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    break;
                case COURSE_ID_PINBALL:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    break;
                case COURSE_ID_RIDGE:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    break;
                case COURSE_ID_SNOW:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    break;
                case COURSE_ID_CLOCK:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    break;
                case COURSE_ID_AIRSHIP:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    break;
                case COURSE_ID_STADIUM:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    break;
                case COURSE_ID_GARDEN:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    break;
                case COURSE_ID_KOOPA:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    break;
                case COURSE_ID_OLD_BABY_GC:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    break;
                case COURSE_ID_OLD_KINOKO_GC:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    break;
                case COURSE_ID_OLD_HYUDORO_64:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    break;
                case COURSE_ID_MINI_STAGE4:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    SetSurfaceSoundIds(data_0216c7e0.mUnk_10, data_0216c7e0.mUnk_14, &data_0216c7e0);
                    break;
                case COURSE_ID_MR_STAGE3:
                    CourseEntrySetSurfaceSoundIds(0x15, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    CourseEntrySetSurfaceSoundIds(0x8, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    CourseEntrySetSurfaceSoundIds(0x9, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    CourseEntrySetSurfaceSoundIds(0xd, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    CourseEntrySetSurfaceSoundIds(0xe, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    CourseEntrySetSurfaceSoundIds(0x10, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                        InitKingTeresaSoundState(1);
                    }
                    break;
            }
            SelectCourseSoundTable(v);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                u8 *w = (u8 *) gRaceSetup + 0x28;
                switch (gRaceSetup->mMissionKind) {
                    case 1:
                        data_0217c770[0] = 0x1d7;
                        data_0217c76c[0] = 0x1d7;
                        break;
                    case 7:
                        data_0217c770[0] = 0x1e0;
                        data_0217c76c[0] = 0x1e1;
                        switch (w[6]) {
                            case 9:
                            case 0xa:
                                data_0217c76c[0] = 0xff;
                                break;
                        }
                        break;
                    case 0:
                        data_0217c770[0] = 0x1db;
                        data_0217c76c[0] = 0x1dc;
                        break;
                    case 2:
                    case 6:
                        data_0217c770[0] = 0xff;
                        data_0217c76c[0] = 0xff;
                        break;
                    case 4:
                        data_0217c770[0] = 0x1dd;
                        data_0217c76c[0] = 0x1de;
                        break;
                    case 3:
                        data_0217c770[0] = 0x1dd;
                        data_0217c76c[0] = 0x1de;
                        break;
                    case 8:
                    case 9:
                    case 10:
                        break;
                }
            }
            { break; }
        case 1:
            if (*(vu16 *) 0x027ffc40 != 2) {
                savedHeap = data_0217d130;
                if (gLoadedSoundBanks.mLoadMarker == 0xff00 || gLoadedSoundBanks.mBankMask != 0xffff) {
                    NNS_SndHeapClear(data_0217c77c);
                    gLoadedSoundBanks.mLoadMarker = 0xff00;
                    gLoadedSoundBanks.mBankMask = 0;
                    data_0217d130 = data_0217c77c;
                    if (NNS_SndArcLoadBank(0x2c, data_0217c77c) != 0) {
                        if (NNS_SndArcLoadSeqArc(3, data_0217d130) != 0) {
                            data_0217d130 = savedHeap;
                            gLoadedSoundBanks.mBankMask = 0xffff;
                            gLoadedSoundBanks.mLoadMarker = 0xfe00;
                        }
                    }
                }
            }
            { break; }
        case 0xc:
            savedHeap = data_0217d130;
            if (gLoadedSoundBanks.mLoadMarker == 0xff00 || gLoadedSoundBanks.mBankMask != 0xffff) {
                NNS_SndHeapClear(data_0217c77c);
                gLoadedSoundBanks.mLoadMarker = 0xff00;
                gLoadedSoundBanks.mBankMask = 0;
                data_0217d130 = data_0217c77c;
                if (NNS_SndArcLoadBank(0x2c, data_0217c77c) != 0) {
                    if (NNS_SndArcLoadSeqArc(3, data_0217d130) != 0) {
                        data_0217d130 = savedHeap;
                        gLoadedSoundBanks.mBankMask = 0xffff;
                        gLoadedSoundBanks.mLoadMarker = 0xfe00;
                    }
                }
            }
            { break; }
        case 0:
            break;
    }
    s.mUnk_00 = 0xff;
    s.mSeqStartProgress = buf.mUnk_00[0];
    s.mSeqId = buf.mUnk_00[1];
    InitVolumeFade();
    InitSceneSoundState(sceneSoundRowIndex & 0xff, s, &gSceneSoundState);
    InitSoundFalloffsAndPlayingSounds();
    InitSceneSoundsNop();
    InitKartSoundQueue();
    ResetSoundRequestQueues();
    ResetSeqPlayerControl();
    if (*(vu16 *) 0x027ffc40 != 2) {
        LoadSceneSoundSet(buf, 0);
    }
    if (currentSceneNumber != 1) {
        return;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcLoadBank(2, data_0217d130);
    }
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    data_0217c798[0] = NNS_SndHeapSaveState(data_0217d130);
    if (GetCurrentSceneNumber() != 1) {
        return;
    }
    if (data_0217b488->mUnk_08 == 3) {
        data_0217d070.mSeqStartProgress = 0xff;
    }
}

void InitSceneSoundState(u32 sceneSoundRowIndex, ScenePlayersSeqInfo b, SceneSoundState *sceneSoundState) {
    sceneSoundState->mLapsDone = 0;
    NNS_SndHandleInit(&sceneSoundState->mKartStarSeq);
    sceneSoundState->mLastLapSeqState = 0;
    sceneSoundState->mOnLastLap = 0;
    sceneSoundState->mKartStarSeqOn = 0;
    sceneSoundState->mRaceFrames = 0;
    sceneSoundState->mSceneFrames = 0;
    sceneSoundState->mRaceState = 0;
    sceneSoundState->mRankIndex = 0xff;
    sceneSoundState->mRankIndexAtSeq = 0xff;
    sceneSoundState->mRankSeqFrames = -1;
    sceneSoundState->mVolumesLowered = 0;
    InitScenePlayers(&data_0217d070, sceneSoundState, sceneSoundRowIndex, b);
    data_0217d084.mUnk_18 = &gSceneSoundState.mKartStarSeq;
    SetSoundMode(&data_0217d084, 0);
}

void StartSceneSounds(void) {
    s32 b;
    u32 c;
    s32 v;
    s32 i;
    NNSSndArc *savedArc;
    NNSSndSeqPlayer **seqHandle;
    s32 j;

    if (*(u16 *) 0x27ffc40 == 2) {
        if (GetCurrentSceneNumber() == 6) {
            return;
        }
    }
    ResetRaceEndSeqState();
    data_0217c780 = 0;
    SoundReturnArgumentWrapper((u32) &data_0217c780);
    b = 0;
    gPlayerVolumeFade.mVolume = 0;
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0x7f;
    gPlayerVolumeFade.mTargetVolumeAfterRaceStart = 0x7f;
    gPlayerVolumeFade.mRaceStarted = 0;
    if (GetCurrentSceneNumber() == 2) {
        c = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == 2;
        if (c != 0) {
            b = 1;
        }
    }
    if (b != 0) {
        SetSoundMode(&data_0217d084, 2);
        data_0217c780 = 1;
        StartScenePlayersSeqNo(&data_0217d070, GetSeqRowSceneSeq(), NULL);
        data_0217c7b0 = 0;
        v = 0xffff;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            switch (gRaceSetup->mMissionTableValue) {
                case 9:
                    v = 0x20e;
                    break;
                case 0x11:
                    v = 0x235;
                    break;
                case 0x31:
                    v = 0x246;
                    break;
                case 0x33:
                    v = 0x228;
                    break;
            }
        }
        if (v == 0xffff) {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_AIRSHIP:
                    v = 0x1d2;
                    break;
                case COURSE_ID_STADIUM:
                    v = 0x1bf;
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    v = 0x1d6;
                    break;
            }
        }
        if (v != 0xffff) {
            NNS_SndPlayerStopSeq(&data_0217c854, 0);
            seqHandle = &data_0217c854;
            if ((data_0217c780 & 1) != 0) {
                if (data_0217d084.mUnk_0c != 0) {
                    if (*seqHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqHandle, 0);
                    }
                    if (*seqHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqHandle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, v);
                }
            }
            data_0217c7b0 = 1;
        }
        if (gRaceSetup->mMode != MODE_BATTLE) {
            SetLapProgressSoundGaps(gCourseMap->mCheckpointSum);
            gSceneSoundState.mLapCount = GetLapCount();
        }
    } else {
        if (GetCurrentSceneNumber() == 2) {
            if (gRaceSetup->mRaceKind - 3 <= 1) {
                SetSoundMode(&data_0217d084, 2);
                data_0217c780 = 2;
            } else {
                if (IsFileSndArcOpen() != 0) {
                    savedArc = NNS_SndArcGetCurrent();
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    v = 0xffff;
                    b = 0x7f;
                    for (i = 1; i <= 7; i++) {
                        if (NNS_SndArcGetPlayerInfo(i) != NULL) {
                            if (((v >> i) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(i, b);
                            }
                        }
                    }
                    NNS_SndArcSetCurrent(savedArc);
                }
                gPlayerVolumeFade.mVolume = 0x7f000;
                SetSoundMode(&data_0217d084, 3);
                data_0217c780 = 0;
            }
        } else {
            if (IsFileSndArcOpen() != 0) {
                savedArc = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gFileSndArc);
                v = 0xffff;
                b = 0x7f;
                for (j = 1; j <= 7; j++) {
                    if (NNS_SndArcGetPlayerInfo(j) != NULL) {
                        if (((v >> j) & 1) != 0) {
                            NNS_SndPlayerSetPlayerVolume(j, b);
                        }
                    }
                }
                NNS_SndArcSetCurrent(savedArc);
            }
            gPlayerVolumeFade.mVolume = 0x7f000;
            SetSoundMode(&data_0217d084, 2);
            data_0217c780 = 0;
        }
    }
    StartScenePlayersForScene(&data_0217d070);
}

void StartRaceSounds(void) {
    s32 i;
    NNSSndSeqPlayer **handle;

    gSceneSoundState.mRaceState = 1;
    StartScenePlayersForRace(&data_0217d070);
    gPlayerVolumeFade.mRaceStarted = 1;
    if (data_0217c7b0 != 0) {
        NNS_SndPlayerStopSeq(&data_0217c854, 0x14);
    }
    if (gRaceSetup->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    handle = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handle, 0, 0x1c0);
}

void StartKartStarSeq(void) {
    if (gSceneSoundState.mRaceState != 1) {
        return;
    }
    gSceneSoundState.mKartStarSeqOn = 1;
    if ((gSceneSoundState.mLastLapSeqState & 1) != 0) {
        data_0217c7a8 = 1;
        return;
    }
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 1);
    StartScenePlayersSeqNo(&data_0217d070, 0x49, &gSceneSoundState.mKartStarSeq);
}

void StopKartStarSeq(void) {
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            StartScenePlayersSeq(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            func_0210faac();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
}

void EndRaceSounds(void) {
    u32 fadeSteps;
    s32 i;
    s32 j;
    u8 *playerCursor;

    gSceneSoundState.mRaceState = 2;
    StopScenePlayersSeq(&data_0217d070, GetEndRaceFadeSteps());
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            StartScenePlayersSeq(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            func_0210faac();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
    if (data_0217d084.mMode == 2) {
        SetSoundMode(&data_0217d084, 3);
    }
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, GetEndRaceFadeSteps());
    }
    fadeSteps = GetEndRaceFadeSteps();
    for (j = 0, playerCursor = (&data_0217c7c4)->mEntries; j < (&data_0217c7c4)->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&data_0217c7c4)->mEntrySize;
    }
}

// Counts a lap done by the selected kart; one lap before the end it switches to seq 0x3e.
void AdvanceSceneSoundLap(void) {
    BOOL finishedAllLaps;
    s32 i;
    NNSSndSeqPlayer **seqHandle;

    finishedAllLaps = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
            return;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    gSceneSoundState.mLapsDone = gSceneSoundState.mLapsDone + 1;
    if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount) {
        finishedAllLaps = TRUE;
    } else if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount - 1) {
        gSceneSoundState.mLastLapSeqState = 1;
        gSceneSoundState.mOnLastLap = 1;
        StopScenePlayersSeq(&data_0217d070, 0);
        if (gSceneSoundState.mKartStarSeq != NULL) {
            NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 1);
        }
        StartScenePlayersSeqNo(&data_0217d070, 0x3e, NULL);
        gSceneSoundState.mLastLapSeqState = 1;
    }
    if (gRaceSetup->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    if (finishedAllLaps != FALSE) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    seqHandle = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, 0x1c1);
}

// Stores the selected kart's new place; in some courses it starts a seq when the place improves.
void SetSceneSoundRank(u32 rankIndex) {
    BOOL b;
    BOOL c;
    u32 slotSeqPlaying;
    u32 shouldStartSeq;
    u32 seqNo;
    s32 i;
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqPlayer **seqHandle;

    b = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        c = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == 2;
        if (c != FALSE) {
            b = TRUE;
        }
    }
    if (b == FALSE) {
        return;
    }
    if ((u32) gRaceSetup->mMode - 1 <= 1) {
        return;
    }
    seqNo = -1;
    b = FALSE;
    if (gSceneSoundState.mRaceFrames <= 0xf0) {
        gSceneSoundState.mRankIndex = rankIndex;
        return;
    }
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mOnLastLap != 0) {
                seqNo = 0x1c2;
                for (i = 7; i < 12; i++) {
                    NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)),
                                         b);
                }
                b = TRUE;
            }
            { break; }
        case COURSE_ID_PINBALL:
            seqNo = rankIndex == 0 ? 0x1cb : 0x1ca;
            b = TRUE;
            seqPlayer = data_0217c838[7];
            slotSeqPlaying = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0x1cc && seqPlayer->mSeqNo == 0;
            if (slotSeqPlaying != 0) {
                b = FALSE;
            }
            break;
    }
    if (b != FALSE) {
        if (rankIndex < gSceneSoundState.mRankIndex) {
            shouldStartSeq = 0;
            if (gSceneSoundState.mRankSeqFrames != -1) {
                if (gSceneSoundState.mRankIndexAtSeq > rankIndex) {
                    shouldStartSeq = 1;
                }
            } else {
                shouldStartSeq = 1;
            }
            if (shouldStartSeq != 0) {
                NNS_SndPlayerStopSeq(&data_0217c854, 0);
                seqHandle = &data_0217c854;
                if (data_0217c780 & 1) {
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*seqHandle != NULL) {
                            NNS_SndPlayerStopSeq(seqHandle, 0);
                        }
                        if (*seqHandle != NULL) {
                            NNS_SndPlayerStopSeq(seqHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(seqHandle, 0, (u16) seqNo);
                    }
                }
                gSceneSoundState.mRankIndexAtSeq = rankIndex;
                gSceneSoundState.mRankSeqFrames = 0;
            }
        }
    }
    gSceneSoundState.mRankIndex = rankIndex;
}

void UpdateRaceSounds(void) {
    PlayerVolumeFade *volumeFade;
    NNSSndSeqPlayer **sceneSeqHandle;
    u32 steppedVolume;
    s32 tableRow;
    s32 playerMask;
    s32 playerNo;
    struct NNSSndArc *savedArc;

    switch (gSceneSoundState.mRaceState) {
        case 1:
            gSceneSoundState.mRaceFrames++;
            if (gSceneSoundState.mRaceFrames == 0x28) {
                StartScenePlayersSeq(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            }
            volumeFade = &gPlayerVolumeFade;
            tableRow = volumeFade->mRaceStarted;
            if (tableRow == 1) {
                volumeFade->mVolumePerFrame = gPlayerVolumeSteps[tableRow];
                steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeTargets[tableRow]);
                if (steppedVolume != -1) {
                    playerMask = gPlayerVolumeMasks[tableRow];
                    if (IsFileSndArcOpen() != 0) {
                        savedArc = NNS_SndArcGetCurrent();
                        NNS_SndArcSetCurrent(&gFileSndArc);
                        for (playerNo = 1; playerNo <= 7; playerNo++) {
                            if (NNS_SndArcGetPlayerInfo(playerNo) != NULL && ((playerMask >> playerNo) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(playerNo, steppedVolume);
                            }
                        }
                        NNS_SndArcSetCurrent(savedArc);
                    }
                }
            }
            UpdateSceneSeqPlayerControl();
            UpdateSoundPitchSwing();
            break;
        case 2:
            UpdateRaceEndSeq();
            break;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        sceneSeqHandle = &data_0217d07c;
        if (IsAnySeqVariableEnabled() != 0) {
            UpdateSeqVariableReadings(sceneSeqHandle);
            if (gRaceSetup->mCourseId == COURSE_ID_TOWN) {
                if (IsSeqVariableChanged(0) != 0 || IsSeqVariableChanged(1) != 0) {
                    StartCourseSoundAtVolume(0, 0x1a9);
                }
            }
        }
        if (gRaceSetup->mCourseId == COURSE_ID_KOOPA) {
            UpdateCourseSound(0, 0x16b);
        }
        if (gSceneSoundState.mRankSeqFrames != -1) {
            if (++gSceneSoundState.mRankSeqFrames >= 0x3c) {
                gSceneSoundState.mRankSeqFrames = -1;
            }
        }
        if (gSceneSoundState.mLastLapSeqState == 1 && sceneSeqHandle[0] == NULL) {
            gSceneSoundState.mLastLapSeqState = 0;
            if (data_0217c7a8 != 0 && gSceneSoundState.mKartStarSeqOn == 1) {
                if (gSceneSoundState.mRaceState == 1) {
                    gSceneSoundState.mKartStarSeqOn = 1;
                    if ((gSceneSoundState.mLastLapSeqState & 1) == 0) {
                        NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 1);
                        StartScenePlayersSeqNo(&data_0217d070, 0x49, &gSceneSoundState.mKartStarSeq);
                    }
                }
                data_0217c7a8 = 0;
                data_0217c78c = 1;
            } else if (gSceneSoundState.mKartStarSeq != NULL) {
                NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 0);
                data_0217c78c = 1;
            } else if (gSceneSoundState.mRaceState == 1) {
                StartScenePlayersSeq(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
                NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
                func_0210faac();
            }
        }
    } else {
        UpdateKartSoundQueue();
    }
    gKingTeresaStateLastFrame = gKingTeresaState;
}

void UpdateCourseSeqAtSceneFrames(void) {
    u32 seqNo;
    NNSSndSeqPlayer **seqHandle;

    seqNo = 0xffff;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1bc;
            }
            break;
        case COURSE_ID_RIDGE:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1a6;
            }
            break;
        case COURSE_ID_GARDEN:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1a5;
            }
            break;
        case COURSE_ID_MANSION:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x126;
            }
            break;
        case COURSE_ID_AIRSHIP:
            switch (gSceneSoundState.mSceneFrames) {
                case 0xa:
                    seqNo = 0x1d2;
                    break;
                case 0xa0:
                    NNS_SndPlayerStopSeq(&data_0217c854, 0x3c);
                    break;
                case 0x122:
                    seqNo = 0x1d2;
                    break;
            }
            { break; }
        case COURSE_ID_KOOPA:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1aa;
            }
            break;
        case COURSE_ID_CLOCK:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x192;
            }
            break;
        case COURSE_ID_MARIO:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x19b;
            }
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_BEACH:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_OLD_MOMO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x12b;
            }
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x19a;
            }
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1d5;
            }
            break;
        case COURSE_ID_RAINBOW:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                seqNo = 0x1ba;
            }
            break;
        case COURSE_ID_TOWN:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                seqNo = 0x199;
            }
            break;
    }
    if (seqNo == 0xffff) {
        return;
    }
    NNS_SndPlayerStopSeq(&data_0217c854, 0);
    seqHandle = &data_0217c854;
    if ((data_0217c780 & 2) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, seqNo);
}

void UpdateSceneSoundState(void) {
    PlayerVolumeFade *volumeFade;
    s32 tableRow;
    s32 steppedVolume;
    s32 playerMask;
    s32 playerNo;
    struct NNSSndArc *savedArc;

    volumeFade = &gPlayerVolumeFade;
    tableRow = volumeFade->mRaceStarted;
    if (tableRow == 0) {
        volumeFade->mVolumePerFrame = gPlayerVolumeSteps[tableRow];
        steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeTargets[tableRow]);
        if (steppedVolume != -1) {
            playerMask = gPlayerVolumeMasks[tableRow];
            if (IsFileSndArcOpen() != 0) {
                savedArc = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gFileSndArc);
                for (playerNo = 1; playerNo <= 7; playerNo++) {
                    if (NNS_SndArcGetPlayerInfo(playerNo) != NULL && ((playerMask >> playerNo) & 1) != 0) {
                        NNS_SndPlayerSetPlayerVolume(playerNo, steppedVolume);
                    }
                }
                NNS_SndArcSetCurrent(savedArc);
            }
        }
    }
    if (GetCurrentSceneNumber() == 2) {
        switch (gRaceSetup->mRaceKind) {
            case RACE_KIND_NORMAL:
            case 2:
                UpdateRaceSounds();
                break;
            case RACE_KIND_START_GP:
            case 4:
                UpdateCourseSeqAtSceneFrames();
                break;
        }
    } else if (GetCurrentSceneNumber() == 9) {
        if (gSceneSoundState.mSceneFrames == 0x5d) {
            NNS_SndPlayerStopSeq(&data_0217d07c, 0x1b);
        }
    } else if (GetCurrentSceneNumber() == 1 || GetCurrentSceneNumber() == 0xc) {
        if (*(vu16 *) 0x027ffc40 != 2) {
            UpdateSeqQueue();
        }
    } else if (GetCurrentSceneNumber() == 3) {
        UpdateEmblemSound();
    }
    if (data_0217d060 != NULL && data_0217d060->mSoundSet.mSeqId == 0 && data_0217d060->mSeqPlayer != NULL) {
        UpdateSeqVariableReadings(&data_0217d060->mSeqPlayer);
    }
    gSceneSoundState.mSceneFrames++;
}

void StopSceneSounds(void) {
    u32 fadeSteps;
    s32 i;
    s32 j;
    u8 *playerCursor;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0;
    gPlayerVolumeFade.mRaceStarted = 0;
    ScenePlayersReturnArgument(&data_0217d070);
    SetSoundMode(&data_0217d084, 4);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, GetSoundFadeSteps());
    }
    fadeSteps = GetSoundFadeSteps();
    for (j = 0, playerCursor = (&data_0217c7c4)->mEntries; j < (&data_0217c7c4)->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&data_0217c7c4)->mEntrySize;
    }
    NNS_SndPlayerStopSeq(&data_0217c788, 13);
    NNS_SndPlayerStopSeq(&data_0217c778, 13);
    gSeqZeroLoopOn = 0;
}

void StopSceneSoundsAtOnce(void) {
    s32 i;
    s32 j;
    u8 *playerCursor;
    SoundHandlePool *playerTable;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0;
    gPlayerVolumeFade.mRaceStarted = 0;
    ReleaseScenePlayers(&data_0217d070, 1);
    SetSoundMode(&data_0217d084, 0);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, 0);
    }
    playerTable = &data_0217c7c4;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, 0);
        playerCursor += playerTable->mEntrySize;
    }
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&data_0217c788, 0);
    NNS_SndPlayerStopSeq(&data_0217c778, 0);
}

void StopSceneSeqWithFadeSteps(void) {
    u32 fadeSteps;
    fadeSteps = GetSoundFadeSteps();
    NNS_SndPlayerStopSeq(&data_0217d07c, fadeSteps);
}

// Starts a seq and fades the sound handles out while the choises-S screen is open.
void LowerSndHandleVolumes(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;

    savedFadeSteps = GetSoundFadeSteps();
    gSceneSoundState.mVolumesLowered = 1;
    SetSoundFadeSteps(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x11);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    SetSoundMode(&data_0217d084, 5);
    if (gSceneSoundState.mLastLapSeqState == 1) {
        gSceneSoundState.mLastLapSeqState = 3;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &data_0217c7c4;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundFadeSteps(savedFadeSteps);
}

// Starts a seq and fades the sound handles back in when the choises-S screen closes.
void RaiseSndHandleVolumes(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;

    savedFadeSteps = GetSoundFadeSteps();
    gSceneSoundState.mVolumesLowered = 0;
    SetSoundFadeSteps(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x12);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    RestoreSavedSoundMode(&data_0217d084);
    if (gSceneSoundState.mLastLapSeqState == 3) {
        gSceneSoundState.mLastLapSeqState = 1;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0x7f, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &data_0217c7c4;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0x7f, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundFadeSteps(savedFadeSteps);
}

void StartChoisesSValueSeq(s32 valueIndex) {
    u32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;
    u32 seqNo;

    seqNo = data_0215a6d8[valueIndex];
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, seqNo);
    if (valueIndex == 4) {
        return;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerStopSeq(handleCursor, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &data_0217c7c4;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundMode(&data_0217d084, 4);
}

void StopAllSeqPlayers(void) {
    NNS_SndPlayerStopSeqAll(GetSoundFadeSteps());
}

void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume) {
    NNS_SndPlayerSetTrackVolume(handle, data_0216cb20, (u8) volume);
}

void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch) {
    NNS_SndPlayerSetTrackPitch(handle, data_0216cb20, pitch);
}

// Starts sound a on the shared handle unless one was already started this frame.
void StartSoundOncePerFrame(s32 seqNo) {
    if (gSoundStartedThisFrame != 0) {
        return;
    }
    gSoundStartedThisFrame = 1;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, seqNo);
}

void StartMissionRunLVselSeq(u32 mode) {
    s32 seqNo;

    data_0217c784 = mode;
    if (mode - 1 > 1) {
        return;
    }
    seqNo = (mode == 1) ? 0x47 : 0x48;
    NNS_SndHeapLoadState(data_0217d130, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    NNS_SndArcLoadSeq(seqNo, data_0217d130);
    NNS_SndPlayerStopSeq(&data_0217d07c, 2);
    StartSeqAtVolume(seqNo, 0x7f, &data_0217c83c);
}

void StartSceneSeqIfIdle(void) {
    if (data_0217d070.mSeqPlayer != NULL) {
        return;
    }
    if (data_0217c838[1] != NULL) {
        return;
    }
    StartScenePlayersSeq(&data_0217d070);
}

void StopMissionRunLVselSeqsWithSteps(int mode, u32 fadeSteps) {
    if (data_0217c784 - 1 <= 1) {
        NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    }
    if (mode == 3) {
        NNS_SndPlayerStopSeq(&data_0217d07c, fadeSteps);
        return;
    }
}

void func_0210593c(u32 mode) {
    if (mode != 4) {
        return;
    }
    if (data_0217d070.mSeqPlayer != NULL) {
        return;
    }
    StartScenePlayersSeq(&data_0217d070);
}

void LoadMissionRunMSselSoundData(u32 mode, u32 missionRow) {
    u32 bankNo = 0xff;
    data_0217c784 = mode;
    data_0217c79c = 0;
    data_0217c7a0 = 0;
    data_0217c774 = 0xff;
    if (mode != 3) {
        return;
    }
    switch (missionRow) {
        case 1:
            data_0217c774 = 1;
            bankNo = 0x25;
            break;
        case 2:
            data_0217c774 = 2;
            bankNo = 0x26;
            break;
        case 3:
            data_0217c774 = 3;
            bankNo = 0x27;
            break;
        case 4:
            data_0217c774 = 4;
            bankNo = 0x28;
            break;
        case 5:
            data_0217c774 = 5;
            bankNo = 0x29;
            break;
        case 6:
            data_0217c774 = 6;
            bankNo = 0x25;
            break;
        case 7:
            data_0217c774 = 7;
            bankNo = 0x17;
            break;
    }
    NNS_SndHeapLoadState(data_0217d130, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    NNS_SndArcLoadBank(bankNo, data_0217d130);
    NNS_SndArcLoadBank(0x2a, data_0217d130);
    NNS_SndArcLoadSeqArc(4, data_0217d130);
}

void UpdateMissionRunMSselSounds(s32 a) {
    s32 trackVolume;
    u32 startsBankSeq;
    s32 stepCount;
    if (data_0217c784 == 0) {
        if (data_0217d070.mSeqPlayer != NULL) {
            return;
        }
        StartScenePlayersSeq(&data_0217d070);
        return;
    }
    if (a != 0 && a != 0x32) {
        return;
    }
    startsBankSeq = 0;
    trackVolume = 0x78;
    stepCount = (a == 0x32) ? data_0217c79c : data_0217c7a0;
    if (stepCount < 5) {
        switch (stepCount) {
            case 0:
                trackVolume = 0xf;
                break;
            case 1:
                trackVolume = 0x1e;
                startsBankSeq = 1;
                break;
            case 2:
                trackVolume = 0x2d;
                break;
            case 3:
                trackVolume = 0x46;
                break;
            case 4:
                trackVolume = 0x2d;
                break;
        }
    } else {
        switch ((stepCount - 5) % 6) {
            case 0:
                trackVolume = 0x1e;
                break;
            case 1:
                trackVolume = 0x2d;
                break;
            case 2:
                trackVolume = 0x46;
                break;
            case 3:
                trackVolume = 0x5f;
                startsBankSeq = 1;
                break;
            case 4:
                trackVolume = 0x46;
                break;
            case 5:
                trackVolume = 0x2d;
                break;
        }
    }
    if (a == 0x32) {
        NNSSndSeqPlayer **seqHandle = &data_0217c83c;
        if (*seqHandle != NULL) {
            NNS_SndPlayerStopSeq(seqHandle, 0);
        }
        NNS_SndArcPlayerStartSeqArc(seqHandle, 4, 0);
        if (*seqHandle != NULL) {
            NNS_SndPlayerSetTrackVolume(seqHandle, data_0216cb20, trackVolume & 0xff);
        }
        data_0217c79c++;
        return;
    }
    if (a != 0) {
        return;
    }
    if (startsBankSeq != 0) {
        u16 seqIndex = data_0217c774;
        if (seqIndex != 0xff) {
            NNSSndSeqPlayer **bankSeqHandle = &data_0217c840;
            if (*bankSeqHandle != NULL) {
                NNS_SndPlayerStopSeq(bankSeqHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(bankSeqHandle, 4, seqIndex);
        }
    }
    data_0217c7a0++;
}

void StopMissionRunMSselSeqsWithSteps(u32 a, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    NNS_SndPlayerStopSeq(&data_0217c840, fadeSteps);
}

void StopMissionRunMSselSeqsAtOnce(void) {
    NNS_SndPlayerStopSeq(&data_0217c83c, 0);
    NNS_SndPlayerStopSeq(&data_0217c840, 0);
}

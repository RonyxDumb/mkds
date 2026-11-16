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

void func_02108ddc(void) {
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    data_0217c7a4 = 1;
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
}

void func_02108d80(void) {
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndPlayerStopSeq(&data_0217c788, 0xd);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
}

void sub_2108D00(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
}

void sub_2108C80(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndArcSetCurrent(&SDATFile);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
}

void func_02108c1c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndArcSetCurrent(&SDATFile);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 8);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
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

LoadedSoundSet *sound_getSeqHeapState(void) {
    return &data_0217c7b4;
}

BOOL loadCharacterSoundsInternal(s32 bankMask) {
    s32 i;
    NNSSndHeap *savedHeap;

    savedHeap = gSndHeapHandle;
    gSndHeapHandle = snd_sDriverVoiceHeap;
    if (g_BootMode != 2) {
        NNS_SndArcLoadBank(1, snd_sDriverVoiceHeap);
    }
    for (i = 0; i < 0xd; i++) {
        if (((bankMask >> i) & 1) != 0) {
            if (NNS_SndArcLoadBankEx(g_CharacterEffectSbnkIdTable[i], 2, snd_sDriverVoiceHeap) == 0) {
                gSndHeapHandle = savedHeap;
                return FALSE;
            }
            if (NNS_SndArcLoadWaveArc(g_CharacterEffectSwarIdTable[i], snd_sDriverVoiceHeap) == 0) {
                gSndHeapHandle = savedHeap;
                return FALSE;
            }
        }
    }
    gSndHeapHandle = savedHeap;
    return TRUE;
}

BOOL sound_loadCharacterSounds(s32 bankMask) {
    if (bankMask == 0) {
        return TRUE;
    }
    if (sLoadedCharacterSounds.field4 != 0xff00 && sLoadedCharacterSounds.field0 == bankMask) {
        return TRUE;
    }
    NNS_SndHeapClear(snd_sDriverVoiceHeap);
    sLoadedCharacterSounds.field4 = 0xff00;
    sLoadedCharacterSounds.field0 = 0;
    sLoadedCharacterSounds.field0 = bankMask;
    sLoadedCharacterSounds.field4 = 0xfe00;
    if (loadCharacterSoundsInternal(bankMask) == FALSE) {
        return FALSE;
    }
    return TRUE;
}

// Total size of the buffer CreateSndHeaps carves into its three parts.
int sound_getSomeSize2(int a) {
    return (a == 0 ? 0xc8000 : 0xaf000) - (a == 2 ? 0xaf000 : 0xc400);
}

int sound_getSomeSize(int a) {
    return a == 2 ? 0xaf000 : 0xc400;
}

void ReleaseSndHeaps(void) {
    NNS_SndHeapDestroy(gSndHeapHandle);
    gSndHeapHandle = NULL;
    NNS_SndHeapDestroy(snd_sDriverVoiceHeap);
    snd_sDriverVoiceHeap = NULL;
    NNS_SndHeapDestroy(g_AnotherSoundContext);
    g_AnotherSoundContext = NULL;
    ClearSndFileAddresses(sub_210EF50());
    ClearSndFileIdList(sub_210EF50());
    ((u32 *) &sLoadedCharacterSounds)[0] = data_0215a6f4[0];
    ((u32 *) &sLoadedCharacterSounds)[1] = data_0215a6f4[1];
    ResetLoadedSoundSet(&data_0217c7b4);
}

void CreateSndHeaps(u32 a, u32 buffer) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    u32 e;
    u32 v;
    u32 w;
    u32 x;

    g_BootMode = a;
    switch (a) {
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
    ((u32 *) &sLoadedCharacterSounds)[0] = data_0215a6ec[0];
    ((u32 *) &sLoadedCharacterSounds)[1] = data_0215a6ec[1];
    ResetLoadedSoundSet(&data_0217c7b4);
    snd_sDriverVoiceHeap = NNS_SndHeapCreate((void *) buffer, soundHeapSize);
    seqRowHeapSize = 0;
    gSndHeapHandle = NULL;
    buffer = buffer + soundHeapSize;
    switch (a) {
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
    g_AnotherSoundContext = (NNSSndHeap *) buffer;
    x = buffer + seqRowHeapSize;
    w = (a == 0 ? 0xc8000 : 0xaf000) - (a == 2 ? 0xaf000 : 0xc400);
    switch (a) {
        case 0:
            e = 0x36f3c;
            break;
        case 1:
            e = 0x26a08;
            break;
        case 2:
            e = 0x25a5c;
            break;
    }
    v = 0;
    switch (a) {
        case 0:
            v = 0x6580;
            break;
        case 1:
            v = 0x35a0;
            break;
        case 2:
            v = 0x35a0;
            break;
    }
    w = w - e - v;
    gSndHeapHandle = NNS_SndHeapCreate((void *) x, w);
    x = 0;
    if (a == 1) {
        x = 1;
    }
    sub_210E8F8(x);
}

void sound_loadSdat(void *buffer, u32 b, u32 c) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    Unk02108344 n;
    s32 i;

    data_0217c7a4 = 0;
    if (c == 0) {
        n = E2;
        switch (n) {
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
        switch (n) {
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
        g_BootMode = 2;
        b = b - seqRowHeapSize;
    }
    Sound_InitializeWithData(buffer, b, c != 0 ? aDataSoundSound : 0);
    InitSoundRequestQueues();
    NNS_SndArcInitOnMemory(&SDATFile, SDATFile_0);
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
    if (c != 0) {
        LoadCertainSwarSbnkSarc();
    } else {
        ((u32 *) &sLoadedCharacterSounds)[0] = data_0215a6e4[0];
        ((u32 *) &sLoadedCharacterSounds)[1] = data_0215a6e4[1];
        snd_sDriverVoiceHeap = NNS_SndHeapCreate((buffer + b), 0x25a5c);
        CreateSeqRowHeap((buffer + b + 0x25a5c), 0x35a0);
    }
    data_0216cb28 = 0x69;
    sound_startOutputEffect(1);
    sub_20250A8();
    ClearSndFileIdList(sub_210EF50());
    ClearSndFileIdList(sub_210EF5C());
    for (i = 0; i < 12; i++) {
        NNS_SndHandleInit(&data_0217c838[i]);
    }
    sp_init(&sound_sPools, data_0217c7d8, 3, 8);
    NNS_SndHandleInit(&data_0217c7ac);
    NNS_SndHandleInit(&data_0217c788);
    NNS_SndHandleInit(&data_0217c778);
    NNS_SndSetMasterVolume(0x7f);
    NNS_SndSetMonoFlag(0);
    sound_setFadeFrameCount(0x1e);
    data_0217c7f0.field1C = FX_Div(0x7f000, 0x46000);
    data_0217c7f0.field20 = FX_Div(0x7f000, 0x3c000);
    data_0217c7f0.field14 = 0xff;
    data_0217c7f0.field18 = 0x7f;
    data_0217c7f0.field0 = data_0217c7f0.field1C;
    data_0217c7f0.field4 = 0;
    sfx_210912C();
    data_0217c780 = 0;
    InitSoundPitchSwing();
}

// Per-frame sound step; runs once per iteration of every scene frame loop.
void sound_main(void) {
    s32 i;
    BOOL v;
    NNSSndSeqPlayer *seqPlayer;

    if (data_0217d070.field0 != 0) {
        UpdateSceneSoundState();
    }
    sub_210FA28();
    sub_210BAC0();
    for (i = 0; i < 7; i++) {
        RunSoundRequests(OFFSET_PTR(SoundRequestQueue, data_0217d26c, i * sizeof(SoundRequestQueue)));
    }
    sp_updateAges(&sound_sPools);
    sfx_update();
    if (data_0217c7a4 == 1) {
        seqPlayer = data_0217c788;
        v = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0 && seqPlayer->mSeqNo == 0;
        if (v == FALSE) {
            NNS_SndArcSetCurrent(&SDATFile);
            if (data_0217c788 != NULL) {
                NNS_SndPlayerStopSeq(&data_0217c788, 0);
            }
            NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0);
            NNS_SndArcSetCurrent(&gSdatFileSndArc);
        }
    }
    sub_210D7AC();
    gSoundStartedThisFrame = 0;
}

// Loads the sound data of the scene that is starting; the parameter is not used.
void InitSceneSounds(s32 e) {
    s32 c;
    s32 a;
    s32 v;
    BOOL b;
    u32 d;
    NNSSndHeap *p;
    SoundRow buf;
    Unk021073ec s;

    if (*(vu16 *) 0x027ffc40 == 2 && scproc_getCurrentScene() == 6) {
        return;
    }
    csfx_init();
    a = scproc_getCurrentScene();
    v = 0x69;
    b = FALSE;
    if (scproc_getCurrentScene() == 2) {
        d = gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL || gRaceMultiConfig->mRaceKind == 2;
        if (d != 0) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        switch (gRaceMultiConfig->mCourseId) {
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
    c = scene_getMusicData(a, &buf);
    if (data_0217d060 == NULL) {
        ResetSeqVariableReadings();
        SetSeqVariableEnabled(0, 0);
        SetSeqVariableEnabled(1, 0);
    }
    sub_2110A60();
    ResetSeqQueue();
    sub_21104DC(0);
    sound_setFadeFrameCount(scene_getFadeOutLength());
    sub_2110484();
    sub_21103C0();
    switch (a) {
        case 2:
            v = gRaceMultiConfig->mCourseId;
            switch (v) {
                case COURSE_ID_TOWN:
                    SetSeqVariableEnabled(0, 1);
                    SetSeqVariableEnabled(1, 1);
                    break;
                case COURSE_ID_MANSION:
                    csfx_setWallOverride(0x15, data_0216c860[0].field4, &data_0216c860[0]);
                    csfx_setWallOverride(0x8, data_0216c860[0].field4, &data_0216c860[0]);
                    csfx_setWallOverride(0x9, data_0216c860[0].field4, &data_0216c860[0]);
                    csfx_setWallOverride(0xd, data_0216c860[0].field4, &data_0216c860[0]);
                    csfx_setWallOverride(0xe, data_0216c860[0].field4, &data_0216c860[0]);
                    csfx_setWallOverride(0x10, data_0216c860[0].field4, &data_0216c860[0]);
                    break;
                case COURSE_ID_PINBALL:
                    csfx_setWallOverride(0x15, data_0216c860[1].field4, &data_0216c860[1]);
                    csfx_setWallOverride(0x8, data_0216c860[1].field4, &data_0216c860[1]);
                    csfx_setWallOverride(0x9, data_0216c860[1].field4, &data_0216c860[1]);
                    csfx_setWallOverride(0xd, data_0216c860[1].field4, &data_0216c860[1]);
                    csfx_setWallOverride(0xe, data_0216c860[1].field4, &data_0216c860[1]);
                    csfx_setWallOverride(0x10, data_0216c860[1].field4, &data_0216c860[1]);
                    break;
                case COURSE_ID_RIDGE:
                    csfx_setWallOverride(0x15, data_0216c860[2].field4, &data_0216c860[2]);
                    csfx_setWallOverride(0x8, data_0216c860[2].field4, &data_0216c860[2]);
                    csfx_setWallOverride(0x9, data_0216c860[2].field4, &data_0216c860[2]);
                    csfx_setWallOverride(0xd, data_0216c860[2].field4, &data_0216c860[2]);
                    csfx_setWallOverride(0xe, data_0216c860[2].field4, &data_0216c860[2]);
                    csfx_setWallOverride(0x10, data_0216c860[2].field4, &data_0216c860[2]);
                    break;
                case COURSE_ID_SNOW:
                    csfx_setWallOverride(0x15, data_0216c860[3].field4, &data_0216c860[3]);
                    csfx_setWallOverride(0x8, data_0216c860[3].field4, &data_0216c860[3]);
                    csfx_setWallOverride(0x9, data_0216c860[3].field4, &data_0216c860[3]);
                    csfx_setWallOverride(0xd, data_0216c860[3].field4, &data_0216c860[3]);
                    csfx_setWallOverride(0xe, data_0216c860[3].field4, &data_0216c860[3]);
                    csfx_setWallOverride(0x10, data_0216c860[3].field4, &data_0216c860[3]);
                    break;
                case COURSE_ID_CLOCK:
                    csfx_setWallOverride(0x15, data_0216c860[4].field4, &data_0216c860[4]);
                    csfx_setWallOverride(0x8, data_0216c860[4].field4, &data_0216c860[4]);
                    csfx_setWallOverride(0x9, data_0216c860[4].field4, &data_0216c860[4]);
                    csfx_setWallOverride(0xd, data_0216c860[4].field4, &data_0216c860[4]);
                    csfx_setWallOverride(0xe, data_0216c860[4].field4, &data_0216c860[4]);
                    csfx_setWallOverride(0x10, data_0216c860[4].field4, &data_0216c860[4]);
                    break;
                case COURSE_ID_AIRSHIP:
                    csfx_setWallOverride(0x15, data_0216c860[5].field4, &data_0216c860[5]);
                    csfx_setWallOverride(0x8, data_0216c860[5].field4, &data_0216c860[5]);
                    csfx_setWallOverride(0x9, data_0216c860[5].field4, &data_0216c860[5]);
                    csfx_setWallOverride(0xd, data_0216c860[5].field4, &data_0216c860[5]);
                    csfx_setWallOverride(0xe, data_0216c860[5].field4, &data_0216c860[5]);
                    csfx_setWallOverride(0x10, data_0216c860[5].field4, &data_0216c860[5]);
                    break;
                case COURSE_ID_STADIUM:
                    csfx_setWallOverride(0x15, data_0216c860[6].field4, &data_0216c860[6]);
                    csfx_setWallOverride(0x8, data_0216c860[6].field4, &data_0216c860[6]);
                    csfx_setWallOverride(0x9, data_0216c860[6].field4, &data_0216c860[6]);
                    csfx_setWallOverride(0xd, data_0216c860[6].field4, &data_0216c860[6]);
                    csfx_setWallOverride(0xe, data_0216c860[6].field4, &data_0216c860[6]);
                    csfx_setWallOverride(0x10, data_0216c860[6].field4, &data_0216c860[6]);
                    break;
                case COURSE_ID_GARDEN:
                    csfx_setWallOverride(0x15, data_0216c860[7].field4, &data_0216c860[7]);
                    csfx_setWallOverride(0x8, data_0216c860[7].field4, &data_0216c860[7]);
                    csfx_setWallOverride(0x9, data_0216c860[7].field4, &data_0216c860[7]);
                    csfx_setWallOverride(0xd, data_0216c860[7].field4, &data_0216c860[7]);
                    csfx_setWallOverride(0xe, data_0216c860[7].field4, &data_0216c860[7]);
                    csfx_setWallOverride(0x10, data_0216c860[7].field4, &data_0216c860[7]);
                    break;
                case COURSE_ID_KOOPA:
                    csfx_setWallOverride(0x15, data_0216c860[8].field4, &data_0216c860[8]);
                    csfx_setWallOverride(0x8, data_0216c860[8].field4, &data_0216c860[8]);
                    csfx_setWallOverride(0x9, data_0216c860[8].field4, &data_0216c860[8]);
                    csfx_setWallOverride(0xd, data_0216c860[8].field4, &data_0216c860[8]);
                    csfx_setWallOverride(0xe, data_0216c860[8].field4, &data_0216c860[8]);
                    csfx_setWallOverride(0x10, data_0216c860[8].field4, &data_0216c860[8]);
                    break;
                case COURSE_ID_OLD_BABY_GC:
                    csfx_setWallOverride(0x15, data_0216c860[9].field4, &data_0216c860[9]);
                    csfx_setWallOverride(0x8, data_0216c860[9].field4, &data_0216c860[9]);
                    csfx_setWallOverride(0x9, data_0216c860[9].field4, &data_0216c860[9]);
                    csfx_setWallOverride(0xd, data_0216c860[9].field4, &data_0216c860[9]);
                    csfx_setWallOverride(0xe, data_0216c860[9].field4, &data_0216c860[9]);
                    csfx_setWallOverride(0x10, data_0216c860[9].field4, &data_0216c860[9]);
                    break;
                case COURSE_ID_OLD_KINOKO_GC:
                    csfx_setWallOverride(0x15, data_0216c860[10].field4, &data_0216c860[10]);
                    csfx_setWallOverride(0x8, data_0216c860[10].field4, &data_0216c860[10]);
                    csfx_setWallOverride(0x9, data_0216c860[10].field4, &data_0216c860[10]);
                    csfx_setWallOverride(0xd, data_0216c860[10].field4, &data_0216c860[10]);
                    csfx_setWallOverride(0xe, data_0216c860[10].field4, &data_0216c860[10]);
                    csfx_setWallOverride(0x10, data_0216c860[10].field4, &data_0216c860[10]);
                    break;
                case COURSE_ID_OLD_HYUDORO_64:
                    csfx_setWallOverride(0x15, data_0216c860[11].field4, &data_0216c860[11]);
                    csfx_setWallOverride(0x8, data_0216c860[11].field4, &data_0216c860[11]);
                    csfx_setWallOverride(0x9, data_0216c860[11].field4, &data_0216c860[11]);
                    csfx_setWallOverride(0xd, data_0216c860[11].field4, &data_0216c860[11]);
                    csfx_setWallOverride(0xe, data_0216c860[11].field4, &data_0216c860[11]);
                    csfx_setWallOverride(0x10, data_0216c860[11].field4, &data_0216c860[11]);
                    break;
                case COURSE_ID_MINI_STAGE4:
                    csfx_setWallOverride(0x15, data_0216c860[12].field4, &data_0216c860[12]);
                    csfx_setWallOverride(0x8, data_0216c860[12].field4, &data_0216c860[12]);
                    csfx_setWallOverride(0x9, data_0216c860[12].field4, &data_0216c860[12]);
                    csfx_setWallOverride(0xd, data_0216c860[12].field4, &data_0216c860[12]);
                    csfx_setWallOverride(0xe, data_0216c860[12].field4, &data_0216c860[12]);
                    csfx_setWallOverride(0x10, data_0216c860[12].field4, &data_0216c860[12]);
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    csfx_setFloorOverride(data_0216c7e0.field10, data_0216c7e0.field14, &data_0216c7e0);
                    break;
                case COURSE_ID_MR_STAGE3:
                    csfx_setWallOverride(0x15, data_0216c860[13].field4, &data_0216c860[13]);
                    csfx_setWallOverride(0x8, data_0216c860[13].field4, &data_0216c860[13]);
                    csfx_setWallOverride(0x9, data_0216c860[13].field4, &data_0216c860[13]);
                    csfx_setWallOverride(0xd, data_0216c860[13].field4, &data_0216c860[13]);
                    csfx_setWallOverride(0xe, data_0216c860[13].field4, &data_0216c860[13]);
                    csfx_setWallOverride(0x10, data_0216c860[13].field4, &data_0216c860[13]);
                    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                        sub_21104DC(1);
                    }
                    break;
            }
            sfx_initSoundTriggers(v);
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                u8 *w = (u8 *) gRaceMultiConfig + 0x28;
                switch (gRaceMultiConfig->mMissionKind) {
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
                p = gSndHeapHandle;
                if (sLoadedCharacterSounds.field4 == 0xff00 || sLoadedCharacterSounds.field0 != 0xffff) {
                    NNS_SndHeapClear(snd_sDriverVoiceHeap);
                    sLoadedCharacterSounds.field4 = 0xff00;
                    sLoadedCharacterSounds.field0 = 0;
                    gSndHeapHandle = snd_sDriverVoiceHeap;
                    if (NNS_SndArcLoadBank(0x2c, snd_sDriverVoiceHeap) != 0) {
                        if (NNS_SndArcLoadSeqArc(3, gSndHeapHandle) != 0) {
                            gSndHeapHandle = p;
                            sLoadedCharacterSounds.field0 = 0xffff;
                            sLoadedCharacterSounds.field4 = 0xfe00;
                        }
                    }
                }
            }
            { break; }
        case 0xc:
            p = gSndHeapHandle;
            if (sLoadedCharacterSounds.field4 == 0xff00 || sLoadedCharacterSounds.field0 != 0xffff) {
                NNS_SndHeapClear(snd_sDriverVoiceHeap);
                sLoadedCharacterSounds.field4 = 0xff00;
                sLoadedCharacterSounds.field0 = 0;
                gSndHeapHandle = snd_sDriverVoiceHeap;
                if (NNS_SndArcLoadBank(0x2c, snd_sDriverVoiceHeap) != 0) {
                    if (NNS_SndArcLoadSeqArc(3, gSndHeapHandle) != 0) {
                        gSndHeapHandle = p;
                        sLoadedCharacterSounds.field0 = 0xffff;
                        sLoadedCharacterSounds.field4 = 0xfe00;
                    }
                }
            }
            { break; }
        case 0:
            break;
    }
    s.field0 = 0xff;
    s.field1 = buf.field0[0];
    s.field2 = buf.field0[1];
    sub_21103C0();
    InitSceneSoundState(c & 0xff, s, &gSceneSoundState);
    sfx_210912C();
    nullsub_13();
    InitKartSoundQueue();
    ResetSoundRequestQueues();
    sub_210FB68();
    if (*(vu16 *) 0x027ffc40 != 2) {
        LoadSceneSoundSet(buf, 0);
    }
    if (a != 1) {
        return;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcLoadBank(2, gSndHeapHandle);
    }
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    g_BackupSoundHeapStateId[0] = NNS_SndHeapSaveState(gSndHeapHandle);
    if (scproc_getCurrentScene() != 1) {
        return;
    }
    if (gStruct217B488->field8 == 3) {
        data_0217d070.fieldA = 0xff;
    }
}

void InitSceneSoundState(u32 a, Unk021073ec b, SceneSoundState *c) {
    c->mLapsDone = 0;
    NNS_SndHandleInit(&c->field8);
    c->field16 = 0;
    c->mOnLastLap = 0;
    c->field17 = 0;
    c->mRaceFrames = 0;
    c->mSceneFrames = 0;
    c->mRaceState = 0;
    c->mRankIndex = 0xff;
    c->mRankIndexAtSeq = 0xff;
    c->mRankSeqFrames = -1;
    c->field20 = 0;
    sub_210D740(&data_0217d070, c, a, b);
    SoundHandle_217D084.field18 = &sound_sStarMusicHandle;
    SetSoundMode(&SoundHandle_217D084, 0);
}

void snd_handleRaceStart(void) {
    s32 b;
    u32 c;
    s32 v;
    s32 i;
    NNSSndArc *n;
    NNSSndSeqPlayer **p;
    s32 j;

    if (*(u16 *) 0x27ffc40 == 2) {
        if (scproc_getCurrentScene() == 6) {
            return;
        }
    }
    sub_2111118();
    data_0217c780 = 0;
    sub_2109178((u32) &data_0217c780);
    b = 0;
    data_0217c7f0.field4 = 0;
    data_0217c7f0.fieldC = 0x7f;
    data_0217c7f0.field10 = 0x7f;
    data_0217c7f0.field8 = 0;
    if (scproc_getCurrentScene() == 2) {
        c = gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL || gRaceMultiConfig->mRaceKind == 2;
        if (c != 0) {
            b = 1;
        }
    }
    if (b != 0) {
        SetSoundMode(&SoundHandle_217D084, 2);
        data_0217c780 = 1;
        MKDS_SND_210D614(&data_0217d070, snd_getRaceStartSeqId(), NULL);
        data_0217c7b0 = 0;
        v = 0xffff;
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            switch (gRaceMultiConfig->mMissionTableValue) {
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
            switch (gRaceMultiConfig->mCourseId) {
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
            p = &data_0217c854;
            if ((data_0217c780 & 1) != 0) {
                if (SoundHandle_217D084.fieldC != 0) {
                    if (*p != NULL) {
                        NNS_SndPlayerStopSeq(p, 0);
                    }
                    if (*p != NULL) {
                        NNS_SndPlayerStopSeq(p, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(p, 0, v);
                }
            }
            data_0217c7b0 = 1;
        }
        if (gRaceMultiConfig->mMode != MODE_BATTLE) {
            SetLapProgressSoundGaps(gMapData->mCheckpointSum);
            gSceneSoundState.mLapCount = rconf_getLapCount();
        }
    } else {
        if (scproc_getCurrentScene() == 2) {
            if (gRaceMultiConfig->mRaceKind - 3 <= 1) {
                SetSoundMode(&SoundHandle_217D084, 2);
                data_0217c780 = 2;
            } else {
                if (sound_getIsSdatLoaded() != 0) {
                    n = NNS_SndArcGetCurrent();
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    v = 0xffff;
                    b = 0x7f;
                    for (i = 1; i <= 7; i++) {
                        if (NNS_SndArcGetPlayerInfo(i) != NULL) {
                            if (((v >> i) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(i, b);
                            }
                        }
                    }
                    NNS_SndArcSetCurrent(n);
                }
                data_0217c7f0.field4 = 0x7f000;
                SetSoundMode(&SoundHandle_217D084, 3);
                data_0217c780 = 0;
            }
        } else {
            if (sound_getIsSdatLoaded() != 0) {
                n = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
                v = 0xffff;
                b = 0x7f;
                for (j = 1; j <= 7; j++) {
                    if (NNS_SndArcGetPlayerInfo(j) != NULL) {
                        if (((v >> j) & 1) != 0) {
                            NNS_SndPlayerSetPlayerVolume(j, b);
                        }
                    }
                }
                NNS_SndArcSetCurrent(n);
            }
            data_0217c7f0.field4 = 0x7f000;
            SetSoundMode(&SoundHandle_217D084, 2);
            data_0217c780 = 0;
        }
    }
    MKDS_SND_210D6CC(&data_0217d070);
}

void StartRaceSounds(void) {
    s32 i;
    NNSSndSeqPlayer **handle;

    gSceneSoundState.mRaceState = 1;
    MKDS_SND_210D65C(&data_0217d070);
    data_0217c7f0.field8 = 1;
    if (data_0217c7b0 != 0) {
        NNS_SndPlayerStopSeq(&data_0217c854, 0x14);
    }
    if (gRaceMultiConfig->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    handle = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (SoundHandle_217D084.fieldC == 0) {
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

void snd_startStarMusic(void) {
    if (gSceneSoundState.mRaceState != 1) {
        return;
    }
    gSceneSoundState.field17 = 1;
    if ((gSceneSoundState.field16 & 1) != 0) {
        data_0217c7a8 = 1;
        return;
    }
    NNS_SndPlayerSetTrackMute(&data_0217d07c, 0xffff, 1);
    MKDS_SND_210D614(&data_0217d070, 0x49, &sound_sStarMusicHandle);
}

void snd_stopStarMusic(void) {
    NNS_SndPlayerSetTrackMute(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&sound_sStarMusicHandle, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            MKDS_SND_210D5C0(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            sub_210FAAC();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.field17 = 0;
}

void EndRaceSounds(void) {
    u32 fadeSteps;
    s32 i;
    s32 j;
    u8 *playerCursor;

    gSceneSoundState.mRaceState = 2;
    sub_210D590(&data_0217d070, GetEndRaceFadeSteps());
    NNS_SndPlayerSetTrackMute(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&sound_sStarMusicHandle, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            MKDS_SND_210D5C0(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            sub_210FAAC();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.field17 = 0;
    if (SoundHandle_217D084.mMode == 2) {
        SetSoundMode(&SoundHandle_217D084, 3);
    }
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, GetEndRaceFadeSteps());
    }
    fadeSteps = GetEndRaceFadeSteps();
    for (j = 0, playerCursor = (&sound_sPools)->mEntries; j < (&sound_sPools)->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&sound_sPools)->mEntrySize;
    }
}

// Counts a lap done by the selected kart; one lap before the end it switches to seq 0x3e.
void snd_handleLapChange(void) {
    BOOL b;
    s32 i;
    NNSSndSeqPlayer **p;

    b = FALSE;
    if (scproc_getCurrentScene() == 2) {
        if (gRaceMultiConfig->mRaceKind == RACE_KIND_DEMO) {
            return;
        }
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        return;
    }
    gSceneSoundState.mLapsDone = gSceneSoundState.mLapsDone + 1;
    if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount) {
        b = TRUE;
    } else if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount - 1) {
        gSceneSoundState.field16 = 1;
        gSceneSoundState.mOnLastLap = 1;
        sub_210D590(&data_0217d070, 0);
        if (gSceneSoundState.field8 != NULL) {
            NNS_SndPlayerSetTrackMute(&sound_sStarMusicHandle, 0xffff, 1);
        }
        MKDS_SND_210D614(&data_0217d070, 0x3e, NULL);
        gSceneSoundState.field16 = 1;
    }
    if (gRaceMultiConfig->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    if (b != FALSE) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    p = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (SoundHandle_217D084.fieldC == 0) {
        return;
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    NNS_SndArcPlayerStartSeqArc(p, 0, 0x1c1);
}

// Stores the selected kart's new place; in some courses it starts a seq when the place improves.
void snd_handlePositionChangeSfx(u32 a) {
    BOOL b;
    BOOL c;
    u32 d;
    u32 e;
    u32 v;
    s32 i;
    NNSSndSeqPlayer *p;
    NNSSndSeqPlayer **q;

    b = FALSE;
    if (scproc_getCurrentScene() == 2) {
        c = gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL || gRaceMultiConfig->mRaceKind == 2;
        if (c != FALSE) {
            b = TRUE;
        }
    }
    if (b == FALSE) {
        return;
    }
    if ((u32) gRaceMultiConfig->mMode - 1 <= 1) {
        return;
    }
    v = -1;
    b = FALSE;
    if (gSceneSoundState.mRaceFrames <= 0xf0) {
        gSceneSoundState.mRankIndex = a;
        return;
    }
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mOnLastLap != 0) {
                v = 0x1c2;
                for (i = 7; i < 12; i++) {
                    NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, data_0217c838, i * sizeof(NNSSndSeqPlayer *)),
                                         b);
                }
                b = TRUE;
            }
            { break; }
        case COURSE_ID_PINBALL:
            v = a == 0 ? 0x1cb : 0x1ca;
            b = TRUE;
            p = data_0217c838[7];
            d = p != NULL && p->mSeqArcIndex == 0x1cc && p->mSeqNo == 0;
            if (d != 0) {
                b = FALSE;
            }
            break;
    }
    if (b != FALSE) {
        if (a < gSceneSoundState.mRankIndex) {
            e = 0;
            if (gSceneSoundState.mRankSeqFrames != -1) {
                if (gSceneSoundState.mRankIndexAtSeq > a) {
                    e = 1;
                }
            } else {
                e = 1;
            }
            if (e != 0) {
                NNS_SndPlayerStopSeq(&data_0217c854, 0);
                q = &data_0217c854;
                if (data_0217c780 & 1) {
                    if (SoundHandle_217D084.fieldC != 0) {
                        if (*q != NULL) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        if (*q != NULL) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(q, 0, (u16) v);
                    }
                }
                gSceneSoundState.mRankIndexAtSeq = a;
                gSceneSoundState.mRankSeqFrames = 0;
            }
        }
    }
    gSceneSoundState.mRankIndex = a;
}

void snd_2106580(void) {
    Unk0217c7f0 *q;
    NNSSndSeqPlayer **v;
    u32 a;
    s32 i;
    s32 b;
    s32 n;
    struct NNSSndArc *p;

    switch (gSceneSoundState.mRaceState) {
        case 1:
            gSceneSoundState.mRaceFrames++;
            if (gSceneSoundState.mRaceFrames == 0x28) {
                MKDS_SND_210D5C0(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
            }
            q = &data_0217c7f0;
            i = q->field8;
            if (i == 1) {
                q->field0 = data_0217c80c[i];
                a = StepValueTowardTarget(q, data_0217c7fc[i]);
                if (a != -1) {
                    b = data_0217c804[i];
                    if (sound_getIsSdatLoaded() != 0) {
                        p = NNS_SndArcGetCurrent();
                        NNS_SndArcSetCurrent(&gSdatFileSndArc);
                        for (n = 1; n <= 7; n++) {
                            if (NNS_SndArcGetPlayerInfo(n) != NULL && ((b >> n) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(n, a);
                            }
                        }
                        NNS_SndArcSetCurrent(p);
                    }
                }
            }
            sub_210FAF4();
            UpdateSoundPitchSwing();
            break;
        case 2:
            sub_2111024();
            break;
    }
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        v = &data_0217d07c;
        if (IsAnySeqVariableEnabled() != 0) {
            sndvar_update(v);
            if (gRaceMultiConfig->mCourseId == COURSE_ID_TOWN) {
                if (sndvar_getVarField4IsZero(0) != 0 || sndvar_getVarField4IsZero(1) != 0) {
                    sfx_updateSoundTriggerVolumeAtStart(0, 0x1a9);
                }
            }
        }
        if (gRaceMultiConfig->mCourseId == COURSE_ID_KOOPA) {
            sfx_updateSoundTriggerVolumeContinuous(0, 0x16b);
        }
        if (gSceneSoundState.mRankSeqFrames != -1) {
            if (++gSceneSoundState.mRankSeqFrames >= 0x3c) {
                gSceneSoundState.mRankSeqFrames = -1;
            }
        }
        if (gSceneSoundState.field16 == 1 && v[0] == NULL) {
            gSceneSoundState.field16 = 0;
            if (data_0217c7a8 != 0 && gSceneSoundState.field17 == 1) {
                if (gSceneSoundState.mRaceState == 1) {
                    gSceneSoundState.field17 = 1;
                    if ((gSceneSoundState.field16 & 1) == 0) {
                        NNS_SndPlayerSetTrackMute(&data_0217d07c, 0xffff, 1);
                        MKDS_SND_210D614(&data_0217d070, 0x49, &sound_sStarMusicHandle);
                    }
                }
                data_0217c7a8 = 0;
                data_0217c78c = 1;
            } else if (gSceneSoundState.field8 != NULL) {
                NNS_SndPlayerSetTrackMute(&sound_sStarMusicHandle, 0xffff, 0);
                data_0217c78c = 1;
            } else if (gSceneSoundState.mRaceState == 1) {
                MKDS_SND_210D5C0(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, gVolumeFade.mVolume >> 12);
                NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
                sub_210FAAC();
            }
        }
    } else {
        UpdateKartSoundQueue();
    }
    data_0217d1f8 = data_0217d20c;
}

void snd_handleIntroAmbiance(void) {
    u32 v;
    NNSSndSeqPlayer **p;

    v = 0xffff;
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x1bc;
            }
            break;
        case COURSE_ID_RIDGE:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x1a6;
            }
            break;
        case COURSE_ID_GARDEN:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x1a5;
            }
            break;
        case COURSE_ID_MANSION:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x126;
            }
            break;
        case COURSE_ID_AIRSHIP:
            switch (gSceneSoundState.mSceneFrames) {
                case 0xa:
                    v = 0x1d2;
                    break;
                case 0xa0:
                    NNS_SndPlayerStopSeq(&data_0217c854, 0x3c);
                    break;
                case 0x122:
                    v = 0x1d2;
                    break;
            }
            { break; }
        case COURSE_ID_KOOPA:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x1aa;
            }
            break;
        case COURSE_ID_CLOCK:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x192;
            }
            break;
        case COURSE_ID_MARIO:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x19b;
            }
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x112;
            }
            break;
        case COURSE_ID_BEACH:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x112;
            }
            break;
        case COURSE_ID_OLD_MOMO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x12b;
            }
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x19a;
            }
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                v = 0x1d5;
            }
            break;
        case COURSE_ID_RAINBOW:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                v = 0x1ba;
            }
            break;
        case COURSE_ID_TOWN:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                v = 0x199;
            }
            break;
    }
    if (v == 0xffff) {
        return;
    }
    NNS_SndPlayerStopSeq(&data_0217c854, 0);
    p = &data_0217c854;
    if ((data_0217c780 & 2) == 0) {
        return;
    }
    if (SoundHandle_217D084.fieldC == 0) {
        return;
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    NNS_SndArcPlayerStartSeqArc(p, 0, v);
}

void UpdateSceneSoundState(void) {
    Unk0217c7f0 *q;
    s32 i;
    s32 a;
    s32 b;
    s32 n;
    struct NNSSndArc *p;

    q = &data_0217c7f0;
    i = q->field8;
    if (i == 0) {
        q->field0 = data_0217c80c[i];
        a = StepValueTowardTarget(q, data_0217c7fc[i]);
        if (a != -1) {
            b = data_0217c804[i];
            if (sound_getIsSdatLoaded() != 0) {
                p = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
                for (n = 1; n <= 7; n++) {
                    if (NNS_SndArcGetPlayerInfo(n) != NULL && ((b >> n) & 1) != 0) {
                        NNS_SndPlayerSetPlayerVolume(n, a);
                    }
                }
                NNS_SndArcSetCurrent(p);
            }
        }
    }
    if (scproc_getCurrentScene() == 2) {
        switch (gRaceMultiConfig->mRaceKind) {
            case RACE_KIND_NORMAL:
            case 2:
                snd_2106580();
                break;
            case RACE_KIND_START_GP:
            case 4:
                snd_handleIntroAmbiance();
                break;
        }
    } else if (scproc_getCurrentScene() == 9) {
        if (gSceneSoundState.mSceneFrames == 0x5d) {
            NNS_SndPlayerStopSeq(&data_0217d07c, 0x1b);
        }
    } else if (scproc_getCurrentScene() == 1 || scproc_getCurrentScene() == 0xc) {
        if (*(vu16 *) 0x027ffc40 != 2) {
            UpdateSeqQueue();
        }
    } else if (scproc_getCurrentScene() == 3) {
        sub_2110874();
    }
    if (data_0217d060 != NULL && data_0217d060->mSoundSet.mSeqId == 0 && data_0217d060->mSeqPlayer != NULL) {
        sndvar_update(&data_0217d060->mSeqPlayer);
    }
    gSceneSoundState.mSceneFrames++;
}

void StopSceneSounds(void) {
    u32 fadeSteps;
    s32 i;
    s32 j;
    u8 *playerCursor;

    if (*(vu16 *) 0x027ffc40 == 2 && scproc_getCurrentScene() == 6) {
        return;
    }
    data_0217c7f0.fieldC = 0;
    data_0217c7f0.field8 = 0;
    nullsub_14(&data_0217d070);
    SetSoundMode(&SoundHandle_217D084, 4);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, sound_getFadeFrameCount());
    }
    fadeSteps = sound_getFadeFrameCount();
    for (j = 0, playerCursor = (&sound_sPools)->mEntries; j < (&sound_sPools)->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&sound_sPools)->mEntrySize;
    }
    NNS_SndPlayerStopSeq(&data_0217c788, 13);
    NNS_SndPlayerStopSeq(&data_0217c778, 13);
    data_0217c7a4 = 0;
}

void StopSceneSoundsAtOnce(void) {
    s32 i;
    s32 j;
    u8 *playerCursor;
    Unk0217c7c4 *playerTable;

    if (*(vu16 *) 0x027ffc40 == 2 && scproc_getCurrentScene() == 6) {
        return;
    }
    data_0217c7f0.fieldC = 0;
    data_0217c7f0.field8 = 0;
    sub_210D570(&data_0217d070, 1);
    SetSoundMode(&SoundHandle_217D084, 0);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, 0);
    }
    playerTable = &sound_sPools;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, 0);
        playerCursor += playerTable->mEntrySize;
    }
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c788, 0);
    NNS_SndPlayerStopSeq(&data_0217c778, 0);
}

void sound_2105E98(void) {
    u32 fadeSteps;
    fadeSteps = sound_getFadeFrameCount();
    NNS_SndPlayerStopSeq(&data_0217d07c, fadeSteps);
}

void sfx_handleRacePause(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    Unk0217c7c4 *playerTable;

    savedFadeSteps = sound_getFadeFrameCount();
    gSceneSoundState.field20 = 1;
    sound_setFadeFrameCount(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x11);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    SetSoundMode(&SoundHandle_217D084, 5);
    if (gSceneSoundState.field16 == 1) {
        gSceneSoundState.field16 = 3;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0, sound_getFadeFrameCount());
        handleCursor++;
    }
    fadeSteps = sound_getFadeFrameCount();
    playerTable = &sound_sPools;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    sound_setFadeFrameCount(savedFadeSteps);
}

void sfx_handleRaceContinue(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    Unk0217c7c4 *playerTable;

    savedFadeSteps = sound_getFadeFrameCount();
    gSceneSoundState.field20 = 0;
    sound_setFadeFrameCount(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x12);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    RestoreSavedSoundMode(&SoundHandle_217D084);
    if (gSceneSoundState.field16 == 3) {
        gSceneSoundState.field16 = 1;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0x7f, sound_getFadeFrameCount());
        handleCursor++;
    }
    fadeSteps = sound_getFadeFrameCount();
    playerTable = &sound_sPools;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0x7f, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    sound_setFadeFrameCount(savedFadeSteps);
}

void sfx_emitRaceChoiceActivationSound(s32 a) {
    u32 fadeSteps;
    s32 j;
    u8 *playerCursor;
    s32 i;
    NNSSndSeqPlayer **handleCursor;
    Unk0217c7c4 *playerTable;
    u32 seqNo;

    seqNo = sfx_sRaceChoiceSelectSfxIds[a];
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, seqNo);
    if (a == 4) {
        return;
    }
    handleCursor = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerStopSeq(handleCursor, sound_getFadeFrameCount());
        handleCursor++;
    }
    fadeSteps = sound_getFadeFrameCount();
    playerTable = &sound_sPools;
    for (j = 0, playerCursor = playerTable->mEntries; j < playerTable->mCount; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundMode(&SoundHandle_217D084, 4);
}

void sound_stopSeqAll(void) {
    NNS_SndPlayerStopSeqAll(sound_getFadeFrameCount());
}

void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume) {
    NNS_SndPlayerSetTrackVolume(handle, data_0216cb20, (u8) volume);
}

void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch) {
    NNS_SndPlayerSetTrackPitch(handle, data_0216cb20, pitch);
}

// Starts sound a on the shared handle unless one was already started this frame.
void sfx_2105AC0(s32 seqNo) {
    if (gSoundStartedThisFrame != 0) {
        return;
    }
    gSoundStartedThisFrame = 1;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, seqNo);
}

void MKDS_SND_PlayTwinkelSound(u32 a) {
    s32 seqNo;

    data_0217c784 = a;
    if (a - 1 > 1) {
        return;
    }
    seqNo = (a == 1) ? 0x47 : 0x48;
    NNS_SndHeapLoadState(gSndHeapHandle, g_BackupSoundHeapStateId[0]);
    NNS_SndHeapGetCurrentLevel(gSndHeapHandle);
    NNS_SndArcLoadSeq(seqNo, gSndHeapHandle);
    NNS_SndPlayerStopSeq(&data_0217d07c, 2);
    sound_startSeq(seqNo, 0x7f, &data_0217c83c);
}

void func_021059e0(void) {
    if (data_0217d070.fieldC != NULL) {
        return;
    }
    if (data_0217c838[1] != NULL) {
        return;
    }
    MKDS_SND_210D5C0(&data_0217d070);
}

void func_02105980(int a, u32 fadeSteps) {
    if (data_0217c784 - 1 <= 1) {
        NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    }
    if (a == 3) {
        NNS_SndPlayerStopSeq(&data_0217d07c, fadeSteps);
        return;
    }
}

void func_0210593c(u32 a) {
    if (a != 4) {
        return;
    }
    if (data_0217d070.fieldC != NULL) {
        return;
    }
    MKDS_SND_210D5C0(&data_0217d070);
}

void sub_21057F0(u32 a, u32 b) {
    u32 bankNo = 0xff;
    data_0217c784 = a;
    data_0217c79c = 0;
    data_0217c7a0 = 0;
    data_0217c774 = 0xff;
    if (a != 3) {
        return;
    }
    switch (b) {
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
    NNS_SndHeapLoadState(gSndHeapHandle, g_BackupSoundHeapStateId[0]);
    NNS_SndHeapGetCurrentLevel(gSndHeapHandle);
    NNS_SndArcLoadBank(bankNo, gSndHeapHandle);
    NNS_SndArcLoadBank(0x2a, gSndHeapHandle);
    NNS_SndArcLoadSeqArc(4, gSndHeapHandle);
}

void func_021055b0(s32 a) {
    s32 trackVolume;
    u32 f;
    s32 n;
    if (data_0217c784 == 0) {
        if (data_0217d070.fieldC != NULL) {
            return;
        }
        MKDS_SND_210D5C0(&data_0217d070);
        return;
    }
    if (a != 0 && a != 0x32) {
        return;
    }
    f = 0;
    trackVolume = 0x78;
    n = (a == 0x32) ? data_0217c79c : data_0217c7a0;
    if (n < 5) {
        switch (n) {
            case 0:
                trackVolume = 0xf;
                break;
            case 1:
                trackVolume = 0x1e;
                f = 1;
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
        switch ((n - 5) % 6) {
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
                f = 1;
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
        NNSSndSeqPlayer **p = &data_0217c83c;
        if (*p != NULL) {
            NNS_SndPlayerStopSeq(p, 0);
        }
        NNS_SndArcPlayerStartSeqArc(p, 4, 0);
        if (*p != NULL) {
            NNS_SndPlayerSetTrackVolume(p, data_0216cb20, trackVolume & 0xff);
        }
        data_0217c79c++;
        return;
    }
    if (a != 0) {
        return;
    }
    if (f != 0) {
        u16 h = data_0217c774;
        if (h != 0xff) {
            NNSSndSeqPlayer **p = &data_0217c840;
            if (*p != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            NNS_SndArcPlayerStartSeqArc(p, 4, h);
        }
    }
    data_0217c7a0++;
}

void func_02105584(u32 a, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    NNS_SndPlayerStopSeq(&data_0217c840, fadeSteps);
}

void func_02105550(void) {
    NNS_SndPlayerStopSeq(&data_0217c83c, 0);
    NNS_SndPlayerStopSeq(&data_0217c840, 0);
}

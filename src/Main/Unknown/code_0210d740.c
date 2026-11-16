#include "Main/Unknown/code_0210d740.h"

#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210dc60.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212df7c.h"
#include "code_0212d214.h"
#include "output_effect.h"
#include "code_0212ba68.h"
#include "Main/Unknown/code_0210d890.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"

void sound_setIsSdatLoaded(u32 flag) {
    sSdatFileLoaded = flag;
}

u32 sound_getIsSdatLoaded(void) {
    return sSdatFileLoaded;
}

void sound_setFadeFrameCount(u32 fadeSteps) {
    sFadeFrameCount = fadeSteps;
}

u32 sound_getFadeFrameCount(void) {
    return sFadeFrameCount;
}

void Sound_InitializeWithData(void *heapMemory, u32 heapSize, const u8 *filePath) {
    NNS_SndInit();
    gSndHeapHandle = NNS_SndHeapCreate(heapMemory, heapSize);
    sOutputEffectBuffer = NNS_SndHeapAlloc(gSndHeapHandle, 0x1020, outputEffectBufferDisposeCallback, NULL, 0);
    if (filePath != NULL) {
        NNS_SndArcInit(&gSdatFileSndArc, filePath, gSndHeapHandle, 0);
        sSdatFileLoaded = 1;
        NNS_SndArcPlayerSetup(gSndHeapHandle);
    }
    NNS_SndHandleInit(&data_0217d068);
    SetupSoundMode(&SoundHandle_217D084, &data_0217d070, 0);
}

void outputEffectBufferDisposeCallback(void *memory, u32 size, void *data1, u32 data2) {}

void sound_startOutputEffect(u32 type) {
    NNS_SndCaptureStartOutputEffect((void *) (((u32) sOutputEffectBuffer + 0x1f) & ~0x1f), 0x1000, type);
    sCurOutputEffect = type;
}

void sound_changeOutputEffect(s32 type) {
    NNS_SndCaptureChangeOutputEffect(type);
    sCurOutputEffect = type;
}

void sound_startSeq(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle) {
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcGetFileAddress(NNS_SndArcGetSeqInfo(seqNo)->mFileId);
    NNS_SndArcPlayerStartSeq(handle, seqNo);
    NNS_SndPlayerSetVolume(handle, volume);
}

void sub_210D7AC(void) {
    if (data_0217d070.field0 != 0) {
        nullsub_15(&data_0217d070);
    }
    NNS_SndMain();
}

void sub_210D740(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 c, Unk021073ec d) {
    SetupSoundMode(&SoundHandle_217D084, scenePlayers, 0);
    *(Unk021073ec *) &scenePlayers->field9 = d;
    scenePlayers->field4 = sceneSoundState;
    scenePlayers->field8 = c;
    NNS_SndHandleInit(&scenePlayers->fieldC);
    NNS_SndHandleInit(&scenePlayers->field10);
    scenePlayers->field0 = 1;
}

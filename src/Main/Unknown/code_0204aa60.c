#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "pm.h"

void sysdat_loadSeq(s32 seqId) {
    if (gSystemData->mSoundSetPlayerInitialized) {
        return;
    }
    gSystemData->mSoundSetPlayerInitialized = 1;
    LoadSomeSseq(&gSystemData->mSoundSetPlayer, seqId, 0xff);
}

void sysdat_startSeq(void) {
    if (!gSystemData->mSoundSetPlayerInitialized) {
        return;
    }
    if (gSystemData->mSoundSetSeqPlaying) {
        return;
    }
    gSystemData->mSoundSetSeqPlaying = 1;
    sound_seqHandleStart(&gSystemData->mSoundSetPlayer, data_0216cb28);
}

void sysdat_stopSeq(void) {
    Unk021759d0 *p = gSystemData;

    if (!p->mSoundSetSeqPlaying) {
        return;
    }
    sound_seqHandleStop(&p->mSoundSetPlayer, sound_getFadeFrameCount());
    gSystemData->mSoundSetSeqPlaying = 0;
}

void sysdat_unloadSeq(void) {
    if (gSystemData->mSoundSetSeqPlaying) {
        return;
    }
    if (!gSystemData->mSoundSetPlayerInitialized) {
        return;
    }
    sound_seqHandleUnload(&gSystemData->mSoundSetPlayer);
    gSystemData->mSoundSetPlayerInitialized = 0;
}

void sysdat_204AB64(u32 fadeSteps) {
    if (!gSystemData->mSoundSetSeqPlaying) {
        return;
    }
    sound_seqHandleStop(&gSystemData->mSoundSetPlayer, fadeSteps);
}

BOOL sysdat_configureBackLight(s32 firstRequest, s32 secondRequest) {
    Unk021759d0 *p = gSystemData;
    s32 firstBackLightOn = p->mFirstBackLightOn;
    s32 secondBackLightOn = p->mSecondBackLightOn;
    BOOL allSet = TRUE;

    if (firstRequest == 0) {
        firstBackLightOn = 1;
    } else if (firstRequest == 1) {
        firstBackLightOn = 0;
    }
    if (secondRequest == 0) {
        secondBackLightOn = 1;
    } else if (secondRequest == 1) {
        secondBackLightOn = 0;
    }
    if (firstBackLightOn != p->mFirstBackLightOn) {
        if (PM_SetBackLight(0, firstBackLightOn) == 0) {
            gSystemData->mFirstBackLightOn = firstBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    if (secondBackLightOn != gSystemData->mSecondBackLightOn) {
        if (PM_SetBackLight(1, secondBackLightOn) == 0) {
            gSystemData->mSecondBackLightOn = secondBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    return allSet;
}

RandomState64 *sysdat_getRandom(void) {
    void *random = NULL;
    Unk021759d0 *p = gSystemData;

    switch (p->field20) {
        case 0:
        case 3:
            random = &p->mRandom;
            break;
        case 1:
        case 2:
            random = &gStruct217AA00->field1EE8;
            break;
    }
    return random;
}

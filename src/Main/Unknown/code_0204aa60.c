#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "pm.h"

void InitSceneSoundSetPlayer(s32 seqId) {
    if (gStartupWork->mSoundSetPlayerInitialized) {
        return;
    }
    gStartupWork->mSoundSetPlayerInitialized = 1;
    InitSoundSetPlayerWithVariables(&gStartupWork->mSoundSetPlayer, seqId, 0xff);
}

void StartSceneSoundSetSeq(void) {
    if (!gStartupWork->mSoundSetPlayerInitialized) {
        return;
    }
    if (gStartupWork->mSoundSetSeqPlaying) {
        return;
    }
    gStartupWork->mSoundSetSeqPlaying = 1;
    StartSoundSetSeq(&gStartupWork->mSoundSetPlayer, gSceneSeqVolume);
}

void StopSceneSoundSetSeq(void) {
    StartupWork *p = gStartupWork;

    if (!p->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&p->mSoundSetPlayer, GetSoundFadeSteps());
    gStartupWork->mSoundSetSeqPlaying = 0;
}

void ReleaseSceneSoundSetPlayer(void) {
    if (gStartupWork->mSoundSetSeqPlaying) {
        return;
    }
    if (!gStartupWork->mSoundSetPlayerInitialized) {
        return;
    }
    ReleaseSoundSetPlayer(&gStartupWork->mSoundSetPlayer);
    gStartupWork->mSoundSetPlayerInitialized = 0;
}

void StopSceneSoundSetSeqWithSteps(u32 fadeSteps) {
    if (!gStartupWork->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&gStartupWork->mSoundSetPlayer, fadeSteps);
}

BOOL TrySetBackLights(s32 firstRequest, s32 secondRequest) {
    StartupWork *p = gStartupWork;
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
            gStartupWork->mFirstBackLightOn = firstBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    if (secondBackLightOn != gStartupWork->mSecondBackLightOn) {
        if (PM_SetBackLight(1, secondBackLightOn) == 0) {
            gStartupWork->mSecondBackLightOn = secondBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    return allSet;
}

RandomState64 *GetRandomState(void) {
    void *random = NULL;
    StartupWork *p = gStartupWork;

    switch (p->mConnectionKind) {
        case 0:
        case 3:
            random = &p->mRandom;
            break;
        case 1:
        case 2:
            random = &gConnectionWork->mRandomState;
            break;
    }
    return random;
}

#include "Main/Sound/scene_sound_set.h"
#include "Main/System/frm_heap_reset.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/backup_net_camera_work.h"
#include "power_management_commands.h"

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
    StartupWork *startupWork = gStartupWork;

    if (!startupWork->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&startupWork->mSoundSetPlayer, GetSoundFadeSteps());
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
    StartupWork *startupWork = gStartupWork;
    s32 firstBackLightOn = startupWork->mFirstBackLightOn;
    s32 secondBackLightOn = startupWork->mSecondBackLightOn;
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
    if (firstBackLightOn != startupWork->mFirstBackLightOn) {
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
    StartupWork *startupWork = gStartupWork;

    switch (startupWork->mConnectionKind) {
        case CONNECTION_KIND_NONE:
        case CONNECTION_KIND_WIFI_MENU:
            random = &startupWork->mRandom;
            break;
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            random = &gConnectionWork->mRandomState;
            break;
    }
    return random;
}

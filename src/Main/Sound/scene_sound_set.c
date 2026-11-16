#include "Main/Sound/scene_sound_set.h"
#include "Main/System/frm_heap_reset.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/backup_net_camera_work.h"
#include "power_management_commands.h"

void SetSomeSceneSseqId(s32 seqId) {
    if (g_GlobalP->mSoundSetPlayerInitialized) {
        return;
    }
    g_GlobalP->mSoundSetPlayerInitialized = 1;
    LoadSomeSseq(&g_GlobalP->mSoundSetPlayer, seqId, 0xff);
}

void StartSceneSoundSetSeq(void) {
    if (!g_GlobalP->mSoundSetPlayerInitialized) {
        return;
    }
    if (g_GlobalP->mSoundSetSeqPlaying) {
        return;
    }
    g_GlobalP->mSoundSetSeqPlaying = 1;
    StartSoundSetSeq(&g_GlobalP->mSoundSetPlayer, gSceneSeqVolume);
}

void StopSceneSoundSetSeq(void) {
    StartupWork *startupWork = g_GlobalP;

    if (!startupWork->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&startupWork->mSoundSetPlayer, GetSoundFadeSteps());
    g_GlobalP->mSoundSetSeqPlaying = 0;
}

void ReleaseSceneSoundSetPlayer(void) {
    if (g_GlobalP->mSoundSetSeqPlaying) {
        return;
    }
    if (!g_GlobalP->mSoundSetPlayerInitialized) {
        return;
    }
    ReleaseSoundSetPlayer(&g_GlobalP->mSoundSetPlayer);
    g_GlobalP->mSoundSetPlayerInitialized = 0;
}

void StopSceneSoundSetSeqWithSteps(u32 fadeSteps) {
    if (!g_GlobalP->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&g_GlobalP->mSoundSetPlayer, fadeSteps);
}

BOOL TrySetBackLights(s32 firstRequest, s32 secondRequest) {
    StartupWork *startupWork = g_GlobalP;
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
            g_GlobalP->mFirstBackLightOn = firstBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    if (secondBackLightOn != g_GlobalP->mSecondBackLightOn) {
        if (PM_SetBackLight(1, secondBackLightOn) == 0) {
            g_GlobalP->mSecondBackLightOn = secondBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    return allSet;
}

RandomState64 *GetRandomState(void) {
    void *random = NULL;
    StartupWork *startupWork = g_GlobalP;

    switch (startupWork->mConnectionKind) {
        case CONNECTION_KIND_NONE:
        case CONNECTION_KIND_WIFI_MENU:
            random = &startupWork->mRandom;
            break;
        case CONNECTION_KIND_MEMBER_SELECT:
        case CONNECTION_KIND_WL_MENU:
            random = &g_GlobalZE->mRandomState;
            break;
    }
    return random;
}

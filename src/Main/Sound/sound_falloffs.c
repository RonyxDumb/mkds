#include "Main/Sound/sound_falloffs.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Scene/run_scenes.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Kart/camera_entry.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "registers.h"
#include "Main/Sound/snd_handle_slots.h"

void StopKartSoundWhileRequested(Kart *kart) {
    if (kart->mSound.mWhileRequestedSoundId == 0xffff) {
        return;
    }
    StopSoundEx(&kart->mSoundSource, 0, kart->mSound.mWhileRequestedSoundId, 0);
    kart->mSound.mWhileRequestedSoundId = 0xffff;
}

void InitSoundFalloffs(void) {
    BOOL isReplayScene;
    SoundFalloffSettings workSettings0;
    SoundFalloffSettings workSettings1;
    SoundFalloffSettings workSettings2;
    SoundFalloffSettings workSettings3;
    SoundFalloffSettings workSettings4;
    SoundFalloffSettings replaySettings0;
    SoundFalloffSettings copiedSettings0;
    SoundFalloffSettings replaySettings1;
    SoundFalloffSettings copiedSettings1;
    SoundFalloffSettings replaySettings2;
    SoundFalloffSettings copiedSettings2;
    SoundFalloffSettings replaySettings3;
    SoundFalloffSettings copiedSettings3;
    SoundFalloffSettings replaySettings4;
    SoundFalloffSettings copiedSettings4;
    SoundFalloffSettings copiedSettings5;
    SoundFalloffSettings copiedSettings6;
    SoundFalloffSettings copiedSettings7;
    SoundFalloffSettings copiedSettings8;
    SoundFalloffSettings copiedSettings9;
    SoundFalloffSettings copiedSettings10;
    SoundFalloffSettings copiedSettings11;
    SoundFalloffSettings copiedSettings12;
    SoundFalloffSettings copiedSettings13;
    SoundFalloffSettings copiedSettings14;
    SoundFalloffSettings copiedSettings15;
    SoundFalloffSettings copiedSettings16;
    static SoundFalloffSettings defaultSettings14 = {1400, 750, 55, 100, 110};
    static SoundFalloffSettings defaultSettings3 = {380, 304, 66, 150, 95};
    static SoundFalloffSettings defaultSettings4 = {800, 500, 57, 150, 95};
    static SoundFalloffSettings defaultSettings6 = {3000, 1500, 52, 150, 95};
    static SoundFalloffSettings defaultSettings5 = {1100, 550, 47, 150, 95};
    static SoundFalloffSettings defaultSettings7 = {600, 400, 47, 150, 95};
    static SoundFalloffSettings defaultSettings8 = {1500, 900, 69, 150, 115};
    static SoundFalloffSettings defaultSettings9 = {1200, 600, 47, 150, 95};
    static SoundFalloffSettings defaultSettings10 = {5000, 4000, 88, 150, 127};
    static SoundFalloffSettings defaultSettings11 = {1100, 550, 62, 150, 95};
    static SoundFalloffSettings defaultSettings2 = {1100, 500, 71, 150, 95};
    static SoundFalloffSettings defaultSettings13 = {1000, 650, 55, 300, 110};
    static SoundFalloffSettings defaultSettings12 = {800, 400, 47, 54, 95};
    static SoundFalloffSettings defaultSettings15 = {1100, 600, 55, 100, 110};
    static SoundFalloffSettings defaultSettings16 = {950, 525, 55, 100, 110};
    static SoundFalloffSettings defaultSettings0 = {800, 500, 47, 150, 127};
    static SoundFalloffSettings defaultSettings1 = {800, 500, 47, 150, 95};

    if (GetCurrentSceneNumber() == 2 && gRaceSetup->mRaceKind == RACE_KIND_REPLAY) {
        isReplayScene = TRUE;
    } else {
        isReplayScene = FALSE;
    }
    workSettings0 = defaultSettings0;
    if (isReplayScene != FALSE) {
        replaySettings0 = workSettings0;
        replaySettings0.mOuterDistance = 0x44c;
        replaySettings0.mUnk_04 = 0x226;
        replaySettings0.mUnk_08 = 0x2f;
        replaySettings0.mMaxVolume = 0x5f;
        workSettings0 = replaySettings0;
    }
    copiedSettings0 = workSettings0;
    gSoundFalloffs[0].mMaxVolume = copiedSettings0.mMaxVolume;
    gSoundFalloffs[0].mOuterDistance = copiedSettings0.mOuterDistance;
    gSoundFalloffs[0].mUnk_04 = copiedSettings0.mUnk_04;
    gSoundFalloffs[0].mUnk_08 = copiedSettings0.mUnk_08;
    gSoundFalloffs[0].mInnerDistance = copiedSettings0.mInnerDistance;
    gSoundFalloffs[0].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings0.mUnk_08 - copiedSettings0.mMaxVolume),
                                       TO_FIXED12(copiedSettings0.mUnk_04 - copiedSettings0.mInnerDistance));
    gSoundFalloffs[0].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings0.mUnk_08),
                                       TO_FIXED12(copiedSettings0.mUnk_04 - copiedSettings0.mOuterDistance));
    gSoundFalloffs[0].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[0].mInnerDistance) + 0x36000);
    gSoundFalloffs[0].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings0.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings0.mOuterDistance), 0x16a1));
    workSettings1 = defaultSettings1;
    if (isReplayScene != FALSE) {
        replaySettings1 = workSettings1;
        replaySettings1.mOuterDistance = 0x44c;
        replaySettings1.mUnk_04 = 0x226;
        replaySettings1.mUnk_08 = 0x2f;
        replaySettings1.mMaxVolume = 0x5f;
        workSettings1 = replaySettings1;
    }
    copiedSettings1 = workSettings1;
    gOtherKartSoundFalloff.mMaxVolume = copiedSettings1.mMaxVolume;
    gOtherKartSoundFalloff.mOuterDistance = copiedSettings1.mOuterDistance;
    gOtherKartSoundFalloff.mUnk_04 = copiedSettings1.mUnk_04;
    gOtherKartSoundFalloff.mUnk_08 = copiedSettings1.mUnk_08;
    gOtherKartSoundFalloff.mInnerDistance = copiedSettings1.mInnerDistance;
    gOtherKartSoundFalloff.mUnk_14 = FX_Div(TO_FIXED12(copiedSettings1.mUnk_08 - copiedSettings1.mMaxVolume),
                                            TO_FIXED12(copiedSettings1.mUnk_04 - copiedSettings1.mInnerDistance));
    gOtherKartSoundFalloff.mUnk_18 = FX_Div(TO_FIXED12(copiedSettings1.mUnk_08),
                                            TO_FIXED12(copiedSettings1.mUnk_04 - copiedSettings1.mOuterDistance));
    gOtherKartSoundFalloff.mUnk_1c = FX_Div(0x666, TO_FIXED12(gOtherKartSoundFalloff.mInnerDistance) + 0x36000);
    gOtherKartSoundFalloff.mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings1.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings1.mOuterDistance), 0x16a1));
    workSettings2 = defaultSettings2;
    if (isReplayScene != FALSE) {
        replaySettings2 = workSettings2;
        replaySettings2.mOuterDistance = 0x514;
        replaySettings2.mUnk_04 = 0x28a;
        replaySettings2.mUnk_08 = 0x2f;
        replaySettings2.mMaxVolume = 0x5f;
        workSettings2 = replaySettings2;
    }
    copiedSettings2 = workSettings2;
    gSoundFalloffs[1].mMaxVolume = copiedSettings2.mMaxVolume;
    gSoundFalloffs[1].mOuterDistance = copiedSettings2.mOuterDistance;
    gSoundFalloffs[1].mUnk_04 = copiedSettings2.mUnk_04;
    gSoundFalloffs[1].mUnk_08 = copiedSettings2.mUnk_08;
    gSoundFalloffs[1].mInnerDistance = copiedSettings2.mInnerDistance;
    gSoundFalloffs[1].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings2.mUnk_08 - copiedSettings2.mMaxVolume),
                                       TO_FIXED12(copiedSettings2.mUnk_04 - copiedSettings2.mInnerDistance));
    gSoundFalloffs[1].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings2.mUnk_08),
                                       TO_FIXED12(copiedSettings2.mUnk_04 - copiedSettings2.mOuterDistance));
    gSoundFalloffs[1].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[1].mInnerDistance) + 0x36000);
    gSoundFalloffs[1].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings2.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings2.mOuterDistance), 0x16a1));
    workSettings3 = defaultSettings3;
    if (isReplayScene != FALSE) {
        replaySettings3 = workSettings3;
        replaySettings3.mOuterDistance = 0x44c;
        replaySettings3.mUnk_04 = 0x226;
        replaySettings3.mUnk_08 = 0x2f;
        replaySettings3.mMaxVolume = 0x5f;
        workSettings3 = replaySettings3;
    }
    copiedSettings3 = workSettings3;
    gSoundFalloffs[2].mMaxVolume = copiedSettings3.mMaxVolume;
    gSoundFalloffs[2].mOuterDistance = copiedSettings3.mOuterDistance;
    gSoundFalloffs[2].mUnk_04 = copiedSettings3.mUnk_04;
    gSoundFalloffs[2].mUnk_08 = copiedSettings3.mUnk_08;
    gSoundFalloffs[2].mInnerDistance = copiedSettings3.mInnerDistance;
    gSoundFalloffs[2].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings3.mUnk_08 - copiedSettings3.mMaxVolume),
                                       TO_FIXED12(copiedSettings3.mUnk_04 - copiedSettings3.mInnerDistance));
    gSoundFalloffs[2].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings3.mUnk_08),
                                       TO_FIXED12(copiedSettings3.mUnk_04 - copiedSettings3.mOuterDistance));
    gSoundFalloffs[2].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[2].mInnerDistance) + 0x36000);
    gSoundFalloffs[2].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings3.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings3.mOuterDistance), 0x16a1));
    workSettings4 = defaultSettings4;
    if (isReplayScene != FALSE) {
        replaySettings4 = workSettings4;
        replaySettings4.mOuterDistance = 0x44c;
        replaySettings4.mUnk_04 = 0x226;
        replaySettings4.mUnk_08 = 0x2f;
        replaySettings4.mMaxVolume = 0x5f;
        workSettings4 = replaySettings4;
    }
    copiedSettings4 = workSettings4;
    gSoundFalloffs[3].mMaxVolume = copiedSettings4.mMaxVolume;
    gSoundFalloffs[3].mOuterDistance = copiedSettings4.mOuterDistance;
    gSoundFalloffs[3].mUnk_04 = copiedSettings4.mUnk_04;
    gSoundFalloffs[3].mUnk_08 = copiedSettings4.mUnk_08;
    gSoundFalloffs[3].mInnerDistance = copiedSettings4.mInnerDistance;
    gSoundFalloffs[3].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings4.mUnk_08 - copiedSettings4.mMaxVolume),
                                       TO_FIXED12(copiedSettings4.mUnk_04 - copiedSettings4.mInnerDistance));
    gSoundFalloffs[3].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings4.mUnk_08),
                                       TO_FIXED12(copiedSettings4.mUnk_04 - copiedSettings4.mOuterDistance));
    gSoundFalloffs[3].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[3].mInnerDistance) + 0x36000);
    gSoundFalloffs[3].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings4.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings4.mOuterDistance), 0x16a1));
    copiedSettings5 = defaultSettings5;
    gSoundFalloffs[4].mMaxVolume = copiedSettings5.mMaxVolume;
    gSoundFalloffs[4].mOuterDistance = copiedSettings5.mOuterDistance;
    gSoundFalloffs[4].mUnk_04 = copiedSettings5.mUnk_04;
    gSoundFalloffs[4].mUnk_08 = copiedSettings5.mUnk_08;
    gSoundFalloffs[4].mInnerDistance = copiedSettings5.mInnerDistance;
    gSoundFalloffs[4].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings5.mUnk_08 - copiedSettings5.mMaxVolume),
                                       TO_FIXED12(copiedSettings5.mUnk_04 - copiedSettings5.mInnerDistance));
    gSoundFalloffs[4].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings5.mUnk_08),
                                       TO_FIXED12(copiedSettings5.mUnk_04 - copiedSettings5.mOuterDistance));
    gSoundFalloffs[4].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[4].mInnerDistance) + 0x36000);
    gSoundFalloffs[4].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings5.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings5.mOuterDistance), 0x16a1));
    copiedSettings6 = defaultSettings6;
    gSoundFalloffs[5].mMaxVolume = copiedSettings6.mMaxVolume;
    gSoundFalloffs[5].mOuterDistance = copiedSettings6.mOuterDistance;
    gSoundFalloffs[5].mUnk_04 = copiedSettings6.mUnk_04;
    gSoundFalloffs[5].mUnk_08 = copiedSettings6.mUnk_08;
    gSoundFalloffs[5].mInnerDistance = copiedSettings6.mInnerDistance;
    gSoundFalloffs[5].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings6.mUnk_08 - copiedSettings6.mMaxVolume),
                                       TO_FIXED12(copiedSettings6.mUnk_04 - copiedSettings6.mInnerDistance));
    gSoundFalloffs[5].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings6.mUnk_08),
                                       TO_FIXED12(copiedSettings6.mUnk_04 - copiedSettings6.mOuterDistance));
    gSoundFalloffs[5].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[5].mInnerDistance) + 0x36000);
    gSoundFalloffs[5].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings6.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings6.mOuterDistance), 0x16a1));
    copiedSettings7 = defaultSettings7;
    gSoundFalloffs[6].mMaxVolume = copiedSettings7.mMaxVolume;
    gSoundFalloffs[6].mOuterDistance = copiedSettings7.mOuterDistance;
    gSoundFalloffs[6].mUnk_04 = copiedSettings7.mUnk_04;
    gSoundFalloffs[6].mUnk_08 = copiedSettings7.mUnk_08;
    gSoundFalloffs[6].mInnerDistance = copiedSettings7.mInnerDistance;
    gSoundFalloffs[6].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings7.mUnk_08 - copiedSettings7.mMaxVolume),
                                       TO_FIXED12(copiedSettings7.mUnk_04 - copiedSettings7.mInnerDistance));
    gSoundFalloffs[6].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings7.mUnk_08),
                                       TO_FIXED12(copiedSettings7.mUnk_04 - copiedSettings7.mOuterDistance));
    gSoundFalloffs[6].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[6].mInnerDistance) + 0x36000);
    gSoundFalloffs[6].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings7.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings7.mOuterDistance), 0x16a1));
    copiedSettings8 = defaultSettings8;
    gSoundFalloffs[7].mMaxVolume = copiedSettings8.mMaxVolume;
    gSoundFalloffs[7].mOuterDistance = copiedSettings8.mOuterDistance;
    gSoundFalloffs[7].mUnk_04 = copiedSettings8.mUnk_04;
    gSoundFalloffs[7].mUnk_08 = copiedSettings8.mUnk_08;
    gSoundFalloffs[7].mInnerDistance = copiedSettings8.mInnerDistance;
    gSoundFalloffs[7].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings8.mUnk_08 - copiedSettings8.mMaxVolume),
                                       TO_FIXED12(copiedSettings8.mUnk_04 - copiedSettings8.mInnerDistance));
    gSoundFalloffs[7].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings8.mUnk_08),
                                       TO_FIXED12(copiedSettings8.mUnk_04 - copiedSettings8.mOuterDistance));
    gSoundFalloffs[7].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[7].mInnerDistance) + 0x36000);
    gSoundFalloffs[7].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings8.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings8.mOuterDistance), 0x16a1));
    copiedSettings9 = defaultSettings9;
    gSoundFalloffs[8].mMaxVolume = copiedSettings9.mMaxVolume;
    gSoundFalloffs[8].mOuterDistance = copiedSettings9.mOuterDistance;
    gSoundFalloffs[8].mUnk_04 = copiedSettings9.mUnk_04;
    gSoundFalloffs[8].mUnk_08 = copiedSettings9.mUnk_08;
    gSoundFalloffs[8].mInnerDistance = copiedSettings9.mInnerDistance;
    gSoundFalloffs[8].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings9.mUnk_08 - copiedSettings9.mMaxVolume),
                                       TO_FIXED12(copiedSettings9.mUnk_04 - copiedSettings9.mInnerDistance));
    gSoundFalloffs[8].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings9.mUnk_08),
                                       TO_FIXED12(copiedSettings9.mUnk_04 - copiedSettings9.mOuterDistance));
    gSoundFalloffs[8].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[8].mInnerDistance) + 0x36000);
    gSoundFalloffs[8].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings9.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings9.mOuterDistance), 0x16a1));
    copiedSettings10 = defaultSettings10;
    gSoundFalloffs[9].mMaxVolume = copiedSettings10.mMaxVolume;
    gSoundFalloffs[9].mOuterDistance = copiedSettings10.mOuterDistance;
    gSoundFalloffs[9].mUnk_04 = copiedSettings10.mUnk_04;
    gSoundFalloffs[9].mUnk_08 = copiedSettings10.mUnk_08;
    gSoundFalloffs[9].mInnerDistance = copiedSettings10.mInnerDistance;
    gSoundFalloffs[9].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings10.mUnk_08 - copiedSettings10.mMaxVolume),
                                       TO_FIXED12(copiedSettings10.mUnk_04 - copiedSettings10.mInnerDistance));
    gSoundFalloffs[9].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings10.mUnk_08),
                                       TO_FIXED12(copiedSettings10.mUnk_04 - copiedSettings10.mOuterDistance));
    gSoundFalloffs[9].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[9].mInnerDistance) + 0x36000);
    gSoundFalloffs[9].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings10.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings10.mOuterDistance), 0x16a1));
    copiedSettings11 = defaultSettings11;
    gSoundFalloffs[10].mMaxVolume = copiedSettings11.mMaxVolume;
    gSoundFalloffs[10].mOuterDistance = copiedSettings11.mOuterDistance;
    gSoundFalloffs[10].mUnk_04 = copiedSettings11.mUnk_04;
    gSoundFalloffs[10].mUnk_08 = copiedSettings11.mUnk_08;
    gSoundFalloffs[10].mInnerDistance = copiedSettings11.mInnerDistance;
    gSoundFalloffs[10].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings11.mUnk_08 - copiedSettings11.mMaxVolume),
                                        TO_FIXED12(copiedSettings11.mUnk_04 - copiedSettings11.mInnerDistance));
    gSoundFalloffs[10].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings11.mUnk_08),
                                        TO_FIXED12(copiedSettings11.mUnk_04 - copiedSettings11.mOuterDistance));
    gSoundFalloffs[10].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[10].mInnerDistance) + 0x36000);
    gSoundFalloffs[10].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings11.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings11.mOuterDistance), 0x16a1));
    copiedSettings12 = defaultSettings12;
    gSoundFalloffs[11].mMaxVolume = copiedSettings12.mMaxVolume;
    gSoundFalloffs[11].mOuterDistance = copiedSettings12.mOuterDistance;
    gSoundFalloffs[11].mUnk_04 = copiedSettings12.mUnk_04;
    gSoundFalloffs[11].mUnk_08 = copiedSettings12.mUnk_08;
    gSoundFalloffs[11].mInnerDistance = copiedSettings12.mInnerDistance;
    gSoundFalloffs[11].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings12.mUnk_08 - copiedSettings12.mMaxVolume),
                                        TO_FIXED12(copiedSettings12.mUnk_04 - copiedSettings12.mInnerDistance));
    gSoundFalloffs[11].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings12.mUnk_08),
                                        TO_FIXED12(copiedSettings12.mUnk_04 - copiedSettings12.mOuterDistance));
    gSoundFalloffs[11].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[11].mInnerDistance) + 0x36000);
    gSoundFalloffs[11].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings12.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings12.mOuterDistance), 0x16a1));
    copiedSettings13 = defaultSettings13;
    gSoundFalloffs[12].mMaxVolume = copiedSettings13.mMaxVolume;
    gSoundFalloffs[12].mOuterDistance = copiedSettings13.mOuterDistance;
    gSoundFalloffs[12].mUnk_04 = copiedSettings13.mUnk_04;
    gSoundFalloffs[12].mUnk_08 = copiedSettings13.mUnk_08;
    gSoundFalloffs[12].mInnerDistance = copiedSettings13.mInnerDistance;
    gSoundFalloffs[12].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings13.mUnk_08 - copiedSettings13.mMaxVolume),
                                        TO_FIXED12(copiedSettings13.mUnk_04 - copiedSettings13.mInnerDistance));
    gSoundFalloffs[12].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings13.mUnk_08),
                                        TO_FIXED12(copiedSettings13.mUnk_04 - copiedSettings13.mOuterDistance));
    gSoundFalloffs[12].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[12].mInnerDistance) + 0x36000);
    gSoundFalloffs[12].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings13.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings13.mOuterDistance), 0x16a1));
    copiedSettings14 = defaultSettings14;
    gSoundFalloffs[13].mMaxVolume = copiedSettings14.mMaxVolume;
    gSoundFalloffs[13].mOuterDistance = copiedSettings14.mOuterDistance;
    gSoundFalloffs[13].mUnk_04 = copiedSettings14.mUnk_04;
    gSoundFalloffs[13].mUnk_08 = copiedSettings14.mUnk_08;
    gSoundFalloffs[13].mInnerDistance = copiedSettings14.mInnerDistance;
    gSoundFalloffs[13].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings14.mUnk_08 - copiedSettings14.mMaxVolume),
                                        TO_FIXED12(copiedSettings14.mUnk_04 - copiedSettings14.mInnerDistance));
    gSoundFalloffs[13].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings14.mUnk_08),
                                        TO_FIXED12(copiedSettings14.mUnk_04 - copiedSettings14.mOuterDistance));
    gSoundFalloffs[13].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[13].mInnerDistance) + 0x36000);
    gSoundFalloffs[13].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings14.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings14.mOuterDistance), 0x16a1));
    copiedSettings15 = defaultSettings15;
    gSoundFalloffs[14].mMaxVolume = copiedSettings15.mMaxVolume;
    gSoundFalloffs[14].mOuterDistance = copiedSettings15.mOuterDistance;
    gSoundFalloffs[14].mUnk_04 = copiedSettings15.mUnk_04;
    gSoundFalloffs[14].mUnk_08 = copiedSettings15.mUnk_08;
    gSoundFalloffs[14].mInnerDistance = copiedSettings15.mInnerDistance;
    gSoundFalloffs[14].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings15.mUnk_08 - copiedSettings15.mMaxVolume),
                                        TO_FIXED12(copiedSettings15.mUnk_04 - copiedSettings15.mInnerDistance));
    gSoundFalloffs[14].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings15.mUnk_08),
                                        TO_FIXED12(copiedSettings15.mUnk_04 - copiedSettings15.mOuterDistance));
    gSoundFalloffs[14].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[14].mInnerDistance) + 0x36000);
    gSoundFalloffs[14].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings15.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings15.mOuterDistance), 0x16a1));
    copiedSettings16 = defaultSettings16;
    gSoundFalloffs[15].mMaxVolume = copiedSettings16.mMaxVolume;
    gSoundFalloffs[15].mOuterDistance = copiedSettings16.mOuterDistance;
    gSoundFalloffs[15].mUnk_04 = copiedSettings16.mUnk_04;
    gSoundFalloffs[15].mUnk_08 = copiedSettings16.mUnk_08;
    gSoundFalloffs[15].mInnerDistance = copiedSettings16.mInnerDistance;
    gSoundFalloffs[15].mUnk_14 = FX_Div(TO_FIXED12(copiedSettings16.mUnk_08 - copiedSettings16.mMaxVolume),
                                        TO_FIXED12(copiedSettings16.mUnk_04 - copiedSettings16.mInnerDistance));
    gSoundFalloffs[15].mUnk_18 = FX_Div(TO_FIXED12(copiedSettings16.mUnk_08),
                                        TO_FIXED12(copiedSettings16.mUnk_04 - copiedSettings16.mOuterDistance));
    gSoundFalloffs[15].mUnk_1c = FX_Div(0x666, TO_FIXED12(gSoundFalloffs[15].mInnerDistance) + 0x36000);
    gSoundFalloffs[15].mFarDistanceSquared =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings16.mOuterDistance), 0x16a1)) *
        FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(copiedSettings16.mOuterDistance), 0x16a1));
}

s32 ComputeSoundVolume(SoundParams *soundParams) {
    Kart *kart;
    SoundFalloff *falloff;
    s32 volume;
    s32 value;

    kart = (Kart *) soundParams->mSource;
    volume = 0;
    if (kart != NULL) {
        if (kart != NULL && kart->mSoundSource.mFalloffIndex == 0 && kart->mIndex != gRaceSetup->mEntryIndex) {
            falloff = &gOtherKartSoundFalloff;
        } else {
            falloff = &gSoundFalloffs[kart->mSoundSource.mFalloffIndex];
        }
    } else {
        falloff = &gSoundFalloffs[soundParams->mStartParams->mFalloffIndex];
    }
    value = soundParams->mDistance;
    if (value <= falloff->mInnerDistance) {
        volume = falloff->mMaxVolume;
    } else if (value <= falloff->mUnk_04) {
        volume = falloff->mMaxVolume +
                 FROM_FIXED12(MUL_FIXED12_ROUNDED(falloff->mUnk_14, TO_FIXED12(value - falloff->mInnerDistance)));
    } else if (value < falloff->mOuterDistance) {
        volume = FROM_FIXED12(MUL_FIXED12_ROUNDED(falloff->mUnk_18, TO_FIXED12(value - falloff->mOuterDistance)));
    }
    value = soundParams->mUnk_08;
    if (value < 0x36) {
        if (value > -falloff->mInnerDistance) {
            value = (MUL_FIXED12_ROUNDED(falloff->mUnk_1c, TO_FIXED12(value - 0x36))) + 0x1000;
            volume = FROM_FIXED12(MUL_FIXED12_ROUNDED(value, TO_FIXED12(volume)));
        } else {
            volume = FROM_FIXED12(MUL_FIXED12_ROUNDED(TO_FIXED12(volume), 0x99a));
        }
    }
    if (volume < 0) {
        return 0;
    }
    if (volume > falloff->mMaxVolume) {
        return falloff->mMaxVolume;
    }
    return volume;
}

// Returns the pan, from -0x80 to 0x7f.
s32 ComputeSoundPan(SoundParams *soundParams) {
    u32 angle;
    s32 pan;

    angle = FX_Atan2Idx(TO_FIXED12(soundParams->mUnk_08), -soundParams->mUnk_0c << 12);
    if (angle > 0x7fff) {
        angle = (u16) (0xffff - angle);
    }
    pan = FROM_FIXED12(MUL_FIXED12_ROUNDED((s32) TO_FIXED12(angle), -32));
    pan += 0x7f;
    if (pan < -0x80) {
        pan = -0x80;
    } else if (pan > 0x7f) {
        pan = 0x7f;
    }
    return pan;
}

// Returns the distance to the camera; also stores the forward and side distance in the record.
u32 ComputeSoundDistanceAndOffsets(SoundParams *soundParams) {
    u32 distanceSquared;
    Vec3 *positionSource;

    if (soundParams->mSource != NULL) {
        distanceSquared = ((Kart *) soundParams->mSource)->mSoundSource.mDistanceSquared;
    } else {
        distanceSquared = soundParams->mStartParams->mDistanceSquared;
    }
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM_LO = distanceSquared;
    positionSource = soundParams->mPositionSource;
    soundParams->mUnk_08 = FROM_FIXED12(GetCameraForwardDistance(positionSource));
    soundParams->mUnk_0c = FROM_FIXED12(GetCameraSideDistance(positionSource));
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    return reg_CP_SQRT_RESULT;
}

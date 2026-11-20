#include "Main/MapObjects/trophy.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Scene/scene_connection.h"
#include "model_draw_state.h"
#include "matrix_3x3_basic.h"
#include "geometry_engine_setup.h"
#include "Main/Item/item_in_use.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/effects.h"
#include "fixed_vector_math.h"
#include "display_blend_affine_setup.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "system_state_globals.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/trophy_work.h"
#include "model_material_set.h"
#include "particle_instance.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/teresa.h"
#include "matrix_4x3_basic.h"
#include "Main/System/startup.h"

const s32 gTrophyModelEffectRadius[9] = {0x400, 0x5ec, 0x452, 0x452, 0x4a4, 0x400, 0x466, 0x4f6, 0x429};
const s16 gTrophyModelLight0X[10] = {0x400, 0x400, -1024, 0xfff, 0xfff, 0xfff, -4096, 0xfff, 0xfff, 0};
const s32 gTrophyModelEffectOffsetY[9] = {0x266, 0xcd, 0x1c3, 0x214, 0x214, 0x214, 0x214, 0x19a, 0x2b8};
const s16 gTrophyModelLight0Y[10] = {0, 0, 0, -2048, 0, 0, 0, 0xfff, 0, 0};
const s16 gTrophyModelLight0Z[10] = {-4096, -4096, -4096, 0xfff, -4096, -2048, -4096, -4096, -1024, 0};
const s16 gTrophyModelLight1X[10] = {-4096, -4096, -4096, -2048, -4096, -4096, -4096, -4096, -4096, 0};
const s16 gTrophyModelLight1Y[10] = {0, 0, 0, 0xc00, 0, 0, -2048, 0, 0, 0};
const s16 gTrophyModelLight1Z[10] = {0xfff, 0xfff, 0xfff, -4096, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0};
Vec3 gTrophyCameraUp = {0, 0x1000, 0};
Vec3 gTrophyCameraPos = {0, 0, 0x3e8000};
char gTrophyTFlowNsbmd[] = "T_flow.nsbmd";
char gTrophyTStarNsbmd[] = "T_star.nsbmd";
char gTrophyTSpecNsbmd[] = "T_spec.nsbmd";
char gTrophyTKoraNsbmd[] = "T_kora.nsbmd";
char gTrophyTKinoNsbtp[] = "T_kino.nsbtp";
char gTrophyTBanaNsbtp[] = "T_bana.nsbtp";
char gTrophyTKonoNsbmd[] = "T_kono.nsbmd";
char gTrophyTrophyNsbmd[] = "trophy.nsbmd";
char gTrophyTKonoNsbtp[] = "T_kono.nsbtp";
char *gTrophyModelNsbmdNames[9] = {gTrophyTKinoNsbmd, gTrophyTFlowNsbmd, gTrophyTStarNsbmd,
                            gTrophyTSpecNsbmd, gTrophyTKoraNsbmd, gTrophyTBanaNsbmd,
                            gTrophyTKonoNsbmd, gTrophyTThunNsbmd, gTrophyTrophyNsbmd};
char gTrophyTFlowNsbtp[] = "T_flow.nsbtp";
char gTrophyTStarNsbtp[] = "T_star.nsbtp";
char gTrophyTrophyNsbtp[] = "trophy.nsbtp";
char gTrophyTBanaNsbmd[] = "T_bana.nsbmd";
char gTrophyTKoraNsbtp[] = "T_kora.nsbtp";
char gTrophyTThunNsbtp[] = "T_thun.nsbtp";
char gTrophyTSpecNsbtp[] = "T_spec.nsbtp";
char gTrophyTKinoNsbmd[] = "T_kino.nsbmd";
char gTrophyTThunNsbmd[] = "T_thun.nsbmd";
char *gTrophyModelNsbtpNames[9] = {gTrophyTKinoNsbtp, gTrophyTFlowNsbtp, gTrophyTStarNsbtp,
                            gTrophyTSpecNsbtp, gTrophyTKoraNsbtp, gTrophyTBanaNsbtp,
                            gTrophyTKonoNsbtp, gTrophyTThunNsbtp, gTrophyTrophyNsbtp};
Trophy *gTrophy;

void SetupTrophy(void) {
    s32 frustumTop;
    s32 frustumRight;
    s32 angle;
    Trophy *trophy;
    TeresaWobble *wobble;

    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x1f, 0x10, 0x10);
    NNS_G3dGlbLightVector(0, gTrophy->mLight0X, gTrophy->mLight0Y, gTrophy->mLight0Z);
    NNS_G3dGlbLightVector(1, gTrophy->mLight1X, gTrophy->mLight1Y, gTrophy->mLight1Z);
    NNS_G3dGlbLightColor(0, COLOR15_WHITE);
    NNS_G3dGlbLightColor(1, COLOR15_WHITE);
    frustumTop = MUL_FIXED12_NO_ROUND(FX_Div(SIN_OF_ANGLE(0xaa0), COS_OF_ANGLE(0xaa0)), 0x19a);
    frustumRight = MUL_FIXED12_NO_ROUND(-frustumTop, 0x1555);
    if (gRaceSetup->mMirrorMode != 0) {
        G3i_FrustumW_(frustumTop, -frustumTop, -frustumRight, frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    } else {
        G3i_FrustumW_(frustumTop, -frustumTop, frustumRight, -frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    }
    {
        Vec3 cameraPos;
        Vec3 cameraUp;
        Vec3 cameraTarget = {0, 0, 0};

        cameraUp = gTrophyCameraUp;
        cameraPos = gTrophyCameraPos;
        NNS_G3dGlb.mCamPos = cameraPos;
        NNS_G3dGlb.mCamUp = cameraUp;
        NNS_G3dGlb.mCamTarget = cameraTarget;
        G3i_LookAt_(&cameraPos, &cameraUp, &cameraTarget, 0, &NNS_G3dGlb.mCameraMtx);
        NNS_G3dGlb.mFlag &= ~0xe8;
        SetG3xSwapBits(gDisplaySettings, 1, 1);
        NNS_G3dGlb.mPrmViewPort = VIEWPORT_WHOLE_SCREEN;
        NNS_G3dGlbFlushP();
        if (gTrophy->mRankIndex >= 3) {
            return;
        }
        gTrophy->mRotateYAngle = -GetSceneFadeToClearFrameCount() * 0x6d;
        angle = -GetSceneFadeToClearFrameCount() * TROPHY_WOBBLE_ANGLE_PER_FRAME;
        trophy = gTrophy;
        trophy->mRotateZWobble.mAngle = angle;
        wobble = &trophy->mRotateZWobble;
        wobble->mMid = 0;
        wobble->mAmplitude = TROPHY_WOBBLE_AMPLITUDE;
        wobble->mAmplitudePerFrame = 0;
        wobble->mAnglePerFrame = TROPHY_WOBBLE_ANGLE_PER_FRAME;
        wobble->mAnglePerFrameDelta = 0;
        MTX_Identity43_(&gTrophy->mEffectMatrix);
        if (gTrophy->mRankIndex == 0) {
            gTrophy->mEffect0->mRadius = gTrophy->mEffectRadius;
            gTrophy->mEffect0->mPosition.x =
                gTrophy->mEffectOffset.x + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.x;
            gTrophy->mEffect0->mPosition.y =
                gTrophy->mEffectOffset.y + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.y;
            gTrophy->mEffect0->mPosition.z =
                gTrophy->mEffectOffset.z + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.z;
            gTrophy->mEffect4->mPosition.x = gTrophy->mEffect4->mResource->mHeader->mPositionOffset.x;
            gTrophy->mEffect4->mPosition.y = gTrophy->mEffect4->mResource->mHeader->mPositionOffset.y - 0xcd;
            gTrophy->mEffect4->mPosition.z = gTrophy->mEffect4->mResource->mHeader->mPositionOffset.z - 0x21ec;
            gTrophy->mEffect5->mPosition.x = gTrophy->mEffect5->mResource->mHeader->mPositionOffset.x;
            gTrophy->mEffect5->mPosition.y = gTrophy->mEffect5->mResource->mHeader->mPositionOffset.y - 0xcd;
            gTrophy->mEffect5->mPosition.z = gTrophy->mEffect5->mResource->mHeader->mPositionOffset.z - 0x21ec;
        } else if (gTrophy->mRankIndex == 1) {
            gTrophy->mEffect0->mRadius = gTrophy->mEffectRadius;
            gTrophy->mEffect0->mPosition.x =
                gTrophy->mEffectOffset.x + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.x;
            gTrophy->mEffect0->mPosition.y =
                gTrophy->mEffectOffset.y + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.y;
            gTrophy->mEffect0->mPosition.z =
                gTrophy->mEffectOffset.z + gTrophy->mEffect0->mResource->mHeader->mPositionOffset.z;
        }
    }
}

void InitTrophy(s32 modelIndex, u16 rankIndex) {
    void *modelFile;
    void *animationFile;
    void *heap;
    float frameIndex;
    s32 storedRankIndex;
    ModelAnimation *modelAnimation;

    gTrophy = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gTrophy));
    gTrophy->mRankIndex = rankIndex;
    gTrophy->mModelIndex = modelIndex;
    if (modelIndex < 9 && rankIndex < 3) {
        modelFile = FindSceneFile(gTrophyModelNsbmdNames[modelIndex]);
        animationFile = FindSceneFile(gTrophyModelNsbtpNames[modelIndex]);
        gTrophy->mLight0X = gTrophyModelLight0X[modelIndex];
        gTrophy->mLight0Y = gTrophyModelLight0Y[modelIndex];
        gTrophy->mLight0Z = gTrophyModelLight0Z[modelIndex];
        gTrophy->mLight1X = gTrophyModelLight1X[modelIndex];
        gTrophy->mLight1Y = gTrophyModelLight1Y[modelIndex];
        gTrophy->mLight1Z = gTrophyModelLight1Z[modelIndex];
        gTrophy->mEffectOffset.x = 0;
        gTrophy->mEffectOffset.y = gTrophyModelEffectOffsetY[modelIndex];
        gTrophy->mEffectOffset.z = -0x2000;
        gTrophy->mEffectRadius = gTrophyModelEffectRadius[modelIndex];
        InitNsbmd(&gTrophy->mModel, modelFile);
        SetNsbmdLightEnableFlagAll(&gTrophy->mModel, 3);
        if (gRaceSetup->mMirrorMode != 0) {
            SetNsbmdCullModeAll(&gTrophy->mModel, 1);
        } else {
            SetNsbmdCullModeAll(&gTrophy->mModel, 2);
        }
        heap = GetHeap(GetCurrentHeapCall());
        InitModelAnimation(MODEL_ANIMATION_KIND_TEX_PAT, &gTrophy->mModelAnimation, &gTrophy->mModel, 1, heap,
                           modelFile);
        InitModelAnimationEntries(&gTrophy->mModelAnimation, animationFile, GetHeap(GetCurrentHeapCall()));
        SetModelAnimation(&gTrophy->mModelAnimation, 0);
        storedRankIndex = gTrophy->mRankIndex;
        if (storedRankIndex != 0) {
            frameIndex = 0.5f + TO_FIXED12(storedRankIndex);
        } else {
            frameIndex = TO_FIXED12(storedRankIndex) - 0.5f;
        }
        modelAnimation = &gTrophy->mModelAnimation;
        modelAnimation->mFrameLoop.mFrameIndexFixed = frameIndex;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mFrameLoop.mFrameIndexFixed;
        InitEffects(GetHeap(GetCurrentHeapCall()));
        if (rankIndex == 0) {
            Vec3 effectPos0 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &effectPos0);
            {
                Vec3 effectPos1 = {0, 0, 0};

                gTrophy->mEffect4 = StartEffect(4, &effectPos1);
                {
                    Vec3 effectPos2 = {0, 0, 0};

                    gTrophy->mEffect5 = StartEffect(5, &effectPos2);
                }
            }
        } else if (rankIndex == 1) {
            Vec3 effectPos3 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &effectPos3);
        }
    }
    SetupTrophy();
}

s16 TrophyFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 TrophyFX_MulInline(s32 lhs, s32 rhs) {
    return MUL_FIXED12_ROUNDED(lhs, rhs);
}

void AdvanceTrophy(void) {
    Trophy *trophy;
    TeresaWobble *wobble;
    s32 value;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    UpdateEffects();
    gTrophy->mRotateYAngle += 0x6d;
    trophy = gTrophy;
    wobble = &trophy->mRotateZWobble;
    trophy->mRotateZWobble.mAngle += wobble->mAnglePerFrame;
    wobble->mValueDelta = wobble->mMid +
                          TrophyFX_MulInline(wobble->mAmplitude, TrophyFX_SinIdx(trophy->mRotateZWobble.mAngle)) -
                          wobble->mValue;
    wobble->mValue += wobble->mValueDelta;
    if (wobble->mAmplitude > 0) {
        value = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (value <= 0) {
            value = 0;
        }
        wobble->mAmplitude = value;
    } else if (wobble->mAmplitude < 0) {
        value = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (value >= 0) {
            value = 0;
        }
        wobble->mAmplitude = value;
    }
    if (wobble->mAnglePerFrame > 0) {
        value = wobble->mAnglePerFrame + wobble->mAnglePerFrameDelta;
        if (value <= 0) {
            value = 0;
        }
        wobble->mAnglePerFrame = value;
    } else if (wobble->mAnglePerFrame < 0) {
        value = wobble->mAnglePerFrame + wobble->mAnglePerFrameDelta;
        if (value >= 0) {
            value = 0;
        }
        wobble->mAnglePerFrame = value;
    }
}

void DrawTrophy(void) {
    MtxFx33 rotateXMatrix;
    MtxFx33 rotateYMatrix;
    MtxFx33 rotateZMatrix;
    s32 scale[3];
    s32 translation[3];
    s32 zeroTranslation[3];
    u16 rotateZAngle;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    DrawEffects(&gTrophy->mEffectMatrix);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    translation[0] = 0;
    translation[1] = -0xcd;
    translation[2] = -0x2000;
    NNS_G3dGeBufferOP_N(0x1c, translation, 3);
    rotateZAngle = gTrophy->mRotateZWobble.mValue;
    MTX_RotX33_(&rotateXMatrix, SIN_OF_ANGLE(0xbb0), COS_OF_ANGLE(0xbb0));
    MTX_RotY33_(&rotateYMatrix, FX_SinIdx(gTrophy->mRotateYAngle), FX_CosIdx(gTrophy->mRotateYAngle));
    MTX_RotZ33_(&rotateZMatrix, FX_SinIdx(rotateZAngle), FX_CosIdx(rotateZAngle));
    NNS_G3dGeBufferOP_N(0x1a, &rotateXMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
    zeroTranslation[0] = 0;
    zeroTranslation[1] = 0;
    zeroTranslation[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, zeroTranslation, 3);
    DrawNsbmd(&gTrophy->mModel);
    NNS_G3dGeFlushBuffer();
}

s32 GetKartBalloonOrShineHeight(Kart *kart) {
    KartModelsEntry *kartModelsEntry;

    kartModelsEntry = kart->mKartModelsEntry;
    return gCharacterBalloonOrShineHeights[kartModelsEntry->mCharacterIndex] +
           kartModelsEntry->mKartOffsetData->mCharacterOffsets[kartModelsEntry->mCharacterIndex].y;
}

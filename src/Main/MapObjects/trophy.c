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
#include "Main/Sound/sound_seq.h"
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
char *gTKinoNsbmdName[9] = {gTrophyTKinoNsbmd, gTrophyTFlowNsbmd, gTrophyTStarNsbmd,
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
char *gTKinoNsbtpName[9] = {gTrophyTKinoNsbtp, gTrophyTFlowNsbtp, gTrophyTStarNsbtp,
                            gTrophyTSpecNsbtp, gTrophyTKoraNsbtp, gTrophyTBanaNsbtp,
                            gTrophyTKonoNsbtp, gTrophyTThunNsbtp, gTrophyTrophyNsbtp};
Trophy *g_GlobalTrophyResult;

void SetupTrophy(void) {
    s32 frustumTop;
    s32 frustumRight;
    s32 angle;
    Trophy *trophy;
    TeresaWobble *wobble;

    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x1f, 0x10, 0x10);
    NNS_G3dGlbLightVector(0, g_GlobalTrophyResult->mLight0X, g_GlobalTrophyResult->mLight0Y, g_GlobalTrophyResult->mLight0Z);
    NNS_G3dGlbLightVector(1, g_GlobalTrophyResult->mLight1X, g_GlobalTrophyResult->mLight1Y, g_GlobalTrophyResult->mLight1Z);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x7fff);
    frustumTop = MUL_FIXED12_NO_ROUND(FX_Div(SIN_OF_ANGLE(0xaa0), COS_OF_ANGLE(0xaa0)), 0x19a);
    frustumRight = MUL_FIXED12_NO_ROUND(-frustumTop, 0x1555);
    if (g_GlobalCO->mMirrorMode != 0) {
        G3i_FrustumW_(frustumTop, -frustumTop, -frustumRight, frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &g_GlobalG3.mProjMtx);
        g_GlobalG3.mFlag &= ~0x50;
    } else {
        G3i_FrustumW_(frustumTop, -frustumTop, frustumRight, -frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &g_GlobalG3.mProjMtx);
        g_GlobalG3.mFlag &= ~0x50;
    }
    {
        Vec3 cameraPos;
        Vec3 cameraUp;
        Vec3 cameraTarget = {0, 0, 0};

        cameraUp = gTrophyCameraUp;
        cameraPos = gTrophyCameraPos;
        g_GlobalG3.mCamPos = cameraPos;
        g_GlobalG3.mCamUp = cameraUp;
        g_GlobalG3.mCamTarget = cameraTarget;
        G3i_LookAt_(&cameraPos, &cameraUp, &cameraTarget, 0, &g_GlobalG3.mCameraMtx);
        g_GlobalG3.mFlag &= ~0xe8;
        DisplayConfig_SetSwapBufferValues(g_GlobalDisplayConfig, 1, 1);
        g_GlobalG3.mPrmViewPort = VIEWPORT_WHOLE_SCREEN;
        NNS_G3dGlbFlushP();
        if (g_GlobalTrophyResult->mRankIndex >= 3) {
            return;
        }
        g_GlobalTrophyResult->mRotateYAngle = -GetSceneFadeToClearFrameCount() * 0x6d;
        angle = -GetSceneFadeToClearFrameCount() * TROPHY_WOBBLE_ANGLE_PER_FRAME;
        trophy = g_GlobalTrophyResult;
        trophy->mRotateZWobble.mAngle = angle;
        wobble = &trophy->mRotateZWobble;
        wobble->mMid = 0;
        wobble->mAmplitude = TROPHY_WOBBLE_AMPLITUDE;
        wobble->mAmplitudePerFrame = 0;
        wobble->mAnglePerFrame = TROPHY_WOBBLE_ANGLE_PER_FRAME;
        wobble->mAnglePerFrameDelta = 0;
        MTX_Identity43_(&g_GlobalTrophyResult->mEffectMatrix);
        if (g_GlobalTrophyResult->mRankIndex == 0) {
            g_GlobalTrophyResult->mEffect0->mRadius = g_GlobalTrophyResult->mEffectRadius;
            g_GlobalTrophyResult->mEffect0->mPosition.x =
                g_GlobalTrophyResult->mEffectOffset.x + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.x;
            g_GlobalTrophyResult->mEffect0->mPosition.y =
                g_GlobalTrophyResult->mEffectOffset.y + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.y;
            g_GlobalTrophyResult->mEffect0->mPosition.z =
                g_GlobalTrophyResult->mEffectOffset.z + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.z;
            g_GlobalTrophyResult->mEffect4->mPosition.x = g_GlobalTrophyResult->mEffect4->mResource->mHeader->mPositionOffset.x;
            g_GlobalTrophyResult->mEffect4->mPosition.y = g_GlobalTrophyResult->mEffect4->mResource->mHeader->mPositionOffset.y - 0xcd;
            g_GlobalTrophyResult->mEffect4->mPosition.z = g_GlobalTrophyResult->mEffect4->mResource->mHeader->mPositionOffset.z - 0x21ec;
            g_GlobalTrophyResult->mEffect5->mPosition.x = g_GlobalTrophyResult->mEffect5->mResource->mHeader->mPositionOffset.x;
            g_GlobalTrophyResult->mEffect5->mPosition.y = g_GlobalTrophyResult->mEffect5->mResource->mHeader->mPositionOffset.y - 0xcd;
            g_GlobalTrophyResult->mEffect5->mPosition.z = g_GlobalTrophyResult->mEffect5->mResource->mHeader->mPositionOffset.z - 0x21ec;
        } else if (g_GlobalTrophyResult->mRankIndex == 1) {
            g_GlobalTrophyResult->mEffect0->mRadius = g_GlobalTrophyResult->mEffectRadius;
            g_GlobalTrophyResult->mEffect0->mPosition.x =
                g_GlobalTrophyResult->mEffectOffset.x + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.x;
            g_GlobalTrophyResult->mEffect0->mPosition.y =
                g_GlobalTrophyResult->mEffectOffset.y + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.y;
            g_GlobalTrophyResult->mEffect0->mPosition.z =
                g_GlobalTrophyResult->mEffectOffset.z + g_GlobalTrophyResult->mEffect0->mResource->mHeader->mPositionOffset.z;
        }
    }
}

void LoadCupTrophyModel(s32 modelIndex, u16 rankIndex) {
    void *modelFile;
    void *animationFile;
    void *heap;
    float frameIndex;
    s32 storedRankIndex;
    ModelAnimation *modelAnimation;

    g_GlobalTrophyResult = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalTrophyResult));
    g_GlobalTrophyResult->mRankIndex = rankIndex;
    g_GlobalTrophyResult->mModelIndex = modelIndex;
    if (modelIndex < 9 && rankIndex < 3) {
        modelFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTKinoNsbmdName[modelIndex]);
        animationFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTKinoNsbtpName[modelIndex]);
        g_GlobalTrophyResult->mLight0X = gTrophyModelLight0X[modelIndex];
        g_GlobalTrophyResult->mLight0Y = gTrophyModelLight0Y[modelIndex];
        g_GlobalTrophyResult->mLight0Z = gTrophyModelLight0Z[modelIndex];
        g_GlobalTrophyResult->mLight1X = gTrophyModelLight1X[modelIndex];
        g_GlobalTrophyResult->mLight1Y = gTrophyModelLight1Y[modelIndex];
        g_GlobalTrophyResult->mLight1Z = gTrophyModelLight1Z[modelIndex];
        g_GlobalTrophyResult->mEffectOffset.x = 0;
        g_GlobalTrophyResult->mEffectOffset.y = gTrophyModelEffectOffsetY[modelIndex];
        g_GlobalTrophyResult->mEffectOffset.z = -0x2000;
        g_GlobalTrophyResult->mEffectRadius = gTrophyModelEffectRadius[modelIndex];
        StructML_LoadModel2(&g_GlobalTrophyResult->mModel, modelFile);
        StructML_SomeFn_8(&g_GlobalTrophyResult->mModel, 3);
        if (g_GlobalCO->mMirrorMode != 0) {
            StructML_SomeFn_0(&g_GlobalTrophyResult->mModel, 1);
        } else {
            StructML_SomeFn_0(&g_GlobalTrophyResult->mModel, 2);
        }
        heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
        StructAM_CreateFrom(2, &g_GlobalTrophyResult->mModelAnimation, &g_GlobalTrophyResult->mModel, 1, heap, modelFile);
        StructAM_MaybeLoadAnimation(&g_GlobalTrophyResult->mModelAnimation, animationFile, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
        StructAM_SomeFn_MaybeLoadFrame(&g_GlobalTrophyResult->mModelAnimation, 0);
        storedRankIndex = g_GlobalTrophyResult->mRankIndex;
        if (storedRankIndex != 0) {
            frameIndex = 0.5f + TO_FIXED12(storedRankIndex);
        } else {
            frameIndex = TO_FIXED12(storedRankIndex) - 0.5f;
        }
        modelAnimation = &g_GlobalTrophyResult->mModelAnimation;
        modelAnimation->mHead.mFrameIndex = frameIndex;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
        SomeEffectFileStuff(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
        if (rankIndex == 0) {
            Vec3 effectPos0 = {0, 0, 0};

            g_GlobalTrophyResult->mEffect0 = StartEffect(0, &effectPos0);
            {
                Vec3 effectPos1 = {0, 0, 0};

                g_GlobalTrophyResult->mEffect4 = StartEffect(4, &effectPos1);
                {
                    Vec3 effectPos2 = {0, 0, 0};

                    g_GlobalTrophyResult->mEffect5 = StartEffect(5, &effectPos2);
                }
            }
        } else if (rankIndex == 1) {
            Vec3 effectPos3 = {0, 0, 0};

            g_GlobalTrophyResult->mEffect0 = StartEffect(0, &effectPos3);
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

    if (g_GlobalTrophyResult->mRankIndex >= 3) {
        return;
    }
    UpdateEffects();
    g_GlobalTrophyResult->mRotateYAngle += 0x6d;
    trophy = g_GlobalTrophyResult;
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

    if (g_GlobalTrophyResult->mRankIndex >= 3) {
        return;
    }
    DrawEffects(&g_GlobalTrophyResult->mEffectMatrix);
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
    rotateZAngle = g_GlobalTrophyResult->mRotateZWobble.mValue;
    MTX_RotX33__from_thumb(&rotateXMatrix, SIN_OF_ANGLE(0xbb0), COS_OF_ANGLE(0xbb0));
    MTX_RotY33__from_thumb(&rotateYMatrix, FX_SinIdx(g_GlobalTrophyResult->mRotateYAngle), FX_CosIdx(g_GlobalTrophyResult->mRotateYAngle));
    MTX_RotZ33__from_thumb(&rotateZMatrix, FX_SinIdx(rotateZAngle), FX_CosIdx(rotateZAngle));
    NNS_G3dGeBufferOP_N(0x1a, &rotateXMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
    zeroTranslation[0] = 0;
    zeroTranslation[1] = 0;
    zeroTranslation[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, zeroTranslation, 3);
    DrawNsbmd(&g_GlobalTrophyResult->mModel);
    NNS_G3dGeFlushBuffer();
}

s32 GetKartBalloonOrShineHeight(Kart *kart) {
    KartModelsEntry *kartModelsEntry;

    kartModelsEntry = kart->mKartModelsEntry;
    return gCharacterBalloonOrShineHeights[kartModelsEntry->mCharacterIndex] +
           kartModelsEntry->mKartOffsetData->mCharacterOffsets[kartModelsEntry->mCharacterIndex].y;
}

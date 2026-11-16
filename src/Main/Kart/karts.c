#include "Main/Kart/karts.h"
#include "Main/Kart/character_animation.h"
#include "model_material_set.h" // NNSG3dResFileHeader

#include "Main/System/heap.h"
#include "linked_vram_block_pool.h"
#include "linked_texture_vram_alloc.h"
#include "linked_palette_vram_alloc.h"
#include "linked_list_ops.h"
#include "Main/System/archive_slots.h"
#include "expanded_heap_head.h"
#include "geometry_render_state.h"
#include "animation_lookup.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Kart/kart_model_path.h"
#include "Main/Kart/shadow_model.h"
#include "sound_archive_load.h"
#include "Main/System/backup_net_camera_work.h"
#include "fixed_point_graphics_setup.h"
#include "Main/Kart/kart_model_menu.h"
#include "Main/Item/item_in_use.h"
#include "arena_cache_init.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/emblem_cursor.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "thread_scheduler.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "vram_load_3d_graphics.h"
#include "model_texture_bind.h"
#include "model_draw_state.h"
#include "vram_transfer_queue.h"
#include "matrix_4x3_basic.h"
#include "geometry_engine_setup.h"
#include "cpu_copy_fill.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "heap_expanded_allocator.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race.h"
#include "geometry_function_tables_and_fast_dma.h"
#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "system_state_globals.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_appear.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/kart_killer_render.h"
#include "Main/Kart/kart_killer_animation_reset.h"
#include "Main/Graphics/emitters.h"
#include "Main/Kart/kart_ai.h"
#include "print_memory_multibyte_write.h"
#include "signed_int_divide.h"
#include "model_set_resource_lookup.h"
#include "Main/Graphics/model_animation_looping.h"
#include "Main/Kart/kart_models_entry.h"
#include "Main/Kart/kart_model_color_blend.h"
#include "Main/Kart/kart_course_colors.h"
#include "Main/Kart/kart_drift.h"
#include "01/Race/mission_run_state.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/kart_surface_effects.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_draw.h"
#include "Main/Kart/kart_peer.h"
#include "Main/Kart/camera.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Kart/kart_resources.h"
#include "ITCM/kart_motion.h"
#include "Main/Race/race_clock.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Graphics/nsbmd_draw.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const Vec3 gCameraVec3UnitX = {0x1000, 0, 0};
const Vec3 gCameraVec3Zero = {0, 0, 0};
const Vec3 gCameraVec3UnitZ = {0, 0, 0x1000};
const Vec3 gCameraVec3UnitY = {0, 0x1000, 0};
const char g_str_P_main[16] = "P_main";
const char g_str_emblem_pl[16] = "emblem_pl";
const char g_str_kart_body[16] = "kart_body";
const char gKartEmblemMaterialName[16] = "kart_emblem";
const char g_str_P_main_0[16] = "P_main";
const char g_str_E_main[16] = "E_main";
const char g_str_P_face[16] = "P_face";
const char g_str_emblem[16] = "emblem";
const char g_str_E_main_0[16] = "E_main";
const char g_str_E_face[16] = "E_face";
const char g_str_kart_body_0[16] = "kart_body";
const char g_str_kart_tire[16] = "kart_tire";
const char g_str_kart_tire_0[16] = "kart_tire";
const u16 gCharacterBEFacePalette[8] = {0x7bdf, 0x463f, 0x3dff, 0x18df, 0x18df, 0x18da, 0x7fff, 0x7fff};
const u16 gCharacterBEMainPalette[16] = {0,      0x18c6, 0x318c, 0x30e9, 0x354a, 0x3d4d, 0x45ad, 0x3daf,
                                         0x4e12, 0x5674, 0x5eb6, 0x62f6, 0x6b38, 0x080c, 0x0c12, 0x7fff};
const u16 gSpecialKartFirstPalette[16] = {0,      0x18c6, 0x45ad, 0x49ef, 0x5674, 0x5eb6, 0x62f6, 0x24de,
                                          0x3dbf, 0x7d50, 0x7e35, 0x2ffd, 0x5fff, 0x4704, 0x63ed, 0x7fff};
const u16 gSpecialKartSecondPalette[16] = {0,      0x18c6, 0x318c, 0x30e9, 0x3d4d, 0x45ad, 0x354a, 0x3daf,
                                           0x4e12, 0x5674, 0x5eb6, 0x62f6, 0x4a52, 0,      0,      0};
const u16 gCharacterBPMainPalette[16] = {0,      0x18c6, 0x318c, 0x30e9, 0x3d4d, 0x45ad, 0x354a, 0x3daf,
                                         0x4e12, 0x5674, 0x5eb6, 0x62f6, 0x6b38, 0x0c12, 0x7fff, 0x7fff};
const u16 gCharacterBPFacePalette[32] = {0,      0x18da, 0x18df, 0x211f, 0x295f, 0x319f, 0x35bf, 0x3dff,
                                         0x463f, 0x56bf, 0x633f, 0x6f7f, 0x7bdf, 0x7fff, 0x7fff, 0x7fff,
                                         0,      0x1063, 0x1462, 0x2081, 0x2460, 0x2881, 0x2ca1, 0x34a0,
                                         0x3cc0, 0x40c0, 0x4cc0, 0x54e0, 0x58e0, 0x60e0, 0x64e0, 0x6ce0};

u16 g_MQEntryCount;
u16 gKillerItemKartIndex;
s32 gKartSpeedLimitReciprocal;
struct Kart *g_GlobalMQ;
s32 gKartForwardSpeedRatio;
struct EntryKartCounters *g_GlobalRK;
u32 gKartZoneMask;
s32 gMinKartDistanceSquaredPresent;
s32 gMissionRunEndShapesPresent;

void DrawShadowModelIfDrawFlag(ShadowModel *shadowModel, u32 unusedSecond, u32 unusedThird) {
    if ((shadowModel->mFlags & 1) != 0) {
        SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
        gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
        SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
        gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    }
}

void CreateGlobalMQAndRK(u32 kartCount) {
    u16 kartIndex;
    void *heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    EntryKartCounters *entryKartCounters;
    g_GlobalMQ = Mem_AllocateHeap(heap, kartCount * 0x5a8);
    g_MQEntryCount = kartCount;
    entryKartCounters = Mem_AllocateHeap(heap, sizeof(*entryKartCounters));
    g_GlobalRK = entryKartCounters;
    gKillerItemKartIndex = 0;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    entryKartCounters->mRaceStartBoosted = 0;
    entryKartCounters->mMiniTurboCount = 0;
    entryKartCounters->mItemHitCount = 0;
    entryKartCounters->mSurfaceCount = 0;
    entryKartCounters->mCourseContactCount = 0;
    entryKartCounters->mMapObjectHitCount = 0;
    entryKartCounters->mRespawnCount = 0;
    gNearPlayerRankKartCount = g_GlobalCO->mMode == MODE_BATTLE ? 1 : 2;
    InitKartMapObjectResponses();
    RegisterKartAiCallbacks();
    InitKartEffects(kartCount);
    gMissionRunEndShapesPresent = 0;
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        if (g_GlobalPE->mMissionEndShapeCount != 0) {
            gMissionRunEndShapesPresent = 1;
        }
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        g_GlobalMQ[kartIndex].mIndex = kartIndex;
        g_GlobalMQ[kartIndex].mEntryIndex = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mIndex;
        StructMQRacerEntry_Create(&g_GlobalMQ[kartIndex], g_DefaultMQFnList);
    }
    gKartZoneMask = 0;
}

void UpdateKarts(void) {
    s32 kartIndex;
    Kart *kart = g_GlobalMQ;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        UpdateKartPrevValuesAndClearFlags(kart);
        kart++;
    }
    SetKartNearPlayerRankBits();
    kart = g_GlobalMQ;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        kart->mSlotFunctions[3](kart);
        kart++;
    }
    kart = g_GlobalMQ;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        kart->mSlotFunctions[4](kart);
        kart++;
    }
}

void UpdateKartSoundDistancesSquared(void) {
    Kart *kart = g_GlobalMQ;
    s16 kartIndex;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        kart->mSlotFunctions[2](kart);
        kart++;
    }
}

void DrawKarts(void) {
    s32 drawOrderIndex = 0;
    u16 *kartIndices = GetKartIndicesByDistance();
    (g_GlobalMQ[g_GlobalCO->mEntryIndex].mKartModelsEntry)->mFarFromCamera = TRUE;
    for (; drawOrderIndex < g_MQEntryCount; drawOrderIndex++) {
        StructMQRacerEntry_SomeFn_50(&g_GlobalMQ[*kartIndices]);
        kartIndices++;
    }
}

void ResetGlobalMQ(void) {
    s32 kartIndex;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        StructMQRacerEntry_Dispose(&g_GlobalMQ[kartIndex]);
    }
    g_GlobalMQ = NULL;
}

Kart *GetRacerMQEntry(s32 kartIndex) {
    return &g_GlobalMQ[kartIndex];
}

void LoadRacerMQVectorB(Vec3 *pos, s32 kartIndex) {
    *pos = *g_GlobalMQ[kartIndex].mPosSource;
}

void LoadRacerMQVectorC(Vec3 *pos, u8 kartIndex) {
    *pos = *g_GlobalMQ[kartIndex].mPosSourceCopy;
}

void LoadRacerMQVectorA(Vec3 *pos, s32 kartIndex) {
    *pos = g_GlobalMQ[kartIndex].mPrevPos;
}

void LoadRacerMQVectorD(Vec3 *scale, s32 kartIndex) {
    *scale = g_GlobalMQ[kartIndex].mScale;
}

u32 GetKartItemEffect(u32 kartIndex) {
    return g_GlobalMQ[kartIndex].mItemEffect;
}

u16 GetKartHeadingAngle(s32 kartIndex) {
    return g_GlobalMQ[kartIndex].mHeadingAngle;
}

u32 IsMissionRunWithEndShapes(void) {
    return gMissionRunEndShapesPresent;
}

BOOL RacerEntryHasFlags0x60(u16 kartIndex) {
    return StructMQRacerEntry_HasFlags0x60(&g_GlobalMQ[kartIndex]);
}

void StructMQRacerEntry_SomeFn_21_ById(u16 kartIndex) {
    StructMQRacerEntry_SomeFn_21(&g_GlobalMQ[kartIndex]);
}

BOOL IsKartOnBoostSurface(s32 kartIndex) {
    return (g_GlobalMQ[kartIndex].mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) != 0;
}

u32 GetKartForwardSpeedRatio(void) {
    return gKartForwardSpeedRatio;
}

// Sets bit i when the kart is inside kind 3 shape list i.
void SetKartZoneMask(s32 kartIndex) {
    u16 shapeListIndex;

    gKartZoneMask = 0;
    for (shapeListIndex = 0; shapeListIndex < 8; shapeListIndex++) {
        if (IsKartInCourseMapZoneShapeList(kartIndex, shapeListIndex) != 0) {
            BIT_SET(gKartZoneMask, shapeListIndex);
        }
    }
}

u32 GetKartZoneMask(void) {
    return gKartZoneMask;
}

// Stores the forward speed as a part of the speed limit, 0x1000 = 1.0.
void SetKartForwardSpeedRatio(s32 forwardSpeed) {
    gKartForwardSpeedRatio = MUL_FIXED12_ROUNDED(forwardSpeed, gKartSpeedLimitReciprocal);
}

void SetKartSpeedLimitReciprocal(u32 speedLimitReciprocal) {
    gKartSpeedLimitReciprocal = speedLimitReciprocal;
}

void IncrementEntryKartItemHitCount(s32 kartIndex) {
    if (kartIndex == g_GlobalCO->mEntryIndex) {
        g_GlobalRK->mItemHitCount++;
    }
}

void IncrementEntryKartSurfaceCount(Kart *kart) {
    if (kart->mIndex != g_GlobalCO->mEntryIndex) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        return;
    }
    if (!(kart->mDriveFlags & KART_DRIVE_ITEM_BOOST)) {
        g_GlobalRK->mSurfaceCount++;
    }
}

EntryKartCounters *GetGlobalRK(void) {
    return g_GlobalRK;
}

u32 GetKartCourseHitAttributeBitWrapper(int kartIndex) {
    return StructMQRacerEntry_SomeFn_71(&g_GlobalMQ[kartIndex]);
}

void SetKartModelsFogEnable(s32 fogEnableFlag) {
    s32 kartIndex;
    Kart *kart = g_GlobalMQ;
    KartModelsEntry *entry;
    for (kartIndex = 0; kartIndex < g_MQEntryCount; kartIndex++) {
        entry = kart->mKartModelsEntry;
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[1]->mResMdl, fogEnableFlag);
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[0]->mResMdl, fogEnableFlag);
        if (entry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[2]->mResMdl, fogEnableFlag);
        }
        kart++;
    }
}

BOOL StructMQHasFlagB_800(s32 kartIndex) {
    return (g_GlobalMQ[kartIndex].mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0 ? 1 : 0;
}

BOOL IsEntryKartNotNormalOrScaleTableBit(void) {
    Kart *kart = &g_GlobalMQ[g_GlobalCO->mEntryIndex];
    if (kart->mState != KART_STATE_NORMAL || (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsEntryKartInContact(void) {
    return (g_GlobalMQ[g_GlobalCO->mEntryIndex].mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) !=
                   0
               ? 1
               : 0;
}

BOOL IsEntryKartRespawnFalling(void) {
    return (g_GlobalMQ[g_GlobalCO->mEntryIndex].mDriveFlags & KART_DRIVE_RESPAWN_FALL) != 0 ? 1 : 0;
}

void SetKartNearPlayerRankBits(void) {
    s32 kartIndices[3];
    u32 kartRank = GetSomeRacerFlags((u16) g_GlobalCO->mEntryIndex);
    u16 nearSlotIndex;
    u16 awardKartIndex;
    s32 kartIndex;
    Kart *kart;
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        for (awardKartIndex = 0; awardKartIndex < 3; awardKartIndex++) {
            g_GlobalMQ[awardKartIndex].mEffectFlags |= KART_EFFECT_NEAR_PLAYER_RANK;
        }
        return;
    }
    kartIndices[0] = g_GlobalCO->mEntryIndex;
    if (kartRank == 1) {
        kartIndices[1] = GetKartIndexAtRank(2);
        if (kartIndices[1] >= 0) {
            if ((g_GlobalMQ[kartIndices[1]].mKartModelsEntry)->mFarFromCamera != FALSE) {
                kartIndices[1] = -1;
            }
        }
    } else {
        kartIndices[1] = GetKartIndexAtRank((u16) (kartRank - 1));
        if (kartIndices[1] >= 0) {
            if ((g_GlobalMQ[kartIndices[1]].mKartModelsEntry)->mFarFromCamera != FALSE) {
                kartIndices[1] = -1;
            }
        }
        if (kartRank < g_GlobalCO->mKartCount) {
            kartIndex = GetKartIndexAtRank((u16) (kartRank + 1));
            if (kartIndex >= 0) {
                kart = &g_GlobalMQ[kartIndex];
                kart->mEffectFlags |= KART_EFFECT_ONE_RANK_BEHIND_PLAYER;
            }
        }
    }
    for (nearSlotIndex = 0; nearSlotIndex < gNearPlayerRankKartCount; nearSlotIndex++) {
        kartIndex = kartIndices[nearSlotIndex];
        if (kartIndex >= 0) {
            kart = &g_GlobalMQ[kartIndex];
            if ((kart->mEffectFlags & KART_EFFECT_KILLER) == 0) {
                kart->mEffectFlags |= KART_EFFECT_NEAR_PLAYER_RANK;
            }
        }
    }
}

u32 GetKillerItemKartIndex(void) {
    return (gKillerItemKartIndex);
}

void SetKillerItemKartIndex(u32 kartIndex) {
    gKillerItemKartIndex = kartIndex;
}

// Keeps the smallest value of the frame; UpdateKarts clears it.
void SetMinKartDistanceSquared(s32 distanceSquared) {
    if (gMinKartDistanceSquared < 0 || distanceSquared < gMinKartDistanceSquared) {
        gMinKartDistanceSquared = distanceSquared;
        gMinKartDistanceSquaredPresent = 1;
    }
}

BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared) {
    if (gMinKartDistanceSquaredPresent == 0) {
        return FALSE;
    }
    *distanceSquared = gMinKartDistanceSquared;
    return TRUE;
}

BOOL IsEntryKartNormalOrNotMissionRun(void) {
    BOOL result = TRUE;
    s32 mode = g_GlobalCO->mMode;
    if (mode == MODE_MISSION_RUN) {
        Kart *kart = &g_GlobalMQ[g_GlobalCO->mEntryIndex];
        if (kart->mState != KART_STATE_NORMAL ||
            (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT | KART_DRIVE_RESPAWN_LANDING)) != 0 ||
            (kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0 ||
            (mode != MODE_MISSION_RUN ? 0 : IsAnyBalloonUnparked()) != 0) {
            result = FALSE;
        }
    }
    return result;
}

void ModelBlock_SomeMatFn(NNSG3dResMdl *mdl, u32 colorSet) {
    u32 diffColor;
    u32 ambColor;
    u32 specColor;
    u32 emiColor;
    switch (colorSet) {
        case KART_MODEL_COLORS_COURSE: {
            u16 *courseColors = g_GlobalAD00->mCourseColors;
            diffColor = courseColors[0];
            ambColor = courseColors[1];
            specColor = courseColors[2];
            emiColor = courseColors[3];
            break;
        }
        case KART_MODEL_COLORS_DARK:
            ambColor = 0;
            specColor = 0;
            emiColor = 0;
            diffColor = 0x2108;
            break;
        case KART_MODEL_COLORS_DARK_EMISSIVE:
            ambColor = 0;
            specColor = 0;
            diffColor = 0x2108;
            emiColor = 0x4210;
            break;
        case KART_MODEL_COLORS_MENU:
            diffColor = COLOR15_WHITE;
            ambColor = 0x14a5;
            emiColor = 0x2108;
            specColor = 0;
            break;
    }
    ModelBlock_SomeMatFn_0(mdl, diffColor);
    ModelBlock_SomeMatFn_1(mdl, ambColor);
    ModelBlock_SomeMatFn_2(mdl, specColor);
    ModelBlock_SomeMatFn_3(mdl, emiColor);
}

u16 GetKartCourseDiffColor(void) {
    return g_GlobalAD00->mCourseColors[0];
}

u16 GetKartCourseEmiColor(void) {
    return g_GlobalAD00->mCourseColors[3];
}

u16 GetKartCourseAmbColor(void) {
    return g_GlobalAD00->mCourseColors[1];
}

void StartKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor) {
    KartModelColorBlend *blend;

    blend = &kartModelsEntry->mColorBlend;
    blend->mDiffStartR = kartModelsEntry->mColorBlend.mDiffColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mDiffDeltaR = (s16) (targetDiffColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) - blend->mDiffStartR;
    blend->mDiffStartG = (kartModelsEntry->mColorBlend.mDiffColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) &
                         KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mDiffDeltaG =
        (s16) ((targetDiffColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mDiffStartG;
    blend->mDiffStartB = (kartModelsEntry->mColorBlend.mDiffColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) &
                         KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mDiffDeltaB =
        (s16) ((targetDiffColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mDiffStartB;
    blend->mEmiStartR = blend->mEmiColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mEmiDeltaR = (s16) (targetEmiColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) - blend->mEmiStartR;
    blend->mEmiStartG = (blend->mEmiColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mEmiDeltaG =
        (s16) ((targetEmiColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mEmiStartG;
    blend->mEmiStartB = (blend->mEmiColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mEmiDeltaB =
        (s16) ((targetEmiColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mEmiStartB;
    blend->mAmbStartR = blend->mAmbColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mAmbDeltaR = (s16) (targetAmbColor & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) - blend->mAmbStartR;
    blend->mAmbStartG = (blend->mAmbColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mAmbDeltaG =
        (s16) ((targetAmbColor >> KART_MODEL_COLOR_BLEND_GREEN_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mAmbStartG;
    blend->mAmbStartB = (blend->mAmbColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK;
    blend->mAmbDeltaB =
        (s16) ((targetAmbColor >> KART_MODEL_COLOR_BLEND_BLUE_SHIFT) & KART_MODEL_COLOR_BLEND_CHANNEL_MASK) -
        blend->mAmbStartB;
    blend->mBlendProgress = 0;
}

s32 AdvanceKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, s32 blendAmount) {
    KartModelColorBlend *blend = &kartModelsEntry->mColorBlend;
    BOOL finished = FALSE;

    if (blend->mBlendProgress < KART_MODEL_COLOR_BLEND_PROGRESS_END) {
        blend->mBlendProgress += blendAmount;
        if (blend->mBlendProgress >= KART_MODEL_COLOR_BLEND_PROGRESS_END) {
            blend->mBlendProgress = KART_MODEL_COLOR_BLEND_PROGRESS_END;
            finished = TRUE;
        }
        blend->mDiffColor =
            (s16) (blend->mDiffStartR + MUL_FIXED12_ROUNDED(blend->mDiffDeltaR, blend->mBlendProgress)) +
            ((s16) (blend->mDiffStartG + MUL_FIXED12_ROUNDED(blend->mDiffDeltaG, blend->mBlendProgress))
             << KART_MODEL_COLOR_BLEND_GREEN_SHIFT) +
            ((s16) (blend->mDiffStartB + MUL_FIXED12_ROUNDED(blend->mDiffDeltaB, blend->mBlendProgress))
             << KART_MODEL_COLOR_BLEND_BLUE_SHIFT);
        ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[0]->mResMdl, blend->mDiffColor);
        ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[1]->mResMdl, blend->mDiffColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[2]->mResMdl, blend->mDiffColor);
        }
        blend->mEmiColor = (s16) (blend->mEmiStartR + MUL_FIXED12_ROUNDED(blend->mEmiDeltaR, blend->mBlendProgress)) +
                           ((s16) (blend->mEmiStartG + MUL_FIXED12_ROUNDED(blend->mEmiDeltaG, blend->mBlendProgress))
                            << KART_MODEL_COLOR_BLEND_GREEN_SHIFT) +
                           ((s16) (blend->mEmiStartB + MUL_FIXED12_ROUNDED(blend->mEmiDeltaB, blend->mBlendProgress))
                            << KART_MODEL_COLOR_BLEND_BLUE_SHIFT);
        ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[0]->mResMdl, blend->mEmiColor);
        ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[1]->mResMdl, blend->mEmiColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[2]->mResMdl, blend->mEmiColor);
        }
        {
            s16 ambientRed = blend->mAmbStartR + MUL_FIXED12_ROUNDED(blend->mAmbDeltaR, blend->mBlendProgress);
            s16 ambientGreen = blend->mAmbStartG + MUL_FIXED12_ROUNDED(blend->mAmbDeltaG, blend->mBlendProgress);
            s16 ambientBlue = blend->mAmbStartB + MUL_FIXED12_ROUNDED(blend->mAmbDeltaB, blend->mBlendProgress);
            ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[0]->mResMdl, blend->mAmbColor);
            ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[1]->mResMdl, blend->mAmbColor);
            if (kartModelsEntry->mModels[2] != NULL) {
                ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[2]->mResMdl, blend->mAmbColor);
            }
            blend->mAmbColor = ambientRed + (ambientGreen << KART_MODEL_COLOR_BLEND_GREEN_SHIFT) +
                               (ambientBlue << KART_MODEL_COLOR_BLEND_BLUE_SHIFT);
        }
    } else {
        finished = TRUE;
    }
    return finished;
}

void StructAD00Sub_SomeFn_3(struct KartModelsEntry *kartModelsEntry) {
    u16 *courseColors = g_GlobalAD00->mCourseColors;
    u32 diffColor;
    u32 emiColor;
    u32 ambColor;

    diffColor = courseColors[0];
    emiColor = courseColors[3];
    ambColor = courseColors[1];
    ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[0]->mResMdl, diffColor);
    ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[1]->mResMdl, diffColor);
    ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[0]->mResMdl, emiColor);
    ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[1]->mResMdl, emiColor);
    ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[0]->mResMdl, ambColor);
    ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[1]->mResMdl, ambColor);
    if (kartModelsEntry->mModels[2] != NULL) {
        ModelBlock_SomeMatFn_0(kartModelsEntry->mModels[2]->mResMdl, diffColor);
        ModelBlock_SomeMatFn_3(kartModelsEntry->mModels[2]->mResMdl, emiColor);
        ModelBlock_SomeMatFn_1(kartModelsEntry->mModels[2]->mResMdl, ambColor);
    }
}

KartModelsEntry *GetAD00SubRacer(u32 kartIndex) {
    return &g_GlobalAD00->mKartModelsEntries[kartIndex];
}

void *GetCharacterKartModel(u16 kartIndex) {
    return g_GlobalAD00->mKartModelsEntries[kartIndex].mModels[1]->mResMdl;
}

// Shows (b non-zero) or hides the tire material of the kart model.
void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible) {
    NNS_G3dMdlSetMdlAlpha(kartModelsEntry->mModels[1]->mResMdl, g_GlobalAD00->mKartTireMaterialIndex,
                          visible != 0 ? 0x1f : 0);
}

void *GetKillerItemModel(void) {
    return &g_GlobalAD00->mKillerItem;
}

void *GetSomeAD00Sh(void) {
    return &g_GlobalAD00->mKillerItemS;
}

void *GetAD00KillerItemAnimation(void) {
    return &g_GlobalAD00->mKillerItemNsbca;
}

u32 GetAD00SubKartIndexMod3(u16 kartIndex) {
    return g_GlobalAD00->mKartModelsEntries[kartIndex].mVariant;
}

#pragma thumb on
void StructAD00Sub_Initialize_from_thumb(void *entry) {
    u32 fieldValue = (u32) entry;
    u32 scratchValue;
    u32 copiedValue;
    u32 entryAddress;
    entryAddress = (fieldValue) + (0u);
    fieldValue = 0u;
    scratchValue = ~(fieldValue);
    *(u32 *) ((entryAddress) + 0u) = scratchValue;
    *(u32 *) ((entryAddress) + 4u) = scratchValue;
    *(u32 *) ((entryAddress) + 8u) = fieldValue;
    *(u32 *) ((entryAddress) + 12u) = fieldValue;
    *(u32 *) ((entryAddress) + 16u) = fieldValue;
    *(u32 *) ((entryAddress) + 20u) = fieldValue;
    *(u32 *) ((entryAddress) + 24u) = fieldValue;
    *(u32 *) ((entryAddress) + 28u) = fieldValue;
    *(u32 *) ((entryAddress) + 32u) = fieldValue;
    fieldValue = (entryAddress) + (0u);
    fieldValue = (fieldValue) + 36u;
    StructAD00SubSub_Create_from_thumb(fieldValue);
    fieldValue = 0u;
    *(u32 *) ((entryAddress) + 84u) = fieldValue;
    *(u32 *) ((entryAddress) + 88u) = fieldValue;
    *(u32 *) ((entryAddress) + 92u) = fieldValue;
    *(u32 *) ((entryAddress) + 96u) = fieldValue;
    *(u32 *) ((entryAddress) + 100u) = fieldValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 104u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 172u;
    *(u32 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 176u;
    *(u32 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 110u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 110u;
    copiedValue = *(const u16 *) ((scratchValue) + 0u);
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 108u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 108u;
    copiedValue = *(const u16 *) ((scratchValue) + 0u);
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 106u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 116u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 116u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 114u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 114u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 112u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 122u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 122u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 120u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 120u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 118u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 128u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 128u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 126u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 126u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 124u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 134u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 134u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 132u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 132u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 130u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 140u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 140u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 138u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 138u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 136u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 146u;
    *(u16 *) ((scratchValue) + 0u) = fieldValue;
    scratchValue = 146u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 144u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    scratchValue = 144u;
    copiedValue = *(const s16 *) ((entryAddress) + (scratchValue));
    scratchValue = (entryAddress) + (0u);
    scratchValue = (scratchValue) + 142u;
    *(u16 *) ((scratchValue) + 0u) = copiedValue;
    entryAddress = (entryAddress) + 148u;
    *(u16 *) ((entryAddress) + 0u) = fieldValue;
}
#pragma thumb off

#pragma thumb on

void StructAD00Sub_SomeFn_from_thumb(KartModelsEntry *kartModelsEntry) {
    StructAM_InitializeImpl(&kartModelsEntry->mKillerItemAnimation,
                               StructAM_GetFrameCount_Times4096(&g_GlobalAD00->mKillerItemNsbca));
}

#pragma thumb off

#pragma thumb on
void StructAD00SubSub_Create_from_thumb(u32 animationStateAddress) {
    u32 animationState = animationStateAddress;
    u32 zero;
    zero = 0u;
    *(u32 *) ((animationState) + 0u) = zero;
    *(u32 *) ((animationState) + 20u) = zero;
    *(u16 *) ((animationState) + 24u) = zero;
    *(u32 *) ((animationState) + 4u) = zero;
    *(u16 *) ((animationState) + 16u) = zero;
}
#pragma thumb off

#pragma thumb on

// TRUE when the entry's character files use the P name list.
BOOL DetermineIsP_from_thumb(s32 kartIndex) {
    BOOL pNameUsed = TRUE;
    s32 isEntryFollowedMissionRunAwardOrStaffRoll = pNameUsed;
    s32 isEntryFollowedOrMissionRun = pNameUsed;
    s32 isEntryOrFollowedKart = pNameUsed;
    if (kartIndex != g_GlobalCO->mEntryIndex && kartIndex != g_GlobalCO->mFollowedKartIndex) {
        isEntryOrFollowedKart = 0;
    }
    if (isEntryOrFollowedKart == 0 && g_GlobalCO->mMode != MODE_MISSION_RUN) {
        isEntryFollowedOrMissionRun = 0;
    }
    if (isEntryFollowedOrMissionRun == 0 && IsAwardOrStaffRoll_0() == 0) {
        isEntryFollowedMissionRunAwardOrStaffRoll = 0;
    }
    if (isEntryFollowedMissionRunAwardOrStaffRoll == 0 && g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        pNameUsed = FALSE;
    }
    if (pNameUsed != FALSE) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Stores the kart index modulo 3.
void StructAD00Sub_SetKartIndex_from_thumb(KartModelsEntry *kartModelsEntry, int kartIndex) {
    u16 variant;
    variant = kartIndex % 3;
    kartModelsEntry->mVariant = variant;
}

#pragma thumb off

#pragma thumb on

void InitializeGlobalAD00_from_thumb(void *heap, u32 kartCount) {
    u8 *kartOffsetFile;
    u16 kartIndex;
    KartModelsEntry *entry;
    KartModelsEntry *entries;
    kartOffsetFile = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb("kartoffsetdata.bin");
    SetCurrentlyInKartModelMenu(0);
    g_GlobalCE = NULL;
    g_GlobalAD00 = Mem_AllocateHeap(heap, sizeof(*g_GlobalAD00));
    g_GlobalAD00->mKartModelsEntries = Mem_AllocateHeap(heap, kartCount * 0xb4);
    g_GlobalAD00->mCourseColors = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("kartcrsmat.bin");
    g_GlobalAD00->mCourseColors = g_GlobalAD00->mCourseColors + (g_GlobalCO->mCourseId << 2) - 4;
    g_GlobalAD00->mKartAPalette = GetKartAPaletteData_from_thumb();
    g_GlobalAD00->mHeyhoPalettes = NULL;
    g_GlobalAD00->mPFaceanimNsbtpFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb((const char *) FormatCharacterFaceAnimationNsbtpPath());
    g_GlobalAD00->mKartCount = kartCount;
    g_GlobalAD00->mKartTireMaterialIndex = 0;
    AllocateGlobalFAT(heap, kartCount);
    MaybeLoadKartAIData_from_thumb();
    LoadAD00KillerItemModel_from_thumb(heap);
    for (kartIndex = 0; kartIndex < g_GlobalAD00->mKartCount; kartIndex++) {
        entries = g_GlobalAD00->mKartModelsEntries;
        entry = &entries[kartIndex];
        StructAD00Sub_Initialize_from_thumb(entry);
        entry->mRegion = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mRegion;
        StructAD00Sub_SomeFn_from_thumb(entry);
        entries[kartIndex].mCharacterIndex = g_GlobalCO->mCurrentEntries[kartIndex].mCharacterIndex;
        entry->mKartIndex = g_GlobalCO->mCurrentEntries[kartIndex].mKartIndex;
        StructAD00Sub_SetKartIndex_from_thumb(entry, entry->mKartIndex);
        entry->mKartOffsetData = Mem_AllocateHeap(heap, sizeof(*entry->mKartOffsetData));
        Mem_CpuCopy8(kartOffsetFile + entry->mKartIndex * sizeof(*entry->mKartOffsetData), entry->mKartOffsetData,
                    sizeof(*entry->mKartOffsetData));
        CopyKartCharPhysicalParam(kartIndex, entry->mKartIndex, entries[kartIndex].mCharacterIndex);
    }
    CreateKartModelsEntryModels(heap, 1);
    Dispose_KM1_Mount_KM2_from_thumb();
    CreateKartModelsEntryModels(heap, 0);
    for (kartIndex = 0; kartIndex < g_GlobalAD00->mKartCount; kartIndex++) {
        entry = &g_GlobalAD00->mKartModelsEntries[kartIndex];
        StructAD00Sub_SomeFnPaletteSwapRelated_from_thumb(entry, DetermineIsP_from_thumb(kartIndex));
    }
    {
        Nclr *nclr;
        Gfx_ReadPalette(&nclr, FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("/character/heyho/HH_color.NCLR"));
        g_GlobalAD00->mHeyhoPalettes = (HeyhoPalette *) nclr->mData;
    }
}

void CreateKartModelsEntryModels(void *heap, s32 firstPass) {
    BOOL isVariantZero;
    KartModelsEntry *entry;
    s32 pNameUsed;
    u16 tireIndex;
    BOOL skipKart;
    s32 entryGate;
    u16 kartIndex;
    s32 characterRangeStart;
    s32 characterRangeEnd;
    s32 kartRangeStart;
    s32 kartRangeEnd;
    Vec3 *dst;
    Vec3 *src;
    if (firstPass != 0) {
        characterRangeStart = 0;
        characterRangeEnd = 7;
        kartRangeStart = characterRangeStart;
        kartRangeEnd = 0x15;
    } else {
        characterRangeStart = 7;
        characterRangeEnd = 0xd;
        kartRangeStart = 0x15;
        kartRangeEnd = 0x25;
    }
    kartIndex = 0;
    if (kartIndex < g_GlobalAD00->mKartCount) {
        entryGate = (firstPass == 0) ? 1 : kartIndex;
        do {
            entry = &g_GlobalAD00->mKartModelsEntries[kartIndex];
            pNameUsed = DetermineIsP_from_thumb(kartIndex);
            if ((u16) entry->mKartIndex % 3 == 0) {
                isVariantZero = TRUE;
            } else {
                isVariantZero = FALSE;
            }
            skipKart = (isVariantZero != FALSE && entryGate != 0) ? TRUE : FALSE;
            if (entry->mCharacterIndex >= characterRangeStart && entry->mCharacterIndex < characterRangeEnd) {
                StructAD00Sub_LoadCharacterEmblem_from_thumb(entry, heap, pNameUsed);
            }
            if (skipKart == FALSE) {
                if ((isVariantZero != FALSE && firstPass != 0) ||
                    (entry->mKartIndex >= kartRangeStart && entry->mKartIndex < kartRangeEnd)) {
                    StructAD00Sub_LoadKartModel_from_thumb(entry, heap, pNameUsed);
                }
            }
            if (firstPass != 0) {
                if (pNameUsed != 0) {
                    tireIndex = 0;
                    entry->mTireTranslations = Mem_AllocateHeap(heap, sizeof(KartTireTranslations));
                    do {
                        dst = &entry->mTireTranslations->mTranslations[tireIndex];
                        src = &entry->mKartOffsetData->mTireOffsets[tireIndex];
                        dst->x = src->x >> 4;
                        dst->y = src->y >> 4;
                        dst->z = src->z >> 4;
                        tireIndex++;
                    } while (tireIndex < KART_TIRE_COUNT);
                    entry->mTireTranslations->mTranslations[1].x = FX_Div(
                        -entry->mTireTranslations->mTranslations[0].x * 2, entry->mKartOffsetData->mFirstTiresScale);
                    entry->mTireTranslations->mTranslations[3].x = -entry->mTireTranslations->mTranslations[2].x * 2;
                    StructAD00Sub_LoadKartTireModel_from_thumb(entry, heap);
                }
                StructAD00Sub_LoadKartShadowModel_from_thumb(entry, heap);
            }
            kartIndex++;
        } while (kartIndex < g_GlobalAD00->mKartCount);
    }
}

void StructAD00Sub_LoadCharacterEmblem_from_thumb(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 animationIndex;
    u16 characterIndex;
    BOOL hasFirstAnimation;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    void *animationFile;
    characterIndex = kartModelsEntry->mCharacterIndex;
    nsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(FormatCharacterEmblemNsbmdPath(characterIndex, pNameUsed));
    nsbtxFile = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(FormatCharacterEmblemNsbtxPath(characterIndex, pNameUsed));
    kartModelsEntry->mModels[0] = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mModels[0]));
    mdl = StructML_LoadModelAndTextures(heap, kartModelsEntry->mModels[0], nsbmdFile, nsbtxFile);
    StructML_MaybeProcessModelAnimations(kartModelsEntry->mModels[0], 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_COURSE);
    if (pNameUsed != 0) {
        animationIndex = 0;
        hasFirstAnimation = FALSE;
        kartModelsEntry->mCharacterAnimation = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mCharacterAnimation));
        StructAM_CreateFrom(0, kartModelsEntry->mCharacterAnimation, kartModelsEntry->mModels[0], 4, heap, NULL);
        do {
            animationFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(FormatCharacterEmblemNsbcaPath(characterIndex, animationIndex));
            if (animationFile != NULL) {
                void *jointAnimation = JNT0_LoadJointByIdx(Anim_NSBCA_LoadGetJNT0Block(animationFile), 0);
                StructAM_SomeFn_2(kartModelsEntry->mCharacterAnimation, animationIndex, jointAnimation,
                                        GetRacerAnimationIndex(animationIndex), heap);
                if (animationIndex == 0) {
                    hasFirstAnimation = TRUE;
                }
            }
            animationIndex++;
        } while (animationIndex < 4);
        if (hasFirstAnimation != FALSE) {
            StructAM_SomeFn_MaybeLoadFrame(kartModelsEntry->mCharacterAnimation, 0);
            kartModelsEntry->mAnimationState.mMiddleFrame =
                (StructAM_GetFrameCount_Times4096(kartModelsEntry->mCharacterAnimation) - 0x1000) / 2;
            kartModelsEntry->mAnimationState.mMiddleFrameReciprocal =
                FX_Div(0x1000, kartModelsEntry->mAnimationState.mMiddleFrame);
        } else {
            kartModelsEntry->mCharacterAnimation->mAnmObjCount = 0;
        }
    }
    kartModelsEntry->mFaceAnimation = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mFaceAnimation));
    StructAM_CreateFrom(2, kartModelsEntry->mFaceAnimation, kartModelsEntry->mModels[0], 1, heap, NULL);
    StructAM_MaybeLoadAnimation(kartModelsEntry->mFaceAnimation, g_GlobalAD00->mPFaceanimNsbtpFile, heap);
    StructAM_SomeFn_MaybeLoadFrame(kartModelsEntry->mFaceAnimation, 0);
}

void StructAD00Sub_LoadKartModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    s32 tireMaterialIndex;
    nsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(FormatCharacterKartNsbmdPath(kartIndex));
    nsbtxFile = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(FormatCharacterKartNsbtxPath(kartIndex));
    kartModelsEntry->mModels[1] = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mModels[1]));
    mdl = StructML_LoadModelAndTextures(heap, kartModelsEntry->mModels[1], nsbmdFile, nsbtxFile);
    StructML_MaybeProcessModelAnimations(kartModelsEntry->mModels[1], 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_COURSE);
    if (pNameUsed != 0) {
        tireMaterialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                       (const u32 *) g_str_kart_tire_0);
        NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
        g_GlobalAD00->mKartTireMaterialIndex = tireMaterialIndex;
    }
    LoadKartBodyPalette_from_thumb(kartModelsEntry->mModels[1], kartModelsEntry->mKartIndex, g_GlobalAD00->mKartAPalette);
}

u16 *GetKartAPaletteData_from_thumb(void) {
    Nclr *nclr;
    Gfx_ReadPalette(&nclr, FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("/kart/palette/kart_a.NCLR"));
    return nclr->mData;
}

u16 *GetKartModelMenuKartAPalette_from_thumb(void *heap) {
    void *file;
    Nclr *nclr;
    ReadKartModelMenuFile_from_thumb(heap, "kart/palette/kart_a.NCLR", &file);
    Gfx_ReadPalette(&nclr, file);
    return nclr->mData;
}

void LoadKartBodyPalette_from_thumb(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette) {
    NNSG3dResMdl *mdl;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    u8 *paletteSlice;
    s32 materialIndex;
    u32 paletteBase;
    if (kartIndex % 3 == 0) {
        mdl = nsbmd->mResMdl;
        paletteSlice = (u8 *) kartAPalette + kartIndex / 3 * 0x20;
        Arm_FlushRange(paletteSlice, 0x10);
        materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) g_str_kart_body_0);
        matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
        paletteBase = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex))->mTexPlttBase
                      << 4;
        GX_BeginLoadTexPltt();
        SomeDmaCopy_0(paletteSlice, paletteBase, 0x10);
        GX_EndLoadTexPltt();
    }
}

void StructAD00Sub_SomeFnPaletteSwapRelated_from_thumb(KartModelsEntry *kartModelsEntry, s32 pNameUsed) {
    const u16 *palette;
    u32 paletteBase;
    u32 secondPaletteSize;
    const u16 *secondPalette;
    u8 *materialBlock;
    u8 *dictionary;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMdl *mdl;
    NNSG3dResMatData *material;
    NNSG3dResMatData *firstMaterial;
    u8 *paletteAddress;
    s32 secondMaterialIndex;
    s32 materialIndex;
    if (kartModelsEntry->mRegion != 0) {
        if ((u32) (kartModelsEntry->mKartIndex - KART_INDEX_SPECIAL_FIRST) <= 1) {
            palette = NULL;
            mdl = kartModelsEntry->mModels[1]->mResMdl;
            switch (kartModelsEntry->mKartIndex) {
                case KART_INDEX_SPECIAL_FIRST:
                    palette = gSpecialKartFirstPalette;
                    break;
                case KART_INDEX_SPECIAL_SECOND:
                    palette = gSpecialKartSecondPalette;
                    break;
            }
            materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                       (const u32 *) g_str_kart_body);
            matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
            entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
            gSpecialKartBodyMaterial = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex));
            paletteBase = gSpecialKartBodyMaterial->mTexPlttBase << 4;
            GX_BeginLoadTexPltt();
            SomeDmaCopy_0(palette, paletteBase, 0x20);
            GX_EndLoadTexPltt();
        }
        if (kartModelsEntry->mCharacterIndex == CHARACTER_ROBO) {
            mdl = kartModelsEntry->mModels[0]->mResMdl;
            if (pNameUsed != 0) {
                materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                           (const u32 *) g_str_P_main_0);
                secondMaterialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                                 (const u32 *) g_str_P_face);
                palette = gCharacterBPMainPalette;
                secondPalette = gCharacterBPFacePalette;
                secondPaletteSize = 0x40;
            } else {
                materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                           (const u32 *) g_str_E_main_0);
                secondMaterialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                                 (const u32 *) g_str_E_face);
                palette = gCharacterBEMainPalette;
                secondPalette = gCharacterBEFacePalette;
                secondPaletteSize = 0x10;
            }
            materialBlock = OFFSET_PTR(u8, mdl, mdl->mOfsMat);
            dictionary = materialBlock + 4;
            material = OFFSET_PTR(NNSG3dResMatData, materialBlock,
                                  *(s32 *) ((dictionary = dictionary + *OFFSET_PTR(u16, materialBlock, 0xa)) +
                                            *(u16 *) dictionary * secondMaterialIndex + 4));
            firstMaterial = OFFSET_PTR(NNSG3dResMatData, materialBlock,
                                       *(s32 *) (dictionary + *(u16 *) dictionary * materialIndex + 4));
            paletteAddress = (u8 *) (firstMaterial->mTexPlttBase << 4);
            GX_BeginLoadTexPltt();
            SomeDmaCopy_0(palette, (u32) paletteAddress, 0x20);
            GX_EndLoadTexPltt();
            paletteAddress = (u8 *) (material->mTexPlttBase << 4);
            GX_BeginLoadTexPltt();
            SomeDmaCopy_0(secondPalette, (u32) paletteAddress, secondPaletteSize);
            GX_EndLoadTexPltt();
        }
    }
}

void StructAD00Sub_LoadKartTireModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResMdl *mdl;
    NNSG3dResFileHeader *nsbtxFile;
    nsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(FormatKartTireNsbmdPath(kartIndex, kartModelsEntry->mKartOffsetData->mTireName));
    nsbtxFile = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(FormatKartTireNsbtxPath(kartIndex, kartModelsEntry->mKartOffsetData->mTireName));
    kartModelsEntry->mModels[2] = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mModels[2]));
    mdl = StructML_LoadModelAndTextures(heap, kartModelsEntry->mModels[2], nsbmdFile, nsbtxFile);
    StructML_MaybeProcessModelAnimations(kartModelsEntry->mModels[2], 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_COURSE);
}

void StructAD00Sub_LoadKartShadowModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap) {
    void *nsbmdFile;
    NNSG3dResMdlSet *mdlSet;
    NNSG3dResDictEntryHeader *entries;
    nsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(FormatKartShadowNsbmdPath(kartModelsEntry->mKartIndex));
    kartModelsEntry->mShadowModel = Mem_AllocateHeap(heap, sizeof(*kartModelsEntry->mShadowModel));
    LoadedModelTexture_SomeFn(&kartModelsEntry->mShadowModel->mNsbmd.mResFileEntry, nsbmdFile, nsbmdFile);
    mdlSet = Nsbmd_GetMDL0Block(nsbmdFile);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mdlSet->mDict, mdlSet->mDict.mOfsEntry);
    StructAD00Sh_SomeFn(kartModelsEntry->mShadowModel,
                              OFFSET_PTR(NNSG3dResMdl, mdlSet, *DICT_ENTRY(u32, entries, 0)), 3);
}

void LoadAD00KillerItemModel_from_thumb(void *heap) {
    void *nsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("character/common/KillerItem.nsbmd");
    NNSG3dResFileHeader *nsbtxFile = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb("character/common/KillerItem.nsbtx");
    void *shadowNsbmdFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("character/common/KillerItem_s.nsbmd");
    void *nsbcaFile;
    ModelBlock_SomeMatFn(StructML_LoadModelAndTextures(heap, &g_GlobalAD00->mKillerItem, nsbmdFile, nsbtxFile),
                               KART_MODEL_COLORS_COURSE);
    StructML_MaybeProcessModelAnimations(&g_GlobalAD00->mKillerItem, 3);
    nsbcaFile = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("character/common/KillerItem.nsbca");
    StructAM_CreateFrom(0, &g_GlobalAD00->mKillerItemNsbca, &g_GlobalAD00->mKillerItem, 1, heap, nsbmdFile);
    StructAM_MaybeLoadAnimation(&g_GlobalAD00->mKillerItemNsbca, nsbcaFile, heap);
    StructAM_SomeFn_MaybeLoadFrame(&g_GlobalAD00->mKillerItemNsbca, 0);
    StructAD00Sh_SomeFn_2(&g_GlobalAD00->mKillerItemS, shadowNsbmdFile, 3);
    StructML_SetSomeDefaultFields(&g_GlobalAD00->mKillerItem);
}

void ReadKartModelMenuFile_from_thumb(void *heap, const void *fileName, void **file) {
    char path[0x100];
    _snprintf(path, 0x100, "/data/KartModelMenu/%s", fileName);
    ReadFileFromMountManagerHandle_from_thumb(path, heap, file);
}

void LoadKartAppearTablePointerCE_from_thumb(void *heap, s32 createKartAppear) {
    if (createKartAppear != 0) {
        g_GlobalCE->mUseEmblemTex = FALSE;
        g_GlobalCE->mKartAppear = LoadKartAppearTablePointer_from_thumb(heap);
    } else {
        g_GlobalCE->mUseEmblemTex = TRUE;
    }
    g_GlobalCE->mKartAPalette = GetKartModelMenuKartAPalette_from_thumb(heap);
    g_GlobalCE->mSelectModel = NULL;
}

#pragma thumb off

#pragma thumb on

void MaybeLoadWinModelTextureAnimationHelper_from_thumb(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile) {
    NNSG3dResMdl *mdl;
    u32 loopFlag;
    void *jointAnimation;
    mdl = StructML_LoadModelAndTextures2(nsbmd, modelFile, textureFile);
    StructML_MaybeProcessModelAnimations(nsbmd, 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_MENU);
    StructAM_CreateFrom(0, animation, nsbmd, 1, heap, NULL);
    jointAnimation = JNT0_LoadJointByIdx(Anim_NSBCA_LoadGetJNT0Block(animationFile), 0);
    loopFlag = GetRacerAnimationIndex(2);
    StructAM_SomeFn_2(animation, 0, jointAnimation, loopFlag, heap);
    StructAM_SomeFn_MaybeLoadFrame(animation, 0);
}

void StructML_SomeFn_6_from_thumb(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    u32 tireMaterialIndex;
    mdl = StructML_LoadModelAndTextures2(nsbmd, modelFile, textureFile);
    StructML_MaybeProcessModelAnimations(nsbmd, 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_MENU);
    tireMaterialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) g_str_kart_tire);
    NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
}

void StructML_LoadModel3Mat_from_thumb(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    mdl = StructML_LoadModelAndTextures2(nsbmd, modelFile, textureFile);
    StructML_MaybeProcessModelAnimations(nsbmd, 3);
    ModelBlock_SomeMatFn(mdl, KART_MODEL_COLORS_MENU);
}

#pragma thumb off

#pragma thumb on

void *StructAD00Sh_SomeFn_1_from_thumb(ShadowModel *shadowModel, NNSG3dResFileHeader *modelFile) {
    return StructAD00Sh_SomeFn_2(shadowModel, modelFile, 3);
}

void CreateCEML_from_thumb(void *heap) {
    void *modelFile;
    void *textureFile;
    ReadKartModelMenuFile_from_thumb(heap, g_str_kart_select_select_nsbmd, &modelFile);
    ReadKartModelMenuFile_from_thumb(heap, g_str_kart_select_select_nsbtx, &textureFile);
    g_GlobalCE->mSelectModel = Mem_AllocateHeap(heap, sizeof(*g_GlobalCE->mSelectModel));
    StructML_LoadModelAndTextures2(g_GlobalCE->mSelectModel, modelFile, textureFile);
    StructML_MaybeProcessModelAnimations(g_GlobalCE->mSelectModel, 2);
    ModelBlock_SetSomethingToAllMaterials(g_GlobalCE->mSelectModel->mResMdl, 1);
}

#pragma thumb off

#pragma thumb on

void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file) {
    g_GlobalCE->mEmblemTex = Nsbtx_GetTEX0Block(file);
    NNS_G3dResDefaultSetup(file);
}

void StructCESub_Initialize_from_thumb(void *heap, KartModelMenuSlot *slot) {
    StructAD00Sub_Initialize_from_thumb(slot);
    slot->mRegion = g_GlobalP->mRegion;
    slot->mEmblemTex = 0;
    slot->mCharacterNsbmd = Mem_AllocateHeap(heap, sizeof(*slot->mCharacterNsbmd));
    slot->mKartNsbmd = Mem_AllocateHeap(heap, sizeof(*slot->mKartNsbmd));
    slot->mTireNsbmd = Mem_AllocateHeap(heap, sizeof(*slot->mTireNsbmd));
    slot->mShadowModel = Mem_AllocateHeap(heap, sizeof(*slot->mShadowModel));
    slot->mCharacterAnimation = Mem_AllocateHeap(heap, sizeof(*slot->mCharacterAnimation));
}

void StructCE0_SomeFn_from_thumb(KartModelMenuView *view, int flag) {
    u32 bg0Offset;
    bg0Offset = 0;
    view->mCharacterIndex = KART_MODEL_MENU_NONE;
    view->mKartIndex = KART_MODEL_MENU_NONE;
    view->mScale = TO_FIXED12(1);
    view->mYawAngle = KART_MODEL_MENU_REST_YAW;
    view->mSpinAngle = view->mYawAngle;
    view->mTiltAngle = 0;
    view->mUnk_0c = 0;
    view->mUnk_10 = 0xffffff88;
    if (flag != 0) {
        bg0Offset = 0xffffff06;
    }
    view->mBg0Offset = bg0Offset;
    view->mBg0Direction = 0;
}

#pragma thumb off

#pragma thumb on

void QueueKartEmblemTexture(void *emblemData, void *emblemPalette) {
    NNSG3dResMdl *mdl;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    s32 materialIndex;
    s32 paletteBase;
    NNSG3dResMatData *material;
    KartModelMenuData *menu = g_GlobalCE;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s16 shownSlotIndex = menu->mShownSlotIndex;
    if (shownSlotIndex >= 0 && files->mLoadRequested == FALSE) {
        mdl = menu->mSlots[shownSlotIndex].mKartNsbmd->mResMdl;
        materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gKartEmblemMaterialName);
        matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
        material = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex));
        paletteBase = material->mTexPlttBase << 4;
        AllocateReserveTEQSub(VRAM_TARGET_TEXTURE_IMAGE, (material->mTexImageParam & 0xffff) << 3,
                                           emblemData, 0x200);
        AllocateReserveTEQSub(VRAM_TARGET_TEXTURE_PALETTE, paletteBase, emblemPalette, 0x20);
    }
}

void CreateGlobalCE_from_thumb(void *heap) {
    u16 fileIndex;
    SetActiveExecutionContextHeapGroupId_from_thumb(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    g_GlobalP->mUnk_1c &= ~STARTUP_FLAG_FAST_DMA;
    InitLnkVramManagers(heap);
    InitializeLoadedModelTextureList();
    SetCurrentlyInKartModelMenu(1);
    InitializeGlobalCE_from_thumb(heap);
    LoadKartAppearTablePointerCE_from_thumb(heap, 0);
    ReadKartModelMenuFile_from_thumb(heap, g_str_charmenuparam_bin, (void **) &g_GlobalCE->mCharMenuParams);
    ReadKartModelMenuFile_from_thumb(heap, g_str_kartmenuparam_bin, (void **) &g_GlobalCE->mKartMenuParams);
    CreateCEML_from_thumb(heap);
    for (fileIndex = 0; fileIndex < 2; fileIndex++) {
        CreateCESex_from_thumb(heap, &g_GlobalCE->mFiles[fileIndex]);
    }
    if (g_SaveDataHolder->mEmblemRecord->mFilled != 0 && g_SaveDataHolder->mFirstBlock->mEmblemOff == 0) {
        g_GlobalCE->mEmblemData = g_SaveDataHolder->mEmblemRecord->mEmblemData;
        g_GlobalCE->mEmblemPalette = GetEmblemPalette_from_thumb()->mData;
    }
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
}

void InitKartModelMenuWithKartList(void *heap) {
    u16 fileIndex;
    enum { KART_INDEX_FIRST } kartIndex;
    s32 characterIndex;
    SetActiveExecutionContextHeapGroupId_from_thumb(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    g_GlobalP->mUnk_1c &= ~STARTUP_FLAG_FAST_DMA;
    InitLnkVramManagers(heap);
    InitializeLoadedModelTextureList();
    SetCurrentlyInKartModelMenu(1);
    InitializeGlobalCE_from_thumb(heap);
    LoadKartAppearTablePointerCE_from_thumb(heap, 1);
    kartIndex = 0;
    g_GlobalCE->mKartIndex = kartIndex;
    g_GlobalCE->mKartListCount = kartIndex;
    g_GlobalCE->mKartListPos = kartIndex;
    while (kartIndex < 0x24) {
        if (FindKartModelMenuCharacter(&characterIndex, kartIndex) != 0) {
            g_GlobalCE->mKartListCount++;
        }
        kartIndex++;
    }
    g_GlobalCE->mView.mScale = gKartModelMenuMaxScale;
    for (fileIndex = 0; fileIndex < 2; fileIndex++) {
        CreateCESex_from_thumb(heap, &g_GlobalCE->mFiles[fileIndex]);
    }
    g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex].mLoadRequested = TRUE;
    g_GlobalCE->mView.mCharacterIndex = CHARACTER_MARIO;
    g_GlobalCE->mView.mKartIndex = 0;
    g_GlobalCE->mLoadSlot->mCharacterIndex = CHARACTER_MARIO;
    g_GlobalCE->mLoadSlot->mKartIndex = 0;
    g_GlobalCE->mLoadSlot->mKartOffsetData = g_GlobalCE->mKartOffsetTable;
    LoadKartAndCharacterFiles();
    AdvanceKartModelMenuLoad();
    StructCE0_SomeFn_from_thumb(&g_GlobalCE->mView, 0);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
}

void InitializeGlobalCE_from_thumb(void *heap) {
    u16 slotIndex;
    g_GlobalAD00 = NULL;
    g_GlobalCE = Mem_AllocateHeap(heap, sizeof(KartModelMenuData));
    g_GlobalCE->mShownSlotIndex = -1;
    g_GlobalCE->mLoadSlotIndex = 0;
    g_GlobalCE->mLoadSlot = &g_GlobalCE->mSlots[g_GlobalCE->mLoadSlotIndex];
    g_GlobalCE->mKartAPalette = NULL;
    g_GlobalCE->mSpinStopTimed = FALSE;
    g_GlobalCE->mSpinStopped = 0;
    g_GlobalCE->mMirrorMode = 0;
    g_GlobalCE->mCharMenuParams = NULL;
    g_GlobalCE->mKartMenuParams = NULL;
    g_GlobalCE->mCharacterRequested = 0;
    g_GlobalCE->mKartRequested = 0;
    g_GlobalCE->mKartAppear = NULL;
    g_GlobalCE->mSpinStopFrames = 0;
    g_GlobalCE->mEmblemPalette = NULL;
    g_GlobalCE->mEmblemData = g_GlobalCE->mEmblemPalette;
    ReadEmblemPalette_from_thumb(heap);
    ReadKartModelMenuFile_from_thumb(heap, g_str_kartoffsetdata_bin_0, (void **) &g_GlobalCE->mKartOffsetTable);
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        StructCESub_Initialize_from_thumb(heap, &g_GlobalCE->mSlots[slotIndex]);
    }
    StructCE0_SomeFn_from_thumb(&g_GlobalCE->mView, 1);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
}

s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex) {
    KartModelMenuData *menu = g_GlobalCE;
    s16 *characterParam = &menu->mCharMenuParams[characterIndex];
    KartMenuParams *kartParams = &menu->mKartMenuParams[kartIndex];
    menu->mMenuParams[0] = kartParams->mParams[0];
    menu->mMenuParams[1] = kartParams->mParams[1];
    menu->mMenuParams[2] = kartParams->mParams[2];
    menu->mMenuParams[3] = kartParams->mParams[3];
    menu->mMenuParams[4] = kartParams->mParams[4];
    menu->mMenuParams[5] = kartParams->mParams[5];
    menu->mMenuParams[2] += *characterParam;
    return g_GlobalCE->mMenuParams;
}

// Asks for a new character in the menu view; -1 clears it at once.
void RequestKartModelMenuCharacter(s32 characterIndex) {
    KartModelMenuData *menu = g_GlobalCE;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentCharacterIndex = view->mCharacterIndex;
    s32 noCharacter = KART_MODEL_MENU_NONE;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (characterIndex == noCharacter) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mCharacterIndex = characterIndex;
        shownSlot->mCharacterIndex = noCharacter;
        return;
    }
    if (files->mLoadRequested == FALSE && currentCharacterIndex != characterIndex && characterIndex <= 0xd) {
        view->mCharacterIndex = characterIndex;
        g_GlobalCE->mCharacterRequested = 1;
    }
}

void RequestKartModelMenuKart(s32 kartIndex) {
    KartModelMenuData *menu = g_GlobalCE;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentKartIndex = view->mKartIndex;
    s32 noKart = KART_MODEL_MENU_NONE;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (kartIndex == noKart) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mKartIndex = kartIndex;
        shownSlot->mKartIndex = noKart;
        return;
    }
    if (files->mLoadRequested == FALSE && currentKartIndex != kartIndex && kartIndex <= 0x25) {
        view->mKartIndex = kartIndex;
        g_GlobalCE->mKartRequested = 1;
    }
}

void AdvanceKartModelMenuBg0Offset(void) {
    KartModelMenuView *view = &g_GlobalCE->mView;
    switch (view->mBg0Direction) {
        case 0:
            view->mBg0Offset += 0x15;
            if (view->mBg0Offset > -0x2e) {
                view->mBg0Offset = -0x2e;
            }
            break;
        case 1:
            view->mBg0Offset -= 0x15;
            if (view->mBg0Offset < -0xfa) {
                view->mBg0Offset = -0xfa;
            }
            break;
    }
}

void StartKartModelMenuBg0Increase(void) {
    g_GlobalCE->mView.mBg0Direction = 0;
}

void StartKartModelMenuBg0Decrease(void) {
    g_GlobalCE->mView.mBg0Direction = 1;
}

void SetFrustumProjection(s32 mirrored) {
    s32 right;
    s32 unmirroredRight;
    s32 left;
    s32 bottom;
    s32 top;
    top = MUL_FIXED12_NO_ROUND(FX_Div(0x579, 0xf09), 0x200);
    bottom = -top;
    left = MUL_FIXED12_NO_ROUND(bottom, 0x1555);
    unmirroredRight = -left;
    right = unmirroredRight;
    if (mirrored != 0) {
        right = -unmirroredRight;
        left = unmirroredRight;
    }
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    G3i_FrustumW_(top, bottom, left, right, 0x200, 0x64000, 0x1000, 0, &g_GlobalG3.mProjMtx);
    g_GlobalG3.mFlag &= ~0x50;
    NNS_G3dGlbFlushP();
}

void SetupLightFrustumAndLookAt(s32 unusedBg0Offset, s32 yOffset) {
    Vec3 lightDirection;
    Vec3 camUp;
    Vec3 viewDirection;
    Vec3 referenceAxis;
    Vec3 target;
    NNS_G3dGlbFlushP();
    lightDirection = gKartModelMenuLightDirection;
    if ((s64) lightDirection.z * lightDirection.z +
            SQUARE_SUM2(lightDirection.x, lightDirection.y) >=
        0x10) {
        Vector3_MaybeNormalize(&lightDirection, &lightDirection);
    }
    NNS_G3dGlbLightVector(0, (s16) lightDirection.x, (s16) lightDirection.y, (s16) lightDirection.z);
    NNS_G3dGlbLightColor(
        0, (u16) (gKartModelMenuLightLevel | (gKartModelMenuLightLevel << 5) | (gKartModelMenuLightLevel << 10)));
    SetFrustumProjection(0);
    referenceAxis = gKartModelMenuReferenceAxis;
    target = gKartModelMenuLookAtTarget;
    target.y += yOffset;
    VecFx32_Subtract(&target, &gKartModelMenuCameraPosition, &viewDirection);
    VecFx32_CrossProduct(&referenceAxis, &viewDirection, &camUp);
    g_GlobalG3.mCamPos = gKartModelMenuCameraPosition;
    g_GlobalG3.mCamUp = camUp;
    g_GlobalG3.mCamTarget = target;
    G3i_LookAt_(&gKartModelMenuCameraPosition, &camUp, &target, 0, &g_GlobalG3.mCameraMtx);
    g_GlobalG3.mFlag &= ~0xe8;
    NNS_G3dGlbFlushP();
}

void DrawKartModelMenuSlot(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored) {
    Vec3 scale;
    MtxFx33 rotationMatrix;
    MtxFx33 tiltMatrix;
    MtxFx43 kartMatrix;
    Vec3 translation;
    Vec3 tireOffset;
    Vec3 tireScale;
    Vec3 *tireOffsets;
    s32 scaleValue;
    u16 tireIndex;

    g_GlobalG3.mPrmViewPort = VIEWPORT_WHOLE_SCREEN;
    translation.x = gKartModelMenuLookAtTarget.x;
    translation.y = gKartModelMenuLookAtTarget.y;
    translation.z = gKartModelMenuLookAtTarget.z;
    scaleValue = FX_MulFunc(gKartModelMenuScaleFactor, view->mScale);
    scale.x = scaleValue;
    scale.y = scaleValue;
    scale.z = scaleValue;
    MTX_RotY33__from_thumb(&rotationMatrix, FX_SinIdx(view->mYawAngle), FX_CosIdx(view->mYawAngle));
    MTX_RotX33__from_thumb(&tiltMatrix, SIN_OF_ANGLE((u16) (gKartModelMenuTiltAngleOffset + view->mDrawnTiltAngle)),
                COS_OF_ANGLE((u16) (gKartModelMenuTiltAngleOffset + view->mDrawnTiltAngle)));
    MTX_Concat33(&rotationMatrix, &tiltMatrix, &rotationMatrix);
    if (slot->mKartOffsetData != NULL) {
        MTX_Copy33To43_(&rotationMatrix, &kartMatrix);
        kartMatrix.mRows[3] = translation;
        MTX_ScaleApply43(&kartMatrix, &kartMatrix, scale.x, scale.y, scale.z);
    } else {
        MTX_Identity43_(&kartMatrix);
    }
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbSetBaseTrans(&translation);
    asm_MI_Copy36B(&tiltMatrix, &g_GlobalG3.mPrmBaseRot);
    g_GlobalG3.mFlag &= ~0xa4;
    NNS_G3dGlbFlushP();
    if (g_GlobalCE->mSelectModel != NULL) {
        NNS_G3dDraw(&g_GlobalCE->mSelectModel->mRenderObj);
    }
    asm_MI_Copy36B(&rotationMatrix, &g_GlobalG3.mPrmBaseRot);
    g_GlobalG3.mFlag &= ~0xa4;
    NNS_G3dGlbSetBaseTrans(&translation);
    NNS_G3dGlbFlushP();
    if (slot->mCharacterIndex != KART_MODEL_MENU_NONE && slot->mKartIndex != KART_MODEL_MENU_NONE) {
        SetFrustumProjection(mirrored);
        if (slot->mShadowModel != NULL) {
            if (mirrored != 0) {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 1;
            } else {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 0;
            }
            ((void (*)(ShadowModel *)) DrawShadowModel)(slot->mShadowModel);
        }
        if (slot->mKartNsbmd != NULL) {
            if (mirrored != 0) {
                SetNsbmdCullModeMirrored(slot->mKartNsbmd);
            } else {
                SetNsbmdCullModeUnmirrored(slot->mKartNsbmd);
            }
            NNS_G3dDraw(&slot->mKartNsbmd->mRenderObj);
        }
        if (slot->mTireNsbmd != NULL) {
            for (tireIndex = 0; tireIndex < 4; tireIndex++) {
                if (tireIndex < 2) {
                    scaleValue = slot->mKartOffsetData->mFirstTiresScale;
                    tireScale.x = MUL_FIXED12_NO_ROUND(scale.x, scaleValue);
                    tireScale.y = MUL_FIXED12_NO_ROUND(scale.y, scaleValue);
                    tireScale.z = MUL_FIXED12_NO_ROUND(scale.z, scaleValue);
                } else {
                    tireScale = scale;
                }
                if (tireIndex != 1 || slot->mKartOffsetData->mTireOffsets[0].x != 0) {
                    tireOffsets = &slot->mKartOffsetData->mTireOffsets[tireIndex];
                    tireOffset.x = tireOffsets->x >> 4;
                    tireOffset.y = tireOffsets->y >> 4;
                    tireOffset.z = tireOffsets->z >> 4;
                    MTX_MultVec43(&tireOffset, &kartMatrix, &translation);
                    NNS_G3dGlbSetBaseScale(&tireScale);
                    NNS_G3dGlbSetBaseTrans(&translation);
                    NNS_G3dGlbFlushP();
                    if (mirrored != 0) {
                        SetNsbmdCullModeMirrored(slot->mTireNsbmd);
                    } else {
                        SetNsbmdCullModeUnmirrored(slot->mTireNsbmd);
                    }
                    NNS_G3dDraw(&slot->mTireNsbmd->mRenderObj);
                }
            }
        }
        if (slot->mCharacterNsbmd != NULL) {
            MTX_MultVec43(&slot->mKartOffsetData->mCharacterOffsets[slot->mCharacterIndex], &kartMatrix, &translation);
            NNS_G3dGlbSetBaseTrans(&translation);
            NNS_G3dGlbFlushP();
            if (mirrored != 0) {
                SetNsbmdCullModeMirrored(slot->mCharacterNsbmd);
            } else {
                SetNsbmdCullModeUnmirrored(slot->mCharacterNsbmd);
            }
            NNS_G3dDraw(&slot->mCharacterNsbmd->mRenderObj);
        }
    }
}

#pragma thumb off

#pragma thumb on

void StructCESub_SomeFn_from_thumb(KartModelMenuSlot *slot) {
    if ((g_GlobalCE->mUseEmblemTex != FALSE) && (slot->mEmblemTex != NULL)) {
        NNS_G3dReleaseMdlTexEx(slot->mKartNsbmd->mResMdl, (const u32 *) g_str_emblem);
        NNS_G3dReleaseMdlPlttEx(slot->mKartNsbmd->mResMdl, (const u32 *) g_str_emblem_pl);
        NNS_G3dBindMdlTexEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, (const u32 *) g_str_emblem);
        NNS_G3dBindMdlPlttEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, (const u32 *) g_str_emblem_pl);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceKartModelMenu(s32 mirrorMode) {
    KartModelMenuView *view;
    KartModelMenuSlot *shownSlot;
    view = &g_GlobalCE->mView;
    g_GlobalCE->mMirrorMode = mirrorMode;
    QueueKartModelMenuLoad();
    AdvanceKartModelMenuBg0Offset();
    if (g_GlobalCE->mShownSlotIndex >= 0) {
        shownSlot = &g_GlobalCE->mSlots[g_GlobalCE->mShownSlotIndex];
        if (g_GlobalCE->mSpinStopped != 0 || g_GlobalCE->mSpinStopTimed != FALSE) {
            AdvanceAngleToward(&view->mSpinAngle, KART_MODEL_MENU_REST_YAW, gKartModelMenuSpinStep);
            if (g_GlobalCE->mSpinStopped == 0 && g_GlobalCE->mSpinStopTimed != FALSE) {
                g_GlobalCE->mSpinStopFrames++;
                if (g_GlobalCE->mSpinStopFrames > KART_MODEL_MENU_SPIN_STOP_FRAMES) {
                    g_GlobalCE->mSpinStopTimed = FALSE;
                }
            }
        } else {
            view->mSpinAngle += 0x64;
        }
        view->mYawAngle = mirrorMode != 0 ? (u16) -view->mSpinAngle : view->mSpinAngle;
        StructAM_SomeFn_MaybeMoveNextFrame(shownSlot->mCharacterAnimation);
        if (g_GlobalCE->mEmblemData != NULL && g_GlobalCE->mEmblemPalette != NULL &&
            g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(g_GlobalCE->mEmblemData, g_GlobalCE->mEmblemPalette);
        }
    }
    ClearKartModelMenuRequests();
}

void AdvanceShownSlotAndQueueEmblem(void) {
    s16 shownSlotIndex = g_GlobalCE->mShownSlotIndex;
    if (shownSlotIndex >= 0) {
        StructAM_SomeFn_MaybeMoveNextFrame(g_GlobalCE->mSlots[shownSlotIndex].mCharacterAnimation);
        if (g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(GetEmblemRecordBytes(), GetEmblemSBPalette());
        }
    }
}

void AdvanceKartModelMenuInput(void) {
    KartModelMenuView *view = &g_GlobalCE->mView;
    s32 value = 0;
    BOOL yawChanged;
    s32 changed;
    s32 characterIndex;
    u16 buttons;
    InputSlotIndex inputSlot;
    s32 scaleInputKind = 2;
    KartModelMenuFiles *files;

    files = &g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex];
    if (g_WorkerContext->mRunRequested == 0 && files->mLoadRequested == FALSE) {
        characterIndex = ~value;
        inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
        buttons = g_GlobalCYT[inputSlot].mPressedBits;
        if ((u16) (buttons & PAD_KEY_R) != 0) {
            changed = value;
            do {
                g_GlobalCE->mKartIndex++;
                if (g_GlobalCE->mKartIndex > KART_MODEL_MENU_LAST_KART_INDEX) {
                    g_GlobalCE->mKartIndex = value;
                }
                if (FindKartModelMenuCharacter(&characterIndex, g_GlobalCE->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(g_GlobalCE->mKartIndex);
                    changed = 1;
                    PlaySseqFromSarc(&gSharedSeqHandle, value, 0x1fd);
                }
            } while (changed == 0);
            g_GlobalCE->mKartListPos++;
            if (g_GlobalCE->mKartListPos >= g_GlobalCE->mKartListCount) {
                g_GlobalCE->mKartListPos = 0;
            }
        } else if ((u16) (buttons & PAD_KEY_L) != 0) {
            changed = value;
            do {
                g_GlobalCE->mKartIndex--;
                if (g_GlobalCE->mKartIndex < 0) {
                    g_GlobalCE->mKartIndex = KART_MODEL_MENU_LAST_KART_INDEX;
                }
                if (FindKartModelMenuCharacter(&characterIndex, g_GlobalCE->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(g_GlobalCE->mKartIndex);
                    changed = 1;
                    PlaySseqFromSarc(&gSharedSeqHandle, value, 0x1fe);
                }
            } while (changed == 0);
            g_GlobalCE->mKartListPos--;
            if (g_GlobalCE->mKartListPos < 0) {
                g_GlobalCE->mKartListPos = g_GlobalCE->mKartListCount - 1;
            }
        }
    }
    yawChanged = FALSE;
    changed = yawChanged;
    GetSndHandleSlot(2);
    inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    buttons = g_GlobalCYT[inputSlot].mBits;
    if ((u16) (buttons & PAD_KEY_RIGHT) != 0) {
        view->mYawAngle += 0x1c2;
        yawChanged = TRUE;
    } else if ((u16) (buttons & PAD_KEY_LEFT) != 0) {
        view->mYawAngle -= 0x1c2;
        yawChanged = TRUE;
    }
    inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    buttons = g_GlobalCYT[inputSlot].mBits;
    if ((u16) (buttons & PAD_KEY_DOWN) != 0) {
        view->mTiltAngle += 0x1c2;
        if (view->mTiltAngle > KART_MODEL_MENU_TILT_DOWN_MAX) {
            view->mTiltAngle = KART_MODEL_MENU_TILT_DOWN_MAX;
        } else {
            changed = 1;
        }
    } else if ((u16) (buttons & PAD_KEY_UP) != 0) {
        view->mTiltAngle -= 0x1c2;
        if (view->mTiltAngle < -KART_MODEL_MENU_TILT_UP_MAX) {
            view->mTiltAngle = -KART_MODEL_MENU_TILT_UP_MAX;
        } else {
            changed = 1;
        }
    }
    if (changed != 0 || yawChanged != FALSE) {
        value = 1;
    }
    GetSndHandleSlot(1);
    inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    buttons = g_GlobalCYT[inputSlot].mBits;
    if ((u16) (buttons & PAD_KEY_X) != 0) {
        view->mScale += 0x7b;
        if (view->mScale > gKartModelMenuMaxScale) {
            view->mScale = gKartModelMenuMaxScale;
        } else {
            scaleInputKind = 0;
        }
    } else {
        inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
        buttons = g_GlobalCYT[inputSlot].mBits;
        if ((u16) (buttons & PAD_KEY_B) != 0) {
            view->mScale -= 0x7b;
            if (view->mScale < KART_MODEL_MENU_SCALE_MIN) {
                view->mScale = KART_MODEL_MENU_SCALE_MIN;
            } else {
                scaleInputKind = 1;
            }
        }
    }
    view->mDrawnTiltAngle = view->mTiltAngle;
    SetKartModelMenuInputSeqs(scaleInputKind, value);
    QueueKartModelMenuLoad();
    ClearKartModelMenuRequests();
}

void DrawKartModelMenu(void) {
    KartModelMenuSlot *slot;
    KartModelMenuView *view;
    if (g_GlobalCE->mShownSlotIndex >= 0) {
        slot = &g_GlobalCE->mSlots[g_GlobalCE->mShownSlotIndex];
        view = &g_GlobalCE->mView;
        if (view->mCharacterIndex != KART_MODEL_MENU_NONE && view->mKartIndex != KART_MODEL_MENU_NONE) {
            SetupLightFrustumAndLookAt(view->mBg0Offset, gKartModelMenuLookAtYOffset);
            DrawKartModelMenuSlot(slot, &g_GlobalCE->mView, g_GlobalCE->mMirrorMode);
            NNS_G3dGeFlushBuffer();
        }
    }
}

void DrawKartModelMenuUnmirrored(void) {
    KartModelMenuSlot *slot;
    if (g_GlobalCE->mShownSlotIndex >= 0) {
        slot = &g_GlobalCE->mSlots[g_GlobalCE->mShownSlotIndex];
        SetupLightFrustumAndLookAt(0, gKartModelMenuLookAtYOffset);
        DrawKartModelMenuSlot(slot, &g_GlobalCE->mView, 0);
        NNS_G3dGeFlushBuffer();
    }
}

void CopySomeHeyhoPaletteRows_from_thumb(void) {
    u16 paletteIndex;
    for (paletteIndex = 0; paletteIndex < 8; paletteIndex++) {
        g_GlobalAD00->mHeyhoPaletteIndices[paletteIndex] = g_GlobalB488->mShuffledIndices[paletteIndex];
    }
}

void CopyDefaultHeyhoColorPalettes_from_thumb(void) {
    u32 kartIndex;
    if (g_GlobalAD00->mHeyhoPalettes != NULL) {
        CopySomeHeyhoPaletteRows_from_thumb();
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            if (g_GlobalAD00->mKartModelsEntries[kartIndex].mCharacterIndex == CHARACTER_HEYHO) {
                UploadHeyhoPalette(kartIndex, &g_GlobalAD00->mKartModelsEntries[kartIndex], GetHeyhoColorPaletteDataForRacer_from_thumb(kartIndex));
            }
        }
    }
}

void UploadHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette) {
    NNSG3dResMdl *mdl;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    s32 materialIndex;
    s32 paletteBase;
    mdl = kartModelsEntry->mModels[0]->mResMdl;
    Arm_FlushRange(palette, 0x20);
    if (DetermineIsP_from_thumb(kartIndex) != 0) {
        materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) g_str_P_main);
    } else {
        materialIndex = Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) g_str_E_main);
    }
    matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
    paletteBase = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex))->mTexPlttBase << 4;
    GX_BeginLoadTexPltt();
    SomeDmaCopy_0(palette, paletteBase, 0x20);
    GX_EndLoadTexPltt();
}

HeyhoPalette *GetHeyhoColorPaletteDataForRacer_from_thumb(int kartIndex) {
    HeyhoPalette *palette = NULL;
    if (g_GlobalAD00->mHeyhoPalettes != NULL) {
        palette = g_GlobalAD00->mHeyhoPalettes + g_GlobalAD00->mHeyhoPaletteIndices[kartIndex];
    }
    return palette;
}

void StartKartModelMenuTimedSpinStop(void) {
    g_GlobalCE->mSpinStopTimed = TRUE;
    g_GlobalCE->mSpinStopFrames = 0;
}

#pragma thumb off

#pragma thumb on

void SetKartModelMenuSpinStopped(u32 flag) {
    g_GlobalCE->mSpinStopped = flag;
}

// Moves *a toward b by a share of the distance plus 100; keeps the old value when the step would reach b.
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor) {
    u16 oldAngle;
    int change;
    int difference;
    oldAngle = *angle;
    difference = targetAngle - oldAngle;
    if (difference < 0) {
        difference = 0xffff - difference;
    }
    change = FX_MulFunc(difference, easeFactor);
    *angle = *angle + change;
    if (((*angle + 100) - targetAngle) < 0) {
        *angle = *angle + 100;
        return;
    }
    *angle = oldAngle;
}

#pragma thumb off

#pragma thumb on

Nclr *GetEmblemPalette_from_thumb(void) {
    return g_EmblemPalettte;
}

#pragma thumb off

#pragma thumb on

// Bytes of the exp heap that holds the kart model menu files.
#define KART_MODEL_MENU_HEAP_SIZE 0xf000

void CreateCESex_from_thumb(void *heap, KartModelMenuFiles *files) {
    void *heapMemory;
    struct NNSiFndHeapHead *expHeap;
    heapMemory = Mem_AllocateHeap(heap, KART_MODEL_MENU_HEAP_SIZE);
    expHeap = Mem_Exp_Create(heapMemory, KART_MODEL_MENU_HEAP_SIZE, 0);
    files->mHeap = expHeap;
    files->mHeapMemory = heapMemory;
    files->mEmblemNsbtxFile = NULL;
    files->mCharacterNsbtxFile = files->mEmblemNsbtxFile;
    files->mCharacterNsbmdFile = files->mCharacterNsbtxFile;
    files->mKartNsbtxFile = NULL;
    files->mKartNsbmdFile = files->mKartNsbtxFile;
    files->mCharacterNsbcaFile = files->mKartNsbmdFile;
    files->mKartShadowNsbmdFile = NULL;
    files->mTireNsbtxFile = files->mKartShadowNsbmdFile;
    files->mTireNsbmdFile = files->mTireNsbtxFile;
    files->mLoadRequested = FALSE;
    files->mLoadStep = 0;
}

#pragma thumb off

#pragma thumb on

void LoadKartAndCharacterFiles(void) {
    KartModelMenuFiles *files;
    s32 characterIndex;
    KartModelMenuFiles *loadFiles;
    s32 kartIndex;
    s32 loadSlotIndex;
    char *tireName;

    files = g_GlobalCE->mFiles;
    loadSlotIndex = g_GlobalCE->mLoadSlotIndex;
    loadFiles = &files[loadSlotIndex];
    characterIndex = g_GlobalCE->mLoadSlot->mCharacterIndex;
    kartIndex = g_GlobalCE->mLoadSlot->mKartIndex;
    loadFiles->mLoadStep = 0;
    Mem_Exp_Finalize(loadFiles->mHeap);
    loadFiles->mHeap = Mem_Exp_Create(loadFiles->mHeapMemory, 0xf000, 0);
    if (characterIndex != -1 && loadFiles->mCharacterNsbmdFile != NULL) {
        MaybeDisposeCommonHeaderFileData(loadFiles->mCharacterNsbmdFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mCharacterNsbtxFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mEmblemNsbtxFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mKartNsbmdFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mKartNsbtxFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mTireNsbmdFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mTireNsbtxFile);
        MaybeDisposeCommonHeaderFileData(loadFiles->mKartShadowNsbmdFile);
    }
    tireName = g_GlobalCE->mKartOffsetTable[kartIndex].mTireName;
    ReadFileFromMountManagerHandle_from_thumb(FormatCharacterEmblemNsbmdPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbmdFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatCharacterEmblemNsbtxPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbtxFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatCharacterEmblemNsbcaPath(characterIndex, 2), loadFiles->mHeap, &loadFiles->mCharacterNsbcaFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatEmblemNsbtx(characterIndex), loadFiles->mHeap, (void **) &loadFiles->mEmblemNsbtxFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatCharacterKartNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbmdFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatCharacterKartNsbtxPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbtxFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatKartShadowNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartShadowNsbmdFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatKartTireNsbmdPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbmdFile);
    ReadFileFromMountManagerHandle_from_thumb(FormatKartTireNsbtxPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbtxFile);
}

// Builds the slot being loaded over three calls, then shows it and loads into the other slot next.
void AdvanceKartModelMenuLoad(void) {
    KartModelMenuFiles *loadFiles;
    KartModelMenuSlot *loadSlot;
    KartModelMenuSlot *shownSlot;
    ModelAnimation *animation;

    G3X_SetHOffset(g_GlobalCE->mView.mBg0Offset);
    if (g_WorkerContext->mRunRequested == 0) {
        loadFiles = &g_GlobalCE->mFiles[g_GlobalCE->mLoadSlotIndex];
        if (loadFiles->mLoadRequested != FALSE) {
            loadSlot = g_GlobalCE->mLoadSlot;
            if (loadFiles->mLoadStep == 0) {
                MaybeLoadWinModelTextureAnimationHelper_from_thumb(loadFiles->mHeap, loadSlot->mCharacterNsbmd, loadSlot->mCharacterAnimation,
                                             loadFiles->mCharacterNsbmdFile, loadFiles->mCharacterNsbtxFile,
                                             loadFiles->mCharacterNsbcaFile);
                loadFiles->mLoadStep++;
                return;
            }
            if (loadFiles->mLoadStep == 1) {
                LoadKartModelMenuEmblemTexData(loadFiles->mEmblemNsbtxFile);
                g_GlobalCE->mLoadSlot->mEmblemTex = g_GlobalCE->mEmblemTex;
                StructAD00Sh_SomeFn_1_from_thumb(loadSlot->mShadowModel, loadFiles->mKartShadowNsbmdFile);
                StructML_LoadModel3Mat_from_thumb(loadSlot->mTireNsbmd, loadFiles->mTireNsbmdFile, loadFiles->mTireNsbtxFile);
                loadFiles->mLoadStep++;
                return;
            }
            StructML_SomeFn_6_from_thumb(loadSlot->mKartNsbmd, loadFiles->mKartNsbmdFile, loadFiles->mKartNsbtxFile);
            StructCESub_SomeFn_from_thumb(g_GlobalCE->mLoadSlot);
            LoadKartBodyPalette_from_thumb(loadSlot->mKartNsbmd, loadSlot->mKartIndex, g_GlobalCE->mKartAPalette);
            StructAD00Sub_SomeFnPaletteSwapRelated_from_thumb((struct KartModelsEntry *) loadSlot, 1);
            loadFiles->mLoadRequested = FALSE;
            loadFiles->mLoadStep = 0;
            if (g_GlobalCE->mShownSlotIndex >= 0) {
                shownSlot = &g_GlobalCE->mSlots[g_GlobalCE->mShownSlotIndex];
                if (loadSlot->mCharacterIndex == shownSlot->mCharacterIndex) {
                    animation = loadSlot->mCharacterAnimation;
                    animation->mHead.mFrameIndex = shownSlot->mCharacterAnimation->mHead.mFrameIndex;
                    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
                }
            }
            g_GlobalCE->mShownSlotIndex = g_GlobalCE->mLoadSlotIndex;
            g_GlobalCE->mLoadSlotIndex = g_GlobalCE->mLoadSlotIndex == 0 ? 1 : 0;
            g_GlobalCE->mLoadSlot = &g_GlobalCE->mSlots[g_GlobalCE->mLoadSlotIndex];
        }
    }
}

#pragma thumb off

#pragma thumb on

void InitLnkVramManagers(void *heap) {
    u32 texWorkSize;
    u32 plttWorkSize;
    NNSiGfdLnkVramBlock *texWork;
    NNSiGfdLnkVramBlock *plttWork;
    texWorkSize = ComputeSomeAllocSize_0(0x20);
    plttWorkSize = ComputeSomeAllocSize_1(0x20);
    texWork = Mem_AllocateHeap(heap, texWorkSize);
    plttWork = Mem_AllocateHeap(heap, plttWorkSize);
    NNS_GfdInitLnkTexVramManager(0x00040000u, 0x00020000u, texWork, texWorkSize, 1);
    NNS_GfdInitLnkPlttVramManager(0x00010000u, plttWork, plttWorkSize, 1);
}

#pragma thumb off

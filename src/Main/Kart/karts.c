#include "Main/Kart/karts.h"
#include "Main/Kart/character_animation.h"
#include "code_02012b30.h" // NNSG3dResFileHeader

#include "Main/System/heap.h"
#include "gfdi_LinkedListVramMan_Common.h"
#include "gfd_LinkedListTexVramMan.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "code_020172d0.h"
#include "Main/System/archive_slots.h"
#include "code_020176c0.h"
#include "g3x.h"
#include "code_02013740.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Kart/kart_model_path.h"
#include "Main/Kart/shadow_model.h"
#include "code_0212d214.h"
#include "Main/System/backup_net_camera_work.h"
#include "gx.h"
#include "Main/Kart/kart_model_menu.h"
#include "Main/Item/item_in_use.h"
#include "code_0200eddc.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/emblem_cursor.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "os_thread.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/System/input_slots.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "player.h"
#include "code_0212df7c.h"
#include "gx_load3d.h"
#include "code_0200fe74.h"
#include "code_02010c84.h"
#include "gfd_VramTransferManager.h"
#include "fx_mtx43.h"
#include "code_0214a748.h"
#include "code_0214d018.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "expheap.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race.h"
#include "gecom.h"
#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "data_02170000.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_appear.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/kart_killer_render.h"
#include "Main/Kart/kart_killer_animation_reset.h"
#include "Main/Graphics/emitters.h"
#include "Main/Kart/kart_ai.h"
#include "code_02134398.h"
#include "code_02133048.h"
#include "res_struct_accessor.h"
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
#include "Main/Race/followed_kart_or.h"
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
const char gHeyhoPMainMaterialName[16] = "P_main";
const char gEmblemPaletteName[16] = "emblem_pl";
const char gSpecialKartBodyMaterialName[16] = "kart_body";
const char gKartEmblemMaterialName[16] = "kart_emblem";
const char gCharacterBPMainMaterialName[16] = "P_main";
const char gHeyhoEMainMaterialName[16] = "E_main";
const char gCharacterBPFaceMaterialName[16] = "P_face";
const char gEmblemTextureName[16] = "emblem";
const char gCharacterBEMainMaterialName[16] = "E_main";
const char gCharacterBEFaceMaterialName[16] = "E_face";
const char gKartAPaletteMaterialName[16] = "kart_body";
const char gTireModelMaterialName[16] = "kart_tire";
const char gKartTireMaterialName[16] = "kart_tire";
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

u16 gKartCount;
u16 gKillerItemKartIndex;
s32 gKartSpeedLimitReciprocal;
struct Kart *gKarts;
s32 gKartForwardSpeedRatio;
struct EntryKartCounters *gEntryKartCounters;
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

void InitKarts(u32 kartCount) {
    u16 kartIndex;
    void *heap = GetHeap(GetCurrentHeapCall());
    EntryKartCounters *entryKartCounters;
    gKarts = HeapAlloc(heap, kartCount * 0x5a8);
    gKartCount = kartCount;
    entryKartCounters = HeapAlloc(heap, sizeof(*entryKartCounters));
    gEntryKartCounters = entryKartCounters;
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
    gNearPlayerRankKartCount = gRaceSetup->mMode == MODE_BATTLE ? 1 : 2;
    InitKartMapObjectResponses();
    RegisterKartAiCallbacks();
    InitKartEffects(kartCount);
    gMissionRunEndShapesPresent = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gCourseMap->mMissionEndShapeCount != 0) {
            gMissionRunEndShapesPresent = 1;
        }
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        gKarts[kartIndex].mIndex = kartIndex;
        gKarts[kartIndex].mEntryIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mIndex;
        InitKart(&gKarts[kartIndex], gKartDefaultSlotFunctions);
    }
    gKartZoneMask = 0;
}

void UpdateKarts(void) {
    s32 kartIndex;
    Kart *kart = gKarts;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        UpdateKartPrevValuesAndClearFlags(kart);
        kart++;
    }
    SetKartNearPlayerRankBits();
    kart = gKarts;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        kart->mSlotFunctions[3](kart);
        kart++;
    }
    kart = gKarts;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        kart->mSlotFunctions[4](kart);
        kart++;
    }
}

void UpdateKartSoundDistancesSquared(void) {
    Kart *kart = gKarts;
    s16 kartIndex;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        kart->mSlotFunctions[2](kart);
        kart++;
    }
}

void DrawKarts(void) {
    s32 drawOrderIndex = 0;
    u16 *kartIndices = GetKartIndicesByDistance();
    (gKarts[gRaceSetup->mEntryIndex].mKartModelsEntry)->mFarFromCamera = TRUE;
    for (; drawOrderIndex < gKartCount; drawOrderIndex++) {
        DrawKart(&gKarts[*kartIndices]);
        kartIndices++;
    }
}

void ReleaseKartsAndClear(void) {
    s32 kartIndex;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        CallKartReleaseFunction(&gKarts[kartIndex]);
    }
    gKarts = NULL;
}

Kart *GetKart(s32 kartIndex) {
    return &gKarts[kartIndex];
}

void GetKartPos(Vec3 *pos, s32 kartIndex) {
    *pos = *gKarts[kartIndex].mPosSource;
}

void GetKartPosFromPosSourceCopy(Vec3 *pos, u8 kartIndex) {
    *pos = *gKarts[kartIndex].mPosSourceCopy;
}

void GetKartPrevPos(Vec3 *pos, s32 kartIndex) {
    *pos = gKarts[kartIndex].mPrevPos;
}

void GetKartScale(Vec3 *scale, s32 kartIndex) {
    *scale = gKarts[kartIndex].mScale;
}

u32 GetKartItemEffect(u32 kartIndex) {
    return gKarts[kartIndex].mItemEffect;
}

u16 GetKartHeadingAngle(s32 kartIndex) {
    return gKarts[kartIndex].mHeadingAngle;
}

u32 IsMissionRunWithEndShapes(void) {
    return gMissionRunEndShapesPresent;
}

BOOL IsKartRemovedWrapper(u16 kartIndex) {
    return IsKartRemoved(&gKarts[kartIndex]);
}

void StartKartRaceEndWrapper(u16 kartIndex) {
    StartKartRaceEnd(&gKarts[kartIndex]);
}

BOOL IsKartOnBoostSurface(s32 kartIndex) {
    return (gKarts[kartIndex].mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) != 0;
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
    if (kartIndex == gRaceSetup->mEntryIndex) {
        gEntryKartCounters->mItemHitCount++;
    }
}

void IncrementEntryKartSurfaceCount(Kart *kart) {
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        return;
    }
    if (!(kart->mDriveFlags & KART_DRIVE_ITEM_BOOST)) {
        gEntryKartCounters->mSurfaceCount++;
    }
}

EntryKartCounters *GetEntryKartCounters(void) {
    return gEntryKartCounters;
}

u32 GetKartCourseHitAttributeBitWrapper(int kartIndex) {
    return GetKartCourseHitAttributeBit(&gKarts[kartIndex]);
}

void SetKartModelsFogEnable(s32 fogEnableFlag) {
    s32 kartIndex;
    Kart *kart = gKarts;
    KartModelsEntry *entry;
    for (kartIndex = 0; kartIndex < gKartCount; kartIndex++) {
        entry = kart->mKartModelsEntry;
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[1]->mResMdl, fogEnableFlag);
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[0]->mResMdl, fogEnableFlag);
        if (entry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[2]->mResMdl, fogEnableFlag);
        }
        kart++;
    }
}

BOOL IsKartInRespawnWait(s32 kartIndex) {
    return (gKarts[kartIndex].mDriveFlags & KART_DRIVE_RESPAWN_WAIT) != 0 ? 1 : 0;
}

BOOL IsEntryKartNotNormalOrScaleTableBit(void) {
    Kart *kart = &gKarts[gRaceSetup->mEntryIndex];
    if (kart->mState != KART_STATE_NORMAL || (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsEntryKartInContact(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) !=
                   0
               ? 1
               : 0;
}

BOOL IsEntryKartRespawnFalling(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mDriveFlags & KART_DRIVE_RESPAWN_FALL) != 0 ? 1 : 0;
}

void SetKartNearPlayerRankBits(void) {
    s32 kartIndices[3];
    u32 kartRank = GetKartRank((u16) gRaceSetup->mEntryIndex);
    u16 nearSlotIndex;
    u16 awardKartIndex;
    s32 kartIndex;
    Kart *kart;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        for (awardKartIndex = 0; awardKartIndex < 3; awardKartIndex++) {
            gKarts[awardKartIndex].mEffectFlags |= KART_EFFECT_NEAR_PLAYER_RANK;
        }
        return;
    }
    kartIndices[0] = gRaceSetup->mEntryIndex;
    if (kartRank == 1) {
        kartIndices[1] = GetKartIndexAtRank(2);
        if (kartIndices[1] >= 0) {
            if ((gKarts[kartIndices[1]].mKartModelsEntry)->mFarFromCamera != FALSE) {
                kartIndices[1] = -1;
            }
        }
    } else {
        kartIndices[1] = GetKartIndexAtRank((u16) (kartRank - 1));
        if (kartIndices[1] >= 0) {
            if ((gKarts[kartIndices[1]].mKartModelsEntry)->mFarFromCamera != FALSE) {
                kartIndices[1] = -1;
            }
        }
        if (kartRank < gRaceSetup->mKartCount) {
            kartIndex = GetKartIndexAtRank((u16) (kartRank + 1));
            if (kartIndex >= 0) {
                kart = &gKarts[kartIndex];
                kart->mEffectFlags |= KART_EFFECT_ONE_RANK_BEHIND_PLAYER;
            }
        }
    }
    for (nearSlotIndex = 0; nearSlotIndex < gNearPlayerRankKartCount; nearSlotIndex++) {
        kartIndex = kartIndices[nearSlotIndex];
        if (kartIndex >= 0) {
            kart = &gKarts[kartIndex];
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
    s32 mode = gRaceSetup->mMode;
    if (mode == MODE_MISSION_RUN) {
        Kart *kart = &gKarts[gRaceSetup->mEntryIndex];
        if (kart->mState != KART_STATE_NORMAL ||
            (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT | KART_DRIVE_RESPAWN_LANDING)) != 0 ||
            (kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0 ||
            (mode != MODE_MISSION_RUN ? 0 : IsAnyBalloonUnparked()) != 0) {
            result = FALSE;
        }
    }
    return result;
}

void SetKartModelMaterialColors(NNSG3dResMdl *mdl, u32 colorSet) {
    u32 diffColor;
    u32 ambColor;
    u32 specColor;
    u32 emiColor;
    switch (colorSet) {
        case KART_MODEL_COLORS_COURSE: {
            u16 *courseColors = gKartModels->mCourseColors;
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
    NNS_G3dMdlSetMdlDiffAll(mdl, diffColor);
    NNS_G3dMdlSetMdlAmbAll(mdl, ambColor);
    NNS_G3dMdlSetMdlSpecAll(mdl, specColor);
    NNS_G3dMdlSetMdlEmiAll(mdl, emiColor);
}

u16 GetKartCourseDiffColor(void) {
    return gKartModels->mCourseColors[0];
}

u16 GetKartCourseEmiColor(void) {
    return gKartModels->mCourseColors[3];
}

u16 GetKartCourseAmbColor(void) {
    return gKartModels->mCourseColors[1];
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
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, blend->mDiffColor);
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, blend->mDiffColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, blend->mDiffColor);
        }
        blend->mEmiColor = (s16) (blend->mEmiStartR + MUL_FIXED12_ROUNDED(blend->mEmiDeltaR, blend->mBlendProgress)) +
                           ((s16) (blend->mEmiStartG + MUL_FIXED12_ROUNDED(blend->mEmiDeltaG, blend->mBlendProgress))
                            << KART_MODEL_COLOR_BLEND_GREEN_SHIFT) +
                           ((s16) (blend->mEmiStartB + MUL_FIXED12_ROUNDED(blend->mEmiDeltaB, blend->mBlendProgress))
                            << KART_MODEL_COLOR_BLEND_BLUE_SHIFT);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, blend->mEmiColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, blend->mEmiColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, blend->mEmiColor);
        }
        {
            s16 ambientRed = blend->mAmbStartR + MUL_FIXED12_ROUNDED(blend->mAmbDeltaR, blend->mBlendProgress);
            s16 ambientGreen = blend->mAmbStartG + MUL_FIXED12_ROUNDED(blend->mAmbDeltaG, blend->mBlendProgress);
            s16 ambientBlue = blend->mAmbStartB + MUL_FIXED12_ROUNDED(blend->mAmbDeltaB, blend->mBlendProgress);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, blend->mAmbColor);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, blend->mAmbColor);
            if (kartModelsEntry->mModels[2] != NULL) {
                NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, blend->mAmbColor);
            }
            blend->mAmbColor = ambientRed + (ambientGreen << KART_MODEL_COLOR_BLEND_GREEN_SHIFT) +
                               (ambientBlue << KART_MODEL_COLOR_BLEND_BLUE_SHIFT);
        }
    } else {
        finished = TRUE;
    }
    return finished;
}

void SetKartModelsEntryCourseColors(struct KartModelsEntry *kartModelsEntry) {
    u16 *courseColors = gKartModels->mCourseColors;
    u32 diffColor;
    u32 emiColor;
    u32 ambColor;

    diffColor = courseColors[0];
    emiColor = courseColors[3];
    ambColor = courseColors[1];
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, ambColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, ambColor);
    if (kartModelsEntry->mModels[2] != NULL) {
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, diffColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, emiColor);
        NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, ambColor);
    }
}

KartModelsEntry *GetKartModelsEntry(u32 kartIndex) {
    return &gKartModels->mKartModelsEntries[kartIndex];
}

void *GetKartModelResMdl(u16 kartIndex) {
    return gKartModels->mKartModelsEntries[kartIndex].mModels[1]->mResMdl;
}

// Shows (b non-zero) or hides the tire material of the kart model.
void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible) {
    NNS_G3dMdlSetMdlAlpha(kartModelsEntry->mModels[1]->mResMdl, gKartModels->mKartTireMaterialIndex,
                          visible != 0 ? 0x1f : 0);
}

void *GetKillerItem(void) {
    return &gKartModels->mKillerItem;
}

void *GetKillerItemS(void) {
    return &gKartModels->mKillerItemS;
}

void *GetKillerItemNsbca(void) {
    return &gKartModels->mKillerItemNsbca;
}

u32 GetKartVariant(u16 kartIndex) {
    return gKartModels->mKartModelsEntries[kartIndex].mVariant;
}

#pragma thumb on
void InitKartModelsEntry(void *entry) {
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
    InitCharacterAnimationState(fieldValue);
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

void ResetKartKillerAnimationLooping(KartModelsEntry *kartModelsEntry) {
    ResetModelAnimationLooping(&kartModelsEntry->mKillerItemAnimation,
                               GetModelAnimationFrameCountFixed(&gKartModels->mKillerItemNsbca));
}

#pragma thumb off

#pragma thumb on
void InitCharacterAnimationState(u32 animationStateAddress) {
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
BOOL IsCharacterPNameUsed(s32 kartIndex) {
    BOOL pNameUsed = TRUE;
    s32 isEntryFollowedMissionRunAwardOrStaffRoll = pNameUsed;
    s32 isEntryFollowedOrMissionRun = pNameUsed;
    s32 isEntryOrFollowedKart = pNameUsed;
    if (kartIndex != gRaceSetup->mEntryIndex && kartIndex != gRaceSetup->mFollowedKartIndex) {
        isEntryOrFollowedKart = 0;
    }
    if (isEntryOrFollowedKart == 0 && gRaceSetup->mMode != MODE_MISSION_RUN) {
        isEntryFollowedOrMissionRun = 0;
    }
    if (isEntryFollowedOrMissionRun == 0 && IsRaceAwardOrStaffRoll() == 0) {
        isEntryFollowedMissionRunAwardOrStaffRoll = 0;
    }
    if (isEntryFollowedMissionRunAwardOrStaffRoll == 0 && gRaceSetup->mMode != MODE_TIME_ATTACK) {
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
void SetKartModelsEntryVariant(KartModelsEntry *kartModelsEntry, int kartIndex) {
    u16 variant;
    variant = kartIndex % 3;
    kartModelsEntry->mVariant = variant;
}

#pragma thumb off

#pragma thumb on

void InitKartModels(void *heap, u32 kartCount) {
    u8 *kartOffsetFile;
    u16 kartIndex;
    KartModelsEntry *entry;
    KartModelsEntry *entries;
    kartOffsetFile = FindKartModelFile("kartoffsetdata.bin");
    SetKartModelPathPrefix(0);
    gKartModelMenu = NULL;
    gKartModels = HeapAlloc(heap, sizeof(*gKartModels));
    gKartModels->mKartModelsEntries = HeapAlloc(heap, kartCount * 0xb4);
    gKartModels->mCourseColors = GetKartModelFile("kartcrsmat.bin");
    gKartModels->mCourseColors = gKartModels->mCourseColors + (gRaceSetup->mCourseId << 2) - 4;
    gKartModels->mKartAPalette = LoadKartAPaletteFromKartModelFile();
    gKartModels->mHeyhoPalettes = NULL;
    gKartModels->mPFaceanimNsbtpFile = GetKartModelFile((const char *) BuildPFaceanimNsbtpPath());
    gKartModels->mKartCount = kartCount;
    gKartModels->mKartTireMaterialIndex = 0;
    CreateKartPhysicalParamTable(heap, kartCount);
    SetKartAiParamRow();
    CreateKillerItem(heap);
    for (kartIndex = 0; kartIndex < gKartModels->mKartCount; kartIndex++) {
        entries = gKartModels->mKartModelsEntries;
        entry = &entries[kartIndex];
        InitKartModelsEntry(entry);
        entry->mRegion = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mRegion;
        ResetKartKillerAnimationLooping(entry);
        entries[kartIndex].mCharacterIndex = gRaceSetup->mCurrentEntries[kartIndex].mCharacterIndex;
        entry->mKartIndex = gRaceSetup->mCurrentEntries[kartIndex].mKartIndex;
        SetKartModelsEntryVariant(entry, entry->mKartIndex);
        entry->mKartOffsetData = HeapAlloc(heap, sizeof(*entry->mKartOffsetData));
        MI_CpuCopy8(kartOffsetFile + entry->mKartIndex * sizeof(*entry->mKartOffsetData), entry->mKartOffsetData,
                    sizeof(*entry->mKartOffsetData));
        CopyKartPhysicalParams(kartIndex, entry->mKartIndex, entries[kartIndex].mCharacterIndex);
    }
    CreateKartModelsEntryModels(heap, 1);
    ReplaceKm1ArchiveWithKm2();
    CreateKartModelsEntryModels(heap, 0);
    for (kartIndex = 0; kartIndex < gKartModels->mKartCount; kartIndex++) {
        entry = &gKartModels->mKartModelsEntries[kartIndex];
        UploadKartModelsEntryPalettes(entry, IsCharacterPNameUsed(kartIndex));
    }
    {
        Nclr *nclr;
        LoadNclrData(&nclr, GetKartModelFile("/character/heyho/HH_color.NCLR"));
        gKartModels->mHeyhoPalettes = (HeyhoPalette *) nclr->mData;
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
    if (kartIndex < gKartModels->mKartCount) {
        entryGate = (firstPass == 0) ? 1 : kartIndex;
        do {
            entry = &gKartModels->mKartModelsEntries[kartIndex];
            pNameUsed = IsCharacterPNameUsed(kartIndex);
            if ((u16) entry->mKartIndex % 3 == 0) {
                isVariantZero = TRUE;
            } else {
                isVariantZero = FALSE;
            }
            skipKart = (isVariantZero != FALSE && entryGate != 0) ? TRUE : FALSE;
            if (entry->mCharacterIndex >= characterRangeStart && entry->mCharacterIndex < characterRangeEnd) {
                CreateCharacter(entry, heap, pNameUsed);
            }
            if (skipKart == FALSE) {
                if ((isVariantZero != FALSE && firstPass != 0) ||
                    (entry->mKartIndex >= kartRangeStart && entry->mKartIndex < kartRangeEnd)) {
                    CreateKart(entry, heap, pNameUsed);
                }
            }
            if (firstPass != 0) {
                if (pNameUsed != 0) {
                    tireIndex = 0;
                    entry->mTireTranslations = HeapAlloc(heap, sizeof(KartTireTranslations));
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
                    CreateTire(entry, heap);
                }
                CreateKartShadow(entry, heap);
            }
            kartIndex++;
        } while (kartIndex < gKartModels->mKartCount);
    }
}

void CreateCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 animationIndex;
    u16 characterIndex;
    BOOL hasFirstAnimation;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    void *animationFile;
    characterIndex = kartModelsEntry->mCharacterIndex;
    nsbmdFile = GetKartModelFile(BuildCharacterNsbmdPath(characterIndex, pNameUsed));
    nsbtxFile = FindKartModelFile(BuildCharacterNsbtxPath(characterIndex, pNameUsed));
    kartModelsEntry->mModels[0] = HeapAlloc(heap, sizeof(*kartModelsEntry->mModels[0]));
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[0], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[0], 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_COURSE);
    if (pNameUsed != 0) {
        animationIndex = 0;
        hasFirstAnimation = FALSE;
        kartModelsEntry->mCharacterAnimation = HeapAlloc(heap, sizeof(*kartModelsEntry->mCharacterAnimation));
        InitModelAnimation(0, kartModelsEntry->mCharacterAnimation, kartModelsEntry->mModels[0], 4, heap, NULL);
        do {
            animationFile = GetKartModelFile(BuildCharacterNsbcaPath(characterIndex, animationIndex));
            if (animationFile != NULL) {
                void *jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
                InitModelAnimationEntry(kartModelsEntry->mCharacterAnimation, animationIndex, jointAnimation,
                                        GetCharacterAnimationLoopFlag(animationIndex), heap);
                if (animationIndex == 0) {
                    hasFirstAnimation = TRUE;
                }
            }
            animationIndex++;
        } while (animationIndex < 4);
        if (hasFirstAnimation != FALSE) {
            SetModelAnimation(kartModelsEntry->mCharacterAnimation, 0);
            kartModelsEntry->mAnimationState.mMiddleFrame =
                (GetModelAnimationFrameCountFixed(kartModelsEntry->mCharacterAnimation) - 0x1000) / 2;
            kartModelsEntry->mAnimationState.mMiddleFrameReciprocal =
                FX_Div(0x1000, kartModelsEntry->mAnimationState.mMiddleFrame);
        } else {
            kartModelsEntry->mCharacterAnimation->mAnmObjCount = 0;
        }
    }
    kartModelsEntry->mFaceAnimation = HeapAlloc(heap, sizeof(*kartModelsEntry->mFaceAnimation));
    InitModelAnimation(2, kartModelsEntry->mFaceAnimation, kartModelsEntry->mModels[0], 1, heap, NULL);
    InitModelAnimationEntries(kartModelsEntry->mFaceAnimation, gKartModels->mPFaceanimNsbtpFile, heap);
    SetModelAnimation(kartModelsEntry->mFaceAnimation, 0);
}

void CreateKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    s32 tireMaterialIndex;
    nsbmdFile = GetKartModelFile(BuildKartNsbmdPath(kartIndex));
    nsbtxFile = FindKartModelFile(BuildKartNsbtxPath(kartIndex));
    kartModelsEntry->mModels[1] = HeapAlloc(heap, sizeof(*kartModelsEntry->mModels[1]));
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[1], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[1], 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_COURSE);
    if (pNameUsed != 0) {
        tireMaterialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                       (const u32 *) gKartTireMaterialName);
        NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
        gKartModels->mKartTireMaterialIndex = tireMaterialIndex;
    }
    UploadKartAPaletteSlice(kartModelsEntry->mModels[1], kartModelsEntry->mKartIndex, gKartModels->mKartAPalette);
}

u16 *LoadKartAPaletteFromKartModelFile(void) {
    Nclr *nclr;
    LoadNclrData(&nclr, GetKartModelFile("/kart/palette/kart_a.NCLR"));
    return nclr->mData;
}

u16 *LoadKartAPaletteFromKartModelMenu(void *heap) {
    void *file;
    Nclr *nclr;
    LoadKartModelMenuFile(heap, "kart/palette/kart_a.NCLR", &file);
    LoadNclrData(&nclr, file);
    return nclr->mData;
}

void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette) {
    NNSG3dResMdl *mdl;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    u8 *paletteSlice;
    s32 materialIndex;
    u32 paletteBase;
    if (kartIndex % 3 == 0) {
        mdl = nsbmd->mResMdl;
        paletteSlice = (u8 *) kartAPalette + kartIndex / 3 * 0x20;
        DC_FlushRange(paletteSlice, 0x10);
        materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gKartAPaletteMaterialName);
        matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
        paletteBase = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex))->mTexPlttBase
                      << 4;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(paletteSlice, paletteBase, 0x10);
        GX_EndLoadTexPltt();
    }
}

void UploadKartModelsEntryPalettes(KartModelsEntry *kartModelsEntry, s32 pNameUsed) {
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
            materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                       (const u32 *) gSpecialKartBodyMaterialName);
            matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
            entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
            gSpecialKartBodyMaterial = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex));
            paletteBase = gSpecialKartBodyMaterial->mTexPlttBase << 4;
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(palette, paletteBase, 0x20);
            GX_EndLoadTexPltt();
        }
        if (kartModelsEntry->mCharacterIndex == CHARACTER_ROBO) {
            mdl = kartModelsEntry->mModels[0]->mResMdl;
            if (pNameUsed != 0) {
                materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                           (const u32 *) gCharacterBPMainMaterialName);
                secondMaterialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                                 (const u32 *) gCharacterBPFaceMaterialName);
                palette = gCharacterBPMainPalette;
                secondPalette = gCharacterBPFacePalette;
                secondPaletteSize = 0x40;
            } else {
                materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                           (const u32 *) gCharacterBEMainMaterialName);
                secondMaterialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                                 (const u32 *) gCharacterBEFaceMaterialName);
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
            GX_LoadTexPltt(palette, (u32) paletteAddress, 0x20);
            GX_EndLoadTexPltt();
            paletteAddress = (u8 *) (material->mTexPlttBase << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(secondPalette, (u32) paletteAddress, secondPaletteSize);
            GX_EndLoadTexPltt();
        }
    }
}

void CreateTire(KartModelsEntry *kartModelsEntry, void *heap) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResMdl *mdl;
    NNSG3dResFileHeader *nsbtxFile;
    nsbmdFile = GetKartModelFile(BuildTireNsbmdPath(kartIndex, kartModelsEntry->mKartOffsetData->mTireName));
    nsbtxFile = FindKartModelFile(BuildTireNsbtxPath(kartIndex, kartModelsEntry->mKartOffsetData->mTireName));
    kartModelsEntry->mModels[2] = HeapAlloc(heap, sizeof(*kartModelsEntry->mModels[2]));
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[2], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[2], 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_COURSE);
}

void CreateKartShadow(KartModelsEntry *kartModelsEntry, void *heap) {
    void *nsbmdFile;
    NNSG3dResMdlSet *mdlSet;
    NNSG3dResDictEntryHeader *entries;
    nsbmdFile = GetKartModelFile(BuildKartShadowNsbmdPath(kartModelsEntry->mKartIndex));
    kartModelsEntry->mShadowModel = HeapAlloc(heap, sizeof(*kartModelsEntry->mShadowModel));
    AddResFileEntry(&kartModelsEntry->mShadowModel->mNsbmd.mResFileEntry, nsbmdFile, nsbmdFile);
    mdlSet = NNS_G3dGetMdlSet(nsbmdFile);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mdlSet->mDict, mdlSet->mDict.mOfsEntry);
    InitShadowModelFromResMdl(kartModelsEntry->mShadowModel,
                              OFFSET_PTR(NNSG3dResMdl, mdlSet, *DICT_ENTRY(u32, entries, 0)), 3);
}

void CreateKillerItem(void *heap) {
    void *nsbmdFile = GetKartModelFile("character/common/KillerItem.nsbmd");
    NNSG3dResFileHeader *nsbtxFile = FindKartModelFile("character/common/KillerItem.nsbtx");
    void *shadowNsbmdFile = GetKartModelFile("character/common/KillerItem_s.nsbmd");
    void *nsbcaFile;
    SetKartModelMaterialColors(InitNsbmdWithTextureInfoCopy(heap, &gKartModels->mKillerItem, nsbmdFile, nsbtxFile),
                               KART_MODEL_COLORS_COURSE);
    SetNsbmdPolygonIdAll(&gKartModels->mKillerItem, 3);
    nsbcaFile = GetKartModelFile("character/common/KillerItem.nsbca");
    InitModelAnimation(0, &gKartModels->mKillerItemNsbca, &gKartModels->mKillerItem, 1, heap, nsbmdFile);
    InitModelAnimationEntries(&gKartModels->mKillerItemNsbca, nsbcaFile, heap);
    SetModelAnimation(&gKartModels->mKillerItemNsbca, 0);
    InitShadowModel(&gKartModels->mKillerItemS, shadowNsbmdFile, 3);
    SetKillerItemRenderCallback(&gKartModels->mKillerItem);
}

void LoadKartModelMenuFile(void *heap, const void *fileName, void **file) {
    char path[0x100];
    snprintf(path, 0x100, "/data/KartModelMenu/%s", fileName);
    LoadFileIntoHeap(path, heap, file);
}

void InitKartModelMenuAppearAndPalette(void *heap, s32 createKartAppear) {
    if (createKartAppear != 0) {
        gKartModelMenu->mUseEmblemTex = FALSE;
        gKartModelMenu->mKartAppear = CreateKartAppear(heap);
    } else {
        gKartModelMenu->mUseEmblemTex = TRUE;
    }
    gKartModelMenu->mKartAPalette = LoadKartAPaletteFromKartModelMenu(heap);
    gKartModelMenu->mSelectModel = NULL;
}

#pragma thumb off

#pragma thumb on

void CreateKartModelMenuCharacter(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile) {
    NNSG3dResMdl *mdl;
    u32 loopFlag;
    void *jointAnimation;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_MENU);
    InitModelAnimation(0, animation, nsbmd, 1, heap, NULL);
    jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
    loopFlag = GetCharacterAnimationLoopFlag(2);
    InitModelAnimationEntry(animation, 0, jointAnimation, loopFlag, heap);
    SetModelAnimation(animation, 0);
}

void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    u32 tireMaterialIndex;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_MENU);
    tireMaterialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gTireModelMaterialName);
    NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
}

void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, KART_MODEL_COLORS_MENU);
}

#pragma thumb off

#pragma thumb on

void *CreateKartModelMenuShadow(ShadowModel *shadowModel, NNSG3dResFileHeader *modelFile) {
    return InitShadowModel(shadowModel, modelFile, 3);
}

void LoadKartModelMenuSelectModel(void *heap) {
    void *modelFile;
    void *textureFile;
    LoadKartModelMenuFile(heap, gKartSelectNsbmdName, &modelFile);
    LoadKartModelMenuFile(heap, gKartSelectNsbtxName, &textureFile);
    gKartModelMenu->mSelectModel = HeapAlloc(heap, sizeof(*gKartModelMenu->mSelectModel));
    InitNsbmdWithTextureFile(gKartModelMenu->mSelectModel, modelFile, textureFile);
    SetNsbmdPolygonIdAll(gKartModelMenu->mSelectModel, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(gKartModelMenu->mSelectModel->mResMdl, 1);
}

#pragma thumb off

#pragma thumb on

void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file) {
    gKartModelMenu->mEmblemTex = NNS_G3dGetTex(file);
    NNS_G3dResDefaultSetup(file);
}

void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot) {
    InitKartModelsEntry(slot);
    slot->mRegion = gStartupWork->mRegion;
    slot->mEmblemTex = 0;
    slot->mCharacterNsbmd = HeapAlloc(heap, sizeof(*slot->mCharacterNsbmd));
    slot->mKartNsbmd = HeapAlloc(heap, sizeof(*slot->mKartNsbmd));
    slot->mTireNsbmd = HeapAlloc(heap, sizeof(*slot->mTireNsbmd));
    slot->mShadowModel = HeapAlloc(heap, sizeof(*slot->mShadowModel));
    slot->mCharacterAnimation = HeapAlloc(heap, sizeof(*slot->mCharacterAnimation));
}

void InitKartModelMenuView(KartModelMenuView *view, int flag) {
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
    KartModelMenuData *menu = gKartModelMenu;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s16 shownSlotIndex = menu->mShownSlotIndex;
    if (shownSlotIndex >= 0 && files->mLoadRequested == FALSE) {
        mdl = menu->mSlots[shownSlotIndex].mKartNsbmd->mResMdl;
        materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gKartEmblemMaterialName);
        matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
        material = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex));
        paletteBase = material->mTexPlttBase << 4;
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_TEXTURE_IMAGE, (material->mTexImageParam & 0xffff) << 3,
                                           emblemData, 0x200);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_TEXTURE_PALETTE, paletteBase, emblemPalette, 0x20);
    }
}

void InitKartModelMenuWithParamFiles(void *heap) {
    u16 fileIndex;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    gStartupWork->mUnk_1c &= ~STARTUP_FLAG_FAST_DMA;
    InitLnkVramManagers(heap);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(heap);
    InitKartModelMenuAppearAndPalette(heap, 0);
    LoadKartModelMenuFile(heap, gCharMenuParamBinName, (void **) &gKartModelMenu->mCharMenuParams);
    LoadKartModelMenuFile(heap, gKartMenuParamBinName, (void **) &gKartModelMenu->mKartMenuParams);
    LoadKartModelMenuSelectModel(heap);
    for (fileIndex = 0; fileIndex < 2; fileIndex++) {
        InitKartModelMenuFiles(heap, &gKartModelMenu->mFiles[fileIndex]);
    }
    if (gBackupBuffers->mEmblemRecord->mFilled != 0 && gBackupBuffers->mFirstBlock->mEmblemOff == 0) {
        gKartModelMenu->mEmblemData = gBackupBuffers->mEmblemRecord->mEmblemData;
        gKartModelMenu->mEmblemPalette = GetEmblemSBNclr()->mData;
    }
    SetHeapGroupId(9);
}

void InitKartModelMenuWithKartList(void *heap) {
    u16 fileIndex;
    enum { KART_INDEX_FIRST } kartIndex;
    s32 characterIndex;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    gStartupWork->mUnk_1c &= ~STARTUP_FLAG_FAST_DMA;
    InitLnkVramManagers(heap);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(heap);
    InitKartModelMenuAppearAndPalette(heap, 1);
    kartIndex = 0;
    gKartModelMenu->mKartIndex = kartIndex;
    gKartModelMenu->mKartListCount = kartIndex;
    gKartModelMenu->mKartListPos = kartIndex;
    while (kartIndex < 0x24) {
        if (FindKartModelMenuCharacter(&characterIndex, kartIndex) != 0) {
            gKartModelMenu->mKartListCount++;
        }
        kartIndex++;
    }
    gKartModelMenu->mView.mScale = gKartModelMenuMaxScale;
    for (fileIndex = 0; fileIndex < 2; fileIndex++) {
        InitKartModelMenuFiles(heap, &gKartModelMenu->mFiles[fileIndex]);
    }
    gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested = TRUE;
    gKartModelMenu->mView.mCharacterIndex = CHARACTER_MARIO;
    gKartModelMenu->mView.mKartIndex = 0;
    gKartModelMenu->mLoadSlot->mCharacterIndex = CHARACTER_MARIO;
    gKartModelMenu->mLoadSlot->mKartIndex = 0;
    gKartModelMenu->mLoadSlot->mKartOffsetData = gKartModelMenu->mKartOffsetTable;
    LoadKartAndCharacterFiles();
    AdvanceKartModelMenuLoad();
    InitKartModelMenuView(&gKartModelMenu->mView, 0);
    SetHeapGroupId(9);
}

void InitKartModelMenu(void *heap) {
    u16 slotIndex;
    gKartModels = NULL;
    gKartModelMenu = HeapAlloc(heap, sizeof(KartModelMenuData));
    gKartModelMenu->mShownSlotIndex = -1;
    gKartModelMenu->mLoadSlotIndex = 0;
    gKartModelMenu->mLoadSlot = &gKartModelMenu->mSlots[gKartModelMenu->mLoadSlotIndex];
    gKartModelMenu->mKartAPalette = NULL;
    gKartModelMenu->mSpinStopTimed = FALSE;
    gKartModelMenu->mSpinStopped = 0;
    gKartModelMenu->mMirrorMode = 0;
    gKartModelMenu->mCharMenuParams = NULL;
    gKartModelMenu->mKartMenuParams = NULL;
    gKartModelMenu->mCharacterRequested = 0;
    gKartModelMenu->mKartRequested = 0;
    gKartModelMenu->mKartAppear = NULL;
    gKartModelMenu->mSpinStopFrames = 0;
    gKartModelMenu->mEmblemPalette = NULL;
    gKartModelMenu->mEmblemData = gKartModelMenu->mEmblemPalette;
    LoadEmblemSBNclr(heap);
    LoadKartModelMenuFile(heap, gKartOffsetDataBinName, (void **) &gKartModelMenu->mKartOffsetTable);
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        InitKartModelMenuSlot(heap, &gKartModelMenu->mSlots[slotIndex]);
    }
    InitKartModelMenuView(&gKartModelMenu->mView, 1);
    SetHeapGroupId(9);
}

s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex) {
    KartModelMenuData *menu = gKartModelMenu;
    s16 *characterParam = &menu->mCharMenuParams[characterIndex];
    KartMenuParams *kartParams = &menu->mKartMenuParams[kartIndex];
    menu->mMenuParams[0] = kartParams->mParams[0];
    menu->mMenuParams[1] = kartParams->mParams[1];
    menu->mMenuParams[2] = kartParams->mParams[2];
    menu->mMenuParams[3] = kartParams->mParams[3];
    menu->mMenuParams[4] = kartParams->mParams[4];
    menu->mMenuParams[5] = kartParams->mParams[5];
    menu->mMenuParams[2] += *characterParam;
    return gKartModelMenu->mMenuParams;
}

// Asks for a new character in the menu view; -1 clears it at once.
void RequestKartModelMenuCharacter(s32 characterIndex) {
    KartModelMenuData *menu = gKartModelMenu;
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
        gKartModelMenu->mCharacterRequested = 1;
    }
}

void RequestKartModelMenuKart(s32 kartIndex) {
    KartModelMenuData *menu = gKartModelMenu;
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
        gKartModelMenu->mKartRequested = 1;
    }
}

void AdvanceKartModelMenuBg0Offset(void) {
    KartModelMenuView *view = &gKartModelMenu->mView;
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
    gKartModelMenu->mView.mBg0Direction = 0;
}

void StartKartModelMenuBg0Decrease(void) {
    gKartModelMenu->mView.mBg0Direction = 1;
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
    G3i_FrustumW_(top, bottom, left, right, 0x200, 0x64000, 0x1000, 0, &NNS_G3dGlb.mProjMtx);
    NNS_G3dGlb.mFlag &= ~0x50;
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
        Vec3NormalizeAndGetLengthUnchecked(&lightDirection, &lightDirection);
    }
    NNS_G3dGlbLightVector(0, (s16) lightDirection.x, (s16) lightDirection.y, (s16) lightDirection.z);
    NNS_G3dGlbLightColor(
        0, (u16) (gKartModelMenuLightLevel | (gKartModelMenuLightLevel << 5) | (gKartModelMenuLightLevel << 10)));
    SetFrustumProjection(0);
    referenceAxis = gKartModelMenuReferenceAxis;
    target = gKartModelMenuLookAtTarget;
    target.y += yOffset;
    VEC_Subtract(&target, &gKartModelMenuCameraPosition, &viewDirection);
    VEC_CrossProduct(&referenceAxis, &viewDirection, &camUp);
    NNS_G3dGlb.mCamPos = gKartModelMenuCameraPosition;
    NNS_G3dGlb.mCamUp = camUp;
    NNS_G3dGlb.mCamTarget = target;
    G3i_LookAt_(&gKartModelMenuCameraPosition, &camUp, &target, 0, &NNS_G3dGlb.mCameraMtx);
    NNS_G3dGlb.mFlag &= ~0xe8;
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

    NNS_G3dGlb.mPrmViewPort = VIEWPORT_WHOLE_SCREEN;
    translation.x = gKartModelMenuLookAtTarget.x;
    translation.y = gKartModelMenuLookAtTarget.y;
    translation.z = gKartModelMenuLookAtTarget.z;
    scaleValue = FX_MulFunc(gKartModelMenuScaleFactor, view->mScale);
    scale.x = scaleValue;
    scale.y = scaleValue;
    scale.z = scaleValue;
    MTX_RotY33_(&rotationMatrix, FX_SinIdx(view->mYawAngle), FX_CosIdx(view->mYawAngle));
    MTX_RotX33_(&tiltMatrix, SIN_OF_ANGLE((u16) (gKartModelMenuTiltAngleOffset + view->mDrawnTiltAngle)),
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
    MI_Copy36B(&tiltMatrix, &NNS_G3dGlb.mPrmBaseRot);
    NNS_G3dGlb.mFlag &= ~0xa4;
    NNS_G3dGlbFlushP();
    if (gKartModelMenu->mSelectModel != NULL) {
        NNS_G3dDraw(&gKartModelMenu->mSelectModel->mRenderObj);
    }
    MI_Copy36B(&rotationMatrix, &NNS_G3dGlb.mPrmBaseRot);
    NNS_G3dGlb.mFlag &= ~0xa4;
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

void SetupKartModelEmblemTex(KartModelMenuSlot *slot) {
    if ((gKartModelMenu->mUseEmblemTex != FALSE) && (slot->mEmblemTex != NULL)) {
        NNS_G3dReleaseMdlTexEx(slot->mKartNsbmd->mResMdl, (const u32 *) gEmblemTextureName);
        NNS_G3dReleaseMdlPlttEx(slot->mKartNsbmd->mResMdl, (const u32 *) gEmblemPaletteName);
        NNS_G3dBindMdlTexEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, (const u32 *) gEmblemTextureName);
        NNS_G3dBindMdlPlttEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, (const u32 *) gEmblemPaletteName);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceKartModelMenu(s32 mirrorMode) {
    KartModelMenuView *view;
    KartModelMenuSlot *shownSlot;
    view = &gKartModelMenu->mView;
    gKartModelMenu->mMirrorMode = mirrorMode;
    QueueKartModelMenuLoad();
    AdvanceKartModelMenuBg0Offset();
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        shownSlot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        if (gKartModelMenu->mSpinStopped != 0 || gKartModelMenu->mSpinStopTimed != FALSE) {
            AdvanceAngleToward(&view->mSpinAngle, KART_MODEL_MENU_REST_YAW, gKartModelMenuSpinStep);
            if (gKartModelMenu->mSpinStopped == 0 && gKartModelMenu->mSpinStopTimed != FALSE) {
                gKartModelMenu->mSpinStopFrames++;
                if (gKartModelMenu->mSpinStopFrames > KART_MODEL_MENU_SPIN_STOP_FRAMES) {
                    gKartModelMenu->mSpinStopTimed = FALSE;
                }
            }
        } else {
            view->mSpinAngle += 0x64;
        }
        view->mYawAngle = mirrorMode != 0 ? (u16) -view->mSpinAngle : view->mSpinAngle;
        AdvanceModelAnimation(shownSlot->mCharacterAnimation);
        if (gKartModelMenu->mEmblemData != NULL && gKartModelMenu->mEmblemPalette != NULL &&
            gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(gKartModelMenu->mEmblemData, gKartModelMenu->mEmblemPalette);
        }
    }
    ClearKartModelMenuRequests();
}

void AdvanceShownSlotAndQueueEmblem(void) {
    s16 shownSlotIndex = gKartModelMenu->mShownSlotIndex;
    if (shownSlotIndex >= 0) {
        AdvanceModelAnimation(gKartModelMenu->mSlots[shownSlotIndex].mCharacterAnimation);
        if (gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(GetEmblemRecordBytes(), GetEmblemSBPalette());
        }
    }
}

void AdvanceKartModelMenuInput(void) {
    KartModelMenuView *view = &gKartModelMenu->mView;
    s32 value = 0;
    BOOL yawChanged;
    s32 changed;
    s32 characterIndex;
    u16 buttons;
    InputSlotIndex inputSlot;
    s32 scaleInputKind = 2;
    KartModelMenuFiles *files;

    files = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
    if (gThreadFunctionQueue->mRunRequested == 0 && files->mLoadRequested == FALSE) {
        characterIndex = ~value;
        inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
        buttons = gInputSlots[inputSlot].mPressedBits;
        if ((u16) (buttons & PAD_KEY_R) != 0) {
            changed = value;
            do {
                gKartModelMenu->mKartIndex++;
                if (gKartModelMenu->mKartIndex > KART_MODEL_MENU_LAST_KART_INDEX) {
                    gKartModelMenu->mKartIndex = value;
                }
                if (FindKartModelMenuCharacter(&characterIndex, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gKartModelMenu->mKartIndex);
                    changed = 1;
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, value, 0x1fd);
                }
            } while (changed == 0);
            gKartModelMenu->mKartListPos++;
            if (gKartModelMenu->mKartListPos >= gKartModelMenu->mKartListCount) {
                gKartModelMenu->mKartListPos = 0;
            }
        } else if ((u16) (buttons & PAD_KEY_L) != 0) {
            changed = value;
            do {
                gKartModelMenu->mKartIndex--;
                if (gKartModelMenu->mKartIndex < 0) {
                    gKartModelMenu->mKartIndex = KART_MODEL_MENU_LAST_KART_INDEX;
                }
                if (FindKartModelMenuCharacter(&characterIndex, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gKartModelMenu->mKartIndex);
                    changed = 1;
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, value, 0x1fe);
                }
            } while (changed == 0);
            gKartModelMenu->mKartListPos--;
            if (gKartModelMenu->mKartListPos < 0) {
                gKartModelMenu->mKartListPos = gKartModelMenu->mKartListCount - 1;
            }
        }
    }
    yawChanged = FALSE;
    changed = yawChanged;
    GetSndHandleSlot(2);
    inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    buttons = gInputSlots[inputSlot].mBits;
    if ((u16) (buttons & PAD_KEY_RIGHT) != 0) {
        view->mYawAngle += 0x1c2;
        yawChanged = TRUE;
    } else if ((u16) (buttons & PAD_KEY_LEFT) != 0) {
        view->mYawAngle -= 0x1c2;
        yawChanged = TRUE;
    }
    inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
    buttons = gInputSlots[inputSlot].mBits;
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
    buttons = gInputSlots[inputSlot].mBits;
    if ((u16) (buttons & PAD_KEY_X) != 0) {
        view->mScale += 0x7b;
        if (view->mScale > gKartModelMenuMaxScale) {
            view->mScale = gKartModelMenuMaxScale;
        } else {
            scaleInputKind = 0;
        }
    } else {
        inputSlot = INPUT_SLOT_PAD_OR_PARTICIPANT;
        buttons = gInputSlots[inputSlot].mBits;
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
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        slot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        view = &gKartModelMenu->mView;
        if (view->mCharacterIndex != KART_MODEL_MENU_NONE && view->mKartIndex != KART_MODEL_MENU_NONE) {
            SetupLightFrustumAndLookAt(view->mBg0Offset, gKartModelMenuLookAtYOffset);
            DrawKartModelMenuSlot(slot, &gKartModelMenu->mView, gKartModelMenu->mMirrorMode);
            NNS_G3dGeFlushBuffer();
        }
    }
}

void DrawKartModelMenuUnmirrored(void) {
    KartModelMenuSlot *slot;
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        slot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        SetupLightFrustumAndLookAt(0, gKartModelMenuLookAtYOffset);
        DrawKartModelMenuSlot(slot, &gKartModelMenu->mView, 0);
        NNS_G3dGeFlushBuffer();
    }
}

void CopyHeyhoPaletteIndices(void) {
    u16 paletteIndex;
    for (paletteIndex = 0; paletteIndex < 8; paletteIndex++) {
        gKartModels->mHeyhoPaletteIndices[paletteIndex] = gMenuShared->mShuffledIndices[paletteIndex];
    }
}

void SetupHeyhoPalettes(void) {
    u32 kartIndex;
    if (gKartModels->mHeyhoPalettes != NULL) {
        CopyHeyhoPaletteIndices();
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            if (gKartModels->mKartModelsEntries[kartIndex].mCharacterIndex == CHARACTER_HEYHO) {
                UploadHeyhoPalette(kartIndex, &gKartModels->mKartModelsEntries[kartIndex], GetHeyhoPalette(kartIndex));
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
    DC_FlushRange(palette, 0x20);
    if (IsCharacterPNameUsed(kartIndex) != 0) {
        materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gHeyhoPMainMaterialName);
    } else {
        materialIndex = NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat)->mDict,
                                                   (const u32 *) gHeyhoEMainMaterialName);
    }
    matBlock = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
    paletteBase = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, materialIndex))->mTexPlttBase << 4;
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(palette, paletteBase, 0x20);
    GX_EndLoadTexPltt();
}

HeyhoPalette *GetHeyhoPalette(int kartIndex) {
    HeyhoPalette *palette = NULL;
    if (gKartModels->mHeyhoPalettes != NULL) {
        palette = gKartModels->mHeyhoPalettes + gKartModels->mHeyhoPaletteIndices[kartIndex];
    }
    return palette;
}

void StartKartModelMenuTimedSpinStop(void) {
    gKartModelMenu->mSpinStopTimed = TRUE;
    gKartModelMenu->mSpinStopFrames = 0;
}

#pragma thumb off

#pragma thumb on

void SetKartModelMenuSpinStopped(u32 flag) {
    gKartModelMenu->mSpinStopped = flag;
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

Nclr *GetEmblemSBNclr(void) {
    return gEmblemSBNclr;
}

#pragma thumb off

#pragma thumb on

// Bytes of the exp heap that holds the kart model menu files.
#define KART_MODEL_MENU_HEAP_SIZE 0xf000

void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files) {
    void *heapMemory;
    struct NNSiFndHeapHead *expHeap;
    heapMemory = HeapAlloc(heap, KART_MODEL_MENU_HEAP_SIZE);
    expHeap = NNS_FndCreateExpHeapEx(heapMemory, KART_MODEL_MENU_HEAP_SIZE, 0);
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

    files = gKartModelMenu->mFiles;
    loadSlotIndex = gKartModelMenu->mLoadSlotIndex;
    loadFiles = &files[loadSlotIndex];
    characterIndex = gKartModelMenu->mLoadSlot->mCharacterIndex;
    kartIndex = gKartModelMenu->mLoadSlot->mKartIndex;
    loadFiles->mLoadStep = 0;
    NNS_FndDestroyExpHeap(loadFiles->mHeap);
    loadFiles->mHeap = NNS_FndCreateExpHeapEx(loadFiles->mHeapMemory, 0xf000, 0);
    if (characterIndex != -1 && loadFiles->mCharacterNsbmdFile != NULL) {
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mEmblemNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartShadowNsbmdFile);
    }
    tireName = gKartModelMenu->mKartOffsetTable[kartIndex].mTireName;
    LoadFileIntoHeap(BuildCharacterNsbmdPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbmdFile);
    LoadFileIntoHeap(BuildCharacterNsbtxPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbtxFile);
    LoadFileIntoHeap(BuildCharacterNsbcaPath(characterIndex, 2), loadFiles->mHeap, &loadFiles->mCharacterNsbcaFile);
    LoadFileIntoHeap(BuildEmblemNsbtxPath(characterIndex), loadFiles->mHeap, (void **) &loadFiles->mEmblemNsbtxFile);
    LoadFileIntoHeap(BuildKartNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbmdFile);
    LoadFileIntoHeap(BuildKartNsbtxPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbtxFile);
    LoadFileIntoHeap(BuildKartShadowNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartShadowNsbmdFile);
    LoadFileIntoHeap(BuildTireNsbmdPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbmdFile);
    LoadFileIntoHeap(BuildTireNsbtxPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbtxFile);
}

// Builds the slot being loaded over three calls, then shows it and loads into the other slot next.
void AdvanceKartModelMenuLoad(void) {
    KartModelMenuFiles *loadFiles;
    KartModelMenuSlot *loadSlot;
    KartModelMenuSlot *shownSlot;
    ModelAnimation *animation;

    G2Bg0OfsWrite(gKartModelMenu->mView.mBg0Offset);
    if (gThreadFunctionQueue->mRunRequested == 0) {
        loadFiles = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
        if (loadFiles->mLoadRequested != FALSE) {
            loadSlot = gKartModelMenu->mLoadSlot;
            if (loadFiles->mLoadStep == 0) {
                CreateKartModelMenuCharacter(loadFiles->mHeap, loadSlot->mCharacterNsbmd, loadSlot->mCharacterAnimation,
                                             loadFiles->mCharacterNsbmdFile, loadFiles->mCharacterNsbtxFile,
                                             loadFiles->mCharacterNsbcaFile);
                loadFiles->mLoadStep++;
                return;
            }
            if (loadFiles->mLoadStep == 1) {
                LoadKartModelMenuEmblemTexData(loadFiles->mEmblemNsbtxFile);
                gKartModelMenu->mLoadSlot->mEmblemTex = gKartModelMenu->mEmblemTex;
                CreateKartModelMenuShadow(loadSlot->mShadowModel, loadFiles->mKartShadowNsbmdFile);
                CreateKartModelMenuTire(loadSlot->mTireNsbmd, loadFiles->mTireNsbmdFile, loadFiles->mTireNsbtxFile);
                loadFiles->mLoadStep++;
                return;
            }
            CreateKartModelMenuKart(loadSlot->mKartNsbmd, loadFiles->mKartNsbmdFile, loadFiles->mKartNsbtxFile);
            SetupKartModelEmblemTex(gKartModelMenu->mLoadSlot);
            UploadKartAPaletteSlice(loadSlot->mKartNsbmd, loadSlot->mKartIndex, gKartModelMenu->mKartAPalette);
            UploadKartModelsEntryPalettes((struct KartModelsEntry *) loadSlot, 1);
            loadFiles->mLoadRequested = FALSE;
            loadFiles->mLoadStep = 0;
            if (gKartModelMenu->mShownSlotIndex >= 0) {
                shownSlot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
                if (loadSlot->mCharacterIndex == shownSlot->mCharacterIndex) {
                    animation = loadSlot->mCharacterAnimation;
                    animation->mHead.mFrameIndex = shownSlot->mCharacterAnimation->mHead.mFrameIndex;
                    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
                }
            }
            gKartModelMenu->mShownSlotIndex = gKartModelMenu->mLoadSlotIndex;
            gKartModelMenu->mLoadSlotIndex = gKartModelMenu->mLoadSlotIndex == 0 ? 1 : 0;
            gKartModelMenu->mLoadSlot = &gKartModelMenu->mSlots[gKartModelMenu->mLoadSlotIndex];
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
    texWorkSize = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    plttWorkSize = NNS_GfdGetLnkPlttVramManagerWorkSize(0x20);
    texWork = HeapAlloc(heap, texWorkSize);
    plttWork = HeapAlloc(heap, plttWorkSize);
    NNS_GfdInitLnkTexVramManager(0x00040000u, 0x00020000u, texWork, texWorkSize, 1);
    NNS_GfdInitLnkPlttVramManager(0x00010000u, plttWork, plttWorkSize, 1);
}

#pragma thumb off

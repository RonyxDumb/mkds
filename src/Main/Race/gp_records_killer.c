#include "Main/Race/gp_records_killer.h"
#include "Main/System/input_slots.h"
#include "Main/System/archive_slots.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/point_link_cursor_first_next.h"
#include "Main/Kart/point_link_cursor_advance.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Kart/use_item.h"
#include "Main/Kart/kart_ai_throw_at_near_target.h"
#include "Main/Kart/kart_ai_throw_after_held.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Scene/run_scenes.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_pool.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/results_gp.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "card_rom_backup_access.h"
#include "Main/MapObjects/sman_collision.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Kart/kart_ai_follow.h"
#include "fixed_vector_math.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const KartAiItemUseEntry gBattleEasyHeldItemEntries[18] = {{ThrowItemRandomAfterHeld, 1, 0x20, 0x1b},
                                                           {ThrowItemRandomAfterHeld, 1, 0x20, 0x1b},
                                                           {ThrowItemRandomMoreForwardAfterHeld, 2, 0x20, 0x1b},
                                                           {ThrowItemRandomAfterHeld, 2, 0x20, 0x1b},
                                                           {UseItemAfterHeldIfTurnUnder10, 0, 0xa, 5},
                                                           {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 0xa, 5},
                                                           {ThrowItemRandomMoreForwardAfterHeld, 1, 0x20, 0x1b},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 5, 5},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {EasyUseItemAfterHeld, 0, 0xa, 0xa},
                                                           {EasyUseItemAfterHeld, 2, 0xa, 0xa}};
const KartAiItemUseEntry gBattleEasyItemInUseEntries[14] = {
    {ThrowItemByCircleKind, 1, 0x20, 0x1b},
    {UseItemByCircleKind, 1, 0x20, 0x1b},
    {ThrowItemByTrailKind, 2, 0x20, 0x1b},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 2, 0x20, 0x1b},
    {BattleItemInUseNop, 2, 5, 0xa},
    {ThrowItemByTrailKind, 1, 0x20, 0x1b},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa}};
const KartAiItemUseEntry gBattleHardItemInUseEntries[14] = {
    {ThrowItemByCircleKind, 1, 5, 3},
    {UseItemByCircleKind, 1, 5, 3},
    {ThrowItemByTrailKind, 2, 1, 0},
    {BattleItemInUseNop, 0, 1, 3},
    {BattleItemInUseNop, 0, 1, 3},
    {BattleItemInUseNop, 0, 3, 3},
    {BattleItemInUseNop, 0, 3, 3},
    {BattleItemInUseNop, 2, 1, 3},
    {BattleItemInUseNop, 2, 3, 0xa},
    {ThrowItemByTrailKind, 1, 1, 3},
    {BattleItemInUseNop, 0, 1, 3},
    {BattleItemInUseNop, 0, 1, 3},
    {BattleItemInUseNop, 0, 1, 3},
    {BattleItemInUseNop, 0, 3, 0xa}};
const KartAiItemUseEntry gBattleNormalHeldItemEntries[18] = {
    {ThrowItemRandomAfterHeldOrAtNearTarget, 1, 0x20, 0x1b},
    {ThrowItemRandomAfterHeldOrAtNearTarget, 1, 0x20, 0x1b},
    {ThrowItemRandomAfterHeldOrBehindNearTarget, 2, 0x20, 0x1b},
    {ThrowItemRandomAfterHeldOrAtNearTarget, 2, 0x20, 0x1b},
    {UseItemAfterHeldOrOnTargetIfTurnUnder10, 0, 0xa, 5},
    {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 0xa, 5},
    {ThrowItemRandomAfterHeldOrBehindNearTarget, 1, 0x20, 0x1b},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {BattleUseItemAfterHeld, 0, 0xa, 0xa},
    {BattleUseItemAfterHeld, 0, 0xa, 0xa},
    {BattleUseItemAfterHeld, 0, 0xa, 0xa},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 5, 5},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {UseItemAfterHeldOrOnTarget, 0, 0xa, 0xa},
    {UseItemAfterHeldOrOnTarget, 2, 0xa, 0xa}};
const KartAiItemUseEntry gBattleNormalItemInUseEntries[14] = {
    {ThrowItemByCircleKind, 1, 0x20, 0x1b},
    {UseItemByCircleKind, 1, 0x20, 0x1b},
    {ThrowItemByTrailKind, 2, 0x20, 0x1b},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 2, 0x20, 0x1b},
    {BattleItemInUseNop, 2, 5, 0xa},
    {ThrowItemByTrailKind, 1, 0x20, 0x1b},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa},
    {BattleItemInUseNop, 0, 5, 0xa}};
const KartAiItemUseEntry gBattleHardHeldItemEntries[18] = {{HardSetItemBitsEveryCall, 1, 1, 0},
                                                           {HardSetItemBitsEveryCall, 1, 1, 0},
                                                           {SetItemBitsEveryCall, 2, 1, 0},
                                                           {ThrowItemRandomAfterHeldOrAtNearTarget, 2, 1, 0},
                                                           {UseItemAfterHeldOrOnTargetIfTurnUnder10, 0, 3, 5},
                                                           {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 3, 5},
                                                           {SetItemBitsEveryCall, 1, 1, 0},
                                                           {UseItemWhenHasTarget, 0, 3, 0xa},
                                                           {UseItemWhenHasTarget, 0, 3, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 3, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 3, 0xa},
                                                           {BattleUseItemAfterHeld, 0, 1, 0},
                                                           {UseItemWhenHasTarget, 0, 1, 0},
                                                           {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 3, 5},
                                                           {UseItemAfterHeldOrOnTarget, 0, 3, 0xa},
                                                           {UseItemWhenHasTarget, 0, 1, 3},
                                                           {UseItemAfterHeldOrOnTarget, 0, 1, 3},
                                                           {UseItemWhenHasTarget, 2, 3, 0xa}};
const KartAiItemUseEntry *gBattleHeldItemEntries;
void (*gUseItemNotCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gUseItemCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gThrowItemNotCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
s32 *gStaffGhostTime;
const KartAiItemUseEntry *gBattleItemInUseEntries;
void (*gThrowItemCircleKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gThrowItemNotTrailKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void (*gThrowItemTrailKindCallback)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);

static inline BOOL AreAllGrandPrixRecordsTopRank(void) {
    BOOL isFilledTopRank;
    enum { CUP_FIRST } cup;
    enum { ENGINE_CLASS_FIRST } engineClass;
    for (cup = 0; cup < 8; cup++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            if (IsGrandPrixRecordFilled(cup, engineClass) != 0 && GetGrandPrixRecordCupRank(cup, engineClass) == 0) {
                isFilledTopRank = TRUE;
            } else {
                isFilledTopRank = FALSE;
            }
            if (isFilledTopRank == FALSE) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

static inline BOOL IsGrandPrixRecordFilledTopRank(s32 cup, s32 engineClass) {
    if (IsGrandPrixRecordFilled(cup, engineClass) != 0 && GetGrandPrixRecordCupRank(cup, engineClass) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 SetAndWriteSecretMessageFlags(void) {
    u32 setFlagBits;
    setFlagBits = 0;
    if (GetCurrentSceneNumber() == SCENE_RESULT) {
        setFlagBits = SetSecretMessageFlags();
        WriteBackupFirstBlockWrapper();
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    return setFlagBits;
}

u32 SetSecretMessageFlagsWrapper(void) {
    return SetSecretMessageFlags();
}

// Sets the backup flags and kart appear limit earned by top-rank records; returns one bit per new secret message.
u32 SetSecretMessageFlags(void) {
    u32 setFlagBits;
    u32 limitRaiseBit;
    BOOL isLimitRaised;
    setFlagBits = 0;
    setFlagBits = setFlagBits | SetSecretMessageFlagsPerEngineClass();
    setFlagBits = setFlagBits | SetSecretMessageFlagsFromCups3And7();
    limitRaiseBit = 0;
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 2) {
        if ((IsGrandPrixRecordFilled(3, 1) != 0 && GetGrandPrixRecordCupRank(3, 1) == 0) ? 1 : 0) {
            RaiseKartAppearLimit(2);
            isLimitRaised = TRUE;
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x200;
    }
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 3) {
        BOOL isFilledTopRank;
        if (IsGrandPrixRecordFilled(3, 2) != 0 && GetGrandPrixRecordCupRank(3, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto raiseLimit;
        }
        if (IsGrandPrixRecordFilled(7, 2) != 0 && GetGrandPrixRecordCupRank(7, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        raiseLimit:
            RaiseKartAppearLimit(3);
            isLimitRaised = TRUE;
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x400;
    }
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 4) {
        if ((IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) ? 1 : 0) {
            if ((IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) ? 1 : 0) {
                RaiseKartAppearLimit(4);
                isLimitRaised = TRUE;
            }
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x800;
    }
    return setFlagBits | limitRaiseBit;
}

u32 SetSecretMessageFlagsPerEngineClass(void) {
    enum { ENGINE_CLASS_FIRST } engineClass;
    u32 setFlagBits;
    u32 lastGroupBit;
    u32 newBit;
    s32 cup2Flag;
    s32 cups4And5Flag;
    s32 cup6Flag;
    setFlagBits = 0;
    for (engineClass = 0; engineClass < 4; engineClass++) {
        newBit = 0;
        if (IsBackupFlagSet(engineClass) == 0) {
            if (IsGrandPrixRecordFilledTopRank(0, engineClass) != FALSE &&
                IsGrandPrixRecordFilledTopRank(1, engineClass) != FALSE) {
                SetBackupFlag(engineClass);
                newBit = 1;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        cup2Flag = engineClass + 4;
        if (IsBackupFlagSet(cup2Flag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(2, engineClass) != FALSE) {
                SetBackupFlag(cup2Flag);
                newBit = 2;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        cups4And5Flag = engineClass + 8;
        if (IsBackupFlagSet(cups4And5Flag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(4, engineClass) != FALSE &&
                IsGrandPrixRecordFilledTopRank(5, engineClass) != FALSE) {
                SetBackupFlag(cups4And5Flag);
                newBit = 4;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        cup6Flag = engineClass + 12;
        if (IsBackupFlagSet(cup6Flag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(6, engineClass) != FALSE) {
                SetBackupFlag(cup6Flag);
                newBit = 8;
            }
        }
        setFlagBits = setFlagBits | newBit;
    }
    lastGroupBit = 0;
    if (IsBackupFlagSet(0x10) == 0) {
        if (IsGrandPrixRecordFilledTopRank(3, 2) != FALSE && IsGrandPrixRecordFilledTopRank(7, 2) != FALSE) {
            SetBackupFlag(0x10);
            lastGroupBit = 0x10;
        }
    }
    return setFlagBits | lastGroupBit;
}

u32 SetSecretMessageFlagsFromCups3And7(void) {
    u32 setFlagBits;
    BOOL flag;
    setFlagBits = 0;
    flag = FALSE;
    if (IsBackupFlagSet(0x14) == 0) {
        if ((IsGrandPrixRecordFilled(3, 0) != 0 && GetGrandPrixRecordCupRank(3, 0) == 0) ? 1 : 0) {
            SetBackupFlag(0x14);
            flag = TRUE;
        }
    }
    if (flag != FALSE) {
        setFlagBits = setFlagBits | 0x20;
    }
    flag = FALSE;
    if (IsBackupFlagSet(0x15) == 0) {
        if ((IsGrandPrixRecordFilled(7, flag) != 0 && GetGrandPrixRecordCupRank(7, flag) == 0) ? 1 : 0) {
            SetBackupFlag(0x15);
            flag = TRUE;
        }
    }
    if (flag != FALSE) {
        setFlagBits = setFlagBits | 0x40;
    }
    flag = FALSE;
    if (IsBackupFlagSet(0x16) == 0) {
        if ((IsGrandPrixRecordFilled(7, 1) != 0 && GetGrandPrixRecordCupRank(7, 1) == 0) ? 1 : 0) {
            SetBackupFlag(0x16);
            flag = TRUE;
        }
    }
    if (flag != FALSE) {
        setFlagBits = setFlagBits | 0x80;
    }
    flag = FALSE;
    if (IsBackupFlagSet(0x17) == 0) {
        BOOL isFilledTopRank;
        if (IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto setSecretFlag;
        }
        if (IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        setSecretFlag:
            SetBackupFlag(0x17);
            flag = TRUE;
        }
    }
    if (flag != FALSE) {
        setFlagBits = setFlagBits | 0x100;
    }
    return setFlagBits;
}

// Returns 0 none, 1 the staff roll, 2 the true staff roll (all records top rank); both need cup 3 or 7 finished.
s32 GetStaffRollKindAfterGp(void) {
    MenuShared *menuShared;
    s32 result;
    s32 cupIndex;
    s32 engineClass;
    BOOL conditionMet;
    BOOL flag;
    result = STAFF_ROLL_AFTER_GP_NONE;
    menuShared = gMenuShared;
    engineClass = menuShared->mEngineIndex;
    cupIndex = menuShared->mCupIndex;
    if (menuShared->mMirrorMode != 0) {
        engineClass = 3;
    }
    conditionMet = FALSE;
    flag = AreAllGrandPrixRecordsTopRank();
    if (flag != FALSE) {
        if (cupIndex == 3 || cupIndex == 7) {
            if (gMenuShared->mCupRankIndex == 0) {
                conditionMet = TRUE;
            }
        }
    }
    if (conditionMet != FALSE) {
        result = STAFF_ROLL_AFTER_GP_TRUE;
    } else {
        conditionMet = FALSE;
        if (cupIndex == 3 || cupIndex == 7) {
            if (cupIndex == 7) {
                cupIndex = 3;
            } else {
                cupIndex = 7;
            }
            if (IsGrandPrixRecordFilled(cupIndex, engineClass) != 0 &&
                GetGrandPrixRecordCupRank(cupIndex, engineClass) <= 2) {
                flag = TRUE;
            } else {
                flag = FALSE;
            }
            if (flag != FALSE) {
                if (gMenuShared->mCupRankIndex <= CUP_RANK_TROPHY_COUNT - 1) {
                    conditionMet = TRUE;
                }
            }
        }
        if (conditionMet != FALSE) {
            result = STAFF_ROLL_AFTER_GP_NORMAL;
        }
    }
    return result;
}

BOOL IsAllGrandPrixRecordsTopRank(void) {
    return AreAllGrandPrixRecordsTopRank();
}

void LoadStaffGhostTime(void *heap) {
    LoadFileIntoHeap("/data/Ghost/staff_ghost_time.bin", heap, (void **) &gStaffGhostTime);
}

// TRUE when the time in milliseconds is below staff ghost time entryNumber - 1.
BOOL IsTimeLessThanStaffGhostTime(u32 entryNumber, MinuteSecondMillisecondTime *time) {
    return TIME_TO_MS(time->mMinute, time->mSecond, time->mMillisecond) < gStaffGhostTime[entryNumber - 1];
}

void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex) {
    Kart *kart;
    kart = GetKart(kartIndex);
    kartKillerCursor->mKillerKartIndex = kartIndex;
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartIndex,
                         (RacePointLink *) gKartItems[kartIndex].mItemLink.mLink);
    kartKillerCursor->mEndCount = 0;
    kartKillerCursor->mEndCountHoldTimer = 0;
    kart->mTurnAngle = 0;
    EndKartDrift(kart);
}

void ResetKartKillerCursorTo(KartKillerCursor *kartKillerCursor, RacePointLink *link) {
    if (link == kartKillerCursor->mPointLinkCursor.mPreviousLink) {
        return;
    }
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartKillerCursor->mKillerKartIndex, link);
}

BOOL AdvanceKartKillerCursor(KartKillerCursor *kartKillerCursor) {
    AdvanceKartKillerAlongPointLinks(kartKillerCursor);
    return AdvanceKartKillerEndCount(kartKillerCursor);
}

// Holds the kart at KART_KILLER_FORWARD_SPEED; when it is past the point link ahead (or, except with
// KART_DRIVE_BOOST_SURFACE_HELD on surface variant 1, within its distance) it moves the cursor on, otherwise it steers
// toward the link.
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor) {
    Kart *kart;
    Vec3 position;
    s32 isPastOrNearLink;
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    position = kart->mPos;
    kartKillerCursor->mAngleToLinkDegrees = ComputeAngleToPositionDegrees(
        kartKillerCursor->mPointLinkCursor.mLink->mPoint, &position, &kart->mRotationRow1, &kart->mRotationRow2);
    if ((kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD) != 0 && kart->mSurfaceVariant == 1) {
        isPastOrNearLink = IsPastPointLink(&kartKillerCursor->mPointLinkCursor, &position);
    } else {
        isPastOrNearLink = IsPastPointLink(&kartKillerCursor->mPointLinkCursor, &position);
        if (isPastOrNearLink == 0) {
            isPastOrNearLink = IsWithinPointLinkDistance(&kartKillerCursor->mPointLinkCursor, &position);
        }
    }
    kart->mForwardSpeed = KART_KILLER_FORWARD_SPEED;
    kart->mSpeedLimitGoal = kart->mForwardSpeed;
    kart->mSpeedLimit = kart->mSpeedLimitGoal;
    if (isPastOrNearLink != 0) {
        AdvancePointLinkCursorToFirstNext(&kartKillerCursor->mPointLinkCursor);
    } else {
        TurnKartKillerTowardPointLink(kartKillerCursor);
    }
}

// Turns the kart toward the point link ahead; the left and right keys first nudge the heading.
void TurnKartKillerTowardPointLink(KartKillerCursor *kartKillerCursor) {
    Kart *kart;
    s32 angleToLinkDegrees;
    s32 turnFactor;
    u16 padBits;
    u16 targetHeadingAngle;
    s32 angleDifference;
    s32 angleDifferenceAbs;
    s32 entryIndex;
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    angleToLinkDegrees = kartKillerCursor->mAngleToLinkDegrees;
    if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) != 0) {
        turnFactor = 0x19a;
    } else {
        turnFactor = 0x52;
    }
    targetHeadingAngle = kart->mHeadingAngle + (s16) MUL_FIXED12_ROUNDED(angleToLinkDegrees, 0xb6);
    entryIndex = *(volatile s32 *) &kart->mEntryIndex;
    padBits = gInputSlots[entryIndex].mBits;
    if ((u16) (padBits & PAD_KEY_DIRECTION_LEFT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle + 0xa0;
    } else if ((u16) (padBits & PAD_KEY_DIRECTION_RIGHT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle - 0xa0;
    }
    angleDifference = targetHeadingAngle - kart->mHeadingAngle;
    angleDifferenceAbs = angleDifference;
    angleDifferenceAbs = ABS(angleDifferenceAbs);
    if (angleDifferenceAbs > ANGLE_HALF_TURN - 1) {
        if (angleDifference > 0) {
            angleDifference = -(0xffff - angleDifference);
        } else {
            angleDifference = angleDifference + 0xffff;
        }
    }
    kart->mHeadingAngle = kart->mHeadingAngle + MUL_FIXED12_NO_ROUND(angleDifference, turnFactor);
}

BOOL AdvanceKartKillerEndCount(KartKillerCursor *kartKillerCursor) {
    BOOL limitReached;
    BOOL isCounting;
    Kart *kart;
    limitReached = FALSE;
    isCounting = FALSE;
    kartKillerCursor->mEndCountHoldTimer = kartKillerCursor->mEndCountHoldTimer - 1;
    if (kartKillerCursor->mEndCountHoldTimer <= 0) {
        kartKillerCursor->mEndCountHoldTimer = 0;
    } else {
        isCounting = TRUE;
    }
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    if ((kart->mMotionFlags & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT)) != 0) {
        isCounting = TRUE;
        kartKillerCursor->mEndCountHoldTimer = KART_KILLER_END_HOLD_FRAMES;
    }
    if (isCounting != FALSE) {
        kartKillerCursor->mEndCount = kartKillerCursor->mEndCount + 1;
        if (kartKillerCursor->mEndCount >= KART_KILLER_END_COUNT_FRAMES) {
            kartKillerCursor->mEndCount = 0;
            limitReached = TRUE;
        }
    } else if (kartKillerCursor->mEndCountHoldTimer <= 0) {
        kartKillerCursor->mEndCount = 0;
    }
    return limitReached;
}

// Stores the battle item entry tables and item callbacks for RaceSetup.mCpuDifficulty: easy and normal each have their
// own, every other value gets the hard set.
void SetupBattleItemEntries(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gBattleHeldItemEntries = gBattleEasyHeldItemEntries;
            gBattleItemInUseEntries = gBattleEasyItemInUseEntries;
            gThrowItemCircleKindCallback = EasyThrowItemRandomAfterInUse;
            gUseItemCircleKindCallback = UseItemAfterInUse;
            gThrowItemNotCircleKindCallback = ThrowItemRandomAfterInUse;
            gUseItemNotCircleKindCallback = UseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemRandomAfterInUseOrBehindNearTarget;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_NORMAL:
            gBattleHeldItemEntries = gBattleNormalHeldItemEntries;
            gBattleItemInUseEntries = gBattleNormalItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemRandomAfterInUseOrAtNearTarget;
            gUseItemCircleKindCallback = NormalUseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemRandomAfterInUse;
            gUseItemNotCircleKindCallback = UseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemRandomAfterInUseOrBehindNearTarget;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_HARD:
            gBattleHeldItemEntries = gBattleHardHeldItemEntries;
            gBattleItemInUseEntries = gBattleHardItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = UseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemAtNearTargetAfterInUseEveryCall;
            gUseItemNotCircleKindCallback = HardUseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemAtNearTargetAheadDotAfterInUse;
            gThrowItemNotTrailKindCallback = ThrowItemBehindNearTargetAfterInUseEveryCall;
            return;
        default:
            gBattleHeldItemEntries = gBattleHardHeldItemEntries;
            gBattleItemInUseEntries = gBattleHardItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = UseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemAtNearTargetAfterInUseEveryCall;
            gUseItemNotCircleKindCallback = HardUseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemAtNearTargetAheadDotAfterInUse;
            gThrowItemNotTrailKindCallback = ThrowItemBehindNearTargetAfterInUseEveryCall;
            return;
    }
}

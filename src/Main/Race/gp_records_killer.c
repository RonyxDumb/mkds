#include "Main/Race/gp_records_killer.h"
#include "Main/Menu/data_02175628.h"
#include "Main/System/archive_slots.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/data_0207e000.h"
#include "Main/MapObjects/data_0207f000.h"
#include "Main/Kart/code_0207ff5c.h"
#include "Main/Kart/code_02080b1c.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Kart/use_item.h"
#include "Main/Kart/code_02090088.h"
#include "Main/Kart/code_0208ffe4.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Scene/run_scenes.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Item/item_pool.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_021458c4.h"
#include "Main/MapObjects/sman_with.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/data_027e0000.h"
#include "Main/Kart/code_0207e654.h"
#include "code_02147cd8.h"
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
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 0x20, 0x1b},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 5, 0xa},
    {ThrowItemByTrailKind, 1, 0x20, 0x1b},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa}};
const KartAiItemUseEntry gBattleHardItemInUseEntries[14] = {
    {ThrowItemByCircleKind, 1, 5, 3},
    {UseItemByCircleKind, 1, 5, 3},
    {ThrowItemByTrailKind, 2, 1, 0},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 3, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 3, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 3, 0xa},
    {ThrowItemByTrailKind, 1, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 1, 3},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 3, 0xa}};
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
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 0x20, 0x1b},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 2, 5, 0xa},
    {ThrowItemByTrailKind, 1, 0x20, 0x1b},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa},
    {(KartAiItemHandler) BattleItemInUseReturnArgument, 0, 5, 0xa}};
const KartAiItemUseEntry gBattleHardHeldItemEntries[18] = {{(KartAiItemHandler) HardSetItemBitsEveryCall, 1, 1, 0},
                                                           {(KartAiItemHandler) HardSetItemBitsEveryCall, 1, 1, 0},
                                                           {(KartAiItemHandler) SetItemBitsEveryCall, 2, 1, 0},
                                                           {ThrowItemRandomAfterHeldOrAtNearTarget, 2, 1, 0},
                                                           {UseItemAfterHeldOrOnTargetIfTurnUnder10, 0, 3, 5},
                                                           {UseItemAndResetHeldTimerAfterHeldIfTurnUnder10, 0, 3, 5},
                                                           {(KartAiItemHandler) SetItemBitsEveryCall, 1, 1, 0},
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
    enum { K0 } cup;
    enum { L0 } engineClass;
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
    if (GetCurrentSceneNumber() == 10) {
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
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 2) != 0 && GetGrandPrixRecordCupRank(7, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
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
    enum { K0 } engineClass;
    u32 setFlagBits;
    u32 lastGroupBit;
    u32 newBit;
    s32 firstFlag;
    s32 secondFlag;
    s32 thirdFlag;
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
        firstFlag = engineClass + 4;
        if (IsBackupFlagSet(firstFlag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(2, engineClass) != FALSE) {
                SetBackupFlag(firstFlag);
                newBit = 2;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        secondFlag = engineClass + 8;
        if (IsBackupFlagSet(secondFlag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(4, engineClass) != FALSE &&
                IsGrandPrixRecordFilledTopRank(5, engineClass) != FALSE) {
                SetBackupFlag(secondFlag);
                newBit = 4;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        thirdFlag = engineClass + 12;
        if (IsBackupFlagSet(thirdFlag) == 0) {
            if (IsGrandPrixRecordFilledTopRank(6, engineClass) != FALSE) {
                SetBackupFlag(thirdFlag);
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
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
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
    result = 0;
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
        result = 2;
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
                if (gMenuShared->mCupRankIndex <= 2) {
                    conditionMet = TRUE;
                }
            }
        }
        if (conditionMet != FALSE) {
            result = 1;
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

// TRUE when the time is smaller than entry a - 1 of the staff ghost times.
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

// Holds the kart at a fixed speed, steers it toward the point link ahead, and moves the cursor on once the kart is past
// that link or close to it.
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
    kart->mForwardSpeed = 0xa800;
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
    if ((u16) (padBits & PAD_KEY_LEFT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle + 0xa0;
    } else if ((u16) (padBits & PAD_KEY_RIGHT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle - 0xa0;
    }
    angleDifference = targetHeadingAngle - kart->mHeadingAngle;
    angleDifferenceAbs = angleDifference;
    angleDifferenceAbs = (angleDifferenceAbs < 0) ? -angleDifferenceAbs : angleDifferenceAbs;
    if (angleDifferenceAbs > 0x7fff) {
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
        kartKillerCursor->mEndCountHoldTimer = 5;
    }
    if (isCounting != FALSE) {
        kartKillerCursor->mEndCount = kartKillerCursor->mEndCount + 1;
        if (kartKillerCursor->mEndCount >= 0x78) {
            kartKillerCursor->mEndCount = 0;
            limitReached = TRUE;
        }
    } else if (kartKillerCursor->mEndCountHoldTimer <= 0) {
        kartKillerCursor->mEndCount = 0;
    }
    return limitReached;
}

// Stores one of three sets of battle item entry tables and callbacks; any value other than 1 or 2 takes the third set.
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

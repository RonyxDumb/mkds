#pragma once

#include "types.h"

struct KartAiItemUse;
struct KartAi;

// Entry of the tables at gBattleItemInUseEntries, gCurrentItemInUseEntries and gCurrentHeldItemEntries, 0xc bytes: a
// function called with the KartAiItemUse and the KartAi at 0x00 and halfwords at 0x08 and 0x0a.
typedef void (*KartAiItemHandler)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);

// Values of KartAiItemUseEntry.mThenBitKind.
enum {
    KART_AI_THEN_BIT_NONE,
    KART_AI_THEN_BIT_THROW_FORWARD,
    KART_AI_THEN_BIT_THROW_BEHIND,
};

// One item use entry of the kart AI: the handler, which bits follow, and the timer base and random limit.
typedef struct KartAiItemUseEntry {
    /* 00 */ void (*mHandler)(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
// 0: item bits only; 1: then the bit 0x40 (ITEM_THROW_FORWARD_BIT); 2: then the bit 0x80.
    /* 04 */ s32 mThenBitKind;
    /* 08 */ u16 mTimerBase;
    /* 0a */ u16 mTimerRandomLimit;
} KartAiItemUseEntry;

// The state of a kart AI using items: the held item and item in use entries, their timers and the pending throw bits.
typedef struct KartAiItemUse {
    /* 00 */ s16 mHeldItemTimer;
    /* 02 */ s16 mItemInUseTimer;
    /* 04 */ const KartAiItemUseEntry *mHeldItemEntry;
    /* 08 */ const KartAiItemUseEntry *mItemInUseEntry;
    /* 0c */ s32 mHeldItemSeen;
// While non-zero, the item bits are requested on every call.
    /* 10 */ s32 mItemBitsEveryCall;
// While set, AdvanceItemBitRequests sends ITEM_THROW_FORWARD_BIT on its calls that do not run the entry function;
// mThrowForwardTimer (set to 2) counts those calls down.
    /* 14 */ s32 mThrowForwardPending;
// While set, AdvanceItemBitRequests sends the item bit 0x80 on its calls that do not run the entry function and no
// bit 0x40 is pending; mThrowBehindTimer (set to 2) counts those calls down.
    /* 18 */ s32 mThrowBehindPending;
    /* 1c */ s16 mThrowForwardTimer;
    /* 1e */ s16 mThrowBehindTimer;
    /* 20 */ s32 mRandomValue;
} KartAiItemUse;

void SetupBattleItemInUseEntry(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAndResetHeldTimerAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, struct KartAi *kartAi);
void BattleUseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemRandomMoreForwardAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemRandomAfterHeldOrBehindNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);

#include "Main/Unknown/code_02067f94.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a6b0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02077bc0.h"

void StartKartPushFlipOnHit(Kart *kart, const Vec3 *direction) {
    s32 canStart;
    BOOL isBlocked;
    s32 inOtherState;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mUnk_4c;
    if ((kartBits & KART_4C_BLINK_GUARD) != 0) {
        canStart = 0;
    } else if ((kart->mUnk_7c & 0x200) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mUnk_48 & 0x1800) == 0 && (kartBits & 0x10000040) == 0) {
            canStart = 1;
        } else {
            canStart = 0;
        }
    } else {
        isBlocked = TRUE;
        if ((kartBits & 0x10000040) == 0 && (kart->mUnk_48 & 0x1800) == 0) {
            inOtherState = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                inOtherState = isBlocked;
            }
            if (inOtherState == 0) {
                isBlocked = FALSE;
            }
        }
        canStart = isBlocked == FALSE ? 1 : 0;
    }
    if (canStart != 0) {
        StartKartState4(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mMapObjectHitCount++;
    }
    kart->mUnk_48 |= 0x20000;
}

void StartKartPushFlipOnHitByMapObject(Kart *kart, s32 direction, MapObject *mapObject) {
    if (TryStartKartState4(kart, mapObject) == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mMapObjectHitCount++;
    }
    kart->mUnk_48 |= 0x20000;
}

void StartKartPushDoubleFlipOnHit(Kart *kart, const Vec3 *direction) {
    s32 canStart;
    BOOL isBlocked;
    s32 inOtherState;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mUnk_4c;
    if ((kartBits & KART_4C_BLINK_GUARD) != 0) {
        canStart = 0;
    } else if ((kart->mUnk_7c & 0x200) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mUnk_48 & 0x1800) == 0 && (kartBits & 0x10000040) == 0) {
            canStart = 1;
        } else {
            canStart = 0;
        }
    } else {
        isBlocked = TRUE;
        if ((kartBits & 0x10000040) == 0 && (kart->mUnk_48 & 0x1800) == 0) {
            inOtherState = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                inOtherState = isBlocked;
            }
            if (inOtherState == 0) {
                isBlocked = FALSE;
            }
        }
        canStart = isBlocked == FALSE ? 1 : 0;
    }
    if (canStart != 0) {
        StartKartState5(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mMapObjectHitCount++;
    }
    kart->mUnk_48 |= 0x20000;
}

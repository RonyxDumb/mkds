#pragma once

#include "types.h"

typedef struct OamEntry OamEntry;

// 0xc bytes allocated by CreateAnimatedIcon.
typedef struct AnimatedIcon {
    /* 00 */ u32 mTask;
    /* 04 */ OamEntry *mOamEntry;
    /* 08 */ u8 mPaletteIndex;
    /* 09 */ u8 mStepFrames;
} AnimatedIcon;

// Message passed to ExchangeWcmNotifyCallback.
typedef struct WcmNoticeHead {
    /* 00 */ s16 mNotify;
    /* 02 */ s16 mResult;
} WcmNoticeHead;

extern AnimatedIcon *gAnimatedIcon;

BOOL InitExchangeWcm(void (*callback)(u32, u32), void *buffer, u32 size);
BOOL ConnectExchangeToEntry(void *entry, void *optionalBytes, u32 option);
BOOL CleanupExchangeWcm(void);
BOOL DisconnectExchange(void);
BOOL StartExchangeSearch(u8 *address, u8 *name, s32 nameLength, u32 option);
s32 CopyExchangeScanRecords(u8 *output, s32 maxCount);
BOOL StartExchangeReturnToIdle(void);
void ExchangeWcmNotifyCallback(WcmNoticeHead *message);
void AdvanceAnimatedIcon(void);
void ReleaseAnimatedIcon(void);
void CreateAnimatedIcon(int index);
void AdvanceButtonReset(u32 task);
void ReleaseSlideButtons(u32 task);

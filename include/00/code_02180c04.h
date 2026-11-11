#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// Object behind gWiFiLoginMenu (0x40 bytes).
typedef struct WiFiLoginMenu {
    /* 00 */ u32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mUnk_08;
    // Usually passed to RequestWiFiState right after it is stored; -1 until set.
    /* 0c */ s32 mPendingWiFiState;
    /* 10 */ s32 mMessageTableIndex;
    /* 14 */ BOOL mUnk_14;
    /* 18 */ s32 mErrorCode;
    /* 1c */ void *mHeap;
    /* 20 */ u8 pad_20[0x18];
    /* 38 */ struct Bmg *mWiFiMessages;
    /* 3c */ struct Bmg *mCommonMessages;
} WiFiLoginMenu;

extern WiFiStateCallbacks gWiFiLoginMenuCallbacks;
extern WiFiLoginMenu *gWiFiLoginMenu;

void RegisterWiFiLoginMenuCallbacks(void);
u32 WriteWiFiLoginMenuRegisters(void);
void AdvanceWiFiLoginMenu(void);
void AdvanceWiFiLoginMenuState9(void);
void AdvanceWiFiLoginMenuState8(void);
void AdvanceWiFiLoginMenuState7(void);
void AdvanceWiFiLoginMenuState6(void);
void AdvanceWiFiLoginMenuState5(void);
void AdvanceWiFiLoginMenuState4(void);
void AdvanceWiFiLoginMenuState3(void);
void AdvanceWiFiLoginMenuState2(void);
void AdvanceWiFiLoginMenuState1(void);
void AdvanceWiFiLoginMenuState0(void);
s32 LookupWiFiLoginErrorMessageIndex(s32 errorCode, s32 pageIndex, s32 *pageCountOut);
u32 GetWiFiSessionErrorCodeNegatedWrapper(void);
s32 CheckUserDataValidConsoleWrapper(void);
BOOL IsUserDataFriendKeyZero(void);
void InitWiFiLoginMenuNop(void);
void ClearWiFiLoginMenuPointer(void);
void InitWiFiLoginMenu(void *heap);

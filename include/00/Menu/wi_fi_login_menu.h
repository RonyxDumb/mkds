#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// Values of WiFiLoginMenu.mState and mNextState: which handler AdvanceWiFiLoginMenu runs.
enum {
    WIFI_LOGIN_MENU_STATE_START,
    WIFI_LOGIN_MENU_STATE_NO_FRIEND_KEY_ASK_LOGIN,
    WIFI_LOGIN_MENU_STATE_INVALID_CONSOLE_NOTICE,
    WIFI_LOGIN_MENU_STATE_INVALID_CONSOLE_ASK,
    WIFI_LOGIN_MENU_STATE_INVALID_CONSOLE_ASK_AGAIN,
    WIFI_LOGIN_MENU_STATE_SHOW_LOGGED_IN,
    WIFI_LOGIN_MENU_STATE_ASK_LOGIN,
    WIFI_LOGIN_MENU_STATE_WAIT_LOGIN,
    WIFI_LOGIN_MENU_STATE_ERROR_MESSAGES,
    WIFI_LOGIN_MENU_STATE_ERROR_CODE,
};

// The Wi-Fi login screen: its state, error code, heap and messages.
typedef struct WiFiLoginMenu {
    /* 00 */ u32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mUnk_08;
    // Usually passed to RequestWiFiState right after it is stored; -1 until set.
    /* 0c */ s32 mPendingWiFiState;
    /* 10 */ s32 mMessageTableIndex;
    /* 14 */ BOOL mShowLoggedInMessage;
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
void AdvanceWiFiLoginMenuErrorCode(void);
void AdvanceWiFiLoginMenuErrorMessages(void);
void AdvanceWiFiLoginMenuWaitLogin(void);
void AdvanceWiFiLoginMenuAskLogin(void);
void AdvanceWiFiLoginMenuShowLoggedIn(void);
void AdvanceWiFiLoginMenuInvalidConsoleConfirm(void);
void AdvanceWiFiLoginMenuInvalidConsoleAsk(void);
void AdvanceWiFiLoginMenuInvalidConsoleNotice(void);
void AdvanceWiFiLoginMenuAskLoginAfterInfo(void);
void AdvanceWiFiLoginMenuStart(void);
s32 LookupWiFiLoginErrorMessageIndex(s32 errorCode, s32 pageIndex, s32 *pageCountOut);
u32 GetWiFiSessionErrorCodeNegatedWrapper(void);
s32 CheckUserDataValidConsoleWrapper(void);
BOOL IsUserDataFriendKeyZero(void);
void InitWiFiLoginMenuNop(void);
void ClearWiFiLoginMenuPointer(void);
void InitWiFiLoginMenu(void *heap);

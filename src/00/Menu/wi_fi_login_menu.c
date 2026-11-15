#include "00/Menu/wi_fi_login_menu.h"

#include "00/code_02180608.h"
#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "Main/Net/wifi_session.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Net/led_pattern.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_02175628.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214cfe4.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/System/heap.h"
#include "Main/Menu/message_screen.h"
#include "Main/System/result_archive_path.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void InitWiFiLoginMenu(void *heap) {
    gWiFiLoginMenu = HeapAlloc(heap, 0x40);
    gWiFiLoginMenu->mHeap = heap;
    gWiFiLoginMenu->mState = WIFI_LOGIN_STATE_START;
    gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_START;
    gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_NONE;
    gWiFiLoginMenu->mUnk_08 = 0;
    gWiFiLoginMenu->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiLoginMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    InitWiFiLoginMenuNop();
    SetLinkLevelIconEnabled(1, 1);
    SetSelectReturnSoundId(0xe);
    SendLedPatternWireless();
}

void ClearWiFiLoginMenuPointer(void) {
    gWiFiLoginMenu = NULL;
}

void InitWiFiLoginMenuNop(void) {}

BOOL IsUserDataFriendKeyZero(void) {
    if (IsUserDataFriendKeyNonZero() == 0) {
        return TRUE;
    }
    return FALSE;
}

s32 CheckUserDataValidConsoleWrapper(void) {
    return CheckUserDataValidConsole();
}

u32 GetWiFiSessionErrorCodeNegatedWrapper(void) {
    u32 wiFiSessionErrorCodeNegated;
    u32 getterAddress;
    getterAddress = (u32) &GetWiFiSessionErrorCodeNegated;
    wiFiSessionErrorCodeNegated = GetWiFiSessionErrorCodeNegated();
    return wiFiSessionErrorCodeNegated;
}

WiFiLoginMenu *gWiFiLoginMenu;

WiFiStateCallbacks gWiFiLoginMenuCallbacks = {InitWiFiLoginMenu, ClearWiFiLoginMenuPointer, AdvanceWiFiLoginMenu,
                                              (void (*)(void)) WriteWiFiLoginMenuRegisters};

static inline s32 WiFiLoginMenuIsBackupBusy(void) {
    if (gBackupBuffers->mBusy == 0) {
        if (gBackupAccess->mBackupEnabled != 0) {
            return gBackupAccess->mCommandRunning;
        }
        return 0;
    }
    return 1;
}

s32 LookupWiFiLoginErrorMessageIndex(s32 errorCode, s32 pageIndex, s32 *pageCountOut) {
    u8 rowPageCounts[9] = {2, 2, 1, 2, 2, 2, 1, 2, 2};
    u16 rowMessageIndices[9][2] = {{0x15, 0x26}, {0x27, 0x26}, {0x28, 0},    {0x29, 0x16}, {0x15, 0x16},
                                   {0x2a, 0x2b}, {0x2c, 0},    {0x2d, 0x2e}, {0x2f, 0x2e}};
    s32 rowIndex = 0;
    s32 rowPageCount;
    if (errorCode == 0x4e8c) {
        rowIndex = 1;
    } else if (errorCode == 0x4e8e) {
        rowIndex = 2;
    } else if ((errorCode >= 0xc79b && errorCode <= 0xc79e) || (errorCode >= 0xc7a0 && errorCode <= 0xc7fe) ||
               (errorCode >= 0xc864 && errorCode <= 0xc8c6)) {
        rowIndex = 3;
    } else if ((errorCode >= 0xcb20 && errorCode <= 0xcb23) || (errorCode >= 0xcb84 && errorCode <= 0xcb87) ||
               (errorCode >= 0xcbe8 && errorCode <= 0xcbeb)) {
        rowIndex = 4;
    } else if (errorCode == 0xc79f) {
        rowIndex = 5;
    } else if (errorCode >= 0xc350 && errorCode <= 0xc3b3) {
        rowIndex = 6;
    } else if (errorCode == 0x4e85 || (errorCode >= 0x59d8 && errorCode <= 0x5dbf)) {
        rowIndex = 7;
    } else if (errorCode >= 0xc800 && errorCode <= 0xc863) {
        rowIndex = 8;
    }
    rowPageCount = rowPageCounts[rowIndex];
    *pageCountOut = rowPageCount;
    if (pageIndex >= rowPageCount) {
        return -1;
    }
    return rowMessageIndices[rowIndex][pageIndex];
}

void AdvanceWiFiLoginMenuState0(void) {
    if (IsUserDataFriendKeyZero() != FALSE) {
        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ASK_LOGIN_AFTER_INFO;
        SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x1c),
                                     GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
        gWiFiLoginMenu->mMessageTableIndex = 0;
        return;
    }
    if (CheckUserDataValidConsoleWrapper() != 0) {
        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ASK_LOGIN;
        SetupTxtSystemMainTextTwoButtons(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x13),
                                         GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 0),
                                         GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 1), 0);
        return;
    }
    gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_SETUP_NOTICE;
    SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x20),
                                 GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
}

void AdvanceWiFiLoginMenuState1(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 messageIndices[2] = {0, 0x1d};
        if (gWiFiLoginMenu->mMessageTableIndex < 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextButton(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(loginMenu->mCommonMessages, 6));
            return;
        }
        if (gWiFiLoginMenu->mMessageTableIndex == 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextTwoButtons(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 0), GetBmgEntry(loginMenu->mCommonMessages, 1), 0);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_WAIT_LOGIN;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            RequestWiFiSessionLogin();
            gWiFiLoginMenu->mShowLoggedInMessage = TRUE;
            StartWiFiSessionLoginSeq();
            return;
        }
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenuState2(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ASK_SETUP;
        SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x21),
                                     GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
        gWiFiLoginMenu->mMessageTableIndex = 0;
    }
}

void AdvanceWiFiLoginMenuState3(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 messageIndices[2] = {0, 0x22};
        if (gWiFiLoginMenu->mMessageTableIndex < 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextButton(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(loginMenu->mCommonMessages, 6));
            return;
        }
        if (gWiFiLoginMenu->mMessageTableIndex == 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextTwoButtons(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 0), GetBmgEntry(loginMenu->mCommonMessages, 1), 1);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_CONFIRM_SETUP;
            SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x23),
                                         GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
            gWiFiLoginMenu->mMessageTableIndex = 0;
            return;
        }
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenuState4(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 messageIndices[3] = {0, 0x24, 0x25};
        if (gWiFiLoginMenu->mMessageTableIndex < 1) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextButton(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(loginMenu->mCommonMessages, 6));
            return;
        }
        if (gWiFiLoginMenu->mMessageTableIndex == 1) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextTwoButtons(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 0), GetBmgEntry(loginMenu->mCommonMessages, 1), 1);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_WAIT_LOGIN;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            RequestWiFiSessionLogin();
            gWiFiLoginMenu->mShowLoggedInMessage = TRUE;
            StartWiFiSessionLoginSeq();
            return;
        }
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenuState5(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 messageIndices[2] = {0, 0x1f};
        if (gWiFiLoginMenu->mMessageTableIndex < 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextButton(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(loginMenu->mCommonMessages, 6));
            return;
        }
        if (gWiFiLoginMenu->mMessageTableIndex == 0) {
            gWiFiLoginMenu->mMessageTableIndex++;
            loginMenu = gWiFiLoginMenu;
            SetupTxtSystemMainTextButton(
                GetBmgEntry(loginMenu->mWiFiMessages, messageIndices[loginMenu->mMessageTableIndex]),
                GetBmgEntry(loginMenu->mCommonMessages, 4));
            return;
        }
        if (WiFiLoginMenuIsBackupBusy() == 0) {
            gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_VS_SETTING;
            RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiLoginMenuState6(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_WAIT_LOGIN;
            SetupTxtSystemMainTextEx(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            RequestWiFiSessionLogin();
            gWiFiLoginMenu->mShowLoggedInMessage = FALSE;
            StartWiFiSessionLoginSeq();
            return;
        }
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenuState7(void) {
    s32 pageCount;
    s32 messageIndex;
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (WiFiLoginMenuIsBackupBusy() == 0) {
            RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
            return;
        }
    }
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        switch (GetWiFiSessionLoginResult()) {
            case -1:
                gWiFiLoginMenu->mErrorCode = GetWiFiSessionErrorCodeNegatedWrapper();
                if (gWiFiLoginMenu->mErrorCode < 0) {
                    gWiFiLoginMenu->mErrorCode = -gWiFiLoginMenu->mErrorCode;
                }
                messageIndex = LookupWiFiLoginErrorMessageIndex(gWiFiLoginMenu->mErrorCode, 0, &pageCount);
                gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ERROR_MESSAGES;
                SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, messageIndex),
                                             GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
                gWiFiLoginMenu->mMessageTableIndex = 0;
                StartWiFiLoginErrorSeq();
                break;
            case 0:
                break;
            case 1:
                if (IsWiFiStatesCounterNotNegative() != 0) {
                    if (gWiFiLoginMenu->mShowLoggedInMessage != FALSE) {
                        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_SHOW_LOGGED_IN;
                        SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x1e),
                                                     GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
                        gWiFiLoginMenu->mMessageTableIndex = 0;
                    } else {
                        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_VS_SETTING;
                        RequestTxtSystemClose();
                    }
                }
                StartWiFiSessionLoginResult1Seq();
                break;
        }
    }
}

void AdvanceWiFiLoginMenuState8(void) {
    vu16 zero;
    s32 pageCount;
    u16 errorCodeText[10];
    u16 messageText[300];
    s32 messageIndex;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        gWiFiLoginMenu->mMessageTableIndex++;
        messageIndex = LookupWiFiLoginErrorMessageIndex(gWiFiLoginMenu->mErrorCode, gWiFiLoginMenu->mMessageTableIndex,
                                                        &pageCount);
        if (messageIndex != -1) {
            SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, messageIndex),
                                         GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
            return;
        }
        zero = 0;
        MIi_CpuClear16(zero, errorCodeText, 0x14);
        FormatAsciiNumber(gWiFiLoginMenu->mErrorCode, errorCodeText);
        FormatMessageWithText(errorCodeText, GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x30), messageText, 0x258);
        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ERROR_CODE;
        SetupTxtSystemMainText(messageText);
        RequestSelectReturnState1();
    }
}

void AdvanceWiFiLoginMenuState9(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    s32 pairRecentlyLost;
    BOOL pairNewUnlessRecentlyLost;
    u32 hasPair;
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairRecentlyLost = pairNewUnlessRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
                pairRecentlyLost = 1;
            }
            if (pairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE ||
                IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                goto next;
            }
        }
        RequestSelectReturnState3WithSound(0);
        RequestTxtSystemClose();
        return;
    }
next:
    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenu(void) {
    gWiFiLoginMenu->mState = gWiFiLoginMenu->mNextState;
    switch (gWiFiLoginMenu->mState) {
        case WIFI_LOGIN_STATE_START:
            AdvanceWiFiLoginMenuState0();
            break;
        case WIFI_LOGIN_STATE_ASK_LOGIN_AFTER_INFO:
            AdvanceWiFiLoginMenuState1();
            break;
        case WIFI_LOGIN_STATE_SETUP_NOTICE:
            AdvanceWiFiLoginMenuState2();
            break;
        case WIFI_LOGIN_STATE_ASK_SETUP:
            AdvanceWiFiLoginMenuState3();
            break;
        case WIFI_LOGIN_STATE_CONFIRM_SETUP:
            AdvanceWiFiLoginMenuState4();
            break;
        case WIFI_LOGIN_STATE_SHOW_LOGGED_IN:
            AdvanceWiFiLoginMenuState5();
            break;
        case WIFI_LOGIN_STATE_ASK_LOGIN:
            AdvanceWiFiLoginMenuState6();
            break;
        case WIFI_LOGIN_STATE_WAIT_LOGIN:
            AdvanceWiFiLoginMenuState7();
            break;
        case WIFI_LOGIN_STATE_ERROR_MESSAGES:
            AdvanceWiFiLoginMenuState8();
            break;
        case WIFI_LOGIN_STATE_ERROR_CODE:
            AdvanceWiFiLoginMenuState9();
            break;
    }
}

u32 WriteWiFiLoginMenuRegisters(void) {
    u32 keepMask;
    u32 registerAddress;
    u32 registerValue;
    registerAddress = 0x4001000u;
    registerValue = *(const u32 *) ((registerAddress) + 0u);
    keepMask = 0xffff1fffu;
    registerValue = (registerValue) & (keepMask);
    *(u32 *) ((registerAddress) + 0u) = registerValue;
    return keepMask;
}

void RegisterWiFiLoginMenuCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiLoginMenuCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}

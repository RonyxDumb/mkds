#include "00/Menu/wi_fi_login_menu.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Menu/wi_fi_states_release.h"
#include "00/Lib/wifi_library_globals.h"
#include "Main/Net/wifi_session.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Net/led_pattern.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Menu/select_return.h"
#include "Main/System/input_slots.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_clear_16.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/System/heap.h"
#include "Main/Menu/message_screen.h"
#include "Main/System/result_archive_path.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void InitWiFiLoginMenu(void *heap) {
    gWiFiLoginMenu = HeapAlloc(heap, sizeof(WiFiLoginMenu));
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

void AdvanceWiFiLoginMenuStart(void) {
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

void AdvanceWiFiLoginMenuAskLoginAfterInfo(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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

void AdvanceWiFiLoginMenuSetupNotice(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        gWiFiLoginMenu->mNextState = WIFI_LOGIN_STATE_ASK_SETUP;
        SetupTxtSystemMainTextButton(GetBmgEntry(gWiFiLoginMenu->mWiFiMessages, 0x21),
                                     GetBmgEntry(gWiFiLoginMenu->mCommonMessages, 6));
        gWiFiLoginMenu->mMessageTableIndex = 0;
    }
}

void AdvanceWiFiLoginMenuAskSetup(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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

void AdvanceWiFiLoginMenuConfirmSetup(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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

void AdvanceWiFiLoginMenuShowLoggedIn(void) {
    WiFiLoginMenu *loginMenu;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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

void AdvanceWiFiLoginMenuAskLogin(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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

void AdvanceWiFiLoginMenuWaitLogin(void) {
    s32 pageCount;
    s32 messageIndex;
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
        if (WiFiLoginMenuIsBackupBusy() == 0) {
            RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
            return;
        }
    }
    if (IsTxtSystemOpenNoCloseRequest() != 0) {
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

void AdvanceWiFiLoginMenuErrorMessages(void) {
    vu16 zero;
    s32 pageCount;
    u16 errorCodeText[10];
    u16 messageText[300];
    s32 messageIndex;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() != 0) {
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
        RequestSelectReturnSlideIn();
    }
}

void AdvanceWiFiLoginMenuErrorCode(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    s32 pairRecentlyLost;
    BOOL pairNewUnlessRecentlyLost;
    u32 hasPair;
    if (IsTxtSystemOpenNoCloseRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
            pairRecentlyLost = pairNewUnlessRecentlyLost = FALSE;
            hasPair = gInputSlots[slotIndex].mPair.mHasPair;
            if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                pairRecentlyLost = 1;
            }
            if (pairRecentlyLost == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
                pairNewUnlessRecentlyLost = TRUE;
            }
            if (pairNewUnlessRecentlyLost == FALSE ||
                IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                      gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
                goto next;
            }
        }
        RequestSelectReturnPressWithSound(0);
        RequestTxtSystemClose();
        return;
    }
next:
    if (IsTxtSystemClosedNoOpenRequest() != 0 && IsSelectReturnShownNoRequest() != 0) {
        gWiFiLoginMenu->mPendingWiFiState = WIFI_STATE_TOP_MENU;
        RequestWiFiState(gWiFiLoginMenu->mPendingWiFiState);
    }
}

void AdvanceWiFiLoginMenu(void) {
    gWiFiLoginMenu->mState = gWiFiLoginMenu->mNextState;
    switch (gWiFiLoginMenu->mState) {
        case WIFI_LOGIN_STATE_START:
            AdvanceWiFiLoginMenuStart();
            break;
        case WIFI_LOGIN_STATE_ASK_LOGIN_AFTER_INFO:
            AdvanceWiFiLoginMenuAskLoginAfterInfo();
            break;
        case WIFI_LOGIN_STATE_SETUP_NOTICE:
            AdvanceWiFiLoginMenuSetupNotice();
            break;
        case WIFI_LOGIN_STATE_ASK_SETUP:
            AdvanceWiFiLoginMenuAskSetup();
            break;
        case WIFI_LOGIN_STATE_CONFIRM_SETUP:
            AdvanceWiFiLoginMenuConfirmSetup();
            break;
        case WIFI_LOGIN_STATE_SHOW_LOGGED_IN:
            AdvanceWiFiLoginMenuShowLoggedIn();
            break;
        case WIFI_LOGIN_STATE_ASK_LOGIN:
            AdvanceWiFiLoginMenuAskLogin();
            break;
        case WIFI_LOGIN_STATE_WAIT_LOGIN:
            AdvanceWiFiLoginMenuWaitLogin();
            break;
        case WIFI_LOGIN_STATE_ERROR_MESSAGES:
            AdvanceWiFiLoginMenuErrorMessages();
            break;
        case WIFI_LOGIN_STATE_ERROR_CODE:
            AdvanceWiFiLoginMenuErrorCode();
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

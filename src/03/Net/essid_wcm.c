#include "03/Net/essid_packet_steps.h"
#include "03/Net/essid_wcm.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "reset_interrupt_enable.h"
#include "cpu_copy_fill.h"
#include "00/Lib/NitroWiFi/wcm_search_defaults.h"
#include "03/Net/exchange_result_records.h"
#include "03/Net/essid_packet_socket.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/DWC/socket_config.h"
#include "signed_int_divide.h"
#include "clock_chip_access.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/CPS/cps_globals.h"
#include "03/Menu/wifi_menu_strings.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "03/Net/poll_entry.h"

u32 gEssidSearchOption;
u32 gEssidConnectOption;
u8 *gEssidSearchAddress;
WCMConfig *gEssidWcmConfig;
WCMWepDesc *gEssidConnectBlock;
WCMWork *gEssidWcmWork;
u8 *gEssidSearchEssid;
s32 gEssidWcmState;
EssidEventCallback *gEssidEventCallback;
WMBssDesc *gEssidConnectRecord;
u8 gEssidSearchAddressBytes[6];
u8 gEssidSearchEssidBytes[0x20];

void EssidWcmNotifyCallback(s16 *event) {
    if (event == NULL) {
        return;
    }
    switch (event[0]) {
        case WIFI_NOTIFY_ENABLE_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_STARTUP_DONE, 0);
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_INITIALIZED;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SCAN_START_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    gEssidWcmState = EXCHANGE_WCM_STATE_SEARCHING;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_SEARCH_STARTED, 0);
                    }
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_SEARCH_START_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_CONNECT_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    gEssidWcmState = EXCHANGE_WCM_STATE_CONNECTED;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_CONNECTED, 0);
                    }
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_CONNECT_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SCAN_STOP_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_SEARCH_STOPPED, 0);
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    if (WCM_CleanupAsync() != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_SEARCH_STOP_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_DISCONNECT_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_DISCONNECTED, 0);
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    if (WCM_CleanupAsync() != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else if (gEssidWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                        }
                    }
                } else {
                    gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_DISCONNECT_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_POWER_OFF_REQUEST:
            if (event[1] == 0) {
                if (gEssidWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    WCM_Finish();
                    gEssidWcmState = EXCHANGE_WCM_STATE_STOPPED;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(EXCHANGE_EVENT_CLEANUP_DONE, 0);
                    }
                }
            } else {
                gEssidWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SEARCH_FOUND:
            if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCHING) {
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(EXCHANGE_EVENT_SEARCH_FOUND, 0);
                }
            }
            break;
        default:
            if (gEssidEventCallback != NULL) {
                gEssidEventCallback(EXCHANGE_EVENT_UNEXPECTED_NOTICE, 0);
            }
            break;
    }
}

BOOL StartEssidReturnToIdle(void) {
    switch (gEssidWcmState) {
        case EXCHANGE_WCM_STATE_SEARCHING:
            if (WCM_SearchAsync(NULL, NULL, 0) != 3) {
                return FALSE;
            }
            break;
        case EXCHANGE_WCM_STATE_CONNECTED:
            if (WCM_DisconnectAsync() != 3) {
                return FALSE;
            }
            break;
        case EXCHANGE_WCM_STATE_INITIALIZED:
            if (WCM_StartupAsync(gEssidWcmConfig, (void (*)(WCMNotice *)) EssidWcmNotifyCallback) != 3) {
                return FALSE;
            }
            break;
        case EXCHANGE_WCM_STATE_STOPPED:
        case EXCHANGE_WCM_STATE_CLEANING_UP:
        case EXCHANGE_WCM_STATE_IDLE:
        case EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING:
        case EXCHANGE_WCM_STATE_SEARCH_PENDING:
        case EXCHANGE_WCM_STATE_CONNECT_PENDING:
        default:
            return FALSE;
    }
    return TRUE;
}

s32 CopyEssidScanRecords(RawEntry *records, s32 maxCount) {
    s32 count;
    s32 recordIndex;
    WCM_LockApList(1);
    count = WCM_CountApList();
    if (count > 0) {
        for (recordIndex = 0; recordIndex < count; recordIndex++, records++) {
            if (recordIndex >= maxCount) {
                break;
            }
            MIi_CpuCopy32(WCM_PointApList(recordIndex), records, 0xc0);
        }
    }
    WCM_LockApList(0);
    return count;
}

BOOL StartEssidSearch(const u8 *addressBytes, const u8 *essidBytes, s32 essidLength, u32 option) {
    u32 enabled = OS_DisableInterrupts();
    s32 byteIndex;
    gEssidSearchOption = option;
    if (addressBytes != NULL) {
        for (byteIndex = 0; byteIndex < 6; byteIndex++) {
            gEssidSearchAddressBytes[byteIndex] = *addressBytes++;
        }
        gEssidSearchAddress = gEssidSearchAddressBytes;
    } else {
        MI_CpuFill8(gEssidSearchAddressBytes, 0xff, 6);
        gEssidSearchAddress = WCM_Bssid_Any;
    }
    if (essidBytes != NULL && essidLength > 0 && essidLength <= 0x20) {
        for (byteIndex = 0; byteIndex < essidLength; byteIndex++) {
            gEssidSearchEssidBytes[byteIndex] = *essidBytes++;
        }
        for (; byteIndex < 0x20; byteIndex++) {
            gEssidSearchEssidBytes[byteIndex] = 0;
        }
        gEssidSearchEssid = gEssidSearchEssidBytes;
    } else {
        MI_CpuFill8(gEssidSearchEssidBytes, 0xff, sizeof(gEssidSearchEssidBytes));
        gEssidSearchEssid = WCM_Essid_Any;
    }
    if (gEssidWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_SearchAsync(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) == 3) {
            gEssidWcmState = EXCHANGE_WCM_STATE_SEARCH_PENDING;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    } else if (StartEssidReturnToIdle() == TRUE) {
        gEssidWcmState = EXCHANGE_WCM_STATE_SEARCH_PENDING;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL EndEssidSearch(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == EXCHANGE_WCM_STATE_SEARCHING) {
        if (WCM_SearchAsync(NULL, NULL, 0) == 3) {
            gEssidWcmState = EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL DisconnectEssid(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == EXCHANGE_WCM_STATE_CONNECTED) {
        if (WCM_DisconnectAsync() == 3) {
            gEssidWcmState = EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL CleanupEssidWcm(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = EXCHANGE_WCM_STATE_CLEANING_UP;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    if (StartEssidReturnToIdle() == TRUE) {
        gEssidWcmState = EXCHANGE_WCM_STATE_CLEANING_UP;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL ConnectEssidToEntry(RawEntry *record, MelcoBlock *melcoBlock, u32 flags) {
    u32 enabled = OS_DisableInterrupts();
    gEssidConnectOption = flags;
    if (melcoBlock != NULL) {
        MI_CpuCopy8(melcoBlock, gEssidConnectBlock, 0x50);
    } else {
        MI_CpuFill8(gEssidConnectBlock, 0, 0x50);
    }
    MIi_CpuCopy32(record, gEssidConnectRecord, 0xc0);
    if (StartEssidReturnToIdle() == TRUE) {
        gEssidWcmState = EXCHANGE_WCM_STATE_CONNECT_PENDING;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    if (gEssidWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_ConnectAsync(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) == 3) {
            gEssidWcmState = EXCHANGE_WCM_STATE_CONNECT_PENDING;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL InitEssidWcm(EssidEventCallback *callback, u8 *buffer, s32 size) {
    u32 enabled = OS_DisableInterrupts();
    gEssidConnectBlock = (WCMWepDesc *) buffer;
    gEssidWcmConfig = (WCMConfig *) (((u32) buffer + 0x53) & ~3);
    gEssidWcmWork = (WCMWork *) (((u32) gEssidWcmConfig + 0x2f) & ~0x1f);
    gEssidConnectRecord = (WMBssDesc *) (((u32) gEssidWcmWork + 0x231f) & ~0x1f);
    gEssidWcmConfig->mPbdBuffer = (u8 *) (((u32) gEssidConnectRecord + 0xdf) & ~0x1f);
    gEssidWcmConfig->mNbdBuffer = (buffer + size) - gEssidWcmConfig->mPbdBuffer;
    gEssidWcmConfig->mNbdMode = 0;
    gEssidWcmConfig->mDmaNo = EXCHANGE_WCM_DMA_NO;
    gEssidEventCallback = callback;
    if (gEssidWcmState == EXCHANGE_WCM_STATE_STOPPED) {
        if (WCM_Init(gEssidWcmWork, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = EXCHANGE_WCM_STATE_INITIALIZED;
    }
    if (gEssidWcmState == EXCHANGE_WCM_STATE_INITIALIZED) {
        if (WCM_StartupAsync(gEssidWcmConfig, (void (*)(WCMNotice *)) EssidWcmNotifyCallback) != 3) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

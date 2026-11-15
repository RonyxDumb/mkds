#include "03/Net/essid_packet_steps.h"
#include "03/Net/essid_wcm.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/Lib/NitroWiFi/wcm_search_defaults.h"
#include "03/Net/exchange_result_records.h"
#include "03/Net/essid_packet_socket.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/DWC/code_0218a064.h"
#include "code_02133048.h"
#include "code_0214d93c.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/NitroWiFi/code_021a8aa8.h"
#include "00/Lib/CPS/cps_globals.h"
#include "03/Menu/wifi_menu_strings.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "03/Net/poll_entry.h"

MaskCodeEntry gMaskCodeTable[12] = {{1, 2, 0},        {2, 4, 0},        {4, 0xb, 0},      {8, 0xc, 0},
                                    {0x10, 0x12, 0},  {0x20, 0x16, 0},  {0x40, 0x18, 0},  {0x80, 0x24, 0},
                                    {0x100, 0x30, 0}, {0x200, 0x48, 0}, {0x400, 0x60, 0}, {0x800, 0x6c, 0}};
u8 gEssidAossString[11] = "ESSID-AOSS";
s8 gMelcoString[6] = "MELCO";
void *(*gEssidAllocFunction)(u32);
void (*gStateChangeCallback)(s32);
void *gEssidWorkBuffer;
void (*gEssidFreeFunction)(void *);
void *gMessageQueueSlots[4];
OSMessageQueue gMessageQueue;
MelcoBlock gMelcoBlock;
RawEntry gMelcoRecord __attribute__((aligned(32)));

void ConvertRecordToEssidEntry(RawEntry *src, EssidEntry *dst) {
    int rateIndex;
    int count;
    int mode;
    dst->mEssidLength = src->mSsidLength;
    MIi_CpuCopy16(src->mSsid, dst->mEssid, 0x20);
    dst->mChannel = src->mChannel;
    MIi_CpuCopy16(&src->mAddress, dst->mAddress, 6);
    count = 0;
    for (rateIndex = 0; rateIndex < 12; rateIndex++) {
        if (src->mSupportRateSet & gMaskCodeTable[rateIndex].mMask) {
            dst->mCodes[count] = gMaskCodeTable[rateIndex].mCode;
            if (src->mBasicRateSet & gMaskCodeTable[rateIndex].mMask) {
                dst->mCodes[count] |= ESSID_RATE_CODE_BASIC;
            }
            count++;
        }
    }
    dst->mCodeCount = count;
    dst->mBeaconPeriod = src->mBeaconPeriod;
    mode = src->mFlags & RAW_ENTRY_MODE_MASK;
    if (mode == 1) {
        dst->mMode = 1;
    } else if (mode == 2) {
        dst->mMode = 2;
    } else {
        dst->mMode = 0;
    }
}

void SetRecordEssidFromRequest(EssidMelcoRequest *request, RawEntry *rec) {
    vu16 zero = 0;
    MIi_CpuClear16(zero, rec->mSsid, 0x20);
    rec->mSsidLength = request->mEssidLength;
    MI_CpuCopy8(request->mEssid, rec->mSsid, rec->mSsidLength);
}

void FillEssidEntryListFromRecord(EssidEntryList *list, RawEntry *src, s32 count) {
    list->mCount = count;
    ConvertRecordToEssidEntry(src, list->mEntries);
}

s32 SendQueueMessage(void *msg) {
    return OS_SendMessage(&gMessageQueue, msg, 0);
}

s32 AlarmSendQueueMessage(void *msg) {
    return OS_SendMessage(&gMessageQueue, msg, 0);
}

s32 InitEssidWiFi(void *(*alloc)(u32), void (*release)(void *)) {
    BOOL running = TRUE;
    void *msg;
    void *buffer;
    u32 enabled;
    OS_InitMessageQueue(&gMessageQueue, gMessageQueueSlots, 4);
    if (alloc == NULL || release == NULL) {
        return -1;
    }
    enabled = OS_DisableInterrupts();
    gEssidAllocFunction = alloc;
    gEssidFreeFunction = release;
    OS_RestoreInterrupts(enabled);
    buffer = gEssidAllocFunction(0x5890);
    gEssidWorkBuffer = buffer;
    if (buffer == NULL) {
        return -1;
    }
    if (InitEssidWcm(SendQueueMessage, buffer, 0x5890) == FALSE) {
        running = FALSE;
    }
    if (running != FALSE) {
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case EXCHANGE_EVENT_SCAN_ROUND:
                case EXCHANGE_EVENT_SEARCH_FOUND:
                    break;
                case EXCHANGE_EVENT_STARTUP_DONE:
                    return 0;
                case EXCHANGE_EVENT_SEARCH_STARTED:
                case EXCHANGE_EVENT_SEARCH_STOPPED:
                case EXCHANGE_EVENT_CONNECTED:
                case EXCHANGE_EVENT_CONNECT_FAILED:
                case EXCHANGE_EVENT_DISCONNECT_FAILED:
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
    }
    gEssidFreeFunction(gEssidWorkBuffer);
    return -1;
}

s32 ReleaseEssidWiFi(void) {
    s32 result;
    BOOL running;
    void *msg;
    u32 enabled;
    running = TRUE;
    result = -1;
    if (gEssidFreeFunction == NULL) {
        return -1;
    }
    if (CleanupEssidWcm() == FALSE) {
        return -1;
    }
    do {
        OS_ReceiveMessage(&gMessageQueue, &msg, 1);
        switch ((u32) msg) {
            case EXCHANGE_EVENT_SCAN_ROUND:
            case EXCHANGE_EVENT_SEARCH_FOUND:
                break;
            case EXCHANGE_EVENT_CLEANUP_DONE:
                running = FALSE;
                result = 0;
                gEssidFreeFunction(gEssidWorkBuffer);
                break;
            case EXCHANGE_EVENT_SEARCH_STARTED:
            case EXCHANGE_EVENT_SEARCH_STOPPED:
            case EXCHANGE_EVENT_CONNECTED:
            case EXCHANGE_EVENT_CONNECT_FAILED:
            case EXCHANGE_EVENT_CONNECT_TIMEOUT:
            case EXCHANGE_EVENT_SEARCH_TIMEOUT:
            default:
                running = FALSE;
                break;
        }
    } while (running != FALSE);
    enabled = OS_DisableInterrupts();
    gEssidAllocFunction = NULL;
    gEssidFreeFunction = NULL;
    OS_RestoreInterrupts(enabled);
    return result;
}

s32 DisconnectEssidAndWait(void) {
    BOOL done;
    s32 result = -1;
    void *msg;
    if (DisconnectEssid() != FALSE) {
        done = FALSE;
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            /* waits for one entry */
            if ((u32) msg == EXCHANGE_EVENT_DISCONNECTED) {
                result = 0;
                done = FALSE;
            }
        } while (done != FALSE);
    }
    return result;
}

s32 ScanEssidEntries(EssidEntryList **out) {
    BOOL found = FALSE;
    s32 result = -1;
    BOOL running = TRUE;
    s32 count = 0;
    s32 waits = 0;
    RawEntry *scan;
    RawEntry *buffer;
    EssidEntryList *list;
    void *msg;
    OSAlarm timer;
    s32 entryIndex;
    if (gEssidAllocFunction == NULL || gEssidFreeFunction == NULL) {
        return -1;
    }
    scan = gEssidAllocFunction(0x3000);
    if (scan == NULL) {
        return -1;
    }
    buffer = scan;
    if (StartEssidSearch(NULL, NULL, 0, 0x30bffe) != 0) {
        OS_CreateAlarm(&timer);
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) AlarmSendQueueMessage, (void *) EXCHANGE_EVENT_SEARCH_TIMEOUT);
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case EXCHANGE_EVENT_SEARCH_TIMEOUT:
                    if (found == FALSE) {
                        if (waits != 0) {
                            count = CopyEssidScanRecords(scan, 0x40);
                        }
                        if (EndEssidSearch() == FALSE) {
                            goto cleanup;
                        }
                        found = TRUE;
                    }
                    break;
                case EXCHANGE_EVENT_SEARCH_FOUND:
                    if (found == FALSE) {
                        if (waits < 8) {
                            waits++;
                        } else {
                            count = CopyEssidScanRecords(scan, 0x40);
                            if (EndEssidSearch() == FALSE) {
                                goto cleanup;
                            }
                            found = TRUE;
                        }
                    }
                    break;
                case EXCHANGE_EVENT_SEARCH_STOPPED:
                    running = FALSE;
                    result = 0;
                    break;
                case EXCHANGE_EVENT_SCAN_ROUND:
                case EXCHANGE_EVENT_SEARCH_STARTED:
                case EXCHANGE_EVENT_CONNECT_TIMEOUT:
                    break;
                case EXCHANGE_EVENT_CONNECTED:
                case EXCHANGE_EVENT_CONNECT_FAILED:
                default:
                    goto cleanup;
            }
        } while (running != FALSE);
        if (count != 0) {
            list = gEssidAllocFunction((count - 1) * 0x54 + 0x58);
            if (list == NULL) {
                goto cleanup;
            }
        } else {
            list = gEssidAllocFunction(0x58);
            if (list == NULL) {
                goto cleanup;
            }
        }
        *out = list;
        list->mCount = count;
        for (entryIndex = 0; entryIndex < count; entryIndex++) {
            ConvertRecordToEssidEntry(scan, &list->mEntries[entryIndex]);
            scan++;
        }
    cleanup:
        OS_CancelAlarm(&timer);
        while (OS_ReceiveMessage(&gMessageQueue, &msg, 0) == 1) {
        }
    }
    gEssidFreeFunction(buffer);
    return result;
}

s32 RunEssidMelcoRequest(EssidMelcoRequest *request, EssidEntryList *out) {
    BOOL running = TRUE;
    s32 result;
    s32 retries;
    BOOL done;
    u32 flags;
    void *msg;
    OSAlarm timer;
    done = FALSE;
    result = -1;
    if (request->mUseSharedKey == FALSE) {
        flags = 0x80000;
    } else if (request->mUseSharedKey == TRUE) {
        flags = 0xc0000;
    }
    MI_CpuFill8(&gMelcoBlock, 0, sizeof(MelcoBlock));
    if (request->mMelcoLength == sizeof(WepKey5)) {
        gMelcoBlock.mLengthKind = MELCO_LENGTH_KIND_WEP_KEY_5_BYTES;
    } else if (request->mMelcoLength == sizeof(WepKey13)) {
        gMelcoBlock.mLengthKind = MELCO_LENGTH_KIND_WEP_KEY_13_BYTES;
    } else if (request->mMelcoLength == sizeof(WepKey16)) {
        gMelcoBlock.mLengthKind = MELCO_LENGTH_KIND_WEP_KEY_16_BYTES;
    } else {
        return -1;
    }
    gMelcoBlock.mUnk_01 = 0;
    MI_CpuCopy8(request->mMelcoBytes, gMelcoBlock.mMelcoBytes, request->mMelcoLength);
    WCM_ClearApList();
    if (StartEssidSearch(NULL, request->mEssid, request->mEssidLength, 0x30bffe) != 0) {
        retries = 0;
        OS_CreateAlarm(&timer);
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) AlarmSendQueueMessage,
                    (void *) EXCHANGE_EVENT_CONNECT_TIMEOUT);
        flags |= 0x30000;
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case EXCHANGE_EVENT_CONNECT_TIMEOUT:
                    if (done == FALSE) {
                        running = FALSE;
                    }
                    break;
                case EXCHANGE_EVENT_SEARCH_FOUND:
                    if (done == FALSE) {
                        OS_CancelAlarm(&timer);
                        if (CopyEssidScanRecords(&gMelcoRecord, 1) != 1) {
                            running = FALSE;
                        } else {
                            SetRecordEssidFromRequest(request, &gMelcoRecord);
                            if (ConnectEssidToEntry(&gMelcoRecord, &gMelcoBlock, flags) == FALSE) {
                                running = FALSE;
                            } else {
                                done = TRUE;
                            }
                        }
                    }
                    break;
                case EXCHANGE_EVENT_SEARCH_STOPPED:
                    SetRecordEssidFromRequest(request, &gMelcoRecord);
                    if (ConnectEssidToEntry(&gMelcoRecord, &gMelcoBlock, flags) == FALSE) {
                        running = FALSE;
                    }
                    break;
                case EXCHANGE_EVENT_CONNECTED:
                    result = 0;
                    running = FALSE;
                    break;
                case EXCHANGE_EVENT_CONNECT_FAILED:
                    retries++;
                    if (retries < 3) {
                        if (ConnectEssidToEntry(&gMelcoRecord, &gMelcoBlock, flags) == FALSE) {
                            running = FALSE;
                        }
                    } else {
                        running = FALSE;
                    }
                    break;
                case EXCHANGE_EVENT_SCAN_ROUND:
                case EXCHANGE_EVENT_SEARCH_STARTED:
                case EXCHANGE_EVENT_SEARCH_TIMEOUT:
                    break;
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
        OS_CancelAlarm(&timer);
        while (OS_ReceiveMessage(&gMessageQueue, &msg, 0) == 1) {
        }
    }
    FillEssidEntryListFromRecord(out, &gMelcoRecord, result == 0 ? 1 : 0);
    return result;
}

void EssidSleepWrapper(u32 msec) {
    OS_Sleep(msec);
}

int CallStateChangeCallback(int state) {
    // nothing in the game sets this pointer
    if (gStateChangeCallback != NULL) {
        gStateChangeCallback(state);
    }
    return 0;
}

void *CallEssidAllocFunction(u32 size) {
    return gEssidAllocFunction(size);
}

void CallEssidFreeFunction(void *ptr) {
    gEssidFreeFunction(ptr);
}

#include "03/Net/essid_packet_steps.h"
#include "03/code_021ba818.h"
#include "00/code_021a5db0.h"
#include "00/code_021a5e84.h"
#include "00/code_021a61c4.h"
#include "00/code_021a61e4.h"
#include "00/code_021a629c.h"
#include "00/code_021a6428.h"
#include "00/code_021a6470.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "00/code_021a6788.h"
#include "00/code_021a67dc.h"
#include "00/code_021a6844.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/unk_021b0000.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "03/code_021b7bb4.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/DWC/code_0218a064.h"
#include "code_02133048.h"
#include "code_0214d93c.h"
#include "00/Lib/CPS/network.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"
#include "03/unk_021d7000.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "03/code_021b7ba8.h"

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
                dst->mCodes[count] |= 0x80;
            }
            count++;
        }
    }
    dst->mCodeCount = count;
    dst->mBeaconPeriod = src->mBeaconPeriod;
    mode = src->mFlags & 3;
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
                case 4:
                case 5:
                    break;
                case 6:
                    return 0;
                case 8:
                case 0xa:
                case 0xc:
                case 0xd:
                case 0xf:
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
            case 4:
            case 5:
                break;
            case 0x14:
                running = FALSE;
                result = 0;
                gEssidFreeFunction(gEssidWorkBuffer);
                break;
            case 8:
            case 0xa:
            case 0xc:
            case 0xd:
            case 0x12:
            case 0x13:
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
            if ((u32) msg == 0xe) {
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
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) AlarmSendQueueMessage, (void *) 0x13);
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case 0x13:
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
                case 5:
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
                case 0xa:
                    running = FALSE;
                    result = 0;
                    break;
                case 4:
                case 8:
                case 0x12:
                    break;
                case 0xc:
                case 0xd:
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
    MI_CpuFill8(&gMelcoBlock, 0, 0x60);
    if (request->mMelcoLength == 5) {
        gMelcoBlock.mLengthKind = 1;
    } else if (request->mMelcoLength == 0xd) {
        gMelcoBlock.mLengthKind = 2;
    } else if (request->mMelcoLength == 0x10) {
        gMelcoBlock.mLengthKind = 3;
    } else {
        return -1;
    }
    gMelcoBlock.mUnk_01 = 0;
    MI_CpuCopy8(request->mMelcoBytes, gMelcoBlock.mMelcoBytes, request->mMelcoLength);
    WCM_ClearApList();
    if (StartEssidSearch(NULL, request->mEssid, request->mEssidLength, 0x30bffe) != 0) {
        retries = 0;
        OS_CreateAlarm(&timer);
        OS_SetAlarm(&timer, 0x3fec42, (void (*)(void *)) AlarmSendQueueMessage, (void *) 0x12);
        flags |= 0x30000;
        do {
            OS_ReceiveMessage(&gMessageQueue, &msg, 1);
            switch ((u32) msg) {
                case 0x12:
                    if (done == FALSE) {
                        running = FALSE;
                    }
                    break;
                case 5:
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
                case 0xa:
                    SetRecordEssidFromRequest(request, &gMelcoRecord);
                    if (ConnectEssidToEntry(&gMelcoRecord, &gMelcoBlock, flags) == FALSE) {
                        running = FALSE;
                    }
                    break;
                case 0xc:
                    result = 0;
                    running = FALSE;
                    break;
                case 0xd:
                    retries++;
                    if (retries < 3) {
                        if (ConnectEssidToEntry(&gMelcoRecord, &gMelcoBlock, flags) == FALSE) {
                            running = FALSE;
                        }
                    } else {
                        running = FALSE;
                    }
                    break;
                case 4:
                case 8:
                case 0x13:
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

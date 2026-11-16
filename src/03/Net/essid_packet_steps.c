#include "03/Net/essid_packet_steps.h"
#include "03/Net/essid_wcm.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "03/Net/exchange_result_records.h"
#include "03/Net/essid_packet_socket.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/DWC/socket_config.h"
#include "signed_int_divide.h"
#include "clock_chip_access.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/CPS/stack_globals.h"
#include "03/Menu/wifi_menu_strings.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "03/Net/poll_entry.h"
#include "03/Net/essid_wifi_session.h"

SOCConfig gEssidSocketConfig = {{0, 0, 0, 1},
                                (SocketAllocFn) AllocSocketMemory,
                                FreeSocketMemory,
                                0,
                                0,
                                0,
                                0,
                                0,
                                0,
                                0x1000,
                                0x1000,
                                0,
                                0,
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                NULL,
                                0,
                                0,
                                0};
u8 gItemTypesToFind[2] = {PACKET_GROUP_ITEM_FIRST, PACKET_GROUP_ITEM_SECOND};
s32 gReportedState = -1;
s32 gSocketDescriptor = -1;
RetryLimit gRetryLimitTemplate = {-1, -1};
s32 gRandomSeeded;
EssidEntryList *gScannedEssidList;
s32 gUseKeyStream;
EssidEntryList *gRequestedEssidList;
PacketBuffer *gRequestPacketBuffer;
s32 gErrorCode;
u8 gSavedTagBytes[8];
u32 gRandomState[3];
RequestState gRequestState;
u8 gKeyStreamKey[0x64];
u8 gItemSlots[0x280];
u32 gCrcTable[0x100];
ParsedItems gParsedItems[2];

s32 RunValueRecordsRequest(ValueRecordsRequest *req) {
    s32 status;
    s32 ret;
    if (req->mScanRetryLimit == 0 || req->mScanRetryLimit < -1 || req->mScanRetryDelayMs < -1 ||
        req->mSendAttemptLimit == 0 || req->mSendAttemptLimit < -1 || req->mSendAttemptDelayMs < -1 ||
        req->mReceiveTimeoutMs < -1 || req->mItem.mItemLength == 0 || req->mItem.mItemLength > 0x100 ||
        req->mItem.mItemBytes[req->mItem.mItemLength - 1] != 0) {
        status = -1;
    } else {
        status = 0;
    }
    if (gEssidAllocFunction == NULL || gEssidFreeFunction == NULL) {
        status = -1;
    }
    if (status == -1) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    gRequestPacketBuffer = CallEssidAllocFunction(0x5f8);
    if (gRequestPacketBuffer == NULL) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    ReportStateChange(-1);
    ret = RunValueRecordsRequestSteps(req);
    CallEssidFreeFunction(gRequestPacketBuffer);
    ReleaseEssidEntryLists();
    if (gSocketDescriptor != -1) {
        CloseSocket(gSocketDescriptor);
    }
    return ret;
}

s32 RunValueRecordsRequestSteps(ValueRecordsRequest *req) {
    s16 timeout;
    s32 step;
    s32 nextStep;
    s32 addr;
    PacketBuffer *buffer;
    s32 scanResult;
    s32 result;
    RetryLimit scanRetry = gRetryLimitTemplate;
    RetryLimit limits = {0, 0};
    s32 value = 1;
    s32 attempts;
    s32 ret;
    u8 resultCode;
    s16 retryCount;
    s16 scanDelayMs;
    SocketAddress senderAddress;
    s32 srcLen;
    s32 received;
    PollEntry set;
    WaitTimeout wait;
    SocketAddress bindAddress;
    PacketTag tags[3];
    EssidMelcoRequest melcoRequest;
    SendPacketScratch sendScratch;

    step = 0;
    attempts = step;
    addr = step;
    FillBytes(tags, 0, sizeof(tags));
    scanRetry.mCount = req->mScanRetryLimit;
    if (scanRetry.mCount == -1) {
        scanRetry.mCount = ESSID_REQUEST_DEFAULT_COUNT;
    }
    limits.mCount = req->mSendAttemptLimit;
    if (limits.mCount == -1) {
        limits.mCount = ESSID_REQUEST_DEFAULT_COUNT;
    }
    scanRetry.mDelayMs = req->mScanRetryDelayMs;
    if (scanRetry.mDelayMs == -1) {
        scanRetry.mDelayMs = ESSID_REQUEST_DEFAULT_DELAY_MS;
    }
    limits.mDelayMs = req->mSendAttemptDelayMs;
    if (limits.mDelayMs == -1) {
        limits.mDelayMs = ESSID_REQUEST_DEFAULT_DELAY_MS;
    }
    timeout = req->mReceiveTimeoutMs;
    if (timeout == -1) {
        timeout = 2000;
    }
    InitRequestState(req);
    if ((gRequestState.mWantedRecordMask & VALUE_RECORD_MASK_KEY_SET_FIRST) != VALUE_RECORD_MASK_KEY_SET_FIRST) {
        SetErrorCode(ESSID_ERROR_FIRST_RECORD_NOT_WANTED);
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }

    retryCount = 0;
    ReportStateChange(0);
    scanDelayMs = scanRetry.mDelayMs;
    while (1) {
        if (gScannedEssidList != NULL) {
            CallEssidFreeFunction(gScannedEssidList);
            gScannedEssidList = NULL;
        }
        if (ScanEssidEntries(&gScannedEssidList) == -1) {
            req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
            ReleaseEssidEntryLists();
            return -1;
        }
        result = CheckSingleEssidAossEntry(gScannedEssidList);
        if (result == 4) {
            req->mResultCode = VALUE_RECORDS_RESULT_ENTRY_REJECTED;
            ReleaseEssidEntryLists();
            return -1;
        }
        if (result == 0) {
            break;
        }
        if (retryCount >= scanRetry.mCount) {
            req->mResultCode = VALUE_RECORDS_RESULT_NO_ENTRY_FOUND;
            ReleaseEssidEntryLists();
            return -1;
        }
        EssidSleepWrapper(scanDelayMs);
        retryCount++;
    }

    ReportStateChange(1);
    FillBytes(&melcoRequest, 0, 0x3c);
    if (FillEssidAossAndMelcoRequest(&melcoRequest) != 0) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    gRequestedEssidList = CallEssidAllocFunction(0x58);
    if (gRequestedEssidList == NULL) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    FillBytes(gRequestedEssidList, 0, 0x58);
    retryCount = 0;
    if (scanRetry.mCount > 0) {
        do {
            result = RunEssidMelcoRequest(&melcoRequest, gRequestedEssidList);
            if (result == -1) {
                req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                ReleaseEssidEntryLists();
                return -1;
            }
            if (result == 0) {
                if (result != 0 || gRequestedEssidList->mCount == 1) {
                    break;
                }
            }
            EssidSleepWrapper(scanDelayMs);
            retryCount++;
        } while (retryCount < scanRetry.mCount);
    }
    if (retryCount == scanRetry.mCount) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (StartSocketsWithAddress(ESSID_REQUEST_OWN_ADDRESS, 0xffffff00, ESSID_REQUEST_OWN_ADDRESS) != 0) {
        SetErrorCode(ESSID_ERROR_START_SOCKETS);
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    ReleaseEssidEntryLists();
    FillPacketTags(3, tags, req->mMacAddress);
    gSocketDescriptor = OpenSocket(2, 2, 0);
    if (gSocketDescriptor < 0) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (SocketReturnArgument(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
        SetErrorCode(ESSID_ERROR_SOCKET_OPTION);
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    FillBytes(&bindAddress, 0, 8);
    bindAddress.mFamily = SOCKET_FAMILY_IPV4;
    bindAddress.mAddress = SwapBytes32(ESSID_REQUEST_OWN_ADDRESS);
    bindAddress.mPort = PacketSwapBytes16(0x5790);
    if (BindSocket(gSocketDescriptor, &bindAddress, 8) < 0) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }

    while (1) {
        buffer = gRequestPacketBuffer;
        FillBytes(&sendScratch, 0, 0x14);
        sendScratch.mOwnAddress = ESSID_REQUEST_OWN_ADDRESS;
        sendScratch.mDestinationAddress = ESSID_REQUEST_FIRST_DESTINATION_ADDRESS;
        while (1) {
            if (step == ESSID_REQUEST_STEP_WANTED_MASK && gRequestState.mAddressApplied != 1) {
                if (gSocketDescriptor != -1) {
                    CloseSocket(gSocketDescriptor);
                }
                gSocketDescriptor = -1;
                if (StopSocketsAndDisconnectEssid() != 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (gScannedEssidList != NULL) {
                    CallEssidFreeFunction(gScannedEssidList);
                    gScannedEssidList = NULL;
                }
                gScannedEssidList = CallEssidAllocFunction(0x58);
                if (gScannedEssidList == NULL) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                while (1) {
                    scanResult = ScanEssidEntries(&gScannedEssidList);
                    if (scanResult == -1) {
                        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    result = CheckSingleEssidAossEntry(gScannedEssidList);
                    if (result == 4) {
                        req->mResultCode = VALUE_RECORDS_RESULT_ENTRY_REJECTED;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (retryCount >= scanRetry.mCount) {
                        req->mResultCode = VALUE_RECORDS_RESULT_NO_ENTRY_FOUND;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    EssidSleepWrapper(scanDelayMs);
                    retryCount++;
                }
                if (scanResult == -1) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                gRequestedEssidList = CallEssidAllocFunction(0x58);
                if (gRequestedEssidList == NULL) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(gRequestedEssidList, 0, 0x58);
                retryCount = 0;
                if (scanRetry.mCount > 0) {
                    do {
                        result = RunEssidMelcoRequest(&melcoRequest, gRequestedEssidList);
                        if (result == -1) {
                            req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                            ReleaseEssidEntryLists();
                            return -1;
                        }
                        if (result == 0) {
                            if (result != 0 || gRequestedEssidList->mCount == 1) {
                                break;
                            }
                        }
                        EssidSleepWrapper(scanDelayMs);
                        retryCount++;
                    } while (retryCount < scanRetry.mCount);
                }
                if (retryCount == scanRetry.mCount) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                addr = GetNextAddressInMask(gRequestState.mDestinationAddress, gRequestState.mAddressMask);
                if (StartSocketsWithAddress(addr, gRequestState.mAddressMask, addr) != 0) {
                    SetErrorCode(ESSID_ERROR_START_SOCKETS);
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                gRequestState.mAddressApplied = 1;
                ReleaseEssidEntryLists();
                gSocketDescriptor = OpenSocket(2, 2, 0);
                if (gSocketDescriptor < 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (SocketReturnArgument(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
                    SetErrorCode(ESSID_ERROR_SOCKET_OPTION);
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(&bindAddress, 0, 8);
                bindAddress.mFamily = SOCKET_FAMILY_IPV4;
                bindAddress.mAddress = SwapBytes32(addr);
                bindAddress.mPort = PacketSwapBytes16(0x5790);
                if (BindSocket(gSocketDescriptor, &bindAddress, 8) < 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
            }
            if (ReportStateAndSendPacketForMode(step, &sendScratch, tags, gSocketDescriptor) == -1) {
                SetErrorCode(step + ESSID_ERROR_SEND_FAILED_BASE);
                req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                ReleaseEssidEntryLists();
                return -1;
            }
            FillBytes(buffer, 0, 0x5f8);
            ClearPollEntry(&set);
            SetPollEntryForRead(gSocketDescriptor, &set);
            wait.mSeconds = timeout / 1000;
            wait.mMicroseconds = timeout % 1000 * 1000;
            if (PollSocketWithTimeout(gSocketDescriptor + 1, &set, NULL, NULL, &wait) > 0) {
                break;
            }
            attempts++;
            if (attempts > limits.mCount) {
                if (step == ESSID_REQUEST_STEP_ITEM_CHAIN) {
                    SetErrorCode(ESSID_ERROR_NO_REPLY_ITEM_CHAIN);
                } else if (step == ESSID_REQUEST_STEP_WANTED_MASK) {
                    SetErrorCode(ESSID_ERROR_NO_REPLY_WANTED_MASK);
                } else {
                    SetErrorCode(ESSID_ERROR_NO_REPLY_FINISH);
                }
                ret = -1;
                goto cleanup;
            }
            EssidSleepWrapper(limits.mDelayMs);
        }
        srcLen = 8;
        received = RecvFromSocket(gSocketDescriptor, buffer->mBytes, 0x5dc, 0, &senderAddress, &srcLen);
        buffer->mDescriptor = gSocketDescriptor;
        buffer->mReceivedLength = SwapBytes16(received);
        nextStep = AdvanceStepByKind(step, buffer, &attempts, tags, gSocketDescriptor);
        if (nextStep == 0x64) {
            ret = 0;
            goto cleanup;
        }
        if (nextStep == -1) {
            ret = -1;
            goto cleanup;
        }
        if (step != nextStep) {
            if (nextStep == 2) {
                if (gSocketDescriptor != -1) {
                    CloseSocket(gSocketDescriptor);
                }
                gSocketDescriptor = -1;
                if (StopSocketsAndDisconnectEssid() != 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                retryCount = 0;
                ReportStateChange(4);
                while (1) {
                    if (gScannedEssidList != NULL) {
                        CallEssidFreeFunction(gScannedEssidList);
                        gScannedEssidList = NULL;
                    }
                    if (ScanEssidEntries(&gScannedEssidList) == -1) {
                        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    result = CheckSingleEssidAossEntry(gScannedEssidList);
                    if (result == 4) {
                        req->mResultCode = VALUE_RECORDS_RESULT_ENTRY_REJECTED;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (retryCount >= scanRetry.mCount) {
                        req->mResultCode = VALUE_RECORDS_RESULT_NO_ENTRY_FOUND;
                        ReleaseEssidEntryLists();
                        return -1;
                    }
                    EssidSleepWrapper(scanDelayMs);
                    retryCount++;
                }
                gRequestedEssidList = CallEssidAllocFunction(0x58);
                if (gRequestedEssidList == NULL) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(gRequestedEssidList, 0, 0x58);
                retryCount = 0;
                if (scanRetry.mCount > 0) {
                    do {
                        result = RunEssidMelcoRequest(&melcoRequest, gRequestedEssidList);
                        if (result == -1) {
                            req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                            ReleaseEssidEntryLists();
                            return -1;
                        }
                        if (result == 0) {
                            if (result != 0 || gRequestedEssidList->mCount == 1) {
                                break;
                            }
                        }
                        EssidSleepWrapper(scanDelayMs);
                        retryCount++;
                    } while (retryCount < scanRetry.mCount);
                }
                if (retryCount == scanRetry.mCount) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (StartSocketsWithAddress(addr, gRequestState.mAddressMask, addr) != 0) {
                    SetErrorCode(ESSID_ERROR_START_SOCKETS);
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                ReleaseEssidEntryLists();
                gSocketDescriptor = OpenSocket(2, 2, 0);
                if (gSocketDescriptor < 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                if (SocketReturnArgument(gSocketDescriptor, 0xffff, 1, &value, 4) < 0) {
                    SetErrorCode(ESSID_ERROR_SOCKET_OPTION);
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
                FillBytes(&bindAddress, 0, 8);
                bindAddress.mFamily = SOCKET_FAMILY_IPV4;
                bindAddress.mAddress = SwapBytes32(addr);
                bindAddress.mPort = PacketSwapBytes16(0x5790);
                if (BindSocket(gSocketDescriptor, &bindAddress, 8) < 0) {
                    req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
                    ReleaseEssidEntryLists();
                    return -1;
                }
            }
            step = nextStep;
            continue;
        }
        step = nextStep;
        if (attempts > limits.mCount) {
            if (nextStep == 0) {
                SetErrorCode(ESSID_ERROR_NO_REPLY_ITEM_CHAIN);
            } else if (nextStep == 1) {
                SetErrorCode(ESSID_ERROR_NO_REPLY_WANTED_MASK);
            } else {
                SetErrorCode(ESSID_ERROR_NO_REPLY_FINISH);
            }
            ret = -1;
            goto cleanup;
        }
        EssidSleepWrapper(limits.mDelayMs);
        continue;
    }

cleanup:
    if (gSocketDescriptor != -1) {
        CloseSocket(gSocketDescriptor);
    }
    gSocketDescriptor = -1;
    if (StopSocketsAndDisconnectEssid() != 0) {
        req->mResultCode = VALUE_RECORDS_RESULT_FAILED;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (ret != 0) {
        switch (GetErrorCode()) {
            case ESSID_ERROR_NO_REPLY_ITEM_CHAIN:
                resultCode = VALUE_RECORDS_RESULT_TIMEOUT_STEP0;
                break;
            case ESSID_ERROR_NO_REPLY_WANTED_MASK:
                resultCode = VALUE_RECORDS_RESULT_TIMEOUT_STEP1;
                break;
            case ESSID_ERROR_NO_REPLY_FINISH:
                resultCode = VALUE_RECORDS_RESULT_TIMEOUT_STEP2;
                break;
            case ESSID_ERROR_REPLY_STATUS_FIRST:
                resultCode = VALUE_RECORDS_RESULT_REPLY_STATUS_FIRST;
                break;
            case ESSID_ERROR_REPLY_STATUS_SECOND:
                resultCode = VALUE_RECORDS_RESULT_REPLY_STATUS_SECOND;
                break;
            default:
                resultCode = VALUE_RECORDS_RESULT_FAILED;
                break;
        }
        req->mResultCode = resultCode;
        ReleaseEssidEntryLists();
        return -1;
    }
    if (CheckAndCopyValueRecordsToRequest(req) != 0) {
        req->mResultCode = VALUE_RECORDS_RESULT_BAD_RECORDS;
        ReleaseEssidEntryLists();
        return -1;
    }
    return 0;
}

u32 GetNextAddressInMask(u32 addr, u32 mask) {
    u32 base = addr & mask;
    u32 next = (addr & ~mask) + 1;
    if ((base | next) < (base | ~mask)) {
        return base | next;
    }
    return base | 1;
}

void ReleaseEssidEntryLists(void) {
    if (gRequestedEssidList != NULL) {
        CallEssidFreeFunction(gRequestedEssidList);
        gRequestedEssidList = NULL;
    }
    if (gScannedEssidList != NULL) {
        CallEssidFreeFunction(gScannedEssidList);
        gScannedEssidList = NULL;
    }
}

void InitRequestState(ValueRecordsRequest *req) {
    FillBytes(gSavedTagBytes, 0, 8);
    gErrorCode = ESSID_ERROR_NONE;
    FillBytes(&gRequestState, 0, 0x1c);
    gRequestState.mItemBytes = req->mItem.mItemBytes;
    gRequestState.mItemLength = req->mItem.mItemLength;
    gRequestState.mWantedRecordMask = req->mWantedRecordMask & VALUE_RECORD_MASK_ALL;
    gRequestState.mItemType = req->mItem.mItemType;
    gRequestState.mFoundRecordMask = 0;
    gRequestState.mDestinationAddress = ESSID_REQUEST_FIRST_DESTINATION_ADDRESS;
    gRequestState.mAddressApplied = 0;
}

void SetErrorCode(s32 code) {
    gErrorCode = code;
}

s32 GetErrorCode(void) {
    u32 errorCode;
    errorCode = (u32) &gErrorCode;
    errorCode = *(const u32 *) ((errorCode) + 0u);
    return errorCode;
}

s32 CheckAndCopyValueRecordsToRequest(ValueRecordsRequest *request) {
    u8 *recordBytes = request->mRecordBytes;
    FourValueRecord *fourValueRecord0 = &gParsedItems[0].mFourValueRecord0;
    FourValueRecord *fourValueRecord1 = &gParsedItems[0].mFourValueRecord1;
    SingleValueRecord *singleValueRecord0 = &gParsedItems[0].mSingleValueRecord0;
    SingleValueRecord *singleValueRecord1 = &gParsedItems[0].mSingleValueRecord1;
    if (recordBytes == NULL) {
        return -1;
    }
    request->mWantedRecordMask = gRequestState.mWantedRecordMask & gRequestState.mFoundRecordMask;
    FillBytes(recordBytes, 0, 0x154);
    if (request->mWantedRecordMask & VALUE_RECORD_MASK_KEY_SET_FIRST) {
        CopyBytes(recordBytes, fourValueRecord0->mWepKeys[0], fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 6, fourValueRecord0->mWepKeys[1], fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 0xc, fourValueRecord0->mWepKeys[2], fourValueRecord0->mValueLength);
        CopyBytes(recordBytes + 0x12, fourValueRecord0->mWepKeys[3], fourValueRecord0->mValueLength);
        if (CheckBytesInRange0x20To0x7f(fourValueRecord0->mString, GetStringLength(fourValueRecord0->mString)) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x18, fourValueRecord0->mString, GetStringLength(fourValueRecord0->mString));
    }
    if (request->mWantedRecordMask & VALUE_RECORD_MASK_KEY_SET_SECOND) {
        CopyBytes(recordBytes + 0x39, fourValueRecord1->mWepKeys[0], fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x47, fourValueRecord1->mWepKeys[1], fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x55, fourValueRecord1->mWepKeys[2], fourValueRecord1->mValueLength);
        CopyBytes(recordBytes + 0x63, fourValueRecord1->mWepKeys[3], fourValueRecord1->mValueLength);
        if (CheckBytesInRange0x20To0x7f(fourValueRecord1->mString, GetStringLength(fourValueRecord1->mString)) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x71, fourValueRecord1->mString, GetStringLength(fourValueRecord1->mString));
    }
    if (request->mWantedRecordMask & VALUE_RECORD_MASK_SINGLE_VALUE_FIRST) {
        if (CheckBytesInRange0x20To0x7f(singleValueRecord0->mValue, singleValueRecord0->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x92, singleValueRecord0->mValue, singleValueRecord0->mValueLength);
        if (CheckBytesInRange0x20To0x7f(singleValueRecord0->mString, GetStringLength(singleValueRecord0->mString)) !=
            0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0xd2, singleValueRecord0->mString, GetStringLength(singleValueRecord0->mString));
    }
    if (request->mWantedRecordMask & VALUE_RECORD_MASK_SINGLE_VALUE_SECOND) {
        if (CheckBytesInRange0x20To0x7f(singleValueRecord1->mValue, singleValueRecord1->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0xf3, singleValueRecord1->mValue, singleValueRecord1->mValueLength);
        if (CheckBytesInRange0x20To0x7f(singleValueRecord1->mString, GetStringLength(singleValueRecord1->mString)) !=
            0) {
            goto fail;
        }
        CopyBytes(recordBytes + 0x133, singleValueRecord1->mString, GetStringLength(singleValueRecord1->mString));
    }
    request->mResultCode = VALUE_RECORDS_RESULT_OK;
    return 0;
fail:
    FillBytes(recordBytes, 0, 0x154);
    return -1;
}

s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count) {
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}

// Returns 0 when exactly one of the first 0x40 entries with bit 0 of mMode has an essid equal to gEssidAossString, 4
// when several do, 5 when none does or the list is empty.
s32 CheckSingleEssidAossEntry(EssidEntryList *entryList) {
    s32 count;
    s32 result;
    s32 entryIndex;
    s32 matchCount;
    result = 0;
    matchCount = 0;
    count = entryList->mCount;
    if (count == 0) {
        return 5;
    }
    if ((u32) count > 0x40) {
        count = 0x40;
    }
    for (entryIndex = 0; entryIndex < count; entryIndex++) {
        if (entryList->mEntries[entryIndex].mMode & 1) {
            if (entryList->mEntries[entryIndex].mEssidLength == GetStringLength(gEssidAossString)) {
                if (CompareBytes(entryList->mEntries[entryIndex].mEssid, gEssidAossString,
                                 GetStringLength(gEssidAossString)) == 0) {
                    matchCount++;
                }
            }
        }
    }
    if (matchCount > 1) {
        result = 4;
    }
    if (matchCount == 0) {
        result = 5;
    }
    return result;
}

s32 FillEssidAossAndMelcoRequest(EssidMelcoRequest *request) {
    request->mEssidLength = GetStringLength(gEssidAossString);
    CopyBytes(request->mEssid, gEssidAossString, request->mEssidLength);
    request->mUseSharedKey = TRUE;
    request->mMelcoLength = GetStringLength(gMelcoString);
    if ((u32) request->mMelcoLength > sizeof(WepKey13)) {
        return -1;
    }
    CopyBytes(request->mMelcoBytes, gMelcoString, request->mMelcoLength);
    return 0;
}

void FillPacketTags(s32 count, PacketTag *tags, const u8 *tagBytes) {
    s32 tagIndex;
    for (tagIndex = 0; tagIndex < count; tagIndex++) {
        CopyBytes(tags, tagBytes, 6);
        tags->mSequence = NextRandomValue();
        tags->mSequence = PacketSwapBytes16(tags->mSequence);
        tags++;
    }
}

s32 ReportStateChange(s32 state) {
    BOOL result = FALSE;
    if (state == -1) {
        gReportedState = state;
        return result;
    }
    if (gReportedState != state) {
        gReportedState = state;
        return CallStateChangeCallback(state);
    }
    return result;
}

s32 AdvanceStepByKind(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list, s32 descriptor) {
    Packet *header = (Packet *) buffer->mBytes;
    u32 kind;
    if (SwapBytes16(header->mNonzeroWord) < 1) {
        *attempts = *attempts + 1;
        return mode;
    }
    if (header->mMagicByte != ESSID_PACKET_MAGIC_BYTE) {
        *attempts = *attempts + 1;
        return mode;
    }
    if (CheckPacketAndXorPayload((Packet *) buffer->mBytes) > 0) {
        *attempts = *attempts + 1;
        return mode;
    }
    kind = SwapBytes16(header->mKind);
    switch (kind) {
        case 0x1010:
            mode = AdvanceStepForItemChainReply(mode, buffer, attempts, list);
            break;
        case 0x2010:
            mode = AdvanceStepForRecordsReply(mode, buffer, attempts, list);
            break;
        case 0x3010:
            mode = AdvanceStepForFinishReply(mode, buffer, attempts, list);
            break;
    }
    return mode;
}

s32 AdvanceStepForItemChainReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    ItemContainerView *payload;
    u32 *valuePointer;
    s32 result;
    if (mode != ESSID_REQUEST_STEP_ITEM_CHAIN) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (ItemContainerView *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[0], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mLength) == 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mType == PAYLOAD_ITEM_STATUS) {
        valuePointer = &payload->mFirstWord;
        if (PacketSwapBytes32(payload->mFirstWord) == -2) {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_FIRST);
        } else if (PacketSwapBytes32(*valuePointer) == -3) {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_SECOND);
        } else {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_OTHER);
        }
        return -1;
    }
    if (payload->mType != PAYLOAD_ITEM_CHAIN) {
        (*attempts)++;
        return mode;
    }
    result = ParseItemChain(&payload->mFirstItem, gItemSlots);
    if (result < 0) {
        if (result == -2) {
            SetErrorCode(ESSID_ERROR_ITEM_CHAIN_PARSE);
            return -1;
        }
        (*attempts)++;
        return mode;
    }
    gUseKeyStream = IsKeyStreamAcceptedBitSet(SwapBytes16(packet->mFlags));
    *attempts = 0;
    return 1;
}

s32 AdvanceStepForRecordsReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    ItemContainerView *payload;
    s32 result;
    if (mode != ESSID_REQUEST_STEP_WANTED_MASK) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (ItemContainerView *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[1], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mLength) == 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mType == PAYLOAD_ITEM_STATUS) {
        if (PacketSwapBytes32(payload->mFirstWord) == -2) {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_FIRST);
        } else if (PacketSwapBytes32(payload->mFirstWord) == -3) {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_SECOND);
        } else {
            SetErrorCode(ESSID_ERROR_REPLY_STATUS_OTHER);
        }
        return -1;
    }
    FillBytes(gParsedItems, 0, 0x6a0);
    result =
        FindItemAndParseSubItems(0, &payload->mItem, SwapBytes16(packet->mPayloadLength), gParsedItems, gItemSlots);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if ((gRequestState.mFoundRecordMask & gRequestState.mWantedRecordMask) == 0) {
        return mode;
    }
    *attempts = 0;
    return 2;
}

s32 AdvanceStepForFinishReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list) {
    Packet *packet;
    ItemContainerView *payload;
    s32 result;
    if (mode != ESSID_REQUEST_STEP_FINISH) {
        (*attempts)++;
        return mode;
    }
    packet = (Packet *) buffer->mBytes;
    payload = (ItemContainerView *) &buffer->mBytes[0x18];
    result = XorSwapAndCheckTag(&list[2], &packet->mTag);
    if (result < 0) {
        (*attempts)++;
        return mode;
    }
    if (payload->mType != PAYLOAD_ITEM_STATUS) {
        (*attempts)++;
        return mode;
    }
    if (SwapBytes16(payload->mLength) == 0) {
        (*attempts)++;
        return mode;
    }
    if (PacketSwapBytes32(payload->mFirstWord) == 0) {
        return 0x64;
    }
    if (PacketSwapBytes32(payload->mFirstWord) == -2) {
        SetErrorCode(ESSID_ERROR_REPLY_STATUS_FIRST);
        return -1;
    }
    if (PacketSwapBytes32(payload->mFirstWord) == -3) {
        SetErrorCode(ESSID_ERROR_REPLY_STATUS_SECOND);
        return -1;
    }
    SetErrorCode(ESSID_ERROR_REPLY_STATUS_OTHER);
    return -1;
}

// Unmixes the tag with the key string and checks it against the saved tag bytes (a kind 0x1000 packet saves it); when
// mFlags & 0xf is set, xors the payload with the key stream, checks its CRC and copies it back over the record.
s32 CheckPacketAndXorPayload(Packet *packet) {
    PayloadRecord *payload;
    u8 tag[8];
    s32 result;
    u32 length;
    u8 *copy;
    payload = (PayloadRecord *) packet->mPayload;
    CopyBytes(tag, &packet->mTag, 8);
    result = XorAndSwapBytesWithKey(tag, 8, gMelcoString, GetStringLength(gMelcoString));
    if (result == -1) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        return -100;
    }
    result = CheckTagAgainstSavedBytesOrFirstRequest(SwapBytes16(packet->mKind), tag);
    if (result != 0) {
        return result;
    }
    if (SwapBytes16(packet->mKind) == 0x1000) {
        CopyBytes(gSavedTagBytes, tag, 8);
    }
    if ((SwapBytes16(packet->mFlags) & 0xf) == 0) {
        return 0;
    }
    length = SwapBytes16(payload->mLength);
    copy = CallEssidAllocFunction(length);
    if (copy == NULL) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        return 100;
    }
    if (XorBytesWithKeyStreamAndCheckCrc(payload->mBytes, copy, length, packet->mPayloadCrc, payload->mKeyPrefix,
                                         gSavedTagBytes, 8) < 0) {
        CallEssidFreeFunction(copy);
        if (GetErrorCode() == ESSID_ERROR_PACKET_BUFFER) {
            return 100;
        }
        return 200;
    }
    CopyBytes(payload, copy, length);
    packet->mPayloadLength = PacketSwapBytes16(length);
    CallEssidFreeFunction(copy);
    return 0;
}

s32 CheckTagAgainstSavedBytesOrFirstRequest(s32 kind, const u8 *tag) {
    s32 result;
    s32 byteIndex;
    BOOL foundNonzero;
    u8 *cursor;
    result = 0;
    foundNonzero = FALSE;
    byteIndex = 0;
    cursor = gSavedTagBytes;
    do {
        if (*cursor != 0) {
            foundNonzero = TRUE;
            break;
        }
        cursor++;
        byteIndex++;
    } while (byteIndex < 6);
    if (foundNonzero != FALSE) {
        if (CompareBytes(gSavedTagBytes, tag, 6) != 0) {
            result = 1;
        }
    } else if (kind != 0x1000) {
        result = 2;
    }
    return result;
}

s32 XorSwapAndCheckTag(PacketTag *expectedTag, PacketTag *incomingTag) {
    s32 result;
    result = 0;
    XorAndSwapBytesWithKey(incomingTag->mBytes, 8, gMelcoString, GetStringLength(gMelcoString));
    if (CompareBytes(expectedTag->mBytes, incomingTag->mBytes, 6) != 0) {
        result = -1;
    } else if (SwapBytes16(expectedTag->mSequence) + 1 != SwapBytes16(incomingTag->mSequence)) {
        result = -2;
    }
    return result;
}

s32 ParseItemChain(PacketItem *firstItem, u8 *slots) {
    PacketItem *item;
    s32 length;
    s32 value;
    FillBytes(slots, 0, 0x104);
    item = firstItem;
    while (1) {
        length = SwapBytes16(item->mLength);
        if (length <= 0) {
            return -1;
        }
        switch (item->mType) {
            case CHAIN_ITEM_SLOT0:
                CopyBytes(slots, item->mValue, length);
                break;
            case CHAIN_ITEM_SLOT1:
                CopyBytes(slots + 0x80, item->mValue, length);
                break;
            case CHAIN_ITEM_SLOT2:
                CopyBytes(slots + 0x100, item->mValue, length);
                break;
            case 3:
            case 4:
                value = SwapBytes16(item->mValue[0]);
                if (value <= 0) {
                    return -2;
                }
                break;
            case CHAIN_ITEM_DESTINATION_ADDRESS:
                gRequestState.mDestinationAddress = PacketSwapBytes32(ReadLittleEndianValue(item->mValue, length));
                break;
            case CHAIN_ITEM_ADDRESS_MASK:
                gRequestState.mAddressMask = PacketSwapBytes32(ReadLittleEndianValue(item->mValue, length));
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = OFFSET_PTR(PacketItem, firstItem, SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

u32 ReadLittleEndianValue(const u8 *bytes, s32 count) {
    u32 value = 0;
    s32 byteIndex;
    const u8 *cursor = bytes + (count - 1);
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        value = (value << 8) + *cursor--;
    }
    return value;
}

s32 ParseFourValueItems(PacketItem *container, FourValueRecord *record) {
    PacketItem *item = (PacketItem *) container->mValue;
    u32 length;
    while (1) {
        length = SwapBytes16(item->mLength);
        switch (item->mType) {
            case RECORD_ITEM_WEP_KEY_SHORT0:
            case RECORD_ITEM_WEP_KEY_SHORT1:
            case RECORD_ITEM_WEP_KEY_SHORT2:
            case RECORD_ITEM_WEP_KEY_SHORT3:
                if (length > 5) {
                    return -1;
                }
                break;
            case RECORD_ITEM_WEP_KEY_LONG0:
            case RECORD_ITEM_WEP_KEY_LONG1:
            case RECORD_ITEM_WEP_KEY_LONG2:
            case RECORD_ITEM_WEP_KEY_LONG3:
                if (length > 0xd) {
                    return -1;
                }
                break;
            case RECORD_ITEM_STRING_SHORT_KEYS:
            case RECORD_ITEM_STRING_LONG_KEYS:
                if (length > 0x21) {
                    return -1;
                }
                break;
        }
        switch (item->mType) {
            case RECORD_ITEM_WEP_KEY_SHORT0:
            case RECORD_ITEM_WEP_KEY_LONG0:
                CopyBytes(record->mWepKeys[0], item->mValue, length);
                record->mValueLength = length;
                break;
            case RECORD_ITEM_WEP_KEY_SHORT1:
            case RECORD_ITEM_WEP_KEY_LONG1:
                CopyBytes(record->mWepKeys[1], item->mValue, length);
                record->mValueLength = length;
                break;
            case RECORD_ITEM_WEP_KEY_SHORT2:
            case RECORD_ITEM_WEP_KEY_LONG2:
                CopyBytes(record->mWepKeys[2], item->mValue, length);
                record->mValueLength = length;
                break;
            case RECORD_ITEM_WEP_KEY_SHORT3:
            case RECORD_ITEM_WEP_KEY_LONG3:
                CopyBytes(record->mWepKeys[3], item->mValue, length);
                record->mValueLength = length;
                break;
            case RECORD_ITEM_STRING_SHORT_KEYS:
            case RECORD_ITEM_STRING_LONG_KEYS:
                if (length != 0 && item->mValue[length - 1] != 0) {
                    return -1;
                }
                CopyBytes(record->mString, item->mValue, length);
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = (PacketItem *) (container->mValue + SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 ParseSingleValueItems(PacketItem *container, SingleValueRecord *record) {
    PacketItem *item = (PacketItem *) container->mValue;
    u32 length;
    while (1) {
        length = SwapBytes16(item->mLength);
        switch (item->mType) {
            case 0x30:
            case 0x40:
                if (length > 0x40) {
                    return -1;
                }
                break;
            case 0x35:
            case 0x45:
                if (length > 0x21) {
                    return -1;
                }
                break;
        }
        switch (item->mType) {
            case 0x30:
            case 0x40:
                CopyBytes(record->mValue, item->mValue, length);
                record->mValueLength = length;
                break;
            case 0x35:
            case 0x45:
                if (length != 0 && item->mValue[length - 1] != 0) {
                    return -1;
                }
                CopyBytes(record->mString, item->mValue, length);
                break;
            default:
                return -1;
        }
        if (item->mNextOffset != 0) {
            item = (PacketItem *) (container->mValue + SwapBytes16(item->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 CopyFirstItemValueIfSlotBytes(PacketItem *container, u8 *output) {
    PacketItem *item = (PacketItem *) container->mValue;
    s32 length;
    length = SwapBytes16(item->mLength);
    if (length <= 0) {
        return -1;
    }
    if (item->mType != SLOT_BYTES_ITEM) {
        return -1;
    }
    CopyBytes(output, item->mValue, length);
    return 0;
}

// Skips top-level items until one has type gItemTypesToFind[index], then parses its sub-items by type into parsedItems
// and slots and adds the found record bits to gRequestState.mFoundRecordMask.
s32 FindItemAndParseSubItems(s32 index, PacketItem *item, s32 remaining, ParsedItems *parsedItems, u8 *slots) {
    u32 foundMask;
    s32 itemSize;
    u32 subRemaining;
    u8 *typePointer;
    ParsedItems *parsed;
    u8 *slotBytes;
    s32 result;
    PacketItem *matchedItem;
    foundMask = 0;
    if (remaining <= 0) {
        return -2;
    }
    typePointer = gItemTypesToFind + index;
    for (;;) {
        matchedItem = item;
        if (item->mType == *typePointer) {
            break;
        }
        itemSize = SwapBytes16(item->mLength) + 4;
        item = OFFSET_PTR(PacketItem, item, itemSize);
        remaining -= itemSize;
        if (remaining <= 0) {
            return -4;
        }
    }
    item = OFFSET_PTR(PacketItem, item, 4);
    subRemaining = SwapBytes16(matchedItem->mLength);
    parsed = parsedItems + index;
    slotBytes = slots + (index + 3) * 0x80;
    result = -3;
    do {
        switch (item->mType) {
            case GROUP_SUB_ITEM_WEP_KEYS_5_BYTES:
                result = ParseFourValueItems(item, &parsed->mFourValueRecord0);
                foundMask |= 1;
                break;
            case GROUP_SUB_ITEM_WEP_KEYS_13_BYTES:
                result = ParseFourValueItems(item, &parsed->mFourValueRecord1);
                foundMask |= 2;
                break;
            case GROUP_SUB_ITEM_SINGLE_VALUE_RECORD0:
                result = ParseSingleValueItems(item, &parsed->mSingleValueRecord0);
                foundMask |= 4;
                break;
            case GROUP_SUB_ITEM_SINGLE_VALUE_RECORD1:
                result = ParseSingleValueItems(item, &parsed->mSingleValueRecord1);
                foundMask |= 8;
                break;
            case GROUP_SUB_ITEM_SLOT_BYTES:
                result = CopyFirstItemValueIfSlotBytes(item, slotBytes);
                break;
            default:
                result = -3;
                break;
        }
        if (result != 0) {
            return result;
        }
        itemSize = SwapBytes16(item->mLength) + 4;
        item = OFFSET_PTR(PacketItem, item, itemSize);
        subRemaining -= itemSize;
    } while ((s32) subRemaining > 0);
    gRequestState.mFoundRecordMask |= foundMask;
    return 0;
}

s32 IsKeyStreamAcceptedBitSet(u32 flags) {
    BOOL result = FALSE;
    if (flags & 0x10) {
        result = TRUE;
    }
    return result;
}

// Reports state 2, 3 or 5 and sends the packet of kind 0x1000, 0x2000 or 0x3000 for mode 0, 1 or 2; any other mode
// returns -1.
s32 ReportStateAndSendPacketForMode(s32 mode, SendPacketScratch *buf, PacketTag *list, s32 descriptor) {
    switch (mode) {
        case ESSID_REQUEST_STEP_ITEM_CHAIN:
            ReportStateChange(2);
            return SendItemChainPacket(buf, list, descriptor);
        case ESSID_REQUEST_STEP_WANTED_MASK:
            ReportStateChange(3);
            return SendWantedMaskPacket(buf, list, descriptor);
        case ESSID_REQUEST_STEP_FINISH:
            ReportStateChange(5);
            return SendFinishPacket(buf, list, descriptor);
    }
    return -1;
}

s32 SendItemChainPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor) {
    PacketFieldValues fields;
    PacketBuffer *packetBuffer;
    ItemContainer *container;
    u8 *payloadRecord;
    fields.mPayloadCrc = 0;
    fields.mPayloadLength = 0;
    fields.mFlags = 0;
    packetBuffer = gRequestPacketBuffer;
    FillBytes(packetBuffer, 0, 0x5dc);
    container = CallEssidAllocFunction(0x210);
    if (container == NULL) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        return -1;
    }
    FillBytes(container, 0, 0x210);
    payloadRecord = &packetBuffer->mBytes[12];
    CopyBytes(gSavedTagBytes, list, 8);
    CopyBytes(fields.mTag, gSavedTagBytes, 8);
    fields.mPayloadLength = BuildTwoItemChain(container->mItems);
    if (fields.mPayloadLength < 0) {
        SetErrorCode(ESSID_ERROR_ITEM_CHAIN_BUILD);
        if (container != NULL) {
            CallEssidFreeFunction(container);
        }
        return -1;
    }
    container->mUnk_00 = 0;
    container->mLength = PacketSwapBytes16(fields.mPayloadLength);
    fields.mPayloadLength += 4;
    FillPayloadRecord(0, payloadRecord, container, &fields.mPayloadLength, &fields.mFlags, &fields.mPayloadCrc);
    fields.mFlags |= 0x10;
    if (XorAndSwapBytesWithKey(fields.mTag, 8, gMelcoString, 6) != 0) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        if (container != NULL) {
            CallEssidFreeFunction(container);
        }
        return -1;
    }
    FillPacketHeader(packetBuffer, 0x1000, fields.mPayloadLength, fields.mFlags, fields.mPayloadCrc,
                     ESSID_PACKET_MAGIC_BYTE, fields.mTag);
    fields.mPayloadLength += 0x18;
    SendPacket(packetBuffer, fields.mPayloadLength, 0xff, descriptor);
    if (container != NULL) {
        CallEssidFreeFunction(container);
    }
    return 0;
}

s32 SendWantedMaskPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor) {
    s8 payloadCrc;
    s16 payloadLength;
    s16 flags;
    u8 tagBytes[8];
    ItemContainerView item;
    PacketBuffer *packetBuffer;
    payloadCrc = 0;
    payloadLength = 0;
    flags = 0;
    packetBuffer = gRequestPacketBuffer;
    FillBytes(&item, 0, 8);
    FillBytes(packetBuffer, 0, 0x5dc);
    item.mType = PAYLOAD_ITEM_WANTED_MASK;
    item.mUnk_01 = 0;
    item.mLength = PacketSwapBytes16(4);
    item.mFirstWord = gRequestState.mWantedRecordMask;
    item.mFirstWord = SwapBytes32(item.mFirstWord);
    payloadLength = 8;
    FillPayloadRecord(gUseKeyStream, &packetBuffer->mBytes[12], &item, &payloadLength, &flags, &payloadCrc);
    CopyBytes(tagBytes, &list[1], 8);
    if (XorAndSwapBytesWithKey(tagBytes, 8, gMelcoString, 6) != 0) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        return -1;
    }
    FillPacketHeader(packetBuffer, 0x2000, payloadLength, flags, payloadCrc, ESSID_PACKET_MAGIC_BYTE, tagBytes);
    payloadLength += 0x18;
    SendPacket(packetBuffer, payloadLength, 0, descriptor);
    return 0;
}

s32 SendFinishPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor) {
    PacketBuffer *packetBuffer;
    u8 tagBytes[8];
    packetBuffer = gRequestPacketBuffer;
    FillBytes(packetBuffer, 0, 0x5dc);
    CopyBytes(tagBytes, &list[2], 8);
    XorAndSwapBytesWithKey(tagBytes, 8, gMelcoString, GetStringLength(gMelcoString));
    FillPacketHeader(packetBuffer, 0x3000, 0, 0, 0, ESSID_PACKET_MAGIC_BYTE, tagBytes);
    SendPacket(packetBuffer, 0x18, 0, descriptor);
    return 0;
}

s16 BuildTwoItemChain(void *buffer) {
    OutgoingPacketItem *firstItem = buffer;
    OutgoingPacketItem *secondItem;
    s16 firstLength;
    s16 firstSize;
    s16 totalSize;
    u32 value;
    totalSize = 0;
    firstItem->mType = gRequestState.mItemType;
    firstItem->mUnk_01 = 1;
    firstLength = gRequestState.mItemLength;
    CopyBytes(firstItem->mValue, gRequestState.mItemBytes, firstLength);
    firstItem->mLength = PacketSwapBytes16(firstLength);
    firstLength += 6;
    firstSize = (firstLength + 1) / 2 * 2;
    firstItem->mNextOffset = PacketSwapBytes16(firstSize);
    totalSize += firstSize;
    secondItem = OFFSET_PTR(OutgoingPacketItem, firstItem, firstSize);
    ((u8 *) firstItem)[firstSize] = PACKET_ITEM_TRAILER;
    secondItem->mUnk_01 = 0;
    secondItem->mNextOffset = PacketSwapBytes16(0);
    value = SwapBytes32(0xe);
    CopyBytes(secondItem->mValue, &value, 4);
    secondItem->mLength = PacketSwapBytes16(4);
    totalSize += 0xa;
    return totalSize;
}

void FillPayloadRecord(s32 useKeyStream, void *destination, const void *source, s16 *length, s16 *flags, s8 *crc) {
    PayloadRecord *record = destination;
    if (useKeyStream == 1) {
        *flags = 1;
        XorBytesWithRandomKeyStreamAndComputeCrc(source, record->mBytes, *length, crc, record->mKeyPrefix,
                                                 gSavedTagBytes, 8);
        record->mLength = PacketSwapBytes16(*length);
        *length += 4;
    } else {
        CopyBytes(record, source, *length);
    }
}

void FillPacketHeader(void *buffer, s32 kind, s32 payloadLength, s32 flags, s8 payloadCrc, s8 magicByte,
                      const u8 *tagBytes) {
    PacketHeader *header = buffer;
    header->mNonzeroWord = PacketSwapBytes16(1);
    header->mUnk_02 = 0;
    header->mUnk_04 = 0;
    header->mKind = PacketSwapBytes16(kind);
    header->mUnk_08 = 0;
    header->mPayloadLength = PacketSwapBytes16(payloadLength);
    header->mFlags = PacketSwapBytes16(flags);
    header->mPayloadCrc = payloadCrc;
    header->mMagicByte = magicByte;
    CopyBytes(header->mTag, tagBytes, 8);
}

s32 SendPacket(void *packet, s32 length, u32 target, s32 descriptor) {
    SocketAddress address;
    FillBytes(&address, 0, 8);
    address.mFamily = SOCKET_FAMILY_IPV4;
    address.mPort = PacketSwapBytes16(0x5790);
    address.mAddress = SwapBytes32(gRequestState.mDestinationAddress);
    if (target == 0xff || gRequestState.mAddressApplied == 0) {
        address.mAddress = -1;
    }
    return SendToSocket(descriptor, packet, length, 0, &address, 8);
}

s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *src, u8 *dst, s32 length, s8 *crc, u8 *keyPrefix,
                                             const u8 *keyTail, s32 keyTailLength) {
    u16 random;
    KeyStreamState state;
    *crc = ComputeCrcLowByte(src, length);
    state.mTable = CallEssidAllocFunction(length);
    if (state.mTable == NULL) {
        return -1;
    }
    random = NextRandomValue();
    CopyBytes(keyPrefix, &random, 2);
    CopyBytes(gKeyStreamKey, keyPrefix, 2);
    CopyBytes(gKeyStreamKey + 2, keyTail, keyTailLength);
    InitKeyStream(&state, gKeyStreamKey, keyTailLength + 2, length);
    XorWithKeyStream(&state, dst, src, length);
    CallEssidFreeFunction(state.mTable);
    return 0;
}

s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *src, u8 *dst, s32 length, u32 expectedCrc, const u8 *keyPrefix,
                                     const u8 *keyTail, s32 keyTailLength) {
    KeyStreamState state;
    u8 crc;
    state.mTable = CallEssidAllocFunction(length);
    if (state.mTable == NULL) {
        SetErrorCode(ESSID_ERROR_PACKET_BUFFER);
        return -1;
    }
    CopyBytes(gKeyStreamKey, keyPrefix, 2);
    CopyBytes(gKeyStreamKey + 2, keyTail, keyTailLength);
    InitKeyStream(&state, gKeyStreamKey, keyTailLength + 2, length);
    XorWithKeyStream(&state, dst, src, length);
    crc = ComputeCrcLowByte(dst, length);
    if (crc != expectedCrc) {
        SetErrorCode(0x12);
        CallEssidFreeFunction(state.mTable);
        return -1;
    }
    CallEssidFreeFunction(state.mTable);
    return 0;
}

// Fills the table with each entry's index as a byte, then permutes it with swaps driven by the key bytes (repeated as
// needed).
void InitKeyStream(KeyStreamState *state, const u8 *key, u32 keyLength, u32 count) {
    u8 *table;
    u32 index;
    u32 swapIndex;
    u32 keyIndex;
    u8 current;
    u8 swapped;
    table = state->mTable;
    state->mSwapIndex = 0;
    state->mIndex = state->mSwapIndex;
    state->mTableCount = count;
    for (index = 0; index < count; index++) {
        table[index] = index;
    }
    swapIndex = 0;
    keyIndex = 0;
    for (index = 0; index < count; index++) {
        current = table[index];
        swapIndex = (swapIndex + key[keyIndex] + current) % state->mTableCount;
        swapped = table[swapIndex];
        table[swapIndex] = current;
        table[index] = swapped;
        keyIndex++;
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void XorWithKeyStream(KeyStreamState *state, u8 *dst, const u8 *src, u32 count) {
    u32 byteIndex;
    u8 keyByte;
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        keyByte = NextKeyStreamByte(state);
        dst[byteIndex] = keyByte ^ src[byteIndex];
    }
}

u32 NextKeyStreamByte(KeyStreamState *state) {
    u8 *table;
    u32 count;
    u8 index;
    u8 swapIndex;
    u8 first;
    u8 second;
    table = state->mTable;
    count = state->mTableCount;
    index = (state->mIndex + 1) % count;
    first = table[index];
    swapIndex = (first + state->mSwapIndex) % count;
    second = table[swapIndex];
    state->mIndex = index;
    state->mSwapIndex = swapIndex;
    table[swapIndex] = first;
    table[index] = second;
    return table[(first + second) % state->mTableCount];
}

u8 ComputeCrcLowByte(const u8 *bytes, s32 count) {
    return ComputeCrc(~0, bytes, count, 0, gCrcTable) ^ ~0;
}

u32 ComputeCrc(u32 crc, const u8 *bytes, s32 count, s32 tableBuilt, u32 *table) {
    s32 byteIndex;
    if (tableBuilt == 0) {
        InitCrcTable(tableBuilt, table);
    }
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        crc = (crc >> 8) ^ table[(crc ^ bytes[byteIndex]) & 0xff];
    }
    return crc;
}

void InitCrcTable(s32 unused, u32 *table) {
    u32 value;
    s32 entryIndex;
    s32 bitIndex;
    for (entryIndex = 0; entryIndex < 0x100; entryIndex++) {
        value = entryIndex;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (value & 1) {
                value = (value >> 1) ^ 0xedb88320;
            } else {
                value = value >> 1;
            }
        }
        *table++ = value;
    }
}

// Two passes: xor the second half with each position xor a key byte (the key start moves on by the pass number), then
// swap the halves.
s32 XorAndSwapBytesWithKey(u8 *buffer, s32 size, const s8 *key, s32 keyLength) {
    s8 *keyHalf;
    u8 *scratch;
    s32 round;
    keyHalf = CallEssidAllocFunction(size / 2);
    if (keyHalf == NULL) {
        return -1;
    }
    scratch = CallEssidAllocFunction(size);
    if (scratch == NULL) {
        CallEssidFreeFunction(keyHalf);
        return -1;
    }
    for (round = 0; round < 2; round++) {
        FillIndexXorKeyBytes(round, keyHalf, size, key, keyLength);
        XorSecondHalf(keyHalf, buffer, size);
        SwapBufferHalves(buffer, size, scratch);
    }
    CallEssidFreeFunction(keyHalf);
    CallEssidFreeFunction(scratch);
    return 0;
}

void FillIndexXorKeyBytes(s32 round, s8 *output, s32 size, const s8 *key, s32 keyLength) {
    s32 half = size / 2;
    s32 keyIndex = round % keyLength;
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < half; byteIndex++) {
        output[byteIndex] = byteIndex;
        output[byteIndex] ^= key[keyIndex++];
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void XorSecondHalf(const s8 *xorBytes, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < half; byteIndex++) {
        buffer[half + byteIndex] ^= xorBytes[byteIndex];
    }
}

void SwapBufferHalves(u8 *buffer, u32 size, u8 *scratch) {
    int half;
    half = _s32_div_f(size, 2);
    CopyBytes(scratch, (buffer + half), half);
    CopyBytes((scratch + half), buffer, half);
    CopyBytes(buffer, scratch, size);
}

void *AllocSocketMemory(u32 name, int size) {
    void *memory;
    if (0 < size) {
        memory = gEssidAllocFunction(size);
        return memory;
    }
    return NULL;
}

void FreeSocketMemory(u32 name, void *pointer, u32 size) {
    gEssidFreeFunction(pointer);
}

s32 StartSocketsWithAddress(u32 address, u32 mask, u32 router) {
    gEssidSocketConfig.mAddr = SwapBytes32(address);
    gEssidSocketConfig.mNetmask = SwapBytes32(mask);
    gEssidSocketConfig.mRouter = SwapBytes32(router);
    if (SOC_Startup(&gEssidSocketConfig) < 0) {
        return -1;
    }
    while (CPSMyIp == 0) {
        OS_Sleep(100);
    }
    return 0;
}

s32 StopSocketsAndDisconnectEssid(void) {
    if (SOC_Cleanup() < 0) {
        return -1;
    }
    return -(DisconnectEssidAndWait() != 0);
}

s32 CompareBytes(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}

void CopyBytes(void *destination, const void *source, u32 size) {
    MI_CpuCopy8(source, destination, size);
}

void FillBytes(void *destination, s32 fillValue, u32 size) {
    void *destinationCopy = destination;
    u32 byteValue = fillValue;
    u32 sizeCopy = size;
    byteValue = (byteValue << 24);
    byteValue = (byteValue >> 24);
    MI_CpuFill8(destinationCopy, byteValue, sizeCopy);
}

s32 RecvFromSocket(s32 descriptor, void *buffer, s32 length, s32 flags, SocketAddress *address, s32 *addressLength) {
    address->mLength = *addressLength;
    return SOC_RecvFrom(descriptor, buffer, length, flags, address);
}

s32 PollSocketWithTimeout(s32 unusedDescriptorLimit, PollEntry *set, void *unusedSecondSet, void *unusedThirdSet,
                          WaitTimeout *timeout) {
    PollEntry setCopy;
    s64 ticks;
    ticks = 0;
    setCopy = *set;
    ticks += timeout->mSeconds * 0x1ff6210 / 0x40;
    ticks += timeout->mMicroseconds * 0x1ff6210 / 0x40;
    return SOC_Poll(&setCopy, 1, ticks);
}

s32 SendToSocket(s32 descriptor, void *buffer, s32 length, s32 flags, SocketAddress *address, u32 addressLength) {
    address->mLength = addressLength;
    return SOC_SendTo(descriptor, buffer, length, flags, address);
}

s32 SocketReturnArgument(s32 id, s32 unusedLevel, s32 unusedOption, void *value, s32 length) {
    return id;
}

s32 OpenSocket(s32 domain, s32 type, s32 protocol) {
    return SOC_Socket(domain, type, protocol);
}

s32 BindSocket(s32 descriptor, SocketAddress *address, u32 addressLength) {
    address->mLength = addressLength;
    return SOC_Bind(descriptor, address);
}

s32 CloseSocket(s32 descriptor) {
    return SOC_Close(descriptor);
}

u32 SwapBytes32(u32 input) {
    u32 word = input;
    u32 topPart;
    u32 scratch;
    u32 bottomPart;
    u32 middlePart;
    topPart = (word << 24);
    scratch = 0xff000000u;
    topPart = (topPart) & (scratch);
    middlePart = (word << 8);
    scratch = 0xff0000u;
    middlePart = (middlePart) & (scratch);
    bottomPart = (word >> 24);
    scratch = 255u;
    bottomPart = (bottomPart) & (scratch);
    scratch = (word >> 8);
    word = 0xff00u;
    scratch = (scratch) & (word);
    bottomPart = (bottomPart) | (scratch);
    middlePart = (middlePart) | (bottomPart);
    topPart = (topPart) | (middlePart);
    word = (topPart) + (0u);
    return word;
}

u16 PacketSwapBytes16(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

u32 PacketSwapBytes32(u32 input) {
    u32 word = input;
    u32 topPart;
    u32 scratch;
    u32 bottomPart;
    u32 middlePart;
    topPart = (word << 24);
    scratch = 0xff000000u;
    topPart = (topPart) & (scratch);
    middlePart = (word << 8);
    scratch = 0xff0000u;
    middlePart = (middlePart) & (scratch);
    bottomPart = (word >> 24);
    scratch = 255u;
    bottomPart = (bottomPart) & (scratch);
    scratch = (word >> 8);
    word = 0xff00u;
    scratch = (scratch) & (word);
    bottomPart = (bottomPart) | (scratch);
    middlePart = (middlePart) | (bottomPart);
    topPart = (topPart) | (middlePart);
    word = (topPart) + (0u);
    return word;
}

u16 SwapBytes16(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

int GetStringLength(const void *string) {
    const s8 *chars = string;
    int length = 0;
    while (chars[length] != 0) {
        length++;
    }
    return length;
}

// Multiply-add generator, seeded on the first call from the clock time (seed 0 if the clock read fails); returns a
// value below 0x7fff.
u16 NextRandomValue(void) {
    s32 seed;
    RTCTime time;
    u32 *unusedState;
    if (gRandomSeeded == 0) {
        seed = 0;
        FillBytes(&time, 0, 12);
        if (RTC_GetTime(&time) == 0) {
            seed += time.mHour << 10;
            seed += time.mMinute << 3;
            seed += time.mSecond;
        }
        gRandomState[0] = seed;
        gRandomState[1] = 0x5d588b65;
        gRandomState[2] = 0x269ec3;
        gRandomSeeded = 1;
    }
    gRandomState[0] = gRandomState[2] + gRandomState[1] * gRandomState[0];
    return ((gRandomState[0] >> 16) * 0x7fff) >> 16;
}

void ClearPollEntry(PollEntry *entry) {
    entry->mDescriptor = 0;
    entry->mAskedBits = 0;
    entry->mFoundBits = 0;
}

void SetPollEntryForRead(s32 descriptor, PollEntry *entry) {
    entry->mDescriptor = descriptor;
    entry->mAskedBits = 1;
}

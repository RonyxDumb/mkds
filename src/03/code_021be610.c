#include "03/code_021be610.h"
#include "03/code_021bf098.h"
#include "03/code_021d1770.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021d2ecc.h"
#include "03/unk_021d5000.h"
#include "03/unk_021d8000.h"
#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_02147cd8.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "00/code_021a669c.h"
#include "00/unk_021b0000.h"

void ReleaseSlideButtons(u32 task) {
    SlideButtons *slideButtons;
    s32 i;

    RequestTaskRemoval(0, task);
    slideButtons = gSlideButtons;
    if (slideButtons->mResetTask != 0) {
        RequestTaskRemoval(0, slideButtons->mResetTask);
    }
    for (i = 0; i < 2; i++) {
        if (gSlideButtons->mButtons[i] != 0) {
            DeleteOamRange(gSlideButtons->mButtons[i]);
        }
    }
    DeleteOamRange(gSlideButtons->mUnk_08);
    FreeExpHeapBlockAndClearPointer(&gSlideButtons);
}

void AdvanceButtonReset(u32 task) {
    SlideButtons *slideButtons;
    s32 i;
    s32 buttonCount;
    u32 imageIndex;
    u32 c;
    u32 d;

    slideButtons = gSlideButtons;
    slideButtons->mStepFrames = slideButtons->mStepFrames + 1;
    if (gSlideButtons->mStepFrames >= 0x10) {
        slideButtons = gSlideButtons;
        buttonCount = gSlideButtonCounts[slideButtons->mKind];
        for (i = 0; i < buttonCount; i++) {
            slideButtons = gSlideButtons;
            imageIndex = (gSlideButtonImages + slideButtons->mKind * 2)[i];
            CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(slideButtons->mButtons[i], 0));
            func_ov003_021d1790(gSlideButtons->mButtons[i], -1, 1);
        }
        SetSlideButtonsY(gSlideButtonsPosition[1]);
        gSlideButtons->mStepFrames = 0;
        gSlideButtons->mButtonResult = -1;
        slideButtons = gSlideButtons;
        if (slideButtons->mResetTask != 0) {
            slideButtons->mResetTask = 0;
            RequestTaskRemoval(0, task);
        }
    }
}

void CreateAnimatedIcon(int index) {
    AnimatedIcon *object;
    OamEntry *innerObject;
    u32 c;

    object = AllocZeroedExpHeapBlock(0xc, 4);
    gAnimatedIcon = object;
    object->mPaletteIndex = index;
    gAnimatedIcon->mOamEntry = CreateOamEntryFromNceImage(0, 0x47);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xfffff3ff) | 0x400;
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mUnk_00 = innerObject->mUnk_00 & 0xfffff3ff;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xffff0fff) | (gAnimatedIconPalettes[index] << 12);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mUnk_00 = ((gAnimatedIconPosition[0] & 0x1ff) << 16) |
                           ((innerObject->mUnk_00 & 0xfe00ff00) | (gAnimatedIconPosition[1] & 0xff));
    gAnimatedIcon->mTask = AddTask(1, AdvanceAnimatedIcon, NULL, 0x78);
}

void ReleaseAnimatedIcon(void) {
    RemoveTaskEntryWrapper(1, gAnimatedIcon->mTask);
    DeleteOamEntry((u32 *) gAnimatedIcon->mOamEntry);
    FreeExpHeapBlockAndClearPointer(&gAnimatedIcon);
}

void AdvanceAnimatedIcon(void) {
    AnimatedIcon *object;
    OamEntry *innerObject;
    u32 c;

    gAnimatedIcon->mStepFrames = FX_ModS32(gAnimatedIcon->mStepFrames + 1, 0x28);
    c = FX_DivS32(gAnimatedIcon->mStepFrames, 5) + 0x47;
    CopyNceImageToOamEntries(0, c, gAnimatedIcon->mOamEntry);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xfffff3ff) | 0x400;
    object = gAnimatedIcon;
    c = gAnimatedIconPalettes[object->mPaletteIndex];
    innerObject = object->mOamEntry;
    innerObject->mUnk_00 = innerObject->mUnk_00 & 0xfffff3ff;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xffff0fff) | (c << 12);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mUnk_00 = ((gAnimatedIconPosition[0] & 0x1ff) << 16) |
                           ((innerObject->mUnk_00 & 0xfe00ff00) | (gAnimatedIconPosition[1] & 0xff));
}

void ExchangeWcmNotifyCallback(WcmNoticeHead *message) {
    if (message == NULL) {
        return;
    }
    switch (message->mNotify) {
        case 1:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 4) {
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(6, 0);
                    }
                } else if (gExchangeWcmState == 6) {
                    if (func_ov000_021a61c4(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 8) {
                    if (func_ov000_021a5e84(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) ==
                        3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                }
            } else {
                gExchangeWcmState = 1;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(2, 0);
                }
            }
            break;
        case 3:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 6) {
                    gExchangeWcmState = 5;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(8, 0);
                    }
                }
            } else {
                gExchangeWcmState = 3;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(9, 0);
                }
            }
            break;
        case 5:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 8) {
                    gExchangeWcmState = 7;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(12, 0);
                    }
                }
            } else {
                gExchangeWcmState = 3;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(13, 0);
                }
            }
            break;
        case 4:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 4) {
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(10, 0);
                    }
                } else if (gExchangeWcmState == 6) {
                    if (func_ov000_021a61c4(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 2) {
                    if (func_ov000_021a61e4() == 3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 8) {
                    if (func_ov000_021a5e84(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) ==
                        3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                }
            } else {
                gExchangeWcmState = 3;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(11, 0);
                }
            }
            break;
        case 6:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 4) {
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(14, 0);
                    }
                } else if (gExchangeWcmState == 6) {
                    if (func_ov000_021a61c4(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 2) {
                    if (func_ov000_021a61e4() == 3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 8) {
                    if (func_ov000_021a5e84(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) ==
                        3) {
                        return;
                    }
                    gExchangeWcmState = 3;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(2, 0);
                    }
                } else if (gExchangeWcmState == 7) {
                    gExchangeWcmState = 3;
                }
            } else {
                gExchangeWcmState = 3;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(15, 0);
                }
            }
            break;
        case 2:
            if (message->mResult == 0) {
                if (gExchangeWcmState == 2) {
                    func_ov000_021a6428();
                    gExchangeWcmState = 0;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(20, 0);
                    }
                }
            } else {
                gExchangeWcmState = 3;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(2, 0);
                }
            }
            break;
        case 7:
            if (gExchangeWcmState == 5) {
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(5, 0);
                }
            }
            break;
        case 8:
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(4, 0);
            }
            break;
        case 9:
            gExchangeWcmState = 0;
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(3, 0);
            }
            break;
        default:
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(1, 0);
            }
            break;
    }
}

BOOL StartExchangeReturnToIdle(void) {
    switch (gExchangeWcmState) {
        case 5:
            if (func_ov000_021a61c4(NULL, NULL, 0) != 3) {
                return 0;
            }
            break;
        case 7:
            if (func_ov000_021a5db0() != 3) {
                return 0;
            }
            break;
        case 1:
            if (func_ov000_021a629c(gExchangeWcmConfig, (void (*)(Unk021a586c *)) ExchangeWcmNotifyCallback) != 3) {
                return 0;
            }
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        default:
            return 0;
    }
    return 1;
}

s32 CopyExchangeScanRecords(u8 *output, s32 maxCount) {
    s32 count;
    s32 i;

    func_ov000_021a67dc(1);
    count = func_ov000_021a6844();
    if (count > 0) {
        i = 0;
        if (count > 0) {
            do {
                if (i >= maxCount) {
                    break;
                }
                MIi_CpuCopy32(func_ov000_021a6788(i), output, 0xc0);
                i++;
                output += 0xc0;
            } while (i < count);
        }
    }
    func_ov000_021a67dc(0);
    return count;
}

BOOL StartExchangeSearch(u8 *address, u8 *name, s32 nameLength, u32 option) {
    u32 savedInterrupts = OS_DisableInterrupts();
    u8 *cursor;
    s32 i;

    gExchangeSearchOption = option;
    cursor = gExchangeSearchAddressBytes;
    gExchangeSearchAddress = cursor;
    if (address != NULL) {
        for (i = 0; i < 6; i++) {
            *cursor++ = *address++;
        }
    } else {
        MI_CpuFill8(cursor, 0xff, 6);
        gExchangeSearchAddress = WCM_Bssid_Any;
    }
    cursor = gExchangeSearchEssidBytes;
    gExchangeSearchEssid = cursor;
    if (name != NULL && nameLength > 0 && nameLength < 0x20) {
        i = 0;
        if (nameLength > 0) {
            do {
                *cursor++ = *name++;
                i++;
            } while (i < nameLength);
        }
        if (i < 0x20) {
            cursor = gExchangeSearchEssidBytes + i;
            do {
                *cursor++ = 0;
                i++;
            } while (i < 0x20);
        }
    } else {
        MI_CpuFill8(gExchangeSearchEssidBytes, 0xff, 0x20);
        gExchangeSearchEssid = WCM_Essid_Any;
    }
    if (gExchangeWcmState == 3) {
        if (func_ov000_021a61c4(gExchangeSearchAddressBytes, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
            gExchangeWcmState = 6;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    } else if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = 6;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL DisconnectExchange(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (gExchangeWcmState == 7) {
        if (func_ov000_021a5db0() == 3) {
            gExchangeWcmState = 4;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL CleanupExchangeWcm(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (gExchangeWcmState == 3) {
        if (func_ov000_021a61e4() != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = 2;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = 2;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL ConnectExchangeToEntry(void *entry, void *optionalBytes, u32 option) {
    u32 savedInterrupts = OS_DisableInterrupts();

    gExchangeConnectOption = option;
    if (optionalBytes != NULL) {
        MI_CpuCopy8(optionalBytes, gExchangeConnectBlock, 0x60);
    } else {
        MI_CpuFill8(gExchangeConnectBlock, 0, 0x60);
    }
    MIi_CpuCopy32(entry, gExchangeConnectRecord, 0xc0);
    if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = 8;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (gExchangeWcmState == 3) {
        if (func_ov000_021a5e84(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) == 3) {
            gExchangeWcmState = 8;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL InitExchangeWcm(void (*callback)(u32, u32), void *buffer, u32 size) {
    u32 savedInterrupts = OS_DisableInterrupts();
    WCMConfig *alignedBlock;
    u32 cursor;

    gExchangeConnectBlock = buffer;
    alignedBlock = (WCMConfig *) (((u32) buffer + 0x63) & ~3);
    gExchangeWcmConfig = alignedBlock;
    cursor = ((u32) alignedBlock + 0x2f) & ~0x1f;
    gExchangeWcmWork = (void *) cursor;
    cursor = (cursor + 0x231f) & ~0x1f;
    gExchangeConnectRecord = (Unk021a5e84 *) cursor;
    cursor = (cursor + 0xdf) & ~0x1f;
    alignedBlock->mPbdBuffer = (u8 *) cursor;
    gExchangeWcmConfig->mNbdBuffer = (u32) buffer + size - (u32) gExchangeWcmConfig->mPbdBuffer;
    gExchangeWcmConfig->mNbdMode = 0;
    gExchangeWcmConfig->mDmaNo = 3;
    gExchangeEventCallback = (UnkFunc *) callback;
    if (gExchangeWcmState == 0) {
        if (func_ov000_021a6470(gExchangeWcmWork, 0x2300) != 0) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = 1;
    }
    if (gExchangeWcmState == 1) {
        if (func_ov000_021a629c(gExchangeWcmConfig, (void (*)(Unk021a586c *)) ExchangeWcmNotifyCallback) != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = 4;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

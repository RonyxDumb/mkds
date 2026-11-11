#include "03/code_021ba818.h"
#include "00/code_021a5db0.h"
#include "00/code_021a5e84.h"
#include "00/code_021a61c4.h"
#include "00/code_021a61e4.h"
#include "00/code_021a629c.h"
#include "00/code_021a6428.h"
#include "00/code_021a6470.h"
#include "00/code_021a669c.h"
#include "00/code_021a6788.h"
#include "00/code_021a67dc.h"
#include "00/code_021a6844.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/unk_021b0000.h"

void EssidWcmNotifyCallback(s16 *event) {
    if (event == NULL) {
        return;
    }
    switch (event[0]) {
        case 1:
            if (event[1] == 0) {
                if (gEssidWcmState == 4) {
                    gEssidWcmState = 3;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(6, 0);
                    }
                } else if (gEssidWcmState == 6) {
                    if (func_ov000_021a61c4(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else if (gEssidWcmState == 8) {
                    if (func_ov000_021a5e84(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                }
            } else {
                gEssidWcmState = 1;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(2, 0);
                }
            }
            break;
        case 3:
            if (event[1] == 0) {
                if (gEssidWcmState == 6) {
                    gEssidWcmState = 5;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(8, 0);
                    }
                }
            } else {
                gEssidWcmState = 3;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(9, 0);
                }
            }
            break;
        case 5:
            if (event[1] == 0) {
                if (gEssidWcmState == 8) {
                    gEssidWcmState = 7;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(0xc, 0);
                    }
                }
            } else {
                gEssidWcmState = 3;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(0xd, 0);
                }
            }
            break;
        case 4:
            if (event[1] == 0) {
                if (gEssidWcmState == 4) {
                    gEssidWcmState = 3;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(0xa, 0);
                    }
                } else if (gEssidWcmState == 6) {
                    if (func_ov000_021a61c4(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else if (gEssidWcmState == 2) {
                    if (func_ov000_021a61e4() != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else if (gEssidWcmState == 8) {
                    if (func_ov000_021a5e84(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                }
            } else {
                gEssidWcmState = 3;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(0xb, 0);
                }
            }
            break;
        case 6:
            if (event[1] == 0) {
                if (gEssidWcmState == 4) {
                    gEssidWcmState = 3;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(0xe, 0);
                    }
                } else if (gEssidWcmState == 6) {
                    if (func_ov000_021a61c4(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else if (gEssidWcmState == 2) {
                    if (func_ov000_021a61e4() != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else if (gEssidWcmState == 8) {
                    if (func_ov000_021a5e84(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) != 3) {
                        gEssidWcmState = 3;
                        if (gEssidEventCallback != NULL) {
                            gEssidEventCallback(2, 0);
                        }
                    }
                } else {
                    gEssidWcmState = 3;
                }
            } else {
                gEssidWcmState = 3;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(0xf, 0);
                }
            }
            break;
        case 2:
            if (event[1] == 0) {
                if (gEssidWcmState == 2) {
                    func_ov000_021a6428();
                    gEssidWcmState = 0;
                    if (gEssidEventCallback != NULL) {
                        gEssidEventCallback(0x14, 0);
                    }
                }
            } else {
                gEssidWcmState = 3;
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(2, 0);
                }
            }
            break;
        case 7:
            if (gEssidWcmState == 5) {
                if (gEssidEventCallback != NULL) {
                    gEssidEventCallback(5, 0);
                }
            }
            break;
        default:
            if (gEssidEventCallback != NULL) {
                gEssidEventCallback(1, 0);
            }
            break;
    }
}

BOOL StartEssidReturnToIdle(void) {
    switch (gEssidWcmState) {
        case 5:
            if (func_ov000_021a61c4(NULL, NULL, 0) != 3) {
                return FALSE;
            }
            break;
        case 7:
            if (func_ov000_021a5db0() != 3) {
                return FALSE;
            }
            break;
        case 1:
            if (func_ov000_021a629c(gEssidWcmConfig, (void (*)(Unk021a586c *)) EssidWcmNotifyCallback) != 3) {
                return FALSE;
            }
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        default:
            return FALSE;
    }
    return TRUE;
}

s32 CopyEssidScanRecords(RawEntry *records, s32 maxCount) {
    s32 count;
    s32 i;
    func_ov000_021a67dc(1);
    count = func_ov000_021a6844();
    if (count > 0) {
        for (i = 0; i < count; i++, records++) {
            if (i >= maxCount) {
                break;
            }
            MIi_CpuCopy32(func_ov000_021a6788(i), records, 0xc0);
        }
    }
    func_ov000_021a67dc(0);
    return count;
}

BOOL StartEssidSearch(const u8 *addressBytes, const u8 *essidBytes, s32 essidLength, u32 option) {
    u32 enabled = OS_DisableInterrupts();
    s32 i;
    gEssidSearchOption = option;
    if (addressBytes != NULL) {
        for (i = 0; i < 6; i++) {
            gEssidSearchAddressBytes[i] = *addressBytes++;
        }
        gEssidSearchAddress = gEssidSearchAddressBytes;
    } else {
        MI_CpuFill8(gEssidSearchAddressBytes, 0xff, 6);
        gEssidSearchAddress = WCM_Bssid_Any;
    }
    if (essidBytes != NULL && essidLength > 0 && essidLength <= 0x20) {
        for (i = 0; i < essidLength; i++) {
            gEssidSearchEssidBytes[i] = *essidBytes++;
        }
        for (; i < 0x20; i++) {
            gEssidSearchEssidBytes[i] = 0;
        }
        gEssidSearchEssid = gEssidSearchEssidBytes;
    } else {
        MI_CpuFill8(gEssidSearchEssidBytes, 0xff, 0x20);
        gEssidSearchEssid = WCM_Essid_Any;
    }
    if (gEssidWcmState == 3) {
        if (func_ov000_021a61c4(gEssidSearchAddress, gEssidSearchEssid, gEssidSearchOption) == 3) {
            gEssidWcmState = 6;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    } else if (StartEssidReturnToIdle() == TRUE) {
        gEssidWcmState = 6;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL EndEssidSearch(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == 5) {
        if (func_ov000_021a61c4(NULL, NULL, 0) == 3) {
            gEssidWcmState = 4;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL DisconnectEssid(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == 7) {
        if (func_ov000_021a5db0() == 3) {
            gEssidWcmState = 4;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL CleanupEssidWcm(void) {
    u32 enabled = OS_DisableInterrupts();
    if (gEssidWcmState == 3) {
        if (func_ov000_021a61e4() != 3) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = 2;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    if (StartEssidReturnToIdle() == TRUE) {
        gEssidWcmState = 2;
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
        gEssidWcmState = 8;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    if (gEssidWcmState == 3) {
        if (func_ov000_021a5e84(gEssidConnectRecord, gEssidConnectBlock, gEssidConnectOption) == 3) {
            gEssidWcmState = 8;
            OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

BOOL InitEssidWcm(Unk021ba818Func *callback, u8 *buffer, s32 size) {
    u32 enabled = OS_DisableInterrupts();
    gEssidConnectBlock = (Unk02188de4 *) buffer;
    gEssidWcmConfig = (WCMConfig *) (((u32) buffer + 0x53) & ~3);
    gEssidWcmWork = (u8 *) (((u32) gEssidWcmConfig + 0x2f) & ~0x1f);
    gEssidConnectRecord = (Unk021a5e84 *) (((u32) gEssidWcmWork + 0x231f) & ~0x1f);
    gEssidWcmConfig->mPbdBuffer = (u8 *) (((u32) gEssidConnectRecord + 0xdf) & ~0x1f);
    gEssidWcmConfig->mNbdBuffer = (buffer + size) - gEssidWcmConfig->mPbdBuffer;
    gEssidWcmConfig->mNbdMode = 0;
    gEssidWcmConfig->mDmaNo = 3;
    gEssidEventCallback = callback;
    if (gEssidWcmState == 0) {
        if (func_ov000_021a6470((Unk021b5f50 *) gEssidWcmWork, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = 1;
    }
    if (gEssidWcmState == 1) {
        if (func_ov000_021a629c(gEssidWcmConfig, (void (*)(Unk021a586c *)) EssidWcmNotifyCallback) != 3) {
            OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        gEssidWcmState = 4;
        OS_RestoreInterrupts(enabled);
        return TRUE;
    }
    OS_RestoreInterrupts(enabled);
    return FALSE;
}

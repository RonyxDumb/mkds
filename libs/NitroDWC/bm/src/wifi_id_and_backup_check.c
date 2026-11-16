#include "wifi_id_and_backup_check.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_info.h"
#include "crc_checksum.h"
#include "tick_counter.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "clock_chip_access.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "reset_interrupts_halt.h"

const u8 DWCi_SETTING_NONE[4] = {0};

#pragma thumb on

BOOL DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *info, u8 *work) {
    DWCWiFiInfo stored;
    StructDW_MaybeCreate_from_thumb(&stored);
    info->mAttestedUserId = info->mNotAttestedId;
    info->mNotAttestedId = stored.mNotAttestedId;
    if (StructDW_SomeFn_0_from_thumb(info, work) != 0) {
        return 1;
    }
    return 0;
}

// Like StructDW_SomeFn_from_thumb, but always picks a new random history.
BOOL DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *info) {
    u8 vendor;
    u32 macLow;
    u8 mac[6] = {0, 0, 0, 0, 0, 0};
    RTCDate date;
    RTCTime time;
    s64 seconds;
    u32 seed;
    StructDW_MaybeCreate_from_thumb(info);
    Rtc_Initialize();
    if (Rtc_GetDate(&date) != 0) {
        return 0;
    }
    if (Rtc_GetTime(&time) != 0) {
        return 0;
    }
    seconds = ComputeTotalSeconds_EpochMaybe_from_thumb(&date, &time);
    seed = seconds;
    if (seconds < 0) {
        return 0;
    }
    if (Os_IsTickInitialized() != 0) {
        seed += (u32) Os_GetTick;
    }
    Os_GetMacAddress(mac);
    vendor = (mac[0] << 16 | mac[1] << 8 | mac[2]) != 0x9bf;
    macLow = mac[5];
    macLow |= (mac[3] << 16 | mac[4] << 8);
    seed = seed * 0x5d588b65 + 0x269ec3;
    info->mPass = ((seed >> 16) * 1000) >> 16;
    info->mNotAttestedId = 0;
    while (info->mNotAttestedId == 0) {
        seed = seed * 0x5d588b65 + 0x269ec3;
        while (seed == 0 || info->mRandomHistory == (u16) seed) {
            seed = seed * 0x5d588b65 + 0x269ec3;
        }
        info->mRandomHistory = seed;
        info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
    }
    return 1;
}

void StructDW_SomeFn_GetSomething_from_thumb(DWCAuthWiFiId *id) {
    DWCWiFiInfo info;
    StructDW_MaybeCreate_from_thumb(&info);
    id->mUId = info.mAttestedUserId;
    id->mNotAttestedId = info.mNotAttestedId;
    if (info.mAttestedUserId == 0) {
        id->mFlag = 0;
    } else {
        id->mFlag = 1;
    }
}

BOOL DWC_Auth_CheckWiFiIDNeedCreate(void) {
    DWCWiFiInfo info;
    StructDW_MaybeCreate_from_thumb(&info);
    if (info.mNotAttestedId == 0 && info.mAttestedUserId == 0) {
        return 1;
    }
    return 0;
}

// Checks and repairs the NVRAM backup pages; returns 0 or a negative error code.
s32 StructDC_SomeFn_2_from_thumb(u8 *work) {
    u32 valid[4];
    s32 pageIndex;
    u8 *page;
    u8 *apPage;
    u32 *validEntry;
    u32 dropped;
    u32 *validCheck;
    s32 validIndex;
    u32 crc;
    if (StructDC_SomeFn_3_from_thumb((u16 *) work) == 0) {
        return -10001;
    }
    SomeHashing(OFFSET_PTR(u16, work, 0x500), 0xa001);
    if (StructDC_SomeFn_1_from_thumb(work) == 0) {
        return -10001;
    }
    Mem_CpuFill8(valid, 0, sizeof(valid));
    pageIndex = 0;
    page = work;
    apPage = work;
    validEntry = valid;
    do {
        crc = Crc16(OFFSET_PTR(u16, work, 0x500), page, 0xfe);
        if (crc == *OFFSET_PTR(u16, page, 0xfe)) {
            if (StructDCSub_SomeFn_from_thumb(apPage) != 0) {
                *validEntry = 1;
            }
        }
        page += 0x100;
        apPage += 0x100;
        validEntry++;
        pageIndex++;
    } while (pageIndex < 3);
    crc = Crc16(OFFSET_PTR(u16, work, 0x500), work + 0x300, 0xfe);
    if (crc == *OFFSET_PTR(u16, work, 0x3fe)) {
        valid[3] = 1;
    }
    if (valid[0] != 0 && valid[1] != 0 && valid[2] != 0 && valid[3] != 0) {
        WritePackedWiFiInfo(work + 0xf0);
        return 0;
    }
    if (valid[0] == 0 && valid[1] == 0 && valid[2] == 0 && valid[3] == 0) {
        StructDC_SomeFn_from_thumb(work);
        if (StructDC_SomeFn_0_from_thumb(work) != 0) {
            return 0;
        }
        return -10000;
    }
    if ((valid[0] == 0 || valid[1] == 0) && (valid[2] == 0 || valid[3] == 0)) {
        StructDC_SomeFn_from_thumb(work);
        if (StructDC_SomeFn_0_from_thumb(work) != 0) {
            return 0;
        }
        return -10000;
    }
    if (valid[0] == 0 && valid[1] == 0) {
        StructDC_SomeFn_from_thumb(work);
        if (StructDC_SomeFn_0_from_thumb(work) != 0) {
            return -10003;
        }
        return -10000;
    }
    if (valid[0] == 0) {
        StructDC_CleanDCSub_from_thumb(work, 0);
        Mem_CpuCopy8(work + 0x1f0, work + 0xf0, 0xd);
        work[0xef] = work[0x1ef];
    } else if (valid[1] == 0) {
        StructDC_CleanDCSub_from_thumb(work, 1);
        Mem_CpuCopy8(work + 0xf0, work + 0x1f0, 0xd);
        work[0x1ef] = work[0xef];
    }
    WritePackedWiFiInfo(work + 0xf0);
    if (valid[2] == 0) {
        StructDC_CleanDCSub_from_thumb(work, 2);
    }
    if (valid[3] == 0) {
        vu16 zero = 0;
        Mem_CpuFill16(zero, work + 0x300, 0x100);
    }
    dropped = 0;
    validIndex = 0;
    validCheck = valid;
    for (; validIndex < 3; validCheck++, validIndex++) {
        if (*validCheck == 0) {
            crc = 1 << validIndex;
            if ((work[0xef] & crc) != 0) {
                work[0xef] &= ~crc;
                dropped = 1;
            }
        }
    }
    if (StructDC_SomeFn_0_from_thumb(work) == 0) {
        return -10000;
    }
    if (dropped != 0) {
        return -10002;
    }
    return 0;
}

BOOL StructDCSub_SomeFn_from_thumb(const u8 *ap) {
    u8 netmask[8];
    u8 setType;
    setType = ap[0xe7];
    if (setType == 0xff) {
        return 1;
    }
    if (setType > 2) {
        return 0;
    }
    if (StructDCInner_HasAnyUnk_from_thumb(ap + 0x40) == 0) {
        return 0;
    }
    if (StructDC_SomeFn_6(ap + 0xc0, DWCi_SETTING_NONE, 4) != 0) {
        if (DWC_BACKUPlCheckAddress(ap + 0xc4) == 0) {
            return 0;
        }
        if (ap[0xd0] > 0x20) {
            return 0;
        }
        DWCi_BACKUPlConvMaskAddr(ap[0xd0], netmask);
        if (DWC_BACKUPlCheckIp(ap + 0xc0, netmask) == 0) {
            return 0;
        }
    }
    if (StructDC_SomeFn_6(ap + 0xc8, DWCi_SETTING_NONE, 4) != 0) {
        if (DWC_BACKUPlCheckAddress(ap + 0xc8) == 0 && DWC_BACKUPlCheckAddress(ap + 0xcc) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 StructDC_SomeFn_from_thumb(u8 *work) {
    vu16 zero;
    s32 pageIndex;
    u8 *page;
    u8 *wifiPage;
    DWCWiFiInfo info;
    u8 *packed;
    zero = 0;
    Mem_CpuFill16(zero, work, 0x400);
    pageIndex = 0;
    page = work;
    for (; pageIndex < 3; pageIndex++) {
        page[0xe7] = 0xff;
        page += 0x100;
    }
    StructDW_SomeFn_from_thumb(&info);
    packed = StructDW_SomeFn_2_from_thumb(&info);
    wifiPage = work;
    for (pageIndex = 0; pageIndex < 2; pageIndex++) {
        Mem_CpuCopy8(packed, wifiPage + 0xf0, 0xe);
        wifiPage += 0x100;
    }
    return 0;
}

void StructDC_CleanDCSub_from_thumb(u8 *work, u32 page) {
    vu16 zero;
    u32 offset;
    zero = 0;
    offset = page << 8;
    Mem_CpuFill16(zero, work + offset, 0x100);
    (work + offset)[0xe7] = 0xff;
}

#pragma thumb off

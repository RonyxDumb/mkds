#include "wifi_settings_nvram_backup.h"
#include "crc_checksum.h"
#include "cpu_copy_fill.h"
#include "reset_interrupts_halt.h"
#include "overlay_section_symbols.h"
#include "arena_cache_init.h"
#include "arm_fifo_messaging.h"
#include "tick_counter.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "thread_scheduler.h"
#include "bios_calls.h"

u16 nv_result = 0;
u32 gNvramEntriesOffset = 0;
u8 gPackedWiFiInfo[32] = {0};
u32 nv_cb_occurred = 0;
u8 Work[32] = {0};

#pragma thumb on

void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf) {
    MI_CpuCopy8(gPackedWiFiInfo, buf, 6);
    buf->mAttestedUserId &= ~0xfffff80000000000ULL;
    MI_CpuCopy8(gPackedWiFiInfo + 5, &buf->mNotAttestedId, 6);
    buf->mNotAttestedId >>= 3;
    buf->mNotAttestedId &= ~0xfffff80000000000ULL;
    MI_CpuCopy8(gPackedWiFiInfo + 10, &buf->mPass, 2);
    buf->mPass = buf->mPass >> 6;
    buf->mPass &= 0x3ff;
    MI_CpuCopy8(gPackedWiFiInfo + 12, &buf->mRandomHistory, 2);
}

BOOL DWCi_BM_SetWiFiInfo(const DWCWiFiInfo *info, u8 *work) {
    u32 address;
    s32 page;
    address = gNvramEntriesOffset;
    DWCi_BACKUPlConvWifiInfo(info);
    Crc16InitTable(OFFSET_PTR(u16, work, 0x200), 0xa001);
    for (page = 0; page < 2;) {
        if (readNvram(address, 0x100, work) == 0) {
            OS_Terminate();
            return 0;
        }
        MI_CpuCopy8(gPackedWiFiInfo, work + 0xf0, 0xe);
        *OFFSET_PTR(u16, work, 0xfe) = Crc16(OFFSET_PTR(u16, work, 0x200), work, 0xfe);
        do {
            writeNvram(address, 0x100, work);
        } while (verify(work, address, 0x100, work + 0x100) == 0);
        page++;
        address += 0x100;
    }
    if (writeDisable() != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 ReadNvramEntriesOffset(u16 *buffer) {
    int readResult;
    readResult = readNvram(0x20, 0x20, buffer);
    if (readResult == 0) {
        return 0;
    }
    gNvramEntriesOffset = *buffer * 8 - 0x400;
    return 1;
}

u32 ReadNvramEntries(void *buffer) {
    int readResult;
    readResult = readNvram(gNvramEntriesOffset, 0x400, buffer);
    if (readResult != 0) {
        return 1;
    }
    return 0;
}

u32 WriteFlaggedNvramEntries(void *data, int *flags, void *verifyBuffer) {
    int verifyResult;
    int entrySize;
    int disableResult;
    int address;
    int *flagPointer;
    int entryIndex;
    entrySize = 0x100;
    address = gNvramEntriesOffset;
    entryIndex = 0;
    flagPointer = flags;
    do {
        if (*flagPointer != 0) {
            do {
                writeNvram(address, entrySize, data);
                verifyResult = verify(data, address, entrySize, verifyBuffer);
            } while (verifyResult == 0);
        }
        flagPointer = flagPointer + 1;
        data = data + entrySize;
        entryIndex = entryIndex + 1;
        address = address + entrySize;
    } while (entryIndex < 4);
    disableResult = writeDisable();
    if (disableResult != 0) {
        return 1;
    }
    return 0;
}

u32 WriteNvramEntriesWithCrc16(u8 *data) {
    int entryIndex;
    int address;
    u8 *entry;
    int entrySize;
    int disableResult;
    int verifyResult;
    u16 crc;
    entrySize = 0x100;
    address = gNvramEntriesOffset;
    entryIndex = 0;
    entry = data;
    do {
        crc = Crc16(OFFSET_PTR(const u16, data, 0x500), entry, 0xfe);
        *OFFSET_PTR(u16, entry, 0xfe) = crc;
        do {
            writeNvram(address, entrySize, entry);
            verifyResult = verify(entry, address, entrySize, OFFSET_PTR(const u8, data, 0x400));
        } while (verifyResult == 0);
        entry = entry + entrySize;
        entryIndex = entryIndex + 1;
        address = address + entrySize;
    } while (entryIndex < 4);
    disableResult = writeDisable();
    if (disableResult != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void WritePackedWiFiInfo(const u8 *packedWiFiInfo) {
    MI_CpuCopy8(packedWiFiInfo, gPackedWiFiInfo, 14);
}
#pragma thumb off

#pragma thumb on

u8 DWCi_BACKUPlConvMaskCidr(const u8 *mask) {
    s32 count;
    s32 byteIndex;
    s32 bit;
    u8 value;
    byteIndex = 0;
    count = 0;
    for (; byteIndex < 4; byteIndex++) {
        bit = 0;
        value = mask[byteIndex];
        for (; bit < 8; bit++) {
            if ((value >> bit) & 1) {
                count++;
            }
        }
    }
    return count;
}

void DWCi_BACKUPlConvMaskAddr(u32 mask, u8 *buf) {
    s32 byteIndex;
    u32 value;
    u32 bitOffset;
    byteIndex = 0;
    value = ((u32) ~byteIndex >> mask) ^ ~byteIndex;
    bitOffset = byteIndex;
    for (; byteIndex < 4; byteIndex++) {
        buf[byteIndex] = value >> (0x18 - bitOffset);
        bitOffset += 8;
    }
}

BOOL DWC_BACKUPlCheckSsid(const u8 *ssid) {
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < 0x20; byteIndex++) {
        if (ssid[byteIndex] != 0) {
            return 1;
        }
    }
    return 0;
}

BOOL DWC_BACKUPlCheckIp(const u8 *ip, const u8 *mask) {
    u32 words[2];
    if (DWC_BACKUPlCheckAddress(ip) == 0) {
        return 0;
    }
    MI_CpuCopy8(ip, &words[0], 4);
    MI_CpuCopy8(mask, &words[1], 4);
    if ((words[0] | words[1]) == 0xfffffffe) {
        return 0;
    }
    if ((words[0] & ~words[1]) == 0) {
        return 0;
    }
    return 1;
}

BOOL DWC_BACKUPlCheckAddress(const u8 *address) {
    u8 first = *address;
    if (first == 0x7f) {
        return 0;
    }
    if (first < 1) {
        return 0;
    }
    if (first <= 0xdf) {
        return 1;
    }
    return 0;
}

static inline u32 SendSixWords(u32 tag, u32 firstWord, u32 secondWord, u32 thirdWord, u32 fourthWord, u32 fifthWord,
                               u32 sixthWord) {
    if (PXI_SendWordByFifo(tag, firstWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, secondWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, thirdWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, fourthWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, fifthWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, sixthWord, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 sendThreeWords(u32 tag, u32 firstWord, u32 secondWord, u32 thirdWord) {
    if (PXI_SendWordByFifo(tag, firstWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, secondWord, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, thirdWord, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 sendOneWord(u32 tag, u32 word) {
    if (PXI_SendWordByFifo(tag, word, 0) >= 0) {
        return 1;
    }
    return 0;
}

BOOL NVRAMm_ExecuteCommand(u32 nv_state, u32 addr, u16 size, u8 *srcp) {
    u32 sending;
    u32 tag;
    u32 bufAddr;
    u32 readHeader;
    u32 sizeWord;
    u32 readBufHigh;
    u32 readBufLow;
    u32 writeHeader;
    u32 writeBufHigh;
    u32 statusHigh;
    u32 statusMid;
    u32 statusLow;
    u64 start;
    sending = 0;
    writeHeader = (addr >> 16) & 0xff;
    readHeader = writeHeader;
    readHeader |= 0x2002300;
    addr &= 0xffff;
    addr |= 0x10000;
    sizeWord = size;
    sizeWord &= 0xffff;
    sizeWord |= 0x30000;
    bufAddr = (u32) srcp;
    writeBufHigh = bufAddr;
    writeBufHigh >>= 16;
    readBufHigh = writeBufHigh;
    readBufHigh |= 0x40000;
    bufAddr &= 0xffff;
    readBufLow = bufAddr;
    readBufLow |= 0x1050000;
    writeHeader |= 0x2002500;
    writeBufHigh |= 0x30000;
    bufAddr |= 0x1040000;
    statusHigh = (u32) &Work >> 24;
    statusHigh |= 0x2002200;
    statusMid = (u32) &Work >> 8;
    statusMid &= 0xffff;
    statusMid |= 0x10000;
    statusLow = (u32) &Work << 8;
    statusLow &= 0xff00;
    statusLow |= 0x1020000;
    tag = 4;
    while (1) {
        if (sending == 0) {
            nv_cb_occurred = 0;
            switch (nv_state) {
                case NVRAM_STATE_READ:
                    sending = SendSixWords(tag, readHeader, addr, 0x20000, sizeWord, readBufHigh, readBufLow);
                    break;
                case NVRAM_STATE_WRITE_ENABLE:
                    sending = sendOneWord(tag, 0x3002000);
                    break;
                case NVRAM_STATE_PAGE_WRITE:
                    if (PXI_SendWordByFifo(tag, writeHeader, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, addr, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, size | 0x20000, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, writeBufHigh, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, bufAddr, 0) < 0) {
                        sending = 0;
                    } else {
                        sending = 1;
                    }
                    start = OS_GetTick();
                    break;
                case NVRAM_STATE_CHECK_WRITE_ENABLED:
                case NVRAM_STATE_WAIT_WRITE_DONE:
                    sending = sendThreeWords(tag, statusHigh, statusMid, statusLow);
                    break;
                case NVRAM_STATE_WRITE_FAILED:
                    sending = sendOneWord(tag, 0x3002d00);
                    break;
                case NVRAM_STATE_FINISH:
                    sending = sendOneWord(tag, 0x3002100);
                    break;
            }
        } else if (nv_cb_occurred == 1) {
            sending = 0;
            if (nv_result != 0) {
                break;
            }
            switch (nv_state) {
                case NVRAM_STATE_READ:
                    return 1;
                case NVRAM_STATE_WRITE_ENABLE:
                    nv_state = tag;
                    break;
                case NVRAM_STATE_PAGE_WRITE:
                    nv_state = NVRAM_STATE_WAIT_WRITE_DONE;
                    break;
                case NVRAM_STATE_CHECK_WRITE_ENABLED:
                case NVRAM_STATE_WAIT_WRITE_DONE:
                    DC_InvalidateRange(&Work, 1);
                    if (nv_state == NVRAM_STATE_CHECK_WRITE_ENABLED) {
                        if (Work[0] & 2) {
                            nv_state = NVRAM_STATE_PAGE_WRITE;
                            break;
                        }
                        return 0;
                    }
                    if ((Work[0] & 1) == 0) {
                        return 1;
                    }
                    if ((Work[0] & 0x20) != 0 || ((OS_GetTick() - start) * 64) / 33514 > 4000) {
                        nv_state = NVRAM_STATE_WRITE_FAILED;
                    } else {
                        SVC_WaitByLoop(0x4000);
                    }
                    break;
                case NVRAM_STATE_WRITE_FAILED:
                    return sending;
                case NVRAM_STATE_FINISH:
                    return 1;
            }
        }
    }
    return sending;
}

BOOL readNvram(u32 address, u32 size, void *buf) {
    u32 tag;
    DC_InvalidateRange(buf, size);
    tag = 4;
    while (PXI_IsCallbackReady(tag, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (PXIFifoCallback) Callback_NVRAM);
    tag = NVRAM_STATE_READ;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, address, size, buf) == 1) {
            break;
        }
        SVC_WaitByLoop(0x40000);
    }
    DC_InvalidateRange(buf, size);
    return 1;
}

void writeNvram(u32 address, u16 size, void *data) {
    u32 tag;
    tag = 4;
    while (PXI_IsCallbackReady(tag, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (PXIFifoCallback) Callback_NVRAM);
    DC_StoreRange(data, size);
    tag = NVRAM_STATE_WRITE_ENABLE;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, address, size, data) == 1) {
            break;
        }
        SVC_WaitByLoop(0x40000);
    }
}

BOOL verify(const u8 *src, u32 address, u32 size, const u8 *work) {
    if (readNvram(address, size, work) == 0) {
        return 0;
    }
    if (memcmp(src, work, size) == 0) {
        return 1;
    }
    return 0;
}

BOOL writeDisable(void) {
    u32 tag;
    u32 proc;
    u32 delay;
    u32 zero;
    tag = 4;
    proc = 1;
    while (PXI_IsCallbackReady(tag, proc) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (PXIFifoCallback) Callback_NVRAM);
    delay = 0x40000;
    tag = 7;
    zero = 0;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, zero, zero, (u8 *) zero) == 1) {
            break;
        }
        SVC_WaitByLoop(delay);
    }
    return 1;
}

u16 Callback_NVRAM(u32 tag, u32 data, u32 err) {
    nv_result = data & 0xff;
    nv_cb_occurred = 1;
    if (err != 0) {
        nv_result = 0xff;
    }
    return nv_result;
}

u8 *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info) {
    u64 notAttestedId;
    u32 byte5;
    u32 byte10;
    notAttestedId = info->mNotAttestedId;
    MI_CpuCopy8(info, gPackedWiFiInfo, 5);
    byte5 = ((u32) (info->mAttestedUserId >> 32) >> 8) & 7;
    byte5 |= ((u32) notAttestedId & 0x1f) << 3;
    gPackedWiFiInfo[5] = byte5;
    notAttestedId >>= 5;
    MI_CpuCopy8(&notAttestedId, gPackedWiFiInfo + 6, 4);
    byte10 = (u32) (notAttestedId >> 32) & 0x3f;
    byte10 |= (info->mPass & 3) << 6;
    gPackedWiFiInfo[10] = byte10;
    gPackedWiFiInfo[11] = info->mPass >> 2;
    MI_CpuCopy8(&info->mRandomHistory, gPackedWiFiInfo + 12, 2);
    return gPackedWiFiInfo;
}

#pragma thumb off

#include "Main/Unknown/code_02151708.h"

#include "Main/Unknown/code_02151718.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_020205b0.h"
#include "code_0214d018.h"
#include "code_021510a4.h"

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

u32 WriteFlaggedNvramEntries(int data, int *flags, void *verifyBuffer) {
    int verifyResult;
    int v2;
    int address;
    int *flagPointer;
    int entryIndex;
    v2 = 0x100;
    address = gNvramEntriesOffset;
    entryIndex = 0;
    flagPointer = flags;
    do {
        if (*flagPointer != 0) {
            do {
                writeNvram(address, v2, (void *) data);
                verifyResult = verify((const u8 *) data, address, v2, verifyBuffer);
            } while (verifyResult == 0);
        }
        flagPointer = flagPointer + 1;
        data = data + v2;
        entryIndex = entryIndex + 1;
        address = address + v2;
    } while (entryIndex < 4);
    v2 = writeDisable();
    if (v2 != 0) {
        return 1;
    }
    return 0;
}

u32 WriteNvramEntriesWithCrc16(u8 *data) {
    int entryIndex;
    int address;
    u8 *entry;
    int v4;
    int verifyResult;
    u16 crc;
    v4 = 0x100;
    address = gNvramEntriesOffset;
    entryIndex = 0;
    entry = data;
    do {
        crc = Crc16(OFFSET_PTR(const u16, data, 0x500), entry, 0xfe);
        *OFFSET_PTR(u16, entry, 0xfe) = crc;
        do {
            writeNvram(address, v4, entry);
            verifyResult = verify(entry, address, v4, OFFSET_PTR(const u8, data, 0x400));
        } while (verifyResult == 0);
        entry = entry + v4;
        entryIndex = entryIndex + 1;
        address = address + v4;
    } while (entryIndex < 4);
    v4 = writeDisable();
    if (v4 != 0) {
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

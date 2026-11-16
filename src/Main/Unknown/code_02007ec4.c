#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_020091fc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 MB_RegisterFile(void *rangeTable, Unk02008188 *source) {
    u32 entryIndex;
    u32 savedInterrupts;
    u32 entryOffset;
    Unk0216fdac *work;
    Unk020082b4 *record;
    u8 i;
    entryIndex = 0xff;
    savedInterrupts = OS_DisableInterrupts();
    if (func_02009958() == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    work = data_0216fdac;
    if (work->mEntryCount + 1 > 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    for (i = 0; i < 0x10; i++) {
        if ((OFFSET_PTR(Unk0216fdac, work, i * 0x5d4))->field1D40 == rangeTable) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        if ((OFFSET_PTR(Unk0216fdac, work, i * 0x5d4))->mEntryUsed == 0) {
            entryIndex = i;
            break;
        }
    }
    if (i == 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    entryOffset = entryIndex * 0x5d4;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D40 = rangeTable;
    record = (Unk020082b4 *) (data_0216fdac->field1788 + entryOffset);
    MBi_MakeDownloadFileInfo(record, source);
    MI_CpuCopy8((u8 *) rangeTable + 0x1c, record->fieldC4, 0x20);
    if (MBi_MakeBlockInfoTable((ChunkTable *) (data_0216fdac->field1D2C + entryOffset), record) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    func_02009828((GameInfoEntry *) (data_0216fdac->field1788 + 0xe4 + entryOffset), rangeTable,
                  (const u8 *) &data_0216fdac->field1300);
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D21 = entryIndex;
    AppendGameInfoEntry((GameInfoEntry *) (data_0216fdac->field1788 + 0xe4 + entryOffset));
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D1F = data_0216fc30++;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D4E = 1;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D44 = source;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D54 = &source->field1E8;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D58 = source->field258;
    if ((OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->field1D54->field30[3].fieldC != 0) {
        if (CTRDGi_IsTaskAvailable() == 0) {
            CTRDGi_InitTaskInfo(data_0216fdac->field7CE0);
            CTRDGi_InitTaskThread(&data_0216fdac->field74E0, 0x800);
        }
    }
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mEntryUsed = 1;
    data_0216fdac->mEntryCount++;
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

void MBi_MakeDownloadFileInfo(Unk020082b4 *record, Unk02008188 *source) {
    u32 nextAddress;
    u8 *headerTail;
    u32 *kinds;
    Unk020082b4_0c *range;
    s32 i;
    nextAddress = 0x022c0000;
    headerTail = source->field160;
    record->field0 = source->field24;
    record->field4 = source->field34;
    range = record->fieldC;
    kinds = data_02152bc0;
    for (i = 0; i < 3; i++) {
        MBi_SetSegmentInfo(source, kinds, range, &nextAddress);
        range++;
        kinds++;
    }
    MI_CpuCopy8(headerTail, record->field3C, 0x88);
}

void MBi_SetSegmentInfo(Unk02008188 *source, u32 *kindWord, Unk020082b4_0c *range, u32 *nextAddress) {
    u32 outOfBounds;
    u32 useNextAddress;
    u32 *pair;
    u32 end;
    switch (*kindWord) {
        case 0:
            pair = source->field28;
            if (source->field28[0] >= 0x02000000 && source->field28[0] < 0x022c0000 &&
                source->field28[0] + pair[1] <= 0x022c0000) {
                range->field8 = pair[1];
                range->field4 = pair[0];
                range->field0 = range->field4;
                range->fieldC &= ~1;
                return;
            }
            OS_Terminate();
            return;
        case 1:
            outOfBounds = 0;
            useNextAddress = 0;
            pair = source->field38;
            end = source->field38[0] + pair[1];
            if (source->field38[0] >= 0x02000000 && source->field38[0] < 0x023fe800) {
                if (end > 0x02300000) {
                    if (end < 0x023fe800 && pair[1] <= 0x40000) {
                        useNextAddress = 1;
                    } else {
                        outOfBounds = 1;
                    }
                }
            } else if (source->field38[0] >= 0x037f8000 && source->field38[0] < 0x0380f000) {
                if (end <= 0x0380f000) {
                    useNextAddress = 1;
                } else {
                    outOfBounds = 1;
                }
            } else {
                outOfBounds = 1;
            }
            if (outOfBounds == 1) {
                OS_Terminate();
            }
            range->field8 = pair[1];
            range->field4 = pair[0];
            if (useNextAddress == 0) {
                range->field0 = range->field4;
            } else {
                range->field0 = *nextAddress;
                *nextAddress = *nextAddress + range->field8;
            }
            range->fieldC = (range->fieldC & ~1) | 1;
            return;
        case 2:
            range->field8 = 0x160;
            range->field4 = 0x027ffe00;
            range->field0 = range->field4;
            range->fieldC &= ~1;
            return;
    }
}

static inline struct Unk0216fdac *func_0200806c_inline(void) {
    return data_0216fdac;
}

u32 MBi_MakeBlockInfoTable(ChunkTable *chunkTable, Unk020082b4 *record) {
    u32 offset;
    u16 nextChunk;
    u8 i;
    Unk020082b4_0c *range;
    u16 *chunkStarts;
    chunkStarts = chunkTable->fieldC;
    offset = 0;
    if (record == NULL) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        chunkTable->field0[i] = offset;
        offset += record->fieldC[i].field8;
    }
    chunkStarts[0] = 0;
    for (i = 0; i < 3; i++) {
        range = &record->fieldC[i];
        nextChunk = chunkStarts[i] + (u16) ((range->field8 + data_0216fdac->field1318 - 1) / data_0216fdac->field1318);
        if (IsAbleToLoad(i, range->field4, range->field8) == 0) {
            return 0;
        }
        if (i < 2) {
            chunkStarts[i + 1] = nextChunk;
        } else {
            chunkTable->fieldC[3] = nextChunk;
        }
    }
    return 1;
}

BOOL MBi_get_blockinfo(Unk020072c0_buf *result, void *b, u16 chunk, void *d) {
    u32 offset;
    Unk020082b4 *record;
    Unk020082b4_0c *range;
    ChunkTable *chunkTable;
    s8 i;
    chunkTable = b;
    record = d;
    if (chunk >= chunkTable->fieldC[3]) {
        return FALSE;
    }
    for (i = 2; i >= 0; i--) {
        if (chunk >= chunkTable->fieldC[i]) {
            break;
        }
    }
    if (i < 0) {
        return FALSE;
    }
    offset = (chunk - chunkTable->fieldC[i]) * func_0200806c_inline()->field1318;
    range = &record->fieldC[i];
    result->field4 = range->field8 - offset;
    if (result->field4 > data_0216fdac->field1318) {
        result->field4 = data_0216fdac->field1318;
    }
    result->field8 = offset + chunkTable->field0[i];
    result->field0 = offset + range->field0;
    result->fieldC = i;
    return TRUE;
}

u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size) {
    switch (data_02152bc0[rangeIndex]) {
        case 2:
            if (address >= 0x027ffe00 && address + size <= 0x027fff60) {
                return 1;
            }
            break;
        case 0:
            if (address >= 0x02000000 && address + size <= 0x022c0000) {
                return 1;
            }
            break;
        case 1:
            if (address >= 0x022c0000 && address + size <= 0x02300000) {
                return 1;
            }
            if (address >= 0x02000000 && address + size <= 0x02300000) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

u32 IsAbleToLoad(u32 rangeIndex, u32 address, u32 size) {
    u32 end;
    switch (data_02152bc0[rangeIndex]) {
        case 0:
        case 2:
            return MBi_IsAbleToRecv(rangeIndex, address, size);
        case 1:
            if (address >= 0x02000000 && address < 0x023fe800) {
                end = address + size;
                if (address < 0x02300000 && end > 0x02300000) {
                    return 0;
                }
                if (end <= 0x02300000) {
                    return 1;
                }
                if (end < 0x023fe800 && size <= 0x40000) {
                    return 1;
                }
                return 0;
            }
            if (address >= 0x037f8000 && address < 0x0380f000) {
                if (address + size <= 0x0380f000) {
                    return 1;
                }
                return 0;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

void func_02007ec4(ScanBlock *record, u16 b, u16 c, u32 d, u32 e) {
    u32 v1;
    u32 v2;
    u16 *p = (u16 *) 0x027ffc40;
    MI_CpuCopy8(*p == 2 ? (void *) (p + 1) : (void *) 0, record, 0x3c);
    record->field3C = 0x10;
    record->field44 = record->fieldC | (record->fieldE << 16);
    record->field48 = record->field10;
    record->field4A = 0;
    record->field4C = b;
    record->field4E = c;
    v1 = 0;
    if (e != 0) {
        v1 = 8;
    }
    if (d != 0) {
        v2 = 4;
    } else {
        v2 = 0;
    }
    record->field4B = v2 | v1 | 1;
}

#pragma thumb off

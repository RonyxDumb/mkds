#include "Main/Unknown/code_02008570.h"
#include "Main/Unknown/code_0200850c.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02000a58.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0200aea8.h"
#include "code_02003024.h"
#include "code_02003be0.h"
#include "fs_file.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

static inline u32 func_02008570_inline(Unk02008570Header *a) {
    u32 b = a->field80;
    if (b == 0) {
        b = 0x01000000;
    }
    return b;
}

int MB_ReadSegment(FSFile *file, void *buffer, u32 bufferSize) {
    FSFile *activeFile;
    Unk02008570Header *header;
    u8 *v3;
    FSFile openedFile;
    BOOL result;
    BOOL openedHere;
    u32 remaining;
    u32 basePosition;
    DataRangeTable *rangeTable;
    u32 *v6;
    s32 v8;
    u32 seekOffset;
    s32 v10;
    u32 v14[4];
    s8 *arcBytes;
    activeFile = file;
    header = buffer;
    result = FALSE;
    if (bufferSize >= 0x164) {
        openedHere = FALSE;
        remaining = bufferSize;
        v3 = (u8 *) header;
        rangeTable = NULL;
        v6 = NULL;
        v3 += 0x160;
        remaining -= 0x160;
        if (activeFile != NULL) {
            basePosition = activeFile->field2C - activeFile->mProp.w.field4;
            if (FS_ReadFile(activeFile, header, 0x160) < 0x160) {
                remaining = 0;
            }
            seekOffset = func_02008570_inline(header);
        } else {
            seekOffset = func_02008570_inline((Unk02008570Header *) 0x027ffe00);
            openedHere = TRUE;
            FS_InitFile(&openedFile);
            FS_OpenFileDirect(&openedFile, FS_FindArchive(aRom_3, 3), 0, seekOffset + 0x88, -1);
            activeFile = &openedFile;
            basePosition = openedFile.field2C - openedFile.mProp.w.field4;
            MI_CpuCopy8((const void *) 0x027ffe00, header, 0x160);
            header->field60 |= 0x00406000;
        }
        if (remaining >= 0x88) {
            FS_SeekFile(activeFile, basePosition + seekOffset, 0);
            FS_ReadFile(activeFile, v3, 0x88);
            v3 += 0x88;
            remaining -= 0x88;
        } else {
            remaining = 0;
        }
        if (remaining >= 0x70) {
            rangeTable = (DataRangeTable *) v3;
            ClearDataRangeTable((u32) v3);
            v3 += 0x70;
            remaining -= 0x70;
            AddDataRange(rangeTable, 0, 0x160, (u8 *) header, 3);
            arcBytes = (s8 *) activeFile->mArc;
            v10 = 0;
            while (v10 < 3 && arcBytes[v10] != 0) {
                v10++;
            }
            MI_CpuCopy8(arcBytes, rangeTable->field10, v10);
            rangeTable->field14 = v10;
        } else {
            remaining = 0;
        }
        if (remaining >= 0x10) {
            v6 = (u32 *) v3;
            v6[0] = 0;
            v6[1] = header->field20 + (basePosition + activeFile->mProp.w.field4);
            v6[2] = header->field30 + (basePosition + activeFile->mProp.w.field4);
            v3 += 0x10;
            remaining -= 0x10;
        } else {
            remaining = 0;
        }
        v8 = header->field2C + header->field3C;
        if (remaining >= v8) {
            v10 = activeFile->mProp.w.field4;
            FS_SeekFile(activeFile, v6[1] - v10, 0);
            FS_ReadFile(activeFile, v3, header->field2C);
            AddDataRange(rangeTable, v6[1], header->field2C, v3, 3);
            v3 += header->field2C;
            FS_SeekFile(activeFile, v6[2] - v10, 0);
            FS_ReadFile(activeFile, v3, header->field3C);
            AddDataRange(rangeTable, v6[2], header->field3C, v3, 3);
            result = TRUE;
        } else if (remaining >= 0xcc00) {
            v10 = activeFile->mProp.w.field4;
            v8 = v6[1];
            FS_SeekFile(activeFile, v8 - v10, 0);
            FS_ReadFile(activeFile, v3, 0x4400);
            AddDataRange(rangeTable, v8, 0x4400, v3, 3);
            FS_SeekFile(activeFile, v8 + 0x4400 - v10, 0);
            FS_ReadFile(activeFile, v3 + 0x4400, 0x4400);
            AddDataRange(rangeTable, v8 + 0x4400, 0x4400, (v3 + 0x4400), 2);
            FS_SeekFile(activeFile, v8 + 0x8800 - v10, 0);
            FS_ReadFile(activeFile, v3 + 0x8800, 0x4400);
            AddDataRange(rangeTable, v8 + 0x8800, 0x4400, (v3 + 0x8800), 2);
            result = TRUE;
        }
        FS_SeekFile(activeFile, basePosition, 0);
        if (openedHere != FALSE) {
            FS_CloseFile(&openedFile);
            if (result != FALSE) {
                v6 = data_02161788;
                v14[0] = header->field20;
                v14[1] = header->field28 - header->field20;
                v14[2] = (u32) rangeTable->field30[1].mData - header->field20;
                v14[3] = bufferSize;
                MBi_ReadSegmentHeader(v14, 0x4000, 0x8000, 1);
                while (((s32 *) v6)[1] != 0) {
                    MBi_ReadSegmentHeader(v14, v6[0], v6[0] + v6[1], 0);
                    v6 += 2;
                }
                v3 = rangeTable->field30[1].mData;
                v3 += (u32) AutoloadCallback - header->field28;
                *(u32 *) v3 = 0xe12fff1e;
            }
        }
        if (result != FALSE) {
            DC_FlushRange(header, bufferSize);
        }
    }
    return result;
}

#pragma thumb off

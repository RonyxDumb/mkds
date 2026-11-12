#include "mb_fileinfo.h"
#include "code_0200fc8c.h"
#include "code_02000a58.h"
#include "code_0200aea8.h"
#include "code_02003024.h"
#include "code_02003be0.h"
#include "fs_file.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "code_021458c4.h"

const u32 mbi_seg_header_default[6] = {0x4000, 0x1000, 0x7000, 0x1000, 0, 0};
u32 *mbi_seg_header = (u32 *) mbi_seg_header_default;
u8 gSegmentRomArchiveName[4] = {0x72, 0x6f, 0x6d, 0};

#pragma thumb on

static inline u32 GetRomSizeOrDefault(CARDRomHeader *header) {
    u32 value = header->mRomSize;
    if (value == 0) {
        value = 0x01000000;
    }
    return value;
}

int MB_ReadSegment(FSFile *file, void *buffer, u32 bufferSize) {
    FSFile *activeFile;
    CARDRomHeader *header;
    u8 *v3;
    FSFile openedFile;
    BOOL result;
    BOOL openedHere;
    u32 remaining;
    u32 basePosition;
    MBiCacheList *rangeTable;
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
            basePosition = activeFile->mUnk_2c - activeFile->mProp.w.mUnk_04;
            if (FS_ReadFile(activeFile, header, 0x160) < 0x160) {
                remaining = 0;
            }
            seekOffset = GetRomSizeOrDefault(header);
        } else {
            seekOffset = GetRomSizeOrDefault(&SYSTEM_WORK->mRomHeader);
            openedHere = TRUE;
            FS_InitFile(&openedFile);
            FS_OpenFileDirect(&openedFile, FS_FindArchive(gSegmentRomArchiveName, 3), 0, seekOffset + 0x88, -1);
            activeFile = &openedFile;
            basePosition = openedFile.mUnk_2c - openedFile.mProp.w.mUnk_04;
            MI_CpuCopy8(&SYSTEM_WORK->mRomHeader, header, 0x160);
            header->mUnk_60 |= 0x00406000;
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
            rangeTable = (MBiCacheList *) v3;
            MBi_InitCache((u32) v3);
            v3 += 0x70;
            remaining -= 0x70;
            MBi_AttachCacheBuffer(rangeTable, 0, 0x160, (u8 *) header, 3);
            arcBytes = (s8 *) activeFile->mArc;
            v10 = 0;
            while (v10 < 3 && arcBytes[v10] != 0) {
                v10++;
            }
            MI_CpuCopy8(arcBytes, rangeTable->mArcName, v10);
            rangeTable->mArcNameLen = v10;
        } else {
            remaining = 0;
        }
        if (remaining >= 0x10) {
            v6 = (u32 *) v3;
            v6[0] = 0;
            v6[1] = header->mHead.mUnk_20 + (basePosition + activeFile->mProp.w.mUnk_04);
            v6[2] = header->mHead.mUnk_30 + (basePosition + activeFile->mProp.w.mUnk_04);
            v3 += 0x10;
            remaining -= 0x10;
        } else {
            remaining = 0;
        }
        v8 = header->mHead.mUnk_2c + header->mHead.mUnk_3c;
        if (remaining >= v8) {
            v10 = activeFile->mProp.w.mUnk_04;
            FS_SeekFile(activeFile, v6[1] - v10, 0);
            FS_ReadFile(activeFile, v3, header->mHead.mUnk_2c);
            MBi_AttachCacheBuffer(rangeTable, v6[1], header->mHead.mUnk_2c, v3, 3);
            v3 += header->mHead.mUnk_2c;
            FS_SeekFile(activeFile, v6[2] - v10, 0);
            FS_ReadFile(activeFile, v3, header->mHead.mUnk_3c);
            MBi_AttachCacheBuffer(rangeTable, v6[2], header->mHead.mUnk_3c, v3, 3);
            result = TRUE;
        } else if (remaining >= 0xcc00) {
            v10 = activeFile->mProp.w.mUnk_04;
            v8 = v6[1];
            FS_SeekFile(activeFile, v8 - v10, 0);
            FS_ReadFile(activeFile, v3, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, v8, 0x4400, v3, 3);
            FS_SeekFile(activeFile, v8 + 0x4400 - v10, 0);
            FS_ReadFile(activeFile, v3 + 0x4400, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, v8 + 0x4400, 0x4400, (v3 + 0x4400), 2);
            FS_SeekFile(activeFile, v8 + 0x8800 - v10, 0);
            FS_ReadFile(activeFile, v3 + 0x8800, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, v8 + 0x8800, 0x4400, (v3 + 0x8800), 2);
            result = TRUE;
        }
        FS_SeekFile(activeFile, basePosition, 0);
        if (openedHere != FALSE) {
            FS_CloseFile(&openedFile);
            if (result != FALSE) {
                v6 = mbi_seg_header;
                v14[0] = header->mHead.mUnk_20;
                v14[1] = header->mHead.mUnk_28 - header->mHead.mUnk_20;
                v14[2] = (u32) rangeTable->mList[1].mPtr - header->mHead.mUnk_20;
                v14[3] = bufferSize;
                MBi_ReadSegmentHeader(v14, 0x4000, 0x8000, 1);
                while (((s32 *) v6)[1] != 0) {
                    MBi_ReadSegmentHeader(v14, v6[0], v6[0] + v6[1], 0);
                    v6 += 2;
                }
                v3 = rangeTable->mList[1].mPtr;
                v3 += (u32) AutoloadCallback - header->mHead.mUnk_28;
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

#pragma thumb on

void MBi_ReadSegmentHeader(u32 *segmentHeader, u32 offsetStart, u32 offsetEnd, int fillFlag) {
    u32 rangeStart;
    if (offsetStart < (0x00004000u)) {
        offsetStart = (0x00004000u);
    }
    if ((0x00008000u) < offsetEnd) {
        offsetEnd = (0x00008000u);
    }
    rangeStart = *segmentHeader;
    if (offsetStart < rangeStart) {
        offsetStart = rangeStart;
    }
    if (offsetEnd > rangeStart + segmentHeader[3]) {
        offsetEnd = rangeStart + segmentHeader[3];
    }
    if (offsetStart < offsetEnd) {
        if (fillFlag != 0) {
            MI_CpuFill8(((u32 *) (u32) (segmentHeader[2] + offsetStart)), 0, offsetEnd - offsetStart);
            return;
        }
        MI_CpuCopy8(((u16 *) (u32) (segmentHeader[1] + offsetStart)), ((u32 *) (u32) (segmentHeader[2] + offsetStart)),
                    offsetEnd - offsetStart);
    }
}

#pragma thumb off

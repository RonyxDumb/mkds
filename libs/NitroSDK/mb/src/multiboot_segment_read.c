#include "multiboot_segment_read.h"
#include "reset_interrupts_halt.h"
#include "autoload_callback.h"
#include "multiboot_cache_init.h"
#include "file_command_handlers.h"
#include "file_archive_access.h"
#include "file_handle_setup.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "card_rom_backup_access.h"
#include "multiboot_file_register.h"

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
    u8 *writePos;
    FSFile openedFile;
    BOOL result;
    BOOL openedHere;
    u32 remaining;
    u32 basePosition;
    MBiCacheList *rangeTable;
    u32 *offsetTable;
    s32 segmentSize;
    s32 mainOffset;
    u32 seekOffset;
    s32 nameLength;
    s32 fileBase;
    u32 segmentParams[4];
    s8 *arcBytes;
    activeFile = file;
    header = buffer;
    result = FALSE;
    if (bufferSize >= MULTIBOOT_HEADER_AREA_SIZE + 4) {
        openedHere = FALSE;
        remaining = bufferSize;
        writePos = (u8 *) header;
        rangeTable = NULL;
        offsetTable = NULL;
        writePos += MULTIBOOT_HEADER_AREA_SIZE;
        remaining -= MULTIBOOT_HEADER_AREA_SIZE;
        if (activeFile != NULL) {
            basePosition = activeFile->mPosition - activeFile->mProp.w.mUnk_04;
            if (FS_ReadFile(activeFile, header, MULTIBOOT_HEADER_AREA_SIZE) < MULTIBOOT_HEADER_AREA_SIZE) {
                remaining = 0;
            }
            seekOffset = GetRomSizeOrDefault(header);
        } else {
            seekOffset = GetRomSizeOrDefault(&SYSTEM_WORK->mRomHeader);
            openedHere = TRUE;
            FS_InitFile(&openedFile);
            FS_OpenFileDirect(&openedFile, FS_FindArchive(gSegmentRomArchiveName, 3), 0, seekOffset + 0x88, -1);
            activeFile = &openedFile;
            basePosition = openedFile.mPosition - openedFile.mProp.w.mUnk_04;
            MI_CpuCopy8(&SYSTEM_WORK->mRomHeader, header, sizeof(SYSTEM_WORK->mRomHeader));
            header->mRomCtrl |= 0x00406000;
        }
        if (remaining >= 0x88) {
            FS_SeekFile(activeFile, basePosition + seekOffset, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos, 0x88);
            writePos += 0x88;
            remaining -= 0x88;
        } else {
            remaining = 0;
        }
        if (remaining >= sizeof(MBiCacheList)) {
            rangeTable = (MBiCacheList *) writePos;
            MBi_InitCache(rangeTable);
            writePos += sizeof(MBiCacheList);
            remaining -= sizeof(MBiCacheList);
            MBi_AttachCacheBuffer(rangeTable, 0, MULTIBOOT_HEADER_AREA_SIZE, (u8 *) header, 3);
            arcBytes = (s8 *) activeFile->mArc;
            nameLength = 0;
            while (nameLength < 3 && arcBytes[nameLength] != 0) {
                nameLength++;
            }
            MI_CpuCopy8(arcBytes, rangeTable->mArcName, nameLength);
            rangeTable->mArcNameLen = nameLength;
        } else {
            remaining = 0;
        }
        if (remaining >= 0x10) {
            offsetTable = (u32 *) writePos;
            offsetTable[0] = 0;
            offsetTable[1] = header->mHead.mMainRomOffset + (basePosition + activeFile->mProp.w.mUnk_04);
            offsetTable[2] = header->mHead.mSubRomOffset + (basePosition + activeFile->mProp.w.mUnk_04);
            writePos += 0x10;
            remaining -= 0x10;
        } else {
            remaining = 0;
        }
        segmentSize = header->mHead.mMainSize + header->mHead.mSubSize;
        if (remaining >= segmentSize) {
            fileBase = activeFile->mProp.w.mUnk_04;
            FS_SeekFile(activeFile, offsetTable[1] - fileBase, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos, header->mHead.mMainSize);
            MBi_AttachCacheBuffer(rangeTable, offsetTable[1], header->mHead.mMainSize, writePos, 3);
            writePos += header->mHead.mMainSize;
            FS_SeekFile(activeFile, offsetTable[2] - fileBase, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos, header->mHead.mSubSize);
            MBi_AttachCacheBuffer(rangeTable, offsetTable[2], header->mHead.mSubSize, writePos, 3);
            result = TRUE;
        } else if (remaining >= 0xcc00) {
            fileBase = activeFile->mProp.w.mUnk_04;
            mainOffset = offsetTable[1];
            FS_SeekFile(activeFile, mainOffset - fileBase, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, mainOffset, 0x4400, writePos, 3);
            FS_SeekFile(activeFile, mainOffset + 0x4400 - fileBase, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos + 0x4400, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, mainOffset + 0x4400, 0x4400, (writePos + 0x4400), 2);
            FS_SeekFile(activeFile, mainOffset + 0x8800 - fileBase, FILE_SEEK_START);
            FS_ReadFile(activeFile, writePos + 0x8800, 0x4400);
            MBi_AttachCacheBuffer(rangeTable, mainOffset + 0x8800, 0x4400, (writePos + 0x8800), 2);
            result = TRUE;
        }
        FS_SeekFile(activeFile, basePosition, FILE_SEEK_START);
        if (openedHere != FALSE) {
            FS_CloseFile(&openedFile);
            if (result != FALSE) {
                offsetTable = mbi_seg_header;
                segmentParams[0] = header->mHead.mMainRomOffset;
                segmentParams[1] = header->mHead.mMainRamAddress - header->mHead.mMainRomOffset;
                segmentParams[2] = (u32) rangeTable->mList[1].mPtr - header->mHead.mMainRomOffset;
                segmentParams[3] = bufferSize;
                MBi_ReadSegmentHeader(segmentParams, 0x4000, 0x8000, 1);
                while (((s32 *) offsetTable)[1] != 0) {
                    MBi_ReadSegmentHeader(segmentParams, offsetTable[0], offsetTable[0] + offsetTable[1], 0);
                    offsetTable += 2;
                }
                writePos = rangeTable->mList[1].mPtr;
                writePos += (u32) AutoloadCallback - header->mHead.mMainRamAddress;
                *(u32 *) writePos = 0xe12fff1e;
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

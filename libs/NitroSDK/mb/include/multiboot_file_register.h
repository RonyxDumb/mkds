#pragma once

#include "types.h"
#include "multiboot_parent_state_machine.h"
#include "multiboot_mode_constants.h"
#include "mb_data.h"
#include "reset_interrupts_halt.h"
#include "wireless_link_control.h"


// Filled by MBi_get_blockinfo.
typedef struct MB_BlockInfo {
    /* 00 */ u32 mChildAddress;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mOffset;
    /* 0c */ u8 mSegmentNo;
    /* 0d */ u8 mUnk_0d[3];
} MB_BlockInfo;

// 0x14 bytes at 0x1d2c of an entry of MB_CommPWork: three words, then four halfwords.
typedef struct MB_BlockInfoTable {
    /* 00 */ u32 mRangeOffsets[3];
    /* 0c */ u16 mChunkStarts[4];
} MB_BlockInfoTable;

// 0x10-byte entry of MBDownloadFileInfo.
typedef struct MbSegmentInfo {
    /* 00 */ u32 mRecvAddr;
    /* 04 */ u32 mLoadAddr;
    /* 08 */ u32 mSize;
    /* 0c */ u32 mTarget;
} MbSegmentInfo;

// 0xe4-byte object that MBi_MakeDownloadFileInfo sets up at 0x1788 of an entry of MB_CommPWork.
typedef struct MBDownloadFileInfo {
    /* 00 */ u32 mArm9EntryAddr;
    /* 04 */ u32 mArm7EntryAddr;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ MbSegmentInfo mSeg[3];
    /* 3c */ u8 mAuthCode[0x88];
    /* c4 */ u8 mReserved[0x20];
} MBDownloadFileInfo;

// Object MB_RegisterFile and MBi_MakeDownloadFileInfo read; the MBiCacheList at 0x1e8 and the words at 0x258 go to
// the entry.
typedef struct SegmentBuffer {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ u32 mMainEntryAddress;
    /* 028 */ u32 mMainRamRange[2];
    /* 030 */ u8 mUnk_030[4];
    /* 034 */ u32 mSubEntryAddress;
    /* 038 */ u32 mSubRamRange[2];
    /* 040 */ u8 mUnk_040[0x120];
    /* 160 */ u8 mAuthCode[0x88];
    /* 1e8 */ MBiCacheList mCacheList;
    /* 258 */ u32 mCardMapping[1];
} SegmentBuffer;

void MB_ReadMultiBootParentBssDesc(WMBssDesc *bssDesc, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag, u32 flagTwo);
u32 IsAbleToLoad(u32 rangeIndex, u32 address, u32 size);
u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size);
BOOL MBi_get_blockinfo(MB_BlockInfo *result, void *chunkTableData, u16 chunk, void *recordData);
u32 MBi_MakeBlockInfoTable(MB_BlockInfoTable *chunkTable, MBDownloadFileInfo *record);
void MBi_SetSegmentInfo(SegmentBuffer *source, const u32 *kindWord, MbSegmentInfo *range, u32 *nextAddress);
void MBi_MakeDownloadFileInfo(MBDownloadFileInfo *record, SegmentBuffer *source);
u32 MB_RegisterFile(void *rangeTable, SegmentBuffer *source);

// Kinds of load segment in MBi_defaultLoadSegList, as the range checks tell them apart: the two main RAM ranges of a
// parent and the fixed area at 0x027ffe00.
enum {
    MULTIBOOT_SEGMENT_MAIN_RAM = 0,
    MULTIBOOT_SEGMENT_SUB_RAM = 1,
    MULTIBOOT_SEGMENT_HEADER_AREA = 2,
};
#define MULTIBOOT_HEADER_AREA_ADDRESS 0x027ffe00
#define MULTIBOOT_HEADER_AREA_SIZE 0x160
extern const u32 MBi_defaultLoadSegList[3];
extern u8 gNextSeqNoFixed;

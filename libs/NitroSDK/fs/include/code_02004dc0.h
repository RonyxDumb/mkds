#pragma once

#include "types.h"
#include "code_02003024.h"
#include "code_021458c4.h"

typedef struct FSFileID FSFileID;
typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

// Record of 0x2c bytes: the first 0x20 bytes are read from a table entry of 0x20 bytes.
typedef struct FSOverlayInfo {
    /* 00 */ u32 mId;
    /* 04 */ u8 *mRamAddress;
    /* 08 */ s32 mRamSize;
    /* 0c */ s32 mBssSize;
    /* 10 */ void (**mSinitInit)(void);
    /* 14 */ void (**mSinitInitEnd)(void);
    /* 18 */ s32 mFileId;
    /* 1c */ union {
        struct {
            u32 mUnk_00_0 : 24;
        } f;
        u8 b[4];
    } mUnk_1c;
    /* 20 */ u32 mTarget;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} FSOverlayInfo;

// Node of the list at gGlobalDestructorChain that FS_EndOverlay walks.
typedef struct MWiDestructorChain {
    /* 00 */ struct MWiDestructorChain *mNext;
    /* 04 */ void (*mDtor)(void *);
    /* 08 */ void *mObj;
} MWiDestructorChain;

extern u32 is_init;
extern u32 fsi_card_lock_id;
extern u32 fsi_default_dma_no;
extern CARDRomRegion fsi_ovt9;
extern CARDRomRegion fsi_ovt7;
extern FSArchive fsi_arc_rom;
extern u32 fsi_def_digest_key[];
extern u8 gRomArchiveLabel[];
extern void *fsi_digest_key_ptr;
extern u32 fsi_digest_key_len;

void FS_Init(u32 dmaNo);
u32 FS_TryLoadTable(u32 mem, u32 size);
void FSi_InitRom(u32 dmaNo);
s32 FSi_EmptyArchiveProc(FSFile *file, u32 command);
s32 FSi_ReadDummyCallback(FSArchive *archive, void *dst, u32 src, u32 len);
s32 FSi_RomArchiveProc(FSFile *file, u32 command);
s32 FSi_WriteDummyCallback(FSArchive *archive, const void *src, u32 dst, u32 len);
s32 FSi_ReadRomCallback(FSArchive *archive, void *dst, u32 src, u32 len);
void FSi_OnRomReadDone(FSArchive *archive);
void FS_AttachOverlayTable(u32 selector, u8 *data, u32 size);
u32 FS_UnloadOverlay(u32 selector, u32 index);
u32 FS_LoadOverlay(u32 selector, u32 index);
u32 FS_UnloadOverlayImage(FSOverlayInfo *info);
void FS_EndOverlay(FSOverlayInfo *info);
void FS_StartOverlay(FSOverlayInfo *info);
u32 FSi_CompareDigest(const u8 *expected, const u8 *data, u32 size);
u32 FS_LoadOverlayImage(FSOverlayInfo *info);
u32 FS_LoadOverlayImageAsync(FSOverlayInfo *info, FSFile *file);
u32 FS_LoadOverlayInfo(FSOverlayInfo *info, u32 selector, u32 index);
u32 FSi_LoadOverlayInfoCore(FSOverlayInfo *info, u32 selector, u32 index, FSArchive *archive, u8 *base0, u32 size0,
                            u8 *base1, u32 size1);
void FS_GetOverlayFileID(FSFileID *fileID, FSOverlayInfo *info);
void FS_ClearOverlayImage(FSOverlayInfo *info);
s32 FSi_GetOverlayBinarySize(FSOverlayInfo *info);

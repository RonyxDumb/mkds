#pragma once

#include "types.h"
#include "file_command_handlers.h"
#include "card_rom_backup_access.h"

typedef struct FSFileID FSFileID;
typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

// The info of one overlay: its id, RAM address and sizes, static initializers, file id and compressed size.
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
            u32 mCompressedSize : 24;
        } f;
        u8 bytes[4];
    } mCompressedSizeAndFlags;
    /* 20 */ u32 mTarget;
    /* 24 */ u32 mFileOffset;
    /* 28 */ u32 mFileLength;
} FSOverlayInfo;

// Node of the list at gGlobalDestructorChain that Fs_OverlayInfo_End walks.
typedef struct MWiDestructorChain {
    /* 00 */ struct MWiDestructorChain *mNext;
    /* 04 */ void (*mDtor)(void *);
    /* 08 */ void *mObj;
} MWiDestructorChain;

extern u32 g_Fs_Init;
extern u32 g_CardLockId;
extern u32 g_CardDmaChannel;
extern CARDRomRegion g_Overlay9;
extern CARDRomRegion g_Overlay7;
extern FSArchive g_Fs_RomArchive;
extern u32 fsi_def_digest_key[];
extern u8 g_str_rom[];
extern void *g_SomeCompCode;
extern u32 fsi_digest_key_len;

void Fs_Initialize(u32 dmaNo);
u32 Fs_LoadRomArchiveFatFnt(u32 mem, u32 size);
void Fs_InitializeMountRom(u32 dmaNo);
s32 Fs_RomArchive_ExtraFileOperationHandler_AllDisable(FSFile *file, u32 command);
s32 Fs_RomArchive_ReadFn_RomDisable(FSArchive *archive, void *dst, u32 src, u32 len);
s32 Fs_RomArchive_ExtraFileOperationHandler_Default(FSFile *file, u32 command);
s32 Fs_RomArchive_WriteFn_RomDisable(FSArchive *archive, const void *src, u32 dst, u32 len);
s32 Fs_RomArchive_ReadFn_Default(FSArchive *archive, void *dst, u32 src, u32 len);
void UnkStructRelated_SaveFnPtr(void *arg);
void FS_AttachOverlayTable(u32 selector, u8 *data, u32 size);
u32 Fs_UnloadOverlay(u32 selector, u32 index);
u32 Fs_LoadOverlay(u32 selector, u32 index);
u32 Fs_OverlayInfo_UnloadImage(FSOverlayInfo *info);
void Fs_OverlayInfo_End(FSOverlayInfo *info);
void Fs_OverlayInfo_Start(FSOverlayInfo *info);
u32 Fs_ComputeCompareDigest(const u8 *expected, const u8 *data, u32 size);
u32 Fs_OverlayInfo_LoadImage(FSOverlayInfo *info);
u32 Fs_OverlayInfo_LoadImageAsync(FSOverlayInfo *info, FSFile *file);
u32 Fs_OverlayInfo_Load(FSOverlayInfo *info, u32 selector, u32 index);
u32 Fs_OverlayInfo_DoLoad(FSOverlayInfo *info, u32 selector, u32 index, FSArchive *archive, u8 *base0, u32 size0,
                            u8 *base1, u32 size1);
void Fs_GetOverlayFileId(FSFileID *fileID, FSOverlayInfo *info);
void Fs_OverlayInfo_ClearImage(FSOverlayInfo *info);
s32 Fs_OverlayInfo_GetBinarySize(FSOverlayInfo *info);

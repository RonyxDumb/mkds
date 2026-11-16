#include "overlay_rom_loader.h"
#include "file_archive_access.h"
#include "bios_calls.h"
#include "file_handle_setup.h"
#include "startup_clear_and_decompress.h"
#include "thread_scheduler.h"
#include "lock_word_and_bus_ownership.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "card_enable_and_lock.h"
#include "card_rom_backup_access.h"
#include "cpu_copy_fill.h"
#include "digest_hmac_overlay_hash.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "multiboot_piece_buffers.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "sound_stream_control.h"
#include "sound_archive_load.h"
#include "Main/Net/friend_data_player_id.h"

u32 g_Fs_Init;
u32 g_CardLockId;
u32 g_CardDmaChannel;
CARDRomRegion g_Overlay7;
CARDRomRegion g_Overlay9;
FSArchive g_Fs_RomArchive;

void *g_SomeCompCode = fsi_def_digest_key;
u8 g_str_rom[4] = "rom";
u32 fsi_digest_key_len = 0x40;

// Returns the size of the overlay image: the compressed size when the compressed flag is set, else the image size.
s32 Fs_OverlayInfo_GetBinarySize(FSOverlayInfo *info) {
    if (info->mCompressedSizeAndFlags.bytes[3] & 1) {
        return info->mCompressedSizeAndFlags.f.mCompressedSize;
    }
    return info->mRamSize;
}

// Invalidates the caches over the overlay and zeroes its uninitialized part.
void Fs_OverlayInfo_ClearImage(FSOverlayInfo *info) {
    u8 *image;
    s32 imageSize;
    s32 totalSize;

    imageSize = info->mRamSize;
    totalSize = imageSize + info->mBssSize;
    image = info->mRamAddress;
    IC_InvalidateRangeNoClean(image, totalSize);
    DC_InvalidateRangeNoClean(image, totalSize);
    Mem_CpuFill8(image + imageSize, 0, totalSize - imageSize);
}

// Gives the archive and file number of an overlay.
void Fs_GetOverlayFileId(FSFileID *fileID, FSOverlayInfo *info) {
    FSFileID id;

    id.mArc = &g_Fs_RomArchive;
    id.mFileId = info->mFileId;
    *fileID = id;
}

// Reads an overlay entry from the overlay table in ROM, then looks up where its file lies.
u32 Fs_OverlayInfo_DoLoad(FSOverlayInfo *info, u32 selector, u32 index, FSArchive *archive, u8 *base0, u32 size0,
                            u8 *base1, u32 size1) {
    FSFile file;
    FSFileID fileID;
    u32 offset;
    u8 *base;
    u32 size;

    if (selector == 0) {
        size = size0;
        base = base0;
    } else {
        size = size1;
        base = base1;
    }
    offset = index << 5;
    if (offset >= size) {
        return 0;
    }
    Fs_File_Initialize(&file);
    if (Fs_File_OpenRaw(&file, archive, (u32) (base + offset), (u32) (base + size), -1) == 0) {
        return 0;
    }
    if (Fs_File_Read(&file, info, 0x20) != 0x20) {
        Fs_File_Close(&file);
        return 0;
    }
    Fs_File_Close(&file);
    info->mTarget = selector;
    Fs_GetOverlayFileId(&fileID, info);
    if (Fs_File_OpenById(&file, fileID) == 0) {
        return 0;
    }
    info->mFileOffset = file.mProp.p.mUnk_04;
    info->mFileLength = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
    Fs_File_Close(&file);
    return 1;
}

// Fills in an overlay record from the attached overlay table, or from the ROM table when none is attached.
u32 Fs_OverlayInfo_Load(FSOverlayInfo *info, u32 selector, u32 index) {
    FSFile file;
    FSFileID fileID;
    CARDRomRegion *table;
    CARDRomRegion *region0;
    CARDRomRegion *region1;

    if (selector == 0) {
        table = &g_Overlay9;
    } else {
        table = &g_Overlay7;
    }
    if (table->mOffset != 0) {
        if (index * 32 >= table->mLength) {
            return 0;
        }
        Mem_CpuCopy8(table->mOffset + index * 32, info, 0x20);
        info->mTarget = selector;
        Fs_File_Initialize(&file);
        Fs_GetOverlayFileId(&fileID, info);
        if (Fs_File_OpenById(&file, fileID) == 0) {
            return 0;
        }
        info->mFileOffset = file.mProp.p.mUnk_04;
        info->mFileLength = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        Fs_File_Close(&file);
        return 1;
    }
    region0 = &SYSTEM_WORK->mRomHeader.mHead.mOverlayTable0;
    region1 = &SYSTEM_WORK->mRomHeader.mHead.mOverlayTable1;
    return Fs_OverlayInfo_DoLoad(info, selector, index, &g_Fs_RomArchive, region0->mOffset, region0->mLength,
                                   region1->mOffset, region1->mLength);
}

// Starts reading an overlay image without waiting; the file stays open until the read ends.
u32 Fs_OverlayInfo_LoadImageAsync(FSOverlayInfo *info, FSFile *file) {
    FSFileID fileID;
    s32 size;

    Fs_File_Initialize(file);
    Fs_GetOverlayFileId(&fileID, info);
    if (Fs_File_OpenById(file, fileID) == 0) {
        return 0;
    }
    size = Fs_OverlayInfo_GetBinarySize(info);
    Fs_OverlayInfo_ClearImage(info);
    if (size == Fs_File_ReadAsync(file, info->mRamAddress, size)) {
        return 1;
    }
    Fs_File_Close(file);
    return 0;
}

// Reads an overlay image into memory and waits for it.
u32 Fs_OverlayInfo_LoadImage(FSOverlayInfo *info) {
    FSFileID fileID;
    FSFile file;
    s32 size;

    Fs_File_Initialize(&file);
    Fs_GetOverlayFileId(&fileID, info);
    if (Fs_File_OpenById(&file, fileID) == 0) {
        return 0;
    }
    size = Fs_OverlayInfo_GetBinarySize(info);
    Fs_OverlayInfo_ClearImage(info);
    if (size != Fs_File_Read(&file, info->mRamAddress, size)) {
        Fs_File_Close(&file);
        return 0;
    }
    Fs_File_Close(&file);
    return 1;
}

// Computes the digest of a block and compares it with the expected one.
u32 Fs_ComputeCompareDigest(const u8 *expected, const u8 *data, u32 size) {
    u8 hmac[0x14];
    u8 key[0x40];
    u32 byteOffset;

    Mem_CpuFill8(hmac, 0, sizeof(hmac));
    Mem_CpuCopy8(g_SomeCompCode, key, fsi_digest_key_len);
    DGT_Hash2CalcHmac(hmac, data, size, key, fsi_digest_key_len);
    for (byteOffset = 0; byteOffset < 0x14; byteOffset += 4) {
        if (*(u32 *) (hmac + byteOffset) != *(u32 *) (expected + byteOffset)) {
            break;
        }
    }
    return byteOffset == 0x14;
}

// Checks the overlay when authentication is required, flushes it and runs its initializers.
void Fs_OverlayInfo_Start(FSOverlayInfo *info) {
    u32 size;
    u32 verified;
    void (**initFunc)(void);
    void (**initEnd)(void);

    size = Fs_OverlayInfo_GetBinarySize(info);
    if (SYSTEM_WORK->mWmBootBuf.mBootType == BOOT_TYPE_MULTIBOOT) {
        verified = 0;
        if (info->mCompressedSizeAndFlags.bytes[3] & 2) {
            if (info->mId < ((u8 *) &g_ArchiveList - (u8 *) OverlaySignatures) / 20) {
                verified = Fs_ComputeCompareDigest(OverlaySignatures[info->mId], info->mRamAddress, size);
            }
        }
        if (verified == 0) {
            Mem_CpuFill8(info->mRamAddress, 0, size);
            Os_Terminate();
            return;
        }
    }
    if (info->mCompressedSizeAndFlags.bytes[3] & 1) {
        Crt0_DecompressFlushCode(info->mRamAddress + size);
    }
    Arm_FlushRange(info->mRamAddress, info->mRamSize);
    initFunc = info->mSinitInit;
    initEnd = info->mSinitInitEnd;
    if (initFunc >= initEnd) {
        return;
    }
    do {
        if (*initFunc != 0) {
            (*initFunc)();
        }
        initFunc++;
    } while (initFunc < initEnd);
}

// Runs and removes the end handlers whose function or object lies inside the overlay.
void Fs_OverlayInfo_End(FSOverlayInfo *info) {
    MWiDestructorChain *prev;
    MWiDestructorChain *base;
    MWiDestructorChain *cur;
    MWiDestructorChain *next;
    MWiDestructorChain *first;
    MWiDestructorChain *removedLast;
    u32 low;
    u32 high;
    u32 enabled;
    u32 funcAddr;
    void *arg;

    for (;;) {
        low = (u32) info->mRamAddress;
        high = low + (info->mRamSize + info->mBssSize);
        first = 0;
        removedLast = 0;
        enabled = Os_DisableIrq();
        prev = 0;
        base = gGlobalDestructorChain;
        cur = base;
        if (base != 0) {
            do {
                arg = cur->mObj;
                next = cur->mNext;
                funcAddr = (u32) cur->mDtor;
                if ((arg == 0 && funcAddr >= low && funcAddr < high) || ((u32) arg >= low && (u32) arg < high)) {
                    if (removedLast != 0) {
                        removedLast->mNext = cur;
                    } else {
                        first = cur;
                    }
                    if (base == cur) {
                        gGlobalDestructorChain = next;
                        base = next;
                    }
                    cur->mNext = 0;
                    removedLast = cur;
                    if (prev != 0) {
                        prev->mNext = next;
                    }
                } else {
                    prev = cur;
                }
                cur = next;
            } while (cur != 0);
        }
        Os_RestoreIrq(enabled);
        if (first == 0) {
            return;
        }
        do {
            next = first->mNext;
            if (first->mDtor != 0) {
                first->mDtor(first->mObj);
            }
            first = next;
        } while (first != 0);
    }
}

// Ends the overlay.
u32 Fs_OverlayInfo_UnloadImage(FSOverlayInfo *info) {
    Fs_OverlayInfo_End(info);
    return 1;
}

// Loads an overlay and starts it.
u32 Fs_LoadOverlay(u32 selector, u32 index) {
    FSOverlayInfo info;

    if (Fs_OverlayInfo_Load(&info, selector, index) == 0 || Fs_OverlayInfo_LoadImage(&info) == 0) {
        return 0;
    }
    Fs_OverlayInfo_Start(&info);
    return 1;
}

// Ends a loaded overlay.
u32 Fs_UnloadOverlay(u32 selector, u32 index) {
    FSOverlayInfo info;

    if (Fs_OverlayInfo_Load(&info, selector, index) == 0 || Fs_OverlayInfo_UnloadImage(&info) == 0) {
        return 0;
    }
    return 1;
}

// Sets the overlay table for a target; the table of target 0 is checked against its digest first.
void FS_AttachOverlayTable(u32 selector, u8 *data, u32 size) {
    CARDRomRegion *table;
    u32 saved;

    if (data != 0 && selector == 0) {
        saved = DGT_SetOverlayTableMode(1);
        if (Fs_ComputeCompareDigest(g_SomeDigest, data, size) == 0) {
            Os_Terminate();
        }
        DGT_SetOverlayTableMode(saved);
    }
    if (selector == 0) {
        table = &g_Overlay9;
    } else {
        table = &g_Overlay7;
    }
    saved = Os_DisableIrq();
    table->mOffset = data;
    table->mLength = size;
    Os_RestoreIrq(saved);
}

// Ends the asynchronous ROM read of an archive.
void UnkStructRelated_SaveFnPtr(void *arg) {
    FSArchive *archive = arg;
    Fs_Archive_NotifyAsyncEnded(archive, 0);
}

// Archive read callback that reads from the card in the background.
s32 Fs_RomArchive_ReadFn_Default(FSArchive *archive, void *dst, u32 src, u32 len) {
    CARDi_ReadRom(g_CardDmaChannel, src, (u32) dst, len, UnkStructRelated_SaveFnPtr, archive, 1);
    return 6;
}

// Archive write callback that always fails.
s32 Fs_RomArchive_WriteFn_RomDisable(FSArchive *archive, const void *src, u32 dst, u32 len) {
    return 1;
}

// ROM archive callback: locks and unlocks the card.
s32 Fs_RomArchive_ExtraFileOperationHandler_Default(FSFile *file, u32 command) {
    switch (command) {
        case ARCHIVE_COMMAND_START_RUN:
            Card_LockRomResource(g_CardLockId);
            return 0;
        case ARCHIVE_COMMAND_STOP_RUN:
            Card_UnlockRomResource(g_CardLockId);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

// Archive read callback that always fails.
s32 Fs_RomArchive_ReadFn_RomDisable(FSArchive *archive, void *dst, u32 src, u32 len) {
    return 1;
}

// Archive callback that rejects every command.
s32 Fs_RomArchive_ExtraFileOperationHandler_AllDisable(FSFile *file, u32 command) {
    return 4;
}

// Registers the "rom" archive and loads its tables from the ROM header.
void Fs_InitializeMountRom(u32 dmaNo) {
    enum { ROM_REGION_ADDRESS_NONE } fntRegion, fatRegion;

    g_CardDmaChannel = dmaNo;
    g_CardLockId = Os_AllocateLockId();
    g_Overlay9.mOffset = 0;
    g_Overlay9.mLength = 0;
    g_Overlay7.mOffset = 0;
    g_Overlay7.mLength = 0;
    Card_Initialize();
    Fs_Archive_Initialize(&g_Fs_RomArchive);
    Fs_RegisterArchive(&g_Fs_RomArchive, g_str_rom, 3);
    if (SYSTEM_WORK->mWmBootBuf.mBootType == BOOT_TYPE_MULTIBOOT) {
        g_Overlay9.mOffset = (u8 *) -1;
        g_Overlay9.mLength = 0;
        g_Overlay7.mOffset = (u8 *) -1;
        g_Overlay7.mLength = 0;
        Fs_Archive_SetExtraFileOperationHandler(&g_Fs_RomArchive, Fs_RomArchive_ExtraFileOperationHandler_AllDisable, -1);
        Fs_Archive_LoadFromFatFnt(&g_Fs_RomArchive, 0, 0, 0, 0, 0, Fs_RomArchive_ReadFn_RomDisable, Fs_RomArchive_WriteFn_RomDisable);
        return;
    }
    fntRegion = 0x27ffe40;
    fatRegion = 0x27ffe48;
    Fs_Archive_SetExtraFileOperationHandler(&g_Fs_RomArchive, Fs_RomArchive_ExtraFileOperationHandler_Default, 0x602);
    if (((CARDRomRegion *) fntRegion)->mOffset == (u8 *) -1) {
        return;
    }
    if (((CARDRomRegion *) fntRegion)->mOffset == 0) {
        return;
    }
    if (((CARDRomRegion *) fatRegion)->mOffset == (u8 *) -1) {
        return;
    }
    if (((CARDRomRegion *) fatRegion)->mOffset == 0) {
        return;
    }
    Fs_Archive_LoadFromFatFnt(&g_Fs_RomArchive, 0, (u32) ((CARDRomRegion *) fatRegion)->mOffset,
                   ((CARDRomRegion *) fatRegion)->mLength, (u32) ((CARDRomRegion *) fntRegion)->mOffset,
                   ((CARDRomRegion *) fntRegion)->mLength, Fs_RomArchive_ReadFn_Default, Fs_RomArchive_WriteFn_RomDisable);
}

// Copies the ROM archive tables into the given memory.
u32 Fs_LoadRomArchiveFatFnt(u32 mem, u32 size) {
    return Fs_Archive_LoadFatFnt(&g_Fs_RomArchive, mem, size);
}

// Initializes the file system once.
void Fs_Initialize(u32 dmaNo) {
    if (g_Fs_Init != 0) {
        return;
    }
    g_Fs_Init = 1;
    Fs_InitializeMountRom(dmaNo);
}

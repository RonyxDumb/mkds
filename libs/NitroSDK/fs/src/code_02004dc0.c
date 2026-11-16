#include "code_02004dc0.h"
#include "code_02003be0.h"
#include "Main/Unknown/code_02000000.h"
#include "fs_file.h"
#include "Main/Unknown/code_02000920.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200cd1c.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214578c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_0214613c.h"
#include "code_0214d018.h"
#include "hash2.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

u32 g_Fs_Init;
u32 g_CardLockId;
u32 g_CardDmaChannel;
Unk02005704 g_Overlay7;
Unk02005704 g_Overlay9;
FSArchive g_Fs_RomArchive;

void *g_SomeCompCode = data_02152b80;
u8 g_str_rom[4] = "rom";
u32 g_40 = 0x40;

// Returns the size of the overlay image: the compressed size when the compressed flag is set, else the image size.
s32 FSi_GetOverlayBinarySize(FSOverlayInfo *info) {
    if (info->field1C.b[3] & 1) {
        return info->field1C.f.field0_0;
    }
    return info->mRamSize;
}

// Invalidates the caches over the overlay and zeroes its uninitialized part.
void FS_ClearOverlayImage(FSOverlayInfo *info) {
    u8 *image;
    s32 imageSize;
    s32 totalSize;

    imageSize = info->mRamSize;
    totalSize = imageSize + info->mBssSize;
    image = info->mRamAddress;
    IC_InvalidateRange(image, totalSize);
    DC_InvalidateRange(image, totalSize);
    MI_CpuFill8(image + imageSize, 0, totalSize - imageSize);
}

// Gives the archive and file number of an overlay.
void FS_GetOverlayFileID(FSFileID *fileID, FSOverlayInfo *info) {
    FSFileID id;

    id.mArc = &g_Fs_RomArchive;
    id.mFileId = info->mFileId;
    *fileID = id;
}

// Reads an overlay entry from the overlay table in ROM, then looks up where its file lies.
u32 FSi_LoadOverlayInfoCore(FSOverlayInfo *info, u32 selector, u32 index, FSArchive *archive, u8 *base0, u32 size0,
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
    FS_InitFile(&file);
    if (FS_OpenFileDirect(&file, archive, (u32) (base + offset), (u32) (base + size), -1) == 0) {
        return 0;
    }
    if (FS_ReadFile(&file, info, 0x20) != 0x20) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_CloseFile(&file);
    info->mTarget = selector;
    FS_GetOverlayFileID(&fileID, info);
    if (FS_OpenFileFast(&file, fileID) == 0) {
        return 0;
    }
    info->field24 = file.mProp.p.field4;
    info->field28 = file.mProp.p.field8 - file.mProp.p.field4;
    FS_CloseFile(&file);
    return 1;
}

// Fills in an overlay record from the attached overlay table, or from the ROM table when none is attached.
u32 FS_LoadOverlayInfo(FSOverlayInfo *info, u32 selector, u32 index) {
    FSFile file;
    FSFileID fileID;
    Unk02005704 *table;
    Unk02005704 *region0;
    Unk02005704 *region1;

    if (selector == 0) {
        table = &g_Overlay9;
    } else {
        table = &g_Overlay7;
    }
    if (table->field0 != 0) {
        if (index * 32 >= table->field4) {
            return 0;
        }
        MI_CpuCopy8(table->field0 + index * 32, info, 0x20);
        info->mTarget = selector;
        FS_InitFile(&file);
        FS_GetOverlayFileID(&fileID, info);
        if (FS_OpenFileFast(&file, fileID) == 0) {
            return 0;
        }
        info->field24 = file.mProp.p.field4;
        info->field28 = file.mProp.p.field8 - file.mProp.p.field4;
        FS_CloseFile(&file);
        return 1;
    }
    region0 = (Unk02005704 *) 0x27ffe50;
    region1 = (Unk02005704 *) 0x27ffe58;
    return FSi_LoadOverlayInfoCore(info, selector, index, &g_Fs_RomArchive, region0->field0, region0->field4,
                                   region1->field0, region1->field4);
}

// Starts reading an overlay image without waiting; the file stays open until the read ends.
u32 FS_LoadOverlayImageAsync(FSOverlayInfo *info, FSFile *file) {
    FSFileID fileID;
    s32 size;

    FS_InitFile(file);
    FS_GetOverlayFileID(&fileID, info);
    if (FS_OpenFileFast(file, fileID) == 0) {
        return 0;
    }
    size = FSi_GetOverlayBinarySize(info);
    FS_ClearOverlayImage(info);
    if (size == FS_ReadFileAsync(file, info->mRamAddress, size)) {
        return 1;
    }
    FS_CloseFile(file);
    return 0;
}

// Reads an overlay image into memory and waits for it.
u32 FS_LoadOverlayImage(FSOverlayInfo *info) {
    FSFileID fileID;
    FSFile file;
    s32 size;

    FS_InitFile(&file);
    FS_GetOverlayFileID(&fileID, info);
    if (FS_OpenFileFast(&file, fileID) == 0) {
        return 0;
    }
    size = FSi_GetOverlayBinarySize(info);
    FS_ClearOverlayImage(info);
    if (size != FS_ReadFile(&file, info->mRamAddress, size)) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_CloseFile(&file);
    return 1;
}

// Computes the digest of a block and compares it with the expected one.
u32 FSi_CompareDigest(const u8 *expected, const u8 *data, u32 size) {
    u8 digest[0x14];
    u8 key[0x40];
    u32 i;

    MI_CpuFill8(digest, 0, 0x14);
    MI_CpuCopy8(g_SomeCompCode, key, g_40);
    DGT_Hash2CalcHmac(digest, data, size, key, g_40);
    for (i = 0; i < 0x14; i += 4) {
        if (*(u32 *) (digest + i) != *(u32 *) (expected + i)) {
            break;
        }
    }
    return i == 0x14;
}

// Checks the overlay when authentication is required, flushes it and runs its initializers.
void FS_StartOverlay(FSOverlayInfo *info) {
    u32 size;
    u32 verified;
    void (**initFunc)(void);
    void (**initEnd)(void);

    size = FSi_GetOverlayBinarySize(info);
    if (*(u16 *) 0x27ffc40 == 2) {
        verified = 0;
        if (info->field1C.b[3] & 2) {
            if (info->mId < ((u8 *) &g_ArchiveList - (u8 *) OverlaySignatures) / 20) {
                verified = FSi_CompareDigest(OverlaySignatures[info->mId], info->mRamAddress, size);
            }
        }
        if (verified == 0) {
            MI_CpuFill8(info->mRamAddress, 0, size);
            OS_Terminate();
            return;
        }
    }
    if (info->field1C.b[3] & 1) {
        Crt0_DecompressFlushCode(info->mRamAddress + size);
    }
    DC_FlushRange(info->mRamAddress, info->mRamSize);
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
void FS_EndOverlay(FSOverlayInfo *info) {
    Unk02005210 *prev;
    Unk02005210 *base;
    Unk02005210 *cur;
    Unk02005210 *next;
    Unk02005210 *first;
    Unk02005210 *removedLast;
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
        enabled = OS_DisableInterrupts();
        prev = 0;
        base = data_0217eeb0;
        cur = base;
        if (base != 0) {
            do {
                arg = cur->field8;
                next = cur->field0;
                funcAddr = (u32) cur->field4;
                if ((arg == 0 && funcAddr >= low && funcAddr < high) || ((u32) arg >= low && (u32) arg < high)) {
                    if (removedLast != 0) {
                        removedLast->field0 = cur;
                    } else {
                        first = cur;
                    }
                    if (base == cur) {
                        data_0217eeb0 = next;
                        base = next;
                    }
                    cur->field0 = 0;
                    removedLast = cur;
                    if (prev != 0) {
                        prev->field0 = next;
                    }
                } else {
                    prev = cur;
                }
                cur = next;
            } while (cur != 0);
        }
        OS_RestoreInterrupts(enabled);
        if (first == 0) {
            return;
        }
        do {
            next = first->field0;
            if (first->field4 != 0) {
                first->field4(first->field8);
            }
            first = next;
        } while (first != 0);
    }
}

// Ends the overlay.
u32 FS_UnloadOverlayImage(FSOverlayInfo *info) {
    FS_EndOverlay(info);
    return 1;
}

// Loads an overlay and starts it.
u32 FS_LoadOverlay(u32 selector, u32 index) {
    FSOverlayInfo info;

    if (FS_LoadOverlayInfo(&info, selector, index) == 0 || FS_LoadOverlayImage(&info) == 0) {
        return 0;
    }
    FS_StartOverlay(&info);
    return 1;
}

// Ends a loaded overlay.
u32 FS_UnloadOverlay(u32 selector, u32 index) {
    FSOverlayInfo info;

    if (FS_LoadOverlayInfo(&info, selector, index) == 0 || FS_UnloadOverlayImage(&info) == 0) {
        return 0;
    }
    return 1;
}

// Sets the overlay table for a target; the table of target 0 is checked against its digest first.
void FS_AttachOverlayTable(u32 selector, u8 *data, u32 size) {
    Unk02005704 *table;
    u32 saved;

    if (data != 0 && selector == 0) {
        saved = DGT_SetOverlayTableMode(1);
        if (FSi_CompareDigest(g_SomeDigest, data, size) == 0) {
            OS_Terminate();
        }
        DGT_SetOverlayTableMode(saved);
    }
    if (selector == 0) {
        table = &g_Overlay9;
    } else {
        table = &g_Overlay7;
    }
    saved = OS_DisableInterrupts();
    table->field0 = data;
    table->field4 = size;
    OS_RestoreInterrupts(saved);
}

// Ends the asynchronous ROM read of an archive.
void FSi_OnRomReadDone(FSArchive *archive) {
    FS_NotifyArchiveAsyncEnd(archive, 0);
}

// Archive read callback that reads from the card in the background.
s32 FSi_ReadRomCallback(FSArchive *archive, void *dst, u32 src, u32 len) {
    CARDi_ReadRom(g_CardDmaChannel, src, (u32) dst, len, FSi_OnRomReadDone, (u32) archive, 1);
    return 6;
}

// Archive write callback that always fails.
s32 FSi_WriteDummyCallback(FSArchive *archive, const void *src, u32 dst, u32 len) {
    return 1;
}

// ROM archive callback: locks and unlocks the card.
s32 FSi_RomArchiveProc(FSFile *file, u32 command) {
    switch (command) {
        case 9:
            CARD_LockRom(g_CardLockId);
            return 0;
        case 10:
            CARD_UnlockRom(g_CardLockId);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

// Archive read callback that always fails.
s32 FSi_ReadDummyCallback(FSArchive *archive, void *dst, u32 src, u32 len) {
    return 1;
}

// Archive callback that rejects every command.
s32 FSi_EmptyArchiveProc(FSFile *file, u32 command) {
    return 4;
}

// Registers the "rom" archive and loads its tables from the ROM header.
void FSi_InitRom(u32 dmaNo) {
    enum { K0 } fntRegion, fatRegion;

    g_CardDmaChannel = dmaNo;
    g_CardLockId = OS_GetLockID();
    g_Overlay9.field0 = 0;
    g_Overlay9.field4 = 0;
    g_Overlay7.field0 = 0;
    g_Overlay7.field4 = 0;
    CARD_Init();
    FS_InitArchive(&g_Fs_RomArchive);
    FS_RegisterArchiveName(&g_Fs_RomArchive, g_str_rom, 3);
    if (*(u16 *) 0x27ffc40 == 2) {
        g_Overlay9.field0 = (u8 *) -1;
        g_Overlay9.field4 = 0;
        g_Overlay7.field0 = (u8 *) -1;
        g_Overlay7.field4 = 0;
        FS_SetArchiveProc(&g_Fs_RomArchive, FSi_EmptyArchiveProc, -1);
        FS_LoadArchive(&g_Fs_RomArchive, 0, 0, 0, 0, 0, FSi_ReadDummyCallback, FSi_WriteDummyCallback);
        return;
    }
    fntRegion = 0x27ffe40;
    fatRegion = 0x27ffe48;
    FS_SetArchiveProc(&g_Fs_RomArchive, FSi_RomArchiveProc, 0x602);
    if (((Unk02005704 *) fntRegion)->field0 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) fntRegion)->field0 == 0) {
        return;
    }
    if (((Unk02005704 *) fatRegion)->field0 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) fatRegion)->field0 == 0) {
        return;
    }
    FS_LoadArchive(&g_Fs_RomArchive, 0, (u32) ((Unk02005704 *) fatRegion)->field0, ((Unk02005704 *) fatRegion)->field4,
                   (u32) ((Unk02005704 *) fntRegion)->field0, ((Unk02005704 *) fntRegion)->field4,
                   FSi_ReadRomCallback, FSi_WriteDummyCallback);
}

// Copies the ROM archive tables into the given memory.
u32 FS_TryLoadTable(u32 mem, u32 size) {
    return FS_LoadArchiveTables(&g_Fs_RomArchive, mem, size);
}

// Initializes the file system once.
void FS_Init(u32 dmaNo) {
    if (g_Fs_Init != 0) {
        return;
    }
    g_Fs_Init = 1;
    FSi_InitRom(dmaNo);
}

#include "03/System/wifi_utility_archive.h"
#include "03/Menu/wifi_menu_shared.h"
#include "card_rom_backup_access.h"

#include "03/System/pointer_stack_delete.h"
#include "03/System/pointer_stack.h"
#include "03/System/exp_heap.h"
#include "file_handle_setup.h"
#include "file_archive_access.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "narrow_string_functions.h"
#include "cpu_copy_fill.h"
#include "reset_interrupts_halt.h"
#include "03/System/pointer_stack_filled.h"
#include "03/Graphics/hl_nsc_names.h"
#include "lock_word_and_bus_ownership.h"
#include "formatted_text_to_buffer.h"
#include "card_enable_and_lock.h"

DwcArchive *gDwcArchive;

const u8 gDwcArchiveName[4] = {0x64, 0x77, 0x63, 0};
char gLzFileSuffix[3] = ".l";
u8 gRomDir[5] = {0x72, 0x6f, 0x6d, 0x3a, 0x2f};
u8 gDwcUtilityBinName[21] = {0x72, 0x6f, 0x6d, 0x3a, 0x2f, 0x64, 0x77, 0x63, 0x2f, 0x75, 0x74,
                             0x69, 0x6c, 0x69, 0x74, 0x79, 0x2e, 0x62, 0x69, 0x6e, 0};

void InitDwcArchive(void) {
    FSFile file;
    u32 fntRegion[2];
    u32 fatRegion[2];
    char dirPath[0x80];
    u32 base;
    u32 tablesSize;

    gDwcArchive = AllocZeroedExpHeapBlock(0xe8, 4);
    FS_InitFile(&file);
    if (FS_OpenFile(&file, gDwcUtilityBinName) == 0) {
        OS_Terminate();
    }
    gDwcArchive->mLockId = OS_GetLockID();
    base = file.mProp.w.mUnk_04;
    FS_ReadFile(&file, fntRegion, 8);
    FS_ReadFile(&file, fatRegion, 8);
    FS_CloseFile(&file);
    FS_InitArchive(&gDwcArchive->mArchive);
    if (FS_RegisterArchiveName(&gDwcArchive->mArchive, gDwcArchiveName, 3) == 0) {
        OS_Terminate();
    }
    FS_SetArchiveProc(&gDwcArchive->mArchive, DwcArchiveProc, 0x602);
    if (FS_LoadArchive(&gDwcArchive->mArchive, (u8 *) base, fatRegion[0], fatRegion[1], fntRegion[0], fntRegion[1],
                       DwcArchiveReadCallback, DwcArchiveWriteCallback) == 0) {
        OS_Terminate();
    }
    tablesSize = FS_LoadArchiveTables(&gDwcArchive->mArchive, 0, 0);
    gDwcArchive->mTables = AllocExpHeapBlock(tablesSize, 4);
    FS_LoadArchiveTables(&gDwcArchive->mArchive, (u32) gDwcArchive->mTables, tablesSize);
    gDwcArchive->mStack = CreateFilledPointerStack(0x20, gDwcArchive->mStackStorage, 4);
    OS_SPrintf(dirPath, "%s:/", gDwcArchiveName);
    FS_ChangeDir((u8 *) dirPath);
}

void ReleaseDwcArchive(void) {
    FS_ChangeDir(gRomDir);
    FS_UnloadArchiveTables(&gDwcArchive->mArchive);
    FS_UnloadArchive(&gDwcArchive->mArchive);
    FS_ReleaseArchiveName(&gDwcArchive->mArchive);
    OS_ReleaseLockID(gDwcArchive->mLockId);
    gDwcArchive->mLockId = 0;
    FreeExpHeapBlockAndClearPointer(gDwcArchive);
    gDwcArchive->mTables = NULL;
    FreeExpHeapBlockAndClearPointer(&gDwcArchive);
}

s32 DwcArchiveProc(FSFile *file, u32 command) {
    switch (command) {
        case FS_COMMAND_ACTIVATE:
            CARD_LockRom(gDwcArchive->mLockId);
            return 0;
        case FS_COMMAND_IDLE:
            CARD_UnlockRom(gDwcArchive->mLockId);
            return 0;
        case FS_COMMAND_WRITEFILE:
            return 4;
        default:
            return 8;
    }
}

s32 DwcArchiveReadCallback(FSArchive *archive, void *dst, u32 offset, u32 length) {
    CARDi_ReadRom(0xffffffff, offset + (u32) archive->mBase, (u32) dst, length, DwcArchiveReadEndCallback, archive, 1);
    return 6;
}

void DwcArchiveReadEndCallback(void *arg) {
    FSArchive *archive = arg;
    FS_NotifyArchiveAsyncEnd(archive, 0);
}

s32 DwcArchiveWriteCallback(FSArchive *archive, const void *src, u32 offset, u32 length) {
    return 1;
}

void *LoadFile(const u8 *path, u32 *outSize, s32 alignment) {
    FSFile file;
    void *fileData;
    u32 size;
    s32 readAlignment;

    PopPointerStack(gDwcArchive->mStack);
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path) == 0) {
        OS_Terminate();
    }
    size = file.mProp.w.mUnk_08 - file.mProp.w.mUnk_04;
    if (outSize != NULL) {
        *outSize = size;
    }
    if (AreStringEndsEqual(path, gLzFileSuffix, 2) != 0) {
        readAlignment = -4;
    } else {
        readAlignment = alignment;
    }
    fileData = AllocExpHeapBlock(size, readAlignment);
    FS_ReadFile(&file, fileData, size);
    FS_CloseFile(&file);
    if (readAlignment > 0) {
        return fileData;
    }
    size = *(u32 *) fileData >> 8;
    if (outSize != NULL) {
        *outSize = size;
    }
    {
        void *uncompressed = AllocExpHeapBlock(size, alignment);

        MI_UncompressLZ8(fileData, uncompressed);
        FreeExpHeapBlockAndClearPointer(&fileData);
        return uncompressed;
    }
}

void DeleteLoadedFile(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
    PushPointerStack(gDwcArchive->mStack, block);
}

BOOL AreStringEndsEqual(const u8 *first, const char *second, s32 endLength) {
    s32 firstLength = strlen((const char *) first);
    s32 secondLength = strlen(second);

    if (firstLength < endLength || secondLength < endLength) {
        return 0;
    }
    if (memcmp(first + (firstLength - endLength), second + (secondLength - endLength), endLength) == 0) {
        return 1;
    }
    return 0;
}

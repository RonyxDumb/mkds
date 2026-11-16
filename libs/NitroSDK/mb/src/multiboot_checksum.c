#include "multiboot_checksum.h"
#include "reset_interrupts_halt.h"
#include "file_command_handlers.h"
#include "file_archive_access.h"
#include "card_rom_backup_access.h"

#pragma thumb on

u16 MBi_calc_cksum(const u16 *data, s32 byteCount) {
    u32 sum;
    u32 folded;
    s32 halfwordCount;
    halfwordCount = byteCount >> 1;
    sum = 0;
    while (halfwordCount > 0) {
        sum += *data++;
        halfwordCount--;
    }
    folded = (sum >> 16) + (sum & 0xffff);
    return (folded + (folded >> 16)) ^ 0xffff;
}

u32 ComputeRomBinarySize_from_thumb(FSFile *file) {
    RomHeaderStart header;
    RomHeaderStart *headerPtr;
    u32 size;
    s32 backupPosition;
    headerPtr = NULL;
    size = 0;
    if (file != NULL) {
        backupPosition = file->mPosition - file->mProp.w.mUnk_04;
        if ((u32) Fs_File_Read(file, &header, 0x60) >= 0x60) {
            headerPtr = &header;
        }
        Fs_File_Seek(file, backupPosition, 0);
    } else {
        headerPtr = &SYSTEM_WORK->mRomHeader.mHead;
    }
    if (headerPtr != NULL) {
        size = headerPtr->mMainSize + 0x268 + headerPtr->mSubSize;
        if (size < 0x10000) {
            size = 0x10000;
        }
    }
    return size;
}

#pragma thumb off

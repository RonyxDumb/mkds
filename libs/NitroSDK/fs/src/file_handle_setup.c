#include "file_handle_setup.h"
#include "overlay_rom_loader.h"

// Returns whether Fs_Initialize has run.
u32 Fs_IsInitialized(void) {
    return g_Fs_Init;
}

// Clears a file record so it is idle and not linked to an archive.
void Fs_File_Initialize(FSFile *file) {
    file->mLink.mPrev = 0;
    file->mLink.mNext = file->mLink.mPrev;
    file->mQueue.mTail = 0;
    file->mQueue.mHead = file->mQueue.mTail;
    file->mArc = 0;
    file->mCommand = ARCHIVE_COMMAND_UNSET;
    file->mStat = 0;
}

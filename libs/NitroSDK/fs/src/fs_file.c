#include "fs_file.h"
#include "overlay_loader.h"

// Returns whether FS_Init has run.
u32 FS_IsAvailable(void) {
    return is_init;
}

// Clears a file record so it is idle and not linked to an archive.
void FS_InitFile(FSFile *file) {
    file->mLink.mPrev = 0;
    file->mLink.mNext = file->mLink.mPrev;
    file->mQueue.mTail = 0;
    file->mQueue.mHead = file->mQueue.mTail;
    file->mArc = 0;
    file->mCommand = ARCHIVE_COMMAND_UNSET;
    file->mStat = 0;
}

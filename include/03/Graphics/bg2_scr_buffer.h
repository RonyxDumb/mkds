#pragma once

#include "types.h"
#include "03/System/tasks.h"

// A BG2 screen map buffer with its task and an upload request flag.
typedef struct Bg2ScrBuffer {
    /* 000 */ TaskEntry *mTask;
    /* 004 */ u8 mScr[0x600];
    /* 604 */ u8 mUploadRequested;
} Bg2ScrBuffer;

void AdvanceBgPaletteCopy(TaskEntry *entry, void *arg);
void RequestBgPaletteCopy(const void *palette);
void AdvanceBgPaletteRowCopy(TaskEntry *entry, void *arg);
// A pending palette copy: the source and, for a row copy, the destination.
typedef struct BgPaletteCopyRequest {
    /* 0 */ const void *mSource;
    /* 4 */ void *mDestination;
} BgPaletteCopyRequest;

void RequestBgPaletteRowCopy(u8 *palette, u32 srcRow, u32 dstRow);
void AdvanceBg2ScrUpload(TaskEntry *task, void *arg);
void CopyBg2ScrBufferRect(const void *source, int destOffset, int width, int rowCount);
void RequestBg2ScrUpload(void);
void ReleaseBg2ScrBuffer(void);
void CreateBg2ScrBuffer(const void *scr);

extern struct Bg2ScrBuffer *gBg2ScrBuffer;
extern BgPaletteCopyRequest gBgPaletteCopyRequest;

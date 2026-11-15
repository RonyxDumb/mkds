#pragma once

#include "types.h"

// Object behind gBg2ScrBuffer.
typedef struct Bg2ScrBuffer {
    /* 000 */ u32 mTask;
    /* 004 */ u8 mScr[0x600];
    /* 604 */ u8 mUploadRequested;
} Bg2ScrBuffer;

void AdvanceBgPaletteCopy(u32 entry);
void RequestBgPaletteCopy(const void *palette);
void AdvanceBgPaletteRowCopy(u32 entry);
typedef struct BgPaletteCopyRequest {
    /* 0 */ const void *mSource;
    /* 4 */ void *mDestination;
} BgPaletteCopyRequest;

void RequestBgPaletteRowCopy(u8 *palette, u32 srcRow, u32 dstRow);
void AdvanceBg2ScrUpload(void);
void CopyBg2ScrBufferRect(const void *source, int destOffset, int width, int rowCount);
void RequestBg2ScrUpload(void);
void ReleaseBg2ScrBuffer(void);
void CreateBg2ScrBuffer(const void *scr);

extern struct Bg2ScrBuffer *gBg2ScrBuffer;
extern BgPaletteCopyRequest gBgPaletteCopyRequest;

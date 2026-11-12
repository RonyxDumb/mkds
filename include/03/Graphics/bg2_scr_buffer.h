#pragma once

#include "types.h"

// Object behind gBg2ScrBuffer.
typedef struct Bg2ScrBuffer {
    /* 000 */ u32 mTask;
    /* 004 */ u8 mScr[0x600];
    /* 604 */ u8 mUploadRequested;
} Bg2ScrBuffer;

void AdvanceBgPaletteCopy(u32 entry);
void RequestBgPaletteCopy(u32 palette);
void AdvanceBgPaletteRowCopy(u32 entry);
void RequestBgPaletteRowCopy(u8 *palette, u32 srcRow, u32 dstRow);
void AdvanceBg2ScrUpload(void);
void CopyBg2ScrBufferRect(int source, int destOffset, int width, int rowCount);
void RequestBg2ScrUpload(void);
void ReleaseBg2ScrBuffer(void);
void CreateBg2ScrBuffer(const void *scr);

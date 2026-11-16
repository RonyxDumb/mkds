#pragma once

#include "types.h"

void MBi_ReadSegmentHeader(u32 *segmentHeader, u32 offsetStart, u32 offsetEnd, int fillFlag);


typedef struct FSFile FSFile;

int FsUnk_ReadCartHeader_from_thumb(FSFile *file, void *buffer, u32 bufferSize);

extern const u32 mbi_seg_header_default[6];
extern u32 *mbi_seg_header;
extern u8 g_str_rom_3[4];

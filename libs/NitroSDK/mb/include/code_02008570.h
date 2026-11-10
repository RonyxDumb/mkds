#pragma once

#include "types.h"

extern u32 *mbi_seg_header;
extern u8 data_usa_0216178c[];

typedef struct FSFile FSFile;

int MB_ReadSegment(FSFile *file, void *buffer, u32 bufferSize);

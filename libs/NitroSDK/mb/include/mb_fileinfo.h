#pragma once

#include "types.h"

void MBi_ReadSegmentHeader(u32 *segmentHeader, u32 offsetStart, u32 offsetEnd, int fillFlag);

extern u32 *mbi_seg_header;
extern u8 data_usa_0216178c[];

typedef struct FSFile FSFile;

int MB_ReadSegment(FSFile *file, void *buffer, u32 bufferSize);

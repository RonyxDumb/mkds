#pragma once

#include "types.h"

typedef struct FSArchive FSArchive;

s32 RomArchiveWriteCallback(FSArchive *archive, const void *src, u32 dst, u32 length);

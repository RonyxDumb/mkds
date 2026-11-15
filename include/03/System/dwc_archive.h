#pragma once

#include "types.h"
#include "03/unk_021da000.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

BOOL AreStringEndsEqual(const u8 *first, const char *second, s32 endLength);
void DeleteLoadedFile(void *block, ...);
void *LoadFile(const u8 *path, u32 *outSize, s32 alignment);
s32 DwcArchiveWriteCallback(FSArchive *archive, const void *src, u32 offset, u32 length);
void DwcArchiveReadEndCallback(void *arg);
s32 DwcArchiveReadCallback(FSArchive *archive, void *dst, u32 offset, u32 length);
s32 DwcArchiveProc(FSFile *file, u32 command);
void ReleaseDwcArchive(void);
void InitDwcArchive(void);

extern const u8 gDwcArchiveName[4];
// Character data in the overlay's data.
extern char gLzFileSuffix[3];
extern u8 gRomDir[5];
extern u8 gDwcUtilityBinName[21];

extern struct DwcArchive *gDwcArchive;

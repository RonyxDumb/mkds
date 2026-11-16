#pragma once

#include "types.h"
#include "code_02003024.h" // FSArchive

// Record whose first fields ArchiveHeaderMatches checks; fieldC is the offset of the first of fieldE blocks that
// ArchiveLoadFromMemory walks, each starting with a word and its own size.
typedef struct Unk02018344 {
    /* 00 */ u32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u8 field8[4];
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
} Unk02018344;

// FSArchive followed by the three words ArchiveLoadFromMemory sets.
typedef struct Unk020182c0 {
    /* 00 */ FSArchive field0;
    /* 5c */ Unk02018344 *field5C;
    /* 60 */ u8 *field60;
    /* 64 */ u8 *field64;
} Unk020182c0;

void *ArchiveFileGetAddress(const u8 *a);
u32 ArchiveUnload(FSArchive *a);
u32 ArchiveLoadFromMemory(Unk020182c0 *a, const u8 *b, Unk02018344 *c);
u32 ArchiveHeaderMatches(Unk02018344 *a);

#pragma once

#include "types.h"

// Section header: two words; LocateBmgSections adds the second to the section address to move on.
typedef struct BmgSectionHeader {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
} BmgSectionHeader;

// First word of the two sections LocateBmgSections keeps, after the byte reversal: the table of entry offsets and the
// body that holds the text.
#define BMG_SECTION_TAG_ENTRY_OFFSETS 0x494e4631
#define BMG_SECTION_TAG_BODY 0x44415431

// A BMG message file: the section count and the first section header.
typedef struct Bmg {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u32 mSectionCount;
    /* 10 */ u8 mUnk_10[0x10];
    /* 20 */ BmgSectionHeader mFirstSection;
} Bmg;

// The BMG section holding the offset of each message entry (mEntryOffsets), found by LocateBmgSections.
typedef struct BmgEntryOffsetSection {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ u32 mEntryOffsets[1];
} BmgEntryOffsetSection;

// Section of LocateBmgSections whose first word is 0x44415431 (gBmgBodySection): bytes from 8.
typedef struct BmgBodySection {
    /* 00 */ u32 mTag;
    /* 04 */ u32 mNextOffset;
    /* 08 */ u8 mBody[1];
} BmgBodySection;

void LocateBmgSections(Bmg *bmg);
void *GetBmgEntry(Bmg *bmg, s32 index);

extern struct BmgBodySection *gBmgBodySection;
extern struct BmgEntryOffsetSection *gBmgEntryOffsetSection;

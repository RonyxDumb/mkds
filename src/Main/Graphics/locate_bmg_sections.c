#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/oam.h"
#include "Main/MapObjects/data_0217b000.h"

struct BmgBodySection *gBmgBodySection;
struct BmgEntryOffsetSection *gBmgEntryOffsetSection;

#pragma thumb on
#pragma optimize_for_size on
void LocateBmgSections(Bmg *bmg) {
    u32 sectionIndex;
    BmgSectionHeader *nextSection;
    BmgSectionHeader *section;
    u32 tag;

    nextSection = &bmg->mFirstSection;
    for (sectionIndex = 0; sectionIndex < bmg->mSectionCount; sectionIndex++) {
        section = nextSection;
        nextSection = OFFSET_PTR(BmgSectionHeader, nextSection, nextSection->mNextOffset);
        tag = ReverseBytes32(section->mTag);
        switch (tag) {
            case 0x494e4631:
                gBmgEntryOffsetSection = (BmgEntryOffsetSection *) section;
                break;
            case 0x44415431:
                gBmgBodySection = (BmgBodySection *) section;
                break;
        }
    }
}

void *GetBmgEntry(Bmg *bmg, s32 index) {
    LocateBmgSections(bmg);
    return &gBmgBodySection->mBody[gBmgEntryOffsetSection->mEntryOffsets[index % 0x10000]];
}
#pragma thumb off

#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

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
            case BMG_SECTION_TAG_ENTRY_OFFSETS:
                gBmgEntryOffsetSection = (BmgEntryOffsetSection *) section;
                break;
            case BMG_SECTION_TAG_BODY:
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

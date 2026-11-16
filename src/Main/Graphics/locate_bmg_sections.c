#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

struct BmgBodySection *g_CurrentBmgDat1Block;
struct BmgEntryOffsetSection *g_CurrentBmgInf1Block;

#pragma thumb on
#pragma optimize_for_size on
void Bmg_Load_from_thumb(Bmg *bmg) {
    u32 sectionIndex;
    BmgSectionHeader *nextSection;
    BmgSectionHeader *section;
    u32 tag;

    nextSection = &bmg->mFirstSection;
    for (sectionIndex = 0; sectionIndex < bmg->mSectionCount; sectionIndex++) {
        section = nextSection;
        nextSection = OFFSET_PTR(BmgSectionHeader, nextSection, nextSection->mNextOffset);
        tag = SwapEndianness32_from_thumb(section->mTag);
        switch (tag) {
            case BMG_SECTION_TAG_ENTRY_OFFSETS:
                g_CurrentBmgInf1Block = (BmgEntryOffsetSection *) section;
                break;
            case BMG_SECTION_TAG_BODY:
                g_CurrentBmgDat1Block = (BmgBodySection *) section;
                break;
        }
    }
}

void *Bmg_GetRawStringPointer_from_thumb(Bmg *bmg, s32 index) {
    Bmg_Load_from_thumb(bmg);
    return &g_CurrentBmgDat1Block->mBody[g_CurrentBmgInf1Block->mEntryOffsets[index % 0x10000]];
}
#pragma thumb off

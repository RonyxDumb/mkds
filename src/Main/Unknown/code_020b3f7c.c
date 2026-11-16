#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
#pragma optimize_for_size on
void setupBmg(Bmg *bmg) {
    u32 i;
    u32 p;
    u32 section;
    u32 tag;

    p = (u32) &bmg->mFirstSection;
    for (i = 0; i < bmg->mSectionCount; i++) {
        section = p;
        p = p + ((BmgSectionHeader *) p)->mNextOffset;
        tag = ReverseBytes32(((BmgSectionHeader *) section)->mTag);
        switch (tag) {
            case 0x494e4631:
                BMG_INF1_Pointer = (Unk0217b340 *) section;
                break;
            case 0x44415431:
                BMG_DAT1_Pointer = (BmgBodySection *) section;
                break;
        }
    }
}

void *jn_msg_getMessage(Bmg *bmg, s32 index) {
    setupBmg(bmg);
    return &BMG_DAT1_Pointer->mBody[BMG_INF1_Pointer->mEntryOffsets[index % 0x10000]];
}
#pragma thumb off

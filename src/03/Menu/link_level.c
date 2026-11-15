#include "03/Menu/link_level.h"
#include "03/unk_021da000.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021d1c18.h"
#include "03/System/exp_heap.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1000.h"
#include "03/code_021d2ecc.h"
#include "code_02142eac.h"
#include "registers.h"

const u16 gLinkLevelPosition[2] = {0xe5, 0x26};
const u8 gLinkLevelImages[2][4] = {{0x18, 0x17, 0x16, 0x15}, {0x5f, 0x5e, 0x5d, 0x5c}};
LinkLevel *gLinkLevel;

void CreateLinkLevel(int row) {
    if (gLinkLevel == NULL) {
        gLinkLevel = AllocExpHeapBlock(0xc, 4);
        gLinkLevel->mImageRow = row;
        gLinkLevel->mOamEntry = CreateOamEntryFromNceImage(0, gLinkLevelImages[row][0]);
        gLinkLevel->mOamEntry->mAttr01 =
            ((gLinkLevelPosition[0] & 0x1ff) << 16) |
            ((gLinkLevel->mOamEntry->mAttr01 & 0xfe00ff00) | (gLinkLevelPosition[1] & 0xff));
        gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & 0xfffff3ff) | 0x800;
        gLinkLevel->mTask = AddTask(0, UpdateLinkLevel, NULL, 0x78);
    }
}

void ReleaseLinkLevel(void) {
    if (gLinkLevel != NULL) {
        RemoveTaskEntryWrapper(0, gLinkLevel->mTask);
        DeleteOamEntry(gLinkLevel->mOamEntry);
        FreeExpHeapBlockAndClearPointer(&gLinkLevel);
    }
}

void UpdateLinkLevel(void) {
    u32 linkLevel;
    u16 savedIme;
    linkLevel = 0;
    savedIme = reg_OS_IME;
    reg_OS_IME = 0;
    if (WM_GetAllowedChannel() != 0x8000) {
        linkLevel = WM_GetLinkLevel();
    }
    reg_OS_IME;
    reg_OS_IME = savedIme;
    CopyNceImageToOamEntries(0, gLinkLevelImages[gLinkLevel->mImageRow][linkLevel], gLinkLevel->mOamEntry);
    gLinkLevel->mOamEntry->mAttr01 = ((gLinkLevelPosition[0] & 0x1ff) << 16) |
                                     ((gLinkLevel->mOamEntry->mAttr01 & 0xfe00ff00) | (gLinkLevelPosition[1] & 0xff));
    gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & 0xfffff3ff) | 0x800;
}

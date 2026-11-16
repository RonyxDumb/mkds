#include "03/Menu/link_level.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/Graphics/nce_file.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "wireless_link_control.h"
#include "registers.h"

const u16 gLinkLevelPosition[2] = {0xe5, 0x26};
const u8 gLinkLevelImages[2][4] = {{0x18, 0x17, 0x16, 0x15}, {0x5f, 0x5e, 0x5d, 0x5c}};
LinkLevel *gLinkLevel;

void CreateLinkLevel(int row) {
    if (gLinkLevel == NULL) {
        gLinkLevel = AllocExpHeapBlock(sizeof(LinkLevel), 4);
        gLinkLevel->mImageRow = row;
        gLinkLevel->mOamEntry = CreateOamEntryFromNceImage(0, gLinkLevelImages[row][0]);
        gLinkLevel->mOamEntry->mAttr01 =
            ((gLinkLevelPosition[0] & 0x1ff) << 16) |
            ((gLinkLevel->mOamEntry->mAttr01 & OAM_ENTRY_NOT_POSITION_MASK) | (gLinkLevelPosition[1] & 0xff));
        gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & OAM_ENTRY_NOT_PRIORITY_MASK) | 0x800;
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

void UpdateLinkLevel(TaskEntry *task, void *arg) {
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
    gLinkLevel->mOamEntry->mAttr01 =
        ((gLinkLevelPosition[0] & 0x1ff) << 16) |
        ((gLinkLevel->mOamEntry->mAttr01 & OAM_ENTRY_NOT_POSITION_MASK) | (gLinkLevelPosition[1] & 0xff));
    gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & OAM_ENTRY_NOT_PRIORITY_MASK) | 0x800;
}

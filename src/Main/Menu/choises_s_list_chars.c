#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Menu/choises_s.h"
#include "Main/Sound/sound_seq.h"

#pragma thumb on

Nclr *GetChoises_s_b_Pallette_from_thumb(void) {
    return (g_RaceOptionMenuManager->mChoisesSBNclr);
}

Ncgr *GetSomeBgTileData_from_thumb(void) {
    int choisesSListIndex;
    choisesSListIndex = GetCurrentOptionMenuKind_from_thumb();
    if (choisesSListIndex == 1) {
        g_RaceOptionMenuManager->mChoisesSBNcgr->mData = g_RaceOptionMenuManager->mList1Chars;
    } else {
        choisesSListIndex = GetCurrentOptionMenuKind_from_thumb();
        if (choisesSListIndex == 2) {
            g_RaceOptionMenuManager->mChoisesSBNcgr->mData = g_RaceOptionMenuManager->mList2Chars;
        }
    }
    return g_RaceOptionMenuManager->mChoisesSBNcgr;
}

void *GetChoisesSListScreenMapData(void) {
    int choisesSListIndex;
    u16 *screenMapData;
    screenMapData = 0;
    choisesSListIndex = GetCurrentOptionMenuKind_from_thumb();
    if (choisesSListIndex == 0) {
        if (g_RaceOptionMenuManager->mList0Nscr != NULL) {
            screenMapData = g_RaceOptionMenuManager->mList0Nscr->mData;
        }
    } else if (choisesSListIndex == 1) {
        if (g_RaceOptionMenuManager->mList1Nscr != NULL) {
            screenMapData = g_RaceOptionMenuManager->mList1Nscr->mData;
        }
    } else if (choisesSListIndex == 2) {
        if (g_RaceOptionMenuManager->mList2Nscr != NULL) {
            screenMapData = g_RaceOptionMenuManager->mList2Nscr->mData;
        }
    } else if ((choisesSListIndex == 3) && (g_RaceOptionMenuManager->mList3Nscr != NULL)) {
        screenMapData = g_RaceOptionMenuManager->mList3Nscr->mData;
    }
    return screenMapData;
}

u32 IsChoisesSPickLocked(void) {
    return (g_RaceOptionMenuManager->mPickLocked);
}

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
// In mode 5 the sequence index is always 4, whatever the selected value.
void StartChoisesSSelectedValueSeq(void) {
    if (GetRaceMode() == 5) {
        StartChoisesSValueSeq(4);
    } else {
        switch (g_RaceOptionMenuManager->mSelectedValue) {
            case CHOISES_S_PICK_CONTINUE:
            case CHOISES_S_PICK_REPLAY:
                StartChoisesSValueSeq(0);
                break;
            case CHOISES_S_PICK_RETRY:
            case CHOISES_S_PICK_RESTART:
                StartChoisesSValueSeq(1);
                break;
            case CHOISES_S_PICK_NEXT:
            case CHOISES_S_PICK_NEXT_LAST:
            case CHOISES_S_PICK_STAFF_CREDITS:
                StartChoisesSValueSeq(5);
                break;
            case CHOISES_S_PICK_CHANGE_COURSE:
            case CHOISES_S_PICK_CHANGE_CHARACTERS:
            case CHOISES_S_PICK_SELECT_MISSION:
                StartChoisesSValueSeq(2);
                break;
            case CHOISES_S_PICK_QUIT:
                StartChoisesSValueSeq(3);
                break;
        }
    }
}
#pragma thumb off

#pragma thumb on

u32 ComputeSomeMESize_from_thumb(int valueCount) {
    if (valueCount < 0) {
        return 0;
    }
    if (valueCount < 2) {
        return 0x1000;
    }
    return valueCount << 0xb;
}

#pragma thumb off

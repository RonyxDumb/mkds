#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Menu/choises_s.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

#pragma thumb on

Nclr *GetChoisesSBNclr(void) {
    return (gChoisesS->mChoisesSBNclr);
}

Ncgr *GetChoisesSBNcgrWithListChars(void) {
    int choisesSListIndex;
    choisesSListIndex = GetChoisesSListIndex();
    if (choisesSListIndex == 1) {
        gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList1Chars;
    } else {
        choisesSListIndex = GetChoisesSListIndex();
        if (choisesSListIndex == 2) {
            gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList2Chars;
        }
    }
    return gChoisesS->mChoisesSBNcgr;
}

void *GetChoisesSListScreenMapData(void) {
    int choisesSListIndex;
    u16 *screenMapData;
    screenMapData = 0;
    choisesSListIndex = GetChoisesSListIndex();
    if (choisesSListIndex == 0) {
        if (gChoisesS->mList0Nscr != NULL) {
            screenMapData = gChoisesS->mList0Nscr->mData;
        }
    } else if (choisesSListIndex == 1) {
        if (gChoisesS->mList1Nscr != NULL) {
            screenMapData = gChoisesS->mList1Nscr->mData;
        }
    } else if (choisesSListIndex == 2) {
        if (gChoisesS->mList2Nscr != NULL) {
            screenMapData = gChoisesS->mList2Nscr->mData;
        }
    } else if ((choisesSListIndex == 3) && (gChoisesS->mList3Nscr != NULL)) {
        screenMapData = gChoisesS->mList3Nscr->mData;
    }
    return screenMapData;
}

u32 IsChoisesSPickLocked(void) {
    return (gChoisesS->mPickLocked);
}

#pragma optimize_for_size on
// In mode 5 the sequence index is always 4, whatever the selected value.
void StartChoisesSSelectedValueSeq(void) {
    if (ChoisesSGetCurrentMode() == MODE_WIFI) {
        StartChoisesSValueSeq(4);
    } else {
        switch (gChoisesS->mSelectedValue) {
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

u32 GetChoisesSListCharsSize(int valueCount) {
    if (valueCount < 0) {
        return 0;
    }
    if (valueCount < 2) {
        return 0x1000;
    }
    return valueCount << 0xb;
}

#pragma thumb off

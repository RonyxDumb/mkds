#include "Main/Unknown/code_020b3260.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_021059e0.h"

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

#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
// In mode 5 the sequence index is always 4, whatever the selected value.
void StartChoisesSSelectedValueSeq(void) {
    if (ChoisesSGetCurrentMode() == 5) {
        StartChoisesSValueSeq(4);
    } else {
        switch (gChoisesS->mSelectedValue) {
            case 0:
            case 8:
                StartChoisesSValueSeq(0);
                break;
            case 1:
            case 3:
                StartChoisesSValueSeq(1);
                break;
            case 2:
            case 7:
            case 10:
                StartChoisesSValueSeq(5);
                break;
            case 4:
            case 5:
            case 6:
                StartChoisesSValueSeq(2);
                break;
            case 9:
                StartChoisesSValueSeq(3);
                break;
        }
    }
}
#pragma thumb off

#pragma thumb on

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

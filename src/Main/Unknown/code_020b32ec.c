#include "Main/Unknown/code_020b32ec.h"
#include "Main/Ui/ChoisesS.h"

#pragma thumb on

Nclr *rchoi_getPalData(void) {
    return (rchoi_sState->mChoisesSBNclr);
}

Ncgr *rchoi_getCharData(void) {
    int choisesSListIndex;
    choisesSListIndex = rchoi_getCurChoicesSetId();
    if (choisesSListIndex == 1) {
        rchoi_sState->mChoisesSBNcgr->mData = rchoi_sState->mList1Chars;
    } else {
        choisesSListIndex = rchoi_getCurChoicesSetId();
        if (choisesSListIndex == 2) {
            rchoi_sState->mChoisesSBNcgr->mData = rchoi_sState->mList2Chars;
        }
    }
    return rchoi_sState->mChoisesSBNcgr;
}

void *rchoi_getMapData(void) {
    int choisesSListIndex;
    u16 *screenMapData;
    screenMapData = 0;
    choisesSListIndex = rchoi_getCurChoicesSetId();
    if (choisesSListIndex == 0) {
        if (rchoi_sState->mList0Nscr != NULL) {
            screenMapData = rchoi_sState->mList0Nscr->mData;
        }
    } else if (choisesSListIndex == 1) {
        if (rchoi_sState->mList1Nscr != NULL) {
            screenMapData = rchoi_sState->mList1Nscr->mData;
        }
    } else if (choisesSListIndex == 2) {
        if (rchoi_sState->mList2Nscr != NULL) {
            screenMapData = rchoi_sState->mList2Nscr->mData;
        }
    } else if ((choisesSListIndex == 3) && (rchoi_sState->mList3Nscr != NULL)) {
        screenMapData = rchoi_sState->mList3Nscr->mData;
    }
    return screenMapData;
}

u32 rchoi_getIsExittingRace(void) {
    return (rchoi_sState->mPickLocked);
}

#pragma thumb off

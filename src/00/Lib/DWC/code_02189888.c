#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_02189888.h"
#include "00/Lib/DWC/code_021898dc.h"
#include "00/Lib/DWC/code_0218973c.h"

u32 CheckStartStealthSearch(ACWORK *work) {
    u8 channel;
    int listNum;
    u32 nextPhase;
    if ((work->mStealthChannel != 0) && (listNum = DWCi_AC_MakeSearchList(AC_SEARCH_LIST_HIDDEN), listNum != 0)) {
        channel = DWCi_AC_GetStealthChannel(0);
        work->mSearchChannel = channel;
        return 5;
    }
    if (work->mAroundCount < 1) {
        nextPhase = SearchAround2ndLap(work);
        return nextPhase;
    }
    return 6;
}

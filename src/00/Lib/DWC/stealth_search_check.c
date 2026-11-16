#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/stealth_search_check.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/DWC/access_point_scan.h"

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

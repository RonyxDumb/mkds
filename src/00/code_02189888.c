#include "00/code_02189888.h"
#include "00/code_021898dc.h"
#include "00/code_0218973c.h"

u32 CheckStartStealthSearch(ACWORK *work) {
    u8 channel;
    int listNum;
    u32 nextPhase;
    if ((work->mUnk_d16 != 0) && (listNum = DWCi_AC_MakeSearchList(2), listNum != 0)) {
        channel = DWCi_AC_GetStealthChannel(0);
        work->mUnk_d11 = channel;
        return 5;
    }
    if (work->mUnk_d0b_4 < 1) {
        nextPhase = SearchAround2ndLap(work);
        return nextPhase;
    }
    return 6;
}

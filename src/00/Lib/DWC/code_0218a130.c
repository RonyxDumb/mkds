#include "00/Lib/DWC/code_0218a130.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/code_02187484.h"
#include "00/code_02188000.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_02189350.h"

u32 ConnectTestProcess(ACWORK *work) {
    ACHOLD *hold;
    u32 error;

    hold = DWCi_AC_GetMemPtr(1);
    error = DWC_Netcheck_GetError();
    if (error != 0) {
        if (hold->mEndType == DWCi_ConvConnectAPType(work->mConnectApType)) {
            hold->mErrorTest = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (error != 0xb) {
            work->mFindList[work->mConnectNo].mState = 1;
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}

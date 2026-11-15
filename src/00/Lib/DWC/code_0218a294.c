#include "00/Lib/DWC/code_0218a294.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/code_02187484.h"
#include "00/code_02188000.h"
#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_02188ee0.h"
#include "00/Lib/DWC/code_0218a0f4.h"
#include "00/Lib/DWC/code_0218a118.h"
#include "00/Lib/DWC/code_0218a130.h"
#include "00/Lib/DWC/code_0218a194.h"
#include "00/Lib/DWC/code_0218a1bc.h"
#include "00/Lib/DWC/code_0218a24c.h"

u32 DWCi_AC_ConnectTest(void) {
    u32 phase;
    ACWORK *work;

    phase = DWCi_AC_GetPhase();
    work = DWCi_AC_GetMemPtr(0x10);
    if (WCM_GetPhase() == 9) {
        switch (phase) {
            case 10:
                phase = ConnectTestStart(work);
                break;
            case 12:
                phase = GetIPAddress(work);
                break;
            case 13:
                phase = ConnectTestCreate();
                break;
            case 14:
                phase = ConnectTestProcess(work);
                break;
            case 15:
                phase = ConnectTestEnd(work);
                break;
            case 11:
                phase = ConnectTestRetry();
                break;
        }
    } else {
        switch (phase) {
            case 15:
                phase = ConnectTestEnd(work);
                break;
            case 11:
                phase = ConnectTestRetry();
                break;
            case 14:
                DWC_Netcheck_Abort();
                DWC_Netcheck_Destroy();
            default:
                work->mFindList[work->mConnectNo].mState = 2;
                phase = 0xb;
        }
    }
    return phase;
}

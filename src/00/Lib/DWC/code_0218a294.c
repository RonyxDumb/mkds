#include "00/Lib/NitroWiFi/code_021a4b98.h"
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
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    if (WCM_GetPhase() == WIFI_LINK_PHASE_CONNECTED) {
        switch (phase) {
            case AC_PHASE_TEST_START:
                phase = ConnectTestStart(work);
                break;
            case AC_PHASE_TEST_GET_IP:
                phase = GetIPAddress(work);
                break;
            case AC_PHASE_TEST_CREATE:
                phase = ConnectTestCreate();
                break;
            case AC_PHASE_TEST_PROCESS:
                phase = ConnectTestProcess(work);
                break;
            case AC_PHASE_TEST_END:
                phase = ConnectTestEnd(work);
                break;
            case AC_PHASE_TEST_RETRY:
                phase = ConnectTestRetry();
                break;
        }
    } else {
        switch (phase) {
            case AC_PHASE_TEST_END:
                phase = ConnectTestEnd(work);
                break;
            case AC_PHASE_TEST_RETRY:
                phase = ConnectTestRetry();
                break;
            case AC_PHASE_TEST_PROCESS:
                DWC_Netcheck_Abort();
                DWC_Netcheck_Destroy();
            default:
                work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_TEST_ABORTED;
                phase = AC_PHASE_TEST_RETRY;
        }
    }
    return phase;
}

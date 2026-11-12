#include "00/Lib/DWC/code_0218a24c.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_0218a064.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8aa8.h"
#include "00/Lib/NitroWiFi/socl_startup.h"

u32 ConnectTestStart(ACWORK *work) {
    u32 hold;
    u32 config;
    int result;
    hold = DWCi_AC_GetMemPtr(1);
    config = DWCi_AC_GetMemPtr(4);
    MakeSOCConfig((const SocketAllocPair *) hold, work, (SOCConfig *) config);
    *(u32 *) &SOCLiYieldWait = 4;
    result = SOC_Startup((void *) config);
    if (result != 0) {
        DWCi_AC_SetError(2);
        return 0x11;
    }
    return 0xc;
}

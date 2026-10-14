/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevGetWirelessCounter FUN_06002098
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevGetWirelessCounterCfm *WMSP_WL_DevGetWirelessCounter(u16 *buf)
{
#if SDK_VERSION_WL >= 16700
    return (WlDevGetWirelessCounterCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_GET_INFO, 92);
#else
    return (WlDevGetWirelessCounterCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_GET_INFO, 96);
#endif
}

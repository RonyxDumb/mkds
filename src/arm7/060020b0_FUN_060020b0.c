/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevGetVersion FUN_060020b0
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevGetVersionCfm *WMSP_WL_DevGetVersion(u16 *buf)
{
    return (WlDevGetVersionCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_GET_VERINFO, 9);
}

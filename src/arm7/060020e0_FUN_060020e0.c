/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevRestart FUN_060020e0
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevRestartCfm *WMSP_WL_DevRestart(u16 *buf)
{
    return (WlDevRestartCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_REBOOT, 1);
}

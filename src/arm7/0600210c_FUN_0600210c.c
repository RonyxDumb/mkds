/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevIdle FUN_0600210c
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevIdleCfm *WMSP_WL_DevIdle(u16 *buf)
{
    return (WlDevIdleCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_IDLE, 1);
}

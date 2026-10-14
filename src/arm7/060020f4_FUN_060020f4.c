/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevClass1 FUN_060020f4
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevClass1Cfm *WMSP_WL_DevClass1(u16 *buf)
{
    return (WlDevClass1Cfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_CLASS1, 1);
}

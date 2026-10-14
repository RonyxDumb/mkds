/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_ParamGetMode FUN_0600213c
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlParamGetModeCfm *WMSP_WL_ParamGetMode(u16 *buf)
{
    return (WlParamGetModeCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_PARAM_GET_MODE, 2);
}

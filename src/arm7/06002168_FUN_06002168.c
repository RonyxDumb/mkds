/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_ParamGetMacAddress FUN_06002168
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlParamGetMacAddressCfm *WMSP_WL_ParamGetMacAddress(u16 *buf)
{
    return (WlParamGetMacAddressCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_PARAM_GET_MAC_ADRS, 4);
}

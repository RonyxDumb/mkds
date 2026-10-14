/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_ParamGetEnableChannel FUN_06002150
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlParamGetEnableChannelCfm *WMSP_WL_ParamGetEnableChannel(u16 *buf)
{
    return (WlParamGetEnableChannelCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_PARAM_GET_ENABLECHANNEL, 3);
}

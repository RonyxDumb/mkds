/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WMSPi_WL_NoArg SDK_data_06001fc0
#define WMSP_WL_DevGetStationState FUN_06002084
#include "wmsp_private.h"
extern WlCmdCfm *WMSPi_WL_NoArg(u16 *buf, u16 code, u16 cfmLength);
#pragma thumb off
WlDevGetStationStateCfm *WMSP_WL_DevGetStationState(u16 *buf)
{
    return (WlDevGetStationStateCfm *)WMSPi_WL_NoArg(buf, WL_CMDCODE_DEV_GET_STATE, 2);
}

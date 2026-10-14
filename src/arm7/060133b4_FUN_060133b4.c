/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WL_WriteByte FUN_060096e4
#define SetDSParamSet FUN_060133b4

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "TxCtrl.h"
#include "MAC.h"
#include "CAM.h"
#include "MA.h"
#include "Compati.h"
#include "WlOpe.h"
#include "WlIntrTask.h"

#pragma thumb off
u32 SetDSParamSet(u8 *pBuf)
{
    WL_WriteByte(&pBuf[0], ID_DS_PARAM_ELEMENT);

    WL_WriteByte(&pBuf[1], 1);

    WL_WriteByte(&pBuf[2], wlMan->Work.CurrChannel);

    return 3;
}

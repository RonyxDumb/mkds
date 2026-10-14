/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define StopBeaconFrame FUN_06014228

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
void StopBeaconFrame(void)
{
    LPTXQ pTxq = &wlMan->TxCtrl.Beacon;

    *(vu16 *)MREG_BCN_ADRS = 0;

    pTxq->Busy = FALSE;
}

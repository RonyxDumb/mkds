/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_SetPowerMgtMode FUN_0600eb40

#include "WlSys.h"
#include "WlLib.h"

#include "WlCmdLabel.h"
#include "Dot11Frm.h"
#include "TxCtrl.h"
#include "WlNic.h"
#include "MAC.h"
#include "Compati.h"

#include "CAM.h"

#pragma thumb off
void CAM_SetPowerMgtMode(u16 camAdrs, u16 pmtMode)
{
    LPCAM_MAN pCamMan = &wlMan->CamMan;

    CAM_CheckCAM(camAdrs);

    pCamMan->PowerMgtMode = (pCamMan->PowerMgtMode & ~(1 << camAdrs)) | (pmtMode << camAdrs);

    if (pCamMan->PowerMgtMode & ~pCamMan->NotClass3) {
        *(vu16 *)MREG_TXQ_CLOSE = TXQ_CLOSE_TXQ2;
    } else {
        *(vu16 *)MREG_TXQ_OPEN = TXQ_OPEN_TXQ2;
    }
}

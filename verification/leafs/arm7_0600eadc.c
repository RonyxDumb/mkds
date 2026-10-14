/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_SetAwake FUN_0600eadc

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
void CAM_SetAwake(u32 camAdrs)
{
    CAM_CheckCAM(camAdrs);

    wlMan->CamMan.PowerState |= (1 << camAdrs);
}

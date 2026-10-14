/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_IsActive FUN_0600e8f8

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
u32 CAM_IsActive(u32 camAdrs)
{
    return (wlMan->CamMan.PowerState >> camAdrs) & 1;
}

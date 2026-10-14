/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CAM_UpdateLifeTime FUN_0600ea58

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
void CAM_UpdateLifeTime(u32 camAdrs)
{
    CAM_CheckCAM(camAdrs);

    wlMan->Config.pCAM[camAdrs].lifeTime = wlMan->Config.pCAM[camAdrs].maxLifeTime;
}

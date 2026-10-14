/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define CAM_SetTIMElementBitmap FUN_0600e748
#define MoveHeapBuf FUN_06009040
#define OS_EnableIrqMask thunk_FUN_037f888c
#define CAM_AddBcFrame FUN_0600ed84

#include "WlSys.h"
#include "WlLib.h"

#include "WlCmdLabel.h"
#include "Dot11Frm.h"
#include "TxCtrl.h"
#include "WlNic.h"
#include "MAC.h"
#include "Compati.h"

#include "CAM.h"
extern void CAM_SetTIMElementBitmap(u32 camAdrs);
#pragma thumb off
void CAM_AddBcFrame(LPHEAPBUF_MAN pBufMan, void *pBuf)
{
    LPHEAPBUF_MAN pBufManBc = &wlMan->HeapMan.TxPri[QID_BROADCAST];
    u32 x;

    x = OS_DisableIrqMask(OS_IE_WIRELESS);

    if (GetHeapBufCount(pBufManBc) == 0) {
        CAM_SetTIMElementBitmap(0);
    }

    MoveHeapBuf(pBufMan, pBufManBc, pBuf);

    OS_EnableIrqMask(x);
}

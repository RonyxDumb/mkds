/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SetManCtrlFrame FUN_06014338
#define TxqPri FUN_0601536c
#define TxManCtrlFrame FUN_060143ac

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
extern void SetManCtrlFrame(LPTXFRM pFrm);
extern void TxqPri(u32 pri);
#pragma thumb off
void TxManCtrlFrame(LPTXFRM pFrm)
{
    SetManCtrlFrame(pFrm);
    TxqPri(QID_MANCTRL);
}

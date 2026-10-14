/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_SetIrqFunction thunk_FUN_037f8944
#define OS_EnableIrqMask thunk_FUN_037f888c
#define WlIntr SDK_data_0600d920
#define InitializeIntr FUN_0600c434

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "MA.h"
#include "TxCtrl.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "WlIntr.h"
#include "Compati.h"
#include "MA.h"
#include "WlOpe.h"
extern void WlIntr(void);
#pragma thumb off
void InitializeIntr(void)
{
    OS_SetIrqFunction(OS_IE_WIRELESS, WlIntr);

    OS_EnableIrqMask(OS_IE_WIRELESS);
}

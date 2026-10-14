/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define OS_SetIrqFunction thunk_FUN_037f8944
#define ReleaseIntr FUN_0600c404

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

#pragma thumb off
void ReleaseIntr(void)
{
    OS_DisableIrqMask(OS_IE_WIRELESS);

    OS_SetIrqFunction(OS_IE_WIRELESS, NULL);
}

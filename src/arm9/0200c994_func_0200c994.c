/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask Os_DisableIrqHandler
#define OSi_IrqCallbackInfo SDK_data_0216fee0
#define OSi_IrqCallbackInfoIndex SDK_data_021617bc
#define SDK_AUTOLOAD_DTCM_START SDK_data_027e0000
#define OSi_IrqCallback func_0200c994
#include "sections.h"
#include "OS_irqTable.h"
#include "code32.h"
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[8];
extern u16 OSi_IrqCallbackInfoIndex[8];
void OSi_IrqCallback(s32 index)
{
    OSIrqMask mask = (1UL << OSi_IrqCallbackInfoIndex[index]);
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;

    OSi_IrqCallbackInfo[index].func = NULL;

    if (callback)
    {
        (callback)(OSi_IrqCallbackInfo[index].arg);
    }

    OS_SetIrqCheckFlag(mask);

    if (!OSi_IrqCallbackInfo[index].enable)
    {
        (void)OS_DisableIrqMask(mask);
    }
}

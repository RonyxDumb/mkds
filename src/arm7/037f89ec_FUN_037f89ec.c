/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_IrqThreadQueue SDK_data_0380766c
#define OS_InitIrqTable FUN_037f89ec
#include <nitro.h>
    #include <nitro/itcm_begin.h>
    #include <nitro/itcm_end.h>
extern OSThreadQueue OSi_IrqThreadQueue;
#pragma thumb off
void OS_InitIrqTable (void)
{
    OS_InitThreadQueue(&OSi_IrqThreadQueue);

#ifdef SDK_ARM7
    OSi_SetVBlankCount(0);
#endif
}

/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define EXIi_SetBitRcnt0L SDK_data_037fb824
#define EXIi_SelectRcnt FUN_037fb808
#include "nitro/exi.h"
#include "nitro/exi/ARM7/genPort.h"
extern void EXIi_SetBitRcnt0L(u16 mask, u16 data);
#pragma thumb off
void EXIi_SelectRcnt(EXIGpioIF type)
{
    EXIi_SetBitRcnt0L(EXI_GPIOIF_MASK, type);
}

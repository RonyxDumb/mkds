/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define EXIi_SetBitRcnt0L FUN_037fb824
#include "nitro/exi.h"
#include "nitro/exi/ARM7/genPort.h"

#pragma thumb off
void EXIi_SetBitRcnt0L(u16 mask, u16 data)
{
    EXIi_SetRcnt0L(EXIi_GetRcnt0L() & ~mask | data);
}

/* Decompiled C draft; module arm9; ROM address 02036778. No matching claim. */
#include "types.h"
#include "deps/02036778_EnableVblankIRQ.h"

void EnableVblankIRQ(void)

{
  undefined2 uVar1;
  
  Os_SetIrqHandler(1,uRam020367bc);
  Os_EnableIrqHandler(1);
  uVar1 = *puRam020367c0;
  *puRam020367c0 = 1;
  Os_EnableIrq(1,uVar1);
  GX_VBlankIntr(1);
  return;
}


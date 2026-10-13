/* Decompiled C draft; module arm9; ROM address 0200f6f4. No matching claim. */
#include "types.h"
#include "deps/0200f6f4_Os_InitializeTick.h"

void Os_InitializeTick(void)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  if (*psRam0200f778 == 0) {
    *psRam0200f778 = 1;
    Os_ReserveTimer(0);
    puVar1 = puRam0200f77c;
    *puRam0200f77c = 0;
    puVar2 = puRam0200f780;
    puVar1[1] = 0;
    puVar3 = puRam0200f784;
    *puVar2 = 0;
    uVar4 = uRam0200f788;
    *puVar3 = 0;
    *puVar2 = 0xc1;
    Os_SetIrqHandler(8,uVar4);
    Os_EnableIrqHandler(8);
    *puRam0200f78c = 0;
    return;
  }
  return;
}


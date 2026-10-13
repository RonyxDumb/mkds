/* Decompiled C draft; module arm9; ROM address 0200db9c. No matching claim. */
#include "types.h"
#include "deps/0200db9c_Os_DisableScheduler.h"

uint Os_DisableScheduler(void)

{
  uint uVar1;
  uint unaff_r4;
  
  Os_DisableIrq();
  uVar1 = *(uint *)((uint)piRam0200dbd0 & 0xfffffffc) >> ((uint)piRam0200dbd0 & 3) * 8 |
          *(uint *)((uint)piRam0200dbd0 & 0xfffffffc) << ((uint)piRam0200dbd0 & 3) * -8 + 0x20;
  if (uVar1 != 0xffffffff) {
    *piRam0200dbd0 = uVar1 + 1;
    unaff_r4 = uVar1;
  }
  Os_RestoreIrq();
  return unaff_r4;
}


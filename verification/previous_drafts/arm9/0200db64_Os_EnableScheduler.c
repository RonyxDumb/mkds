/* Decompiled C draft; module arm9; ROM address 0200db64. No matching claim. */
#include "types.h"
#include "deps/0200db64_Os_EnableScheduler.h"

uint Os_EnableScheduler(void)

{
  uint uVar1;
  uint uVar2;
  
  Os_DisableIrq();
  uVar2 = *(uint *)((uint)piRam0200db98 & 0xfffffffc) >> ((uint)piRam0200db98 & 3) * 8 |
          *(uint *)((uint)piRam0200db98 & 0xfffffffc) << ((uint)piRam0200db98 & 3) * -8 + 0x20;
  uVar1 = 0;
  if (uVar2 != 0) {
    *piRam0200db98 = uVar2 - 1;
    uVar1 = uVar2;
  }
  Os_RestoreIrq();
  return uVar1;
}


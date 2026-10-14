/* Decompiled C draft; module arm9; ROM address 0200dbe8. No matching claim. */
#include "types.h"
#include "deps/0200dbe8_Os_SetThreadSwitchCallback.h"

uint Os_SetThreadSwitchCallback(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  Os_DisableIrq();
  uVar1 = iRam0200dc18 + 0xcU & 3;
  uVar2 = *(uint *)(iRam0200dc18 + 0xcU & 0xfffffffc);
  *(undefined4 *)(iRam0200dc18 + 0xc) = param_1;
  Os_RestoreIrq();
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}


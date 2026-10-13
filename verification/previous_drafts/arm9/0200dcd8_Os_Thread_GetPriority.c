/* Decompiled C draft; module arm9; ROM address 0200dcd8. No matching claim. */
#include "types.h"
#include "deps/0200dcd8_Os_Thread_GetPriority.h"

uint Os_Thread_GetPriority(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x70U & 3;
  uVar2 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}


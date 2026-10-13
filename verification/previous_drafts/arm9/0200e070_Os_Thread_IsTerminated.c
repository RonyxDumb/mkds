/* Decompiled C draft; module arm9; ROM address 0200e070. No matching claim. */
#include "types.h"
#include "deps/0200e070_Os_Thread_IsTerminated.h"

bool Os_Thread_IsTerminated(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 100U & 3;
  uVar2 = *(uint *)(param_1 + 100U & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2;
}


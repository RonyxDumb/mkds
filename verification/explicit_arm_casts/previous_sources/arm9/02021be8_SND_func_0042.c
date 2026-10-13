/* Decompiled C draft; module arm9; ROM address 02021be8. No matching claim. */
#include "types.h"
#include "deps/02021be8_SND_func_0042.h"

void SND_func_0042(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  Sound_LockMutex();
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  while (puVar3 != (undefined4 *)0x0) {
    uVar1 = (uint)(puVar3 + 1) & 3;
    uVar2 = *(uint *)((uint)(puVar3 + 1) & 0xfffffffc);
    *puVar3 = 0;
    puVar3[1] = 0;
    DC_SomeClean(puVar3,8);
    puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  Sound_UnlockMutex();
  return;
}


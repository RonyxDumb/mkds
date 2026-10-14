/* Decompiled C draft; module arm9; ROM address 01ff8cc4. No matching claim. */
#include "types.h"
#include "deps/01ff8cc4_func_01ff8cc4.h"

void func_01ff8cc4(int *param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1;
  return;
}


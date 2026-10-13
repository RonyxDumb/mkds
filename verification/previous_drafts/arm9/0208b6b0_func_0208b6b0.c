/* Decompiled C draft; module arm9; ROM address 0208b6b0. No matching claim. */
#include "types.h"
#include "deps/0208b6b0_func_0208b6b0.h"

void func_0208b6b0(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
  *param_1 = 0;
  return;
}


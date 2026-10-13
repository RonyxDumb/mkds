/* Decompiled C draft; module arm9; ROM address 02010a40. No matching claim. */
#include "types.h"
#include "deps/02010a40_func_02010a40.h"

undefined4 func_02010a40(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    return 0;
  }
  if (uVar3 == param_2) {
    uVar1 = uVar3 + 0x10 & 3;
    uVar3 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
    *param_1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    *(undefined4 *)(param_2 + 0x10) = 0;
    return 1;
  }
  uVar1 = uVar3 + 0x10 & 3;
  uVar4 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
  uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if (uVar1 == param_2) break;
    uVar4 = uVar1 + 0x10 & 3;
    uVar2 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
    uVar3 = uVar1;
    uVar1 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  }
  uVar4 = uVar1 + 0x10 & 3;
  uVar2 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
  *(uint *)(uVar3 + 0x10) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  *(undefined4 *)(uVar1 + 0x10) = 0;
  return 1;
}


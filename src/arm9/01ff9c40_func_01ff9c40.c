/* Decompiled C draft; module arm9; ROM address 01ff9c40. No matching claim. */
#include "types.h"
#include "deps/01ff9c40_func_01ff9c40.h"

void func_01ff9c40(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0) {
    return;
  }
  uVar1 = param_1 + 0x2b8U & 3;
  uVar4 = *(uint *)(param_1 + 0x2b8U & 0xfffffffc);
  uVar2 = param_1 + 200U & 3;
  uVar3 = *(uint *)(param_1 + 200U & 0xfffffffc);
  *(uint *)(param_1 + 0x2b8) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 700U & 3;
  uVar4 = *(uint *)(param_1 + 700U & 0xfffffffc);
  uVar2 = param_1 + 0x2b8U & 3;
  uVar3 = *(uint *)(param_1 + 0x2b8U & 0xfffffffc);
  *(uint *)(param_1 + 700) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 700U & 3;
  uVar2 = *(uint *)(param_1 + 700U & 0xfffffffc);
  if (-1 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    return;
  }
  *(undefined4 *)(param_1 + 700) = 0;
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam01ff9c98;
  return;
}


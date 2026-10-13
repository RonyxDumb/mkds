/* Decompiled C draft; module arm9; ROM address 020d8b88. No matching claim. */
#include "types.h"
#include "deps/020d8b88_func_020d8b88.h"

void func_020d8b88(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar6 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = param_1 + 0x14 & 3;
  uVar5 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  func_020d9340((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 0x54 +
                (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20),
                uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,param_2);
  return;
}


/* Decompiled C draft; module arm9; ROM address 020b5fe4. No matching claim. */
#include "types.h"
#include "deps/020b5fe4_func_020b5fe4.h"

void func_020b5fe4(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar8;
  
  uVar6 = *(uint *)(uRam020b6074 & 0xfffffffc) >> (uRam020b6074 & 3) * 8 |
          *(uint *)(uRam020b6074 & 0xfffffffc) << (uRam020b6074 & 3) * -8 + 0x20;
  uVar1 = uVar6 + 0x4c & 3;
  uVar7 = *(uint *)(uVar6 + 0x4c & 0xfffffffc);
  uVar8 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  uVar2 = uVar6 + 0x50 & 3;
  uVar3 = *(uint *)(uVar6 + 0x50 & 0xfffffffc);
  uVar1 = uVar6 + 0x5c & 3;
  uVar5 = *(uint *)(uVar6 + 0x5c & 0xfffffffc);
  uVar7 = uVar6 + 0x60 & 3;
  uVar6 = *(uint *)(uVar6 + 0x60 & 0xfffffffc);
  uVar4 = func_020b57b4((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) - uVar8,
                        uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
                        uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,uVar8,uVar8);
  SomeFxProduct(0x200000,uVar4);
  uVar4 = func_020b5250();
  *param_2 = uVar4;
  uVar5 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = *(uint *)(uRam020b6074 & 0xfffffffc) >> (uRam020b6074 & 3) * 8 |
          *(uint *)(uRam020b6074 & 0xfffffffc) << (uRam020b6074 & 3) * -8 + 0x20;
  uVar1 = uVar7 + 100;
  uVar6 = uVar1 & 3;
  uVar8 = *(uint *)(uVar1 & 0xfffffffc);
  uVar7 = uVar7 + 0x68;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = func_020b57b4((uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) -
                        (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),
                        uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,
                        uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  SomeFxProduct(0x200000,uVar4);
  uVar4 = func_020b5250();
  param_2[1] = uVar4;
  return;
}


/* Decompiled C draft; module arm9; ROM address 020e3b4c. No matching claim. */
#include "types.h"
#include "deps/020e3b4c_func_020e3b4c.h"

void func_020e3b4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 4U & 3;
  uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(int *)(param_1 + 0x4c) = (int)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) >> 4;
  uVar1 = uRam020e3bbc;
  uVar4 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(int *)(param_1 + 0x50) = (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) >> 4;
  uVar4 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(int *)(param_1 + 0x54) = (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) >> 4;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x154U & 3;
  uVar1 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  *(uint *)(uVar2 + 0xc) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 + 0x1c & 3;
  uVar5 = *(uint *)(uVar2 + 0x1c & 0xfffffffc);
  uVar1 = uVar2 + 0xc & 3;
  uVar3 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + (uint)*(ushort *)(uVar2 + 0x1a) * 4;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) =
       uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar4 = param_1 + 0x140U & 3;
  uVar1 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  func_020ea8a8(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20,param_1 + 0x28,param_1 + 0x1c,
                param_3);
  return;
}


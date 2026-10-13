/* Decompiled C draft; module arm9; ROM address 020e00f8. No matching claim. */
#include "types.h"
#include "deps/020e00f8_func_020e00f8.h"

void func_020e00f8(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = param_1 + 0x168U & 3;
  uVar5 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  *(uint *)(param_1 + 0x148) = uVar6;
  uVar2 = param_1 + 0x144U & 3;
  uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  uVar4 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x150U & 3;
  uVar3 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0x54 +
          (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x34;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0x154) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}


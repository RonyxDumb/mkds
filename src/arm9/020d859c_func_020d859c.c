/* Decompiled C draft; module arm9; ROM address 020d859c. No matching claim. */
#include "types.h"
#include "deps/020d859c_func_020d859c.h"

void func_020d859c(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  func_020d90a8();
  uVar4 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  iVar3 = (int)*(short *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0xe);
  if (iVar3 == 0) {
    uVar4 = param_1 + 0x28 & 3;
    uVar2 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  }
  else {
    uVar4 = param_1 + 0x24 & 3;
    uVar2 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
    uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * iVar3;
  }
  *(uint *)(param_1 + 0x2c) = uVar4;
  uVar4 = param_1 + 0x2c & 3;
  uVar2 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  *(uint *)(param_1 + 0x30) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x20 & 3;
  uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  iVar3 = (int)*(short *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0xe);
  if (iVar3 == 0) {
    uVar4 = param_1 + 0x28 & 3;
    uVar2 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  }
  else {
    uVar4 = param_1 + 0x24 & 3;
    uVar2 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
    uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * iVar3;
  }
  *(uint *)(param_1 + 0x34) = uVar4;
  uVar4 = param_1 + 0x30 & 3;
  uVar2 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  uVar7 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  *(uint *)(param_1 + 4) = uVar7;
  uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar4 = param_1 + 0xc & 3;
  uVar5 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * 0x54 +
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0x34;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  lVar1 = (longlong)(int)uVar7 * (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}


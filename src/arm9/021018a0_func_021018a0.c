/* Decompiled C draft; module arm9; ROM address 021018a0. No matching claim. */
#include "types.h"
#include "deps/021018a0_func_021018a0.h"

void func_021018a0(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar4;
  
  uVar2 = GetDriverEntry(*(ushort *)(param_1 + 0x78) & 0xff);
  *(undefined4 *)(param_1 + 0x168) = uVar2;
  uVar4 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar2 = *(undefined4 *)(uVar4 + 0x9c);
  uVar5 = *(undefined4 *)(uVar4 + 0xa0);
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(uVar4 + 0x98);
  *(undefined4 *)(param_1 + 0x188) = uVar2;
  *(undefined4 *)(param_1 + 0x18c) = uVar5;
  uVar4 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar2 = *(undefined4 *)(uVar4 + 0xa8);
  uVar5 = *(undefined4 *)(uVar4 + 0xac);
  *(undefined4 *)(param_1 + 400) = *(undefined4 *)(uVar4 + 0xa4);
  *(undefined4 *)(param_1 + 0x194) = uVar2;
  *(undefined4 *)(param_1 + 0x198) = uVar5;
  uVar4 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 + 0x2cc;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar3 = uVar3 + 0xc4;
  uVar4 = uVar3 & 3;
  uVar6 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x800;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(uint *)(param_1 + 0x170) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined2 *)(param_1 + 0xd8) = 0x1f;
  uVar4 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x48;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) != 0) {
    *(int *)(param_1 + 0xd0) = param_1 + 0xc4;
  }
  return;
}


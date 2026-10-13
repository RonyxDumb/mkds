/* Decompiled C draft; module arm9; ROM address 01ffca50. No matching claim. */
#include "types.h"
#include "deps/01ffca50_func_01ffca50.h"

void func_01ffca50(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0xffffffe7;
  uVar6 = param_1 + 0x2ccU & 3;
  uVar2 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar4 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x394U & 3;
  uVar3 = *(uint *)(param_1 + 0x394U & 0xfffffffc);
  uVar2 = uVar4 & 3;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = param_1 + 0x4c8U & 3;
  uVar7 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  lVar1 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) *
          (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  *(uint *)(param_1 + 0x1d0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x2ccU & 3;
  uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar2 = param_1 + 0xc4U & 3;
  uVar3 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 4;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x1d4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x3ec) = 0;
  return;
}


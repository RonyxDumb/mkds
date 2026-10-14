/* Decompiled C draft; module arm9; ROM address 01ff96cc. No matching claim. */
#include "types.h"
#include "deps/01ff96cc_func_01ff96cc.h"

void func_01ff96cc(uint *param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_2 + 0x18U & 3;
  uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  *param_1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x1cU & 3;
  uVar3 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  param_1[5] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  param_1[1] = 0;
  uVar1 = param_2 + 0x18U & 3;
  uVar5 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar3 = param_2 + 0x24U & 3;
  uVar4 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  param_1[0xc] = (uint)*(ushort *)(param_2 + 0x2c) *
                 -((uint)lVar2 >> 8 | (int)((ulonglong)lVar2 >> 0x20) << 0x18);
  uVar1 = param_2 + 0x1cU & 3;
  uVar3 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x28U & 3;
  uVar4 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
  lVar2 = (longlong)(int)uVar3 * (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  param_1[0xd] = (uint)*(ushort *)(param_2 + 0x2e) *
                 ((uint)lVar2 >> 8 | (int)((ulonglong)lVar2 >> 0x20) << 0x18) +
                 (uint)*(ushort *)(param_2 + 0x2e) * (uVar3 * -2 + 0x2000) * 8;
  param_1[4] = 0;
  return;
}


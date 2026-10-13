/* Decompiled C draft; module arm9; ROM address 020d8a5c. No matching claim. */
#include "types.h"
#include "deps/020d8a5c_func_020d8a5c.h"

void func_020d8a5c(uint param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  iVar3 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) * 0x54;
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar6 = param_1 + 0x14 & 3;
  uVar4 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar2 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  iVar8 = 0x1000000 - uVar2;
  uVar6 = uVar5 + iVar3;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  iVar3 = uVar5 + iVar3;
  lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * (longlong)iVar8;
  *param_2 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar6 = iVar3 + 4U & 3;
  uVar4 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) * (longlong)iVar8;
  param_2[1] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar6 = iVar3 + 8U & 3;
  uVar4 = *(uint *)(iVar3 + 8U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) * (longlong)iVar8;
  param_2[2] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar6 = iVar3 + 0x24U & 3;
  uVar4 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) * (longlong)(int)uVar2;
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) +
             ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  uVar6 = iVar3 + 0x28U & 3;
  uVar5 = *(uint *)(iVar3 + 0x28U & 0xfffffffc);
  uVar4 = (uint)(param_2 + 1) & 3;
  uVar7 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * (longlong)(int)uVar2;
  param_2[1] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
               ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  uVar6 = iVar3 + 0x2cU & 3;
  uVar5 = *(uint *)(iVar3 + 0x2cU & 0xfffffffc);
  uVar4 = (uint)(param_2 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * (longlong)(int)uVar2;
  param_2[2] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
               ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  return;
}


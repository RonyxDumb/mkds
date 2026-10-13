/* Decompiled C draft; module arm9; ROM address 01ff9598. No matching claim. */
#include "types.h"
#include "deps/01ff9598_func_01ff9598.h"

void func_01ff9598(uint *param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar8;
  
  iVar5 = (uint)*(ushort *)(param_2 + 0x2c) << 0xc;
  iVar1 = (uint)*(ushort *)(param_2 + 0x2e) << 0xc;
  FX_DivAsync(iVar1,iVar5);
  uVar8 = param_2 + 0x18U & 3;
  uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = param_2 + 0x1cU & 3;
  uVar7 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar6 * (longlong)(int)*(short *)(param_2 + 0x22);
  uVar10 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  lVar2 = (longlong)(int)uVar6 * (longlong)(int)*(short *)(param_2 + 0x20);
  uVar11 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  lVar2 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(param_2 + 0x20);
  lVar3 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(param_2 + 0x22);
  uVar9 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar7 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  *param_1 = uVar10;
  param_1[5] = uVar7;
  iVar4 = FX_GetDivResult();
  param_1[1] = (int)(-uVar9 * iVar4) >> 0xc;
  FX_DivAsync(iVar5,iVar1);
  uVar8 = param_2 + 0x18U & 3;
  uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  param_1[0xc] = (uint)*(ushort *)(param_2 + 0x2c) *
                 ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) - (uVar11 + uVar10)) * 8;
  uVar8 = param_2 + 0x1cU & 3;
  uVar6 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  param_1[0xd] = (uint)*(ushort *)(param_2 + 0x2e) *
                 (((uVar9 - uVar7) - (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20)) + 0x2000) *
                 8;
  iVar5 = FX_GetDivResult();
  param_1[4] = (int)(uVar11 * iVar5) >> 0xc;
  return;
}


/* Decompiled C draft; module arm9; ROM address 020ee284. No matching claim. */
#include "types.h"
#include "deps/020ee284_func_020ee284.h"

bool func_020ee284(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  
  uVar1 = param_1 + 0x54U & 3;
  uVar11 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  uVar9 = param_2 + 4 & 3;
  uVar8 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar6 = param_1 + 0xe0U & 3;
  uVar10 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  iVar12 = (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) -
           (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
  uVar1 = param_1 + 0x50U & 3;
  uVar9 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
  param_3 = param_3 + (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20);
  iVar5 = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) -
          (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar1 = param_1 + 0x58U & 3;
  uVar8 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar9 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar3 = (longlong)param_3 * (longlong)param_3;
  iVar4 = (int)((ulonglong)lVar3 >> 0x20);
  iVar7 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
          (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
  lVar2 = (longlong)iVar7 * (longlong)iVar7 +
          (longlong)iVar5 * (longlong)iVar5 + (longlong)iVar12 * (longlong)iVar12;
  iVar5 = (int)((ulonglong)lVar2 >> 0x20);
  bVar13 = (uint)lVar2 < (uint)lVar3;
  return (int)(iVar5 - (iVar4 + (uint)bVar13)) < 0 !=
         (SBORROW4(iVar5,iVar4) != SBORROW4(iVar5 - iVar4,(uint)bVar13));
}


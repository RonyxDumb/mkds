/* Decompiled C draft; module arm9; ROM address 020f97e0. No matching claim. */
#include "types.h"
#include "deps/020f97e0_func_020f97e0.h"

bool func_020f97e0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  if (*(short *)(param_1 + 0xda) != -1) {
    if ((*(ushort *)(param_1 + 0x78) & 0x4000) == 0) {
      uVar5 = 8;
    }
    else {
      uVar5 = *(ushort *)(param_1 + 0x78) & 0xff;
    }
    if (*(ushort *)(param_2 + 0x74) != uVar5) {
      uVar1 = param_1 + 0x54U & 3;
      uVar7 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      uVar13 = param_2 + 0x1dcU & 3;
      uVar6 = *(uint *)(param_2 + 0x1dcU & 0xfffffffc);
      uVar2 = param_1 + 0x50U & 3;
      uVar12 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
      iVar9 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) -
              (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20);
      uVar1 = param_2 + 0x1d8U & 3;
      uVar7 = *(uint *)(param_2 + 0x1d8U & 0xfffffffc);
      uVar13 = param_2 + 0x1d0U & 3;
      uVar6 = *(uint *)(param_2 + 0x1d0U & 0xfffffffc);
      iVar10 = (uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20) -
               (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
      uVar1 = param_1 + 0xe0U & 3;
      uVar12 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
      uVar2 = param_2 + 0x1e0U & 3;
      uVar7 = *(uint *)(param_2 + 0x1e0U & 0xfffffffc);
      iVar8 = (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
              (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20);
      uVar1 = param_1 + 0x58U & 3;
      uVar13 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
      lVar4 = (longlong)iVar8 * (longlong)iVar8;
      iVar8 = (int)((ulonglong)lVar4 >> 0x20);
      iVar11 = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) -
               (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
      lVar3 = (longlong)iVar11 * (longlong)iVar11 +
              (longlong)iVar10 * (longlong)iVar10 + (longlong)iVar9 * (longlong)iVar9;
      iVar9 = (int)((ulonglong)lVar3 >> 0x20);
      bVar14 = (uint)lVar3 < (uint)lVar4;
      return (int)(iVar9 - (iVar8 + (uint)bVar14)) < 0 !=
             (SBORROW4(iVar9,iVar8) != SBORROW4(iVar9 - iVar8,(uint)bVar14));
    }
  }
  return false;
}


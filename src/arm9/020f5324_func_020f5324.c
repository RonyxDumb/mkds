/* Decompiled C draft; module arm9; ROM address 020f5324. No matching claim. */
#include "types.h"
#include "deps/020f5324_func_020f5324.h"

undefined4 func_020f5324(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  
  iVar5 = GetDriverEntry(param_2);
  uVar1 = param_1 + 0x58U & 3;
  uVar7 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar2 = iVar5 + 0x1e0U & 3;
  uVar6 = *(uint *)(iVar5 + 0x1e0U & 0xfffffffc);
  uVar11 = param_1 + 0xe0U & 3;
  uVar8 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  iVar9 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) -
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  uVar1 = iVar5 + 0x1d0U & 3;
  uVar7 = *(uint *)(iVar5 + 0x1d0U & 0xfffffffc);
  uVar2 = iVar5 + 0x1d8U & 3;
  uVar6 = *(uint *)(iVar5 + 0x1d8U & 0xfffffffc);
  iVar5 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) +
          ((int)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) * 3) >> 1);
  uVar1 = param_1 + 0x50U & 3;
  uVar11 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
  lVar4 = (longlong)iVar5 * (longlong)iVar5;
  iVar5 = (int)((ulonglong)lVar4 >> 0x20);
  iVar10 = (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) -
           (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  lVar3 = (longlong)iVar10 * (longlong)iVar10 + (longlong)iVar9 * (longlong)iVar9;
  iVar9 = (int)((ulonglong)lVar3 >> 0x20);
  bVar12 = (uint)lVar3 < (uint)lVar4;
  if ((int)(iVar9 - (iVar5 + (uint)bVar12)) < 0 !=
      (SBORROW4(iVar9,iVar5) != SBORROW4(iVar9 - iVar5,(uint)bVar12))) {
    return 1;
  }
  if (*(short *)(param_1 + 0xda) != -1) {
    func_020f9c40(param_1);
    *(undefined2 *)(param_1 + 0x24c) = 5;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    func_020f112c(param_1,param_2);
    return 0;
  }
  return 1;
}


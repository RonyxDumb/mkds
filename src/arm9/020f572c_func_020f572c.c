/* Decompiled C draft; module arm9; ROM address 020f572c. No matching claim. */
#include "types.h"
#include "deps/020f572c_func_020f572c.h"

void func_020f572c(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  
  uVar9 = param_1 + 0x228U & 3;
  uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar9 = (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + 0x1fc;
  uVar3 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
  iVar4 = StructMQRacerEntry_SomeFn_86(uVar9);
  if (iVar4 == 0) {
    func_020f14a0(param_1,0x10000,uRam020f5818,0);
  }
  else {
    func_020f6f10(param_1,0,8);
  }
  uVar3 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 1) == 0) {
    uVar3 = param_1 + 0xd4U & 3;
    uVar5 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210ddf4(uRam020f581c,(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x3fffffe0,
                  uRam020f5820,param_1);
  }
  uVar3 = param_1 + 0x240U & 3;
  uVar5 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  if ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) < 0x15) {
    uVar3 = param_1 + 0x58U & 3;
    uVar7 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar5 = uVar9 + 0x1e0 & 3;
    uVar6 = *(uint *)(uVar9 + 0x1e0 & 0xfffffffc);
    uVar11 = param_1 + 0xe0U & 3;
    uVar8 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    iVar4 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
            (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar3 = uVar9 + 0x1d0 & 3;
    uVar5 = *(uint *)(uVar9 + 0x1d0 & 0xfffffffc);
    iVar12 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
             ((int)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) * 3) >> 1);
    uVar3 = param_1 + 0x50U & 3;
    uVar11 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
    uVar5 = uVar9 + 0x1d8 & 3;
    uVar9 = *(uint *)(uVar9 + 0x1d8 & 0xfffffffc);
    lVar2 = (longlong)iVar12 * (longlong)iVar12;
    iVar12 = (int)((ulonglong)lVar2 >> 0x20);
    iVar10 = (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) -
             (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
    lVar1 = (longlong)iVar10 * (longlong)iVar10 + (longlong)iVar4 * (longlong)iVar4;
    iVar4 = (int)((ulonglong)lVar1 >> 0x20);
    bVar13 = (uint)lVar1 < (uint)lVar2;
    if ((int)(iVar4 - (iVar12 + (uint)bVar13)) < 0 ==
        (SBORROW4(iVar4,iVar12) != SBORROW4(iVar4 - iVar12,(uint)bVar13))) {
      return;
    }
  }
  func_020f6f10(param_1,0,8);
  return;
}


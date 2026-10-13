/* Decompiled C draft; module arm9; ROM address 020651fc. No matching claim. */
#include "types.h"
#include "deps/020651fc_DriverContext_MaybeHandleKill.h"

void DriverContext_MaybeHandleKill(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar8;
  
  uVar8 = param_1 + 0x7cU & 3;
  uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if ((uVar8 & 0xa0) == 0) {
    uVar8 = param_1 + 0x514U & 3;
    uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar3 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    func_01ffcd84(param_1 + 0x120,param_1 + 0x110);
    StructMQRacerEntry_SomeFn_78(param_1);
    uVar8 = param_1 + 0x2a8U & 3;
    uVar7 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    if (0x3000 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
      uVar6 = puRam020653c8[1];
      uVar9 = puRam020653c8[2];
      *(undefined4 *)(uVar3 + 0xa8) = *puRam020653c8;
      *(undefined4 *)(uVar3 + 0xac) = uVar6;
      *(undefined4 *)(uVar3 + 0xb0) = uVar9;
    }
    func_01ffca50(param_1);
    func_01ffbe70(param_1);
    func_01ffbe04(param_1);
    func_01ffbd9c(param_1);
    func_01ffc6c0(param_1);
    func_01ff9d18(param_1);
    uVar8 = param_1 + 0x514U & 3;
    uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar10 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 200U & 3;
    uVar3 = *(uint *)(param_1 + 200U & 0xfffffffc);
    uVar7 = uVar10 + 100 & 3;
    uVar5 = *(uint *)(uVar10 + 100 & 0xfffffffc);
    *(uint *)(uVar10 + 100) =
         (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) +
         (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
    uVar8 = uVar10 + 0x60 & 3;
    uVar5 = *(uint *)(uVar10 + 0x60 & 0xfffffffc);
    uVar7 = uVar10 + 100 & 3;
    uVar3 = *(uint *)(uVar10 + 100 & 0xfffffffc);
    *(uint *)(uVar10 + 0x60) =
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) +
         (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
    uVar8 = uVar10 + 0x60 & 3;
    uVar7 = *(uint *)(uVar10 + 0x60 & 0xfffffffc);
    if ((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) < 0) {
      *(undefined4 *)(uVar10 + 0x60) = 0;
      *(undefined4 *)(uVar10 + 100) = 0;
    }
    iVar4 = IsAwardOrStaffRoll();
    if (iVar4 == 1) {
      *(undefined4 *)(param_1 + 0x230) = uRam020653cc;
    }
    uVar8 = param_1 + 0x514U & 3;
    uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x44;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if (((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x260) = 0;
    }
    func_01ffb130(param_1);
    return;
  }
  if ((uVar8 & 0x20) == 0) {
    *(short *)(param_1 + 0x3c8) = *(short *)(param_1 + 0x3c8) + 1;
    iVar2 = iRam020653c4;
    iVar4 = iRam020653c0;
    iVar11 = (int)*(short *)(param_1 + 0x3c8);
    if (iVar11 < 0x19) {
      uVar8 = iRam020653bc + iVar11 * 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(param_1 + 0x41c) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iVar4 + iVar11 * 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(param_1 + 0x420) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iVar2 + iVar11 * 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(param_1 + 0x424) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = param_1 + 0x428U & 3;
      uVar5 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
      uVar7 = param_1 + 0x41cU & 3;
      uVar3 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x42cU & 3;
      uVar5 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
      uVar7 = param_1 + 0x420U & 3;
      uVar3 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x430U & 3;
      uVar5 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
      uVar7 = param_1 + 0x424U & 3;
      uVar3 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x434U & 3;
      uVar5 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
      uVar7 = param_1 + 0xc0U & 3;
      uVar3 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      return;
    }
    uVar8 = param_1 + 0x7cU & 3;
    uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 0xffffff7f;
    return;
  }
  StructMQRacerEntry_SomeFn_53();
  return;
}


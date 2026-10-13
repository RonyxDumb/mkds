/* Decompiled C draft; module arm9; ROM address 0206a354. No matching claim. */
#include "types.h"
#include "deps/0206a354_StructMQRacerEntry_SomeFn_82.h"

void StructMQRacerEntry_SomeFn_82(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = param_1 + iRam0206a60c;
  if (0 < *(short *)(iVar9 + 2)) {
    *(short *)(iVar9 + 2) = *(short *)(iVar9 + 2) + -1;
    uVar8 = param_1 + 0x42cU & 3;
    uVar5 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    if (0x800 < (int)uVar8) {
      if ((int)uVar8 < 0x800) {
        iVar9 = uVar8 + 0x29;
        if (0x800 < iVar9) {
          iVar9 = 0x800;
        }
      }
      else {
        iVar9 = uVar8 - 0x29;
        if (iVar9 < 0x801) {
          iVar9 = 0x800;
        }
      }
      *(int *)(param_1 + 0x42c) = iVar9;
      uVar8 = param_1 + 0x42cU & 3;
      uVar5 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
      *(uint *)(param_1 + 0x430) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 0x430U & 3;
      uVar5 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
      *(uint *)(param_1 + 0x428) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 0x428U & 3;
      uVar7 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
      uVar5 = param_1 + 0x41cU & 3;
      uVar6 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x42cU & 3;
      uVar7 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
      uVar5 = param_1 + 0x420U & 3;
      uVar6 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x430U & 3;
      uVar7 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
      uVar5 = param_1 + 0x424U & 3;
      uVar6 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar8 = param_1 + 0x434U & 3;
      uVar7 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
      uVar5 = param_1 + 0xc0U & 3;
      uVar6 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
              (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    }
    func_0210fa3c();
    return;
  }
  if (*(short *)(iVar9 + 4) == 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xed,0x7f,0);
  }
  *(short *)(iVar9 + 4) = *(short *)(iVar9 + 4) + 1;
  iVar2 = iRam0206a618;
  if (*(short *)(iVar9 + 4) < 0x19) {
    uVar8 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20 | 0x100;
    iVar4 = iRam0206a620;
    iVar3 = iRam0206a61c;
    uVar8 = iVar2 + *(short *)(iVar9 + 4) * 4;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x41c) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    uVar8 = iVar3 + *(short *)(iVar9 + 4) * 4;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x420) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    uVar8 = iVar4 + *(short *)(iVar9 + 4) * 4;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x424) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x428) = 0x1000;
    *(undefined4 *)(param_1 + 0x42c) = 0x1000;
    *(undefined4 *)(param_1 + 0x430) = 0x1000;
    uVar8 = param_1 + 0x428U & 3;
    uVar7 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
    uVar5 = param_1 + 0x41cU & 3;
    uVar6 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x42cU & 3;
    uVar7 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar5 = param_1 + 0x420U & 3;
    uVar6 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x430U & 3;
    uVar7 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
    uVar5 = param_1 + 0x424U & 3;
    uVar6 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x434U & 3;
    uVar7 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar5 = param_1 + 0xc0U & 3;
    uVar6 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  *(undefined4 *)(param_1 + 0x428) = 0x1000;
  *(undefined4 *)(param_1 + 0x42c) = 0x1000;
  *(undefined4 *)(param_1 + 0x430) = 0x1000;
  *(undefined4 *)(param_1 + 0x41c) = 0x1000;
  *(undefined4 *)(param_1 + 0x420) = 0x1000;
  *(undefined4 *)(param_1 + 0x424) = 0x1000;
  uVar8 = param_1 + 0x428U & 3;
  uVar7 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
  uVar5 = param_1 + 0x41cU & 3;
  uVar6 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_1 + 0x42cU & 3;
  uVar7 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
  uVar5 = param_1 + 0x420U & 3;
  uVar6 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_1 + 0x430U & 3;
  uVar7 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
  uVar5 = param_1 + 0x424U & 3;
  uVar6 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_1 + 0x434U & 3;
  uVar7 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
  uVar5 = param_1 + 0xc0U & 3;
  uVar6 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = uRam0206a610;
  if (*(short *)(iVar9 + 4) < 0x1a) {
    uVar8 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20 | 0x100;
    return;
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xffffff7f;
  uVar5 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & uVar8) == 0) {
    *(undefined4 *)(param_1 + 0x394) = 0x1000;
  }
  if ((uint)*(ushort *)(param_1 + 0x74) ==
      (int)*(char *)((*(uint *)(uRam0206a614 & 0xfffffffc) >> (uRam0206a614 & 3) * 8 |
                     *(uint *)(uRam0206a614 & 0xfffffffc) << (uRam0206a614 & 3) * -8 + 0x20) + 0x62)
     ) {
    func_0210fa74(0);
  }
  func_0210a664(param_1);
  return;
}


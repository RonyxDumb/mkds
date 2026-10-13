/* Decompiled C draft; module arm9; ROM address 02069f6c. No matching claim. */
#include "types.h"
#include "deps/02069f6c_StructMQRacerEntry_SomeFn_81.h"

void StructMQRacerEntry_SomeFn_81(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  iVar10 = param_1 + iRam0206a22c;
  if (0 < *(short *)(iVar10 + 0xe)) {
    *(short *)(iVar10 + 0xe) = *(short *)(iVar10 + 0xe) + -1;
    if ((*(short *)(iVar10 + 0xe) == iRam0206a240) &&
       (uVar9 = param_1 + 0x48U & 3, uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       *(uint *)(param_1 + 0x48) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 0xfbffffff,
       uVar9 = param_1 + 0x7cU & 3, uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
       ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 1) != 0)) {
      func_02074854();
    }
    uVar9 = param_1 + 0x48U & 3;
    uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 0x4000000) != 0) {
      *(undefined4 *)(param_1 + 0x2a8) = 0;
    }
    uVar9 = param_1 + 0x434U & 3;
    uVar5 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar6 = FUN_02132440(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
    iVar10 = FUN_02131860(uVar6,uRam0206a244);
    if (iVar10 != 0) {
      uVar9 = param_1 + 0x434U & 3;
      uVar5 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
      *(uint *)(param_1 + 0x434) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) - iRam0206a248;
      uVar9 = param_1 + 0x434U & 3;
      uVar5 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
      uVar6 = FUN_02132440(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
      iVar10 = FUN_021317b0(uVar6,uRam0206a244);
      if (iVar10 != 0) {
        *(int *)(param_1 + 0x434) = iRam0206a248;
      }
    }
    uVar9 = param_1 + 0x428U & 3;
    uVar8 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
    uVar5 = param_1 + 0x41cU & 3;
    uVar7 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x42cU & 3;
    uVar8 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar5 = param_1 + 0x420U & 3;
    uVar7 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x430U & 3;
    uVar8 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
    uVar5 = param_1 + 0x424U & 3;
    uVar7 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x434U & 3;
    uVar8 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar5 = param_1 + 0xc0U & 3;
    uVar7 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  if (*(short *)(iVar10 + 0xc) == 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xed,0x7f,0);
  }
  *(short *)(iVar10 + 0xc) = *(short *)(iVar10 + 0xc) + 1;
  if (*(short *)(iVar10 + 0xc) < 0x19) {
    *(undefined4 *)(param_1 + 0x398) = 0x1000;
    iVar2 = iRam0206a234;
    uVar9 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20 | 0x100;
    iVar4 = iRam0206a23c;
    iVar3 = iRam0206a238;
    uVar9 = iVar2 + *(short *)(iVar10 + 0xc) * 4;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x41c) = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    uVar9 = iVar3 + *(short *)(iVar10 + 0xc) * 4;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x420) = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    uVar9 = iVar4 + *(short *)(iVar10 + 0xc) * 4;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x424) = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x434) = 0x1000;
    uVar9 = param_1 + 0x428U & 3;
    uVar8 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
    uVar5 = param_1 + 0x41cU & 3;
    uVar7 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x42cU & 3;
    uVar8 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar5 = param_1 + 0x420U & 3;
    uVar7 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x430U & 3;
    uVar8 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
    uVar5 = param_1 + 0x424U & 3;
    uVar7 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x434U & 3;
    uVar8 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar5 = param_1 + 0xc0U & 3;
    uVar7 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  *(undefined4 *)(param_1 + 0x398) = 0x1000;
  *(undefined4 *)(param_1 + 0x434) = 0x1000;
  *(undefined4 *)(param_1 + 0x41c) = 0x1000;
  *(undefined4 *)(param_1 + 0x420) = 0x1000;
  *(undefined4 *)(param_1 + 0x424) = 0x1000;
  uVar9 = param_1 + 0x428U & 3;
  uVar8 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
  uVar5 = param_1 + 0x41cU & 3;
  uVar7 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = param_1 + 0x42cU & 3;
  uVar8 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
  uVar5 = param_1 + 0x420U & 3;
  uVar7 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = param_1 + 0x430U & 3;
  uVar8 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
  uVar5 = param_1 + 0x424U & 3;
  uVar7 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = param_1 + 0x434U & 3;
  uVar8 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
  uVar5 = param_1 + 0xc0U & 3;
  uVar7 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = uRam0206a230;
  if (*(short *)(iVar10 + 0xc) < 0x1a) {
    uVar9 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20 | 0x100;
    return;
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 0xfffeffff;
  uVar5 = param_1 + 0x4cU & 3;
  uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & uVar9) == 0) {
    *(undefined4 *)(param_1 + 0x394) = 0x1000;
  }
  return;
}


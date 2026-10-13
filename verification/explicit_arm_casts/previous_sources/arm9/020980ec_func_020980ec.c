/* Decompiled C draft; module arm9; ROM address 020980ec. No matching claim. */
#include "types.h"
#include "deps/020980ec_func_020980ec.h"

undefined1 func_020980ec(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  int iVar11;
  int iVar12;
  undefined1 auStack_20 [16];
  uint uVar9;
  
  uVar9 = param_1 + 0xeccU & 3;
  uVar8 = *(uint *)(param_1 + 0xeccU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  uVar4 = *param_4;
  bVar10 = false;
  bVar2 = true;
  if ((uVar9 != 2) && (uVar9 != 5)) {
    bVar2 = false;
  }
  if ((bVar2) &&
     (uVar8 = param_1 + 0xa0U & 3, uVar7 = *(uint *)(param_1 + 0xa0U & 0xfffffffc),
     0 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20))) {
    bVar10 = true;
  }
  iVar11 = iRam02098258;
  if ((!bVar10) &&
     (((uVar9 != 3 && (uVar9 != 6)) ||
      (uVar9 = param_1 + 0xa0U & 3, uVar8 = *(uint *)(param_1 + 0xa0U & 0xfffffffc),
      iVar11 = iRam0209825c, -1 < (int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20))))) {
    iVar11 = 0;
  }
  if (iVar11 != 0) {
    uVar9 = param_1 + (uint)*(ushort *)(param_2 + 0x74) * 4 + 0xed4;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (uVar9 >> uVar8 * 8 == 0 && uVar9 << uVar8 * -8 + 0x20 == 0) {
      VecFx32_Subtract(param_2 + 0x80,param_1 + 4,auStack_20);
      iVar5 = VecFx32_Norm(auStack_20);
      uVar9 = param_1 + 0xec0U & 3;
      uVar8 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
      iVar12 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * 0x30;
      uVar9 = param_1 + 0xc0 + iVar12;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar6 = (uint)((longlong)iVar5 * (longlong)iVar11) >> 0xc |
              (int)((ulonglong)((longlong)iVar5 * (longlong)iVar11) >> 0x20) << 0x14;
      lVar1 = (longlong)(int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) *
              (longlong)(int)uVar6;
      iVar12 = param_1 + 0xc0 + iVar12;
      *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar7 = uRam02098260;
      uVar9 = iVar12 + 4;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar3 = uRam02098264;
      uVar9 = iVar12 + 8;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) *
              (longlong)(int)uVar6;
      *(uint *)(param_1 + 0x18) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar9 = param_1 + 0x78U & 3;
      uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20 |
           uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      func_020d26ec(param_2,uVar3);
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    uVar9 = param_1 + 0xec8U & 3;
    uVar8 = *(uint *)(param_1 + 0xec8U & 0xfffffffc);
    if (uVar8 >> uVar9 * 8 == 0 && uVar8 << uVar9 * -8 + 0x20 == 0) {
      uVar4 = 0xc;
    }
    else {
      uVar4 = 0xe;
    }
    return uVar4;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return uVar4;
}


/* Decompiled C draft; module arm9; ROM address 02024a88. No matching claim. */
#include "types.h"
#include "deps/02024a88_func_02024a88.h"

void func_02024a88(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  int unaff_r5;
  uint *puVar10;
  bool bVar11;
  uint uVar7;
  
  uVar7 = param_1 + 0x48U & 3;
  uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  puVar10 = (uint *)(param_1 + 0x450);
  uVar6 = (uint)((uVar7 & 2) != 0);
  bVar11 = (uVar7 & 4) != 0;
  if (bVar11) {
    unaff_r5 = 1;
  }
  uVar7 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (!bVar11) {
    unaff_r5 = 0;
  }
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x10000000) != 0) {
    *(undefined4 *)(param_1 + 0x458) = 0x6c0000;
    *(undefined4 *)(param_1 + 0x45c) = 0x6c0000;
    *(undefined4 *)(param_1 + 0x460) = 0;
    if (uVar6 == 0) {
      uVar7 = param_1 + 0x4a0U & 3;
      uVar2 = *(uint *)(param_1 + 0x4a0U & 0xfffffffc);
      *puVar10 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    }
    else {
      uVar7 = param_1 + 0x4b0U & 3;
      uVar2 = *(uint *)(param_1 + 0x4b0U & 0xfffffffc);
      *puVar10 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    }
    *(uint *)(param_1 + 0x464) = uVar6;
    *(undefined1 *)(param_1 + 0x454) = 0x46;
    func_02109078(param_1,0xfc,0x7f,0);
    return;
  }
  iVar3 = GetSomeTimeOrDuration();
  if (iVar3 < 5) {
    return;
  }
  uVar7 = iRam02024ec0 + 0xcU & 3;
  uVar2 = *(uint *)(iRam02024ec0 + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar7 * 8 == 0 && uVar2 << uVar7 * -8 + 0x20 == 0) {
    uVar7 = param_1 + 0x4d4U & 3;
    uVar2 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    if (((int)uVar7 < 0xce) ||
       (uVar2 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 +
                (*(uint *)(uRam02024ec4 & 0xfffffffc) >> (uRam02024ec4 & 3) * 8 |
                *(uint *)(uRam02024ec4 & 0xfffffffc) << (uRam02024ec4 & 3) * -8 + 0x20) + 0x70,
       uVar8 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
       (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) == 1)) {
      *(undefined4 *)(param_1 + 0x45c) = 0;
      *(undefined4 *)(param_1 + 0x460) = 0;
      *(undefined1 *)(param_1 + 0x454) = 0x3c;
      uVar4 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02024ec8,uVar4,uRam02024ed0,param_1);
      uVar4 = 0xffffffff;
    }
    else if (uVar6 == 0) {
      lVar1 = (ulonglong)uVar7 * 0x480000 + 0x800;
      uVar4 = func_02024eec(param_1 + 0x450,
                            (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
      *(undefined1 *)(param_1 + 0x454) = 0x46;
      uVar7 = param_1 + 0x494U & 3;
      uVar2 = *(uint *)(param_1 + 0x494U & 0xfffffffc);
      *puVar10 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      uVar5 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02024ec8,uVar5,uRam02024ecc,param_1);
    }
    else {
      uVar2 = param_1 + 0x4cU & 3;
      uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) & 0x20000000) == 0) {
        lVar1 = (ulonglong)uVar7 * 0x580000 + 0x800;
        uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
      }
      else {
        uVar7 = 0;
      }
      uVar4 = func_02024eec(param_1 + 0x450,uVar7,0);
      *(undefined1 *)(param_1 + 0x454) = 0x7f;
      uVar7 = param_1 + 0x494U & 3;
      uVar2 = *(uint *)(param_1 + 0x494U & 0xfffffffc);
      *puVar10 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      uVar5 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02024ec8,uVar5,uRam02024ecc,param_1);
    }
    *(undefined4 *)(param_1 + 0x458) = uVar4;
    *(uint *)(param_1 + 0x464) = uVar6;
    return;
  }
  uVar7 = param_1 + 0x2ccU & 3;
  uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar2 = param_1 + 0x2a4U & 3;
  uVar9 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  uVar9 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar7 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x10;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar3 = uVar9 - (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  if (((unaff_r5 == 0) ||
      (uVar7 = param_1 + 0x2a8U & 3, uVar2 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc),
      (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) < 1)) ||
     (uVar7 = param_1 + 0x44U & 3, uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x10) == 0)) {
    if ((uVar6 == 0) &&
       ((unaff_r5 == 0 ||
        (uVar7 = param_1 + 0x2a8U & 3, uVar2 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc),
        -1 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20))))) {
      if (iVar3 < 1) {
        uVar7 = param_1 + 0x470U & 3;
        uVar2 = *(uint *)(param_1 + 0x470U & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) *
                (longlong)(int)uVar9 + 0x800;
        uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
      }
      else {
        uVar7 = param_1 + 0x468U & 3;
        uVar2 = *(uint *)(param_1 + 0x468U & 0xfffffffc);
        lVar1 = (longlong)iVar3 * (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) +
                0x800;
        uVar7 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x480000;
      }
      uVar2 = func_02024eec(param_1 + 0x450,uVar7);
      *(undefined1 *)(param_1 + 0x454) = 0x32;
      uVar7 = param_1 + 0x2a0U & 3;
      uVar8 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
      uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      if ((int)uVar7 < iRam02024ee4) {
        uVar7 = param_1 + 0x4a8U & 3;
        uVar8 = *(uint *)(param_1 + 0x4a8U & 0xfffffffc);
        *puVar10 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      else if ((int)uVar7 < iRam02024ee8) {
        uVar7 = param_1 + 0x4a4U & 3;
        uVar8 = *(uint *)(param_1 + 0x4a4U & 0xfffffffc);
        *puVar10 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      else {
        uVar7 = param_1 + 0x4a0U & 3;
        uVar8 = *(uint *)(param_1 + 0x4a0U & 0xfffffffc);
        *puVar10 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      uVar4 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02024ec8,uVar4,uRam02024ee0,param_1);
    }
    else {
      if (iVar3 < 1) {
        uVar7 = param_1 + 0x46cU & 3;
        uVar2 = *(uint *)(param_1 + 0x46cU & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) *
                (longlong)(int)uVar9 + 0x800;
        uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
      }
      else {
        uVar7 = param_1 + 0x468U & 3;
        uVar2 = *(uint *)(param_1 + 0x468U & 0xfffffffc);
        lVar1 = (longlong)iVar3 * (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) +
                0x800;
        uVar7 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x580000;
      }
      uVar2 = func_02024eec(param_1 + 0x450,uVar7);
      *(undefined1 *)(param_1 + 0x454) = 0x7f;
      uVar7 = param_1 + 0x464U & 3;
      uVar8 = *(uint *)(param_1 + 0x464U & 0xfffffffc);
      if (uVar8 >> uVar7 * 8 == 0 && uVar8 << uVar7 * -8 + 0x20 == 0) {
        uVar7 = param_1 + 0x2a0U & 3;
        uVar8 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
        if ((int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) < iRam02024edc) {
          uVar7 = param_1 + 0x4b4U & 3;
          uVar8 = *(uint *)(param_1 + 0x4b4U & 0xfffffffc);
          uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        }
        else {
          uVar7 = param_1 + 0x4b0U & 3;
          uVar8 = *(uint *)(param_1 + 0x4b0U & 0xfffffffc);
          uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        }
        *puVar10 = uVar7;
      }
      uVar4 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02024ec8,uVar4,uRam02024ee0,param_1);
    }
  }
  else {
    uVar7 = param_1 + 0x474U & 3;
    uVar2 = *(uint *)(param_1 + 0x474U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * (longlong)(int)uVar9
            + 0x800;
    uVar7 = param_1 + 0x2a0U & 3;
    uVar8 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    uVar2 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    if (0x280000 < (int)uVar2) {
      uVar2 = 0x280000;
    }
    *(undefined1 *)(param_1 + 0x454) =
         *(undefined1 *)
          (iRam02024ed4 + ((int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) >> 8 & 0xffU));
    uVar4 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
    func_0210ddf4(uRam02024ec8,uVar4,uRam02024ed8,param_1);
  }
  *(uint *)(param_1 + 0x458) = uVar2;
  *(uint *)(param_1 + 0x464) = uVar6;
  return;
}


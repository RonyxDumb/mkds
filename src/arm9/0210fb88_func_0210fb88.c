/* Decompiled C draft; module arm9; ROM address 0210fb88. No matching claim. */
#include "types.h"
#include "deps/0210fb88_func_0210fb88.h"

void func_0210fb88(uint param_1,undefined4 param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_28 [2];
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar12 = 0;
  uVar11 = 0x7f;
  uVar10 = 0xffffffff;
  if (0 < (int)uVar2) {
    if (uVar2 == 1) {
      uVar11 = 0;
    }
    func_02108eb4(1,0x7f);
    func_0212c524(param_2,uRam0211000c,0);
    uVar2 = uRam02110010 + 4 & 3;
    uVar10 = *(uint *)(uRam02110010 + 4 & 0xfffffffc);
    uVar10 = uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20;
    uVar2 = (int)uVar10 >> 0xc;
    if (uVar11 == uVar2) {
      uVar11 = 0xffffffff;
    }
    else {
      if ((int)uVar11 < (int)uVar2) {
        iVar9 = uVar10 - (*(uint *)(uRam02110010 & 0xfffffffc) >> (uRam02110010 & 3) * 8 |
                         *(uint *)(uRam02110010 & 0xfffffffc) << (uRam02110010 & 3) * -8 + 0x20);
        if (iVar9 >> 0xc < (int)uVar11) {
          iVar9 = uVar11 << 0xc;
        }
      }
      else {
        iVar9 = uVar10 + (*(uint *)(uRam02110010 & 0xfffffffc) >> (uRam02110010 & 3) * 8 |
                         *(uint *)(uRam02110010 & 0xfffffffc) << (uRam02110010 & 3) * -8 + 0x20);
        if ((int)uVar11 < iVar9 >> 0xc) {
          iVar9 = uVar11 << 0xc;
        }
      }
      uVar11 = iVar9 >> 0xc;
      *(int *)(uRam02110010 + 4) = iVar9;
      uVar2 = uVar11;
    }
    uVar10 = *(uint *)(uRam02110014 & 0xfffffffc) >> (uRam02110014 & 3) * 8 |
             *(uint *)(uRam02110014 & 0xfffffffc) << (uRam02110014 & 3) * -8 + 0x20;
    *puRam02110018 = uVar2;
    if (((int)uVar2 <= (int)uVar10) && (uVar10 = uVar2, (int)uVar2 < 0)) {
      uVar10 = 0;
    }
    *puRam02110018 = uVar10;
    if (uVar11 != 0xffffffff) {
      func_0212c678(param_2);
      return;
    }
    return;
  }
  if (*(uint *)(uRam0211001c & 0xfffffffc) >> (uRam0211001c & 3) * 8 != 0 ||
      *(uint *)(uRam0211001c & 0xfffffffc) << (uRam0211001c & 3) * -8 + 0x20 != 0) {
    func_02110114(param_2);
    return;
  }
  iVar9 = func_0207a2a8(local_28);
  if ((iVar9 == 0) || (iRam02110020 <= local_28[0])) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  uVar8 = uRam0211000c;
  uVar2 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if (((int)uVar2 >> 2 & 1U) == 0) {
    uVar7 = param_1 + 0xc & 3;
    uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    if (uVar4 >> uVar7 * 8 == 0 && uVar4 << uVar7 * -8 + 0x20 == 0) {
      uVar7 = *(uint *)(uRam02110014 & 0xfffffffc) >> (uRam02110014 & 3) * 8 |
              *(uint *)(uRam02110014 & 0xfffffffc) << (uRam02110014 & 3) * -8 + 0x20;
    }
    else {
      uVar10 = (local_28[0] + iRam02110028) * 0x1000;
      lVar1 = (longlong)
              (int)(*(uint *)(uRam02110024 & 0xfffffffc) >> (uRam02110024 & 3) * 8 |
                   *(uint *)(uRam02110024 & 0xfffffffc) << (uRam02110024 & 3) * -8 + 0x20) *
              (longlong)(int)uVar10 + 0x800;
      uVar11 = ((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc) +
               0x1e;
      if ((int)uVar11 < 0) {
        uVar11 = 0;
      }
      else if (0x7f < (int)uVar11) {
        uVar11 = 0x7f;
      }
      uVar11 = uVar11 & 0xff;
      uVar7 = *(uint *)(uRam0211002c & 0xfffffffc) >> (uRam0211002c & 3) * 8 |
              *(uint *)(uRam0211002c & 0xfffffffc) << (uRam0211002c & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uVar10 * (ulonglong)uVar7;
      uVar4 = (uint)lVar1;
      uVar12 = 0x9d - uVar11 & 0xff;
      uVar7 = ((int)(uVar4 + 0x800 >> 0xc |
                    (uVar7 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
                    (uint)(0xfffff7ff < uVar4)) * 0x100000) >> 0xc) + 0x14;
      uVar10 = 0xfe;
      if ((int)uVar7 < 0) {
        uVar7 = 0;
      }
      else if (0x7f < (int)uVar7) {
        uVar7 = 0x7f;
      }
    }
  }
  else {
    uVar7 = 0;
    uVar11 = 0x1e;
    uVar10 = 0xff;
    uVar12 = 0x7f;
  }
  uVar4 = iRam02110030 + 0xcU & 3;
  uVar5 = *(uint *)(iRam02110030 + 0xcU & 0xfffffffc);
  iVar9 = 0;
  if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 1) {
    if (((int)uVar2 >> 1 & 1U) == 0) {
      if (((int)uVar2 >> 3 & 1U) != 0) {
        iVar9 = 0x40;
        uVar2 = *(uint *)(uRam02110014 & 0xfffffffc) >> (uRam02110014 & 3) * 8 |
                *(uint *)(uRam02110014 & 0xfffffffc) << (uRam02110014 & 3) * -8 + 0x20;
        if (uVar7 == uVar2) {
          uVar7 = uVar2 - 10;
        }
      }
    }
    else {
      uVar2 = param_1 + 4 & 3;
      uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(param_1 + 4) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + iRam02110034;
      iVar9 = iRam02110038;
      uVar2 = param_1 + 4 & 3;
      uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(param_1 + 4) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & uVar8;
      uVar2 = param_1 + 4 & 3;
      uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
      lVar1 = (ulonglong)
              (uint)(int)*(short *)(iVar9 + ((int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20)
                                            >> 4) * 4) * 0x30000 + 0x800;
      iVar9 = ((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc) + 0x80
      ;
      if (0x3c < (int)uVar7) {
        uVar7 = 0x3c;
      }
    }
  }
  func_02108eb4(1,uVar11);
  func_0212c524(param_2,uRam0211000c,iVar9);
  uVar2 = uRam02110010 + 4 & 3;
  uVar11 = *(uint *)(uRam02110010 + 4 & 0xfffffffc);
  uVar11 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
  uVar2 = (int)uVar11 >> 0xc;
  if (uVar7 == uVar2) {
    uVar11 = 0xffffffff;
  }
  else {
    if ((int)uVar7 < (int)uVar2) {
      iVar9 = uVar11 - (*(uint *)(uRam02110010 & 0xfffffffc) >> (uRam02110010 & 3) * 8 |
                       *(uint *)(uRam02110010 & 0xfffffffc) << (uRam02110010 & 3) * -8 + 0x20);
      if (iVar9 >> 0xc < (int)uVar7) {
        iVar9 = uVar7 << 0xc;
      }
    }
    else {
      iVar9 = uVar11 + (*(uint *)(uRam02110010 & 0xfffffffc) >> (uRam02110010 & 3) * 8 |
                       *(uint *)(uRam02110010 & 0xfffffffc) << (uRam02110010 & 3) * -8 + 0x20);
      if ((int)uVar7 < iVar9 >> 0xc) {
        iVar9 = uVar7 << 0xc;
      }
    }
    uVar11 = iVar9 >> 0xc;
    *(int *)(uRam02110010 + 4) = iVar9;
    uVar2 = uVar11;
  }
  uVar8 = *(uint *)(uRam02110014 & 0xfffffffc) >> (uRam02110014 & 3) * 8 |
          *(uint *)(uRam02110014 & 0xfffffffc) << (uRam02110014 & 3) * -8 + 0x20;
  *puRam02110018 = uVar2;
  if (((int)uVar2 <= (int)uVar8) && (uVar8 = uVar2, (int)uVar2 < 0)) {
    uVar8 = 0;
  }
  *puRam02110018 = uVar8;
  if (uVar11 != 0xffffffff) {
    func_0212c678(param_2);
  }
  uVar3 = func_02108e6c(5);
  if ((uVar10 != 0xffffffff) && (uVar12 != 0)) {
    iVar9 = func_02110100();
    if ((iVar9 == 0) || (iVar6 = func_021100dc(uVar3,0,uVar10), iVar6 != 0)) {
      if (iVar9 == 0) {
        func_0211003c(uVar10 & 0xff,uVar3);
      }
    }
    else {
      func_021100d0(uVar3,0);
      func_0211003c(uVar10 & 0xff,uVar3);
    }
    iVar9 = func_02110100(uVar3);
    if (iVar9 != 0) {
      if (0x7f < uVar12) {
        uVar12 = 0x7f;
      }
      func_02105b28(uVar3,uVar12);
      return;
    }
    return;
  }
  iVar9 = func_02110100(uVar3);
  if (iVar9 != 0) {
    func_021100d0(uVar3,0x1e);
    return;
  }
  return;
}


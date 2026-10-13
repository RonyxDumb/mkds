/* Decompiled C draft; module arm9; ROM address 0210689c. No matching claim. */
#include "types.h"
#include "deps/0210689c_func_0210689c.h"

void func_0210689c(uint param_1)

{
  undefined1 uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  bVar3 = false;
  iVar5 = GetCurrentSceneId();
  iVar4 = iRam02106aa0;
  uVar8 = uRam02106a9c;
  if (iVar5 == 2) {
    bVar2 = true;
    uVar6 = (*(uint *)(uRam02106a94 & 0xfffffffc) >> (uRam02106a94 & 3) * 8 |
            *(uint *)(uRam02106a94 & 0xfffffffc) << (uRam02106a94 & 3) * -8 + 0x20) + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    if ((uVar6 != 0) && (uVar6 != 2)) {
      bVar2 = false;
    }
    if (bVar2) {
      bVar3 = true;
    }
  }
  if (!bVar3) {
    return;
  }
  uVar9 = *(uint *)(uRam02106a94 & 0xfffffffc) >> (uRam02106a94 & 3) * 8 |
          *(uint *)(uRam02106a94 & 0xfffffffc) << (uRam02106a94 & 3) * -8 + 0x20;
  uVar6 = uVar9 + 8 & 3;
  uVar7 = *(uint *)(uVar9 + 8 & 0xfffffffc);
  if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) - 1 < 2) {
    return;
  }
  uVar6 = 0xffffffff;
  bVar3 = false;
  uVar1 = (undefined1)param_1;
  if (0xf0 < (*(uint *)(uRam02106a98 & 0xfffffffc) >> (uRam02106a98 & 3) * 8 |
             *(uint *)(uRam02106a98 & 0xfffffffc) << (uRam02106a98 & 3) * -8 + 0x20)) {
    uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    if (uVar7 == 0x21) {
      if (param_1 == 0) {
        uVar6 = uRam02106aa4;
      }
      uVar8 = iRam02106aa0 + 0x1cU & 3;
      uVar7 = *(uint *)(iRam02106aa0 + 0x1cU & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if (param_1 != 0) {
        uVar6 = uRam02106aa8;
      }
      bVar3 = true;
      if (((uVar8 == 0) || (*(short *)(uVar8 + 0x3a) != 0x1cc)) || (*(short *)(uVar8 + 0x38) != 0))
      {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        bVar3 = false;
      }
    }
    else if ((uVar7 == 0x22) &&
            (uVar7 = uRam02106a98 + 0x10 & 3, uVar9 = *(uint *)(uRam02106a98 + 0x10 & 0xfffffffc),
            uVar9 >> uVar7 * 8 != 0 || uVar9 << uVar7 * -8 + 0x20 != 0)) {
      iVar5 = 7;
      do {
        func_0212c6f0(iVar4 + iVar5 * 4,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0xc);
      bVar3 = true;
      uVar6 = uVar8;
    }
    if ((bVar3) && (param_1 < *(byte *)(uRam02106a98 + 0x18))) {
      uVar8 = uRam02106a98 + 0x1c & 3;
      uVar7 = *(uint *)(uRam02106a98 + 0x1c & 0xfffffffc);
      if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 0xffffffff) {
        bVar3 = true;
      }
      else {
        bVar3 = param_1 < *(byte *)(uRam02106a98 + 0x19);
      }
      if (bVar3) {
        func_0212c6f0(uRam02106aac,0);
        uVar8 = uRam02106aac;
        if ((((*(uint *)(uRam02106ab0 & 0xfffffffc) >> (uRam02106ab0 & 3) * 8 |
              *(uint *)(uRam02106ab0 & 0xfffffffc) << (uRam02106ab0 & 3) * -8 + 0x20) & 1) != 0) &&
           (uVar7 = iRam02106ab4 + 0xcU & 3, uVar9 = *(uint *)(iRam02106ab4 + 0xcU & 0xfffffffc),
           uVar9 >> uVar7 * 8 != 0 || uVar9 << uVar7 * -8 + 0x20 != 0)) {
          if (*(uint *)(uRam02106aac & 0xfffffffc) >> (uRam02106aac & 3) * 8 != 0 ||
              *(uint *)(uRam02106aac & 0xfffffffc) << (uRam02106aac & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uRam02106aac,0);
          }
          if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uVar8,0);
          }
          NNSi_MaybeSndPlayerStartSeq(uVar8,0,uVar6 & 0xffff);
        }
        uVar8 = uRam02106a98;
        *(undefined1 *)(uRam02106a98 + 0x19) = uVar1;
        *(undefined4 *)(uVar8 + 0x1c) = 0;
      }
    }
    *(undefined1 *)(uRam02106a98 + 0x18) = uVar1;
    return;
  }
  *(undefined1 *)(uRam02106a98 + 0x18) = uVar1;
  return;
}


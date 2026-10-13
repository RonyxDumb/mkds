/* Decompiled C draft; module arm9; ROM address 020431e4. No matching claim. */
#include "types.h"
#include "deps/020431e4_func_020431e4.h"

void func_020431e4(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar8;
  
  uVar2 = uRam020433fc;
  iVar6 = iRam020433f8;
  iVar12 = 0;
  uVar1 = (undefined2)uRam02043400;
  do {
    iVar11 = iVar12 * 0x5c + iVar6;
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar11));
    StructCY_SomeFn_0(iVar11,uVar2,0x1e,10);
    *(undefined4 *)(iVar11 + 0x3c) = 0;
    *(undefined2 *)(iVar11 + 0x40) = 0;
    *(undefined4 *)(iVar11 + 0x44) = 0;
    *(undefined2 *)(iVar11 + 0x42) = uVar1;
    StructCYB_SomeFn(iVar11 + 0x28);
    StructCYA_SomeFn((undefined2 *)(uintptr_t)(iVar11 + 0x48));
    uVar3 = uRam02043404;
    iVar11 = iRam020433f8;
    iVar12 = iVar12 + 1;
  } while (iVar12 < 10);
  uVar10 = uRam02043404 & 3;
  uVar4 = *(uint *)(uRam02043404 & 0xfffffffc);
  *(undefined4 *)(iRam020433f8 + 0x31c) = 5;
  *(undefined4 *)(iVar11 + 0x378) = 6;
  iVar6 = 0;
  *(undefined4 *)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + 8) = 0;
  uVar10 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + 0xc) = 0;
  uVar2 = uRam020433fc;
  do {
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar11));
    *(undefined2 *)(iVar11 + 0x40) = 0;
    StructCY_SomeFn_0(iVar11,uVar2,0x1e,10);
    iVar12 = iRam020433f8;
    iVar6 = iVar6 + 1;
    iVar11 = iVar11 + 0x5c;
  } while (iVar6 < 10);
  uVar4 = *(uint *)(uRam02043408 & 0xfffffffc) >> (uRam02043408 & 3) * 8 |
          *(uint *)(uRam02043408 & 0xfffffffc) << (uRam02043408 & 3) * -8 + 0x20;
  uVar10 = *(uint *)(uRam0204340c & 0xfffffffc) >> (uRam0204340c & 3) * 8 |
           *(uint *)(uRam0204340c & 0xfffffffc) << (uRam0204340c & 3) * -8 + 0x20;
  uVar3 = 0;
  do {
    iVar6 = uVar3 * 0x30 + uVar4;
    uVar7 = iVar6 + 0x70;
    uVar9 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    uVar7 = iVar6 + 0x7c;
    uVar9 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    bVar5 = false;
    if ((uVar8 < 4) && (bVar5 = false, (1 << (uVar8 & 0xff) & 0xdU) != 0)) {
      bVar5 = true;
    }
    if (bVar5) {
      if (uVar3 == (int)*(char *)(uVar4 + 0x62)) {
        if (uVar10 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                  *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
        }
        bVar5 = false;
        if ((uVar9 != 0) &&
           (uVar9 = uVar10 + 4 & 3, uVar8 = *(uint *)(uVar10 + 4 & 0xfffffffc),
           (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) != 0xd)) {
          bVar5 = true;
        }
        if (bVar5) {
          *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 4;
        }
        else {
          uVar9 = uVar4 + 0xc & 3;
          uVar8 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
          if ((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) == 2) {
            *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 1;
          }
          else {
            *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 2;
          }
        }
      }
      else if (uVar8 == 2) {
        *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 1;
      }
      else {
        uVar9 = uVar4 + 8 & 3;
        uVar8 = *(uint *)(uVar4 + 8 & 0xfffffffc);
        if ((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) == 5) {
          *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 7;
        }
        else {
          *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 4;
        }
      }
    }
    else if (uVar8 == 1) {
      *(undefined4 *)(uVar7 * 0x5c + iVar12 + 0x3c) = 3;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 8);
  return;
}


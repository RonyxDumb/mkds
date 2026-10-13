/* Decompiled C draft; module arm9; ROM address 0208552c. No matching claim. */
#include "types.h"
#include "deps/0208552c_func_0208552c.h"

void func_0208552c(void)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  iVar7 = iRam0208576c;
  uVar11 = uRam02085768;
  uVar8 = uRam02085764;
  iVar10 = 1;
  uVar12 = *(uint *)(uRam02085764 & 0xfffffffc) >> (uRam02085764 & 3) * 8 |
           *(uint *)(uRam02085764 & 0xfffffffc) << (uRam02085764 & 3) * -8 + 0x20;
  uVar9 = 0;
  uVar3 = (uint)*(byte *)(uVar12 + 0x3d0);
  if (uVar3 != 0) {
    do {
      uVar3 = (*(uint *)(uRam02085770 & 0xfffffffc) >> (uRam02085770 & 3) * 8 |
              *(uint *)(uRam02085770 & 0xfffffffc) << (uRam02085770 & 3) * -8 + 0x20) + 0x108;
      uVar12 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar4 = GetSomeRacerValue(uVar9);
      lVar2 = (longlong)iVar4 * (longlong)(int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) +
              0x800;
      uVar3 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      iVar4 = GetDriverPlace(uVar9);
      *(uint *)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + uVar9 * 4) = uVar3;
      if (0 < iVar4) {
        uVar12 = uVar9 * 0x30 +
                 (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                 *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x70;
        uVar6 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        if (((uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) == 1) && (iVar10 < iVar4)) {
          *(uint *)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                    *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x80) = uVar9;
          iVar10 = iVar4;
        }
        *(uint *)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                  *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) +
                  (iVar4 - 1U & 0xffff) * 4 + 0x20) = uVar9;
      }
      if (iVar4 == 1) {
        if ((int)uVar3 < 0) {
          *(undefined4 *)
           ((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
            *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x8c) = 0;
        }
        else {
          uVar3 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                  *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + uVar9 * 4;
          uVar12 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar5 = FX_Div(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20,uRam02085774);
          *(undefined4 *)
           ((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
            *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x8c) = uVar5;
          uVar6 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                  *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
          uVar3 = uVar6 + 0x8c & 3;
          uVar12 = *(uint *)(uVar6 + 0x8c & 0xfffffffc);
          uVar3 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
          if ((int)uVar3 < iVar7) {
            *(int *)(uVar6 + 0x8c) = iVar7;
          }
          else if (0x1000 < (int)uVar3) {
            *(undefined4 *)(uVar6 + 0x8c) = 0x1000;
          }
        }
      }
      uVar12 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
               *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
      uVar3 = (uint)*(byte *)(uVar12 + 0x3d0);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < uVar3);
  }
  uVar8 = uRam02085768;
  uVar9 = uRam02085764;
  iVar10 = 0;
  iVar7 = 0;
  if (uVar3 != 0) {
    do {
      uVar11 = uVar8 & 3;
      uVar3 = *(uint *)(uVar8 & 0xfffffffc);
      uVar6 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
      uVar11 = uVar6 + iVar7 * 4 + 0x20;
      uVar3 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
      if ((-1 < (int)uVar11) &&
         (uVar3 = (uVar11 & 0xffff) * 0x30 + uVar12 + 0x70, uVar12 = uVar3 & 3,
         uVar3 = *(uint *)(uVar3 & 0xfffffffc),
         (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) == 1)) {
        *(uint *)(uVar6 + iVar10 * 4 + 0x40) = uVar11;
        iVar10 = iVar10 + 1;
      }
      uVar11 = uVar9 & 3;
      uVar3 = *(uint *)(uVar9 & 0xfffffffc);
      uVar12 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
      iVar7 = iVar7 + 1;
      uVar3 = (uint)*(byte *)(uVar12 + 0x3d0);
    } while (iVar7 < (int)uVar3);
  }
  uVar6 = uRam02085768;
  uVar11 = uRam02085764;
  uVar9 = (*(uint *)(uRam02085768 & 0xfffffffc) >> (uRam02085768 & 3) * 8 |
          *(uint *)(uRam02085768 & 0xfffffffc) << (uRam02085768 & 3) * -8 + 0x20) + 0x120;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (uVar9 >> uVar8 * 8 != 0 || uVar9 << uVar8 * -8 + 0x20 != 0) {
    iVar10 = 0;
    iVar7 = 0;
    if (uVar3 != 0) {
      do {
        uVar9 = uVar6 & 3;
        uVar8 = *(uint *)(uVar6 & 0xfffffffc);
        uVar3 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        uVar9 = uVar3 + iVar7 * 4 + 0x20;
        uVar8 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
        if (-1 < (int)uVar9) {
          uVar8 = (uVar9 & 0xffff) * 0x30 + uVar12 + 0x70;
          uVar12 = uVar8 & 3;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc);
          uVar8 = uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20;
          bVar1 = false;
          if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
            bVar1 = true;
          }
          if (bVar1) {
            *(uint *)(uVar3 + iVar10 * 4 + 0x60) = uVar9;
            iVar10 = iVar10 + 1;
          }
        }
        uVar9 = uVar11 & 3;
        uVar8 = *(uint *)(uVar11 & 0xfffffffc);
        uVar12 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)*(byte *)(uVar12 + 0x3d0));
      return;
    }
    return;
  }
  return;
}


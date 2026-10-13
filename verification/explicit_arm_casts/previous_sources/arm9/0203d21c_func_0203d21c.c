/* Decompiled C draft; module arm9; ROM address 0203d21c. No matching claim. */
#include "types.h"
#include "deps/0203d21c_func_0203d21c.h"

void func_0203d21c(void)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  uint uVar7;
  
  uVar4 = DAT_0203d55c;
  uVar3 = DAT_0203d558;
  uVar11 = 0xffffffff;
  uVar5 = *(uint *)(DAT_0203d558 & 0xfffffffc) >> (DAT_0203d558 & 3) * 8 |
          *(uint *)(DAT_0203d558 & 0xfffffffc) << (DAT_0203d558 & 3) * -8 + 0x20;
  bVar2 = false;
  uVar7 = uVar5 + 8 & 3;
  uVar6 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (((uVar7 == 2) || (uVar7 == 3)) && (*(char *)(uVar5 + 0x58) != '\0')) {
    bVar2 = true;
  }
  switch(uVar7) {
  case 0:
    goto LAB_0203d278;
  case 1:
    break;
  case 2:
    if ((bVar2) && (uVar7 = 0, *(char *)(uVar5 + 0x3d0) != '\0')) {
      do {
        uVar6 = uVar7 * 0x8c +
                (*(uint *)(DAT_0203d55c & 0xfffffffc) >> (DAT_0203d55c & 3) * 8 |
                *(uint *)(DAT_0203d55c & 0xfffffffc) << (DAT_0203d55c & 3) * -8 + 0x20) + 0x14;
        uVar1 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if ((((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) == 1) && (bVar2)) &&
           (uVar11 == 0xffffffff)) {
          uVar6 = uVar7 * 0x30 + uVar5 + 0x74;
          uVar11 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
        }
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < *(byte *)(uVar5 + 0x3d0));
    }
    uVar7 = 0;
    if (*(char *)(uVar5 + 0x3d0) != '\0') {
      do {
        iVar10 = uVar7 * 0x8c;
        iVar9 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + iVar10;
        *(ushort *)(iVar9 + 0x44) = *(ushort *)(iVar9 + 0x44) | 2;
        uVar5 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + iVar10 + 0x14;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 1) {
          if (bVar2) {
            uVar5 = uVar7 * 0x30 +
                    (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x74;
            uVar6 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            bVar12 = uVar11 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
          }
          else {
            bVar12 = true;
          }
          func_0205d88c(uVar7,1);
        }
        else {
          bVar12 = false;
          if (bVar2) {
            uVar5 = uVar7 * 0x30 +
                    (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x74;
            uVar6 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            bVar12 = uVar11 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
          }
          func_0205d88c(uVar7,0);
          iVar10 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                   *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + iVar10;
          uVar5 = iVar10 + 0x14;
          uVar6 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
            *(undefined4 *)(iVar10 + 0x14) = 2;
          }
        }
        uVar8 = GetDriverEntry(uVar7);
        StructMQRacerEntry_SomeFn_25(uVar8,bVar12);
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < *(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3d0))
      ;
    }
    MaybePlayCrowdAmbientNoise(0);
    break;
  case 3:
    goto LAB_0203d278;
  case 4:
    break;
  case 5:
LAB_0203d278:
    uVar7 = 0;
    if (*(char *)(uVar5 + 0x3d0) != '\0') {
      do {
        uVar6 = uVar5 + 8 & 3;
        uVar5 = *(uint *)(uVar5 + 8 & 0xfffffffc);
        uVar8 = 0;
        if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 5) {
          uVar5 = ((uint)*(byte *)(*(char *)((*(uint *)(DAT_0203d560 & 0xfffffffc) >>
                                              (DAT_0203d560 & 3) * 8 |
                                             *(uint *)(DAT_0203d560 & 0xfffffffc) <<
                                             (DAT_0203d560 & 3) * -8 + 0x20) + (uVar7 & 0xff)) *
                                   0x88 + (*(uint *)(DAT_0203d564 & 0xfffffffc) >>
                                           (DAT_0203d564 & 3) * 8 |
                                          *(uint *)(DAT_0203d564 & 0xfffffffc) <<
                                          (DAT_0203d564 & 3) * -8 + 0x20) + 0x18a) << 0x18) >> 0x19;
        }
        else {
          uVar5 = *(ushort *)
                   (uVar7 * 0x8c +
                    (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x50) & 0xf;
        }
        iVar9 = uVar7 * 0x8c;
        uVar6 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + iVar9 + 0x14;
        uVar1 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) != 4) {
          uVar8 = func_0203c4d0(uVar5,uVar5,0);
        }
        func_0205d9d4(uVar7,uVar5,uVar8);
        func_0205d818(uVar7,(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x34 + iVar9
                     );
        uVar6 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8;
        uVar1 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) == 5) &&
           (uVar6 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + iVar9 + 0x14,
           uVar1 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
           (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) == 4)) {
          func_0205d974(uVar7);
        }
        if ((bVar2) && (uVar5 == 1)) {
          uVar5 = uVar7 * 0x30 +
                  (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x74;
          uVar6 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          uVar11 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        }
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < *(byte *)(uVar5 + 0x3d0));
    }
  }
  if (bVar2) {
    func_0205d558(uVar11);
  }
  *(undefined4 *)
   ((*(uint *)(DAT_0203d55c & 0xfffffffc) >> (DAT_0203d55c & 3) * 8 |
    *(uint *)(DAT_0203d55c & 0xfffffffc) << (DAT_0203d55c & 3) * -8 + 0x20) + 0x4cc) = 1;
  return;
}


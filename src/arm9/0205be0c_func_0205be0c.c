/* Decompiled C draft; module arm9; ROM address 0205be0c. No matching claim. */
#include "types.h"
#include "deps/0205be0c_func_0205be0c.h"

void func_0205be0c(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte abStack_39 [5];
  uint local_34 [4];
  
  uVar16 = uRam0205c21c;
  uVar17 = 0xf;
  uVar18 = 0;
  do {
    uVar6 = *(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
            *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20;
    local_34[uVar18] = 0xffffffff;
    abStack_39[uVar18 + 1] = (byte)uVar18;
    uVar12 = 1 << uVar18;
    uVar13 = *(byte *)(uVar6 + 0x749) & uVar12;
    if (uVar13 != 0) {
      bVar15 = false;
      if (((*(byte *)(uVar6 + 0xfc) & uVar12) != 0) && (uVar13 == 0)) {
        bVar15 = true;
      }
      if (bVar15) {
        uVar12 = uVar18 * 0x88 + uVar6 + 0x184;
        uVar6 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        local_34[uVar18] = (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) & uRam0205c220;
      }
      else {
        uVar6 = func_0x0219bb50();
        if (uVar18 == uVar6) {
          uVar13 = func_0205afa8();
          uVar6 = (uint)*(byte *)((*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                                  *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) +
                                 0x73e);
        }
        else {
          uVar6 = uVar18 * 0x88 +
                  (*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                  *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) + 0x108;
          uVar13 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar13 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
          uVar6 = (uVar13 & 0x7800000) >> 0x17;
        }
        uVar17 = uVar17 & uVar6;
        if (((uVar13 == 0) && (iVar8 = IsAwardOrStaffRoll(), iVar8 == 0)) &&
           (uVar6 = (uint)*(char *)((*(uint *)(uRam0205c224 & 0xfffffffc) >> (uRam0205c224 & 3) * 8
                                    | *(uint *)(uRam0205c224 & 0xfffffffc) <<
                                      (uRam0205c224 & 3) * -8 + 0x20) + uVar18 + 6),
           uVar6 != 0xffffffff)) {
          iVar8 = func_0205d27c(uVar6 & 0xffff);
          uVar13 = iVar8 - 1U | 0x700000;
        }
        if (uVar13 != 0) {
          if ((uVar13 & 0x400000) == 0) {
            uVar6 = *(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                    *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20;
            *(byte *)(uVar6 + 0x73e) = *(byte *)(uVar6 + 0x73e) | (byte)uVar12;
          }
          *(uint *)((*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                    *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) + uVar18 * 0x88 +
                   0x184) = uVar13;
          uVar12 = (*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                   *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) + uVar18 * 0x88 +
                   0x184;
          uVar6 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          local_34[uVar18] = (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) & uRam0205c220;
        }
      }
    }
    uVar12 = uRam0205c228;
    uVar18 = uVar18 + 1 & 0xff;
  } while (uVar18 < 4);
  uVar16 = 0;
  do {
    uVar7 = *(uint *)(uRam0205c21c & 0xfffffffc) >> (uRam0205c21c & 3) * 8 |
            *(uint *)(uRam0205c21c & 0xfffffffc) << (uRam0205c21c & 3) * -8 + 0x20;
    uVar18 = 1 << uVar16;
    uVar3 = *(undefined1 *)
             ((*(uint *)(uRam0205c224 & 0xfffffffc) >> (uRam0205c224 & 3) * 8 |
              *(uint *)(uRam0205c224 & 0xfffffffc) << (uRam0205c224 & 3) * -8 + 0x20) + uVar16 + 6);
    uVar14 = *(byte *)(uVar7 + 0x749) & uVar18;
    uVar6 = uVar16 * 0x88 + uVar7 + 0x184;
    uVar13 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar14 != 0) {
      bVar15 = false;
      if (((*(byte *)(uVar7 + 0xfc) & uVar18) != 0) && (uVar14 == 0)) {
        bVar15 = true;
      }
      if (((!bVar15) && ((uVar17 & uVar18) != 0)) &&
         (iVar8 = IsRacerFinishedRace(uVar3), iVar8 == 0)) {
        func_0203e4c4(uVar3,((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) & uVar12) != uVar12
                     );
      }
    }
    uVar16 = uVar16 + 1 & 0xff;
  } while (uVar16 < 4);
  uVar16 = 1;
  do {
    uVar18 = local_34[uVar16];
    bVar4 = abStack_39[uVar16 + 1];
    for (uVar17 = uVar16; (uVar17 != 0 && (uVar18 < local_34[uVar17 - 1]));
        uVar17 = uVar17 - 1 & 0xff) {
      bVar5 = abStack_39[uVar17];
      local_34[uVar17] = local_34[uVar17 - 1];
      abStack_39[uVar17 + 1] = bVar5;
    }
    uVar16 = uVar16 + 1 & 0xff;
    local_34[uVar17] = uVar18;
    abStack_39[uVar17 + 1] = bVar4;
  } while (uVar16 < 4);
  uVar16 = 0;
  do {
    uVar6 = (uint)abStack_39[uVar16 + 1];
    uVar17 = 0;
    uVar12 = *(uint *)(uRam0205c21c & 0xfffffffc) >> (uRam0205c21c & 3) * 8 |
             *(uint *)(uRam0205c21c & 0xfffffffc) << (uRam0205c21c & 3) * -8 + 0x20;
    uVar18 = uVar17;
    if (((uint)*(byte *)(uVar12 + 0xfc) & 1 << uVar6) != 0) {
      uVar18 = uVar6 * 0x88 + uVar12 + 0x184;
      uVar13 = uVar18 & 3;
      uVar18 = *(uint *)(uVar18 & 0xfffffffc);
      if (((uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20) & 0x400000) == 0) {
        uVar18 = uVar16 + 1 & 0xff;
        pbVar9 = abStack_39 + uVar16 + 1;
        uVar17 = uVar16;
        do {
          uVar13 = (uint)*pbVar9 * 0x88 + uVar12 + 0x184;
          uVar7 = uVar13 & 3;
          uVar13 = *(uint *)(uVar13 & 0xfffffffc);
          if (((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & 0x400000) != 0) {
            uVar18 = uVar18 - 1 & 0xff;
          }
          pbVar9 = pbVar9 + -1;
          uVar17 = (int)((uVar17 - 1) * 0x10000) >> 0x10;
        } while (-1 < (int)uVar17);
      }
      else {
        uVar14 = *(uint *)(uRam0205c224 & 0xfffffffc) >> (uRam0205c224 & 3) * 8 |
                 *(uint *)(uRam0205c224 & 0xfffffffc) << (uRam0205c224 & 3) * -8 + 0x20;
        uVar7 = *(uint *)(uRam0205c22c & 0xfffffffc) >> (uRam0205c22c & 3) * 8 |
                *(uint *)(uRam0205c22c & 0xfffffffc) << (uRam0205c22c & 3) * -8 + 0x20;
        uVar13 = *(ushort *)(((int)*(char *)(uVar14 + uVar6 + 6) & 0xffffU) * 0x8c + uVar7 + 0x50) &
                 0xf;
        uVar18 = uVar13;
        do {
          uVar10 = uVar17 * 0x88 + uVar12 + 0x184;
          uVar1 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          if ((((((uint)*(byte *)(uVar12 + 0xfc) & 1 << uVar17) != 0) &&
               (iVar8 = ((int)*(char *)(uVar14 + uVar17 + 6) & 0xffffU) * 0x8c + uVar7,
               uVar11 = iVar8 + 0x14, uVar2 = uVar11 & 3, uVar11 = *(uint *)(uVar11 & 0xfffffffc),
               (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) != 4)) &&
              (((uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) & 0x400000) == 0)) &&
             (uVar13 < (*(ushort *)(iVar8 + 0x50) & 0xf))) {
            uVar18 = uVar18 + 1 & 0xff;
          }
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 < 4);
      }
    }
    uVar16 = uVar16 + 1 & 0xff;
    *(byte *)(uVar12 + iRam0205c230 + uVar6 * 0x88) =
         *(byte *)(uVar12 + iRam0205c230 + uVar6 * 0x88) & 1 | (byte)((uVar18 & 0x7f) << 1);
  } while (uVar16 < 4);
  return;
}


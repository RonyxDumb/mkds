/* Decompiled C draft; module arm9; ROM address 020ca074. No matching claim. */
#include "types.h"
#include "deps/020ca074_func_020ca074.h"

void func_020ca074(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  undefined6 uVar20;
  int local_78;
  int local_74;
  int local_64;
  undefined4 local_50 [4];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uVar15;
  
  iVar18 = 0;
  uVar4 = func_020c0db0();
  uVar3 = uRam020ca3c0;
  local_78 = 0;
  local_64 = 0;
  do {
    uVar12 = iRam020ca3c4 + local_78 * 4;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    iVar11 = (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) * 0x44 +
             (*(uint *)(uRam020ca3c8 & 0xfffffffc) >> (uRam020ca3c8 & 3) * 8 |
             *(uint *)(uRam020ca3c8 & 0xfffffffc) << (uRam020ca3c8 & 3) * -8 + 0x20);
    uVar12 = iVar11 + 4;
    uVar1 = uVar12 & 3;
    uVar5 = *(uint *)(uVar12 & 0xfffffffc);
    uVar12 = iVar11 + 0x14;
    uVar14 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar12 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
    local_50[0] = *puRam020ca3cc;
    local_50[1] = puRam020ca3cc[1];
    local_50[2] = puRam020ca3cc[2];
    local_50[3] = puRam020ca3cc[3];
    local_40 = puRam020ca3cc[4];
    uStack_3c = puRam020ca3cc[5];
    uStack_38 = puRam020ca3cc[6];
    uStack_34 = puRam020ca3cc[7];
    local_30 = puRam020ca3cc[8];
    uStack_2c = puRam020ca3cc[9];
    uVar6 = GetB3C4_Cell_RaceS(local_50[local_78]);
    local_74 = 0;
    if (0 < (int)uVar12) {
      do {
        uVar14 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + local_74 * 4;
        uVar7 = uVar14 & 3;
        uVar14 = *(uint *)(uVar14 & 0xfffffffc);
        uVar15 = uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20;
        uVar14 = uVar15 + 0x74 & 3;
        uVar7 = *(uint *)(uVar15 + 0x74 & 0xfffffffc);
        iVar11 = local_64;
        if (((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 0x80000) == 0) {
          iVar11 = uVar15 + 0x50;
        }
        uVar2 = 3;
        if (local_78 == 9) {
          if (iVar11 != 0) {
            iVar13 = iVar18 * 0x14;
            uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            iVar8 = func_020b5ae8(iVar11,(int *)(uintptr_t)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) +
                                         iVar13),uVar4,1,1);
            if ((iVar8 != 0) && (0 < *(short *)(uVar15 + 0xd8))) {
              uVar7 = uVar15 + 0x170 & 3;
              uVar16 = *(uint *)(uVar15 + 0x170 & 0xfffffffc);
              uVar9 = func_021001a0();
              uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
              uVar15 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              iVar17 = (uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) + iVar13;
              iVar8 = _s32_div_f((uVar16 >> uVar7 * 8 | uVar16 << uVar7 * -8 + 0x20) * 0x88,uVar9);
              uVar14 = iVar17 + 4;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              *(uint *)(iVar17 + 4) = (uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) - iVar8;
              uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              iVar8 = (uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13;
              uVar14 = iVar8 + 4;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              if (0 < (int)(uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20)) {
                *(undefined4 *)(iVar8 + 8) = uVar6;
                uVar20 = CheckVectorBounds_Clock_Airship(iVar11);
                uVar10 = (undefined2)((uint6)uVar20 >> 0x20);
                bVar19 = (int)uVar20 != 0;
                if (bVar19) {
                  uVar10 = 2;
                }
                uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                         *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
                uVar7 = uVar14 & 3;
                uVar14 = *(uint *)(uVar14 & 0xfffffffc);
                if (!bVar19) {
                  uVar10 = uVar2;
                }
                *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xc)
                     = uVar10;
                iVar18 = iVar18 + 1;
                uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                         *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
                uVar7 = uVar14 & 3;
                uVar14 = *(uint *)(uVar14 & 0xfffffffc);
                *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xe)
                     = 0;
              }
            }
          }
        }
        else if (local_78 == 6) {
          uVar14 = uVar15 + 0x1a0 & 3;
          uVar7 = *(uint *)(uVar15 + 0x1a0 & 0xfffffffc);
          if ((uVar7 >> uVar14 * 8 != 0 || uVar7 << uVar14 * -8 + 0x20 != 0) && (iVar11 != 0)) {
            iVar13 = iVar18 * 0x14;
            uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            iVar8 = func_020b5ae8(iVar11,(int *)(uintptr_t)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) +
                                         iVar13),uVar4,1,1);
            if ((iVar8 != 0) &&
               (uVar14 = iVar11 + 4U & 3, uVar7 = *(uint *)(iVar11 + 4U & 0xfffffffc),
               iVar8 = func_020d3d10(uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20), iVar8 == 0)
               ) {
              uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              *(undefined4 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 8) =
                   uVar6;
              uVar20 = CheckVectorBounds_Clock_Airship(iVar11);
              uVar10 = (undefined2)((uint6)uVar20 >> 0x20);
              bVar19 = (int)uVar20 != 0;
              if (bVar19) {
                uVar10 = 2;
              }
              uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              if (!bVar19) {
                uVar10 = uVar2;
              }
              *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xc) =
                   uVar10;
              uVar14 = uVar15 + 0x74 & 3;
              uVar7 = *(uint *)(uVar15 + 0x74 & 0xfffffffc);
              iVar18 = iVar18 + 1;
              bVar19 = ((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 0x40000) != 0;
              if (bVar19) {
                uVar10 = 1;
              }
              uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
              uVar7 = uVar14 & 3;
              uVar14 = *(uint *)(uVar14 & 0xfffffffc);
              if (!bVar19) {
                uVar10 = 0;
              }
              *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xe) =
                   uVar10;
            }
          }
        }
        else if (iVar11 != 0) {
          iVar13 = iVar18 * 0x14;
          uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                   *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
          uVar7 = uVar14 & 3;
          uVar14 = *(uint *)(uVar14 & 0xfffffffc);
          iVar8 = func_020b5ae8(iVar11,(int *)(uintptr_t)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13),
                                uVar4,1,1);
          if ((iVar8 != 0) &&
             (uVar14 = iVar11 + 4U & 3, uVar7 = *(uint *)(iVar11 + 4U & 0xfffffffc),
             iVar8 = func_020d3d10(uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20), iVar8 == 0))
          {
            uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            *(undefined4 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 8) =
                 uVar6;
            uVar20 = CheckVectorBounds_Clock_Airship(iVar11);
            uVar10 = (undefined2)((uint6)uVar20 >> 0x20);
            bVar19 = (int)uVar20 != 0;
            if (bVar19) {
              uVar10 = 2;
            }
            uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            if (!bVar19) {
              uVar10 = uVar2;
            }
            *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xc) =
                 uVar10;
            uVar14 = uVar15 + 0x74 & 3;
            uVar7 = *(uint *)(uVar15 + 0x74 & 0xfffffffc);
            iVar18 = iVar18 + 1;
            bVar19 = ((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 0x40000) != 0;
            if (bVar19) {
              uVar10 = 1;
            }
            uVar14 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            if (!bVar19) {
              uVar10 = 0;
            }
            *(undefined2 *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + iVar13 + 0xe) =
                 uVar10;
          }
        }
        local_74 = local_74 + 1;
      } while (local_74 < (int)uVar12);
    }
    local_78 = local_78 + 1;
  } while (local_78 < 10);
  *(int *)((*(uint *)(uRam020ca3c0 & 0xfffffffc) >> (uRam020ca3c0 & 3) * 8 |
           *(uint *)(uRam020ca3c0 & 0xfffffffc) << (uRam020ca3c0 & 3) * -8 + 0x20) + 4) = iVar18;
  return;
}


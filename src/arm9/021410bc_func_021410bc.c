/* Decompiled C draft; module arm9; ROM address 021410bc. No matching claim. */
#include "types.h"
#include "deps/021410bc_func_021410bc.h"

void func_021410bc(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  undefined2 *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar16;
  bool bVar17;
  uint uVar15;
  
  iVar8 = 9;
  puVar12 = param_1;
  do {
    puVar3 = param_2 + 1;
    uVar1 = *param_2;
    param_2 = param_2 + 2;
    uVar2 = *puVar3;
    iVar8 = iVar8 + -1;
    puVar3 = puVar12 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 2;
    *puVar3 = uVar2;
  } while (iVar8 != 0);
  *puVar12 = *param_2;
  uVar16 = param_3 + 5U & 3;
  uVar4 = *(uint *)(param_3 + 5U & 0xfffffffc);
  if (((uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff) == 0) {
    return;
  }
  uVar16 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar9 = (uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff;
  uVar16 = param_3 + 4U & 3;
  uVar4 = *(uint *)(param_3 + 4U & 0xfffffffc);
  uVar4 = (uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff;
  uVar16 = uVar9;
  if (uVar9 < uVar4) {
    uVar16 = uVar4;
  }
  iVar13 = (int)(short)param_1[1] - (int)*(short *)(param_3 + 2);
  iVar8 = uVar16 + iVar13;
  if (0x20 < iVar8) {
    iVar8 = 0x20;
  }
  if ((int)uVar9 < iVar8) {
    puVar11 = (uint *)(param_1 + 2);
    do {
      uVar4 = ((*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
               *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) & 0xff) + 1
              & 0xff | (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                       *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) &
                       0xffffff00;
      uVar16 = (4 - ((uint)puVar11 & 3)) * 8 & 0x1f;
      *puVar11 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
      puVar10 = (uint *)((int)param_1 + uVar9 + 5);
      uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
              *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00
      ;
      uVar16 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
      *puVar10 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
      uVar16 = (uint)(param_1 + 2) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar9 = (uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff;
    } while ((int)uVar9 < iVar8);
  }
  puVar11 = (uint *)((int)param_1 + 5);
  uVar16 = param_3 + 4U & 3;
  uVar4 = *(uint *)(param_3 + 4U & 0xfffffffc);
  uVar9 = param_3 + 5;
  iVar6 = ((uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff) + iVar13;
  if (iVar6 < iVar8) {
    iVar8 = iVar6;
  }
  uVar16 = (int)puVar11 + iVar8 + uVar9 + (-iVar13 - (int)puVar11);
  puVar10 = (uint *)((int)puVar11 + iVar8);
  uVar4 = uVar16;
  while ((puVar11 < puVar10 && (uVar9 < uVar4))) {
    puVar7 = (uint *)((int)puVar10 + -1);
    uVar4 = uVar4 - 1;
    if (((*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
         *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff) <
        ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff)) {
      puVar5 = (uint *)((int)puVar10 + -2);
      uVar15 = (int)puVar10 - 2U & 3;
      uVar14 = *(uint *)((int)puVar10 - 2U & 0xfffffffc);
      uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
      while ((uVar15 & 0xff) == 0) {
        puVar5 = (uint *)((int)puVar5 + -1);
        uVar15 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                 *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      }
      while (puVar5 != puVar7) {
        uVar14 = ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                  *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xff) -
                 1 & 0xff |
                 (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                 *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) &
                 0xffffff00;
        uVar15 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
        *puVar5 = uVar14 >> uVar15 | uVar14 << 0x20 - uVar15;
        puVar5 = (uint *)((int)puVar5 + 1);
        uVar14 = ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                  *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xff) +
                 10 & 0xff |
                 (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                 *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) &
                 0xffffff00;
        uVar15 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
        *puVar5 = uVar14 >> uVar15 | uVar14 << 0x20 - uVar15;
      }
    }
    uVar14 = ((*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff) -
             ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff) & 0xff |
             (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
             *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
    uVar15 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar14 >> uVar15 | uVar14 << 0x20 - uVar15;
    puVar10 = puVar7;
  }
  iVar8 = uVar16 - uVar9;
  uVar4 = param_3 + 4U & 3;
  uVar9 = *(uint *)(param_3 + 4U & 0xfffffffc);
  uVar4 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) & 0xff;
  if (iVar8 < (int)uVar4) {
    uVar9 = (*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
            *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) & 0xff;
    bVar17 = uVar9 < 5;
    if ((bVar17) || (uVar9 != 5)) {
LAB_02141344:
      if (bVar17) {
        if (((*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
             *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff) == 0)
        {
          puVar7 = (uint *)((int)puVar10 + -1);
          uVar16 = (int)puVar10 - 1U & 3;
          uVar4 = *(uint *)((int)puVar10 - 1U & 0xfffffffc);
          uVar16 = uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20;
          while ((uVar16 & 0xff) == 0) {
            puVar7 = (uint *)((int)puVar7 + -1);
            uVar16 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                     *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
          }
          while (puVar7 != puVar10) {
            uVar4 = ((*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                     *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff)
                    - 1 & 0xff |
                    (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                    *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                    0xffffff00;
            uVar16 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
            *puVar7 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
            puVar7 = (uint *)((int)puVar7 + 1);
            uVar4 = ((*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                     *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff)
                    + 10 & 0xff |
                    (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                    *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                    0xffffff00;
            uVar16 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
            *puVar7 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
          }
        }
        uVar4 = ((*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
                 *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff) -
                1 & 0xff |
                (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
                *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) &
                0xffffff00;
        uVar16 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
        *puVar10 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
      }
    }
    else {
      do {
        uVar16 = uVar16 + 1;
        if (param_3 + 5 + uVar4 <= uVar16) {
          iVar13 = iVar13 + iVar8;
          puVar10 = (uint *)((int)puVar11 + iVar13 + -1);
          uVar16 = (int)puVar11 + iVar13 + -1;
          uVar4 = uVar16 & 3;
          uVar16 = *(uint *)(uVar16 & 0xfffffffc);
          if (((uVar16 >> uVar4 * 8 | uVar16 << uVar4 * -8 + 0x20) & 1) != 0) {
            bVar17 = true;
          }
          goto LAB_02141344;
        }
      } while (((*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) & 0xff) == 0);
    }
  }
  uVar16 = *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
           *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20;
  puVar10 = puVar11;
  while ((uVar16 & 0xff) == 0) {
    puVar10 = (uint *)((int)puVar10 + 1);
    uVar16 = *(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
             *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20;
  }
  if (puVar11 < puVar10) {
    uVar9 = (int)puVar10 - (int)puVar11 & 0xff;
    param_1[1] = param_1[1] - (short)uVar9;
    uVar16 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    puVar7 = (uint *)((int)puVar11 + ((uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff));
    for (; puVar10 < puVar7; puVar10 = (uint *)((int)puVar10 + 1)) {
      uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
              *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
              *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) & 0xffffff00
      ;
      uVar16 = (4 - ((uint)puVar11 & 3)) * 8 & 0x1f;
      *puVar11 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
      puVar11 = (uint *)((int)puVar11 + 1);
    }
    uVar16 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    puVar11 = (uint *)(param_1 + 2);
    uVar4 = ((uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff) - uVar9 & 0xff |
            (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
            *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) & 0xffffff00;
    uVar16 = (4 - ((uint)puVar11 & 3)) * 8 & 0x1f;
    *puVar11 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
  }
  uVar9 = (int)param_1 + 5;
  uVar16 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar16 = uVar9 + ((uVar4 >> uVar16 * 8 | uVar4 << uVar16 * -8 + 0x20) & 0xff);
  do {
    if (uVar16 <= uVar9) break;
    uVar16 = uVar16 - 1;
  } while (((*(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
            *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20) & 0xff) == 0);
  puVar11 = (uint *)(param_1 + 2);
  uVar4 = (uVar16 - uVar9) + 1 & 0xff |
          (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
          *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) & 0xffffff00;
  uVar16 = (4 - ((uint)puVar11 & 3)) * 8 & 0x1f;
  *puVar11 = uVar4 >> uVar16 | uVar4 << 0x20 - uVar16;
  return;
}


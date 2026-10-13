/* Decompiled C draft; module arm9; ROM address 02150228. No matching claim. */
#include "types.h"
#include "deps/02150228_func_02150228.h"

void func_02150228(int *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  
  piVar2 = param_1 + 6;
  uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar17 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar18 = uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar17 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar17 = uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20;
  iVar8 = 0;
  uVar1 = uRam02150608;
  piVar10 = piVar2;
  do {
    uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
            (*(uint *)((uint)piVar10 & 0xfffffffc) >> ((uint)piVar10 & 3) * 8 |
            *(uint *)((uint)piVar10 & 0xfffffffc) << ((uint)piVar10 & 3) * -8 + 0x20) +
            uVar4 + (uVar3 & uVar18 | ~uVar3 & uVar17);
    uVar4 = uVar3 + (uVar4 * 0x80 | uVar4 >> 0x19);
    uVar7 = (uint)(piVar10 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar10 + 1) & 0xfffffffc);
    uVar6 = uVar1 + 4 & 3;
    uVar11 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    uVar17 = (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
             (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) +
             uVar17 + (uVar4 & uVar3 | ~uVar4 & uVar18);
    uVar17 = uVar4 + (uVar17 * 0x1000 | uVar17 >> 0x14);
    uVar7 = (uint)(piVar10 + 2) & 3;
    uVar12 = *(uint *)((uint)(piVar10 + 2) & 0xfffffffc);
    uVar6 = uVar1 + 8 & 3;
    uVar13 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar5 = (uint)(piVar10 + 3) & 3;
    uVar11 = *(uint *)((uint)(piVar10 + 3) & 0xfffffffc);
    uVar18 = (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
             (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) +
             uVar18 + (uVar17 & uVar4 | ~uVar17 & uVar3);
    uVar7 = uVar1 + 0xc & 3;
    uVar6 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
    uVar18 = uVar17 + (uVar18 * 0x20000 | uVar18 >> 0xf);
    uVar1 = uVar1 + 0x10;
    piVar10 = piVar10 + 4;
    uVar3 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
            (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) +
            uVar3 + (uVar18 & uVar17 | ~uVar18 & uVar4);
    uVar3 = uVar18 + (uVar3 * 0x400000 | uVar3 >> 10);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 4);
  iVar8 = 0;
  uVar7 = uRam0215060c;
  do {
    uVar6 = (uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) &
                     0xfffffffc);
    uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
            (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
            uVar4 + (uVar3 & uVar17 | uVar18 & ~uVar17);
    uVar4 = uVar3 + (uVar4 * 0x20 | uVar4 >> 0x1b);
    uVar6 = uVar7 + 4 & 3;
    uVar12 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    uVar5 = uVar7 + 8 & 3;
    uVar13 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar11 = (uint)(piVar2 + (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20)) & 3;
    uVar15 = *(uint *)((uint)(piVar2 + (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20)) &
                      0xfffffffc);
    uVar6 = (uint)(piVar2 + (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20)) & 3;
    uVar14 = *(uint *)((uint)(piVar2 + (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20)) &
                      0xfffffffc);
    uVar5 = uVar7 + 0xc & 3;
    uVar9 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    uVar12 = uVar1 + 4 & 3;
    uVar16 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    uVar13 = (uint)(piVar2 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) & 3;
    uVar9 = *(uint *)((uint)(piVar2 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) &
                     0xfffffffc);
    uVar17 = (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) +
             (uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20) +
             uVar17 + (uVar4 & uVar18 | uVar3 & ~uVar18);
    uVar17 = uVar4 + (uVar17 * 0x200 | uVar17 >> 0x17);
    uVar5 = uVar1 + 8 & 3;
    uVar11 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar18 = (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) +
             (uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) +
             uVar18 + (uVar17 & uVar3 | uVar4 & ~uVar3);
    uVar6 = uVar1 + 0xc & 3;
    uVar5 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
    uVar18 = uVar17 + (uVar18 * 0x4000 | uVar18 >> 0x12);
    uVar1 = uVar1 + 0x10;
    uVar7 = uVar7 + 0x10;
    uVar3 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
            (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
            uVar3 + (uVar18 & uVar4 | uVar17 & ~uVar4);
    uVar3 = uVar18 + (uVar3 * 0x100000 | uVar3 >> 0xc);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 4);
  iVar8 = 0;
  do {
    uVar6 = (uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) &
                     0xfffffffc);
    uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
            (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + uVar4 + (uVar17 ^ uVar3 ^ uVar18);
    uVar4 = uVar3 + (uVar4 * 0x10 | uVar4 >> 0x1c);
    uVar6 = uVar7 + 4 & 3;
    uVar11 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    uVar5 = (uint)(piVar2 + (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20)) & 3;
    uVar12 = *(uint *)((uint)(piVar2 + (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20)) &
                      0xfffffffc);
    uVar6 = uVar7 + 8 & 3;
    uVar13 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar11 = uVar1 + 4 & 3;
    uVar9 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    uVar17 = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) +
             (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + uVar17 + (uVar18 ^ uVar4 ^ uVar3)
    ;
    uVar17 = uVar4 + (uVar17 * 0x800 | uVar17 >> 0x15);
    uVar5 = (uint)(piVar2 + (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20)) & 3;
    uVar13 = *(uint *)((uint)(piVar2 + (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20)) &
                      0xfffffffc);
    uVar6 = uVar1 + 8 & 3;
    uVar9 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar11 = uVar7 + 0xc & 3;
    uVar12 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    uVar18 = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
             (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) + uVar18 + (uVar3 ^ uVar17 ^ uVar4)
    ;
    uVar6 = (uint)(piVar2 + (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20)) & 3;
    uVar12 = *(uint *)((uint)(piVar2 + (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20)) &
                      0xfffffffc);
    uVar18 = uVar17 + (uVar18 * 0x10000 | uVar18 >> 0x10);
    iVar8 = iVar8 + 1;
    uVar5 = uVar1 + 0xc & 3;
    uVar11 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
    uVar3 = (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) +
            (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) + uVar3 + (uVar4 ^ uVar18 ^ uVar17);
    uVar1 = uVar1 + 0x10;
    uVar7 = uVar7 + 0x10;
    uVar3 = uVar18 + (uVar3 * 0x800000 | uVar3 >> 9);
  } while (iVar8 < 4);
  iVar8 = 0;
  do {
    uVar6 = (uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20)) &
                     0xfffffffc);
    uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
            (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + uVar4 + (uVar18 ^ (uVar3 | ~uVar17))
    ;
    uVar4 = uVar3 + (uVar4 * 0x40 | uVar4 >> 0x1a);
    uVar6 = uVar7 + 4 & 3;
    uVar12 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    uVar5 = uVar7 + 8 & 3;
    uVar9 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar11 = (uint)(piVar2 + (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20)) & 3;
    uVar12 = *(uint *)((uint)(piVar2 + (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20)) &
                      0xfffffffc);
    uVar6 = uVar1 + 4 & 3;
    uVar13 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    uVar17 = (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
             (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
             uVar17 + (uVar3 ^ (uVar4 | ~uVar18));
    uVar6 = uVar7 + 0xc & 3;
    uVar13 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    uVar17 = uVar4 + (uVar17 * 0x400 | uVar17 >> 0x16);
    uVar11 = (uint)(piVar2 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) & 3;
    uVar14 = *(uint *)((uint)(piVar2 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) &
                      0xfffffffc);
    uVar5 = uVar1 + 0xc & 3;
    uVar9 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
    uVar12 = (uint)(piVar2 + (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20)) & 3;
    uVar13 = *(uint *)((uint)(piVar2 + (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20)) &
                      0xfffffffc);
    uVar6 = uVar1 + 8 & 3;
    uVar15 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar18 = (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
             (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) +
             uVar18 + (uVar4 ^ (uVar17 | ~uVar3));
    uVar18 = uVar17 + (uVar18 * 0x8000 | uVar18 >> 0x11);
    uVar1 = uVar1 + 0x10;
    uVar7 = uVar7 + 0x10;
    uVar3 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
            (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) +
            uVar3 + (uVar17 ^ (uVar18 | ~uVar4));
    uVar3 = uVar18 + (uVar3 * 0x200000 | uVar3 >> 0xb);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 4);
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + uVar4;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + uVar3;
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[2] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar18;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[3] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar17;
  return;
}


/* Decompiled C draft; module arm9; ROM address 01ffdb70. No matching claim. */
#include "types.h"
#include "deps/01ffdb70_func_01ffdb70.h"

void func_01ffdb70(void)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  short *psVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint *puVar15;
  int local_28;
  
  uVar5 = uRam01ffdee0;
  uVar4 = uRam01ffdedc;
  uVar3 = uRam01ffded8;
  psVar2 = psRam01ffded4;
  iVar6 = (int)*psRam01ffded4;
  iVar12 = 0;
  if (0 < iVar6) {
    iVar8 = 0;
    do {
      uVar9 = uVar5 & 3;
      uVar7 = *(uint *)(uVar5 & 0xfffffffc);
      psVar11 = (short *)((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + iVar8);
      uVar9 = (uint)(psVar11 + 6) & 3;
      uVar7 = *(uint *)((uint)(psVar11 + 6) & 0xfffffffc);
      uVar10 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
      uVar9 = (uint)(psVar11 + 8) & 3;
      uVar7 = *(uint *)((uint)(psVar11 + 8) & 0xfffffffc);
      uVar9 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
      if (uVar10 != 0) {
        uVar1 = psVar11[10];
        if ((uVar1 & 0x600) != 0) {
          if ((uVar1 & 0x100) == 0) {
            iVar12 = iVar12 + 1;
            goto LAB_01ffdc30;
          }
          psVar11[10] = uVar1 & 0xfeff;
        }
        uVar7 = uVar10 + 8 & 3;
        uVar14 = *(uint *)(uVar10 + 8 & 0xfffffffc);
        iVar12 = iVar12 + 1;
        *(uint *)(psVar11 + 2) = (uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + uVar9;
        uVar7 = uVar10 + 8 & 3;
        uVar14 = *(uint *)(uVar10 + 8 & 0xfffffffc);
        *(uint *)(psVar11 + 4) = (uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) - uVar9;
        uVar7 = uVar3 & 3;
        uVar14 = *(uint *)(uVar3 & 0xfffffffc);
        *(short *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + *psVar11 * 4 + 2) =
             (short)((int)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                           *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + uVar9) >>
                    0xb);
        uVar7 = uVar4 & 3;
        uVar14 = *(uint *)(uVar4 & 0xfffffffc);
        *(short *)((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) + psVar11[1] * 4 + 2) =
             (short)((int)((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                           *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) - uVar9) >>
                    0xb);
      }
LAB_01ffdc30:
      iVar6 = (int)*psVar2;
      iVar8 = iVar8 + 0x1c;
    } while (iVar12 < iVar6);
  }
  uVar5 = uRam01ffdee0;
  uVar4 = uRam01ffdedc;
  uVar3 = uRam01ffded8;
  local_28 = 1;
  if (1 < iVar6) {
    do {
      iVar6 = local_28 << 2;
      iVar12 = local_28;
      while( true ) {
        uVar9 = uVar3 & 3;
        uVar7 = *(uint *)(uVar3 & 0xfffffffc);
        uVar9 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
        puVar15 = (uint *)(uVar9 + iVar6);
        puVar13 = (uint *)(uVar9 + (iVar12 + -1) * 4);
        if ((*(short *)((int)puVar13 + 2) <= *(short *)((int)puVar15 + 2)) || (iVar12 < 1)) break;
        uVar9 = *(uint *)((uint)puVar15 & 0xfffffffc);
        *puVar15 = *(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                   *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20;
        *puVar13 = uVar9 >> ((uint)puVar15 & 3) * 8 | uVar9 << ((uint)puVar15 & 3) * -8 + 0x20;
        uVar7 = (uint)(byte)*puVar15;
        uVar14 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        uVar9 = (uint)(byte)*puVar13;
        *(char *)(uVar14 + uVar7 * 4) = *(char *)(uVar14 + uVar7 * 4) + '\x01';
        *(char *)(uVar14 + uVar9 * 4) = *(char *)(uVar14 + uVar9 * 4) + -1;
        uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                 *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
        iVar8 = (uint)*(byte *)(uVar14 + uVar7 * 4 + 1) * 0x1c;
        *(short *)(uVar10 + iVar8) = *(short *)(uVar10 + iVar8) + 1;
        uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
        iVar8 = (uint)*(byte *)(uVar14 + uVar9 * 4 + 1) * 0x1c;
        *(short *)(uVar7 + iVar8) = *(short *)(uVar7 + iVar8) + -1;
        uVar9 = (uint)*(byte *)((int)puVar15 + 1);
        if (uVar9 == (byte)*puVar13) {
          do {
            uVar9 = uVar9 + 1;
          } while ((int)(uint)*(byte *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) +
                                       uVar9 * 4) < iVar12);
          *(byte *)((int)puVar15 + 1) = (byte)uVar9;
        }
        iVar6 = iVar6 + -4;
        iVar12 = iVar12 + -1;
        if ((byte)*puVar15 < *(byte *)((int)puVar13 + 1)) {
          *(byte *)((int)puVar13 + 1) = (byte)*puVar15;
        }
      }
      iVar6 = (int)*psRam01ffded4;
      local_28 = local_28 + 1;
    } while (local_28 < iVar6);
  }
  uVar5 = uRam01ffdee0;
  uVar4 = uRam01ffdedc;
  uVar3 = uRam01ffded8;
  psVar2 = psRam01ffded4;
  uVar9 = 1;
  if (iVar6 < 2) {
    return;
  }
  do {
    iVar6 = uVar9 << 2;
    uVar7 = uVar9;
    while( true ) {
      uVar10 = uVar4 & 3;
      uVar14 = *(uint *)(uVar4 & 0xfffffffc);
      uVar10 = uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20;
      puVar15 = (uint *)(uVar10 + iVar6);
      puVar13 = (uint *)(uVar10 + (uVar7 - 1) * 4);
      if ((*(short *)((int)puVar13 + 2) <= *(short *)((int)puVar15 + 2)) || ((int)uVar7 < 1)) break;
      uVar10 = *(uint *)((uint)puVar15 & 0xfffffffc);
      *puVar15 = *(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                 *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20;
      *puVar13 = uVar10 >> ((uint)puVar15 & 3) * 8 | uVar10 << ((uint)puVar15 & 3) * -8 + 0x20;
      uVar10 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
               *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      *(char *)(uVar10 + (uint)(byte)*puVar15 * 4) =
           *(char *)(uVar10 + (uint)(byte)*puVar15 * 4) + '\x01';
      uVar10 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
               *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      *(char *)(uVar10 + (uint)(byte)*puVar13 * 4) =
           *(char *)(uVar10 + (uint)(byte)*puVar13 * 4) + -1;
      iVar12 = (uint)*(byte *)((int)puVar15 + 1) * 0x1c +
               (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20);
      *(short *)(iVar12 + 2) = *(short *)(iVar12 + 2) + 1;
      iVar12 = (uint)*(byte *)((int)puVar13 + 1) * 0x1c +
               (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20);
      *(short *)(iVar12 + 2) = *(short *)(iVar12 + 2) + -1;
      uVar14 = (uint)(byte)*puVar13;
      uVar10 = (uint)(byte)*puVar15;
      if (uVar14 < uVar10) {
        while (((int)(uint)(byte)*puVar13 < (int)uVar10 &&
               (uVar14 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                         *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20,
               uVar7 - 1 == (uint)*(byte *)(uVar14 + uVar10 * 4 + 1)))) {
          iVar12 = uVar14 + uVar10 * 4;
          uVar10 = uVar10 - 1;
          *(char *)(iVar12 + 1) = *(char *)(iVar12 + 1) + '\x01';
        }
      }
      else {
        while (((int)(uint)(byte)*puVar15 < (int)uVar14 &&
               (uVar10 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                         *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20,
               uVar7 == *(byte *)(uVar10 + uVar14 * 4 + 1)))) {
          iVar12 = uVar10 + uVar14 * 4;
          uVar14 = uVar14 - 1;
          *(char *)(iVar12 + 1) = *(char *)(iVar12 + 1) + -1;
        }
      }
      iVar6 = iVar6 + -4;
      uVar7 = uVar7 - 1;
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < (int)*psVar2);
  return;
}


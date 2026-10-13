/* Decompiled C draft; module arm9; ROM address 020d5344. No matching claim. */
#include "types.h"
#include "deps/020d5344_func_020d5344.h"

undefined4 func_020d5344(int param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  short *psVar5;
  uint uVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  undefined1 local_28 [4];
  
  uVar6 = uRam020d554c;
  psVar5 = psRam020d5548;
  uVar4 = uRam020d5544;
  if ((param_1 < 0) || (0xff < param_1)) {
    return 0xffffffff;
  }
  uVar12 = *(uint *)(uRam020d5544 & 0xfffffffc) >> (uRam020d5544 & 3) * 8 |
           *(uint *)(uRam020d5544 & 0xfffffffc) << (uRam020d5544 & 3) * -8 + 0x20;
  iVar8 = uVar12 + param_1 * 0x1c;
  uVar9 = iVar8 + 0xc;
  uVar10 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  iVar16 = (int)*(short *)(uVar12 + param_1 * 0x1c);
  bVar2 = uVar9 >> uVar10 * 8 == 0;
  bVar3 = uVar9 << uVar10 * -8 + 0x20 == 0;
  piVar18 = (int *)local_28;
  if (bVar2 && bVar3) {
    piVar18 = (int *)&stack0xffffffdc;
  }
  uVar9 = (uint)*(short *)(iVar8 + 2);
  if (bVar2 && bVar3) {
    return 0xffffffff;
  }
  iVar8 = *psRam020d5548 + -1;
  if (iVar16 < iVar8) {
    iVar19 = iVar16 << 2;
    iVar14 = iVar16;
    do {
      uVar11 = uRam020d5550;
      uVar10 = uVar6 & 3;
      uVar12 = *(uint *)(uVar6 & 0xfffffffc);
      uVar13 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
      uVar10 = uVar13 + (iVar14 + 1) * 4;
      uVar12 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      *(uint *)(uVar13 + iVar19) = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
      uVar12 = (uint)*(byte *)(uVar13 + iVar19);
      uVar10 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
      iVar17 = uVar13 + iVar19;
      *(char *)(uVar11 + uVar12 * 4) = *(char *)(uVar11 + uVar12 * 4) + -1;
      uVar10 = uVar4 & 3;
      uVar13 = *(uint *)(uVar4 & 0xfffffffc);
      uVar10 = uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20;
      iVar14 = iVar14 + 1;
      iVar8 = (uint)*(byte *)(uVar11 + uVar12 * 4 + 1) * 0x1c;
      iVar19 = iVar19 + 4;
      *(short *)(uVar10 + iVar8) = *(short *)(uVar10 + iVar8) + -1;
      bVar1 = *(byte *)(iVar17 + 1);
      if ((int)uVar9 < (int)(uint)bVar1) {
        *(byte *)(iVar17 + 1) = bVar1 - 1;
      }
      iVar8 = *psVar5 + -1;
    } while (iVar14 < iVar8);
  }
  uVar10 = uRam020d5550;
  uVar6 = uRam020d554c;
  uVar4 = uRam020d5544;
  if ((int)uVar9 < iVar8) {
    iVar8 = uVar9 << 2;
    uVar12 = uVar9;
    do {
      uVar15 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
               *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
      uVar11 = uVar15 + (uVar12 + 1) * 4;
      uVar13 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      *(uint *)(uVar15 + iVar8) = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
      uVar11 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      *(char *)(uVar11 + (uint)*(byte *)(uVar15 + iVar8) * 4) =
           *(char *)(uVar11 + (uint)*(byte *)(uVar15 + iVar8) * 4) + -1;
      uVar11 = uVar4 & 3;
      uVar13 = *(uint *)(uVar4 & 0xfffffffc);
      iVar19 = (uint)*(byte *)(uVar15 + iVar8 + 1) * 0x1c +
               (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20);
      *(short *)(iVar19 + 2) = *(short *)(iVar19 + 2) + -1;
      uVar11 = (uint)*(byte *)(uVar15 + iVar8);
      if ((int)uVar11 < iVar16) {
        iVar19 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + uVar11 * 4;
        uVar13 = (uint)*(byte *)(iVar19 + 1);
        if (uVar13 == uVar9) {
          uVar15 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                   *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
          bVar1 = *(byte *)(uVar15 + uVar13 * 4);
          while (bVar1 < uVar11) {
            uVar13 = uVar13 + 1;
            bVar1 = *(byte *)(uVar15 + uVar13 * 4);
          }
          *(char *)(iVar19 + 1) = (char)uVar13;
        }
      }
      uVar12 = uVar12 + 1;
      iVar8 = iVar8 + 4;
    } while ((int)uVar12 < *psRam020d5548 + -1);
  }
  *(undefined4 *)(*piVar18 + 0xc) = 0;
  puVar7 = puRam020d5554;
  *(undefined2 *)
   ((*(uint *)(uRam020d5558 & 0xfffffffc) >> (uRam020d5558 & 3) * 8 |
    *(uint *)(uRam020d5558 & 0xfffffffc) << (uRam020d5558 & 3) * -8 + 0x20) + param_1 * 2) =
       *puRam020d5554;
  *puVar7 = (short)param_1;
  *psRam020d5548 = *psRam020d5548 + -1;
  return 0xffffffff;
}


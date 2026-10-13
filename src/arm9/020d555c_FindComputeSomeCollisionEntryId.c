/* Decompiled C draft; module arm9; ROM address 020d555c. No matching claim. */
#include "types.h"
#include "deps/020d555c_FindComputeSomeCollisionEntryId.h"

int FindComputeSomeCollisionEntryId(uint param_1,int param_2,undefined2 param_3,undefined4 param_4)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined2 *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined2 uVar6;
  
  uVar15 = uRam020d58b4;
  psVar7 = psRam020d58a8;
  if (0xff < *psRam020d58a8) {
    return -1;
  }
  sVar2 = *psRam020d58ac;
  iVar23 = (int)sVar2;
  uVar14 = uRam020d58b4 & 3;
  uVar20 = *(uint *)(uRam020d58b4 & 0xfffffffc);
  *psRam020d58ac =
       *(short *)((*(uint *)(uRam020d58b0 & 0xfffffffc) >> (uRam020d58b0 & 3) * 8 |
                  *(uint *)(uRam020d58b0 & 0xfffffffc) << (uRam020d58b0 & 3) * -8 + 0x20) +
                 iVar23 * 2);
  uVar18 = param_1 + 8 & 3;
  uVar19 = *(uint *)(param_1 + 8 & 0xfffffffc);
  puVar17 = (undefined2 *)(iVar23 * 0x1c + (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20));
  *(uint *)(puVar17 + 2) = (uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20) + param_2;
  uVar18 = param_1 + 8 & 3;
  uVar14 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(uint *)(puVar17 + 4) = (uVar14 >> uVar18 * 8 | uVar14 << uVar18 * -8 + 0x20) - param_2;
  *(uint *)(puVar17 + 6) = param_1;
  *(int *)(puVar17 + 8) = param_2;
  puVar17[10] = param_3;
  *(undefined4 *)(puVar17 + 0xc) = param_4;
  uVar14 = uRam020d58bc;
  uVar18 = uRam020d58b8;
  uVar19 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar8 = (int)*psVar7;
  iVar9 = (uVar19 + param_2) * 0x20;
  iVar11 = (uVar19 - param_2) * 0x20;
  uVar5 = (undefined2)((uint)iVar9 >> 0x10);
  uVar3 = (undefined1)sVar2;
  uVar6 = (undefined2)((uint)iVar11 >> 0x10);
  if (iVar8 == 0) {
    *(undefined1 *)
     (*(uint *)(uRam020d58b8 & 0xfffffffc) >> (uRam020d58b8 & 3) * 8 |
     *(uint *)(uRam020d58b8 & 0xfffffffc) << (uRam020d58b8 & 3) * -8 + 0x20) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
      *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + 1) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
      *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + 2) = uVar5;
    *(undefined1 *)
     (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
     *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 1) = uVar3;
    *(undefined2 *)
     ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 2) = uVar6;
    *(undefined2 *)
     (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
     *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
      *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 2) = 0;
    *psVar7 = 1;
    return iVar23;
  }
  iVar13 = 0;
  iVar12 = 0;
  iVar22 = iVar8;
  while( true ) {
    iVar10 = iVar13 + iVar22;
    iVar21 = iVar12 + iVar22;
    if ((iVar10 <= iVar8) &&
       ((int)*(short *)((*(uint *)(uRam020d58b8 & 0xfffffffc) >> (uRam020d58b8 & 3) * 8 |
                        *(uint *)(uRam020d58b8 & 0xfffffffc) << (uRam020d58b8 & 3) * -8 + 0x20) +
                        (iVar10 + -1) * 4 + 2) < iVar9 >> 0x10)) {
      iVar13 = iVar10;
    }
    if ((iVar21 <= iVar8) &&
       ((int)*(short *)((*(uint *)(uRam020d58bc & 0xfffffffc) >> (uRam020d58bc & 3) * 8 |
                        *(uint *)(uRam020d58bc & 0xfffffffc) << (uRam020d58bc & 3) * -8 + 0x20) +
                        (iVar21 + -1) * 4 + 2) < iVar11 >> 0x10)) {
      iVar12 = iVar21;
    }
    if (iVar22 == 1) break;
    iVar22 = iVar22 + 1 >> 1;
  }
  *puVar17 = (short)iVar13;
  psVar7 = psRam020d58a8;
  puVar17[1] = (short)iVar12;
  uVar15 = uRam020d58b8;
  iVar9 = (int)*psVar7;
  if (iVar13 < iVar9) {
    iVar11 = iVar9 << 2;
    do {
      uVar19 = uRam020d58bc;
      uVar18 = uVar15 & 3;
      uVar14 = *(uint *)(uVar15 & 0xfffffffc);
      uVar20 = uVar14 >> uVar18 * 8 | uVar14 << uVar18 * -8 + 0x20;
      uVar18 = uVar20 + (iVar9 + -1) * 4;
      uVar14 = uVar18 & 3;
      uVar18 = *(uint *)(uVar18 & 0xfffffffc);
      *(uint *)(uVar20 + iVar11) = uVar18 >> uVar14 * 8 | uVar18 << uVar14 * -8 + 0x20;
      uVar14 = (uint)*(byte *)(uVar20 + iVar11);
      uVar18 = uVar19 & 3;
      uVar19 = *(uint *)(uVar19 & 0xfffffffc);
      uVar18 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
      iVar22 = uVar20 + iVar11;
      *(char *)(uVar18 + uVar14 * 4) = *(char *)(uVar18 + uVar14 * 4) + '\x01';
      iVar9 = iVar9 + -1;
      iVar8 = (uint)*(byte *)(uVar18 + uVar14 * 4 + 1) * 0x1c;
      uVar18 = *(uint *)(uRam020d58b4 & 0xfffffffc) >> (uRam020d58b4 & 3) * 8 |
               *(uint *)(uRam020d58b4 & 0xfffffffc) << (uRam020d58b4 & 3) * -8 + 0x20;
      iVar11 = iVar11 + -4;
      *(short *)(uVar18 + iVar8) = *(short *)(uVar18 + iVar8) + 1;
      bVar1 = *(byte *)(iVar22 + 1);
      if (iVar12 <= (int)(uint)bVar1) {
        *(byte *)(iVar22 + 1) = bVar1 + 1;
      }
    } while (iVar13 < iVar9);
  }
  uVar15 = uRam020d58b8;
  psVar7 = psRam020d58a8;
  uVar4 = (undefined1)iVar12;
  *(undefined1 *)
   ((*(uint *)(uRam020d58b8 & 0xfffffffc) >> (uRam020d58b8 & 3) * 8 |
    *(uint *)(uRam020d58b8 & 0xfffffffc) << (uRam020d58b8 & 3) * -8 + 0x20) + iVar13 * 4) = uVar4;
  *(undefined2 *)
   ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
    *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar13 * 4 + 2) = uVar5;
  uVar18 = uRam020d58b8;
  if (iVar13 != *psVar7) {
    uVar15 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
             *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
    bVar1 = *(byte *)(uVar15 + (iVar13 + 1) * 4 + 1);
    if ((int)(uint)bVar1 <= iVar12) {
      *(byte *)(uVar15 + iVar13 * 4 + 1) = bVar1;
      goto LAB_020d57f0;
    }
  }
  *(undefined1 *)
   ((*(uint *)(uRam020d58b8 & 0xfffffffc) >> (uRam020d58b8 & 3) * 8 |
    *(uint *)(uRam020d58b8 & 0xfffffffc) << (uRam020d58b8 & 3) * -8 + 0x20) + iVar13 * 4 + 1) =
       uVar4;
  iVar9 = iVar13;
  while ((iVar9 = iVar9 + -1, -1 < iVar9 &&
         (uVar15 = uVar18 & 3, uVar14 = *(uint *)(uVar18 & 0xfffffffc),
         uVar15 = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20,
         iVar12 < (int)(uint)*(byte *)(uVar15 + iVar9 * 4 + 1)))) {
    *(undefined1 *)(uVar15 + iVar9 * 4 + 1) = uVar4;
  }
LAB_020d57f0:
  uVar14 = uRam020d58bc;
  uVar18 = uRam020d58b8;
  uVar15 = uRam020d58b4;
  iVar9 = (int)*psRam020d58a8;
  if (iVar12 < iVar9) {
    iVar11 = iVar9 << 2;
    do {
      uVar19 = uVar14 & 3;
      uVar20 = *(uint *)(uVar14 & 0xfffffffc);
      uVar16 = uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20;
      uVar19 = uVar16 + (iVar9 + -1) * 4;
      uVar20 = uVar19 & 3;
      uVar19 = *(uint *)(uVar19 & 0xfffffffc);
      iVar9 = iVar9 + -1;
      *(uint *)(uVar16 + iVar11) = uVar19 >> uVar20 * 8 | uVar19 << uVar20 * -8 + 0x20;
      uVar19 = uVar18 & 3;
      uVar20 = *(uint *)(uVar18 & 0xfffffffc);
      uVar19 = uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20;
      iVar8 = uVar16 + iVar11;
      *(char *)(uVar19 + (uint)*(byte *)(uVar16 + iVar11) * 4) =
           *(char *)(uVar19 + (uint)*(byte *)(uVar16 + iVar11) * 4) + '\x01';
      uVar19 = uVar15 & 3;
      uVar20 = *(uint *)(uVar15 & 0xfffffffc);
      iVar11 = iVar11 + -4;
      iVar8 = (uint)*(byte *)(iVar8 + 1) * 0x1c +
              (uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20);
      *(short *)(iVar8 + 2) = *(short *)(iVar8 + 2) + 1;
    } while (iVar12 < iVar9);
  }
  uVar15 = uRam020d58bc;
  psVar7 = psRam020d58a8;
  *(char *)((*(uint *)(uRam020d58bc & 0xfffffffc) >> (uRam020d58bc & 3) * 8 |
            *(uint *)(uRam020d58bc & 0xfffffffc) << (uRam020d58bc & 3) * -8 + 0x20) + iVar12 * 4) =
       (char)iVar13;
  *(undefined1 *)
   ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
    *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar12 * 4 + 1) = uVar3;
  *(undefined2 *)
   ((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
    *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + iVar12 * 4 + 2) = uVar6;
  *psVar7 = *psVar7 + 1;
  return iVar23;
}


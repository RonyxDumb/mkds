/* Decompiled C draft; module arm9; ROM address 01ffd900. No matching claim. */
#include "types.h"
#include "deps/01ffd900_func_01ffd900.h"

void func_01ffd900(int param_1,ushort param_2)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  
  if (param_1 < 0) {
    return;
  }
  if (0xff < param_1) {
    return;
  }
  iVar17 = (short)param_1 * 0x1c;
  uVar19 = *(uint *)(uRam01ffdb50 & 0xfffffffc) >> (uRam01ffdb50 & 3) * 8 |
           *(uint *)(uRam01ffdb50 & 0xfffffffc) << (uRam01ffdb50 & 3) * -8 + 0x20;
  sVar3 = *psRam01ffdb54;
  iVar11 = uVar19 + iVar17;
  iVar20 = (int)*(short *)(iVar11 + 2);
  uVar16 = *(uint *)(uRam01ffdb5c & 0xfffffffc) >> (uRam01ffdb5c & 3) * 8 |
           *(uint *)(uRam01ffdb5c & 0xfffffffc) << (uRam01ffdb5c & 3) * -8 + 0x20;
  puVar10 = (ushort *)(int)*(short *)(uVar19 + iVar17);
  uVar15 = *(uint *)(uRam01ffdb58 & 0xfffffffc) >> (uRam01ffdb58 & 3) * 8 |
           *(uint *)(uRam01ffdb58 & 0xfffffffc) << (uRam01ffdb58 & 3) * -8 + 0x20;
  uVar19 = iVar11 + 0xcU & 3;
  uVar13 = *(uint *)(iVar11 + 0xcU & 0xfffffffc);
  bVar6 = uVar13 >> uVar19 * 8 == 0;
  bVar7 = uVar13 << uVar19 * -8 + 0x20 == 0;
  uVar19 = iVar11 + 4U & 3;
  uVar14 = *(uint *)(iVar11 + 4U & 0xfffffffc);
  sVar4 = *(short *)(uVar15 + (int)puVar10 * 4 + 2);
  sVar5 = *(short *)(uVar16 + iVar20 * 4 + 2);
  uVar13 = iVar11 + 8U & 3;
  uVar12 = *(uint *)(iVar11 + 8U & 0xfffffffc);
  if (bVar6 && bVar7) {
    param_2 = 0;
    puVar10 = puRam01ffdb60;
  }
  if (bVar6 && bVar7) {
    *puVar10 = param_2;
    return;
  }
  *puRam01ffdb60 = 0;
  puVar9 = puRam01ffdb60;
  uVar8 = uRam01ffdb5c;
  while ((7 < (int)puVar10 && (sVar5 <= *(short *)(uVar15 + (int)(puVar10 + -4) * 4 + 2)))) {
    puVar10 = puVar10 + -4;
  }
  while ((0 < (int)puVar10 && (sVar5 <= *(short *)(uVar15 + ((int)puVar10 + -1) * 4 + 2)))) {
    puVar10 = (ushort *)((int)puVar10 + -1);
  }
  iVar11 = iVar20;
  while ((iVar11 < sVar3 + -8 && (*(short *)(uVar16 + (iVar11 + 8) * 4 + 2) <= sVar4))) {
    iVar11 = iVar11 + 8;
  }
  while ((iVar11 < sVar3 + -1 && (*(short *)(uVar16 + (iVar11 + 1) * 4 + 2) <= sVar4))) {
    iVar11 = iVar11 + 1;
  }
  iVar11 = (int)(short)iVar11;
  iVar17 = (int)(short)(ushort)*(byte *)(uVar15 + (int)puVar10 * 4 + 1);
  if (iVar11 < iVar17) {
    return;
  }
  do {
    uVar15 = uVar8 & 3;
    uVar16 = *(uint *)(uVar8 & 0xfffffffc);
    uVar15 = uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20;
    if (((int)(uint)*(byte *)(uVar15 + iVar11 * 4) < (int)puVar10) || (iVar11 == iVar20)) {
LAB_01ffdb28:
      if (iVar11 == 0) {
        return;
      }
    }
    else {
      bVar1 = *(byte *)(uVar15 + iVar11 * 4 + 1);
      iVar18 = (uint)bVar1 * 0x1c +
               (*(uint *)(uRam01ffdb50 & 0xfffffffc) >> (uRam01ffdb50 & 3) * 8 |
               *(uint *)(uRam01ffdb50 & 0xfffffffc) << (uRam01ffdb50 & 3) * -8 + 0x20);
      uVar15 = iVar18 + 4U & 3;
      uVar16 = *(uint *)(iVar18 + 4U & 0xfffffffc);
      uVar2 = *(ushort *)(iVar18 + 0x14);
      if (((int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) <=
           (int)(uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20)) &&
         (((uVar15 = iVar18 + 8U & 3, uVar16 = *(uint *)(iVar18 + 8U & 0xfffffffc),
           (int)(uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20) <=
           (int)(uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20) && ((uVar2 & param_2) != 0))
          && ((uVar2 & 0x200) == 0)))) {
        *(ushort *)
         ((*(uint *)(uRam01ffdb64 & 0xfffffffc) >> (uRam01ffdb64 & 3) * 8 |
          *(uint *)(uRam01ffdb64 & 0xfffffffc) << (uRam01ffdb64 & 3) * -8 + 0x20) +
         (short)*puVar9 * 2) = (ushort)bVar1;
        *(ushort *)
         ((*(uint *)(uRam01ffdb68 & 0xfffffffc) >> (uRam01ffdb68 & 3) * 8 |
          *(uint *)(uRam01ffdb68 & 0xfffffffc) << (uRam01ffdb68 & 3) * -8 + 0x20) +
         (short)*puVar9 * 2) = uVar2;
        uVar15 = iVar18 + 0x18U & 3;
        uVar16 = *(uint *)(iVar18 + 0x18U & 0xfffffffc);
        *(uint *)((*(uint *)(uRam01ffdb6c & 0xfffffffc) >> (uRam01ffdb6c & 3) * 8 |
                  *(uint *)(uRam01ffdb6c & 0xfffffffc) << (uRam01ffdb6c & 3) * -8 + 0x20) +
                 (short)*puVar9 * 4) = uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20;
        *puVar9 = *puVar9 + 1;
        if (*puVar9 == 0x80) {
          return;
        }
        goto LAB_01ffdb28;
      }
    }
    iVar11 = iVar11 + -1;
    if (iVar11 < iVar17) {
      return;
    }
  } while( true );
}


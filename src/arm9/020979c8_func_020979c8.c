/* Decompiled C draft; module arm9; ROM address 020979c8. No matching claim. */
#include "types.h"
#include "deps/020979c8_func_020979c8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020979c8(uint param_1)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iStack_b4;
  int iStack_b0;
  int iStack_80;
  undefined1 auStack_70 [36];
  undefined1 auStack_4c [40];
  
  iVar9 = iRam02097d78;
  if (param_1 == 0) {
    return;
  }
  uVar14 = *(uint *)(uRam02097d68 & 0xfffffffc) >> (uRam02097d68 & 3) * 8 |
           *(uint *)(uRam02097d68 & 0xfffffffc) << (uRam02097d68 & 3) * -8 + 0x20;
  iStack_b4 = 0;
  iStack_80 = 0x16c;
  sVar4 = *(short *)(iRam02097d6c + 0xea);
  iVar1 = (int)uVar14 >> 0x1f;
  sVar5 = *(short *)(iRam02097d6c + 0xe8);
  uVar3 = *puRam02097d70;
  sVar6 = *(short *)(iRam02097d74 + 0x16);
  sVar7 = *(short *)(iRam02097d74 + 0x14);
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iStack_b4) {
      return;
    }
    uVar15 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iStack_b4 * 4;
    uVar16 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar15 = uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20;
    if (uVar15 == 0) break;
    uVar16 = uVar15 + 0x9c & 3;
    uVar10 = *(uint *)(uVar15 + 0x9c & 0xfffffffc);
    sVar8 = *(short *)((uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) + 0x28);
    if (sVar8 == 0) {
      *(undefined4 *)(uVar15 + 0xa4) = 0;
      *(ushort *)(uVar15 + 2) = *(ushort *)(uVar15 + 2) & 0xfbff;
      *(undefined2 *)(uVar15 + 0x7e) = 0x2000;
      *(undefined4 *)(uVar15 + 0xeb8) = 0x1e;
      MTX_RotY33__from_thumb((undefined4 *)(void *)(auStack_70),(int)sVar5,(int)sVar4);
    }
    else if (sVar8 == 1) {
      *(undefined4 *)(uVar15 + 0xa4) = 1;
      *(ushort *)(uVar15 + 2) = *(ushort *)(uVar15 + 2) | uVar3;
      *(undefined2 *)(uVar15 + 0x7e) = 0x2000;
      *(undefined4 *)(uVar15 + 0xeb8) = 0x1e;
      MTX_RotY33__from_thumb((undefined4 *)(void *)(auStack_70),(int)sVar7,(int)sVar6);
    }
    iVar13 = uVar15 + 0xa8;
    *(undefined4 *)(uVar15 + 0xec8) = 0;
    uVar16 = uVar15 + 0xa4 & 3;
    uVar10 = *(uint *)(uVar15 + 0xa4 & 0xfffffffc);
    if (uVar10 >> uVar16 * 8 == 0 && uVar10 << uVar16 * -8 + 0x20 == 0) {
      uVar16 = (uint)*(ushort *)(uVar15 + 0x7e);
    }
    else {
      uVar16 = -(uint)*(ushort *)(uVar15 + 0x7e);
    }
    iStack_b0 = 0;
    iVar17 = uVar15 + iRam02097d7c;
    uVar10 = uVar15;
    do {
      uVar2 = uVar15 + 0xa4 & 3;
      uVar11 = *(uint *)(uVar15 + 0xa4 & 0xfffffffc);
      iVar12 = iStack_80;
      if (uVar11 >> uVar2 * 8 != 0 || uVar11 << uVar2 * -8 + 0x20 != 0) {
        iVar12 = -0x16c;
      }
      uVar16 = uVar16 - iVar12;
      iVar12 = (int)(uVar16 & 0xffff) >> 4;
      MTX_RotY33__from_thumb
                ((undefined4 *)(void *)(auStack_4c),(int)*(short *)(iVar9 + iVar12 * 4),
                 (int)*(short *)(iVar9 + (iVar12 * 2 + 1) * 2));
      MTX_Concat33((uint)(uintptr_t)(auStack_4c),(uint *)(uintptr_t)(uVar15 + 0x28),(uint *)(uintptr_t)(iVar13));
      MTX_Concat33((uint)(uintptr_t)(auStack_70),(uint *)(uintptr_t)(iVar13),(uint *)(uintptr_t)(iVar17));
      uVar2 = uVar15 + 4 & 3;
      uVar11 = *(uint *)(uVar15 + 4 & 0xfffffffc);
      *(int *)(uVar10 + 0xbe8) = (int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) >> 4;
      uVar2 = uVar15 + 8 & 3;
      uVar11 = *(uint *)(uVar15 + 8 & 0xfffffffc);
      *(int *)(uVar10 + 0xbec) = (int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) >> 4;
      uVar2 = uVar15 + 0xc & 3;
      uVar11 = *(uint *)(uVar15 + 0xc & 0xfffffffc);
      *(int *)(uVar10 + 0xbf0) = (int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) >> 4;
      uVar2 = uVar15 + 0xa4 & 3;
      uVar11 = *(uint *)(uVar15 + 0xa4 & 0xfffffffc);
      if (uVar11 >> uVar2 * 8 == 0 && uVar11 << uVar2 * -8 + 0x20 == 0) {
        iVar12 = FX_Atan2(0xfffffffe,0xfffffff6);
        iVar12 = (int)(iVar12 - uVar16 & 0xffff) >> 4;
        uVar11 = (uint)*(short *)(iVar9 + (iVar12 * 2 + 1) * 2);
        uVar2 = uVar15 + 4 & 3;
        uVar18 = *(uint *)(uVar15 + 4 & 0xfffffffc);
        *(int *)(uVar10 + 0xd50) =
             (int)((uVar18 >> uVar2 * 8 | uVar18 << uVar2 * -8 + 0x20) +
                  ((uint)((ulonglong)uVar11 * (ulonglong)uVar14) >> 0xc |
                  (iVar1 * uVar11 +
                  uVar14 * ((int)uVar11 >> 0x1f) +
                  (int)((ulonglong)uVar11 * (ulonglong)uVar14 >> 0x20)) * 0x100000)) >> 4;
        uVar2 = uVar15 + 8 & 3;
        uVar11 = *(uint *)(uVar15 + 8 & 0xfffffffc);
        *(int *)(uVar10 + 0xd54) = (int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) >> 4;
        uVar18 = (uint)*(short *)(iVar9 + iVar12 * 4);
        uVar2 = uVar15 + 0xc & 3;
        uVar11 = *(uint *)(uVar15 + 0xc & 0xfffffffc);
        *(int *)(uVar10 + 0xd58) =
             (int)((uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) +
                  ((uint)((ulonglong)uVar18 * (ulonglong)uVar14) >> 0xc |
                  (iVar1 * uVar18 +
                  uVar14 * ((int)uVar18 >> 0x1f) +
                  (int)((ulonglong)uVar18 * (ulonglong)uVar14 >> 0x20)) * 0x100000)) >> 4;
      }
      else {
        iVar12 = FX_Atan2(0xfffffffe,0xfffffff6);
        iVar12 = (int)(-iVar12 - uVar16 & 0xffff) >> 4;
        uVar11 = (uint)*(short *)(iVar9 + (iVar12 * 2 + 1) * 2);
        uVar2 = uVar15 + 4 & 3;
        uVar18 = *(uint *)(uVar15 + 4 & 0xfffffffc);
        *(int *)(uVar10 + 0xd50) =
             (int)((uVar18 >> uVar2 * 8 | uVar18 << uVar2 * -8 + 0x20) -
                  ((uint)((ulonglong)uVar11 * (ulonglong)uVar14) >> 0xc |
                  (iVar1 * uVar11 +
                  uVar14 * ((int)uVar11 >> 0x1f) +
                  (int)((ulonglong)uVar11 * (ulonglong)uVar14 >> 0x20)) * 0x100000)) >> 4;
        uVar2 = uVar15 + 8 & 3;
        uVar11 = *(uint *)(uVar15 + 8 & 0xfffffffc);
        *(int *)(uVar10 + 0xd54) = (int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) >> 4;
        uVar18 = (uint)*(short *)(iVar9 + iVar12 * 4);
        uVar2 = uVar15 + 0xc & 3;
        uVar11 = *(uint *)(uVar15 + 0xc & 0xfffffffc);
        *(int *)(uVar10 + 0xd58) =
             (int)((uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) -
                  ((uint)((ulonglong)uVar18 * (ulonglong)uVar14) >> 0xc |
                  (iVar1 * uVar18 +
                  uVar14 * ((int)uVar18 >> 0x1f) +
                  (int)((ulonglong)uVar18 * (ulonglong)uVar14 >> 0x20)) * 0x100000)) >> 4;
      }
      iVar13 = iVar13 + 0x30;
      iStack_b0 = iStack_b0 + 1;
      iVar17 = iVar17 + 0x30;
      uVar10 = uVar10 + 0xc;
    } while (iStack_b0 < 0x1e);
    iStack_b4 = iStack_b4 + 1;
  }
  return;
}


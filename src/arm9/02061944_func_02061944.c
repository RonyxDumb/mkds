/* Decompiled C draft; module arm9; ROM address 02061944. No matching claim. */
#include "types.h"
#include "deps/02061944_func_02061944.h"

void func_02061944(uint param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  
  iVar9 = iRam02061c1c;
  uVar12 = (*(uint *)(uRam02061be4 & 0xfffffffc) >> (uRam02061be4 & 3) * 8 |
           *(uint *)(uRam02061be4 & 0xfffffffc) << (uRam02061be4 & 3) * -8 + 0x20) + 0x18;
  uVar13 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  if ((*(char *)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + 5) != '\0') &&
     (param_2 == 0)) {
    uVar12 = 0;
    lVar4 = (ulonglong)(param_1 * 0x1000) * 0x39;
    uVar13 = (uint)lVar4;
    uVar20 = uVar13 + 0x800 >> 0xc |
             (((int)(param_1 * 0x1000) >> 0x1f) * 0x39 + (int)((ulonglong)lVar4 >> 0x20) +
             (uint)(0xfffff7ff < uVar13)) * 0x100000;
    uVar11 = (uint)((ulonglong)uVar20 * 0x48);
    sVar1 = *psRam02061bf0;
    uVar13 = uRam02061be8 & 3;
    uVar14 = *(uint *)(uRam02061be8 & 0xfffffffc);
    uVar18 = uRam02061bf4 & 3;
    uVar16 = *(uint *)(uRam02061bf4 & 0xfffffffc);
    sVar2 = *psRam02061bfc;
    uVar19 = uRam02061c00 & 3;
    uVar17 = *(uint *)(uRam02061c00 & 0xfffffffc);
    sVar3 = *psRam02061bec;
    uVar15 = 0x1000 - uVar20;
    *puRam02061bf8 = uVar20;
    *puRam02061c04 = uVar15;
    puVar7 = puRam02061c0c;
    uVar11 = uVar11 + 0x800 >> 0xc |
             (((int)uVar20 >> 0x1f) * 0x48 + (int)((ulonglong)uVar20 * 0x48 >> 0x20) +
             (uint)(0xfffff7ff < uVar11)) * 0x100000;
    lVar4 = (longlong)(int)uVar15 *
            (longlong)(int)(uVar17 >> uVar19 * 8 | uVar17 << uVar19 * -8 + 0x20) + 0x800;
    lVar5 = (longlong)(int)uVar20 *
            (longlong)(int)(uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 0x800;
    lVar6 = (longlong)(int)uVar15 *
            (longlong)(int)(uVar16 >> uVar18 * 8 | uVar16 << uVar18 * -8 + 0x20) + 0x800;
    *psRam02061c08 =
         (short)((int)sVar3 * uVar15 + 0x800 >> 0xc) +
         (short)((int)sVar1 * uVar15 + 0x800 >> 0xc) * 0x20 +
         (short)((int)sVar2 * uVar15 + 0x800 >> 0xc) * 0x400;
    puVar8 = puRam02061c14;
    *piRam02061c10 =
         ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000) +
         ((uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000);
    *puVar8 = (uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) * 0x100000;
    iVar10 = iRam02061c20;
    iVar9 = iRam02061c1c;
    puVar8 = puRam02061c18;
    *puVar7 = uVar11;
    do {
      uVar13 = iVar10 + uVar12 * 4;
      uVar18 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      uVar13 = uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20;
      uVar18 = 0;
      *puVar8 = uVar13 & 0xff;
      puVar8[1] = (uVar13 & 0xff00) >> 8;
      puVar8[2] = (uVar13 & 0xff0000) >> 0x10;
      puVar8[3] = uVar13 >> 0x18;
      do {
        uVar19 = (uint)(puVar8 + uVar18) & 3;
        uVar14 = *(uint *)((uint)(puVar8 + uVar18) & 0xfffffffc);
        uVar19 = uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20;
        uVar14 = (uint)((ulonglong)uVar15 * (ulonglong)uVar19);
        puVar8[uVar18] =
             uVar11 + (uVar14 + 0x800 >> 0xc |
                      (((int)uVar19 >> 0x1f) * uVar15 +
                       uVar19 * ((int)uVar15 >> 0x1f) +
                       (int)((ulonglong)uVar15 * (ulonglong)uVar19 >> 0x20) +
                      (uint)(0xfffff7ff < uVar14)) * 0x100000);
        uVar18 = uVar18 + 1;
      } while (uVar18 < 4);
      uVar18 = (uint)(puVar8 + 1) & 3;
      uVar16 = *(uint *)((uint)(puVar8 + 1) & 0xfffffffc);
      uVar19 = (uint)(puVar8 + 2) & 3;
      uVar17 = *(uint *)((uint)(puVar8 + 2) & 0xfffffffc);
      uVar14 = (uint)(puVar8 + 3) & 3;
      uVar20 = *(uint *)((uint)(puVar8 + 3) & 0xfffffffc);
      *(uint *)(iVar9 + uVar12 * 4) =
           *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
           *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20 |
           (uVar16 >> uVar18 * 8 | uVar16 << uVar18 * -8 + 0x20) << 8 |
           (uVar17 >> uVar19 * 8 | uVar17 << uVar19 * -8 + 0x20) << 0x10 |
           (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20) << 0x18;
      uVar12 = uVar12 + 1 & 0xffff;
    } while (uVar12 < 8);
    *puRam02061c24 = uVar13;
    return;
  }
  uVar12 = 0;
  do {
    *(uint *)(iVar9 + uVar12 * 4) = param_1 | param_1 << 8 | param_1 << 0x10 | param_1 << 0x18;
    uVar12 = uVar12 + 1 & 0xffff;
  } while (uVar12 < 8);
  return;
}


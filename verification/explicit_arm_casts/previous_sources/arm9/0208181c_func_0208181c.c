/* Decompiled C draft; module arm9; ROM address 0208181c. No matching claim. */
#include "types.h"
#include "deps/0208181c_func_0208181c.h"

void func_0208181c(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar17;
  undefined1 auStack_34 [16];
  uint uVar12;
  uint uVar16;
  
  iVar17 = param_1 * 0xc +
           (*(uint *)(uRam02081a20 & 0xfffffffc) >> (uRam02081a20 & 3) * 8 |
           *(uint *)(uRam02081a20 & 0xfffffffc) << (uRam02081a20 & 3) * -8 + 0x20);
  iVar7 = GetDriverEntry();
  iVar6 = iRam02081a38;
  uVar10 = *(uint *)(uRam02081a24 & 0xfffffffc) >> (uRam02081a24 & 3) * 8 |
           *(uint *)(uRam02081a24 & 0xfffffffc) << (uRam02081a24 & 3) * -8 + 0x20;
  uVar16 = iVar7 + 0x2a0U & 3;
  uVar15 = *(uint *)(iVar7 + 0x2a0U & 0xfffffffc);
  uVar16 = uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20;
  lVar4 = (longlong)(int)uVar16 *
          (longlong)
          (int)((*(uint *)(uRam02081a28 & 0xfffffffc) >> (uRam02081a28 & 3) * 8 |
                *(uint *)(uRam02081a28 & 0xfffffffc) << (uRam02081a28 & 3) * -8 + 0x20) - uVar10) +
          0x800;
  uVar15 = *(uint *)(uRam02081a2c & 0xfffffffc) >> (uRam02081a2c & 3) * 8 |
           *(uint *)(uRam02081a2c & 0xfffffffc) << (uRam02081a2c & 3) * -8 + 0x20;
  uVar13 = *(uint *)(uRam02081a34 & 0xfffffffc) >> (uRam02081a34 & 3) * 8 |
           *(uint *)(uRam02081a34 & 0xfffffffc) << (uRam02081a34 & 3) * -8 + 0x20;
  lVar5 = (longlong)(int)uVar16 *
          (longlong)
          (int)((*(uint *)(uRam02081a30 & 0xfffffffc) >> (uRam02081a30 & 3) * 8 |
                *(uint *)(uRam02081a30 & 0xfffffffc) << (uRam02081a30 & 3) * -8 + 0x20) - uVar15) +
          0x800;
  uVar16 = 0;
  do {
    uVar8 = iVar17 + uVar16 * 4;
    uVar11 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if (uVar8 >> uVar11 * 8 != 0 || uVar8 << uVar11 * -8 + 0x20 != 0) {
      uVar8 = iVar7 + 0x590U & 3;
      uVar11 = *(uint *)(iVar7 + 0x590U & 0xfffffffc);
      uVar12 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
      uVar11 = iVar7 + 0xc0U & 3;
      uVar9 = *(uint *)(iVar7 + 0xc0U & 0xfffffffc);
      uVar8 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar8 = iRam02081a3c + (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) * 4;
      uVar12 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) *
              (longlong)(int)(uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) + 0x800;
      VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,iVar7 + 300,
                        iVar7 + 0x80,auStack_34);
      uVar8 = iVar17 + uVar16 * 4;
      uVar11 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      func_0208b5b0(uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20,auStack_34);
      uVar8 = iVar7 + 0x3b0U & 3;
      uVar11 = *(uint *)(iVar7 + 0x3b0U & 0xfffffffc);
      uVar12 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
      lVar1 = (ulonglong)uVar12 * 0xc00;
      uVar8 = iVar7 + 0x3b4U & 3;
      uVar11 = *(uint *)(iVar7 + 0x3b4U & 0xfffffffc);
      uVar9 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
      lVar2 = (ulonglong)uVar9 * 0xc00;
      uVar8 = iVar7 + 0x3b8U & 3;
      uVar11 = *(uint *)(iVar7 + 0x3b8U & 0xfffffffc);
      uVar14 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
      lVar3 = (ulonglong)uVar14 * 0xc00;
      uVar8 = iVar17 + uVar16 * 4;
      uVar11 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20;
      *(uint *)(uVar8 + 0x40) =
           (uint)lVar1 >> 0xc |
           (((int)uVar12 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      *(uint *)(uVar8 + 0x44) =
           (uint)lVar2 >> 0xc |
           (((int)uVar9 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
      *(uint *)(uVar8 + 0x48) =
           (uint)lVar3 >> 0xc |
           (((int)uVar14 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
      uVar8 = iVar17 + uVar16 * 4;
      uVar11 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(int *)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x68) =
           (int)(short)((uVar10 + ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000))
                        * uVar13 + 0x800 >> 0xc);
      uVar8 = iVar17 + uVar16 * 4;
      uVar11 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(int *)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 100) =
           (int)(short)((uVar15 + ((uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000))
                        * uVar13 + 0x800 >> 0xc);
      uVar11 = iVar7 + 0xc4U & 3;
      uVar9 = *(uint *)(iVar7 + 0xc4U & 0xfffffffc);
      uVar8 = iVar17 + uVar16 * 4;
      uVar12 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(int *)((uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) + 0x5c) =
           (int)(short)(iVar6 * (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + 0x800 >> 0xc);
    }
    uVar16 = uVar16 + 1 & 0xffff;
  } while (uVar16 < 3);
  return;
}


/* Decompiled C draft; module arm9; ROM address 02081618. No matching claim. */
#include "types.h"
#include "deps/02081618_func_02081618.h"

void func_02081618(int param_1,uint param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  iVar10 = param_1 * 0x58 +
           (*(uint *)(uRam0208171c & 0xfffffffc) >> (uRam0208171c & 3) * 8 |
           *(uint *)(uRam0208171c & 0xfffffffc) << (uRam0208171c & 3) * -8 + 0x20);
  uVar6 = iVar10 + 0x2c;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  if (uVar6 != 0) {
    uVar8 = uVar6 + 0x20 & 3;
    uVar7 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar6 + 0x28) =
         (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) +
         (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    uVar8 = uVar6 + 0x20 & 3;
    uVar7 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar9 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar7 = param_2 + 4 & 3;
    uVar11 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar8 = (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + 8;
    uVar9 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar6 + 0x2c) =
         (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
         (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
    uVar8 = uVar6 + 0x20 & 3;
    uVar7 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar9 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar7 = param_2 + 8 & 3;
    uVar11 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar8 = (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + 0xc;
    uVar9 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar6 + 0x30) =
         (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
         (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
    iVar5 = GetDriverEntry();
    uVar6 = iVar5 + 0x3b0U & 3;
    uVar8 = *(uint *)(iVar5 + 0x3b0U & 0xfffffffc);
    uVar7 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    lVar2 = (ulonglong)uRam02081720 * (ulonglong)uVar7;
    uVar6 = iVar5 + 0x3b4U & 3;
    uVar8 = *(uint *)(iVar5 + 0x3b4U & 0xfffffffc);
    uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    lVar3 = (ulonglong)uRam02081720 * (ulonglong)uVar6;
    iVar1 = ((int)uVar6 >> 0x1f) * uRam02081720;
    uVar6 = iVar5 + 0x3b8U & 3;
    uVar8 = *(uint *)(iVar5 + 0x3b8U & 0xfffffffc);
    uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    lVar4 = (ulonglong)uRam02081720 * (ulonglong)uVar6;
    iVar5 = ((int)uVar6 >> 0x1f) * uRam02081720;
    uVar6 = iVar10 + 0x2c;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    *(uint *)(uVar6 + 0x40) =
         (uint)lVar2 >> 0xc |
         (((int)uVar7 >> 0x1f) * uRam02081720 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
    *(uint *)(uVar6 + 0x44) =
         (uint)lVar3 >> 0xc | (iVar1 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    *(uint *)(uVar6 + 0x48) =
         (uint)lVar4 >> 0xc | (iVar5 + (int)((ulonglong)lVar4 >> 0x20)) * 0x100000;
    return;
  }
  return;
}


/* Decompiled C draft; module arm9; ROM address 020813ec. No matching claim. */
#include "types.h"
#include "deps/020813ec_func_020813ec.h"

void func_020813ec(int param_1,uint param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined1 auStack_2c [16];
  
  iVar6 = GetDriverEntry();
  uVar8 = iVar6 + 0x4cU & 3;
  uVar9 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc);
  iVar14 = param_1 * 0x58 +
           (*(uint *)(uRam02081550 & 0xfffffffc) >> (uRam02081550 & 3) * 8 |
           *(uint *)(uRam02081550 & 0xfffffffc) << (uRam02081550 & 3) * -8 + 0x20);
  if (((((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) & 0x8000) != 0) &&
      (uVar8 = iVar14 + 0x28U & 3, uVar9 = *(uint *)(iVar14 + 0x28U & 0xfffffffc),
      uVar9 >> uVar8 * 8 == 0 && uVar9 << uVar8 * -8 + 0x20 == 0)) &&
     (uVar8 = iVar6 + 0x2a4U & 3, uVar9 = *(uint *)(iVar6 + 0x2a4U & 0xfffffffc),
     0x1000 < (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20))) {
    uVar8 = iVar6 + 0x508U & 3;
    uVar9 = *(uint *)(iVar6 + 0x508U & 0xfffffffc);
    iVar7 = func_0208b7bc(0x53,uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
    uVar5 = uRam02081554;
    *(int *)(iVar7 + 0x94) = iVar6;
    *(undefined4 *)(iVar7 + 0x90) = uVar5;
    *(int *)(iVar14 + 0x28) = iVar7;
  }
  uVar8 = iVar14 + 0x28U & 3;
  uVar9 = *(uint *)(iVar14 + 0x28U & 0xfffffffc);
  uVar8 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  if (uVar8 != 0) {
    uVar9 = iVar6 + 0x3b0U & 3;
    uVar12 = *(uint *)(iVar6 + 0x3b0U & 0xfffffffc);
    uVar12 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    lVar2 = (ulonglong)uRam02081558 * (ulonglong)uVar12;
    uVar9 = iVar6 + 0x3b4U & 3;
    uVar13 = *(uint *)(iVar6 + 0x3b4U & 0xfffffffc);
    uVar9 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
    lVar3 = (ulonglong)uRam02081558 * (ulonglong)uVar9;
    iVar7 = ((int)uVar9 >> 0x1f) * uRam02081558;
    uVar9 = iVar6 + 0x3b8U & 3;
    uVar13 = *(uint *)(iVar6 + 0x3b8U & 0xfffffffc);
    uVar9 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
    lVar4 = (ulonglong)uRam02081558 * (ulonglong)uVar9;
    iVar1 = ((int)uVar9 >> 0x1f) * uRam02081558;
    *(uint *)(uVar8 + 0x40) =
         (uint)lVar2 >> 0xc |
         (((int)uVar12 >> 0x1f) * uRam02081558 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
    *(uint *)(uVar8 + 0x44) =
         (uint)lVar3 >> 0xc | (iVar7 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    *(uint *)(uVar8 + 0x48) =
         (uint)lVar4 >> 0xc | (iVar1 + (int)((ulonglong)lVar4 >> 0x20)) * 0x100000;
    uVar8 = iVar6 + 0x1d0U & 3;
    uVar12 = *(uint *)(iVar6 + 0x1d0U & 0xfffffffc);
    uVar9 = iVar6 + 0x508U & 3;
    uVar13 = *(uint *)(iVar6 + 0x508U & 0xfffffffc);
    VecFx32_AddScale1(-(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20),param_2,
                      uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20,(int *)(void *)(auStack_2c));
    uVar8 = iVar14 + 0x28U & 3;
    uVar9 = *(uint *)(iVar14 + 0x28U & 0xfffffffc);
    func_0208b5b0(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20,(uint)(uintptr_t)(auStack_2c));
    uVar8 = param_2 + 4 & 3;
    uVar13 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar9 = param_2 + 8 & 3;
    uVar10 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar12 = iVar14 + 0x28U & 3;
    uVar11 = *(uint *)(iVar14 + 0x28U & 0xfffffffc);
    uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    *(ushort *)(uVar12 + 0x50) =
         (ushort)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8) |
         (ushort)(*(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
    *(ushort *)(uVar12 + 0x52) =
         (ushort)(uVar13 >> uVar8 * 8) | (ushort)(uVar13 << uVar8 * -8 + 0x20);
    *(ushort *)(uVar12 + 0x54) =
         (ushort)(uVar10 >> uVar9 * 8) | (ushort)(uVar10 << uVar9 * -8 + 0x20);
    uVar8 = iVar6 + 0x48U & 3;
    uVar9 = *(uint *)(iVar6 + 0x48U & 0xfffffffc);
    *(uint *)(iVar6 + 0x48) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20 | 0x400;
    return;
  }
  return;
}


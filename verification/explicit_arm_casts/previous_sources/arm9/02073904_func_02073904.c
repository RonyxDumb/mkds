/* Decompiled C draft; module arm9; ROM address 02073904. No matching claim. */
#include "types.h"
#include "deps/02073904_func_02073904.h"

void func_02073904(uint param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint uVar8;
  uint uVar11;
  
  iVar2 = func_02061f7c();
  if (iVar2 == 0) {
    VecFx32_Subtract(param_1 + 0x24,param_1 + 0x18,&local_58);
    lVar1 = (longlong)local_50 * (longlong)local_50 +
            (longlong)local_58 * (longlong)local_58 + (longlong)local_54 * (longlong)local_54;
    iVar2 = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar2 = Vector3_MaybeNormalize(&local_58,&local_58);
    }
    if (iVar2 != 0) {
      uVar15 = *(uint *)(uRam02073de0 & 0xfffffffc) >> (uRam02073de0 & 3) * 8 |
               *(uint *)(uRam02073de0 & 0xfffffffc) << (uRam02073de0 & 3) * -8 + 0x20;
      uVar12 = uVar15 + 0x498 & 3;
      uVar7 = *(uint *)(uVar15 + 0x498 & 0xfffffffc);
      uVar8 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      iVar14 = uVar15 + iRam02073de8;
      uVar12 = iVar14 + 8U & 3;
      uVar7 = *(uint *)(iVar14 + 8U & 0xfffffffc);
      uVar9 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = iVar14 + 4U & 3;
      uVar3 = *(uint *)(iVar14 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar8 * (ulonglong)uVar9;
      uVar13 = (uint)lVar1;
      uVar7 = iVar14 + 0xcU & 3;
      uVar4 = *(uint *)(iVar14 + 0xcU & 0xfffffffc);
      uVar6 = iVar14 + 0x10U & 3;
      uVar10 = *(uint *)(iVar14 + 0x10U & 0xfffffffc);
      uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
      uVar10 = *(uint *)(uRam02073de4 & 0xfffffffc) >> (uRam02073de4 & 3) * 8 |
               *(uint *)(uRam02073de4 & 0xfffffffc) << (uRam02073de4 & 3) * -8 + 0x20;
      uVar6 = iVar14 + 0x14U & 3;
      uVar5 = *(uint *)(iVar14 + 0x14U & 0xfffffffc);
      *(uint *)(uVar15 + 0x498) = uVar11 + uVar13;
      *(uint *)(iVar14 + 4) =
           (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
           (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * uVar8 +
           uVar9 * (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar11,uVar13);
      uVar12 = iVar14 + 4U & 3;
      uVar7 = *(uint *)(iVar14 + 4U & 0xfffffffc);
      lVar1 = (longlong)
              (int)(*(uint *)(uRam02073dec & 0xfffffffc) >> (uRam02073dec & 3) * 8 |
                   *(uint *)(uRam02073dec & 0xfffffffc) << (uRam02073dec & 3) * -8 + 0x20) *
              (longlong)iVar2;
      lVar1 = (longlong)
              (int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) + 0x1000) *
              (longlong)
              (int)(*(uint *)(uRam02073df0 & 0xfffffffc) >> (uRam02073df0 & 3) * 8 |
                   *(uint *)(uRam02073df0 & 0xfffffffc) << (uRam02073df0 & 3) * -8 + 0x20);
      uVar11 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      lVar1 = (longlong)(int)uVar11 *
              (longlong)
              (((short)((ushort)((ushort)((uVar7 >> uVar12 * 8) >> 0x10) |
                                (ushort)((uVar7 << uVar12 * -8 + 0x20) >> 0x10)) >> 4) + -0x800) * 2
              );
      uVar12 = param_1 + 0xc & 3;
      uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
      uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_70 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x10 & 3;
      uVar7 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_6c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x14 & 3;
      uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_68 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = uVar15 + 0x498 & 3;
      uVar7 = *(uint *)(uVar15 + 0x498 & 0xfffffffc);
      uVar3 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = iVar14 + 8U & 3;
      uVar7 = *(uint *)(iVar14 + 8U & 0xfffffffc);
      uVar16 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = iVar14 + 4U & 3;
      uVar13 = *(uint *)(iVar14 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar3 * (ulonglong)uVar16;
      uVar5 = (uint)lVar1;
      uVar7 = iVar14 + 0xcU & 3;
      uVar4 = *(uint *)(iVar14 + 0xcU & 0xfffffffc);
      uVar6 = iVar14 + 0x10U & 3;
      uVar8 = *(uint *)(iVar14 + 0x10U & 0xfffffffc);
      uVar9 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      uVar6 = iVar14 + 0x14U & 3;
      uVar8 = *(uint *)(iVar14 + 0x14U & 0xfffffffc);
      *(uint *)(uVar15 + 0x498) = uVar9 + uVar5;
      *(uint *)(iVar14 + 4) =
           (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
           (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * uVar3 +
           uVar16 * (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar9,uVar5);
      uVar12 = iVar14 + 4U & 3;
      uVar7 = *(uint *)(iVar14 + 4U & 0xfffffffc);
      lVar1 = (longlong)(int)uVar11 *
              (longlong)
              (((short)((ushort)((ushort)((uVar7 >> uVar12 * 8) >> 0x10) |
                                (ushort)((uVar7 << uVar12 * -8 + 0x20) >> 0x10)) >> 4) + -0x800) * 2
              );
      uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      lVar1 = (longlong)
              (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_64 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 4 & 3;
      uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_60 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 8 & 3;
      uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_5c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      VecFx32_Add(&local_70,&local_64,param_1 + 0xf4);
      uVar13 = *(uint *)(uRam02073de0 & 0xfffffffc) >> (uRam02073de0 & 3) * 8 |
               *(uint *)(uRam02073de0 & 0xfffffffc) << (uRam02073de0 & 3) * -8 + 0x20;
      iVar2 = uVar13 + iRam02073de8;
      uVar12 = iVar2 + 8U & 3;
      uVar7 = *(uint *)(iVar2 + 8U & 0xfffffffc);
      uVar5 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = uVar13 + 0x498 & 3;
      uVar7 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
      uVar15 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = iVar2 + 4U & 3;
      uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar15 * (ulonglong)uVar5;
      uVar8 = (uint)lVar1;
      uVar7 = iVar2 + 0xcU & 3;
      uVar4 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
      uVar6 = iVar2 + 0x10U & 3;
      uVar9 = *(uint *)(iVar2 + 0x10U & 0xfffffffc);
      uVar11 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = iVar2 + 0x14U & 3;
      uVar9 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
      *(uint *)(uVar13 + 0x498) = uVar11 + uVar8;
      *(uint *)(iVar2 + 4) =
           (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * uVar15 +
           uVar5 * (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar11,uVar8);
      uVar12 = iVar2 + 4U & 3;
      uVar6 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      uVar7 = param_1 + 0xc & 3;
      uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
      lVar1 = (longlong)(int)uVar10 *
              (longlong)
              (((short)((ushort)((ushort)((uVar6 >> uVar12 * 8) >> 0x10) |
                                (ushort)((uVar6 << uVar12 * -8 + 0x20) >> 0x10)) >> 4) + -0x800) * 2
              );
      uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      lVar1 = (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_70 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x10 & 3;
      uVar7 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_6c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x14 & 3;
      uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar6;
      local_68 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = iVar2 + 8U & 3;
      uVar7 = *(uint *)(iVar2 + 8U & 0xfffffffc);
      uVar5 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = uVar13 + 0x498 & 3;
      uVar7 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
      uVar15 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
      uVar12 = iVar2 + 4U & 3;
      uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar15 * (ulonglong)uVar5;
      uVar8 = (uint)lVar1;
      uVar7 = iVar2 + 0xcU & 3;
      uVar4 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
      uVar6 = iVar2 + 0x10U & 3;
      uVar9 = *(uint *)(iVar2 + 0x10U & 0xfffffffc);
      uVar11 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar6 = iVar2 + 0x14U & 3;
      uVar9 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
      *(uint *)(uVar13 + 0x498) = uVar11 + uVar8;
      *(uint *)(iVar2 + 4) =
           (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * uVar15 +
           uVar5 * (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar11,uVar8);
      uVar12 = iVar2 + 4U & 3;
      uVar7 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      lVar1 = (longlong)(int)uVar10 *
              (longlong)
              (((short)((ushort)((ushort)((uVar7 >> uVar12 * 8) >> 0x10) |
                                (ushort)((uVar7 << uVar12 * -8 + 0x20) >> 0x10)) >> 4) + -0x800) * 2
              );
      uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      lVar1 = (longlong)
              (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_64 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 4 & 3;
      uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_60 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 8 & 3;
      uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar7;
      local_5c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      VecFx32_Add(&local_70,&local_64,param_1 + 0x100);
    }
  }
  uVar12 = *(uint *)(uRam02073df4 & 0xfffffffc) >> (uRam02073df4 & 3) * 8 |
           *(uint *)(uRam02073df4 & 0xfffffffc) << (uRam02073df4 & 3) * -8 + 0x20;
  VecFx32_Subtract(param_1 + 0x100,param_1 + 0x118,&local_40);
  local_40 = (uint)((longlong)(int)local_40 * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_40 * (longlong)(int)uVar12) >> 0x20) << 0x14;
  local_38 = (uint)((longlong)(int)local_38 * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)uVar12) >> 0x20) << 0x14;
  local_3c = (uint)((longlong)(int)local_3c * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_3c * (longlong)(int)uVar12) >> 0x20) << 0x14;
  VecFx32_Add(param_1 + 0x118,&local_40,param_1 + 0x118);
  uVar12 = *(uint *)(uRam02073df8 & 0xfffffffc) >> (uRam02073df8 & 3) * 8 |
           *(uint *)(uRam02073df8 & 0xfffffffc) << (uRam02073df8 & 3) * -8 + 0x20;
  VecFx32_Subtract(param_1 + 0xf4,param_1 + 0x10c,&local_34);
  local_34 = (uint)((longlong)(int)local_34 * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_34 * (longlong)(int)uVar12) >> 0x20) << 0x14;
  local_30 = (uint)((longlong)(int)local_30 * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_30 * (longlong)(int)uVar12) >> 0x20) << 0x14;
  local_2c = (uint)((longlong)(int)local_2c * (longlong)(int)uVar12) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_2c * (longlong)(int)uVar12) >> 0x20) << 0x14;
  VecFx32_Add(param_1 + 0x10c,&local_34,param_1 + 0x10c);
  uVar7 = param_1 + 0x10c & 3;
  uVar3 = *(uint *)(param_1 + 0x10c & 0xfffffffc);
  uVar12 = iRam02073dfc + (*(byte *)(param_1 + 0x130) - 1) * 4;
  uVar6 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  iVar2 = -(uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
  lVar1 = (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) * (longlong)iVar2;
  local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = param_1 + 0x110 & 3;
  uVar7 = *(uint *)(param_1 + 0x110 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) * (longlong)iVar2;
  local_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = param_1 + 0x114 & 3;
  uVar7 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) * (longlong)iVar2;
  local_44 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  VecFx32_Add(&local_4c,param_1 + 0x124,param_1 + 0x124);
  uVar12 = param_1 + 0x124 & 3;
  uVar7 = *(uint *)(param_1 + 0x124 & 0xfffffffc);
  uVar6 = *(uint *)(uRam02073e00 & 0xfffffffc) >> (uRam02073e00 & 3) * 8 |
          *(uint *)(uRam02073e00 & 0xfffffffc) << (uRam02073e00 & 3) * -8 + 0x20;
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) * (longlong)(int)uVar6;
  *(uint *)(param_1 + 0x124) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = param_1 + 0x128 & 3;
  uVar7 = *(uint *)(param_1 + 0x128 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) * (longlong)(int)uVar6;
  *(uint *)(param_1 + 0x128) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = param_1 + 300 & 3;
  uVar7 = *(uint *)(param_1 + 300 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) * (longlong)(int)uVar6;
  *(uint *)(param_1 + 300) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}


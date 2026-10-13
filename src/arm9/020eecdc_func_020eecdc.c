/* Decompiled C draft; module arm9; ROM address 020eecdc. No matching claim. */
#include "types.h"
#include "deps/020eecdc_func_020eecdc.h"

void func_020eecdc(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint local_7c;
  uint local_74;
  int local_68;
  uint local_58;
  int local_54;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint uVar3;
  uint uVar6;
  
  uVar4 = param_1 + 0xc & 3;
  uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x14 & 3;
  uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar11 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 + 0x1fc;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar4 = param_1 + 0x20 & 3;
  uVar5 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  local_48 = *(undefined4 *)(uVar2 + 0x1fc);
  uStack_44 = *(undefined4 *)(uVar2 + 0x200);
  uStack_40 = *(undefined4 *)(uVar2 + 0x204);
  uVar4 = param_1 + 0x8c & 3;
  uVar2 = *(uint *)(param_1 + 0x8c & 0xfffffffc);
  uVar10 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar2 = param_1 + 0x78 & 3;
  uVar15 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  uVar9 = (uint)((ulonglong)uVar10 * 0x3000) >> 0xc |
          (int)((ulonglong)uVar10 * 0x3000 >> 0x20) * 0x100000;
  uVar4 = uVar11 + 0x44 & 3;
  uVar5 = *(uint *)(uVar11 + 0x44 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020ef1b8 & 0xfffffffc) >> (uRam020ef1b8 & 3) * 8 |
          *(uint *)(uRam020ef1b8 & 0xfffffffc) << (uRam020ef1b8 & 3) * -8 + 0x20) + 0x70;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar14 = (uVar15 >> uVar2 * 8 | uVar15 << uVar2 * -8 + 0x20) +
           ((uVar10 << 0xe) >> 0xc | (uVar10 >> 0x12) << 0x14);
  func_020ef65c(param_1,uVar11 + 0x50,param_1 + 0xa8);
  iVar7 = func_020fa0b8(uVar11,uVar4,uRam020ef1bc);
  if (iVar7 != 0) {
    uVar2 = param_1 + 0x84 & 3;
    uVar10 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
    uVar5 = param_1 + 0x88 & 3;
    uVar15 = *(uint *)(param_1 + 0x88 & 0xfffffffc);
    func_020f9f08(uVar11,uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20,
                  uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20);
  }
  if (1 < (int)uVar6) {
    uVar2 = param_1 + 0x80 & 3;
    uVar5 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
    if (uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) {
      VecFx32_Subtract(param_1 + 0xd8,param_1 + 0x9c,&local_30);
      uVar2 = param_1 + 0x68 & 3;
      uVar5 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      lVar1 = (longlong)(int)uVar2 * (longlong)(int)uVar2;
      uVar2 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      local_30 = (uint)((longlong)(int)local_30 * (longlong)(int)uVar2) >> 0xc |
                 (int)((ulonglong)((longlong)(int)local_30 * (longlong)(int)uVar2) >> 0x20) << 0x14;
      local_2c = (uint)((longlong)(int)local_2c * (longlong)(int)uVar2) >> 0xc |
                 (int)((ulonglong)((longlong)(int)local_2c * (longlong)(int)uVar2) >> 0x20) << 0x14;
      local_28 = (uint)((longlong)(int)local_28 * (longlong)(int)uVar2) >> 0xc |
                 (int)((ulonglong)((longlong)(int)local_28 * (longlong)(int)uVar2) >> 0x20) << 0x14;
    }
    *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x9c);
    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xa4);
    uVar2 = param_1 + 0x16c & 3;
    uVar5 = *(uint *)(param_1 + 0x16c & 0xfffffffc);
    uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    *(uint *)(param_1 + 0x16c) = uVar2 + 1;
    local_7c = uVar2 & 0xf;
    uVar2 = param_1 + 0xe4 & 3;
    uVar5 = *(uint *)(param_1 + 0xe4 & 0xfffffffc);
    *(uint *)(param_1 + local_7c * 4 + 0xec) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar2 = param_1 + 0x68 & 3;
    uVar5 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
    uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    local_74 = (uVar2 << 9) >> 0xc | (((int)uVar2 >> 0x1f) << 9 | uVar2 >> 0x17) << 0x14;
    if (0x1000 < (int)local_74) {
      local_74 = 0x1000;
    }
  }
  iVar7 = 1;
  if (1 < (int)uVar6) {
    iVar12 = 0x1800;
    local_68 = iRam020ef1c0;
    iVar8 = param_1 + 0xb4;
    iVar16 = param_1 + 0xa8;
    do {
      iVar13 = iVar8;
      uVar2 = param_1 + 0x14 + iVar7 * 4;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar10 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      VecFx32_Add(iVar13,(uint)(uintptr_t)(&local_48),(int *)(uintptr_t)(iVar13));
      uVar2 = param_1 + 0x24 & 3;
      uVar5 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
      if (uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) {
        uVar2 = param_1 + 0x14 + (iVar7 + -1) * 4;
        uVar5 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        VecFx32_Add((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x5c,uVar10 + 0x5c,
                    (int *)(uintptr_t)(uVar10 + 0x5c));
      }
      uVar2 = param_1 + 0x80 & 3;
      uVar5 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
      if (uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) {
        VecFx32_AddScale1(iVar12,(uint)(uintptr_t)(&local_30),iVar13,(int *)(uintptr_t)(iVar13));
      }
      uVar2 = param_1 + iVar7 * 4 + 0xcc;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      if (0 < (int)uVar2) {
        VecFx32_AddScale1(uVar2,param_1 + 0x6c,iVar13,(int *)(uintptr_t)(iVar13));
      }
      VecFx32_Subtract(iVar13,param_1 + 0x50,&local_3c);
      if (1 < iVar7) {
        iVar14 = iVar14 + (iVar7 + -1) * -0x2000;
      }
      iVar8 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_3c),param_1 + 0x9c);
      if (0 < iVar14 - iVar8) {
        VecFx32_AddScale1(iVar14 - iVar8,param_1 + 0x9c,iVar13,(int *)(uintptr_t)(iVar13));
      }
      uVar2 = iVar16 + 4U & 3;
      uVar11 = *(uint *)(iVar16 + 4U & 0xfffffffc);
      uVar5 = iVar13 + 4U & 3;
      uVar15 = *(uint *)(iVar13 + 4U & 0xfffffffc);
      uVar5 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) - uVar5;
      lVar1 = (ulonglong)uRam020ef1c4 * (ulonglong)uVar2;
      uVar2 = (uint)lVar1 >> 0xc |
              (((int)uVar2 >> 0x1f) * uRam020ef1c4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      if ((int)uVar2 < 0) {
        *(uint *)(iVar13 + 4) = uVar5 + uVar2;
      }
      uVar2 = param_1 + (local_7c - 6 & 0xf) * 4 + (iVar7 + -1) * 0x40 + 0xec;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      if (iVar7 == 1) {
        *(uint *)(param_1 + local_7c * 4 + 300) = uVar2;
      }
      uVar5 = param_1 + 0x7c & 3;
      uVar11 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
      uVar2 = uVar2 - (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20);
      VecFx32_Subtract(iVar13,iVar16,&local_3c);
      local_54 = (int)((ulonglong)((longlong)(int)uVar9 * (longlong)(int)uVar9) >> 0x20);
      local_58 = (uint)((longlong)(int)uVar9 * (longlong)(int)uVar9);
      lVar1 = (longlong)local_34 * (longlong)local_34 +
              (longlong)local_3c * (longlong)local_3c + (longlong)local_38 * (longlong)local_38;
      uVar5 = (uint)lVar1;
      iVar8 = (int)((ulonglong)lVar1 >> 0x20);
      if ((int)(iVar8 - (local_54 + (uint)(uVar5 < local_58))) < 0 ==
          (SBORROW4(iVar8,local_54) != SBORROW4(iVar8 - local_54,(uint)(uVar5 < local_58)))) {
        if ((int)(uint)(uVar5 < 0x10) <= iVar8) {
          Vector3_MaybeNormalize((uint)(uintptr_t)(&local_3c),&local_3c);
        }
        VecFx32_AddScale1(uVar9,(uint)(uintptr_t)(&local_3c),iVar16,(int *)(uintptr_t)(iVar13));
        iVar8 = param_1 + iVar7 * 4;
        uVar5 = iVar8 + 0xcc;
        uVar11 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
        if (0 < (int)uVar5) {
          *(uint *)(iVar8 + 0xcc) = uVar5 - 0x3d;
        }
      }
      uVar5 = param_1 + 0x8c & 3;
      uVar11 = *(uint *)(param_1 + 0x8c & 0xfffffffc);
      uVar5 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uRam020ef1c8 * (ulonglong)uVar5;
      VecFx32_AddScale1(((uint)((ulonglong)local_74 * (ulonglong)uVar2) >> 0xc |
                        (((int)uVar2 >> 0x1f) * local_74 +
                        uVar2 * ((int)local_74 >> 0x1f) +
                        (int)((ulonglong)local_74 * (ulonglong)uVar2 >> 0x20)) * 0x100000) +
                        ((uint)lVar1 >> 0xc |
                        (((int)uVar5 >> 0x1f) * uRam020ef1c8 + (int)((ulonglong)lVar1 >> 0x20)) *
                        0x100000),param_1 + 0x38,iVar13,(int *)(uintptr_t)(uVar10 + 0x50));
      iVar8 = func_020fa0b8(uVar10,uVar4,local_68);
      if (iVar8 != 0) {
        uVar2 = param_1 + 0x84 & 3;
        uVar11 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
        uVar5 = param_1 + 0x88 & 3;
        uVar15 = *(uint *)(param_1 + 0x88 & 0xfffffffc);
        func_020f9f08(uVar10,uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20,
                      uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20);
      }
      iVar7 = iVar7 + 1;
      local_68 = local_68 + 0xcd;
      iVar12 = iVar12 + 0x1800;
      iVar8 = iVar13 + 0xc;
      iVar16 = iVar13;
    } while (iVar7 < (int)uVar6);
  }
  if ((*(ushort *)(uVar3 + 0x1ec) & 0x244) != 0x244) {
    return;
  }
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 0xf) {
    return;
  }
  uVar4 = param_1 + 0x24 & 3;
  uVar2 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    return;
  }
  func_020efa60(param_1,1);
  return;
}


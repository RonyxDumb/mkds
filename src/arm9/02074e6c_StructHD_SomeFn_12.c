/* Decompiled C draft; module arm9; ROM address 02074e6c. No matching claim. */
#include "types.h"
#include "deps/02074e6c_StructHD_SomeFn_12.h"

void StructHD_SomeFn_12(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  uint uVar19;
  int local_190;
  int iStack_18c;
  int iStack_188;
  int local_184;
  int local_180;
  int local_17c;
  uint local_178;
  uint local_174;
  uint local_170;
  undefined1 auStack_16c [36];
  undefined1 auStack_148 [36];
  undefined1 auStack_124 [36];
  undefined1 auStack_100 [36];
  undefined1 auStack_dc [36];
  undefined1 auStack_b8 [36];
  undefined1 auStack_94 [36];
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int iStack_54;
  int iStack_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  uint uVar17;
  
  uVar10 = param_1 + 0x218U & 3;
  uVar16 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar17 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20;
  uVar10 = (*(uint *)(uRam0207537c & 0xfffffffc) >> (uRam0207537c & 3) * 8 |
           *(uint *)(uRam0207537c & 0xfffffffc) << (uRam0207537c & 3) * -8 + 0x20) + 0xc;
  uVar16 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) == 5) {
    uVar10 = uVar17 + 0x2c & 3;
    uVar16 = *(uint *)(uVar17 + 0x2c & 0xfffffffc);
    *(short *)(param_1 + 0x210) =
         (short)((int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) >> 0xc) + -1;
    GetDriverMaybeSfxPosition((undefined4 *)(uintptr_t)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x210));
    uVar10 = param_1 + 0x218U & 3;
    uVar11 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
    uVar16 = param_1 + 0x1cU & 3;
    uVar15 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar10 = (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) + 0x1c;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) =
         (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) +
         (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20);
  }
  else {
    GetDriverMaybeSfxPosition((undefined4 *)(uintptr_t)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x210));
    uVar10 = param_1 + 0x1cU & 3;
    uVar16 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) + 0x6000;
  }
  iVar12 = GetDriverEntry(*(undefined2 *)(param_1 + 0x210));
  local_190 = *(int *)(iVar12 + 0x138);
  iStack_18c = *(int *)(iVar12 + 0x13c);
  iStack_188 = *(int *)(iVar12 + 0x140);
  uVar10 = uVar17 + 0x24 & 3;
  uVar16 = *(uint *)(uVar17 + 0x24 & 0xfffffffc);
  uVar16 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20;
  uVar10 = uVar17 + 0x18 & 3;
  uVar11 = *(uint *)(uVar17 + 0x18 & 0xfffffffc);
  uVar15 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  uVar10 = uVar17 + 0x1c & 3;
  uVar11 = *(uint *)(uVar17 + 0x1c & 0xfffffffc);
  uVar19 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  uVar10 = uVar17 + 0x28 & 3;
  uVar11 = *(uint *)(uVar17 + 0x28 & 0xfffffffc);
  uVar18 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  iVar13 = (int)(uint)*(ushort *)(iVar12 + 0x2c0) >> 4;
  uVar5 = (ulonglong)uRam02075380;
  iVar14 = ((int)uVar15 >> 0x1f) * uRam02075380;
  uVar6 = (ulonglong)uRam02075380;
  iVar1 = ((int)uVar19 >> 0x1f) * uRam02075380;
  uVar7 = (ulonglong)uRam02075380;
  iVar2 = ((int)uVar16 >> 0x1f) * uRam02075380;
  uVar8 = (ulonglong)uRam02075380;
  iVar3 = ((int)uVar18 >> 0x1f) * uRam02075380;
  func_02146f98((int *)(void *)(auStack_100),iVar12 + 0x120,(int)*(short *)(iRam02075384 + iVar13 * 4),
                (int)*(short *)(iRam02075384 + (iVar13 * 2 + 1) * 2));
  MTX_MultVec33((uint)(uintptr_t)(&local_190),(uint)(uintptr_t)(auStack_100),&local_190);
  local_34 = local_190;
  iStack_30 = iStack_18c;
  iStack_2c = iStack_188;
  local_58 = local_190;
  iStack_54 = iStack_18c;
  iStack_50 = iStack_188;
  local_184 = local_190;
  local_180 = iStack_18c;
  local_17c = iStack_188;
  uVar10 = uVar17 + 0x20 & 3;
  uVar11 = *(uint *)(uVar17 + 0x20 & 0xfffffffc);
  iVar13 = -(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
  local_4c = (uint)((longlong)local_190 * (longlong)iVar13) >> 0xc |
             (int)((ulonglong)((longlong)local_190 * (longlong)iVar13) >> 0x20) << 0x14;
  local_48 = (uint)((longlong)iStack_18c * (longlong)iVar13) >> 0xc |
             (int)((ulonglong)((longlong)iStack_18c * (longlong)iVar13) >> 0x20) << 0x14;
  local_44 = (uint)((longlong)iStack_188 * (longlong)iVar13) >> 0xc |
             (int)((ulonglong)((longlong)iStack_188 * (longlong)iVar13) >> 0x20) << 0x14;
  Vector3_Cross(uRam02075388,(uint)(uintptr_t)(&local_190),&local_70);
  Vector3_Cross((uint)(uintptr_t)(&local_58),(uint)(uintptr_t)(&local_70),&local_64);
  iVar9 = iRam02075384;
  iVar13 = (int)((iVar14 + uVar15 * 0xb6 + (int)(uVar5 * uVar15 >> 0x20) +
                 (uint)(0x7fffffff < (uint)(uVar5 * uVar15))) * 0x10 >> 0x10) >> 4;
  func_02146f98((int *)(void *)(auStack_148),(uint)(uintptr_t)(&local_64),(int)*(short *)(iRam02075384 + iVar13 * 4),
                (int)*(short *)(iRam02075384 + (iVar13 * 2 + 1) * 2));
  iVar13 = (int)((iVar1 + uVar19 * 0xb6 + (int)(uVar6 * uVar19 >> 0x20) +
                 (uint)(0x7fffffff < (uint)(uVar6 * uVar19))) * 0x10 >> 0x10) >> 4;
  func_02146f98((int *)(void *)(auStack_16c),(uint)(uintptr_t)(&local_70),(int)*(short *)(iVar9 + iVar13 * 4),
                (int)*(short *)(iVar9 + (iVar13 * 2 + 1) * 2));
  MTX_Concat33((uint)(uintptr_t)(auStack_16c),(uint *)(void *)(auStack_148),(uint *)(void *)(auStack_124));
  MTX_MultVec33((uint)(uintptr_t)(&local_184),(uint)(uintptr_t)(auStack_124),&local_184);
  uVar10 = uVar17 + 0x20 & 3;
  uVar17 = *(uint *)(uVar17 + 0x20 & 0xfffffffc);
  uVar10 = uVar17 >> uVar10 * 8 | uVar17 << uVar10 * -8 + 0x20;
  local_178 = (uint)((longlong)local_184 * (longlong)(int)uVar10) >> 0xc |
              (int)((ulonglong)((longlong)local_184 * (longlong)(int)uVar10) >> 0x20) << 0x14;
  local_174 = (uint)((longlong)local_180 * (longlong)(int)uVar10) >> 0xc |
              (int)((ulonglong)((longlong)local_180 * (longlong)(int)uVar10) >> 0x20) << 0x14;
  local_170 = (uint)((longlong)local_17c * (longlong)(int)uVar10) >> 0xc |
              (int)((ulonglong)((longlong)local_17c * (longlong)(int)uVar10) >> 0x20) << 0x14;
  VecFx32_Add(param_1 + 0x18,(uint)(uintptr_t)(&local_178),(int *)(uintptr_t)(param_1 + 0x24));
  iVar14 = iRam02075384;
  iVar13 = (int)((iVar2 + uVar16 * 0xb6 + (int)(uVar7 * uVar16 >> 0x20) +
                 (uint)(0x7fffffff < (uint)(uVar7 * uVar16))) * 0x10 >> 0x10) >> 4;
  local_70 = -local_70;
  local_6c = -local_6c;
  local_68 = -local_68;
  local_64 = -local_64;
  local_60 = -local_60;
  local_5c = -local_5c;
  func_02146f98(auStack_b8,&local_64,(int)*(short *)(iRam02075384 + iVar13 * 4),
                (int)*(short *)(iRam02075384 + (iVar13 * 2 + 1) * 2));
  iVar13 = (int)((iVar3 + uVar18 * 0xb6 + (int)(uVar8 * uVar18 >> 0x20) +
                 (uint)(0x7fffffff < (uint)(uVar8 * uVar18))) * 0x10 >> 0x10) >> 4;
  func_02146f98(auStack_dc,&local_70,(int)*(short *)(iVar14 + iVar13 * 4),
                (int)*(short *)(iVar14 + (iVar13 * 2 + 1) * 2));
  MTX_Concat33(auStack_b8,auStack_148,auStack_b8);
  MTX_Concat33(auStack_dc,auStack_16c,auStack_dc);
  MTX_Concat33(auStack_dc,auStack_b8,auStack_94);
  MTX_MultVec33(&local_4c,auStack_94,&local_4c);
  VecFx32_Add(param_1 + 0x24,&local_4c,param_1 + 0x18);
  uVar17 = uRam0207537c;
  uVar10 = param_1 + 0x1cU & 3;
  uVar15 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar16 = iVar12 + 700U & 3;
  uVar11 = *(uint *)(iVar12 + 700U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) =
       (uVar15 >> uVar10 * 8 | uVar15 << uVar10 * -8 + 0x20) -
       (uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20);
  uVar10 = iVar12 + 700U & 3;
  uVar11 = *(uint *)(iVar12 + 700U & 0xfffffffc);
  uVar16 = param_1 + 0x28U & 3;
  uVar15 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) -
       (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
  uVar10 = uVar17 & 3;
  uVar16 = *(uint *)(uVar17 & 0xfffffffc);
  uVar10 = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) + 8;
  uVar16 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20;
  if ((uVar10 != 4) && (uVar10 != 2)) {
    iVar13 = func_01ffdee4(param_1 + 0x24,param_1 + 0x134,0,
                           (int)(*(uint *)(uRam0207538c & 0xfffffffc) >> (uRam0207538c & 3) * 8 |
                                *(uint *)(uRam0207538c & 0xfffffffc) <<
                                (uRam0207538c & 3) * -8 + 0x20) >> 1,2,0xfffffffe,&local_40,0,0,0,0,
                           0,0,0);
    if (iVar13 != 0) {
      iVar13 = GetDriverEntry(*(undefined2 *)(param_1 + 0x210));
      iVar14 = Vector3_DotProduct(iVar13 + 0x120,&local_40);
      uVar10 = iVar13 + 0x120U & 3;
      uVar16 = *(uint *)(iVar13 + 0x120U & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) *
              (longlong)iVar14;
      local_40 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar10 = iVar13 + 0x124U & 3;
      uVar16 = *(uint *)(iVar13 + 0x124U & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) *
              (longlong)iVar14;
      local_3c = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      uVar10 = iVar13 + 0x128U & 3;
      uVar16 = *(uint *)(iVar13 + 0x128U & 0xfffffffc);
      lVar4 = (longlong)(int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) *
              (longlong)iVar14;
      local_38 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      VecFx32_Add(&local_40,param_1 + 0x24,param_1 + 0x24);
    }
  }
  StructHD_SomeLookAt(param_1);
  return;
}


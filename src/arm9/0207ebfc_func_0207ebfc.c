/* Decompiled C draft; module arm9; ROM address 0207ebfc. No matching claim. */
#include "types.h"
#include "deps/0207ebfc_func_0207ebfc.h"

void func_0207ebfc(uint param_1)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int local_54;
  int local_50;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined1 auStack_24 [12];
  uint uVar18;
  
  func_02080cc0(param_1 + 8);
  uVar4 = param_1 + 0x90 & 3;
  uVar3 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  uVar15 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 1) {
    uVar4 = uVar15 + 0x78 & 3;
    uVar3 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
    func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x100);
    *(undefined4 *)(param_1 + 0x90) = 2;
  }
  uVar4 = param_1 + 0x90 & 3;
  uVar3 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 4) {
    uVar4 = uVar15 + 0x44 & 3;
    uVar3 = *(uint *)(uVar15 + 0x44 & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 2) == 0) {
      *(undefined4 *)(param_1 + 0x90) = 0;
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    else {
      uVar4 = param_1 + 0x94 & 3;
      uVar3 = *(uint *)(param_1 + 0x94 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 == 1) {
        uVar4 = uVar15 + 0x48 & 3;
        uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
        *(uint *)(uVar15 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffef;
        uVar4 = uVar15 + 0x48 & 3;
        uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
        *(uint *)(uVar15 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 8;
      }
      else if (uVar4 == 2) {
        uVar4 = uVar15 + 0x48 & 3;
        uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
        *(uint *)(uVar15 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffff7;
        uVar4 = uVar15 + 0x48 & 3;
        uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
        *(uint *)(uVar15 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x10;
      }
    }
  }
  uVar4 = param_1 + 0x90 & 3;
  uVar3 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 == 3) &&
     (uVar3 = uVar15 + 0x44 & 3, uVar5 = *(uint *)(uVar15 + 0x44 & 0xfffffffc),
     ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x10) != 0)) {
    VecFx32_Subtract(param_1 + 0x44,uVar15 + 0x80,&local_54);
    iVar6 = Vector3_DotProduct(uVar15 + 300,(uint)(uintptr_t)(&local_54));
    uVar4 = uVar15 + 300 & 3;
    uVar3 = *(uint *)(uVar15 + 300 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)iVar6;
    local_54 = local_54 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar4 = uVar15 + 0x130 & 3;
    uVar3 = *(uint *)(uVar15 + 0x130 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)iVar6;
    local_50 = local_50 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar4 = uVar15 + 0x134 & 3;
    uVar3 = *(uint *)(uVar15 + 0x134 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)iVar6;
    local_4c = local_4c - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    Vector3_Cross(uVar15 + 0x138,(uint)(uintptr_t)(&local_54),(uint *)(void *)(auStack_24));
    uVar7 = VecFx32_Norm((uint)(uintptr_t)(auStack_24));
    uVar8 = VecFx32_CrossProduct_0(uVar15 + 0x138,(uint)(uintptr_t)(&local_54));
    uVar4 = func_02148538(uVar7,uVar8);
    iVar14 = ((int)uVar4 >> 0x1f) * uRam0207f04c +
             uVar4 * 0x39 + (int)((ulonglong)uRam0207f04c * (ulonglong)uVar4 >> 0x20) +
             (uint)(0x7fffffff < (uint)((ulonglong)uRam0207f04c * (ulonglong)uVar4));
    iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_24),uVar15 + 300);
    if (iVar6 < 0) {
      iVar14 = -iVar14;
    }
    uVar7 = AbsValue(iVar14);
    *(undefined4 *)(param_1 + 0x70) = uVar7;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    DriverContext_ApplyDriftBoost(uVar15);
    uVar4 = param_1 + 0x70 & 3;
    uVar3 = *(uint *)(param_1 + 0x70 & 0xfffffffc);
    iVar6 = AbsValue(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    if (0x32000 < iVar6) {
      VecFx32_Subtract(param_1 + 0x44,uVar15 + 0x80,&iStack_60);
      *(undefined4 *)(param_1 + 0x90) = 4;
      uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      StructMQRacerEntry_GetVec555(uVar4,&iStack_48);
      iVar6 = Vector3_DotProduct((uint)(uintptr_t)(&iStack_48),(uint)(uintptr_t)(&iStack_60));
      iStack_2c = iStack_5c -
                  ((uint)((longlong)iStack_44 * (longlong)iVar6) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_44 * (longlong)iVar6) >> 0x20) << 0x14);
      iStack_30 = iStack_60 -
                  ((uint)((longlong)iStack_48 * (longlong)iVar6) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_48 * (longlong)iVar6) >> 0x20) << 0x14);
      iStack_28 = iStack_58 -
                  ((uint)((longlong)iStack_40 * (longlong)iVar6) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_40 * (longlong)iVar6) >> 0x20) << 0x14);
      Vector3_Cross(uVar4 + 0x138,(uint)(uintptr_t)(&iStack_30),(uint *)(void *)(auStack_3c));
      iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&iStack_48),(uint)(uintptr_t)(auStack_3c));
      if (iVar6 < 1) {
        iVar6 = -1;
      }
      else {
        iVar6 = 1;
      }
      if (iVar6 < 1) {
        *(undefined4 *)(param_1 + 0x94) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x94) = 1;
      }
      uVar4 = uVar15 + 0x44 & 3;
      uVar3 = *(uint *)(uVar15 + 0x44 & 0xfffffffc);
      *(uint *)(uVar15 + 0x44) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x20000000;
      return;
    }
    return;
  }
  if (uVar4 != 2) {
    return;
  }
  uVar4 = uVar15 + 0x44 & 3;
  uVar3 = *(uint *)(uVar15 + 0x44 & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 2) != 0) {
    uVar4 = param_1 + 0x94 & 3;
    uVar3 = *(uint *)(param_1 + 0x94 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 == 1) {
      uVar4 = uVar15 + 0x48 & 3;
      uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
      *(uint *)(uVar15 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffef;
      uVar4 = uVar15 + 0x48 & 3;
      uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
      *(uint *)(uVar15 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 8;
    }
    else if (uVar4 == 2) {
      uVar4 = uVar15 + 0x48 & 3;
      uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
      *(uint *)(uVar15 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffff7;
      uVar4 = uVar15 + 0x48 & 3;
      uVar3 = *(uint *)(uVar15 + 0x48 & 0xfffffffc);
      *(uint *)(uVar15 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x10;
    }
  }
  uVar4 = uVar15 + 0x78 & 3;
  uVar3 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
  func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x100);
  uVar4 = param_1 + 0x98 & 3;
  uVar3 = *(uint *)(param_1 + 0x98 & 0xfffffffc);
  bVar2 = false;
  *(uint *)(param_1 + 0x98) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
  uVar4 = param_1 + 0x98 & 3;
  uVar3 = *(uint *)(param_1 + 0x98 & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0x28) &&
     (uVar4 = param_1 + 0xa0 & 3, uVar3 = *(uint *)(param_1 + 0xa0 & 0xfffffffc),
     uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0)) {
    piVar9 = (int *)func_0208537c();
    uVar4 = (uint)(piVar9 + 2) & 3;
    uVar3 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
    uVar13 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar12 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
             *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
    uVar4 = (uint)(piVar9 + 1) & 3;
    uVar10 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar12 * (ulonglong)uVar13;
    uVar16 = (uint)lVar1;
    uVar3 = (uint)(piVar9 + 3) & 3;
    uVar11 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
    uVar5 = (uint)(piVar9 + 4) & 3;
    uVar17 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
    uVar18 = uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20;
    uVar5 = (uint)(piVar9 + 5) & 3;
    uVar17 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
    *piVar9 = uVar18 + uVar16;
    piVar9[1] = (uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20) +
                (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) * uVar12 +
                uVar13 * (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar18,uVar16);
    uVar4 = (uint)(piVar9 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
    uVar3 = param_1 + 0x8c & 3;
    uVar10 = *(uint *)(param_1 + 0x8c & 0xfffffffc);
    if ((int)(short)((ushort)((ushort)((uVar5 >> uVar4 * 8) >> 0x10) |
                             (ushort)((uVar5 << uVar4 * -8 + 0x20) >> 0x10)) >> 4) <=
        (int)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20)) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    StructMQRacerEntry_SomeFn_73(uVar15,3);
  }
  uVar7 = puRam0207f050[1];
  uVar8 = puRam0207f050[2];
  *(undefined4 *)(param_1 + 0x60) = *puRam0207f050;
  *(undefined4 *)(param_1 + 100) = uVar7;
  *(undefined4 *)(param_1 + 0x68) = uVar8;
  *(undefined4 *)(param_1 + 0x74) = 0;
  uVar4 = uVar15 + 0x44 & 3;
  uVar3 = *(uint *)(uVar15 + 0x44 & 0xfffffffc);
  if ((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & uRam0207f054) == 0) &&
     (uVar4 = uVar15 + 0x2cc & 3, uVar3 = *(uint *)(uVar15 + 0x2cc & 0xfffffffc),
     uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10, uVar3 = uVar4 & 3,
     uVar4 = *(uint *)(uVar4 & 0xfffffffc), uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
     uVar4 = uVar15 + 0x2a4 & 3, uVar15 = *(uint *)(uVar15 + 0x2a4 & 0xfffffffc),
     lVar1 = (ulonglong)uRam0207f058 * (ulonglong)uVar3,
     (int)((uint)lVar1 >> 0xc |
          (((int)uVar3 >> 0x1f) * uRam0207f058 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000) <
     (int)(uVar15 >> uVar4 * 8 | uVar15 << uVar4 * -8 + 0x20))) {
    return;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}


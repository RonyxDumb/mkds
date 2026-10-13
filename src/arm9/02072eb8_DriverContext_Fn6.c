/* Decompiled C draft; module arm9; ROM address 02072eb8. No matching claim. */
#include "types.h"
#include "deps/02072eb8_DriverContext_Fn6.h"

void DriverContext_Fn6(int param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_70 [4];
  int local_6c;
  undefined1 auStack_64 [12];
  uint local_58;
  uint local_54;
  uint local_50;
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [40];
  
  uVar2 = param_1 + 0x3c4U & 3;
  uVar5 = *(uint *)(param_1 + 0x3c4U & 0xfffffffc);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 0xffffffff) {
    uVar2 = (*(uint *)(uRam020732a8 & 0xfffffffc) >> (uRam020732a8 & 3) * 8 |
            *(uint *)(uRam020732a8 & 0xfffffffc) << (uRam020732a8 & 3) * -8 + 0x20) + 8;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 2) {
      uVar3 = GetCourseCpoiRespawnId(0);
    }
    else {
      uVar3 = GetCourseCpoiRespawnId
                        (*(undefined2 *)
                          ((uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                           (*(uint *)(uRam020732ac & 0xfffffffc) >> (uRam020732ac & 3) * 8 |
                           *(uint *)(uRam020732ac & 0xfffffffc) << (uRam020732ac & 3) * -8 + 0x20) +
                          0x46));
    }
    *(undefined4 *)(param_1 + 0x3c4) = uVar3;
  }
  uVar5 = param_1 + 0x3c4U & 3;
  uVar8 = *(uint *)(param_1 + 0x3c4U & 0xfffffffc);
  uVar2 = (*(uint *)(uRam020732a8 & 0xfffffffc) >> (uRam020732a8 & 3) * 8 |
          *(uint *)(uRam020732a8 & 0xfffffffc) << (uRam020732a8 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar2 & 3;
  uVar6 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffff;
  if ((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) == 2) {
    uVar3 = func_02040fd8(uVar2,(uint *)(void *)(auStack_70),&local_58);
  }
  else {
    uVar3 = func_020410a4(uVar2,(uint *)(void *)(auStack_70),&local_58);
  }
  iVar7 = (int)((((int)local_54 >> 0x1f) * uRam020732b0 +
                 local_54 * 0xb6 + (int)((ulonglong)uRam020732b0 * (ulonglong)local_54 >> 0x20) +
                (uint)(0x7fffffff < (uint)((ulonglong)uRam020732b0 * (ulonglong)local_54))) * 0x10
               >> 0x10) >> 4;
  MTX_RotY33__from_thumb
            ((undefined4 *)(void *)(auStack_40),(int)*(short *)(iRam020732b4 + iVar7 * 4),
             (int)*(short *)(iRam020732b4 + (iVar7 * 2 + 1) * 2));
  MTX_MultVec33(uRam020732b8,(uint)(uintptr_t)(auStack_40),(uint *)(void *)(auStack_64));
  uVar2 = (*(uint *)(uRam020732a8 & 0xfffffffc) >> (uRam020732a8 & 3) * 8 |
          *(uint *)(uRam020732a8 & 0xfffffffc) << (uRam020732a8 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) != 2) &&
     (*(short *)((*(uint *)(uRam020732bc & 0xfffffffc) >> (uRam020732bc & 3) * 8 |
                 *(uint *)(uRam020732bc & 0xfffffffc) << (uRam020732bc & 3) * -8 + 0x20) + 0x60) !=
      0)) {
    uVar2 = param_1 + 0x3c4U & 3;
    uVar5 = *(uint *)(param_1 + 0x3c4U & 0xfffffffc);
    uVar4 = func_02040f78((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xffff);
    iVar7 = (uint)*(ushort *)(param_1 + 0x74) * 0x210 +
            (*(uint *)(uRam020732c0 & 0xfffffffc) >> (uRam020732c0 & 3) * 8 |
            *(uint *)(uRam020732c0 & 0xfffffffc) << (uRam020732c0 & 3) * -8 + 0x20);
    *(undefined4 *)(iVar7 + 0x1f0) = uVar4;
    *(undefined4 *)(iVar7 + 500) = 1;
  }
  uVar2 = (*(uint *)(uRam020732a8 & 0xfffffffc) >> (uRam020732a8 & 3) * 8 |
          *(uint *)(uRam020732a8 & 0xfffffffc) << (uRam020732a8 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) != 1) {
    uVar2 = iRam020732c4 + (uint)*(ushort *)(param_1 + 0x74) * 8;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar9 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar2 = iRam020732c8 + (uint)*(ushort *)(param_1 + 0x74) * 8;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    Vector3_Cross(uRam020732cc,(uint)(uintptr_t)(auStack_64),(uint *)(void *)(auStack_4c));
    lVar1 = (longlong)
            (int)(*(uint *)(uRam020732d0 & 0xfffffffc) >> (uRam020732d0 & 3) * 8 |
                 *(uint *)(uRam020732d0 & 0xfffffffc) << (uRam020732d0 & 3) * -8 + 0x20) *
            (longlong)(int)uVar9;
    VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,(uint)(uintptr_t)(auStack_4c),
                      (uint)(uintptr_t)(auStack_70),(int *)(void *)(auStack_70));
    lVar1 = (longlong)
            (int)(*(uint *)(uRam020732d0 & 0xfffffffc) >> (uRam020732d0 & 3) * 8 |
                 *(uint *)(uRam020732d0 & 0xfffffffc) << (uRam020732d0 & 3) * -8 + 0x20) *
            (longlong)(int)uVar2;
    VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,(uint)(uintptr_t)(auStack_64),
                      (uint)(uintptr_t)(auStack_70),(int *)(void *)(auStack_70));
    if ((local_58 != 0) && (uVar2 != 0)) {
      lVar1 = (longlong)
              (int)*(short *)(iRam020732b4 +
                             ((int)((((int)local_58 >> 0x1f) * uRam020732b0 +
                                     local_58 * 0xb6 +
                                     (int)((ulonglong)uRam020732b0 * (ulonglong)local_58 >> 0x20) +
                                    (uint)(0x7fffffff <
                                          (uint)((ulonglong)uRam020732b0 * (ulonglong)local_58))) *
                                    0x10 >> 0x10) >> 4) * 4) * (longlong)(int)-uVar2 + 0x800;
      lVar1 = (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) *
              (longlong)
              (int)(*(uint *)(uRam020732d0 & 0xfffffffc) >> (uRam020732d0 & 3) * 8 |
                   *(uint *)(uRam020732d0 & 0xfffffffc) << (uRam020732d0 & 3) * -8 + 0x20) + 0x800;
      local_6c = local_6c + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    }
    if ((local_50 != 0) && (uVar9 != 0)) {
      uVar2 = (uint)*(short *)(iRam020732b4 +
                              ((int)((((int)local_50 >> 0x1f) * uRam020732b0 +
                                      local_50 * 0xb6 +
                                      (int)((ulonglong)uRam020732b0 * (ulonglong)local_50 >> 0x20) +
                                     (uint)(0x7fffffff <
                                           (uint)((ulonglong)uRam020732b0 * (ulonglong)local_50))) *
                                     0x10 >> 0x10) >> 4) * 4);
      uVar5 = (uint)((ulonglong)uVar9 * (ulonglong)uVar2);
      lVar1 = (longlong)
              (int)(uVar5 + 0x800 >> 0xc |
                   (((int)uVar2 >> 0x1f) * uVar9 +
                    uVar2 * ((int)uVar9 >> 0x1f) +
                    (int)((ulonglong)uVar9 * (ulonglong)uVar2 >> 0x20) + (uint)(0xfffff7ff < uVar5))
                   * 0x100000) *
              (longlong)
              (int)(*(uint *)(uRam020732d0 & 0xfffffffc) >> (uRam020732d0 & 3) * 8 |
                   *(uint *)(uRam020732d0 & 0xfffffffc) << (uRam020732d0 & 3) * -8 + 0x20) + 0x800;
      local_6c = local_6c + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    }
  }
  local_6c = local_6c + 0x28000;
  uVar2 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x800000) == 0) {
    if ((uVar2 & 0x1000000) != 0) {
      uVar4 = func_0208b7bc(0x70,(uint)(uintptr_t)(auStack_70));
      func_02081f10(uVar4,*(undefined2 *)(param_1 + 0x74),0x32);
    }
  }
  else {
    uVar4 = func_0208b7bc(0x71,(uint)(uintptr_t)(auStack_70));
    func_02081f10(uVar4,*(undefined2 *)(param_1 + 0x74),0x32);
  }
  StructMQRacerEntry_SomeFn_63(param_1,(undefined4 *)(void *)(auStack_70),(uint)(uintptr_t)(auStack_64),uVar3);
  uVar2 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 1) == 0) {
    func_0210b850(param_1 + iRam020732d4);
  }
  else {
    iVar7 = GetGlobalRK();
    uVar2 = iVar7 + 0x18U & 3;
    uVar5 = *(uint *)(iVar7 + 0x18U & 0xfffffffc);
    *(uint *)(iVar7 + 0x18) = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 1;
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 0xc00;
  uVar2 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 0x2000000;
  uVar2 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 1) != 0) {
    func_02055bd4(0x3c);
    func_02075d08(0);
    return;
  }
  return;
}


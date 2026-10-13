/* Decompiled C draft; module arm9; ROM address 020fc2e8. No matching claim. */
#include "types.h"
#include "deps/020fc2e8_func_020fc2e8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020fc2e8(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  int local_48;
  int local_44;
  int local_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  uint uVar6;
  uint uVar8;
  
  puVar11 = (undefined4 *)(param_1 + 0x28c);
  puVar10 = (uint *)(param_1 + 0x298);
  if (param_4 == 0) {
    uVar8 = (uint)(param_2 + 1) & 3;
    uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    uVar6 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    uVar8 = (uint)(param_2 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
            (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(param_2),&local_48);
    }
    if (local_48 * local_48 + local_40 * local_40 < iRam020fc64c) {
      return;
    }
    *(int *)(param_1 + 0xac) = local_48;
    *(int *)(param_1 + 0xb0) = local_44;
    *(int *)(param_1 + 0xb4) = local_40;
    if (param_3 == 0) {
      uVar8 = *(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
              *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uVar8 * 0xc00;
      *puVar10 = (uint)lVar1 >> 0xc |
                 (((int)uVar8 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar8 = param_1 + 0x2a0U & 3;
      uVar5 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
      uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
      lVar1 = (ulonglong)uVar8 * 0xc00;
      *(uint *)(param_1 + 0x2a0) =
           (uint)lVar1 >> 0xc |
           (((int)uVar8 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    }
    else {
      uVar8 = *(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
              *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20;
      uVar5 = ((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) -
              (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
              *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20)) - uVar8;
      lVar1 = (ulonglong)uVar5 * 0x148;
      *puVar10 = uVar8 + ((uint)lVar1 >> 0xc |
                         (((int)uVar5 >> 0x1f) * 0x148 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000
                         );
      uVar8 = (uint)(param_2 + 2) & 3;
      uVar12 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      uVar5 = param_1 + 0x294U & 3;
      uVar9 = *(uint *)(param_1 + 0x294U & 0xfffffffc);
      uVar6 = param_1 + 0x2a0U & 3;
      uVar7 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      uVar8 = ((uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) -
              (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) - uVar6;
      lVar1 = (ulonglong)uVar8 * 0x148;
      *(uint *)(param_1 + 0x2a0) =
           uVar6 + ((uint)lVar1 >> 0xc |
                   (((int)uVar8 >> 0x1f) * 0x148 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    }
    uStack_38 = *(undefined4 *)(iRam020fc650 + 4);
    lVar1 = (ulonglong)
            (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) * 0x3000;
    uStack_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    uVar8 = param_1 + 0x2a0U & 3;
    uVar5 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * 0x3000;
    uStack_34 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    Vector3_Cross((uint)(uintptr_t)(&local_48),param_1 + 0xac,(uint *)(uintptr_t)(param_1 + 0x94));
    uVar8 = param_1 + 0x98U & 3;
    uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
    uVar6 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x94U & 3;
    uVar5 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar5 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x9cU & 3;
    uVar7 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    iVar2 = 0;
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
            (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar2 = Vector3_MaybeNormalize(param_1 + 0x94,(int *)(uintptr_t)(param_1 + 0x94));
    }
    if (iVar2 == 0) {
      uStack_2c = 0;
      uVar8 = param_1 + 0x9cU & 3;
      uVar5 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uStack_30 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 0x94U & 3;
      uVar5 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
      iStack_28 = -(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
      *(uint *)(param_1 + 0x94) = uStack_30;
      *(undefined4 *)(param_1 + 0x98) = 0;
      *(int *)(param_1 + 0x9c) = iStack_28;
    }
  }
  else {
    uVar8 = (uint)(param_2 + 1) & 3;
    uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    uVar6 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar5 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    uVar8 = (uint)(param_2 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
            (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(param_2),(int *)(uintptr_t)(param_1 + 0xac));
    }
    uVar5 = uRam020fc648;
    uVar8 = *(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20;
    lVar1 = (ulonglong)uRam020fc648 * (ulonglong)uVar8;
    *puVar10 = (uint)lVar1 >> 0xc |
               (((int)uVar8 >> 0x1f) * uRam020fc648 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar8 = param_1 + 0x29cU & 3;
    uVar6 = *(uint *)(param_1 + 0x29cU & 0xfffffffc);
    uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar8;
    *(uint *)(param_1 + 0x29c) =
         (uint)lVar1 >> 0xc |
         (((int)uVar8 >> 0x1f) * uVar5 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar8 = param_1 + 0x2a0U & 3;
    uVar6 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar8;
    *(uint *)(param_1 + 0x2a0) =
         (uint)lVar1 >> 0xc |
         (((int)uVar8 >> 0x1f) * uVar5 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    VecFx32_AddScale1(0x3000,(uint)(uintptr_t)(puVar10),param_4,&local_48);
    Vector3_Cross((uint)(uintptr_t)(&local_48),param_1 + 0xac,&local_48);
    lVar1 = (longlong)local_40 * (longlong)local_40 +
            (longlong)local_48 * (longlong)local_48 + (longlong)local_44 * (longlong)local_44;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&local_48),(int *)(uintptr_t)(param_1 + 0x94));
    }
  }
  Vector3_Cross(param_1 + 0xac,param_1 + 0x94,(uint *)(uintptr_t)(param_1 + 0xa0));
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *puVar11 = *param_2;
  *(undefined4 *)(param_1 + 0x290) = uVar3;
  *(undefined4 *)(param_1 + 0x294) = uVar4;
  return;
}


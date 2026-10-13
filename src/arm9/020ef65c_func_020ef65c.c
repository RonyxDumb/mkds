/* Decompiled C draft; module arm9; ROM address 020ef65c. No matching claim. */
#include "types.h"
#include "deps/020ef65c_func_020ef65c.h"

void func_020ef65c(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int local_30;
  int local_2c;
  int local_28;
  
  local_30 = *(int *)(param_1 + 0x44);
  local_2c = *(int *)(param_1 + 0x48);
  local_28 = *(int *)(param_1 + 0x4c);
  uVar3 = param_1 + 0x80U & 3;
  uVar2 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  puVar7 = (uint *)(param_1 + 0x90);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    VecFx32_AddScale1(uRam020ef8ac,param_1 + 0x6c,&local_30);
  }
  uVar2 = uRam020ef8b0;
  uVar3 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
  lVar1 = (ulonglong)uRam020ef8b0 * (ulonglong)uVar3;
  *puVar7 = (uint)lVar1 >> 0xc |
            (((int)uVar3 >> 0x1f) * uRam020ef8b0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = uRam020ef8b4;
  uVar3 = param_1 + 0x94U & 3;
  uVar5 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar3;
  *(uint *)(param_1 + 0x94) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar3;
  *(uint *)(param_1 + 0x98) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  VecFx32_AddScale1(uVar4,(uint)(uintptr_t)(&local_30),(uint)(uintptr_t)(puVar7),puVar7);
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar2 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
  uVar3 = param_1 + 0x98U & 3;
  uVar4 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
          (longlong)(int)uVar2 * (longlong)(int)uVar2 + (longlong)(int)uVar5 * (longlong)(int)uVar5;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(puVar7),&local_30);
  }
  *(int *)(param_1 + 0x9c) = -local_30;
  *(int *)(param_1 + 0xa0) = -local_2c;
  *(int *)(param_1 + 0xa4) = -local_28;
  uVar3 = param_1 + 0x8cU & 3;
  uVar2 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x78U & 3;
  uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  VecFx32_AddScale1((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
                    ((uVar2 << 0xe) >> 0xc | (uVar2 >> 0x12) << 0x14),param_1 + 0x9c,param_1 + 0x50,
                    (int *)(uintptr_t)(param_3));
  uVar3 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 2) {
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    lVar1 = (ulonglong)uRam020ef8bc * (ulonglong)uVar2;
    uVar3 = param_1 + 0xe4U & 3;
    uVar4 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
    *(uint *)(param_1 + 0xe4) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar2 >> 0x1f) * uRam020ef8bc + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar3 = param_1 + 0xe4U & 3;
    uVar2 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_1 + 0xe4) =
         uVar3 - ((uint)((ulonglong)uRam020ef8c0 * (ulonglong)uVar3) >> 0xc |
                 (((int)uVar3 >> 0x1f) * uRam020ef8c0 +
                 (int)((ulonglong)uRam020ef8c0 * (ulonglong)uVar3 >> 0x20)) * 0x100000);
  }
  else {
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    lVar1 = (ulonglong)uRam020ef8b4 * (ulonglong)uVar2;
    uVar3 = param_1 + 0xe4U & 3;
    uVar4 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
    *(uint *)(param_1 + 0xe4) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar2 >> 0x1f) * uRam020ef8b4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar3 = param_1 + 0xe4U & 3;
    uVar2 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_1 + 0xe4) =
         uVar3 - ((uint)((ulonglong)uRam020ef8b8 * (ulonglong)uVar3) >> 0xc |
                 (((int)uVar3 >> 0x1f) * uRam020ef8b8 +
                 (int)((ulonglong)uRam020ef8b8 * (ulonglong)uVar3 >> 0x20)) * 0x100000);
  }
  uVar3 = param_1 + 0xe8U & 3;
  uVar6 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  uVar2 = param_1 + 0x8cU & 3;
  uVar5 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar4 = param_1 + 0xe4U & 3;
  uVar8 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  uVar3 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  VecFx32_AddScale1(((uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) -
                    (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) +
                    ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14),param_1 + 0x38,
                    param_3,(int *)(uintptr_t)(param_2));
  return;
}


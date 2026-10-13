/* Decompiled C draft; module arm9; ROM address 020f6be8. No matching claim. */
#include "types.h"
#include "deps/020f6be8_func_020f6be8.h"

void func_020f6be8(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined1 auStack_24 [16];
  
  VecFx32_Subtract(param_3,param_1 + 0x5c,(int *)(void *)(auStack_24));
  VecFx32_Subtract(param_1 + 0x50,param_2,&local_30);
  iVar2 = Vector3_DotProduct(param_4,(uint)(uintptr_t)(&local_30));
  lVar1 = (longlong)
          (int)(*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
               *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) * (longlong)iVar2;
  local_30 = local_30 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_4 + 4 & 3;
  uVar6 = *(uint *)(param_4 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  local_2c = local_2c - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_4 + 8 & 3;
  uVar6 = *(uint *)(param_4 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  local_28 = local_28 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  lVar1 = (longlong)(int)local_28 * (longlong)(int)local_28 +
          (longlong)(int)local_30 * (longlong)(int)local_30 +
          (longlong)(int)local_2c * (longlong)(int)local_2c;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_30),&local_30);
  }
  uVar6 = uRam020f6e54;
  uVar4 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x8000) != 0) {
    VecFx32_AddScale1(uRam020f6e48,(uint)(uintptr_t)(auStack_24),param_1 + 0x5c,(int *)(uintptr_t)(param_1 + 0x5c));
    uVar6 = uRam020f6e50;
    uVar4 = uRam020f6e4c;
    puVar5 = (uint *)(*(uint *)(uRam020f6e50 & 0xfffffffc) >> (uRam020f6e50 & 3) * 8 |
                     *(uint *)(uRam020f6e50 & 0xfffffffc) << (uRam020f6e50 & 3) * -8 + 0x20);
    *puVar5 = (uint)((ulonglong)uRam020f6e4c * (ulonglong)local_30) >> 0xc |
              (((int)local_30 >> 0x1f) * uRam020f6e4c +
              (int)((ulonglong)uRam020f6e4c * (ulonglong)local_30 >> 0x20)) * 0x100000;
    puVar5[1] = (uint)((ulonglong)uVar4 * (ulonglong)local_2c) >> 0xc |
                (((int)local_2c >> 0x1f) * uVar4 +
                (int)((ulonglong)uVar4 * (ulonglong)local_2c >> 0x20)) * 0x100000;
    puVar5[2] = (uint)((ulonglong)uVar4 * (ulonglong)local_28) >> 0xc |
                (((int)local_28 >> 0x1f) * uVar4 +
                (int)((ulonglong)uVar4 * (ulonglong)local_28 >> 0x20)) * 0x100000;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    VecFx32_Add(param_1 + 0x5c,uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20,(int *)(uintptr_t)(param_1 + 0x5c));
    return;
  }
  uVar4 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  lVar1 = (ulonglong)uRam020f6e54 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x5c) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uRam020f6e54 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_3 + 4 & 3;
  uVar3 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x60) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_3 + 8 & 3;
  uVar3 = *(uint *)(param_3 + 8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar4;
  *(uint *)(param_1 + 100) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar6 = uRam020f6e50;
  puVar5 = (uint *)(*(uint *)(uRam020f6e50 & 0xfffffffc) >> (uRam020f6e50 & 3) * 8 |
                   *(uint *)(uRam020f6e50 & 0xfffffffc) << (uRam020f6e50 & 3) * -8 + 0x20);
  *puVar5 = (uint)((ulonglong)local_30 * 0x1800) >> 0xc |
            (((int)local_30 >> 0x1f) * 0x1800 + (int)((ulonglong)local_30 * 0x1800 >> 0x20)) *
            0x100000;
  puVar5[1] = (uint)((ulonglong)local_2c * 0x1800) >> 0xc |
              (((int)local_2c >> 0x1f) * 0x1800 + (int)((ulonglong)local_2c * 0x1800 >> 0x20)) *
              0x100000;
  puVar5[2] = (uint)((ulonglong)local_28 * 0x1800) >> 0xc |
              (((int)local_28 >> 0x1f) * 0x1800 + (int)((ulonglong)local_28 * 0x1800 >> 0x20)) *
              0x100000;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  VecFx32_Add(param_1 + 0x5c,uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20,(int *)(uintptr_t)(param_1 + 0x5c));
  return;
}


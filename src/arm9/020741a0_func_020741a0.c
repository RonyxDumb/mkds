/* Decompiled C draft; module arm9; ROM address 020741a0. No matching claim. */
#include "types.h"
#include "deps/020741a0_func_020741a0.h"

void func_020741a0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                  int *param_6,int param_7)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_c4 [4];
  undefined4 local_c0;
  undefined1 auStack_b8 [12];
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int iStack_9c;
  int iStack_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 uStack_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  int local_68;
  undefined4 local_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_ac = *param_6;
  local_a8 = param_6[1];
  local_a4 = param_6[2];
  uVar2 = param_3 + 0xdcU & 3;
  uVar5 = *(uint *)(param_3 + 0xdcU & 0xfffffffc);
  iVar6 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) - param_7;
  StructMQRacerEntry_GetVec555(param_4,(uint *)(void *)(auStack_b8));
  if (iVar6 < 500) {
    iVar6 = 500;
  }
  VecFx32_Subtract(param_4 + 0x80,param_4 + 0x8c,(int *)(void *)(auStack_c4));
  uVar2 = param_4 + 0x48U & 3;
  uVar5 = *(uint *)(param_4 + 0x48U & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x1000) != 0) {
    uVar2 = param_4 + 0x4cU & 3;
    uVar5 = *(uint *)(param_4 + 0x4cU & 0xfffffffc);
    if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x4000000) == 0) {
      uVar2 = param_3 + 0x88U & 3;
      uVar5 = *(uint *)(param_3 + 0x88U & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      lVar1 = (ulonglong)uRam020745c0 * (ulonglong)uVar2;
      *(uint *)(param_3 + 0x88) =
           (uint)lVar1 >> 0xc |
           (((int)uVar2 >> 0x1f) * uRam020745c0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar2 = param_3 + 0x88U & 3;
      uVar5 = *(uint *)(param_3 + 0x88U & 0xfffffffc);
      VecFx32_AddScale1(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,(uint)(uintptr_t)(auStack_c4),param_1,(int *)(uintptr_t)(param_1));
      return;
    }
    return;
  }
  local_c0 = 0;
  VecFx32_Add(param_1,(uint)(uintptr_t)(auStack_c4),(int *)(uintptr_t)(param_1));
  iVar6 = -iVar6;
  local_7c = (uint)((longlong)local_ac * (longlong)iVar6) >> 0xc |
             (int)((ulonglong)((longlong)local_ac * (longlong)iVar6) >> 0x20) << 0x14;
  local_78 = (uint)((longlong)local_a8 * (longlong)iVar6) >> 0xc |
             (int)((ulonglong)((longlong)local_a8 * (longlong)iVar6) >> 0x20) << 0x14;
  local_74 = (uint)((longlong)local_a4 * (longlong)iVar6) >> 0xc |
             (int)((ulonglong)((longlong)local_a4 * (longlong)iVar6) >> 0x20) << 0x14;
  VecFx32_Add((uint)(uintptr_t)(&local_7c),param_3 + 0x188,&local_7c);
  VecFx32_Add((uint)(uintptr_t)(&local_7c),param_3 + 0x17c,&local_7c);
  VecFx32_AddScale1(*(uint *)(uRam020745c4 & 0xfffffffc) >> (uRam020745c4 & 3) * 8 |
                    *(uint *)(uRam020745c4 & 0xfffffffc) << (uRam020745c4 & 3) * -8 + 0x20,
                    (uint)(uintptr_t)(auStack_b8),(uint)(uintptr_t)(&local_7c),(int *)(void *)(auStack_4c));
  VecFx32_Add(param_5,(uint)(uintptr_t)(auStack_4c),(int *)(void *)(auStack_58));
  local_78 = *(uint *)(uRam020745c4 & 0xfffffffc) >> (uRam020745c4 & 3) * 8 |
             *(uint *)(uRam020745c4 & 0xfffffffc) << (uRam020745c4 & 3) * -8 + 0x20;
  VecFx32_Add(param_5,(uint)(uintptr_t)(&local_7c),&local_64);
  local_88 = local_64;
  uStack_80 = uStack_5c;
  uVar2 = param_3 + 0x168U & 3;
  uVar5 = *(uint *)(param_3 + 0x168U & 0xfffffffc);
  local_84 = iStack_60 + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  uVar2 = param_4 + 0x48U & 3;
  uVar5 = *(uint *)(param_4 + 0x48U & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x40000000) == 0) {
    uStack_40 = *puRam020745c8;
    uStack_3c = puRam020745c8[1];
    uStack_38 = puRam020745c8[2];
  }
  else {
    VecFx32_Subtract((uint)(uintptr_t)(auStack_58),(uint)(uintptr_t)(&local_88),&uStack_40);
    VecFx32_AddScale1(0xfffe2000,(uint)(uintptr_t)(auStack_b8),(uint)(uintptr_t)(&uStack_40),&uStack_40);
  }
  VecFx32_Subtract((uint)(uintptr_t)(&uStack_40),param_2,&local_34);
  local_34 = (uint)((ulonglong)uRam020745cc * (ulonglong)local_34) >> 0xc |
             (((int)local_34 >> 0x1f) * uRam020745cc +
             (int)((ulonglong)uRam020745cc * (ulonglong)local_34 >> 0x20)) * 0x100000;
  local_30 = (uint)((ulonglong)uRam020745cc * (ulonglong)local_30) >> 0xc |
             (((int)local_30 >> 0x1f) * uRam020745cc +
             (int)((ulonglong)uRam020745cc * (ulonglong)local_30 >> 0x20)) * 0x100000;
  local_2c = (uint)((ulonglong)uRam020745cc * (ulonglong)local_2c) >> 0xc |
             (((int)local_2c >> 0x1f) * uRam020745cc +
             (int)((ulonglong)uRam020745cc * (ulonglong)local_2c >> 0x20)) * 0x100000;
  VecFx32_Add(param_2,&local_34,param_2);
  VecFx32_Add(&local_88,param_2,&local_88);
  VecFx32_Subtract(&local_88,param_1,&local_70);
  uVar2 = local_6c;
  uVar5 = 0;
  lVar1 = (longlong)local_68 * (longlong)local_68 + (longlong)local_70 * (longlong)local_70;
  local_6c = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar5 = Vector3_MaybeNormalize(&local_70,&local_70);
  }
  VecFx32_AddScale1((uint)((ulonglong)uRam020745d0 * (ulonglong)uVar5) >> 0xc |
                    (((int)uVar5 >> 0x1f) * uRam020745d0 +
                    (int)((ulonglong)uRam020745d0 * (ulonglong)uVar5 >> 0x20)) * 0x100000,&local_70,
                    param_1,param_1);
  lVar1 = (ulonglong)uRam020745d0 * (ulonglong)uVar2;
  uVar5 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(param_1 + 4) =
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) +
       ((uint)lVar1 >> 9 |
       (((int)uVar2 >> 0x1f) * uRam020745d0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x800000) +
       param_7 * 2;
  uVar2 = param_3 + 0x248U & 3;
  uVar5 = *(uint *)(param_3 + 0x248U & 0xfffffffc);
  if (uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) {
    uVar2 = param_3 + 0xd0U & 3;
    uVar5 = *(uint *)(param_3 + 0xd0U & 0xfffffffc);
    if (uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) {
      uVar2 = param_3 + 0xccU & 3;
      uVar5 = *(uint *)(param_3 + 0xccU & 0xfffffffc);
      uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar2 = param_1 + 4U & 3;
      uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - uVar5;
      lVar1 = (ulonglong)uVar2 * 0x29;
      uVar3 = (uint)lVar1;
      *(uint *)(param_3 + 0xcc) =
           uVar5 + (uVar3 + 0x800 >> 0xc |
                   (((int)uVar2 >> 0x1f) * 0x29 + (int)((ulonglong)lVar1 >> 0x20) +
                   (uint)(0xfffff7ff < uVar3)) * 0x100000);
    }
    uVar2 = param_3 + 0xccU & 3;
    uVar5 = *(uint *)(param_3 + 0xccU & 0xfffffffc);
    *(uint *)(param_1 + 4) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  }
  VecFx32_Subtract(param_1,param_5,&local_a0);
  local_94 = local_a0;
  local_90 = iStack_9c;
  local_8c = iStack_98;
  lVar1 = (longlong)iStack_98 * (longlong)iStack_98 +
          (longlong)local_a0 * (longlong)local_a0 + (longlong)iStack_9c * (longlong)iStack_9c;
  iVar6 = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    iVar6 = Vector3_MaybeNormalize(&local_94,&local_94);
  }
  if (iVar6 != 0) {
    uVar2 = param_3 + 0xdcU & 3;
    uVar4 = *(uint *)(param_3 + 0xdcU & 0xfffffffc);
    uVar5 = param_3 + 0xe8U & 3;
    uVar3 = *(uint *)(param_3 + 0xe8U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) *
            (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,&local_94,param_5
                      ,param_1);
    return;
  }
  return;
}


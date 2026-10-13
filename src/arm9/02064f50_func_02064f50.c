/* Decompiled C draft; module arm9; ROM address 02064f50. No matching claim. */
#include "types.h"
#include "deps/02064f50_func_02064f50.h"

void func_02064f50(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar9;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [12];
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [12];
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined4 *puVar8;
  
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar4 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  puVar8 = (undefined4 *)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x20) == 0) {
    uVar5 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x20;
    bVar9 = uVar5 != 0;
    if (bVar9) {
      uVar5 = param_1 + 0x44U & 3;
      uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    }
    if (bVar9) {
      *(uint *)(param_1 + 0x44) = uVar5 | 0x80000;
    }
    else {
      uVar5 = param_1 + 0x44U & 3;
      uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfff7ffff;
    }
    func_01ffc064(param_1 + 0x1b8,param_1 + 0x80,0x400,param_1);
    func_01ffa4b4(param_1,&uStack_64);
    StructMQRacerEntry_SomeFn_84(param_1,&uStack_64);
    *(undefined4 *)(param_1 + 0x244) = uStack_64;
    *(undefined4 *)(param_1 + 0x248) = uStack_60;
    *(undefined4 *)(param_1 + 0x24c) = uStack_5c;
    uVar5 = param_1 + 0x4d0U & 3;
    uVar4 = *(uint *)(param_1 + 0x4d0U & 0xfffffffc);
    *(uint *)(param_1 + 0x4d0) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 1;
    func_01ffc920(param_1);
    func_01ffc8cc(param_1);
    uVar5 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x8000) != 0) {
      StructMQRacerEntry_SomeFn_61(param_1);
    }
    uVar5 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 8) != 0) {
      StructMQRacerEntry_SomeFn_85(param_1);
    }
    uVar5 = param_1 + 0x230U & 3;
    uVar4 = *(uint *)(param_1 + 0x230U & 0xfffffffc);
    (*(code *)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))(param_1);
    uStack_58 = *(undefined4 *)(param_1 + 0x80);
    uStack_50 = *(undefined4 *)(param_1 + 0x88);
    uVar5 = (uint)(puVar8 + 0x18) & 3;
    uVar4 = *(uint *)((uint)(puVar8 + 0x18) & 0xfffffffc);
    iStack_54 = *(int *)(param_1 + 0x84) - (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    uVar5 = (uint)(puVar8 + 9) & 3;
    uVar4 = *(uint *)((uint)(puVar8 + 9) & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    VecFx32_Subtract((uint)(uintptr_t)(&uStack_58),(uint)(uintptr_t)(puVar8),&uStack_28);
    uStack_28 = (uint)((longlong)(int)uStack_28 * (longlong)(int)uVar5) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_28 * (longlong)(int)uVar5) >> 0x20) << 0x14;
    uStack_24 = (uint)((longlong)(int)uStack_24 * (longlong)(int)uVar5) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_24 * (longlong)(int)uVar5) >> 0x20) << 0x14;
    uStack_20 = (uint)((longlong)(int)uStack_20 * (longlong)(int)uVar5) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_20 * (longlong)(int)uVar5) >> 0x20) << 0x14;
    VecFx32_Add((uint)(uintptr_t)(puVar8),(uint)(uintptr_t)(&uStack_28),puVar8);
    uVar5 = param_1 + 0x514U & 3;
    uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x44;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) != 0) {
      func_01ffc064((undefined4)(uintptr_t)(auStack_34),(undefined4)(uintptr_t)(puVar8),0x400,param_1);
      uVar5 = param_1 + 300U & 3;
      uVar4 = *(uint *)(param_1 + 300U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uVar5 * 0xffff9000;
      uStack_40 = (uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar5) * 0x100000;
      uVar5 = param_1 + 0x130U & 3;
      uVar4 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uVar5 * 0xffff9000;
      uStack_3c = (uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar5) * 0x100000;
      uVar5 = param_1 + 0x134U & 3;
      uVar4 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      lVar1 = (ulonglong)uVar5 * 0xffff9000;
      uStack_38 = (uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar5) * 0x100000;
      VecFx32_Add((uint)(uintptr_t)(auStack_34),(uint)(uintptr_t)(&uStack_40),(int *)(void *)(auStack_34));
      uVar5 = param_1 + 0x1d0U & 3;
      uVar4 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
      iVar6 = func_01ffdee4(auStack_34,0,0,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
      if (iVar6 != 0) {
        VecFx32_Add((uint)(uintptr_t)(auStack_4c),(uint)(uintptr_t)(&uStack_40),(int *)(void *)(auStack_4c));
        VecFx32_Add((uint)(uintptr_t)(puVar8),(uint)(uintptr_t)(auStack_4c),puVar8);
      }
    }
    puVar8[4] = *puVar8;
    puVar8[5] = puVar8[1];
    puVar8[6] = puVar8[2];
    uVar2 = uRam020651f8;
    uVar5 = (uint)(puVar8 + 5) & 3;
    uVar7 = *(uint *)((uint)(puVar8 + 5) & 0xfffffffc);
    uVar4 = (uint)(puVar8 + 0x18) & 3;
    uVar3 = *(uint *)((uint)(puVar8 + 0x18) & 0xfffffffc);
    puVar8[5] = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    func_01ffce48((uint)(uintptr_t)(puVar8 + 0x13),param_1 + 0x110,puVar8 + 0x13,uVar2);
    return;
  }
  return;
}


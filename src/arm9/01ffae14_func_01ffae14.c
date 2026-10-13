/* Decompiled C draft; module arm9; ROM address 01ffae14. No matching claim. */
#include "types.h"
#include "deps/01ffae14_func_01ffae14.h"

void func_01ffae14(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  uVar5 = param_1 + 0xa4U & 3;
  uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * (longlong)param_2;
  *(uint *)(param_1 + 0xa4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0xa8U & 3;
  uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar3 = 0;
  lVar1 = (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * (longlong)param_2;
  *(uint *)(param_1 + 0xa8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0xacU & 3;
  uVar2 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * (longlong)param_2;
  *(uint *)(param_1 + 0xac) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0xa8U & 3;
  uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar6 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0xa4U & 3;
  uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0xacU & 3;
  uVar4 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar2 * (longlong)(int)uVar2 + (longlong)(int)uVar6 * (longlong)(int)uVar6;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar3 = Vector3_MaybeNormalize(param_1 + 0xa4,(int *)(uintptr_t)(param_1 + 0xb0));
  }
  *(undefined4 *)(param_1 + 0x2a4) = uVar3;
  uVar5 = param_1 + 0x2a4U & 3;
  uVar2 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  if (0xd000 < (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x2a4) = 0xd000;
    uVar5 = param_1 + 0xb0U & 3;
    uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 0xd000;
    *(uint *)(param_1 + 0xa4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    uVar5 = param_1 + 0xb4U & 3;
    uVar2 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 0xd000;
    *(uint *)(param_1 + 0xa8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    uVar5 = param_1 + 0xb8U & 3;
    uVar2 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * 0xd000;
    *(uint *)(param_1 + 0xac) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    return;
  }
  return;
}


/* Decompiled C draft; module arm9; ROM address 020f1ea4. No matching claim. */
#include "types.h"
#include "deps/020f1ea4_func_020f1ea4.h"

void func_020f1ea4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  bool bVar7;
  uint uVar4;
  uint uVar6;
  
  uVar6 = param_1 + 0x60U & 3;
  uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x5cU & 3;
  uVar3 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 100U & 3;
  uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  uVar2 = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar2 = Vector3_MaybeNormalize(param_1 + 0x5c,(int *)(uintptr_t)(param_1 + 0x130));
  }
  *(undefined4 *)(param_1 + 300) = uVar2;
  if (param_3 != 0) {
    uVar6 = param_1 + 300U & 3;
    uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
    *(uint *)(param_1 + 300) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x130U & 3;
    uVar3 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    *(uint *)(param_1 + 0x130) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x134U & 3;
    uVar3 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
    *(uint *)(param_1 + 0x134) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x138U & 3;
    uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
    *(uint *)(param_1 + 0x138) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  }
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x138);
  uVar6 = param_1 + 0x138U & 3;
  uVar5 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar3 = param_1 + 0x130U & 3;
  uVar4 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  *(uint *)(param_1 + 0x150) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  *(uint *)(param_1 + 0x148) = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x14c) = 0;
  bVar7 = param_2 < 0;
  if (bVar7) {
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  else {
    *(int *)(param_1 + 0x154) = param_2;
  }
  if (!bVar7) {
    *(uint *)(param_1 + 0x15c) = (uint)!bVar7;
  }
  *(undefined4 *)(param_1 + 0x124) = uRam020f1f94;
  *(undefined4 *)(param_1 + 0x160) = 1;
  *(undefined4 *)(param_1 + 0x158) = param_4;
  return;
}


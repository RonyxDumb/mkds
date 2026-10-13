/* Decompiled C draft; module arm9; ROM address 020881b0. No matching claim. */
#include "types.h"
#include "deps/020881b0_Animation_Register.h"

void Animation_Register(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_5 == 0) {
    uVar2 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar5 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + param_2 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    *(undefined4 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + param_2 * 4) = param_4;
  }
  else {
    uVar2 = param_1 + 0x14U & 3;
    uVar5 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 4;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = Anim_GetNeededBlockSize((char *)(uintptr_t)(param_3),uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
    *puRam02088238 = uVar3;
    uVar2 = Mem_AllocateHeap(param_5);
    uVar5 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + param_2 * 4) = uVar2;
    uVar5 = param_1 + 0x20U & 3;
    uVar1 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + param_2 * 4) = param_4;
  }
  uVar5 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  uVar5 = uVar1 + 4;
  uVar4 = uVar5 & 3;
  uVar6 = *(uint *)(uVar5 & 0xfffffffc);
  uVar1 = uVar1 + 0x68;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  MaybeCreateAnimationBlock
            ((undefined4 *)(uintptr_t)(uVar2),(char *)(uintptr_t)(param_3),uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20,
             uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  return;
}


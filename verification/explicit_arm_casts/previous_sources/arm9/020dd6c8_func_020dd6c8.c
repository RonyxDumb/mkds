/* Decompiled C draft; module arm9; ROM address 020dd6c8. No matching claim. */
#include "types.h"
#include "deps/020dd6c8_func_020dd6c8.h"

void func_020dd6c8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_40 [36];
  int local_1c;
  int local_18;
  int local_14;
  
  if ((*(short *)(param_2 + 0x8e) == 4) && (iVar2 = IsRaceOptionMenuOn_from_thumb(), iVar2 == 0)) {
    uVar1 = param_2 + 4U & 3;
    uVar5 = *(uint *)(param_2 + 4U & 0xfffffffc);
    uVar4 = param_2 + 0x10U & 3;
    uVar3 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    *(uint *)(param_2 + 4) =
         (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    uVar1 = param_2 + 0xcU & 3;
    uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar4 = param_2 + 0x18U & 3;
    uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    *(uint *)(param_2 + 0xc) =
         (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  }
  uVar4 = uRam020dd7a0;
  uVar1 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  func_020ea8a8(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c,
                param_4);
  func_01ffccd0(auStack_40,param_2 + 0xd4);
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_1c = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  local_18 = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  local_14 = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  func_020ea868(*(uint *)(uRam020dd7a4 & 0xfffffffc) >> (uRam020dd7a4 & 3) * 8 |
                *(uint *)(uRam020dd7a4 & 0xfffffffc) << (uRam020dd7a4 & 3) * -8 + 0x20,auStack_40,
                param_2 + 0x1c,param_4);
  return;
}


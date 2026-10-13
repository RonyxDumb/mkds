/* Decompiled C draft; module arm9; ROM address 020ec538. No matching claim. */
#include "types.h"
#include "deps/020ec538_func_020ec538.h"

void func_020ec538(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int local_14;
  int iStack_10;
  int local_c;
  uint uVar4;
  
  if (param_2 == 0) {
    local_38 = *(undefined4 *)(param_1 + 4);
    uStack_34 = *(undefined4 *)(param_1 + 8);
    uStack_30 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    local_38 = *(undefined4 *)(param_2 + 0x50);
    uStack_34 = *(undefined4 *)(param_2 + 0x54);
    uStack_30 = *(undefined4 *)(param_2 + 0x58);
  }
  local_20 = local_38;
  uStack_1c = uStack_34;
  uStack_18 = uStack_30;
  piVar1 = piRam020ec6d8;
  if (param_2 != 0) {
    piVar1 = (int *)(param_2 + 0x5c);
  }
  local_14 = *piVar1;
  iStack_10 = piVar1[1];
  local_c = piVar1[2];
  VecFx32_Subtract(param_1 + 4,(uint)(uintptr_t)(&local_20),&local_2c);
  if ((int)((int)((ulonglong)((longlong)local_24 * (longlong)local_14) >> 0x20) -
           ((int)((ulonglong)((longlong)local_2c * (longlong)local_c) >> 0x20) +
           (uint)((uint)((longlong)local_24 * (longlong)local_14) <
                 (uint)((longlong)local_2c * (longlong)local_c)))) < 0) {
    iVar2 = func_020d6f78((uint)(uintptr_t)(&local_14),&local_2c);
    if (iVar2 == 0) {
      local_28 = piRam020ec6dc[1];
      local_24 = piRam020ec6dc[2];
      local_2c = *piRam020ec6dc;
    }
    else {
      iVar2 = local_24;
      local_24 = -local_2c;
      local_28 = 0;
      local_2c = iVar2;
    }
    *(undefined4 *)(param_1 + 0xa8) = 1;
  }
  else {
    iVar2 = func_020d6f78((uint)(uintptr_t)(&local_14),&local_2c);
    if (iVar2 == 0) {
      local_2c = *piRam020ec6e0;
      local_28 = piRam020ec6e0[1];
      local_24 = piRam020ec6e0[2];
    }
    else {
      iVar2 = local_2c;
      local_2c = -local_24;
      local_28 = 0;
      local_24 = iVar2;
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  uVar4 = param_1 + 0xb4U & 3;
  uVar3 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  *(uint *)(param_1 + 0x10) =
       (uint)((longlong)local_2c * (longlong)(int)uVar4) >> 0xc |
       (int)((ulonglong)((longlong)local_2c * (longlong)(int)uVar4) >> 0x20) << 0x14;
  *(uint *)(param_1 + 0x14) =
       (uint)((longlong)local_28 * (longlong)(int)uVar4) >> 0xc |
       (int)((ulonglong)((longlong)local_28 * (longlong)(int)uVar4) >> 0x20) << 0x14;
  *(uint *)(param_1 + 0x18) =
       (uint)((longlong)local_24 * (longlong)(int)uVar4) >> 0xc |
       (int)((ulonglong)((longlong)local_24 * (longlong)(int)uVar4) >> 0x20) << 0x14;
  uVar4 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + (local_14 >> 1);
  uVar4 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + (local_c >> 1);
  uVar4 = param_1 + 0xb0U & 3;
  uVar3 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}


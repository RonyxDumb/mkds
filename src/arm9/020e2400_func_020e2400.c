/* Decompiled C draft; module arm9; ROM address 020e2400. No matching claim. */
#include "types.h"
#include "deps/020e2400_func_020e2400.h"

void func_020e2400(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18 [3];
  
  uVar1 = param_1 + 0x11cU & 3;
  uVar2 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
  local_1c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x118U & 3;
  uVar2 = *(uint *)(param_1 + 0x118U & 0xfffffffc);
  local_20 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x114U & 3;
  uVar2 = *(uint *)(param_1 + 0x114U & 0xfffffffc);
  local_24 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x120U & 3;
  uVar2 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
  local_18[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x114U & 3;
  uVar2 = *(uint *)(param_1 + 0x114U & 0xfffffffc);
  local_18[0] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  local_18[1] = 0;
  func_020eafc4(param_2,param_1 + 4,param_1 + 0x28,(uint)(uintptr_t)(&local_24),(uint)(uintptr_t)(local_18),param_3,(uint *)(uintptr_t)(param_4));
  return;
}


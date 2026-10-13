/* Decompiled C draft; module arm9; ROM address 020fce94. No matching claim. */
#include "types.h"
#include "deps/020fce94_func_020fce94.h"

void func_020fce94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  ushort param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x25cU & 3;
  uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
  *(uint *)(param_1 + 0x25c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)param_5;
  uVar1 = param_1 + 0x25cU & 3;
  uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
  func_020fcf10(param_1,param_3,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff,param_4,
                param_2,1,1);
  return;
}


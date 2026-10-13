/* Decompiled C draft; module arm9; ROM address 020204c0. No matching claim. */
#include "types.h"
#include "deps/020204c0_func_020204c0.h"

undefined4 func_020204c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  ushort auStack_10 [3];
  short sStack_a;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(short *)(param_1 + 0x3c) != 0) {
    Mem_CpuCopy8(param_1 + 0x50,auStack_10,8);
    DC_SomeClean(auStack_10,8);
    uVar1 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
       (((auStack_10[0] == uRam02020564 || (auStack_10[0] == uRam02020568)) && (sStack_a == 4)))) {
      return 1;
    }
    return 0;
  }
  return 0;
}


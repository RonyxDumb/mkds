/* Decompiled C draft; module arm9; ROM address 02004734. No matching claim. */
#include "types.h"
#include "deps/02004734_Fs_Archive_WriteFn_Default.h"

undefined4 Fs_Archive_WriteFn_Default(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x28U & 3;
  uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  Mem_CpuCopy8(param_2,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3,param_4);
  return 0;
}


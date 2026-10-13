/* Decompiled C draft; module arm9; ROM address 021525f0. No matching claim. */
#include "types.h"
#include "deps/021525f0_func_021525f0.h"

void func_021525f0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 auStack_410 [1028];
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  GenerateProfileInfoCrcLookupTable(auStack_410,uRam02152634);
  uVar1 = ComputeProfileInfoCrc(auStack_410,param_1,0x3c);
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 1;
  return;
}


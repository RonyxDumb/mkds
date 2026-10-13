/* Decompiled C draft; module arm9; ROM address 0200bc78. No matching claim. */
#include "types.h"
#include "deps/0200bc78_func_0200bc78.h"

int func_0200bc78(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  Arm_FlushRange(param_3,4);
  Mem_DcDrainWriteBuffer();
  iVar1 = func_0200bd0c();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = func_02144048(uRam0200bcd0,0,param_3,param_1,param_2,1,3);
  if (iVar1 == 2) {
    *(undefined2 *)(*piRam0200bcd4 + 0x20) = 1;
    iVar1 = 2;
  }
  return iVar1;
}


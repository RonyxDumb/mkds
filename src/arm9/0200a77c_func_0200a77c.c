/* Decompiled C draft; module arm9; ROM address 0200a77c. No matching claim. */
#include "types.h"
#include "deps/0200a77c_func_0200a77c.h"

void func_0200a77c(int param_1)

{
  short sVar1;
  
  if ((((*(short *)(param_1 + 2) == 0) && (sVar1 = *(short *)(param_1 + 4), sVar1 != 7)) &&
      (sVar1 != 9)) && (sVar1 == 0x15)) {
    (**(code **)(*piRam0200a7a8 + iRam0200a7ac))(9);
  }
  return;
}


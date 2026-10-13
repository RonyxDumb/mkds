/* Decompiled C draft; module arm9; ROM address 0214d33c. No matching claim. */
#include "types.h"
#include "deps/0214d33c_Mem_Swap16.h"

undefined4 Mem_Swap16(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}


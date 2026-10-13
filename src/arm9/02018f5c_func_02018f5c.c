/* Decompiled C draft; module arm9; ROM address 02018f5c. No matching claim. */
#include "types.h"
#include "deps/02018f5c_func_02018f5c.h"

int func_02018f5c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (*(code *)(*(uint *)(uRam02018f8c & 0xfffffffc) >> (uRam02018f8c & 3) * 8 |
                    *(uint *)(uRam02018f8c & 0xfffffffc) << (uRam02018f8c & 3) * -8 + 0x20))
                    (param_1,param_2,0);
  return (uVar1 & uRam02018f90) << 3;
}


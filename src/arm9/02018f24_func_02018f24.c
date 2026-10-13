/* Decompiled C draft; module arm9; ROM address 02018f24. No matching claim. */
#include "types.h"
#include "deps/02018f24_func_02018f24.h"

int func_02018f24(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (*(code *)(*(uint *)(uRam02018f54 & 0xfffffffc) >> (uRam02018f54 & 3) * 8 |
                    *(uint *)(uRam02018f54 & 0xfffffffc) << (uRam02018f54 & 3) * -8 + 0x20))
                    (param_1,param_2,0);
  return (uVar1 & uRam02018f58) << 3;
}


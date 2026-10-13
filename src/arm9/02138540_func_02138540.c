/* Decompiled C draft; module arm9; ROM address 02138540. No matching claim. */
#include "types.h"
#include "deps/02138540_func_02138540.h"

undefined4 func_02138540(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint local_10 [4];
  
  if ((param_1 != 0) &&
     (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff) != 0)) {
    local_10[1] = 0;
    local_10[0] = param_1;
    uVar1 = func_02138618(uRam0213859c,(undefined4)(uintptr_t)(local_10),param_2,param_3);
    return uVar1;
  }
  return 0xffffffff;
}


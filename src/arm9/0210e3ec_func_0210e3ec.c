/* Decompiled C draft; module arm9; ROM address 0210e3ec. No matching claim. */
#include "types.h"
#include "deps/0210e3ec_func_0210e3ec.h"

undefined4 func_0210e3ec(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (((param_2 ==
        (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) &&
      (uVar1 = param_1 + 4 & 3, uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc),
      param_3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) &&
     (uVar1 = param_1 + 8 & 3, uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc),
     param_4 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) {
    return 1;
  }
  return 0;
}


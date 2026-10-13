/* Decompiled C draft; module arm9; ROM address 02121990. No matching claim. */
#include "types.h"
#include "deps/02121990_func_02121990.h"

undefined4 func_02121990(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (((((int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) < 10) &&
       (uVar1 = param_1 + 4 & 3, uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc),
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == param_2)) &&
      (*(byte *)(param_1 + 8) == param_3)) && (*(byte *)(param_1 + 9) == param_4)) {
    return 1;
  }
  return 0;
}


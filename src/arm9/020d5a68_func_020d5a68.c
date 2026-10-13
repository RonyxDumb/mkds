/* Decompiled C draft; module arm9; ROM address 020d5a68. No matching claim. */
#include "types.h"
#include "deps/020d5a68_func_020d5a68.h"

undefined4 func_020d5a68(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((param_2 & 0x80000000) == 0) &&
      (uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20, uVar1 = uVar3 + 4 & 3,
      uVar2 = *(uint *)(uVar3 + 4 & 0xfffffffc),
      uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0)) &&
     ((*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
      *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) ==
      (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20))) {
    return 0;
  }
  return 1;
}


/* Decompiled C draft; module arm9; ROM address 021100dc. No matching claim. */
#include "types.h"
#include "deps/021100dc_func_021100dc.h"

bool func_021100dc(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (*(ushort *)(uVar1 + 0x3a) != param_3) {
    return false;
  }
  return *(ushort *)(uVar1 + 0x38) == param_2;
}


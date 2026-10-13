/* Decompiled C draft; module arm9; ROM address 0213c94c. No matching claim. */
#include "types.h"
#include "deps/0213c94c_func_0213c94c.h"

int func_0213c94c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 != 0) &&
     (uVar2 = param_1 + 4U & 3, uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc),
     uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20, (uVar2 << 0x16) >> 0x1d != 0)) {
    uVar1 = (uVar2 << 0x14) >> 0x1e;
    if (uVar1 == 0) {
      if (param_2 < 1) {
        if (param_2 < 0) {
          *(uint *)(param_1 + 4) = uVar2 & 0xfffff3ff | 0x400;
        }
      }
      else {
        *(uint *)(param_1 + 4) = uVar2 & 0xfffff3ff | 0x800;
      }
    }
    else if (uVar1 == 1) {
      param_2 = -1;
    }
    else if (uVar1 == 2) {
      param_2 = 1;
    }
    return param_2;
  }
  return 0;
}


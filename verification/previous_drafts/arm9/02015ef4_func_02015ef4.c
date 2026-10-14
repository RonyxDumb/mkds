/* Decompiled C draft; module arm9; ROM address 02015ef4. No matching claim. */
#include "types.h"
#include "deps/02015ef4_func_02015ef4.h"

void func_02015ef4(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 2) == 0) {
      func_01ff9048(0x19,param_1 + 0x28,0xc);
    }
    else {
      func_01ff9048(0x1c,param_1 + 0x4c,3);
    }
  }
  else if ((uVar1 & 2) == 0) {
    func_01ff9048(0x1a,param_1 + 0x28,9);
  }
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 1) == 0) {
    func_01ff9048(0x1b,param_1 + 4,3);
    return;
  }
  return;
}


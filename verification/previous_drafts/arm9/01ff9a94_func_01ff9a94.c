/* Decompiled C draft; module arm9; ROM address 01ff9a94. No matching claim. */
#include "types.h"
#include "deps/01ff9a94_func_01ff9a94.h"

void func_01ff9a94(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  bVar2 = (uVar1 & 4) == 0;
  if (((uVar1 & 0x20) != 0) && ((uVar1 & 8) == 0)) {
    if (bVar2) {
      func_01ff9048(0x1c,param_1 + 0x4c,3);
    }
    bVar2 = false;
    func_01ff9048(0x1b,param_1 + 0x10,3);
  }
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 2) == 0) {
    if (bVar2) {
      func_01ff9048(0x19,param_1 + 0x28,0xc);
    }
    else {
      func_01ff9048(0x1a,param_1 + 0x28,9);
    }
  }
  else if (bVar2) {
    func_01ff9048(0x1c,param_1 + 0x4c,3);
  }
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 1) == 0) {
    func_01ff9048(0x1b,param_1 + 4,3);
    return;
  }
  return;
}


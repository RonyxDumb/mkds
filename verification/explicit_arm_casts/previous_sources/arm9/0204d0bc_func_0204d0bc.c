/* Decompiled C draft; module arm9; ROM address 0204d0bc. No matching claim. */
#include "types.h"
#include "deps/0204d0bc_func_0204d0bc.h"

void func_0204d0bc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  func_0204d110(param_1 + iRam0204d108,param_1 + iRam0204d10c,param_2);
  *(undefined4 *)(param_2 + 0x80) = 0;
  uVar1 = param_1 + 0x46e4U & 3;
  uVar2 = *(uint *)(param_1 + 0x46e4U & 0xfffffffc);
  *(uint *)(param_1 + 0x46e4) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
  return;
}


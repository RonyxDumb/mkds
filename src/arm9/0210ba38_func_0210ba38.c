/* Decompiled C draft; module arm9; ROM address 0210ba38. No matching claim. */
#include "types.h"
#include "deps/0210ba38_func_0210ba38.h"

void func_0210ba38(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  func_0210ddf4(uRam0210ba70,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam0210ba6c,
                uRam0210ba74,param_1,param_2);
  return;
}


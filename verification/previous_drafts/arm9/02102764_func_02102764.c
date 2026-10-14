/* Decompiled C draft; module arm9; ROM address 02102764. No matching claim. */
#include "types.h"
#include "deps/02102764_func_02102764.h"

void func_02102764(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  func_020fecdc();
  if (param_2 == 0) {
    return;
  }
  if (param_3 != 0) {
    uVar1 = param_2 + 0x44U & 3;
    uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    func_020fe8ac(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}


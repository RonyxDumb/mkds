/* Decompiled C draft; module arm9; ROM address 0209ba58. No matching claim. */
#include "types.h"
#include "deps/0209ba58_func_0209ba58.h"

void func_0209ba58(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x10U & 3;
  uVar1 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    func_020ea740(uVar2,*(undefined2 *)(param_3 + 0x66));
    return;
  }
  return;
}


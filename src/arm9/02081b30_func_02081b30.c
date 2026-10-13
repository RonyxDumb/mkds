/* Decompiled C draft; module arm9; ROM address 02081b30. No matching claim. */
#include "types.h"
#include "deps/02081b30_func_02081b30.h"

void func_02081b30(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar2 = GetDriverEntry(*(undefined1 *)(param_1 + 0x9b));
    uVar1 = param_1 + 0x94U & 3;
    uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    func_02081ca0(param_1,uVar2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}


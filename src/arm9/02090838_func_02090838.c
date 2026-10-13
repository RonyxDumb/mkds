/* Decompiled C draft; module arm9; ROM address 02090838. No matching claim. */
#include "types.h"
#include "deps/02090838_func_02090838.h"

void func_02090838(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  if (param_2 != (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    func_0207ffa4(param_1,*(undefined2 *)(param_1 + 0x24));
    return;
  }
  return;
}


/* Decompiled C draft; module arm9; ROM address 01ffc8cc. No matching claim. */
#include "types.h"
#include "deps/01ffc8cc_func_01ffc8cc.h"

void func_01ffc8cc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x3d2) < 1) {
    return;
  }
  *(short *)(param_1 + 0x3d2) = *(short *)(param_1 + 0x3d2) + -1;
  if (*(short *)(param_1 + 0x3d2) < 1) {
    uVar1 = param_1 + 0x3ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    func_0210b12c(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                  (int)*(short *)(param_1 + 0x3d0));
    *(undefined2 *)(param_1 + 0x3d2) = 0;
    return;
  }
  return;
}


/* Decompiled C draft; module arm9; ROM address 0210a6ec. No matching claim. */
#include "types.h"
#include "deps/0210a6ec_func_0210a6ec.h"

void func_0210a6ec(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  func_02105b28(param_2,*(undefined1 *)(param_2 + 0x1a));
  func_02105b0c(param_2,(int)*(short *)(param_2 + 0x14) +
                        (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20));
  return;
}


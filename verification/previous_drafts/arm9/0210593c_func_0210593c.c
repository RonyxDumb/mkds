/* Decompiled C draft; module arm9; ROM address 0210593c. No matching claim. */
#include "types.h"
#include "deps/0210593c_func_0210593c.h"

void func_0210593c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != 4) {
    return;
  }
  uVar1 = iRam0210597c + 0xcU & 3;
  uVar2 = *(uint *)(iRam0210597c + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_0210d5c0();
    return;
  }
  return;
}


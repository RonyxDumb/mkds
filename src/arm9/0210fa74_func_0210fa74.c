/* Decompiled C draft; module arm9; ROM address 0210fa74. No matching claim. */
#include "types.h"
#include "deps/0210fa74_func_0210fa74.h"

void func_0210fa74(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 1) {
    uVar1 = iRam0210faa8 + 8U & 3;
    uVar2 = *(uint *)(iRam0210faa8 + 8U & 0xfffffffc);
    *(uint *)(iRam0210faa8 + 8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 2;
  }
  else {
    uVar1 = iRam0210faa8 + 8U & 3;
    uVar2 = *(uint *)(iRam0210faa8 + 8U & 0xfffffffc);
    *(uint *)(iRam0210faa8 + 8) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
  }
  *(undefined4 *)(iRam0210faa8 + 4) = 0;
  return;
}


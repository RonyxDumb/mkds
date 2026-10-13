/* Decompiled C draft; module arm9; ROM address 0206169c. No matching claim. */
#include "types.h"
#include "deps/0206169c_func_0206169c.h"

uint func_0206169c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    uVar1 = param_1 + 4U & 3;
    uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xf;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


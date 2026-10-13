/* Decompiled C draft; module arm9; ROM address 0210faac. No matching claim. */
#include "types.h"
#include "deps/0210faac_func_0210faac.h"

void func_0210faac(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0210fac0 + 8U & 3;
  uVar2 = *(uint *)(iRam0210fac0 + 8U & 0xfffffffc);
  *(uint *)(iRam0210fac0 + 8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
  return;
}


/* Decompiled C draft; module arm9; ROM address 0210fac4. No matching claim. */
#include "types.h"
#include "deps/0210fac4_func_0210fac4.h"

uint func_0210fac4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0210fad0 + 0xcU & 3;
  uVar2 = *(uint *)(iRam0210fad0 + 0xcU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}


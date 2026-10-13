/* Decompiled C draft; module arm9; ROM address 0204bcdc. No matching claim. */
#include "types.h"
#include "deps/0204bcdc_func_0204bcdc.h"

uint func_0204bcdc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0204bce8 + 0xcU & 3;
  uVar2 = *(uint *)(iRam0204bce8 + 0xcU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}


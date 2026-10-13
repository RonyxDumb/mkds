/* Decompiled C draft; module arm9; ROM address 020d50b4. No matching claim. */
#include "types.h"
#include "deps/020d50b4_func_020d50b4.h"

uint func_020d50b4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam020d50c0 + 0x54U & 3;
  uVar2 = *(uint *)(iRam020d50c0 + 0x54U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}


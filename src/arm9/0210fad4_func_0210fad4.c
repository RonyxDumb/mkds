/* Decompiled C draft; module arm9; ROM address 0210fad4. No matching claim. */
#include "types.h"
#include "deps/0210fad4_func_0210fad4.h"

bool func_0210fad4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0210faf0 + 8U & 3;
  uVar2 = *(uint *)(iRam0210faf0 + 8U & 0xfffffffc);
  return ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 2 & 1U) != 0;
}


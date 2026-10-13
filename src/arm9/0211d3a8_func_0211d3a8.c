/* Decompiled C draft; module arm9; ROM address 0211d3a8. No matching claim. */
#include "types.h"
#include "deps/0211d3a8_func_0211d3a8.h"

undefined4 func_0211d3a8(void)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(*piRam0211d3f0 + 0x6c) != 0) {
    uVar1 = func_0211d478(0);
    uVar2 = func_0211d478(1);
    if (uVar2 < uVar1) {
      return 0;
    }
    uVar1 = func_0211d478(0);
    uVar2 = func_0211d478(1);
    if (uVar1 < uVar2) {
      return 1;
    }
  }
  return 2;
}


/* Decompiled C draft; module arm9; ROM address 021277c8. No matching claim. */
#include "types.h"
#include "deps/021277c8_func_021277c8.h"

undefined4 func_021277c8(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*piRam021277e0 + 4) == 1) && (*(int *)(*piRam021277e0 + 0x28) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


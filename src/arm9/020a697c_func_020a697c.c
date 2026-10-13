/* Decompiled C draft; module arm9; ROM address 020a697c. No matching claim. */
#include "types.h"
#include "deps/020a697c_func_020a697c.h"

void func_020a697c(void)

{
  uint uVar1;
  
  uVar1 = *puRam020a699c + 1;
  if (2 < uVar1) {
    uVar1 = 0;
  }
  *puRam020a699c = (ushort)uVar1;
  return;
}


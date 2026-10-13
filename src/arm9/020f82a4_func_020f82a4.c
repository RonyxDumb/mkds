/* Decompiled C draft; module arm9; ROM address 020f82a4. No matching claim. */
#include "types.h"
#include "deps/020f82a4_func_020f82a4.h"

void func_020f82a4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = puRam020f82c0;
  *puRam020f82c0 = 900;
  if (param_1 != 0) {
    *puVar1 = 0x4b0;
  }
  return;
}


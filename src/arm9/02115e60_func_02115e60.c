/* Decompiled C draft; module arm9; ROM address 02115e60. No matching claim. */
#include "types.h"
#include "deps/02115e60_func_02115e60.h"

void func_02115e60(void)

{
  int *piVar1;
  
  piVar1 = piRam02115e70;
  *(undefined4 *)(*piRam02115e70 + 0x58) = 1;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  return;
}


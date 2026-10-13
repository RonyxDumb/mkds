/* Decompiled C draft; module arm9; ROM address 02115e20. No matching claim. */
#include "types.h"
#include "deps/02115e20_func_02115e20.h"

void func_02115e20(void)

{
  int *piVar1;
  
  piVar1 = piRam02115e40;
  *(undefined4 *)(*piRam02115e40 + 0x58) = 3;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  func_02128374();
  func_02116244();
  return;
}


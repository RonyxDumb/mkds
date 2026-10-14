/* Decompiled C draft; module arm9; ROM address 02118114. No matching claim. */
#include "types.h"
#include "deps/02118114_func_02118114.h"

void func_02118114(void)

{
  int *piVar1;
  
  piVar1 = piRam02118144;
  *(undefined4 *)(*piRam02118144 + 0x34) = 6;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  func_0212775c(0,7);
  func_0212775c(1,0x10);
  func_0212775c(0xffffffff,0x10);
  return;
}


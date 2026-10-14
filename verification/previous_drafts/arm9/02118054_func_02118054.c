/* Decompiled C draft; module arm9; ROM address 02118054. No matching claim. */
#include "types.h"
#include "deps/02118054_func_02118054.h"

void func_02118054(void)

{
  int *piVar1;
  
  piVar1 = piRam02118084;
  *(undefined4 *)(*piRam02118084 + 0x34) = 9;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  func_0212775c(0,5);
  func_0212775c(1,0xf);
  func_0212775c(0xffffffff,0x10);
  return;
}


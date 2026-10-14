/* Decompiled C draft; module arm9; ROM address 02119a90. No matching claim. */
#include "types.h"
#include "deps/02119a90_func_02119a90.h"

void func_02119a90(void)

{
  int *piVar1;
  
  piVar1 = piRam02119ac0;
  *(undefined4 *)(*piRam02119ac0 + 0x38) = 6;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  func_0212775c(0,7);
  func_0212775c(1,0x10);
  func_0212775c(0xffffffff,0x10);
  return;
}


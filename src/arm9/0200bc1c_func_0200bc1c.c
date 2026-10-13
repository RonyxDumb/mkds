/* Decompiled C draft; module arm9; ROM address 0200bc1c. No matching claim. */
#include "types.h"
#include "deps/0200bc1c_func_0200bc1c.h"

void func_0200bc1c(int param_1)

{
  int *piVar1;
  
  piVar1 = piRam0200bc74;
  *(undefined2 *)(*piRam0200bc74 + 0x20) = 0;
  if (*(short *)(param_1 + 2) == 0) {
    if (*(code **)*piVar1 != (code *)0x0) {
      (**(code **)*piVar1)(8);
    }
  }
  else if (*(short *)(param_1 + 2) == 9) {
    if (*(code **)*piVar1 != (code *)0x0) {
      (**(code **)*piVar1)(0x29);
    }
  }
  else if (*(code **)*piVar1 != (code *)0x0) {
    (**(code **)*piVar1)(0x12);
  }
  if (*(code **)*piRam0200bc74 != (code *)0x0) {
    (**(code **)*piRam0200bc74)(0x19,0);
  }
  return;
}


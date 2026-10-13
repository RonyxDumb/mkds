/* Decompiled C draft; module arm9; ROM address 0202cc18. No matching claim. */
#include "types.h"
#include "deps/0202cc18_func_0202cc18.h"

void func_0202cc18(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*piRam0202cc40 + 0x50 + param_1 * 0x2c);
  piVar1[1] = param_2;
  if (piVar1[1] == piVar1[2]) {
    piVar1[2] = piVar1[3];
    piVar1[3] = piVar1[1];
    *piVar1 = 10 - *piVar1;
  }
  return;
}


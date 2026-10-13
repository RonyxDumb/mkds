/* Decompiled C draft; module arm9; ROM address 0202cc44. No matching claim. */
#include "types.h"
#include "deps/0202cc44_func_0202cc44.h"

void func_0202cc44(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = piRam0202cc74;
  param_1 = param_1 * 0x2c;
  *(undefined4 *)(*piRam0202cc74 + param_1 + 0x50) = 10;
  *(undefined4 *)(*piVar1 + param_1 + 0x5c) = param_2;
  *(undefined4 *)(*piVar1 + param_1 + 0x54) = *(undefined4 *)(*piVar1 + param_1 + 0x5c);
  *(undefined4 *)(*piVar1 + param_1 + 0x58) = *(undefined4 *)(*piVar1 + param_1 + 0x54);
  return;
}


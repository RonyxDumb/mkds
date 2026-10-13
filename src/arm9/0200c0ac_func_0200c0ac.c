/* Decompiled C draft; module arm9; ROM address 0200c0ac. No matching claim. */
#include "types.h"
#include "deps/0200c0ac_func_0200c0ac.h"

void func_0200c0ac(int param_1)

{
  int *piVar1;
  
  piVar1 = piRam0200c0d4;
  *piRam0200c0d4 = param_1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(*piVar1 + 0x1a) = 0;
  *(undefined2 *)(*piVar1 + 0x1e) = 0;
  *(undefined2 *)(*piVar1 + 0x20) = 0;
  *(undefined2 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)*piVar1 = 0;
  return;
}


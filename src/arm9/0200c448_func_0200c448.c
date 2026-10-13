/* Decompiled C draft; module arm9; ROM address 0200c448. No matching claim. */
#include "types.h"
#include "deps/0200c448_func_0200c448.h"

void func_0200c448(int param_1)

{
  int *piVar1;
  int iVar2;
  
  *piRam0200c468 = param_1 + -2;
  iVar2 = _s32_div_f(0x1e);
  piVar1 = piRam0200c468;
  piRam0200c468[1] = iVar2;
  piVar1[2] = 0x1e;
  return;
}


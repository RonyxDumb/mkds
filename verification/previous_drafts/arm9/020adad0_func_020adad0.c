/* Decompiled C draft; module arm9; ROM address 020adad0. No matching claim. */
#include "types.h"
#include "deps/020adad0_func_020adad0.h"

void func_020adad0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = piRam020adaf4;
  *(undefined4 *)*piRam020adaf4 = 0;
  *(undefined4 *)(*piVar1 + 4) = 1;
  *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0xc);
  *(undefined4 *)(*piVar1 + 0xc) = param_1;
  *(undefined4 *)(*piVar1 + 0x10) = param_2;
  return;
}


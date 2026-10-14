/* Decompiled C draft; module arm9; ROM address 020ccc74. No matching claim. */
#include "types.h"
#include "deps/020ccc74_func_020ccc74.h"

void func_020ccc74(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = piRam020ccc98;
  *(undefined4 *)*piRam020ccc98 = 0;
  *(undefined4 *)(*piVar1 + 4) = 1;
  *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0xc);
  *(undefined4 *)(*piVar1 + 0xc) = param_1;
  *(undefined4 *)(*piVar1 + 0x10) = param_2;
  return;
}


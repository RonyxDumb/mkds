/* Decompiled C draft; module arm9; ROM address 020cac9c. No matching claim. */
#include "types.h"
#include "deps/020cac9c_func_020cac9c.h"

void func_020cac9c(void)

{
  int *piVar1;
  
  piVar1 = piRam020cacbc;
  *(undefined4 *)(*piRam020cacbc + 0x1c) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 0;
  return;
}


/* Decompiled C draft; module arm9; ROM address 02028f84. No matching claim. */
#include "types.h"
#include "deps/02028f84_func_02028f84.h"

undefined4 func_02028f84(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(*piRam02028fa8 + 0xfc) == 0) || (iVar1 = func_0202b8c0(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* Decompiled C draft; module arm9; ROM address 020270d0. No matching claim. */
#include "types.h"
#include "deps/020270d0_func_020270d0.h"

undefined4 func_020270d0(void)

{
  int iVar1;
  
  if ((*(int *)(*piRam020270f8 + 0x80) != 0) && (iVar1 = func_0202b8c0(), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


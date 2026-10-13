/* Decompiled C draft; module arm9; ROM address 02007df8. No matching claim. */
#include "types.h"
#include "deps/02007df8_func_02007df8.h"

undefined4 func_02007df8(int param_1)

{
  int iVar1;
  
  if (((*piRam02007e30 != 0) && (iVar1 = func_02007138(), iVar1 != 0)) &&
     (*(int *)(*piRam02007e30 + (param_1 + -1) * 4 + iRam02007e34) == 7)) {
    return 1;
  }
  return 0;
}


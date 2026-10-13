/* Decompiled C draft; module arm9; ROM address 02033dd0. No matching claim. */
#include "types.h"
#include "deps/02033dd0_func_02033dd0.h"

undefined4 func_02033dd0(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*piRam02033dec + iRam02033df0) != 0) &&
     (*(int *)(*piRam02033dec + iRam02033df4) < iRam02033df8)) {
    uVar1 = 1;
  }
  return uVar1;
}


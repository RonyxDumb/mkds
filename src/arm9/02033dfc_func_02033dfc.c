/* Decompiled C draft; module arm9; ROM address 02033dfc. No matching claim. */
#include "types.h"
#include "deps/02033dfc_func_02033dfc.h"

undefined4 func_02033dfc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*piRam02033e18 + iRam02033e1c) != 0) &&
     (*(int *)(*piRam02033e18 + iRam02033e20) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


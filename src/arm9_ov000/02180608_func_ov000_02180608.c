/* Decompiled C draft; module arm9_ov000; ROM address 02180608. No matching claim. */
#include "types.h"
#include "deps/02180608_func_ov000_02180608.h"

undefined4 func_ov000_02180608(void)

{
  bool bVar1;
  
  bVar1 = true;
  if ((*piRam02180630 != 0) && (*(int *)(*piRam02180630 + 8) == 0)) {
    bVar1 = false;
  }
  if ((*(short *)(*piRam02180634 + 0x16) == 0) && (bVar1)) {
    return 1;
  }
  return 0;
}


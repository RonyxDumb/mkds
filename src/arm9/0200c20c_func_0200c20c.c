/* Decompiled C draft; module arm9; ROM address 0200c20c. No matching claim. */
#include "types.h"
#include "deps/0200c20c_func_0200c20c.h"

undefined4 func_0200c20c(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0 < *(int *)(iRam0200c250 + 4)) {
    do {
      if ((1 << (uVar1 & 0xff) & *(uint *)(*piRam0200c254 + (param_1 + -1) * 4 + iRam0200c258)) == 0
         ) {
        return 0;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while ((int)uVar1 < *(int *)(iRam0200c250 + 4));
  }
  return 1;
}


/* Decompiled C draft; module arm9; ROM address 02059784. No matching claim. */
#include "types.h"
#include "deps/02059784_func_02059784.h"

undefined4 func_02059784(void)

{
  uint uVar1;
  
  uVar1 = 1;
  while ((((uint)*(byte *)(*piRam020597c8 + 0x87) & 1 << (uVar1 & 0xff)) == 0 ||
         (*(int *)(*piRam020597c8 + uVar1 * 4 + iRam020597cc) != 0))) {
    uVar1 = uVar1 + 1 & 0xffff;
    if (7 < uVar1) {
      return 1;
    }
  }
  return 0;
}


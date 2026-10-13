/* Decompiled C draft; module arm7; ROM address 0600f00c. No matching claim. */
#include "types.h"
#include "deps/0600f00c_FUN_0600f00c.h"

undefined4 FUN_0600f00c(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x27ff < uVar1) {
      return 1;
    }
    if ((*DAT_0600f03c & 1) == 0) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}


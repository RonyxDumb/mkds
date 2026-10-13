/* Decompiled C draft; module arm7; ROM address 0600f0ec. No matching claim. */
#include "types.h"
#include "deps/0600f0ec_FUN_0600f0ec.h"

void FUN_0600f0ec(void)

{
  int iVar1;
  
  iVar1 = 4000;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if ((*DAT_0600f114 & 0x80) != 0) break;
    iVar1 = iVar1 + -1;
  }
  return;
}


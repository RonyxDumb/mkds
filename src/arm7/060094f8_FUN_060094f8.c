/* Decompiled C draft; module arm7; ROM address 060094f8. No matching claim. */
#include "types.h"
#include "deps/060094f8_FUN_060094f8.h"

void FUN_060094f8(void)

{
  int iVar1;
  
  *DAT_06009534 = 0;
  iVar1 = 0x10;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*DAT_06009538 == 0) break;
    if (*DAT_06009538 == 9) {
      return;
    }
    iVar1 = iVar1 + -1;
  }
  return;
}


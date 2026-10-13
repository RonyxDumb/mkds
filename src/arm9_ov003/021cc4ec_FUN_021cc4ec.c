/* Decompiled C draft; module arm9_ov003; ROM address 021cc4ec. No matching claim. */
#include "types.h"
#include "deps/021cc4ec_FUN_021cc4ec.h"

void FUN_021cc4ec(undefined4 param_1)

{
  if (*DAT_021cc598 == '\0') {
    switch(param_1) {
    case 0:
      *DAT_021cc598 = '\x03';
      FUN_021cdbd0();
      FUN_021cdc10(0x12);
      FUN_021cefc0(0x45,1,1,0xffffffff,0);
      FUN_021bf2d0();
      FUN_021c212c(DAT_021cc59c);
      return;
    case 1:
      *DAT_021cc598 = '\x01';
      FUN_021cdbd0();
      FUN_021c212c(DAT_021cc5a0);
      return;
    case 2:
      FUN_021cdbd0();
      FUN_021ce834(0);
      FUN_021cefc0(0x47,0,1,0xffffffff,0);
      FUN_021bf2d0();
      FUN_021c212c(DAT_021cc5a4);
      return;
    case 3:
      *DAT_021cc598 = '\x02';
      FUN_021cdbd0();
      FUN_021cdc10(9);
      FUN_021c212c(DAT_021cc5a0);
    }
  }
  return;
}


/* Decompiled C draft; module arm7; ROM address 03803ff8. No matching claim. */
#include "types.h"
#include "deps/03803ff8_FUN_03803ff8.h"

undefined4 FUN_03803ff8(void)

{
  undefined4 uVar1;
  ushort local_8 [4];
  
  FUN_03804cdc(local_8);
  if ((local_8[0] & 1) == 0) {
    if ((local_8[0] & 2) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


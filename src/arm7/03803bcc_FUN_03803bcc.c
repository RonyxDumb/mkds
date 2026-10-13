/* Decompiled C draft; module arm7; ROM address 03803bcc. No matching claim. */
#include "types.h"
#include "deps/03803bcc_FUN_03803bcc.h"

uint FUN_03803bcc(void)

{
  uint uVar1;
  
  if (*DAT_03803c1c == DAT_03803c20) {
    uVar1 = 0;
  }
  else {
    if (-1 < (int)((uint)*(byte *)((int)DAT_03803c1c + 5) << 0x1e)) {
      FUN_03803ac0();
    }
    uVar1 = ((uint)*(byte *)((int)DAT_03803c1c + 5) << 0x1e) >> 0x1f;
  }
  return uVar1;
}

